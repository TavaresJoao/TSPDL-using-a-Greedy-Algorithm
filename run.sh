#!/bin/bash
for y in Instances/TSPDL_Instances/*
do
  for x in $y/*
  do
    ./main /$x /Outputs/myoutput.out
  done
done
