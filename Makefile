all: 18_2

CFLAGS=-std=c++1z  -g -pthread
%: %.cpp
	clang++ ${CFLAGS} $< -o $@