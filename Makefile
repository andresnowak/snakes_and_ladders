TARGET = app

SRCS  = $(shell find ./src     -type f -name *.cpp)
HEADS = $(shell find ./headers -type f -name *.h)
OBJS = $(SRCS:.cpp=.o)
DEPS = Makefile.depend

INCLUDES = -I./headers
CXXFLAGS = -O2 -Wall $(INCLUDES)
LDFLAGS = -lm


all: $(TARGET)

$(TARGET): $(OBJS) $(HEADS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

run: all
	@./$(TARGET)

.PHONY: depend clean tests
depend:
	$(CXX) $(INCLUDES) -MM $(SRCS) > $(DEPS)
	@sed -i -E "s/^(.+?).o: ([^ ]+?)\1/\2\1.o: \2\1/g" $(DEPS)

clean:
	$(RM) $(OBJS) $(TARGET)

tests:
	cat tests/tests.txt | ./app

-include $(DEPS)