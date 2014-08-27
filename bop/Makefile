OBJECTS=main.o
EXECUTABLE=bop

$(EXECUTABLE): $(OBJECTS)
	cc $(OBJECTS) -o $(EXECUTABLE)
	rm main.o

main.o: src/main.c
	cc -c src/main.c

