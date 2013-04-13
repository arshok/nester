PROGRAM=nintendo
CXX=clang++
CXXFLAGS=-std=c++11
SOURCES=$(wildcard ./source/*.cc)
OBJECTS=$(patsubst ./source/%.cc,%.o, $(SOURCES))
INCLUDES=
LIBRARIES=
INCLUDE_PATHS=-I/usr/include/ -I/usr/local/include/
LIBRARY_PATHS=-L/usr/lib/ -L/usr/local/lib/

$(PROGRAM): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LIBRARY_PATHS) $(LIBRARIES) $(OBJECTS) -o $@

$(OBJECTS): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCLUDE_PATHS) -c $<

clean:
	@ rm -rf $(PROGRAM) $(OBJECTS)

