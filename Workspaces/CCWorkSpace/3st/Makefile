#TODO: Set your googletest directory path
GTEST_DIR = /Users/bagseongmin/googletest/googletest

CC=clang++
CPPFLAGS += -isystem $(GTEST_DIR)/include

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

#TODO: Set your executable target
all : hw3

#TODO: Change 'hw2.cc' and 'util.o' to your main source file and util target respectively
hw3: hw3.cc int_accumulator.o float_accumulator.o 
	$(CC) --std=c++17 $^ -o $@

#TODO: Change 'util.h' and 'util.cc' to your source files
int_accumulator.o : int_accumulator.cc
	$(CC) --std=c++17 -c $^ -o $@

#TODO: Change 'util.h' and 'util.cc' to your source files
float_accumulator.o : float_accumulator.cc
	$(CC) --std=c++17 -c $^ -o $@

#TODO: Change 'util_test.cc' to your test file
test.o : test.cc $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c $< -o $@

#TODO: Change 'util_test.o'and 'util.o' to your object targets
test: test.o int_accumulator.o float_accumulator.o gtest_main.a
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@

#TODO: Change 'main' and 'main_test' to your executable and test respectively
clean:
	 rm -f gtest.a gtest_main.a *.o hw2 test

gtest-all.o: $(GTEST_SRCS_) 
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) --std=c++17 -c\
		$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) --std=c++17 -c\
		$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean


