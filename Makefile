SRC = main.c Stack_Template_Array_Realiz.c Integer_Template_Int.c array.c Resolve.c
OBJ = $(SRC:.c=.o)
EXE = main.exe

CC=gcc
CFLAGS = 
RM = rm

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
.PHONY : all
all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@

.PHONY : run
run: 
	$(EXE)
	
.PHONY : clean
clean:
	-$(RM) $(OBJ) $(EXE)