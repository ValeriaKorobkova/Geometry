CC = gcc

OBJDIR = build
SRCDIR = src
BINDIR = bin
CFLAGS = -Wall -Werror

OBJECT_FILES = $(addprefix $(OBJDIR)/, main.o circle.o circle_utils.o )

build: $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) -o $(BINDIR)/geometry -lm

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm $(OBJECT_FILES)

format: *.c
	clang-format -i *.c
