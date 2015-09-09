CXX=/usr/bin/clang++
INCLUDE_DIRS=include ../include ./include
INCDIR=include
TESTDIR=test
CXXFLAGS=-I$(INCDIR) -std=c++11
TESTFILES=$(shell find $(TESTDIR) -name '*.cpp')
OBJFILES=$(patsubst test/%.cpp,bin/%.o,$(TESTFILES))
EXECS=$(patsubst test/%.cpp,bin/%,$(TESTFILES))
TEST_TARGETS=$(patsubst bin/%,%,$(EXECS))
PREV_BUILD=$(shell find ./.prev 2>/dev/null | xargs cat)

.PHONY: Makefile all include src lib README.md bin test tests check-syntax

.SUFFIXES: .cpp

all:
	@echo Available targets:
	@echo  - test: build all test targets
	@echo  - [target]: build and run specified target

test: $(EXECS)
	@echo $(EXECS) > ./.prev

tests: test

bin/%.o: test/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin/%: bin/%.o
	$(CXX) $(CXXFLAGS) $< -o $@

$(TEST_TARGETS):
	$(eval OUTFILE=$(patsubst %,bin/%,$@) )
	$(CXX) $(CXXFLAGS) $(patsubst %,test/%.cpp,$@) -o $(OUTFILE)
	@echo $(OUTFILE) > ./.prev
	@echo Running $(OUTFILE)
	@$(OUTFILE)

clean:
	rm -f $(EXECS)
	rm -f $(OBJFILES)
	@clean $(INCDIR) $(TESTDIR)

redo: clean $(PREV_BUILD)

check-syntax:
	$(CXX) $(CXXFLAGS) -Wall -Wextra -fsyntax-only $(CHK_SOURCES)

dumpvars:
	@echo $(foreach var, ${DUMPVARS}, "\n$(var)=$($(var))")
