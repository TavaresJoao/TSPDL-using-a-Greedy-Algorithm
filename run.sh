#!/bin/bash
g++ -c allocation.cpp
g++ -c file.cpp
g++ -c Greedy.cpp
g++ -c main.cpp
g++ -c TSPDL.cpp
g++ -o main allocation.o file.o Greedy.o main.o TSPDL.o

for y in Instances/TSPDL_Instances/*
do
  echo $y;
  for x in $y/*
  do
    echo $x;
    ./main $x Outputs/myoutput_0.out 0
  done
done

for y in Instances/tspdl-test-data-equal-demand/*
do
  echo $y;
  ./main $y Outputs/myoutput_1.out 1
done
