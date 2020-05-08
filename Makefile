CC = gcc

OBJDIR = build
SRCDIR = src
BINDIR = bin
TSTDIR = test
CFLAGS = -Wall -Werror

OBJECT_FILES = $(addprefix $(OBJDIR)/, circle.o circle_utils.o )
TEST_FILE = $(TSTDIR)/test.o
MAIN_FILE = $(OBJDIR)/main.o

build: $(OBJECT_FILES) $(MAIN_FILE)
	$(CC) $(OBJECT_FILES) $(MAIN_FILE) -o $(BINDIR)/geometry -lm

test: $(OBJECT_FILES) $(TEST_FILE)
	$(CC) $(OBJECT_FILES) $(TEST_FILE) -o $(BINDIR)/test -lm

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm $(OBJECT_FILES)

format: *.c
	clang-format -i *.c
