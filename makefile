NAME = rl1
CC = g++
CFLAGS = -Iinclude -std=c++0x
LDFLAGS =

LIBS = -L. -ltcod -ltcodxx -Wl,-rpath=. -Wall

SRCDIR = src
OBJDIR = build
SRC := $(wildcard $(SRCDIR)/*.cpp) 
OBJ := $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o) 


all: $(SRC) $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(LDFLAGS) $(OBJ) -o $@ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)/* $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)


-include $(OBJ:.o=.d)
# ....
