#!/bin/bash

awk -F, '$1 == 1 { print }' result_last_ram2.csv > correct.csv

