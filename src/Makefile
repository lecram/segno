CXXFLAGS = -Wall -Wextra -Werror -ansi -pedantic -O2
CPPFLAGS = -Iinclude

I = include/

objects = segno_core.o segno_op.o segno_dl.o segno_pa.o segno_pac.o segno_osc.o segno_fx.o \
          segno_file.o

dist : $(objects)
	ar rcs libsegno.a $(objects)

segno_core.o : segno_core.cpp $(I)segno_core.hh
	$(CXX) -c $(CXXFLAGS) segno_core.cpp $(CPPFLAGS)

segno_op.o : segno_op.cpp $(I)segno_core.hh $(I)segno_op.hh
	$(CXX) -c $(CXXFLAGS) segno_op.cpp $(CPPFLAGS)

segno_dl.o : segno_dl.cpp $(I)segno_core.hh $(I)segno_dl.hh
	$(CXX) -c $(CXXFLAGS) segno_dl.cpp $(CPPFLAGS)

segno_pa.o : segno_pa.cpp $(I)segno_core.hh $(I)segno_pa.hh
	$(CXX) -c $(CXXFLAGS) segno_pa.cpp $(CPPFLAGS)

segno_pac.o : segno_pac.cpp $(I)segno_core.hh $(I)segno_pac.hh
	$(CXX) -c $(CXXFLAGS) segno_pac.cpp $(CPPFLAGS)

segno_osc.o : segno_osc.cpp $(I)segno_core.hh $(I)segno_osc.hh
	$(CXX) -c $(CXXFLAGS) segno_osc.cpp $(CPPFLAGS)

segno_fx.o : segno_fx.cpp $(I)segno_core.hh $(I)segno_op.hh $(I)segno_dl.hh $(I)segno_osc.hh $(I)segno_fx.hh
	$(CXX) -c $(CXXFLAGS) segno_fx.cpp $(CPPFLAGS)


segno_file.o : segno_file.cpp $(I)segno_core.hh $(I)segno_file.hh
	$(CXX) -c $(CXXFLAGS) segno_file.cpp $(CPPFLAGS)

.PHONY : clean
clean :
	$(RM) $(objects)
