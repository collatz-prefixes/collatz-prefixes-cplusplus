# Binary target
TGTDIR  := bin
TARGET  ?= collatz
TESTTGT  = test

# Code extensions
SRCEXT	:= .cpp
INCEXT	:= .hpp
TPLEXT	:= .tpp
OBJEXT	:= .o

# Code directories
SRCDIR	:= src
INCDIR	:= include
TPLDIR  := templates
OBJDIR	:= build

# Compiler and linker
CC			:= g++
LD			:= g++
CCMACRO ?= 
LDOPTS	:= -L$(OBJDIR)
INCOPTS := -I$(INCDIR) -I$(TPLDIR)
CCFLAGS	:= -O3 -Wall -Wextra -pedantic -Wno-sign-compare -std=c++20 $(CCMACRO)
 
# Code files
INCS     = $(shell find $(INCDIR) -type f -name '*$(INCEXT)')
INCS 	  += $(shell find $(TPLDIR) -type f -name '*$(TPLEXT)')
SRCS		 = $(shell find $(SRCDIR) -type f -name '*$(SRCEXT)') 
OBJS	   = $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SRCS:.cpp=.o))

# First rule
all: $(TARGET) | $(TGTDIR)
	@mv $(TARGET) $(TGTDIR)/

# Linking
$(TARGET): $(OBJS) 
	$(LD) $(LDFLAGS) -o $@ $^

# Compiling
$(OBJS): $(OBJDIR)/%$(OBJEXT) : $(SRCDIR)/%$(SRCEXT) | $(OBJDIR)
	$(CC) $(CCFLAGS) $(INCOPTS) -c -o $@ $?

# Objects directory
$(OBJDIR):
	mkdir -p $(OBJDIR)  

# Target directory
$(TGTDIR):
	mkdir -p $(TGTDIR)  

# Run with arguments
run:
	@./$(TGTDIR)/$(TARGET) $(ARGUMENTS)

# Run tests
validate: 
	@./$(TGTDIR)/$(TESTTGT)

# Clean objects and binaries
clean:
	rm -f $(OBJS)

# Create a test binary
tests:
	@make clean
	@make CCMACRO="-DCOLLATZ_TESTING=1" TARGET=$(TESTTGT)

# Clean and make again
again:
	@make clean
	@make

# Diagnostic to show files
show:
	@echo "Sources: $(SRCS)"
	@echo "Includes: $(INCS)"
	@echo "Objects: $(OBJS)" 

.PHONY: all run validate clean again test show
