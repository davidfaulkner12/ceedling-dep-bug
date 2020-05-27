# tl;dr
I would expect dependencies to work correctly and the same way for release and test.

In fact, libraries with a "source" artefact aren't being included correctly in the compiler commands for `ceedling test`.

# Detailed Description
This is using `ceedling-0.29.2b.gem`.

If I run `ceedling verbosity[4] release` in this repo, the final GCC line is:

```
> Shell executed command:
'gcc "third_party/zlog/tidy/zlog.c" "build/release/out/c/core.o" "build/release/out/c/main.o" -L third_party/builds/jemalloc/lib -o "build/release/project.out" -ljemalloc'
```

And it all works correctly. However, if I run `ceedling verbosity[4] test` on this repo, it does NOT link in the C file:

```
Linking test_core.out...
Undefined symbols for architecture x86_64:
  "_zlogf_time", referenced from:
      _add in core.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
ERROR: Shell command failed.
> Shell executed command:
'gcc "build/test/out/c/test_core_runner.o" "build/test/out/c/test_core.o" "build/test/out/c/unity.o" "build/test/out/c/core.o" "build/test/out/c/cmock.o" -L third_party/builds/jemalloc/lib -o "build/test/out/test_core.out" -ljemalloc'
> And exited with status: [1].
```

If I change `#include <zlog.h>` to `#include <zlog.c>` in the test file it DOES work but that seems surprising.

I would expect dependencies to work correctly and the same way for release and test.
