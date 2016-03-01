CXX=g++ 
CXXFLAGS=-g

OBJS = nodo_t.o lista_t.o  pila_t.o evaluador_RPN.o main.o

all: ${OBJS}
	$(CXX) $(CXXFLAGS) -o calc ${OBJS}

clean: 
	rm -rf *.o calc