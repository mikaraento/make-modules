include root.mk

D := clj

$(D)/cp := $(D)/clojure-1.4.0.jar

$(D) := $($(D)/cp)

deps := $(root) $(D)/Makefile

.PHONY: repl
$(D)/repl: $(deps)
	java -cp $($(@D)/cp) clojure.main

$(OUT)/$(D)/run-repl.sh: $(deps)
	mkdir -p $(@D)
	echo java -cp $(abspath $(clj/cp)) clojure.main > $@
	chmod 0755 $@
