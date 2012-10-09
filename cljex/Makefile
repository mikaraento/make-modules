sp := $(sp).x
dirstack_$(sp) := $(D)
D := $(dir $(lastword $(MAKEFILE_LIST)))

include rules.mk

include genjava/Makefile
include clj/Makefile

$(D)d := $(D)run.clj

$(D)run_cp := $(genjava/cp):$(clj/cp)

.PHONY: $(D)run
$(D)run: $(D)run.clj $(genjava/d) $(clj/d)
	java -cp $($(@D)/run_cp) clojure.main $<

D := $(dirstack_$(sp))
sp := $(basename $(sp))
