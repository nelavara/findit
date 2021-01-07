#------------------------------- Make file for Findit
OBJS = main.cpp FileID.cpp params.cpp Sniff.cpp exceptions.cpp
CXXFLAGS = -Wall -std=c++17
# CCX is prefedeined to the default C++ compiler on your machine.
#On a Mac, CXX = Cland++, on Linux, g++. Both define C== also.
#--------------------------------- Linking Command
FindIt: $(OBJS)
	$(CXX) -o findit $(CXXFLAGS) $(OBJS)
#--------------------------------- Compilation Commands
exceptions.o: exceptions.cpp exceptions.hpp
FileID.o: FileID.cpp FileID.hpp Direntry.hpp Stats.hpp params.hpp \
 exceptions.hpp
main.o: main.cpp Sniff.hpp FileID.hpp Direntry.hpp Stats.hpp params.hpp \
 exceptions.hpp
params.o: params.cpp params.hpp exceptions.hpp
Sniff.o: Sniff.cpp Sniff.hpp FileID.hpp Direntry.hpp Stats.hpp params.hpp \
 exceptions.hpp
#Optional Cleanup Command
clean:
	rm -f $(OBJS) FindIt
