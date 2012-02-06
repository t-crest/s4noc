#/bin/bash

# get path to the noc-sched binary
NOC_SCHED=`dirname $0`/../build/src/noc-sched

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# run a set of experiments for a given topology, size, and heuristic.
function run_instance()
{
  TOP=$1
  SIZE=$2
  HEUR=$3;
  echo "configuration: ${TOP} ${SIZE} ${HEUR};"
  echo "running: ${NOC_SCHED} --hshd --hsel ${HEUR} --${TOP} $i;"
  ${NOC_SCHED} --hshd - --hsel ${HEUR} --${TOP} $i;
}

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# run a set of experiments for a given topology and heuristic.
function run_set()
{
  TOP=$1
  HEUR=$2;

  for i in 2 3 4 5 6 7 8 9 10 11 12 13 14 15; do
    run_instance ${TOP} ${i} ${HEUR}
  done
}

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# run a set of experiments for a given topology.
function run_top()
{
  TOP=$1
  run_set ${TOP} rnd
  run_set ${TOP} lng
  run_set ${TOP} sht
  run_set ${TOP} cnfl
}

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# check arguments
if [ $# != 1 ]; then
  echo "experiments.sh <results-file>";
  echo "  Run the noc-sched tool for various network topologies/sizes/heuristics.";
  exit 1;
fi;

# check result file
if [ -f $1 ]; then
  echo "Result file exists."
  exit 2;
fi;

RESULT=$1

# run the experiments

echo "" > ${RESULT}

run_top mesh | tee -a ${RESULT} | egrep "running|network|configuration|schedule|time"
run_top torus | tee -a ${RESULT} | egrep "running|network|configuration|schedule|time"
run_top bitorus | tee -a ${RESULT} | egrep "running|network|configuration|schedule|time"

exit 0;
