CC = gcc
TARGET = programa
SRCDIR = .
TADDIR = Funcions
IMPDIR = TAD



# Wildcard expande un patron, e decir
# busca no directorio SRCDIR todos os
# arquivos que cumpran a condición de
# rematar en .c
SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(SOURCES:.c=.o)

TAD_SOURCES := $(wildcard $(TADDIR)/*.c)
TAD_OBJECTS := $(TAD_SOURCES:.c=.o)

IMP_SOURCES := $(wildcard $(IMPDIR)/*.c)
IMP_OBJECTS := $(IMP_SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS) $(TAD_OBJECTS) $(IMP_OBJECTS)
	$(CC) $^ -o $@

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@

$(TADDIR)/%.o: $(TADDIR)/%.c
	$(CC) -c $< -o $@

$(IMPDIR)/%.o: $(IMPDIR)/%.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TAD_OBJECTS) $(IMP_OBJECTS)

cleanall: clean
	rm -f  $(TARGET)