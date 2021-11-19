TEMPLATE = subdirs
SUBDIRS += \
    lib \
    testlib \
    tests

lib.subdir = src/lib
testlib.subdir = src/testlib
tests.subdir = src/tests
