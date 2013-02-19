CPPFLAGS = -Wall -Wextra -Werror -ansi -pedantic -O2 -Iinclude

I = include/

objects = segno_core.o segno_op.o segno_dl.o segno_pa.o segno_pac.o segno_osc.o segno_fx.o \
          segno_file.o

dist : $(objects)
	ar rcs libsegno.a $(objects)

segno_core.o : segno_core.cpp $(I)segno_core.hh
	$(CXX) -c $(CPPFLAGS) segno_core.cpp

segno_op.o : segno_op.cpp $(I)segno_core.hh $(I)segno_op.hh
	$(CXX) -c $(CPPFLAGS) segno_op.cpp

segno_dl.o : segno_dl.cpp $(I)segno_core.hh $(I)segno_dl.hh
	$(CXX) -c $(CPPFLAGS) segno_dl.cpp

segno_pa.o : segno_pa.cpp $(I)segno_core.hh $(I)segno_pa.hh
	$(CXX) -c $(CPPFLAGS) segno_pa.cpp

segno_pac.o : segno_pac.cpp $(I)segno_core.hh $(I)segno_pac.hh
	$(CXX) -c $(CPPFLAGS) segno_pac.cpp

segno_osc.o : segno_osc.cpp $(I)segno_core.hh $(I)segno_osc.hh
	$(CXX) -c $(CPPFLAGS) segno_osc.cpp

segno_fx.o : segno_fx.cpp $(I)segno_core.hh $(I)segno_op.hh $(I)segno_dl.hh $(I)segno_osc.hh $(I)segno_fx.hh
	$(CXX) -c $(CPPFLAGS) segno_fx.cpp


segno_file.o : segno_file.cpp $(I)segno_core.hh $(I)segno_file.hh
	$(CXX) -c $(CPPFLAGS) segno_file.cpp

.PHONY : clean
clean :
	$(RM) $(objects)
