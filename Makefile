simple_program:simple_program
	gcc -o simple_program simple_program.c

clean:
	rm -f simple_program
.PHONY: all clean
