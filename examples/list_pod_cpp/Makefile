INCLUDE:=-I../../kubernetes/
LIBS:=-L../../kubernetes/build -lyaml -lwebsockets -lkubernetes -L/usr/local/lib
CXXFLAGS:=-g -std=c++11
BIN:=list_pod_cpp

.PHONY : all clean test memcheck
all:
	g++ main.cpp $(CXXFLAGS) $(INCLUDE) $(LIBS) -o $(BIN)

test:
	./$(BIN)

memcheck:
	valgrind --tool=memcheck --leak-check=full ./$(BIN)

clean:
	rm -f ./$(BIN)