sp := $(sp).x
dirstack_$(sp) := $(D)
D := $(dir $(lastword $(MAKEFILE_LIST)))

include rules.mk
include generator/Makefile

$(D)all: $(D)genjava.jar

$(D)cp := $(D)genjava.jar

$(D)foo/foo.java: $(generator/all)
	mkdir -p $(@D)
	cd $(@D) && $(generator/generator) foo

$(D)genjava.jar: $(D)foo/foo.java
	cd $(@D)/foo && javac foo.java
	cd $(@D) && jar cvf genjava.jar foo


D := $(dirstack_$(sp))
sp := $(basename $(sp))
