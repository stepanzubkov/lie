TARGET = lie
PREFIX ?= /usr/local
SRCS = main.cpp parse.cpp buffer.cpp exit.cpp commands/quit.cpp commands/help.cpp commands/print.cpp commands/open.cpp commands/goto.cpp commands/change.cpp errors.cpp validators/validate_int.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean install uninstall

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(CXXFLAGS)

.cpp:
	$(CXX) $(CXXFLAGS)  -c $< -o $@

clean:
	rm -rf $(TARGET) *.o
install:
	install $(TARGET) $(PREFIX)/bin
uninstall:
	rm -rf $(PREFIX)/bin/$(TARGET)
