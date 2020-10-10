#------------------------------- Make file for Program 3
#------------------------------- Evan Perry and Jaron Bialecki
#------------------------------- 09-27-2020
#------------------------------- CSCI 6647
OBJS = main.cpp FileID.cpp params.cpp Sniff.cpp tools.cpp exceptions.cpp
CXXFLAGS = -std=c++17 -g -Wall -O1
# CCX is prefedeined to the default C++ compiler on your machine.
#On a Mac, CXX = Cland++, on Linux, g++. Both define C== also.
#--------------------------------- Linking Command
#Build targets
TARGETS = program3
#.PHONY : means that the targets that follow are build even though they are not real
.PHONY: all clean
all: $(TARGETS)
program3: $(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJS)
#--------------------------------- Compilation Commands
FileID.o: FileID.cpp FileID.hpp Direntry.hpp Stats.hpp params.hpp \
  exceptions.hpp tools.hpp
Sniff.o: Sniff.cpp Sniff.hpp FileID.hpp Direntry.hpp Stats.hpp params.hpp \
  exceptions.hpp tools.hpp
exceptions.o: exceptions.cpp exceptions.hpp tools.hpp
main.o: main.cpp Sniff.hpp FileID.hpp Direntry.hpp Stats.hpp params.hpp \
  exceptions.hpp tools.hpp
params.o: params.cpp params.hpp exceptions.hpp tools.hpp
tools.o: tools.cpp tools.hpp
#Optional Cleanup Command
clean:
	rm -f $(OBJS) $(TARGETS)