#
# Makefile
#
# Author       : Finn Rayment <finn@rayment.fr>
# Date created : 15/03/2021
#

VERSION:=1.0

CC:=cc
CCFLAGS:=-O2 --std=c89 \
         -Wall -Wextra -Wpedantic -Werror --pedantic-errors \
         -DVERSION=\"${VERSION}\"

SOURCES:=$(wildcard src/*.c)
OBJECTS:=$(patsubst src/%,obj/%,$(patsubst %.c,%.o,$(SOURCES)))
INCLUDE:=-Iinclude/

TEST_SOURCES:=$(wildcard test/*.c)
TEST_BINARIES:=$(patsubst %.c,%,$(TEST_SOURCES))

all: $(OBJECTS)
	mkdir -p obj

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf obj $(TEST_BINARIES)

test: $(TEST_BINARIES)
	cd test && sh test.sh

test/%: test/%.c
	$(CC) -g $(CCFLAGS) $(INCLUDE) $(OBJECTS) $< -o $@

.PHONY: all clean test

