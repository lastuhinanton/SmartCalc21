.PHONY: s21_calc.a gcov_report test clean

OS=$(shell uname)
BASE=graph.c lib/*.c
TEST_C=tests/*.c
OBJS=graph.o input_formula.o calculate.o code.o input_formula.o polish_notation.o stack.o
GCC=gcc -std=c11 -Wall -Werror -Wextra -fsanitize=address

# -- Main targets ---
START=start
LIB=s21_calc.a
GCOV=gcov_report
TEST=tests
CLEAN=clean
INSTALL=install
UNINSTALL=uninstall
DVI=dvi
DIST=dist
OPEN=open ./build/SmartCalc.app

# -- Dependencie of OS ---
ifeq ($(OS), Linux)
	LINUX=-lsubunit
else
	VIEWHTML=open ./report/index.html
endif

all: $(START)

$(LIB): main $(OBJS) 
	rm -rf $(LIB)
	ar rcs $(LIB) $(OBJS)
	ranlib $(LIB)

.c.o:
	$(GCC) -c -g -o $@ $<


main:
	$(GCC) -c $(BASE)

$(START): $(INSTALL)
	$(OPEN)

$(INSTALL): $(CLEAN)
	mkdir build
	cd SmartCalc/ && qmake && make && make clean && rm -rf Makefile && mv SmartCalc.app ../build/

$(UNINSTALL):
	rm -rf build

$(DVI):
	open dvi.md

$(DIST): $(INSTALL)
	rm -rf Archive_CalcApp_v1_0/
	mkdir Archive_CalcApp_v1_0
	mkdir Archive_CalcApp_v1_0/src
	mv ./build/SmartCalc.app Archive_CalcApp_v1_0/src
	tar cvzf Archive_CalcApp_v1_0.tgz Archive_CalcApp_v1_0/
	rm -rf Archive_CalcApp_v1_0/
	rm -rf build

$(TEST): $(LIB) 
	$(GCC) -g $(TEST_C) -o $(TEST).out -L. $(LIB) -lcheck -lm $(LINUX)
ifeq ($(OS), Darwin)
	./$(TEST).out
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(TEST).out
endif

$(GCOV): $(LIB)
	# if lcov is not found
	# eval "$(/opt/goinfre/USERNAME/homebrew/bin/brew shellenv)"
	# brew update --force --quiet
	# chmod -R go-w "$(brew --prefix)/share/zsh"
	rm -rf *.o *.gcno *.gcda
	$(GCC) $(TEST_C) $(BASE) -o gcov --coverage -lcheck -lm $(LINUX) -L. $(LIB)
	./gcov
	lcov -t "gcov" -o $(GCOV).info --no-external -c -d .
	genhtml -o report $(GCOV).info
	$(VIEWHTML)

rebuild: $(CLEAN) all

$(CLEAN):
	rm -rf *.a *.o *.info
	rm -rf *.dSYM *.out *.inf
	rm -rf *.gcda *.out lib/*.o
	rm -rf build *.gcno gcov
	rm -rf *.tgz

check:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h ./lib/*.c ./lib/*.h ./SmartCalc/*.cpp
	rm -rf .clang-format
