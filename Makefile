all: subdir/foo bar

include subdir/Makefile

bar:
	@echo in main
	@echo $(subdir/cflags)
