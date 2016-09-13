#makefile for Time class with three files:
# Time.h, Time.cpp, Driver.cpp
# executable file is called timetest

timetest: Driver.o Time.o
	g++ Driver.o Time.o -o timetest

Driver.o: Driver.cpp Time.h
	g++ -c Driver.cpp

Time.o: Time.cpp Time.h
	g++ -c Time.cpp

