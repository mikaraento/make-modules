sp := $(sp).x
dirstack_$(sp) := $(D)
D := $(dir $(lastword $(MAKEFILE_LIST)))

include rules.mk

$(D)generator := $(abspath $(OUT)$(D)generator)

$(D)d := $(OUT)$(D)generator

$(OUT)$(D)generator: $(D)generator.cpp
	mkdir -p $(@D)
	g++ -o $@ $^

D := $(dirstack_$(sp))
sp := $(basename $(sp))
