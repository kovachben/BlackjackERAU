CC = gcc
CFLAGS = 
TARGET_FILES = actions.c dealer.c deck.c payout.c playerhand.c game.c
OBJECTS = $(TARGET_FILES:.c=.o)
EXEC = program

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXEC)