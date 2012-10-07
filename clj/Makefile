sp := $(sp).x
dirstack_$(sp) := $(D)
D := $(dir $(lastword $(MAKEFILE_LIST)))

include rules.mk

$(D)all:

$(D)cp := $(D)clojure-1.4.0.jar

D := $(dirstack_$(sp))
sp := $(basename $(sp))
