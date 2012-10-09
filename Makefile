default: all

include root.mk

include cljex/Makefile

all: $(cljex/run)

clean:
	rm -rf $(OUT)
	mkdir -p $(OUT)
