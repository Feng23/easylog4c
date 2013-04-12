CC = gcc
CFLAGS = -O3
INCDR = .

all: elog.o

test: test/test_elog_a_fatal.out test/test_elog_a_error.out test/test_elog_a_warn.out test/test_elog_a_info.out test/test_elog_a_debug.out test/test_elog_a_trace.out

elog.o : elog.c
	$(CC) -c $(CFLAGS) -I$(INCDR) $^ -o $@

test/test_elog_a_fatal.out : test/test_elog_a.c elog.o
	$(CC) -o $@ $(CFLAGS) -I$(INCDR) $^ -DElogLevel=0

test/test_elog_a_error.out : test/test_elog_a.c elog.o
	$(CC) -o $@ $(CFLAGS) -I$(INCDR) $^ -DElogLevel=1

test/test_elog_a_warn.out : test/test_elog_a.c elog.o
	$(CC) -o $@ $(CFLAGS) -I$(INCDR) $^ -DElogLevel=2

test/test_elog_a_info.out : test/test_elog_a.c elog.o
	$(CC) -o $@ $(CFLAGS) -I$(INCDR) $^ -DElogLevel=3

test/test_elog_a_debug.out : test/test_elog_a.c elog.o
	$(CC) -o $@ $(CFLAGS) -I$(INCDR) $^ -DElogLevel=4

test/test_elog_a_trace.out : test/test_elog_a.c elog.o
	$(CC) -o $@ $(CFLAGS) -I$(INCDR) $^ -DElogLevel=5


clean:
	rm -f *.o
	rm -f test/*.out

