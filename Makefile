default: all

include rules.mk

include cljex/Makefile

all: $(cljex/run)

clean:
	rm -rf $(OUT)
	mkdir -p $(OUT)
