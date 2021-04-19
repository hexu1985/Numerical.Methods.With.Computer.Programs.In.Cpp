#!/usr/bin/env bash

echo
echo "====================================="
echo

echo "./P3_1 < E3.2.data"
cat E3.2.data
./P3_1 < E3.2.data

echo
echo "====================================="
echo

echo "./P3_1 < E3.4.data"
cat E3.4.data
./P3_1 < E3.4.data

echo
echo "====================================="
echo

echo "./P3_1 < E3.5.data"
cat E3.5.data
./P3_1 < E3.5.data

echo
echo "====================================="
echo

echo "./P3_2"
cp E3.2.data gauss.dat
cat gauss.dat
./P3_2
cat gauss.out
rm gauss.dat gauss.out

echo
echo "====================================="
echo

echo "./P3_2"
cp E3.4.data gauss.dat
cat gauss.dat
./P3_2
cat gauss.out
rm gauss.dat gauss.out

echo
echo "====================================="
echo

echo "./P3_2"
cp E3.5.data gauss.dat
cat gauss.dat
./P3_2
cat gauss.out
rm gauss.dat gauss.out

echo
echo "====================================="
echo

echo "./P3_3 < E3.7.data"
cat E3.7.data
./P3_3 < E3.7.data

