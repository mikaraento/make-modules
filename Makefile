all: subdir/foo bar

include subdir/Makefile

.PHONY: bar
bar:
	@echo in main
	@echo $(subdir/cflags)

.PHONY: clean
clean:
	rm -rf build
	mkdir -p build
