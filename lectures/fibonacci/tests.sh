#!/bin/bash
echo "Running a few trials ..."

for i in {0..50}
do
    echo 'Calculating the value of Fib('$i')'  
    ./fibonacci $i
    echo '---'
    echo
done
