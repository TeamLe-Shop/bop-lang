OBJECTS=main.o opcodes.o
EXECUTABLE=bop

$(EXECUTABLE): $(OBJECTS)
	cc $(OBJECTS) -o $(EXECUTABLE)
	rm $(OBJECTS)
	mv bop ../

main.o: $(OBJECTS) src/main.c
	cc -c src/main.c

opcodes.o: src/opcodes.c
	cc -c src/opcodes.c