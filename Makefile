CC = g++
CFLAGS = -O3 -Wall -W -pedantic -std=c++20

SRCDIR = src
OBJDIR = obj
BINDIR = bin

SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
OUT = $(BINDIR)/linked_list.out

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OUT)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/*.hpp
	@mkdir -p $(OBJDIR) $(BINDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -Rf $(OBJDIR) $(BINDIR)