CC:=clang
CFLAGS:=-g -O2 -Wall -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: a.x86.s a.aarch64.s a.armv8.s


atomic: atomic.o
	$(CC) $(CFLAGS) -o $@ $<


a.x86.s: atomic.c
	clang $(CFLAGS) -S --target=x86_64-pc-linux-gnu -o $@ $<

a.aarch64.s: atomic.c
	clang $(CFLAGS) -S --target=aarch64-unknown-linux-gnu -o $@ $<

a.armv8.s: atomic.c
	clang $(CFLAGS) -S -mfloat-abi=soft --target=armv8-unknown-linux-gnu -o $@ $<

run: atomic
	./atomic

clean:
	-rm atomic atomic.o atomic.s
	-rm a.aarch64.s a.x86.s a.armv8.s

