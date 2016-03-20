CXX=g++ 
CXXFLAGS=-g

OBJS = enteros.o racionales.o reales.o complejos.o main.o

all: ${OBJS}
	$(CXX) $(CXXFLAGS) -o pol ${OBJS}

clean: 
	rm -rf *.o pol