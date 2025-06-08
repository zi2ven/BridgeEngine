SDL_PKG_CONFIG	:= $(shell pkg-config --cflags --libs sdl2)

CC				:= gcc
C_FLAGS			:= -Wall -Wextra -O2 -g3 -I include

C_SOURCES		:= $(shell find * -name "*.c")
OBJS			:= $(C_SOURCES:%.c=%.o)

all: link

%.o: %.c
		@printf "**CC** $< -> $@\n"
		@$(CC) $(C_FLAGS) -c -o $@ $< $(SDL_PKG_CONFIG)

link: $(OBJS)
		$(CC) $(C_FLAGS) $^ -o main $(SDL_PKG_CONFIG)

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
