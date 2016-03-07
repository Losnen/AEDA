CXX=g++ 
CXXFLAGS=-g

OBJS = complejos.o reales.o main.o enteros.o racionales.o

all: ${OBJS}
	$(CXX) $(CXXFLAGS) -o calc ${OBJS}

clean: 
	rm -rf ${OBJS} calc