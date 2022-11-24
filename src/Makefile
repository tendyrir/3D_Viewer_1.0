all:
#	-Werror
	gcc -Wall -Wextra main.c parser.c 
	./a.out

clean:
	rm -f a.out


leaks:
	CK_FORK=no leaks --atExit -- ./a.out
