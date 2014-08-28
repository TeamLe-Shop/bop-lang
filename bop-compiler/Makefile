OBJECTS=main.o util.o opcodes.o
EXECUTABLE=bopc

$(EXECUTABLE): $(OBJECTS)
	cc $(OBJECTS) -o $(EXECUTABLE)
	rm $(OBJECTS)
	mv bopc ../

main.o: util.o opcodes.o src/main.c
	cc -c src/main.c

util.o: src/util.c
	cc -c src/util.c

opcodes.o: src/opcodes.c
	cc -c src/opcodes.c