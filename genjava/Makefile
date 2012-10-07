sp := $(sp).x
dirstack_$(sp) := $(D)
D := $(dir $(lastword $(MAKEFILE_LIST)))

include rules.mk
include generator/Makefile

$(D)all: $(D)genjava.jar

$(D)cp := $(D)genjava.jar

$(D)foo.java: $(TOP)/generator/all
	chdir $(D) && $(TOP)/generator/generator foo

$(D)genjava.jar: $(D)foo.java
	echo $(D)all
	chdir $(D) && javac foo.java
	chdir $(D) && jar cvf genjava.jar foo.class


D := $(dirstack_$(sp))
sp := $(basename $(sp))
