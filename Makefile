# Objects

OBJECTS = trab.o heap.o grafosM.o prim.o

BIN = trab

# Maintainer flags

CPP_FLAGS = -I.
C_FLAGS = 
LD_FLAGS = 
CC = gcc
MAKE = make

# Install prefix

PREFIX=.

# Default target

all: $(BIN)

# Binary

$(BIN) : $(OBJECTS)
	gcc $(LD_FLAGS) $(LDFLAGS) $^ -o $@ -lm

# Pattern rule for object-source dependences

%.o : %.c 
	$(CC) $(CPP_FLAGS) $(CPPFLAGS) $(C_FLAGS) $(CFLAGS)-c $<

# Automatic object-header dependences

makefiles = $(OBJECTS:%.o=%.d) 

include $(makefiles)

%.d : %.c
	$(CC) $(CPP_FLAGS) $(CPPFLAGS) -c $<  -MM -MT '$(<:.c=.o) $@' $< >$@

# Cleaning

.PHONY : clean

clean:
	rm -f $(OBJECTS) $(makefiles) $(BIN) 
	rm -f *~ \#*

