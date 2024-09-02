# The name of the source files
SOURCES = main.c logger.c flashbang.c

# The name of the executable
EXE = keyrot

# Flags for compilation (adding warnings are always good)
CFLAGS = -Wall

# Flags for linking (none for the moment)
LDFLAGS =

# Libraries to link with (none for the moment)
LIBS =

# Use the GCC frontend program when linking
LD = gcc

# This creates a list of object files from the source files
OBJECTS = $(SOURCES:%.c=%.o)

# The first target, this will be the default target if none is specified
# This target tells "make" to make the "all" target
default: all

# Having an "all" target is customary, so one could write "make all"
# It depends on the executable program
all: $(EXE)

# This will link the executable from the object files
$(EXE): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o  $(EXE) $(LIBS)


# This is a target that will compile all needed source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Target to clean up after us
clean:
	-rm -f $(EXE)      # Remove the executable file
	-rm -f $(OBJECTS)  # Remove the object files

# Finally we need to tell "make" what source and header file each object file depends on
main.o: main.c logger.h flashbang.h
logger.o: logger.c logger.h
flashbang.o: flashbang.c flashbang.h