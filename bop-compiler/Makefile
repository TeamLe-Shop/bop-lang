OBJECTS=main.o util.o opcodes.o label.o
EXECUTABLE=bopc

$(EXECUTABLE): $(OBJECTS)
	cc $(OBJECTS) -o $(EXECUTABLE)
	rm $(OBJECTS)
	mv bopc ../

main.o: $(OBJECTS) src/main.c
	cc -c src/main.c

util.o: src/util.c
	cc -c src/util.c

opcodes.o: src/opcodes.c
	cc -c src/opcodes.c

label.o: src/label.c
	cc -c src/label.c