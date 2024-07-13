#!/bin/bash

clang++ -Wall -Wextra -Wpedantic -Werror -std=c++23 main.cpp -o main

if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

declare -a inputs=("FirstInput.txt" "SecondInput.txt" "ThirdInput.txt" "FourthInput.txt" "FifthInput.txt")
declare -a colors=("255,0,255" "0,255,0" "0,255,0" "0,0,255" "255,180,245")
declare -a outputs=("FirstOutput.txt" "SecondOutput.txt" "ThirdOutput.txt" "FourthOutput.txt" "FifthOutput.txt")

for i in ${!inputs[@]}; do
    ./favorite_color ${inputs[$i]} ${colors[$i]} ${outputs[$i]}
    if [ $? -ne 0 ]; then
        echo "Test case ${inputs[$i]} failed."
    else
        echo "Test case ${inputs[$i]} passed."
    fi
done

echo "Outputs:"
for output in ${outputs[@]}; do
    echo "${output}"
    if [ -f "$output" ]; then
        cat "$output"
    else
        echo "File not created."
    fi
    echo ""
done
