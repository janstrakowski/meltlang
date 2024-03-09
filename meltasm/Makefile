CC := clang
CFLAGS := -Wall -Wextra -Wno-unused-function -I ../libdtstruct/header -g3

SRCS := $(wildcard src/*.c)

.PHONY: all
all: meltasm

meltasm: $(patsubst src/%.c,src/%.o,$(SRCS))
	$(CC) $(CFLAGS) -o $@ $^

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f meltasm
	rm -f src/*.o
