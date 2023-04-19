
flag = -std=c++11

Hist: main.cpp
#main:main.cpp
#		g++  $(flag) $^ -o $@ $(shell root-config --libs --cflags)
		g++  -Wall $(flag) $^ -o $@ $(shell root-config --libs --cflags)


clean:
	rm -rf Hist
