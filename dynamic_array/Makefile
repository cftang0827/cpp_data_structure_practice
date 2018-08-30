all: test
test: *.o
	g++ -o test *.o
%.o: %.cpp
	g++ -Wall -g -c $^
clean:
	rm -rf test *.o