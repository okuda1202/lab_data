#!/bin/bash

awk -F, 'BEGIN {OFS=","} 
         ($2 >= 12736 && $2 <= 12992) { $2 = $2 - 12736; print }
         ($2 >= 5376 && $2 <= 5632) { $2 = $2 - 5376; print }' correct.csv > correct_arrange.csv

