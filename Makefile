source_files = $(wildcard src/*.c)
out = out

main:
	gcc -Wall -Wextra $(source_files) -lraylib -o $(out)

run: main
	./$(out)

clean:
	rm -f $(out)

