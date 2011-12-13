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
  print "digraph schedule"
  print "{"

  FS="\""
}

END {
  for (l in cycles)
  {
    split(cycles[l], sep, ",")
    makered = false;
    for (i in sep)
    {
      found = 0;
      for (j in sep)
      {
        if (i == j)
        {
          found++;
        }
      }
      if (found != 1)
      {
        makered = true;
      }
    }

    if (makered == true)
      print "  " l "[label=\"" cycles[l] "\"]";
    else
      print "  " l "[color=\"red\", label=\"" cycles[l] "\"]";
  }
  print "  " max " [shape=rectangle]";

  print "}"
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

    cycles[ls "->" ld] = cycles[ls "->" ld] at ",";
    cycles[ls "__" who "->" ld "__" who] = cycles[ls "__" who "->" ld "__" who] at ",";

    if ((at + 0) > max)
    {
      max = at + 0;
    }
  }
}
