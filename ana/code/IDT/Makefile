
flag = -std=c++11
#OBJ=main.cpp
#OBJ=151Yb.cpp
#OBJ=149Er.cpp
#OBJ=152Yb.cpp
#OBJ=new.cpp
#OBJ=150Tm.cpp
IDT: main.cpp
IDT:$(OBJ)
#		g++  $(flag) $^ -o $@ $(shell root-config --libs --cflags)
		g++  -Wall $(flag) $^ -o $@ $(shell root-config --libs --cflags)


clean:
	rm -rf IDT
