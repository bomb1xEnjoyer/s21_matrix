CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
SRC = $(wildcard Functions/*.c HelpFunctions/*.c)
TESTS_SRC = $(wildcard tests/*.c)
OS := $(shell uname -s)


ifeq ($(OS),Linux)
	OPEN_CMD = xdg-open
	TEST_LIBS = -lcheck -lsubunit -lm -lrt -pthread
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
	TEST_LIBS = -lcheck
endif


all: style_test s21_matrix.a test gcov_report clean_test


s21_matrix.a: ${SRC}
	$(CC) -c $(CFLAGS) $(SRC)
	ar rc $@ *.o
	ranlib $@
	cp $@ lib$@
	make clean_obj


test:
	$(CC) $(CFLAGS) -o test $(SRC) $(TESTS_SRC) $(TEST_LIBS)

gcov_report:
	$(CC) $(CFLAGS) --coverage $(SRC) $(TESTS_SRC) -o gcov_test $(TEST_LIBS)
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test

style_test:
	cp ../materials/linters/.clang-format .
	clang-format -style=Google -n Functions/*.c
	clang-format -style=Google -n HelpFunctions/*.c
	rm .clang-format

re:
	make clean
	make all

clean: clean_obj clean_lib clean_test
	rm -rf test
	rm -rf report
	

clean_obj:
	rm -rf *.o

clean_lib: 
	rm -rf *.a

clean_test: clean_lib
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf gcov_test
	rm -rf test.o