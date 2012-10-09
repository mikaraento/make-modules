include root.mk

D := library

$(D) := $(OUT)/$(D)/library.$(SO)
.deps := $(root) $(wildcard $(D)/*.h) $(D)/Makefile

$(OUT)/$(D)/library.o: $(D)/library.cpp $(.deps)
	mkdir -p $(@D)
	g++ -c -fPIC $(root/cflags) -o $@ $<

$(OUT)/$(D)/library.$(SO): $(OUT)/$(D)/library.o $(.deps)
	mkdir -p $(@D)
	g++ -dynamiclib -o $(abspath $@) $<

$(D)/ldflags := $(abspath $(OUT)/$(D)/library.$(SO))
