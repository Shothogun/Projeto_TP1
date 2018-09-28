IDIR = ../include

CC = g++
CXXFLAGS = -W -Wall -std=c++14 -pedantic -I$(IDIR)

EDIR = ../exe
ODIR = ../obj

T_EDIR = ../t_exe
T_SDIR = ../t_src

_T_SRC = $(patsubst $(T_SDIR)/%,%,$(wildcard $(T_SDIR)/*.cpp))

_T_OBJ = $(patsubst %.hpp,%.o,$(_DEPS)) $(patsubst %.cpp,%.o,$(_T_SRC))
T_OBJ = $(patsubst %,$(ODIR)/%,$(_T_OBJ))

T_SRC = $(patsubst %,$(T_SDIR)/%,$(wildcard *.cpp))

LIBS = -lm
DEBUG = -g

_DEPS = $(patsubst $(IDIR)/%,%,$(DEPS))
DEPS = $(wildcard $(IDIR)/*.hpp)

_OBJ = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS) $(DEBUG)

$(ODIR)/%.o: $(T_SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS) $(DEBUG)

test: $(T_OBJ)
	$(CC) -o $(T_EDIR)/$@ $^ $(CXXFLAGS) $(LIBS) $(DEBUG)

main: $(OBJ)
	$(CC) -o $(EDIR)/$@ $^ $(CXXFLAGS) $(LIBS) $(DEBUG)

.PHONY: clean

clean:
	rm -f $(wildcard $(ODIR)/*.o)
