all: 18_1

CFLAGS=-std=c++1z  -g -pthread
%: %.cpp
	clang++ ${CFLAGS} $< -o $@
