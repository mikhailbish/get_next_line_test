LIB=libft.a

HEADER=libft.h

DIR=../libft

FLAGS=-Wall -Wextra -Werror
BS=-D BUFFER_SIZE

all: $(HEADER) ${LIB} test.c
	cc ${BS}=100000000000000000000 test.c $(LIB) && man atoi | ./a.out

$(LIB):
	make -C $(DIR) re
	cp $(DIR)/$(LIB) ./

$(HEADER):
	cp $(DIR)/$(HEADER) ./


clean:
	rm -f ${HEADER}
	rm -f ${LIB}
	rm -f a.out 

re: clean all

.PHONY:all clean re
