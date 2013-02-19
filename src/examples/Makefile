CPPFLAGS = -Wall -Wextra -Werror -ansi -pedantic -O2 -I../include

objects = sine

dist : $(objects)
	@echo "Examples compiled: $(objects)"

sine : ../libsegno.a sine.cpp
	$(CXX) $(CPPFLAGS) -o sine sine.cpp -lm -lsndfile ../libsegno.a

.PHONY : clean
clean :
	$(RM) $(objects)
