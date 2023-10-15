.PHONY: s21_calc.a gcov_report test clean

OS=$(shell uname)

CFLAGS=-Wall -Werror -Wextra
CPPFLAGS=-lstdc++ -std=c++17
LIBS=-lgtest -lgcov

# -- Main targets ---
START=start
LIB=s21_calc.a
GCOV=gcov_report
TEST=test
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

$(TEST): ${CLEAN}
	@gcc $(CFLAGS) $(LIBS) $(CPPFLAGS) --coverage unit_tests.cpp Controller/controller.cpp Model/model.cpp -o test
	@./test

$(LIB): main $(OBJS) 
	rm -rf $(LIB)
	ar rcs $(LIB) $(OBJS)
	ranlib $(LIB)

open:
	open ./build/SmartCalc.app

.c.o:
	$(GCC) -c -g -o $@ $<

$(START): $(INSTALL)
	$(OPEN)

$(INSTALL): $(CLEAN)
	mkdir build
	cd View/SmartCalc/ && qmake && make && make clean && rm -rf Makefile && mv SmartCalc.app ../../build/

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

$(GCOV): $(TEST)
	# if lcov is not found
	# eval "$(/opt/goinfre/USERNAME/homebrew/bin/brew shellenv)"
	# brew update --force --quiet
	# chmod -R go-w "$(brew --prefix)/share/zsh"

	@lcov --ignore-errors mismatch -t "./gcov" -o report.info --no-external -c -d .
	@genhtml --ignore-errors mismatch -o report report.info
	@open ./report/index.html

rebuild: $(CLEAN) all

$(CLEAN):
	@rm -rf *.a *.o *.info
	@rm -rf *.dSYM *.out *.inf
	@rm -rf *.gcda *.out lib/*.o
	@rm -rf build *.gcno gcov
	@rm -rf *.tgz test

style:
	find . -name "*.h" -o -name "*.cc" -o -name "*.tpp" | xargs clang-format --style=google -n

gost:
	find . -name "*.h" -o -name "*.cc" -o -name "*.tpp" | xargs clang-format --style=google -i

