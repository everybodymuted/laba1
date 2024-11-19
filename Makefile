CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = main.c calc.c
OBJ = $(SRC:.c=.o)
	EXEC = cmdcalc

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(OBJ)
		$(CC) $(OBJ) -o $(EXEC)

%.o: %.c calc.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ) $(EXEC)

run: $(EXEC)
		./$(EXEC) 234 + 32 23 + 32 32 + 12 233 - 180 11 "*" 5 19 + 23 200 % 5 -k 2 
		







