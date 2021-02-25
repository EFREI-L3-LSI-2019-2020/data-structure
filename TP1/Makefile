DEBUG=yes
CC=gcc
ifeq ($(DEBUG),yes)
	CFLAGS=-g
	LDFLAGS=
else
	CFLAGS=
	LDFLAGS=
endif
EXEC=number
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)
ifeq ($(DEBUG),yes)
	@echo "Génération en mode debug"
else
	@echo "Génération en mode release"
endif

number: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

number.o: number.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)