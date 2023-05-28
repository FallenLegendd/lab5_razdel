


all: main compulie clear

main: compulie
	-g++ -o Lab5 *.o
	Lab5

compulie:
	-g++ -c *.cpp
#	g++ -c Object.cpp
clear:
	-del *.o


main1:
	g++ -o Lab5 main.cpp coordinates.cpp Object.cpp UserEquipment.cpp









