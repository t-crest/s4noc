#/bin/bash

# path to the explab binaries (set if needed)
EXPLAB=

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Make a summary over all heuristic configurations for a topology
function summary()
{
  TOP=$1
  
  ${EXPLAB}sus2sus -i ${BIGSUS} --filter="topology==\"${TOP}\"" --filter='heuristic=="rnd"' --add 'cycles_rnd=schedule_length' --add 'time_rnd=total_time' > ${RNDSUS}
  ${EXPLAB}sus2sus -i ${BIGSUS} --filter="topology==\"${TOP}\"" --filter='heuristic=="lng"' --add 'cycles_lng=schedule_length' --add 'time_lng=total_time' > ${LNGSUS}
  ${EXPLAB}sus2sus -i ${BIGSUS} --filter="topology==\"${TOP}\"" --filter='heuristic=="sht"' --add 'cycles_sht=schedule_length' --add 'time_sht=total_time' > ${SHTSUS}
  ${EXPLAB}sus2sus -i ${BIGSUS} --filter="topology==\"${TOP}\"" --filter='heuristic=="cnfl"' --add 'cycles_cnfl=schedule_length' --add 'time_cnfl=total_time' > ${CNFLSUS}

  ${EXPLAB}sus2sus -i ${RNDSUS} -i ${LNGSUS} -i ${SHTSUS} -i ${CNFLSUS} -o - -s 'float(nodes)' -c max \
    side_length nodes links capacity_bound bisection_bound bound num_patterns cycles_rnd cycles_lng cycles_sht cycles_cnfl time_rnd time_lng time_sht time_cnfl
}

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 

# check arguments
if [ $# != 1 ]; then
  echo "mktables.sh <results-file>";
  echo "  Run the noc-sched tool for various network topologies/sizes/heuristics.";
  exit 1;
fi;

INPUT=$1

# grep for relevant lines only
GREPTMP=`mktemp`
egrep "configuration" -A 4 ${INPUT} > ${GREPTMP}


BIGSUS=`mktemp`
${EXPLAB}text2sus -i ${GREPTMP} -o - -n '--\n' \
  'configuration: (?P<topology>(mesh|torus|bitorus)) (?P<side_length>1?[0-9]) (?P<heuristic>(rnd|lng|sht|cnfl));\n.*;\nnetwork: 1?[0-9] side length, (?P<nodes>[0-9]+) nodes, (?P<links>[0-9]+) links, (?P<capacity_bound>[0-9]+) capacity bound, (?P<bisection_bound>[0-9]+) bisection bound\ntime: (?P<patterns_time>[0-9]+(.[0-9]+)?)s patterns, (?P<schedule_time>[0-9]+(.[0-9]+)?)s schedule, (?P<total_time>[0-9]+(.[0-9]+)?)s total\nschedule: (?P<schedule_length>[0-9]+) \((?P<schedule_patterns>[0-9]+) patterns scheduled from (?P<num_patterns>[0-9]+)\)' \
  | ${EXPLAB}sus2sus -i - -o ${BIGSUS} --add bound='max(float(capacity_bound), float(bisection_bound))'


RNDSUS=`mktemp`
LNGSUS=`mktemp`
SHTSUS=`mktemp`
CNFLSUS=`mktemp`

# make a summary for the mesh topology
summary mesh | sus2text -i - -o - > mesh.dat

# make a summary for the mesh topology
summary torus | sus2text -i - -o - > torus.dat

# make a summary for the mesh topology
summary bitorus | sus2text -i - -o - > bitorus.dat

# cleanup
rm ${GREPTMP} ${BIGSUS} ${RNDSUS} ${LNGSUS} ${SHTSUS} ${CNFLSUS}