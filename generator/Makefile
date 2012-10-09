include rules.mk

D := generator

$(D)/generator := $(abspath $(OUT)/$(D)/generator)

$(D)/d := $(OUT)/$(D)/generator

$(OUT)/$(D)/generator: $(D)/generator.cpp $(wildcard $(D)/*h) $(D)/Makefile $(root/d)
	mkdir -p $(@D)
	g++ $(root/cflags) -o $@ $<
