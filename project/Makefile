COMMON_OBJECTS  = main.o
CPU             = msp430g2553
CFLAGS = -mmcu=${CPU} -I../timerLib -I../demos/h -L/opt/ti/msp430_gcc/include
# LDFLAGS		= -L/opt/ti/msp430_gcc/include

CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf libs

libs:
    (cd ../timerLib; make install)
    (cd ../lcdLib; make install)
    (cd ../wakedemo; make)

main.elf: ${COMMON_OBJECTS} buzzer.o ../timerLib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh $^

clean:
	(cd timerLib; make clean)
	(cd lcdLib; make clean)
	(cd wakedemo; make clean)
	rm -f *.o *.elf

buzzer.c: buzzer.h
