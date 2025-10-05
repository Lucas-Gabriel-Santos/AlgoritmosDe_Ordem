EXEC = AlgoritmosBusca
CXX = g++
CXXFLAGS = -Wall -O2

SRC = main.cpp \
      Bubble_sort.cpp \
      Insertion_sort.cpp \
      Selection_sort.cpp \
      Merge_sort.cpp \
      Quick_sort.cpp

OBJ = $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

clean:
	rm -f $(EXEC) *.o