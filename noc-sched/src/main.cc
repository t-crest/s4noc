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
#include <fstream>
#include <sstream>
#include <cassert>
#include <cmath>

#include <boost/program_options.hpp>

/// Check whether the node is a router node.
/// @param n The node.
/// @return True if the node is a router, false otherwise.
static bool is_router(const node_t &n)
{
  return n.get_kind() == ROUTER;
}

#ifndef NDEBUG
std::set<std::string> ILP_names;
#endif

/// Get the name of the ILP variable for a link, a destination node, and a
/// cycle.
/// @param l The link.
/// @param d The destination node.
/// @param c The cycle.
static void el_(const link_t &l, const node_t &d, unsigned int c,
                std::ostream &os)
{
  os << l << "____" << d << "____" << c;
}

/// Get the name of the ILP variable for a link, a destination node, and a 
/// cycle.
/// @param l The link.
/// @param d The destination node.
/// @param c The cycle.
static void el(const link_t &l, const node_t &d, unsigned int c,
               std::ostream &os)
{
  el_(l, d, c, os);

#ifndef NDEBUG
  const node_t &ls(l.get_source());
  const node_t &ld(l.get_destination());

  assert(is_router(ls) || &ls != &d);
  assert(is_router(ld) || &ld == &d);

  std::stringstream s;
  el_(l, d, c, s);
  if (ILP_names.find(s.str()) == ILP_names.end())
  {
    std::cerr << s.str();
  }
  assert(ILP_names.find(s.str()) != ILP_names.end());
#endif
}

/// Print ILP equations to derive a routing schedule for the NoC.
/// @param os An output stream to write the equations to.
/// @param noc An instance of a given NoC (topology).
/// @param bound An upper bound on the schedule length (depending on the NoC 
/// topology)
void print_lp(std::ostream &os, const noc_t &noc, unsigned int bound)
{
  const nodes_t &N = noc.get_nodes();
  const links_t &L = noc.get_links();

  // count non-router nodes
  unsigned int non_router = 0;
  for(nodes_t::const_iterator d(N.begin()), de(N.end());d != de; d++)
  {
    if (!is_router(**d))
    {
      non_router++;
    }
  }

  unsigned int MAXC = bound;

  // count constraints
  unsigned int cnt = 0;

  // make a list of all valid ILP variable names appearing in the equations.
#ifndef NDEBUG
  for(links_t::const_iterator l(L.begin()), le(L.end()); l != le; l++)
  {
    const node_t &ls((*l)->get_source());
    const node_t &ld((*l)->get_destination());

    for(nodes_t::const_iterator d(N.begin()), de(N.end());d != de; d++)
    {
      if ((is_router(ls) || &ls != *d) &&
          (is_router(ld) || &ld == *d) &&
          !is_router(**d))
      {
        for(unsigned int c = 0; c != MAXC + 1; c++)
        {
          std::stringstream s;
          el_(**l, **d, c, s);
          ILP_names.insert(s.str());
        }
      }
    }
  }
#endif
  os << "Minimize\ncycles\n";

  for(links_t::const_iterator l(L.begin()), le(L.end()); l != le; l++)
  {
    const node_t &ls((*l)->get_source());
    const node_t &ld((*l)->get_destination());

    for(nodes_t::const_iterator d(N.begin()), de(N.end());d != de; d++)
    {
      if ((is_router(ls) || &ls != *d) &&
          (is_router(ld) || &ld == *d) &&
          !is_router(**d))
      {
        for(unsigned int c = 0; c != MAXC + 1; c++)
        {
          os << " + " << 1.0/(L.size()*non_router*MAXC) << " ";
          el_(**l, **d, c, os);
        }
        os << "\n";
      }
    }
  }
  
  os << "\n\nSubject To\n";

  // derive the last cycle with an active link.
  for(unsigned int c = 1; c != MAXC + 1; c++)
  {
    os << "c" << cnt++ << ":\t" << non_router << " cycle_" << c;

    for(links_t::const_iterator l(L.begin()), le(L.end()); l != le; l++)
    {
      const node_t &ld((*l)->get_destination());

      // a link to a non-router node
      if (!is_router(ld))
      {
        os << " - ";
        el(**l, ld, c, os);
      }
    }
    os << " >= 0\n";

    os << "c" << cnt++ << ":\tcycles - " << c << " cycle_" << c << " >= 0\n";
  }

  // ensure that routers never produce values out of nothing at cycle 0
  for(links_t::const_iterator l(L.begin()), le(L.end()); l != le; l++)
  {
    const node_t &ls((*l)->get_source());
    const node_t &ld((*l)->get_destination());

    // do not constrain the ILP variables for non-router nodes, since they
    // can produce values at any moment
    if (is_router(ls))
    {
      for(nodes_t::const_iterator d(N.begin()), de(N.end());d != de; d++)
      {
        if ((is_router(ld) || &ld == *d) &&
            !is_router(**d))
        {
          // ensure that routers never produce values out of nothing at cycle 0
          os << "i" << cnt++ << ":\t";
          el(**l, **d, 0, os);
          os << " = 0\n";
        }
      }
    }
  }

  // preserve in- and out-going flow at routers on every cycle
  // find all router
  for(nodes_t::const_iterator r(N.begin()), re(N.end());r != re; r++)
  {
    if (is_router(**r))
    {
      for(nodes_t::const_iterator d(N.begin()), de(N.end());d != de; d++)
      {
        if (!is_router(**d))
        {
          for(unsigned int c = 0; c != MAXC; c++)
          {
            os << "f" << cnt++ << ":\t";

            for(links_t::const_iterator l(L.begin()), le(L.end()); l != le; l++)
            {
              const node_t &ls((*l)->get_source());
              const node_t &ld((*l)->get_destination());

              // a link to/from the router
              if (&ls == *r || &ld == *r)
              {
                if ((is_router(ls) || &ls != *d) &&
                    (is_router(ld) || &ld == *d))
                {
                  // sum out-flow
                  if (&ls == *r)
                  {
                    os << " + ";
                    el(**l, **d, c + 1, os);
                  }
                  // subtract in-flow
                  if (&ld == *r)
                  {
                    os << " - ";
                    el(**l, **d, c, os);
                  }
                }
              }
            }

            // in-flow and out-flow have to match
            os << " = 0\n";
          }
        }
      }
    }
  }

  // restrict each link to one message per cycle
  for(unsigned int c = 0; c != MAXC + 1; c++)
  {
    for(links_t::const_iterator l(L.begin()), le(L.end()); l != le; l++)
    {
      const node_t &ls((*l)->get_source());
      const node_t &ld((*l)->get_destination());

      os << "u" << cnt++ << ":\t";

      for(nodes_t::const_iterator d(N.begin()), de(N.end());d != de; d++)
      {
        if ((is_router(ls) || &ls != *d) &&
            (is_router(ld) || &ld == *d) &&
            !is_router(**d))
        {
          os << " + ";
          el(**l, **d, c, os);
        }
      }

      os << " <= 1\n";
    }
  }

  // ensure that every node receives a message from every other node
  for(links_t::const_iterator l(L.begin()), le(L.end()); l != le; l++)
  {
    const node_t &ld((*l)->get_destination());

    // a link to a non-router node
    if (!is_router(ld))
    {
      // consider all communications over this links leading to the non-router 
      // node over all cycles
      os << "r" << cnt++ << ":\t";
      for(unsigned int c = 0; c != MAXC + 1; c++)
      {
        os << " + ";
        el(**l, ld, c, os);
      }

      os << " = " << (non_router - 1) << "\n";
    }
  }
  
  // ensure that every node sends once to every other node
  for(links_t::const_iterator l(L.begin()), le(L.end()); l != le; l++)
  {
    const node_t &ls((*l)->get_source());

    // a link from a non-router node
    if (!is_router(ls))
    {
      for(nodes_t::const_iterator d(N.begin()), de(N.end());d != de; d++)
      {
        // only send to other non-router nodes
        if (*d != &ls && !is_router(**d))
        {
          // disallow sending messages in the last cycle
          os << "n" << cnt++ << ":\t";
          el(**l, **d, MAXC, os);
          os << " = 0\n";

          // consider all links leading from the non-router node to the 
          // destination.
          os << "s" << cnt++ << ":\t";
          for(unsigned int c = 0; c != MAXC; c++)
          {
            os << " + ";
            el(**l, **d, c, os);
          }

          os << " = 1\n";
        }
      }
    }
  }

  // // // // // // // // // // // // // // // // // // // // // // // // // //
  os << "\n\nBounds\n";
  os << (non_router - 1) << " <= cycles <= " << (non_router*non_router) << "\n";

  // // // // // // // // // // // // // // // // // // // // // // // // // //
  os << "\n\nBinaries\n";
  for(links_t::const_iterator l(L.begin()), le(L.end()); l != le; l++)
  {
    const node_t &ls((*l)->get_source());
    const node_t &ld((*l)->get_destination());

    for(nodes_t::const_iterator d(N.begin()), de(N.end());d != de; d++)
    {
      if ((is_router(ls) || &ls != *d) &&
          (is_router(ld) || &ld == *d) &
          !is_router(**d))
      {
        for(unsigned int c = 0; c != MAXC + 1; c++)
        {
          el(**l, **d, c, os);
          os << "\n";
        }
      }
    }
  }
  
  for(unsigned int c = 1; c != MAXC + 1; c++)
  {
    os << "cycle_" << c << "\n";
  }
  
  os << "Generals\ncycles\n";
  os << "End\n";
}

/// Open an output file given by name.
/// @param name The name of the output file.
/// @return An output stream to write to the file given by the name. When the 
/// name is "-" or the standard output stream is returned.
static std::ostream &get_stream(const std::string &name)
{
  if (name == "-")
    return std::cout;
  else
  {
    return *new std::ofstream(name.c_str());
  }
}

/// possibly free an output stream previously opened the get_stream function.
/// \see get_stream
/// @param os The output stream
static void free_stream(std::ostream &os)
{
  if (&os != &std::cout)
  {
    delete &os;
  }
}

int main(int argc, char **argv)
{
  boost::program_options::options_description desc("Allowed options");
  desc.add_options()
    ("help", "produce help message")
    ("dot", boost::program_options::value<std::string>(), "dump NoC as dot graph file")
    ("lp", boost::program_options::value<std::string>(), "dump ILP equations to a file")
    ("size", "dump network size")
    ("bound", boost::program_options::value<int>(), "give a bound for the ILP formulation")
    ("mesh", boost::program_options::value<int>(), "create a NxN mesh NoC")
    ("torus", boost::program_options::value<int>(),"create a NxN torus NoC")
    ("dtorus", boost::program_options::value<int>(),"create a NxN double-torus NoC")
    ("tree", boost::program_options::value<int>(),"create a tree NoC with N leafs")
    ("ftree", boost::program_options::value<int>(),"create a fat-tree NoC with N leafs");

  boost::program_options::variables_map vm;
  boost::program_options::store(
              boost::program_options::parse_command_line(argc, argv, desc), vm);
  boost::program_options::notify(vm);

  if (vm.count("help")) {
    std::cout << desc << "\n";
    return 1;
  }
  
  noc_t *noc = NULL;
  unsigned int bound = 0;
  
  if (vm.count("mesh"))
  {
    unsigned int n = vm["mesh"].as<int>();
    noc = &noc_t::create_mesh(n, n);
    // TODO: use analytical bounds from paper
    bound = 1.5*n*n;
  }
  else if (vm.count("torus"))
  {
    unsigned int n = vm["torus"].as<int>();
    noc = &noc_t::create_torus(n, n);
    // TODO: use analytical bounds from paper
    bound = 3*n*n;
  }
  else if (vm.count("dtorus"))
  {
    unsigned int n = vm["dtorus"].as<int>();
    noc = &noc_t::create_double_torus(n, n);
    // TODO: use analytical bounds from paper
    bound = 20*n*n;
  }
  else if (vm.count("tree"))
  {
    unsigned int n = vm["tree"].as<int>();
    noc = &noc_t::create_tree(n);
    // TODO: use analytical bounds from paper
    bound = 2*n*n;
  }
  else if (vm.count("ftree"))
  {
    unsigned int n = vm["ftree"].as<int>();
    noc = &noc_t::create_fat_tree(n);
    // TODO: use analytical bounds from paper
    bound = 3*n*n;
  }
  else
  {
    std::cout << desc << "\n";
    return 1;
  }

  if (vm.count("bound"))
  {
    bound = vm["bound"].as<int>();
  }
  
  if (vm.count("dot"))
  {
    std::ostream &ds(get_stream(vm["dot"].as<std::string>()));
    noc->dot(ds);
    free_stream(ds);
  }

  if (vm.count("size"))
  {
    const nodes_t &N = noc->get_nodes();
    const links_t &L = noc->get_links();

    // count non-router nodes
    unsigned int non_router = 0;
    unsigned int router = 0;
    for(nodes_t::const_iterator d(N.begin()), de(N.end());d != de; d++)
    {
      if (!is_router(**d))
      {
        non_router++;
      }
      else
        router++;
    }

    std::cout << boost::format("Network Size: nodes = %1%, router = %2%, "
                               "devices = %3%, links = %4%\n\n")
              % N.size() % router % non_router % L.size();
  }
  
  if (vm.count("lp"))
  {
    std::ostream &ls(get_stream(vm["lp"].as<std::string>()));
    print_lp(ls, *noc, bound);
    free_stream(ls);
  }

  return 0;
}
