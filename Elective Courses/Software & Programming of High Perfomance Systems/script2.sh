#!/bin/bash
COUNT=10
COUNT2=1
until [ $COUNT -gt 3000 ]; do
        echo Dimensions of A matrix is: $COUNT x $COUNT2
        echo $COUNT x $COUNT2 ,`./ex1/ex1 $COUNT $COUNT2 1 0`,`./ex2/ex2 $COUNT $COUNT2 1 0`,`./ex3/ex3 $COUNT $COUNT2 1 0` >> times.txt
        let COUNT=COUNT*2
done
