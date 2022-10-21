runtest: test
	./test

test: split_test.o split.o
	g++ split_test.o split.o -lcppunit -o test

split_test.o: split_test.cpp split.hpp
	g++ -c split_test.cpp

split.o: split.cpp split.hpp
	g++ -c split.cpp


clean:
	rm -f *.o *~ test
