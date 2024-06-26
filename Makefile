NAME=get_next_line.c \
	 get_next_line_utils.c \

BNAME=get_next_line_bonus.c \
	 get_next_line_utils_bonus.c \

HEADER=get_next_line.h

BHEADER=get_next_line_bonus.h

DIR=../get_next_line

FLAGS=-Wall -Wextra -Werror
BS=-D BUFFER_SIZE

all: ${NAME} ${HEADER}
	cc ${BS}=1000000 test.c ${NAME} && ./a.out

bonus: ${BNAME} ${BHEADER}
	cc ${BS}=1000000 bonus-test.c ${BNAME} && ./a.out

%.c: 
	cp ${DIR}/$@ ./

%.h:
	cp ${DIR}/$@ ./

clean:
	rm -f ${NAME} ${HEADER} ${BNAME} ${BHEADER}
	rm -f a.out 

re: clean all

.PHONY:all clean re
