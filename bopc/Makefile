OBJECTS=main.o
EXECUTABLE=bopc

$(EXECUTABLE): $(OBJECTS)
	cc $(OBJECTS) -o $(EXECUTABLE)
	rm main.o

main.o: src/main.c
	cc -c src/main.c
