SDL_PKG_CONFIG	:= $(shell pkg-config --cflags --libs sdl2)

CC				:= gcc
C_FLAGS			:= -Wall -Wextra -O2 -g3 $(SDL_PKG_CONFIG) -I include

C_SOURCES		:= $(shell find * -name "*.c")
OBJS			:= $(C_SOURCES:%.c=%.o)

LIB_PATH = $(shell $(CC) -print-search-dirs | grep libraries | cut -d= -f2)
CRT1_O = $(shell $(CC) -print-file-name=crt1.o)
CRTI_O = $(shell $(CC) -print-file-name=crti.o)
CRTN_O = $(shell $(CC) -print-file-name=crtn.o)
LIBC = $(shell $(CC) -print-file-name=libc.so)
DYNAMIC_LINKER = $(shell $(CC) -print-file-name=ld-linux-x86-64.so.2)

all: link

%.o: %.c
		@printf "**CC** $< -> $@\n"
		@$(CC) $(C_FLAGS) -c -o $@ $<

link: $(OBJS)
		$(CC) $(C_FLAGS) $^ -o main

%.fmt: %
		@printf "**fmt** $< ...\n"
		@clang-format -i $<

%.tidy: %
		@printf "**tidy** $< ...\n"
		@clang-tidy $< -- $(C_FLAGS)

.PHONY: format check clean

format: $(C_SOURCES:%=%.fmt) $(S_SOURCES:%=%.fmt) $(HEADERS:%=%.fmt)
		@printf "**fmt** done \n"

check: $(C_SOURCES:%=%.tidy) $(S_SOURCES:%=%.tidy) $(HEADERS:%=%.tidy)
		@printf "**check** done \n"

clean: 
	rm -f $(OBJS)
