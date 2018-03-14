# CS 104 Student Repository

- **Name**: Farrell Hohman
- **USC ID**: 6292503996
- **Email**: fhohman@usc.edu

Problem 1: Solution to problem 1 is in hw2.txt 

Problem 2: Solution to problem 3 is in hw2.txt

Problem 4: Solution to problem 4 is in hw2.txt

Problem 5: Solution to problem 5 is in fullsort.cpp
			Compile with code below, it may return an error with an undefined
			reference to main if you do not write a main in the fullsort.cpp and
			do not use the -c in the compiling

		   g++ -g -Wall -std=c++11 -c fullsort.cpp -o fullsort
		   
Run as listed below once you have a main function written as well

		   ./fullsort.cpp

Problem 6: Solution to problem 6 is in lliststr.cpp with the test cases in 
			lliststr_test.cpp
Compile the lliststr.cpp with the test case file with:

	g++ -g -Wall -std=c++11 lliststr_test.cpp lliststr.cpp -o lliststr_test

Run as

		   ./lliststr_test

The test cases in lliststr_test should all output SUCCESS



Problem 7: Solution to problem 7 is in assassin.cpp
Compile with 

	g++ -g -Wall -std=c++11 assassin.cpp lliststr.cpp -o assassin


Run as 

	./assassin file.txt

The file.txt can be any text file with the format given in the homework 
assignment. 
