# 
#  This file is part of the s4NoC's noc-sched.
#  noc-sched is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
# 
#  noc-sched is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
# 
#  You should have received a copy of the GNU General Public License
#  along with noc-sched. If not, see <http://www.gnu.org/licenses/>.
#

BEGIN {
  max = 0;
  FS="\""
}

function cpu(r)
{
  return "c" substr(r, 2);
}

function north(r)
{
  split(substr(r, 2), ridx, "_");
  if (ridx[1] == 0)
    return "";
  else
    return "r" (ridx[1]-1)"_"(ridx[2]);
}

function south(r)
{
  split(substr(r, 2), ridx, "_");
  x = "r" (ridx[1] + 1)"_"(ridx[2])
  if (x in noc_nodes)
    return x;
  else
    return "";
}

function west(r)
{
  split(substr(r, 2), ridx, "_");
  x = "r" (ridx[1])"_"(ridx[2] - 1)
  if (x in noc_nodes)
    return x;
  else
    return "";
}

function east(r)
{
  split(substr(r, 2), ridx, "_");
  x = "r" (ridx[1])"_"(ridx[2] + 1)
  if (x in noc_nodes)
    return x;
  else
    return "";
}

function in_north(r, c, n, e, s, w, d)
{
  l = r"-"north(r) "@" (c+1);

  e = east(r)"-"r "@" c;
  s = south(r)"-"r "@" c;
  w = west(r)"-"r "@" c;
  d = cpu(r)"-"r "@" c;

  if (!(l in flow))
    return "-"
  else if(flow[l] == flow[e]) 
  {
    return "e";
  }
  else if(flow[l] == flow[s])
    return "s";
  else if(flow[l] == flow[w])
    return "w";
  else if(flow[l] == flow[d])
    return "c";
  else
    return "-";
}

function in_east(r, c, n, e, s, w, d)
{
  l = r"-"east(r) "@" (c+1);

  n = north(r)"-"r "@" c;
  s = south(r)"-"r "@" c;
  w = west(r)"-"r "@" c;
  d = cpu(r)"-"r "@" c;

  if (!(l in flow))
    return "-"
  else if(flow[l] == flow[n]) 
  {
    return "n";
  }
  else if(flow[l] == flow[s])
    return "s";
  else if(flow[l] == flow[w])
    return "w";
  else if(flow[l] == flow[d])
    return "c";
  else
    return "-";
}

function in_south(r, c, n, e, s, w, d)
{
  l = r"-"south(r) "@" (c+1);

  n = north(r)"-"r "@" c;
  e = east(r)"-"r "@" c;
  w = west(r)"-"r "@" c;
  d = cpu(r)"-"r "@" c;

  if (!(l in flow))
    return "-"
  else if(flow[l] == flow[n]) 
  {
    return "n";
  }
  else if(flow[l] == flow[e])
    return "e";
  else if(flow[l] == flow[w])
    return "w";
  else if(flow[l] == flow[d])
    return "c";
  else
    return "-";
}

function in_west(r, c, n, e, s, w, d)
{
  l = r"-"west(r) "@" (c+1);

  n = north(r)"-"r "@" c;
  e = east(r)"-"r "@" c;
  s = south(r)"-"r "@" c;
  d = cpu(r)"-"r "@" c;

  if (!(l in flow))
    return "-"
  if(flow[l] == flow[n]) 
    return "n";
  else if(flow[l] == flow[e])
    return "e";
  else if(flow[l] == flow[s])
    return "s";
  else if(flow[l] == flow[d])
    return "c";
  else
    return "-";
}

function in_cpu(r, c, n, e, s, w, d)
{
  d = cpu(r)
  l = r"-"d "@" (c+1);

  n = north(r)"-"r "@" c;
  e = east(r)"-"r "@" c;
  s = south(r)"-"r "@" c;
  w = west(r)"-"r "@" c;

  if (!(l in flow))
    return "-"
  if(flow[l] == flow[n]) 
    return "n";
  else if(flow[l] == flow[e])
    return "e";
  else if(flow[l] == flow[s])
    return "s";
  else if(flow[l] == flow[w])
    return "w";
  else
    return "-";
}

END {
  for (n in noc_nodes)
  {
    if (index(n, "c") == 0)
    {
      print "\n" n "\tn\te\ts\tw\tc";
      for (c = 0; c < max; c++)
      {
        print c "\t" in_north(n, c) "\t" in_east(n, c) "\t" in_south(n, c) "\t" in_west(n, c) "\t" in_cpu(n, c);
      }
    }       
  }
}

/  <variable name="[^"]*" index="[^"]*" value="[^"]*"\/>/ && !/.*cycle.*/ {

  if ($6 > 0.9)
  {
    sep1=index($2, "____");
    rest=substr($2, sep1 + 4);
    sep2=index(rest, "____");
    link=substr($2, 0, sep1 - 1);
    split(link, link_, "_");
    ls=link_[1] "_" link_[2];
    ld=link_[3] "_" link_[4];
    at=substr(rest, sep2 + 4);
    who=substr($2, sep1 + 4, sep2 - 1);

    flow[ls"-"ld "@" at] = who;
    noc_nodes[ls] = true;
    noc_nodes[ld] = true;

    if ((at + 0) > max)
    {
      max = at + 0;
    }
  }
}
