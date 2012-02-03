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

#ifndef HEURISTIC_H
#define HEURISTIC_H

#include <ostream>

/// Determine how candidate patterns are selected by the heuristic scheduling 
/// algorithm.
enum candidate_selection_e
{
  /// Randomly select one candidate pattern.
  RND,
  /// Randomly select one of the longest candidate patterns.
  LNG,
  /// Randomly select one of the longest candidate pattern without a conflict 
  /// to the previously selected candidate.
  CNFL,
};

/// Construct a schedule for an NxN mesh, based on communication patterns.
/// @param os Output stream to dump the heuristic schedule.
/// @param n The size of the mesh.
/// @return The length of the schedule.
extern unsigned int schedule_mesh_pattern(std::ostream &os,
                                          candidate_selection_e cnd_sel,
                                          unsigned int n);

/// Construct a schedule for an NxN torus, based on communication patterns.
/// @param os Output stream to dump the heuristic schedule.
/// @param n The size of the torus.
/// @return The length of the schedule.
extern unsigned int schedule_torus_pattern(std::ostream &os,
                                           candidate_selection_e cnd_sel,
                                           unsigned int n);

/// Construct a schedule for an NxN bi-directional torus, based on communication
/// patterns.
/// @param os Output stream to dump the heuristic schedule.
/// @param n The size of the bi-torus.
/// @return The length of the schedule.
extern unsigned int schedule_bitorus_pattern(std::ostream &os,
                                             candidate_selection_e cnd_sel,
                                             unsigned int n);
#endif // HEURISTIC_H
