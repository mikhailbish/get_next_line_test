NAME=get_next_line.c \
	 get_next_line_utils.c \

HEADER=get_next_line.h

DIR=../get_next_line

FLAGS=-Wall -Wextra -Werror
BS=-D BUFFER_SIZE

all: ${NAME} ${HEADER}
	cc ${BS}=9999999999999 test.c ${NAME} && ./a.out

%.c: 
	cp ${DIR}/$@ ./

%.h:
	cp ${DIR}/$@ ./

clean:
	rm -f ${NAME} ${HEADER}
	rm -f a.out 

re: clean all

.PHONY:all clean re
