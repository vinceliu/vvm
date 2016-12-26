SUBDIRS = src

# Only called by CI. Compiles and runs unit tests. Possibly can do better
# with fancy makefiles into '/test' and fancy bells and whistles, but IDK
# enough to do that
test: test_interface

test_interface: test/test_interface.cpp
	g++ -o test_interface -I/tmp/googletest/include $< \
		/tmp/googletest/libgtest.a \
		/tmp/googletest/libgtest_main.a \
		-lpthread -ldl
		./test_interface

.PHONY: test
