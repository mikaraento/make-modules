include root.mk

include generator/Makefile

D := genjava

$(D)/cp := $(OUT)/$(D)/genjava.jar
$(D) := $($(D)/cp)

deps := $(root) $(generator) $(D)/Makefile

$(OUT)/$(D)/foo/foo.java: $(deps)
	mkdir -p $(@D)
	cd $(@D) && $(generator/generator) foo

$(OUT)/$(D)/genjava.jar: $(OUT)/$(D)/foo/foo.java $(deps)
	mkdir -p $(@D)
	cd $(@D)/foo && javac foo.java
	cd $(@D) && jar cvf genjava.jar foo
