#!/bin/bash

awk -F, '$1 == 1 { print }' result_last.csv > correct.csv

