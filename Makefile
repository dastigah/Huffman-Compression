CC=g++
FLAGS=-g -std=c++14

TEST=Main_test.cpp Compress_test.cpp

OBJS=Compress.o Compress_Test.o Main_test.o
EXES=Compress

GTEST_LIB=lib/
INCLUDE=-I./include


Main_Test: Main_Test.o Compress_Test.o Compress.o
	$(CC) -lpthread $(FLAGS) $(^) $(GTEST_LIB) -o $(@) 

Compress: Compress.o
	$(CC) $(FLAGS) $(<) -o $(@)	

%.o: %.cpp
	$(CC) -c $(FLAGS) $(<) -o $(@)
