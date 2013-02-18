CPPFLAGS = -Wall -Wextra -Werror -ansi -pedantic -O2 -Iinclude

I = include/

objects = segno_core.o segno_op.o segno_dl.o segno_pa.o segno_pac.o segno_osc.o segno_fx.o

dist : $(objects)
	ar rcs libsegno.a $(objects)

segno_core.o : segno_core.cpp $(I)segno_core.hh
	$(CC) -c $(CPPFLAGS) segno_core.cpp

segno_op.o : segno_op.cpp $(I)segno_op.hh
	$(CC) -c $(CPPFLAGS) segno_op.cpp

segno_dl.o : segno_dl.cpp $(I)segno_dl.hh
	$(CC) -c $(CPPFLAGS) segno_dl.cpp

segno_pa.o : segno_pa.cpp $(I)segno_pa.hh
	$(CC) -c $(CPPFLAGS) segno_pa.cpp

segno_pac.o : segno_pac.cpp $(I)segno_pac.hh
	$(CC) -c $(CPPFLAGS) segno_pac.cpp

segno_osc.o : segno_osc.cpp $(I)segno_osc.hh
	$(CC) -c $(CPPFLAGS) segno_osc.cpp

segno_fx.o : segno_fx.cpp $(I)segno_fx.hh
	$(CC) -c $(CPPFLAGS) segno_fx.cpp

.PHONY : clean
clean :
	$(RM) $(objects)
