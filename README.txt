There are _packages_ named like foo/bar.

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

Additionally each module exports a variable $(foo/bar) that you must
depend on to access any of the other variables. This variable must
depend on all the artefacts the module has so that dependent modules
get recompiled.

All things must depend on $(root) and their own module Makefile - that
way you'll rebuild if command line flags change.

Environment variables should not affect builds.

root.mk defines a variable OUT for the build output. All actual output
files should go under $(OUT)/package ($(OUT)/foo/bar).

Each Makefile can be given as a -f argument to make; files that
only make sense when included somewhere else should be named *.mk.

A package can (of course) use something else than make to actually
build its exports, but it should have the correct dependencies to
integrate into the build (and should not build unnecessarily either).

---

Practical guidelines

- for each Makefile it's convenient to define a shortcut to the directory
  (package) it lives in so you don't have to keep spelling it out, e.g.,
  foo/bar/Makefile: D := foo/bar; this should be set after all includes
- for each package it's convenient to define a variable that holds that
  package's dependencies and use it as a dependency in all your rules
  foo/bar/Makefile:
    .deps := $(quuz) $(root) $(D)/Makefile
    $(OUT)/$(D)/exe: exe.cpp $(.deps)
      g++ $(root/cflags) -o $@ $<
- to manage the scope of variables the following three things are allowed:
    - you can define any variable prefixed with your package name
    - any name beginning with a leading dot (.deps) can be defined
      by any makefile and used locally
    - any target-specific variable will not affect any other targets
      and you can use them freely
- note that since all Makefiles will use the $(D) variable, you can't
  use it in recipes (since they are only expanded during execution)
- always use := to assign to variables so that the right-hand-side
  is expanded when defining  

---

Notable things:

- non-recursive makefiles
- hence all paths are relative to root directory
- and you run make always from the root directory
- dependencies are between modules, not between files (simple graph,
  easier to get right, always correct, most of the performance benefits
  of the dependency graph)
- inside a module, you should prob. depend on all of your headers
  rather than use fancy dependency generation (simpler, less work
  at graph creation time, possibly some extra compilation)
- not using a directory stack for the D variable, instead setting
  it explicitly after includes  

