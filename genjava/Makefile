include rules.mk

include generator/Makefile

D := genjava/

$(D)cp := $(OUT)$(D)genjava.jar
$(D)d := $($(D)cp)

$(OUT)$(D)foo/foo.java: $(generator/d)
	mkdir -p $(@D)
	cd $(@D) && $(generator/generator) foo

$(OUT)$(D)genjava.jar: $(OUT)$(D)foo/foo.java
	mkdir -p $(@D)
	cd $(@D)/foo && javac foo.java
	cd $(@D) && jar cvf genjava.jar foo
