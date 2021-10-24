TEMPLATE = subdirs
SUBDIRS += \
    lib \
    tests

lib.subdir = src/lib
tests.subdir = src/tests
