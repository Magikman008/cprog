#!/bin/bash

shopt -s extglob
rm -rf !(data|scripts|func_tests|*.sh|*.c|*.h)
mapfile -t files < <(find "$PWD" -type f | grep -Pv '.*(data).*' | grep -P "\.txt")
for file in "${files[@]}"; do
    rm -rf "$file"
done
