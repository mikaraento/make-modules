include root.mk

include library/Makefile

D := generator

$(D)/generator := $(abspath $(OUT)/$(D)/generator)

$(D) := $(OUT)/$(D)/generator

.deps := $(root) $(library) $(D)/Makefile

$(OUT)/$(D)/generator: $(D)/generator.cpp $(wildcard $(D)/*h) $(.deps)
	mkdir -p $(@D)
	g++ $(root/cflags) $(library/cflags) $(library/ldflags) -o $@ $<
