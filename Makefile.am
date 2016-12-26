SUBDIRS = src

# Only called by CI. Compiles and runs unit tests. Possibly can do better
# with fancy makefiles into '/test' and fancy bells and whistles, but IDK
# enough to do that
test: test_interface

test_interface: test/test_interface.cpp
	g++ -o test_interface -I/tmp/googletest/include -lpthread -ldl $< \
		/tmp/googletest/libgtest.a \
		/tmp/googletest/libgtest_main.a
		./test_interface

.PHONY: test
