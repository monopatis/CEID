#!/bin/bash
COUNT=10
COUNT2=5
until [ $COUNT2 -gt 4000 ]; do
        echo Dimensions of A matrix is: $COUNT2 x $COUNT
        echo $COUNT2 x $COUNT ,`./ex1/ex1 $COUNT2 $COUNT 1 0`,`./ex2/ex2 $COUNT2 $COUNT 1 0`,`./ex3/ex3 $COUNT2 $COUNT 1 0` >> times.txt
        let COUNT=COUNT*2
        let COUNT2=COUNT2*3
done
