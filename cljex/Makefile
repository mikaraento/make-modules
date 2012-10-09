include rules.mk

include genjava/Makefile
include clj/Makefile

D := cljex

$(D)/d := $(D)/run.clj

$(D)/run_cp := $(genjava/cp):$(clj/cp)

.PHONY: $(D)/run
$(D)/run: $(D)/run.clj $(genjava/d) $(clj/d)
	java -cp $($(@D)/run_cp) clojure.main $<
