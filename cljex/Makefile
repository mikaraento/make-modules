sp := $(sp).x
dirstack_$(sp) := $(D)
D := $(dir $(lastword $(MAKEFILE_LIST)))

include rules.mk

include genjava/Makefile
include clj/Makefile

$(D)all:

$(D)run_cp := $(genjava/cp):$(clj/cp)

$(D)run: CP := $($(D)run_cp)
$(D)run: $(D)run.clj $(genjava/all) $(clj/all)
	java -cp $(CP) clojure.main $< && touch $@

D := $(dirstack_$(sp))
sp := $(basename $(sp))
