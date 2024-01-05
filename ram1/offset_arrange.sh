#!/bin/bash

awk -F, 'BEGIN {OFS=","} 
         ($2 >= 32256 && $2 <= 32511) { $2 = $2 - 32256; print }' correct.csv > correct_arrange.csv

