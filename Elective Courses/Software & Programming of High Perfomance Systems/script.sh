#!/bin/bash
COUNT=10
until [ $COUNT -gt 3000 ]; do
        echo Dimensions of A matrix is: $COUNT x $COUNT
        echo $COUNT x $COUNT ,`./ex1/ex1 $COUNT $COUNT 1 0`,`./ex2/ex2 $COUNT $COUNT 1 0`,`./ex3/ex3 $COUNT $COUNT 1 0` >> times.txt
        let COUNT=COUNT*2
done
