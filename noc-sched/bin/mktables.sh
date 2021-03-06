#/bin/bash

# path to the explab binaries (set if needed)
EXPLAB=

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Make a summary over all heuristic configurations for a topology
function summary()
{
  TOP=$1
  
  ${EXPLAB}sus2sus -i ${BIGSUS} --filter="topology==\"${TOP}\"" --filter='heuristic=="rnd"' --add 'cycles_rnd=schedule_length' --add 'time_rnd=total_time' --add 'ratio_rnd=format(float(cycles_rnd)/float(bound), digits=2)' --add 'utilization_rnd=format(float(capacity_bound)/float(cycles_rnd), digits=2)' > ${RNDSUS}
  ${EXPLAB}sus2sus -i ${BIGSUS} --filter="topology==\"${TOP}\"" --filter='heuristic=="lng"' --add 'cycles_lng=schedule_length' --add 'time_lng=total_time' --add 'ratio_lng=format(float(cycles_lng)/float(bound), digits=2)' --add 'utilization_lng=format(float(capacity_bound)/float(cycles_lng), digits=2)' > ${LNGSUS}
  ${EXPLAB}sus2sus -i ${BIGSUS} --filter="topology==\"${TOP}\"" --filter='heuristic=="sht"' --add 'cycles_sht=schedule_length' --add 'time_sht=total_time' --add 'ratio_sht=format(float(cycles_sht)/float(bound), digits=2)' --add 'utilization_sht=format(float(capacity_bound)/float(cycles_sht), digits=2)' > ${SHTSUS}
  ${EXPLAB}sus2sus -i ${BIGSUS} --filter="topology==\"${TOP}\"" --filter='heuristic=="cnfl"' --add 'cycles_cnfl=schedule_length' --add 'time_cnfl=total_time' --add 'ratio_cnfl=format(float(cycles_cnfl)/float(bound), digits=2)' --add 'utilization_cnfl=format(float(capacity_bound)/float(cycles_cnfl), digits=2)' > ${CNFLSUS}

  ${EXPLAB}sus2sus -i ${RNDSUS} -i ${LNGSUS} -i ${SHTSUS} -i ${CNFLSUS} -o - -s 'float(nodes)' -c max \
    side_length nodes links capacity_bound bisection_bound bound \
    num_patterns avg_len_patterns scheduled_patterns \
    cycles_rnd cycles_lng cycles_sht cycles_cnfl \
    time_rnd time_lng time_sht time_cnfl \
    ratio_rnd ratio_lng ratio_sht ratio_cnfl \
    utilization_rnd utilization_lng utilization_sht utilization_cnfl
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
egrep "configuration" -A 5 ${INPUT} > ${GREPTMP}


BIGSUS=`mktemp`
${EXPLAB}text2sus -i ${GREPTMP} -o - -n '--\n' \
  'configuration: (?P<topology>(mesh|torus|ptorus|bitorus|pbitorus)) (?P<side_length>1?[0-9]) (?P<heuristic>(rnd|lng|sht|cnfl));\n.*;\nnetwork: 1?[0-9] side length, (?P<nodes>[0-9]+) nodes, (?P<links>[0-9]+) links, (?P<capacity_bound>[0-9]+) capacity bound, (?P<bisection_bound>[0-9]+) bisection bound\ntime: (?P<patterns_time>[0-9]+(.[0-9]+)?)s patterns, (?P<scheduled_time>[0-9]+(.[0-9]+)?)s schedule, (?P<total_time>[0-9]+(.[0-9]+)?)s total\npatterns: (?P<num_patterns>[0-9]+) number, (?P<avg_len_patterns>[0-9]+) average length, (?P<scheduled_patterns>[0-9]+) scheduled\nschedule: (?P<schedule_length>[0-9]+)' \
  | ${EXPLAB}sus2sus -i - -o ${BIGSUS} --add bound='max(float(capacity_bound), float(bisection_bound))'

RNDSUS=`mktemp`
LNGSUS=`mktemp`
SHTSUS=`mktemp`
CNFLSUS=`mktemp`

# make a summary for the mesh topology
summary mesh | sus2text -i - -o - > mesh.dat

# make a summary for the torus topology
summary torus | sus2text -i - -o - > torus.dat

# make a summary for the torus topology (with a register on links)
summary ptorus | sus2text -i - -o - > ptorus.dat

# make a summary for the bidirectional torus topology
summary bitorus | sus2text -i - -o - > bitorus.dat

# make a summary for the bidirectional torus topology (with a register on links)
summary pbitorus | sus2text -i - -o - > pbitorus.dat

# cleanup
rm ${GREPTMP} ${BIGSUS} ${RNDSUS} ${LNGSUS} ${SHTSUS} ${CNFLSUS} 
