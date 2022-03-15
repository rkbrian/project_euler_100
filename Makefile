# Memo
# Problem level: easy
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
# Sometimes I would like to practice C++ a little
CPPC = g++
CPPFLAGS = -std=c++11
# If not noted, all execution commands are: ./<exe file>

001:	001.c # exe command: ./001 <number>
	$(CC) $(CFLAGS) $^ -o $@
002:	002.c
	$(CC) $(CFLAGS) $^ -o $@
003:	003.c
	$(CC) $(CFLAGS) $^ -o $@
004:	004.c
	$(CC) $(CFLAGS) $^ -o $@
005:	005.c
	$(CC) $(CFLAGS) $^ -o $@
006:	006.c
	$(CC) $(CFLAGS) $^ -o $@
007:	007.c
	$(CC) $(CFLAGS) $^ -o $@
008:	008.c
	$(CC) $(CFLAGS) $^ -o $@
009:	009.c
	$(CC) $(CFLAGS) $^ -o $@
010:	010.c
	$(CC) $(CFLAGS) $^ -o $@
011:	011.c
	$(CC) $(CFLAGS) $^ -o $@
012:	012.c
	$(CC) $(CFLAGS) $^ -o $@
013:	013.c
	$(CC) $(CFLAGS) $^ -o $@
014:	014.c
	$(CC) $(CFLAGS) $^ -o $@
015:	015.c
	$(CC) $(CFLAGS) $^ -o $@
016:	016.c
	$(CC) $(CFLAGS) $^ -o $@
017:	017.c
	$(CC) $(CFLAGS) $^ -o $@
018:	018.c
	$(CC) $(CFLAGS) $^ -o $@
019:	019.c
	$(CC) $(CFLAGS) $^ -o $@
020:	020.c
	$(CC) $(CFLAGS) $^ -o $@
021:	021.cpp
	$(CPPC) $(CPPFLAGS) $^ -o $@
022:	022.cpp
	$(CPPC) $(CPPFLAGS) $^ -o $@
023:	023.cpp
	$(CPPC) $(CPPFLAGS) $^ -o $@
024:	024.cpp
	$(CPPC) $(CPPFLAGS) $^ -o $@
025:	025.cpp
	$(CPPC) $(CPPFLAGS) $^ -o $@
026:	026.cpp
	$(CPPC) $(CPPFLAGS) $^ -o $@
027:	027.cpp
	$(CPPC) $(CPPFLAGS) $^ -o $@
028:	028.cpp
	$(CPPC) $(CPPFLAGS) $^ -o $@
029:	029.cpp
	$(CPPC) $(CPPFLAGS) $^ -o $@
030:	030.cpp
	$(CPPC) $(CPPFLAGS) $^ -o $@
.PHONY: $(CC) $(CFLAGS) $(CPPC) $(CPPFLAGS) 001 002 003 004 005 006 007 008 009 010 011 012 013 014 015 016 017 018 019 020\
 021 022 023 024 025 026 027 028 029 030
