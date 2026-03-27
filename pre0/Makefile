cc := gcc
cflags := -Wall -g
bin := app 

objs := $(patsubst %.c,%.o,$(wildcard *.c))

all: $(objs)
	$(cc) $(objs) -o $(bin)

%.o: %.c
	$(cc) -c $^

.PHONY: clean

clean:
	rm -f $(objs) $(bin)
