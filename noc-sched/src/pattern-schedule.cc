//
//  This file is part of the s4NoC's noc-sched.
//  noc-sched is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  noc-sched is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with noc-sched. If not, see <http://www.gnu.org/licenses/>.
//

#include "noc.h"

#include <iostream>
#include <ostream>
#include <map>

/// Trace conflicts during schedule construction.
#undef TRACE_CONFLICTS

/// Trace progress of schedule construction.
#undef TRACE_SCHEDULE

typedef std::set<unsigned int> range_t;

void insert(range_t &r, unsigned int f, unsigned int t)
{
  assert(f <= t);
  for (unsigned int i = f; i != t + 1; i++)
    r.insert(i);
}

void insert(range_t &r, unsigned int f)
{
  insert(r, f, f);
}

std::ostream &operator << (std::ostream &s, const range_t &r)
{
  bool first = true;
  bool first_skip = true;
  unsigned int skip = std::numeric_limits<unsigned int>::max();
  for (range_t::const_iterator i(r.begin()), ie(r.end()); i != ie; i++)
  {
    if (*i != skip)
    {
      if (!first_skip)
        s << "-" << skip - 1;

      if (first)
        s << *i;
      else
        s << ", " << *i;

      first_skip = true;
    }
    else
    {
      first_skip = false;
    }
    
    skip = *i + 1;
    first = false;
  }

  if (!first_skip)
    s << "-" << skip - 1;
  
  return s;
}

enum direction_t
{
  NONE,
  NORTH,
  EAST,
  SOUTH,
  WEST
};

struct pattern_t
{
  direction_t da, db;
  int la, lb;

  pattern_t(direction_t da_, int la_, direction_t db_, int lb_)
      : da(da_), db(db_), la(la_), lb(lb_)
  {
    assert(da != NONE && la != 0);
    assert(db == NONE || lb != 0);
  }
};

bool operator < (const pattern_t &a, const pattern_t &b)
{
  if (a.da != b.da)
    return a.da < b.da;
  else if (a.la != b.la)
    return a.la < b.la;
  else if (a.db != b.db)
    return a.db < b.db;
  else if (a.lb != b.lb)
    return a.lb < b.lb;
  else
    return false;
}

typedef std::set<pattern_t> patterns_t;
typedef std::map<unsigned int, pattern_t> schedule_t;

std::ostream &operator << (std::ostream &s, const direction_t &d)
{
  switch(d)
  {
    case NORTH:
      s << "n";
      break;
    case EAST:
      s << "e";
      break;
    case SOUTH:
      s << "s";
      break;
    case WEST:
      s << "w";
      break;
  }

  return s;
}

std::ostream &operator << (std::ostream &s, const pattern_t &p)
{
  assert(p.da != NONE && p.la != 0);
  assert(p.db != NONE || p.lb == 0);

  if (p.lb == 0)
    s << p.da << p.la;
  else
    s << p.da << p.la << "_" << p.db << p.lb;

  return s;
}

range_t conflict(const pattern_t &a, const pattern_t &b)
{
  range_t r;
  // consider conflicts when sending a message out
  insert(r, 0);

  // consider conflicts on horizontal and vertical directions
  if (a.da == b.da)
    insert(r, 0, a.la - 1);
  else if (a.da == b.db && b.lb != 0 && (a.la - b.la - 1) > 0)
    insert(r, 0, a.la - b.la - 1);

  // consider conflicts on horizontal and vertical directions
  if (a.db == b.db && a.lb != 0 && b.lb != 0 && (a.la + a.lb - b.la - 1) > 0)
    insert(r, std::max(0, a.la - b.la - b.lb + 1), a.la + a.lb - b.la - 1);
  else if (a.db == b.da && a.lb != 0)
    insert(r, std::max(0, a.la - b.la + 1), a.la + a.lb - 1);

  // consider conflicts of messages arriving at the same instant
  if ((a.la + a.lb - b.la - b.lb) > 0)
    insert(r, a.la + a.lb - b.la - b.lb);
  
  return r;
}

/// Return the total length of the pattern, i.e., the sum of its horizontal and 
/// vertical path lengths.
/// @param a The pattern.
/// @return Return the total length of the pattern, i.e., the sum of its 
/// horizontal and vertical path lengths.
unsigned int length(const pattern_t &a)
{
  return a.la + a.lb;
}

/// The inverse of a pattern, i.e., a pattern that communicates to the same
/// node relative to some reference node using the horizontal and vertical paths
/// swapped.
/// @param a The original pattern.
/// @return The inverse pattern of the original pattern with the horizontal and
/// vertical paths swapped.
pattern_t inverse(const pattern_t &a)
{
  if (a.lb == 0)
    return a;
  else
    return pattern_t(a.db, a.lb, a.da, a.la);
}

/// Select a candidate range to schedule next.
/// Currently the longest unscheduled pattern is selected, other strategies
/// using e.g., some form of critical path length, might be a good idea.
/// @param p The set of unscheduled patterns.
pattern_t select_candidate(const patterns_t &p)
{
  const pattern_t *r = NULL;
  for(patterns_t::const_iterator i(p.begin()), ie(p.end()); i != ie; i++)
  {
    if (!r || length(*r) < length(*i))
    {
      r = &*i;
    }
  }

  assert(r);
  return *r;
}

/// Insert the pattern at the earliest possible position in the schedule such
/// that it does not conflict with any other scheduled pattern.
/// @param s The partial schedule so far.
/// @param max_t Current maximal schedule length.
/// @param p The pattern to schedule.
/// @param Returns the time instance at which p has been scheduled.
unsigned int schedule(schedule_t &s, unsigned int max_t, const pattern_t &p)
{
  // the easy case -- we are scheduling the first pattern
  if (s.empty())
  {
    s.insert(std::make_pair(0, p));
    return 0;
  }

  // try to schedule r at any point within the schedule
  for(unsigned int t = 1; t != max_t + 1; t++)
  {
    bool has_conflict = false;
    for(schedule_t::const_iterator i(s.begin()), ie(s.end()); i != ie &&
        !has_conflict; i++)
    {
      // check for a schedule when the ith pattern in the schedule is before p.
      if (i->first == t)
      {
#ifdef TRACE_CONFLICTS
        std::cerr << "  conflict:" << p << "==" << i->second << ": " << (t - i->first) << "\n";
#endif //TRACE_CONFLICTS
        has_conflict = true;
      }
      else if (i->first < t)
      {
        range_t c(conflict(i->second, p));
#ifdef TRACE_CONFLICTS
        std::cerr << "  conflict:" << p << "<-" << i->second << ": " << (t - i->first) << "   " << c << "\n";
#endif //TRACE_CONFLICTS
        has_conflict |= c.find(t - i->first) != c.end();
      }
      // check for a schedule when the ith pattern in the schedule is after p.
      else 
      {
        range_t c(conflict(p, i->second));
#ifdef TRACE_CONFLICTS
        std::cerr << "  conflict:" << p << "->" << i->second << ": " << (i->first - t) << "   " << c << "\n";
#endif //TRACE_CONFLICTS
        has_conflict |= c.find(i->first - t) != c.end();
      }
    }

    if (!has_conflict)
    {
      s.insert(std::make_pair(t, p));
      return t;
    }
  }

  // no position in schedule found? not even after all other patterns?
  assert(false);
  abort();

  return -1;
}

/// Make a heuristic schedule based on the given set of patterns
/// @param os Output stream to dump the heuristic schedule.
/// @param p The set of patterns.
/// @return The length of the schedule.
unsigned int schedule_heuristic(std::ostream &os, const patterns_t &p)
{
  // copy all patterns
  patterns_t worklist(p);
  schedule_t s;
   
  unsigned int max_t = 0;
  while (!worklist.empty())
  {
    pattern_t p(select_candidate(worklist));

#ifdef TRACE_SCHEDULE
    std::cerr << "candidate :" << p << " (" << inverse(p) << ")\n";
#endif // TRACE_SCHEDULE

    // find the earliest point to schedule p.
    unsigned int t = schedule(s, max_t, p);

    // keep track of schedule length
    max_t = std::max(max_t, t + length(p));

#ifdef TRACE_SCHEDULE
    std::cerr << "  " << p << "@" << t << "\n";
#endif // TRACE_SCHEDULE

    // remove p and its inverse from the worklist
    worklist.erase(p);
    worklist.erase(inverse(p));
  }

  // dump the schedule to the output stream
  os << boost::format("schedule: %1%\n") % max_t;
  for(schedule_t::const_iterator i(s.begin()), ie(s.end()); i != ie; i++)
  {
    for(unsigned int t = 0; t < i->first; t++)
    {
      os << " ";
    }

    for (unsigned int a = 0; a < i->second.la; a++)
    {
      os << i->second.da;
    }

    for (unsigned int b = 0; b < i->second.lb; b++)
    {
      os << i->second.db;
    }

    os << "\n";
  }

  return max_t;
}

/// Construct a schedule for an NxN mesh, based on communication patterns.
/// @param os Output stream to dump the heuristic schedule.
/// @param n The size of the mesh.
/// @return The length of the schedule.
unsigned int schedule_mesh_pattern(std::ostream &os, unsigned int n)
{
  patterns_t patterns;

  for(unsigned int i = 1; i < n; i++)
  {
    patterns.insert(pattern_t(NORTH, i, NONE, 0));
    patterns.insert(pattern_t(EAST, i, NONE, 0));
    patterns.insert(pattern_t(SOUTH, i, NONE, 0));
    patterns.insert(pattern_t(WEST, i, NONE, 0));
    for(unsigned int j = 1; j < n; j++)
    {
      patterns.insert(pattern_t(NORTH, i, EAST, j));
      patterns.insert(pattern_t(NORTH, i, WEST, j));
      patterns.insert(pattern_t(EAST, i, NORTH, j));
      patterns.insert(pattern_t(EAST, i, SOUTH, j));
      patterns.insert(pattern_t(SOUTH, i, EAST, j));
      patterns.insert(pattern_t(SOUTH, i, WEST, j));
      patterns.insert(pattern_t(WEST, i, NORTH, j));
      patterns.insert(pattern_t(WEST, i, SOUTH, j));
    }
  }

  // make a heuristic schedule
  return schedule_heuristic(os, patterns);
}

/// Construct a schedule for an NxN torus, based on communication patterns.
/// @param os Output stream to dump the heuristic schedule.
/// @param n The size of the torus.
/// @return The length of the schedule.
unsigned int schedule_torus_pattern(std::ostream &os, unsigned int n)
{
  patterns_t patterns;

  for(unsigned int i = 0; i < n; i++)
  {
    for(unsigned int j = 0; j < n; j++)
    {
      if (i != 0)
      {
        pattern_t p(EAST, i, (j == 0) ? NONE : SOUTH, j);
        
        patterns.insert(p);
        patterns.insert(inverse(p));
      }
      else if (j != 0)
      {
        pattern_t p(SOUTH, j, NONE, 0);
        
        patterns.insert(p);
      }
    }
  }

  // make a heuristic schedule
  return schedule_heuristic(os, patterns);
}

/// Construct a schedule for an NxN bi-directional torus, based on communication
/// patterns.
/// @param os Output stream to dump the heuristic schedule.
/// @param n The size of the bi-torus.
/// @return The length of the schedule.
unsigned int schedule_bitorus_pattern(std::ostream &os, unsigned int n)
{
  patterns_t patterns;

  unsigned int ref = n/2;
  for(unsigned int i = 0; i < n; i++)
  {
    for(unsigned int j = 0; j < n; j++)
    {
      if (i != ref)
      {
        direction_t da = (i < ref) ? EAST : WEST;
        unsigned int la = (i < ref) ? ref - i : i -ref;

        direction_t db = (j == ref) ? NONE : (j < ref ? NORTH : SOUTH);
        unsigned int lb = j < ref ? ref - j : j - ref;

        pattern_t p(da, la, db, lb);

        patterns.insert(p);
        patterns.insert(inverse(p));
      }
      else if (j != ref)
      {
        direction_t da = j < ref ? NORTH : SOUTH;
        unsigned int la = j < ref ? ref - j : j - ref;

        pattern_t p(da, la, NONE, 0);

        patterns.insert(p);
      }
    }
  }

  // make a heuristic schedule
  return schedule_heuristic(os, patterns);
}

