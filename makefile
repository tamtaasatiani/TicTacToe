CC=clang++

BINARY=bin
CODEDIRS=. ./src
INCDIRS=./include
LIBPATH=

DEPFLAGS=-MP -MD
CFLAGS=-Wall -g $(foreach D,$(INCDIRS),-I$(D)) $(DEPFLAGS)
LINKERFLAGS=

CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))
OBJECTS=$(patsubst %.cpp,%.o,$(CFILES))
DEPFILES=$(patsubst %.cpp,%.d,$(CFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(LIBPATH) -o $@ $^ $(LINKERFLAGS)

# % is a make wildcard (% can be anything)
%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $< 
# @ is a special character which refers to the target
# ^ is a special character which refers to the dependency

clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)

-include $(DEPFILES)
