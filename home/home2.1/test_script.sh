#!/bin/bash

g++ -o main main.cpp

run_test() {
    local expected="$1"
    shift
    local output=$(./main "$@")
    if [ "$output" == "$expected" ]; then
        echo "Test passed: $@"
    else
        echo "Test failed: $@"
        echo "Expected: $expected"
        echo "Got: $output"
    fi
}

clear_history() {
    ./main "bread"
}

clear_history
echo "Running Test Case 1"
run_test "Welcome, Anastasiia!" "Anastasiia"
run_test "Welcome, Gabriele!" "Gabriele"
run_test "Hello again(x=2), Gabriele" "Gabriele"
run_test "Hello again(x=2), Anastasiia" "Anastasiia"
run_test "Hello again(x=3), Gabriele" "Gabriele"
run_test "Welcome, Markel!" "Markel"
clear_history

echo "Running Test Case 2"
run_test "Welcome, Anastasiia!" "Anastasiia"
run_test "Usage: ./main <name> [delete]" "Anastasiia" "Alex"
run_test "Usage: ./main <name> [delete]" "Anastasiia" "5 nn, nnnm"
run_test "Usage: ./main <name> [delete]" " "
clear_history

echo "Running Test Case 3"
run_test "Welcome, Anastasiia!" "Anastasiia"
run_test "Statistics was deleted for Anastasiia" "Anastasiia" "delete"
run_test "Welcome, Anastasiia!" "Anastasiia"
run_test "Hello again(x=2), Anastasiia" "Anastasiia"
clear_history

echo "Running Test Case 4"
run_test "Welcome, Anastasiia!" "Anastasiia"
run_test "Hello again(x=2), Anastasiia" "Anastasiia"
run_test "Welcome, Gabriele!" "Gabriele"
run_test "The history was deleted" "bread"
run_test "Welcome, Anastasiia!" "Anastasiia"
run_test "Welcome, Gabriele!" "Gabriele"
clear_history

echo "Running Test Case 5"
run_test "Welcome, Anastasiia!" "Anastasiia"
run_test "Welcome, Alex!" "Alex"
run_test "Hello again(x=2), Alex" "Alex"
run_test "Usage: ./main <name> [delete]" " "
run_test "Statistics was deleted for Alex" "Alex" "delete"
run_test "The history was deleted" "bread"
run_test "Welcome, Alex!" "Alex"
run_test "Welcome, Anastasiia!" "Anastasiia"
clear_history

echo "All tests completed."
