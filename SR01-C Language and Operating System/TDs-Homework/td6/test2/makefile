OBJS = teststring.o mystrchrn.o mystrinv.o mystrshow.o

myapp : $(OBJS)
	gcc -o myapp $(OBJS)

teststring.o : teststring.c mystrchrn.h mystrinv.h mystrshow.h
	gcc -c teststring.c
	
mystrchrn.o : mystrchrn.c mystrchrn.h
	gcc -c mystrchrn.c
	
mystrinv.o : mystrinv.c mystrinv.h
	gcc -c mystrinv.c

mystrshow.o : mystrshow.c mystrshow.h
	gcc -c mystrshow.c

clean : rm myapp $(OBJS)
