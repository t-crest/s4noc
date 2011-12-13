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

#ifndef NOC_H
#define NOC_H

#include <ostream>
#include <set>
#include <cmath>

#include <boost/format.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/lexical_cast.hpp>

// forward declaration
class noc_t;

/// The kind of nodes in the NoC
enum node_kind_e
{
  /// A CPU node
  CPU,
  /// A router
  ROUTER
};

/// A simple representation of a node in the NoC.
class node_t
{
  friend std::ostream &operator<<(std::ostream &os, const node_t &n);
private:
  /// The kind of the node, e.g., router, cpu, ....
  node_kind_e Kind;

  /// The column of the node.
  unsigned int Column;

  /// The row of the node.
  unsigned int Row;

public:
  /// Construct a node.
  /// @param kind The kind of the node, i.e., a router, a CPU, ...
  /// @param column The column index of the node.
  /// @param row The row index of the node.
  node_t(node_kind_e kind, unsigned int column, unsigned int row) :
      Kind(kind), Column(column), Row(row)
  {
  }

  /// Return the kind of the NoC node.
  /// @return Return the kind of the NoC node.
  node_kind_e get_kind() const
  {
    return Kind;
  }

  unsigned int get_column() const
  {
    return Column;
  }

  unsigned int get_row() const
  {
    return Row;
  }
};

/// Print a textual representation of a node kind to the output stream.
/// @param os The output stream.
/// @param kind The node kind.
std::ostream &operator<<(std::ostream &os, node_kind_e kind)
{
  switch(kind)
  {
    case CPU:
      os << "c";
      break;
    case ROUTER:
      os << "r";
      break;
  }

  return os;
}

/// Print a node of the NoC to the output stream.
/// @param os The output stream.
/// @param n The node.
std::ostream &operator<<(std::ostream &os, const node_t &n)
{
  return os << boost::format("%1%%2%_%3%") % n.Kind % n.Column % n.Row;
}

/// A set of NoC nodes.
typedef std::set<const node_t*> nodes_t;

/// A link within the NoC.
class link_t
{
  friend std::ostream &operator<<(std::ostream &os, const link_t &l);
private:
  friend class noc_t;
  /// The source node of the link.
  const node_t &S;

  /// The destination node of the link.
  const node_t &D;

public:
  /// Construct a link.
  /// @param s The source node of the link.
  /// @param d The destination node of the link.
  link_t(const node_t &s, const node_t &d) : S(s), D(d)
  {
  }

  /// Return the source node of the link.
  /// @return Return the source node of the link.
  const node_t &get_source() const
  {
    return S;
  }

  /// Return the destination node of the link.
  /// @return Return the destination node of the link.
  const node_t &get_destination() const
  {
    return D;
  }
};

/// Print a link of the NoC to the output stream.
/// @param os The output stream.
/// @param l The link.
std::ostream &operator<<(std::ostream &os, const link_t &l)
{
  return os << boost::format("%1%_%2%") % l.S % l.D;
}

/// A set of links.
typedef std::set<const link_t*> links_t;

/// A simple representation of a NoC with an open network structure.
class noc_t
{
private:
  /// The nodes of the NoC.
  nodes_t Nodes;

  /// The links of the NoC.
  links_t Links;

  /// Perfect shuffle for the construction of fat trees.
  /// @param X Router position.
  /// @param Y Number of Ports.
  /// @param i Port of router.
  static int perfect_shuffle(int X, int Y, int  i)
  {
    return (Y*i + i/(X/Y)) % X;
  }

  /// Perfect shuffle for the construction of fat trees.
  /// @param X Router position.
  /// @param Y Number of Ports.
  /// @param i Port of router.
  static int inverse_perfect_shuffle(int X, int Y, int i)
  {
    return (i/Y + i*(X/Y)) % X;
  }

  /// Implement the shuffle function to construct fat trees.
  /// @param X Number of routers.
  /// @param Y Number of ports.
  /// @param S Number of layer.
  /// @param s Current layer.
  /// @param p Current port.
  static int benes_shuffle(int X, int Y, int S, int s, int p)
  {
    int i, k, K;

    if (s < (S - 1)/2)
    {
      K= X/(int(pow(Y, s)));
    }
    else
    {
      K = X/(int(pow(Y, (S-1) - s - 1)));
    }

    i = p / K;
    k = p % K;

    if (s < (S - 1)/2)
    {
      return i*K + inverse_perfect_shuffle(K, Y, k);
    }
    else
    {
      return i*K + perfect_shuffle(K, Y, k);
    }
  }
  
public:
  /// Create a new node and append it to the NoC's node list.
  /// @param kind The kind of the node, i.e., a router, a CPU, ...
  /// @param column The column index of the node.
  /// @param row The row index of the node.
  node_t &create_node(node_kind_e kind, unsigned int column, unsigned int row)
  {
    node_t *new_node = new node_t(kind, column, row);
    Nodes.insert(new_node);
    return *new_node;
  }

  /// Create a new link and append it to the NoC's link list.
  /// @param s The source node of the link.
  /// @param d The destination node of the link.
  link_t &create_link(const node_t &s, const node_t &d)
  {
    link_t *new_link = new link_t(s, d);
    Links.insert(new_link);
    return *new_link;
  }

  /// Create a two (bidirectional) links and append them to the NoC's link list.
  /// @param n1 The first node of the links.
  /// @param n1 The second node of the links.
  boost::tuple<link_t&, link_t&> create_bilink(const node_t &n1,
                                                 const node_t &n2)
  {
    link_t *new_link1 = new link_t(n1, n2);
    link_t *new_link2 = new link_t(n2, n1);
    Links.insert(new_link1);
    Links.insert(new_link2);
    return boost::tuple<link_t&, link_t&>(*new_link1, *new_link2);
  }

  /// Return the node list of the NoC.
  /// @return The node list of the NoC.
  const nodes_t &get_nodes() const
  {
    return Nodes;
  }
    
  /// Return the link list of the NoC.
  /// @return The link list of the NoC.
  const links_t &get_links() const
  {
    return Links;
  }

  /// Dump the NoC as a graphviz-dot graph.
  /// @param os The output stream.
  void dot(std::ostream &os)
  {
    os << "digraph noc\n{\n";
    for(nodes_t::const_iterator i(Nodes.begin()), ie(Nodes.end()); i != ie; i++)
    {
      os << boost::format("  %1%;\n") % **i;
    }
    os << "\n";
    for(links_t::const_iterator i(Links.begin()), ie(Links.end()); i != ie; i++)
    {
      os << boost::format("  %1% -> %2%;\n") % (*i)->S % (*i)->D;
    }
    os << "}\n";
  }

  /// Get all the predecessors of a link, i.e., all other links leading the 
  /// source node of the link, except for those that originate from the link's
  /// destination.
  /// @param l The link.
  /// @return The set of predecessor links of l.
  links_t pred(const link_t &l) const
  {
    links_t P;
    for(links_t::const_iterator i(Links.begin()), ie(Links.end()); i != ie; i++)
    {
      // is the destination equal to the source of link l? 
      if (&(*i)->D == &l.S
          // prevent two-cycles
          && &(*i)->S != &l.D)
      {
        P.insert(*i);
      }
    }

    return P;
  }

  /// Create a new mesh NoC with NxM nodes each with a router.
  /// @param n The number of columns in the NoC.
  /// @param m The number of rows in the NoC.
  /// @return A new instance of a NoC with all nodes and links constructed.
  static noc_t &create_mesh(unsigned int n, unsigned int m)
  {
    noc_t *new_noc = new noc_t();

    node_t *router[n][m];
    node_t *cpu[n][m];

    for(unsigned int i = 0; i  < n; i++)
    {
      for(unsigned int j = 0; j  < m; j++)
      {
        router[i][j] = &new_noc->create_node(ROUTER, i, j);
        cpu[i][j] = &new_noc->create_node(CPU, i, j);

        // connect CPU to router
        new_noc->create_bilink(*cpu[i][j], *router[i][j]);

        // connect router to neighbors
        if (i > 0)
        {
          new_noc->create_bilink(*router[i][j], *router[i - 1][j]);
        }

        if (j > 0)
        {
          new_noc->create_bilink(*router[i][j], *router[i][j - 1]);
        }
      }
    }

    return *new_noc;
  }

  /// Create a new torus NoC with NxM nodes each with a router.
  /// @param n The number of columns in the NoC.
  /// @param m The number of rows in the NoC.
  /// @return A new instance of a NoC with all nodes and links constructed.
  static noc_t &create_torus(unsigned int n, unsigned int m)
  {
    noc_t *new_noc = new noc_t();

    node_t *router[n][m];
    node_t *cpu[n][m];

    for(unsigned int i = 0; i  < n; i++)
    {
      for(unsigned int j = 0; j  < m; j++)
      {
        router[i][j] = &new_noc->create_node(ROUTER, i, j);
        cpu[i][j] = &new_noc->create_node(CPU, i, j);

        // connect CPU to router
        new_noc->create_bilink(*cpu[i][j], *router[i][j]);

        // connect router to neighbors
        if (i > 0)
        {
          new_noc->create_link(*router[i][j], *router[i - 1][j]);
        }

        if (j > 0)
        {
          new_noc->create_link(*router[i][j], *router[i][j - 1]);
        }
      }

      // close torus
      new_noc->create_link(*router[i][0], *router[i][m - 1]);
    }

    // close torus
    for(unsigned int j = 0; j  < m; j++)
    {
      new_noc->create_link(*router[0][j], *router[m - 1][j]);
    }

    return *new_noc;
  }

  /// Create a new double-torus NoC with NxM nodes each with a router.
  /// @param n The number of columns in the NoC.
  /// @param m The number of rows in the NoC.
  /// @return A new instance of a NoC with all nodes and links constructed.
  static noc_t &create_double_torus(unsigned int n, unsigned int m)
  {
    noc_t *new_noc = new noc_t();

    node_t *router[n][m];
    node_t *cpu[n][m];

    for(unsigned int i = 0; i  < n; i++)
    {
      for(unsigned int j = 0; j  < m; j++)
      {
        router[i][j] = &new_noc->create_node(ROUTER, i, j);
        cpu[i][j] = &new_noc->create_node(CPU, i, j);

        // connect CPU to router
        new_noc->create_bilink(*cpu[i][j], *router[i][j]);

        // connect router to neighbors
        if (i > 0)
        {
          new_noc->create_bilink(*router[i][j], *router[i - 1][j]);
        }

        if (j > 0)
        {
          new_noc->create_bilink(*router[i][j], *router[i][j - 1]);
        }
      }

      // close torus
      new_noc->create_bilink(*router[i][0], *router[i][m - 1]);
    }

    // close torus
    for(unsigned int j = 0; j  < m; j++)
    {
      new_noc->create_bilink(*router[0][j], *router[m - 1][j]);
    }

    return *new_noc;
  }

  /// Create a new tree NoC with N leaf nodes.
  /// @param n The number of leaf nodes in the NoC.
  /// @return A new instance of a NoC with all nodes and links constructed.
  static noc_t &create_tree(unsigned int n)
  {
    noc_t *new_noc = new noc_t();

    node_t *nodes[n + 1];

    // create leafs
    for(unsigned int i = 0; i  < n; i++)
    {
      nodes[i] = &new_noc->create_node(CPU, i, 0);
    }

    // make sure last element is cleared
    nodes[n] = NULL;

    unsigned int j = 1;
    while (n != 1)
    {
      n = std::ceil( ((float)n) / 2.0 );


      for(unsigned int i = 0; i  < n; i++)
      {
        node_t *router = &new_noc->create_node(ROUTER, i, j);

        // connect to children
        new_noc->create_bilink(*router, *nodes[2 * i]);
        if (nodes[2 * i + 1])
        {
          new_noc->create_bilink(*router, *nodes[2 * i + 1]);
        }

        nodes[i] = router;
        nodes[i + 1] = NULL;
      }

      j++;
    }

    return *new_noc;
  }
  
  /// Create a new fat-tree NoC with N leaf nodes.
  /// @param n The number of leaf nodes in the NoC.
  /// @return A new instance of a NoC with all nodes and links constructed.
  static noc_t &create_fat_tree(unsigned int n)
  {
    noc_t *new_noc = new noc_t();

    int M = n;
    int L = std::ceil(log2(M/4)) + 1;
    int N = 4;
    int S = 2*L - 1;
    int SS = pow((N/2), L - 1);

    node_t *nodes[M];
    node_t *router[S][SS];
    
    // create leafs
    for(unsigned int i = 0; i  < M; i++)
    {
      nodes[i] = &new_noc->create_node(CPU, i, 0);
    }

    // create router
    for(unsigned int s = 0; s < S; s++)
    {
      for(unsigned int ss = 0; ss < SS; ss++)
      {
        router[s][ss] = &new_noc->create_node(ROUTER, s, ss);
      }
    }

    // connect router to leafs
    for(unsigned int ss = 0; ss < SS; ss++)
    {
      new_noc->create_bilink(*router[0][ss], *nodes[2*ss]);
      new_noc->create_bilink(*router[0][ss], *nodes[2*ss + 1]);
      new_noc->create_bilink(*router[S - 1][ss], *nodes[2*SS + 2*ss]);
      new_noc->create_bilink(*router[S - 1][ss], *nodes[2*SS + 2*ss + 1]);
    }

    // connect router
    for(unsigned int s = 0; s < (S - 1); s++)
    {
      for(unsigned int p = 0; p < SS*2; p++)
      {
        unsigned p_ = benes_shuffle(M/2, N/2, S, s, p);
        if (s < (S - 1)/2)
          new_noc->create_bilink(*router[(S - 1)/2 - s][p/2],
                               *router[(S - 1)/2 - s - 1][p_/2]);
        else
          new_noc->create_bilink(*router[s][p/2], *router[s + 1][p_/2]);
      }
    }
    
    return *new_noc;
  }
};

#endif // NOC_H
