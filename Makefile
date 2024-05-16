CC = g++
ODIR = obj
SDIR = src
OUT = app


_OBJS = main.o subject.o modes.o users.o utils.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp 
	$(CC) -c -o $@ $<

$(OUT): $(OBJS) 
	$(CC) $^ -o $(OUT)
clear:
	rm -f $(ODIR)/*.o
	
