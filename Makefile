SRC_FILES = llist.c lnode.c lnode.h

test : llist
	./llist < input.txt
	
llist : llist.c lnode.c lnode.h
	gcc -Wall -g -o llist llist.c lnode.c
	
gdb : llist
	gdb -x gdbcmds.txt llist
	
clean :
	-rm llist
	
submit : $(SRC_FILES)
	mkdir $(USER)_proj2
	cp $(SRC_FILES) $(USER)_proj2
	tar -cvzf $(USER)_proj2.tar.gz $(USER)_proj2
	rm -r $(USER)_proj2	