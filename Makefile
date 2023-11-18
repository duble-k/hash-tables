all: openhttest orderedhttest

openhttest: openhttest.cpp HashDouble.cpp
	g++ openhttest.cpp HashDouble.cpp -o openhttest
	
orderedhttest: orderedhttest.cpp HashChain.cpp
	g++ orderedhttest.cpp HashChain.cpp -o orderedhttest