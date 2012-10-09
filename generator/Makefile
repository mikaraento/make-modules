include root.mk

D := generator

$(D)/generator := $(abspath $(OUT)/$(D)/generator)

$(D) := $(OUT)/$(D)/generator

deps := $(root) $(D)/Makefile

$(OUT)/$(D)/generator: $(D)/generator.cpp $(wildcard $(D)/*h) $(deps)
	mkdir -p $(@D)
	g++ $(root/cflags) -o $@ $<
