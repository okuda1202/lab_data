#!/bin/bash

awk -F, '$1 == 1 { print }' result_last_219.csv > correct.csv

