include rules.mk

D := clj

$(D)/cp := $(D)/clojure-1.4.0.jar

$(D)/d := $($(D)/cp)

.PHONY: repl
$(D)/repl: $($(D)/cp) $(root/d)
	java -cp $($(@D)/cp) clojure.main

$(OUT)/$(D)/run-repl.sh: $($(D)/cp) $(root/d) $(D)/Makefile
	mkdir -p $(@D)
	echo java -cp $(abspath $(clj/cp)) clojure.main > $@
	chmod 0755 $@
