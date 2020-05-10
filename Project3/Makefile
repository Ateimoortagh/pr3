CC 	 = gcc	#compiler name
CFLAGS   = -Wall # compress all warning, choose your own compile flags (if any)
TARGET   = test
OBJFILES = test.o list.o
  
$(TARGET): $(OBJFILES)  
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) 

test.o: test.c list.c      # Meaning: target listmain.o depends on test.c list.c
	gcc -c test.c list.c   # Command to make the target

list.o: list.c   list.h #target list.o depends on list.c and indirectly on list.h	
	gcc -c list.c
clean: 
	rm -f $(OBJFILES) $(TARGET)
