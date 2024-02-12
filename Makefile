SRCDIR=../src
INCDIR=../inc
OBJDIR=../obj
BINDIR=../bin
CFLAGS=-c -g -Wall -I${INCDIR}

all:
        gcc ${CFLAGS} ${SRCDIR}/main1.c -o ${OBJDIR}/main1.o
        gcc ${CFLAGS} ${SRCDIR}/user.c -o ${OBJDIR}/user.o
        gcc ${CFLAGS} ${SRCDIR}/cfss.c -o ${OBJDIR}/cfss.o
        gcc ${CFLAGS} ${SRCDIR}/admin.c -o ${OBJDIR}/admin.o
        gcc ${OBJDIR}/main1.o ${OBJDIR}/user.o ${OBJDIR}/cfss.o ${OBJDIR}/admin.o -o ${BINDIR}/cfs
clean:
        rm gcc ${OBJDIR}/main1.o ${OBJDIR}/user.o  ${OBJDIR}/cfss.o ${OBJDIR}/admin.o ${BINDIR}/cfs
