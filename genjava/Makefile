sp := $(sp).x
dirstack_$(sp) := $(D)
D := $(dir $(lastword $(MAKEFILE_LIST)))

include rules.mk
include generator/Makefile

$(D)d := $(OUT)$(D)genjava.jar

$(D)cp := $(OUT)$(D)genjava.jar

$(OUT)$(D)foo/foo.java: $(generator/d)
	mkdir -p $(@D)
	cd $(@D) && $(generator/generator) foo

$(OUT)$(D)genjava.jar: $(OUT)$(D)foo/foo.java
	mkdir -p $(@D)
	cd $(@D)/foo && javac foo.java
	cd $(@D) && jar cvf genjava.jar foo

D := $(dirstack_$(sp))
sp := $(basename $(sp))
