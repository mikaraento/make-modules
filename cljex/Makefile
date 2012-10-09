include root.mk

include genjava/Makefile
include clj/Makefile

D := cljex

$(D) := $(D)/run.clj
deps := $(genjava) $(clj) $(root)

$(D)/run_cp := $(genjava/cp):$(clj/cp)

$(D)/run := $(D)/run

.PHONY: $(D)/run
$(D)/run: $(D)/run.clj $(deps)
	java -cp $($(@D)/run_cp) clojure.main $<
