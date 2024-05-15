NAME=gnl.c \
	 utils.c \

HEADER=gnl.h

DIR=../../get_next_line

FLAGS=-Wall -Wextra -Werror
BS=-D BUFFER_SIZE

all: ${NAME} ${HEADER}
	cc ${BS}=40 test.c ${NAME} && ./a.out

%.c: 
	cp ${DIR}/$@ ./

%.h:
	cp ${DIR}/$@ ./

clean:
	rm -f ${NAME} ${HEADER}
	rm -f a.out 

re: clean all

.PHONY:all clean re
