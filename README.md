# EDA-1-Final-Project
Forensic Laboratory

This project simulates the behavior of a forensic laboratory, creating random samples, processing them, and generating a delivery report periodically.
The samples are generated randomly.

# How to compile.
The following code is used in the main folder:

To link:

gcc colaCircularLSE.c colaLSE.c lab.c main.c sample.c stack.c -c

gcc colaCircularLSE.o colaLSE.o lab.o main.o sample.o stack.o -o lab

To run:

./lab