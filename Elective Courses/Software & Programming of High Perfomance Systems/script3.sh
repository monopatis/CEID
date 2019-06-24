#!/bin/bash
COUNT=10
COUNT2=1
until [ $COUNT -gt 3000 ]; do
        echo Dimensions of A matrix is: $COUNT2 x $COUNT
        echo $COUNT2 x $COUNT ,`./ex1/ex1 $COUNT2 $COUNT 1 0`,`./ex2/ex2 $COUNT2 $COUNT 1 0`,`./ex3/ex3 $COUNT2 $COUNT 1 0` >> times.txt
        let COUNT=COUNT*2
done
