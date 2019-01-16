CODESSRC := $(wildcard codes/*.c)
TOOLSSRC := $(wildcard tools/*.c)
TOOLSSCRIPTS := $(patsubst tools/%, %, $(wildcard tools/*.sh))
CODESBIN := $(patsubst codes/%.c, %, $(CODESSRC))
TOOLSBIN := $(patsubst tools/%.c, %, $(TOOLSSRC))
BIN = $(CODESBIN) $(TOOLSBIN) $(TOOLSSCRIPTS)

all: $(BIN)

$(BIN): | BINDIR

BINDIR:
	mkdir -p bin/

$(CODESBIN): $(CODESSRC)
	gcc -lm -o bin/$@ codes/$@.c

$(TOOLSBIN): $(TOOLSSRC)
	gcc -lm -o bin/$@ tools/$@.c

$(TOOLSSCRIPTS):
	cp tools/$@ bin/$@
	chmod +x bin/$@
