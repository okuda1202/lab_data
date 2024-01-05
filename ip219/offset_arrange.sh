#!/bin/bash

awk -F, 'BEGIN {OFS=","} 
         ($2 >= 7680 && $2 <= 7936) { $2 = $2 - 7680; print }
         ($2 >= 15040 && $2 <= 15296) { $2 = $2 - 15040; print }' correct.csv > correct_arrange.csv

