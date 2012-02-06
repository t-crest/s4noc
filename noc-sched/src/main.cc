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
#include "heuristic.h"

#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <istream>

#include <boost/program_options.hpp>

extern void print_lp(std::ostream &os, const noc_t &noc, unsigned int bound);

/// Parse the name of the "hsel" program option from an input stream.
///  @param s The input stream.
///  @param res The result.
///  @return The original input stream.
std::istream& operator>>(std::istream& s, candidate_selection_e &cnd_sel)
{
  // read string
  std::string tmp;
  s >> tmp;

  // check all alternatives
  if (tmp == "rnd")
  {
    cnd_sel = RND;
  }
  else if (tmp == "lng")
  {
    cnd_sel = LNG;
  }
  else if (tmp == "sht")
  {
    cnd_sel = SHT;
  }
  else if (tmp == "cnfl")
  {
    cnd_sel = CNFL;
  }
  else throw boost::program_options::validation_error(
                 boost::program_options::validation_error::invalid_option_value,
                 "Invalid value for hsel, possible value: rnd, lng, cnfl",
                 "hsel");

  return s;
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
    ("hshd", boost::program_options::value<std::string>(), "schedule using a heuristic to a file")
    ("hsel", boost::program_options::value<candidate_selection_e>()->default_value(LNG), "choose candidate selection for heuristic")
    ("size", "dump network size")
    ("bound", boost::program_options::value<int>(), "give a bound for the ILP formulation")
    ("mesh", boost::program_options::value<int>(), "create a NxN mesh NoC")
    ("torus", boost::program_options::value<int>(),"create a NxN torus NoC")
    ("bitorus", boost::program_options::value<int>(),"create a NxN bi-directional torus NoC")
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
  else if (vm.count("bitorus"))
  {
    unsigned int n = vm["bitorus"].as<int>();
    noc = &noc_t::create_bitorus(n, n);
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
      if (!(*d)->is_router())
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

  if (vm.count("hshd"))
  {
    std::ostream &hs(get_stream(vm["hshd"].as<std::string>()));
    candidate_selection_e cnd_sel(vm["hsel"].as<candidate_selection_e>());
    if (vm.count("mesh"))
    {
      unsigned int n = vm["mesh"].as<int>();
      bound = std::min(bound, schedule_mesh_pattern(hs, cnd_sel, n));
    }
    else if (vm.count("torus"))
    {
      unsigned int n = vm["torus"].as<int>();
      bound = std::min(bound, schedule_torus_pattern(hs, cnd_sel, n));
    }
    else if (vm.count("bitorus"))
    {
      unsigned int n = vm["bitorus"].as<int>();
      bound = std::min(bound, schedule_bitorus_pattern(hs, cnd_sel, n));
    }
    free_stream(hs);
  }
  
  if (vm.count("lp"))
  {
    std::ostream &ls(get_stream(vm["lp"].as<std::string>()));
    print_lp(ls, *noc, bound);
    free_stream(ls);
  }

  return 0;
}
