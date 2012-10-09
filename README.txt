There are _packages_ named like foo/bar/.

Each package lives in a Makefile (one Makefile can have multiple packages).

Packages can export:
  - jars / classpath entries
  - compilation flags
  - shared objects / linker flags
  - executables / executable names
  - headers

All exports except headers are expressed as makefile variables:
  - jars: $(foo/bar/cp)
  - compilation flags: $(foo/bar/cflags)
  - sos: $(foo/bar/ldflags)
  - exes: $(foo/bar/baz)

Headers are used by referring to the full path: foo/bar/.../baz.h

Additionally each module exports a variable $(foo/bar/d) that you must
depend on to access any of the other variables. This variable must
depend on all the artefacts the module has so that dependent modules
get recompiled.

---

Notable things:

- non-recursive makefiles
- dependencies are between modules, not between files (simple graph,
  easier to get right, always correct, most of the performance benefits
  of the dependency graph)
- inside a module, you should prob. depend on all of your headers
  rather than use fancy dependency generation (simpler, less work
  at graph creation time, possibly some extra compilation)
