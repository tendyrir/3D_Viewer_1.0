all:
#	-Werror
	gcc -Wall -Wextra -Werror main.c parser.c 
	./a.out

clean:
	rm -f a.out


leaks:
	CK_FORK=no leaks --atExit -- ./a.out


check:
	cppcheck -v parse.c main.c viewer.h

# cp ../materials/linters/.clang-format .clang-format
# clang-format -n smart_calc/*.c smart_calc/*.h smart_calc/calculator.cpp smart_calc/main.cpp
# leaks --atExit -- ./smartcalc -trace address