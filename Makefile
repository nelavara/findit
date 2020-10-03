#------------------------------- Make file for Program 3
#------------------------------- Evan Perry and Jaron Bialecki
#------------------------------- 09-27-2020
#------------------------------- CSCI 6647
OBJS = main.cpp FileID.cpp params.cpp Sniff.cpp tools.cpp exceptions.cpp
CXXFLAGS = -Wall -std=c++17 -O1
# CCX is prefedeined to the default C++ compiler on your machine.
#On a Mac, CXX = Cland++, on Linux, g++. Both define C== also.
#--------------------------------- Linking Command
Program3: $(OBJS)
	$(CXX) -o program3 $(OBJS)
#--------------------------------- Compilation Commands
exceptions.o: exceptions.cpp exceptions.hpp tools.hpp
FileID.o: FileID.cpp FileID.hpp Direntry.hpp Stats.hpp params.hpp \
 exceptions.hpp tools.hpp
main.o: main.cpp Sniff.hpp FileID.hpp Direntry.hpp Stats.hpp params.hpp \
 exceptions.hpp tools.hpp
params.o: params.cpp params.hpp exceptions.hpp tools.hpp
Sniff.o: Sniff.cpp Sniff.hpp FileID.hpp Direntry.hpp Stats.hpp params.hpp \
 exceptions.hpp tools.hpp
tools.o: tools.cpp tools.hpp
#Optional Cleanup Command
clean:
	rm -f $(OBJS) Program3
