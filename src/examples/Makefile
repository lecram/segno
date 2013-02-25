CXXFLAGS = -Wall -Wextra -Werror -ansi -pedantic -O2
CPPFLAGS = -I../include

objects = sine tremolo realtime

dist : $(objects)
	@echo "Examples compiled: $(objects)"

sine : ../libsegno.a sine.cpp
	$(CXX) $(CXXFLAGS) -o sine sine.cpp $(CPPFLAGS) ../libsegno.a -lm -lsndfile

tremolo : ../libsegno.a tremolo.cpp
	$(CXX) $(CXXFLAGS) -o tremolo tremolo.cpp $(CPPFLAGS) ../libsegno.a -lm -lsndfile

realtime : ../libsegno.a realtime.cpp
	$(CXX) $(CXXFLAGS) -o realtime realtime.cpp $(CPPFLAGS) ../libsegno.a -lm `pkg-config --libs jack` -ljackcpp

.PHONY : clean
clean :
	$(RM) $(objects)
