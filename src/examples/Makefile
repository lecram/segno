CXXFLAGS = -Wall -Wextra -Werror -ansi -pedantic -O2
CPPFLAGS = -I../include

objects = sine

dist : $(objects)
	@echo "Examples compiled: $(objects)"

sine : ../libsegno.a sine.cpp
	$(CXX) $(CXXFLAGS) -o sine sine.cpp $(CPPFLAGS) ../libsegno.a -lm -lsndfile

.PHONY : clean
clean :
	$(RM) $(objects)
