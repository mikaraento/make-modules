include rules.mk

D := generator/

$(D)generator := $(abspath $(OUT)$(D)generator)

$(D)d := $(OUT)$(D)generator

$(OUT)$(D)generator: $(D)generator.cpp
	mkdir -p $(@D)
	g++ -o $@ $^
