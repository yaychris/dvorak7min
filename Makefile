INSTALL = /usr/local/games/bin

# Uncomment these lines if you want to change the defaults to something else

#PRETTINESS = -DNOT_SO_PRETTY
#NASTINESS = -DNASTY_AS_USUAL
#BEEPS = -DBEEPS_ARENT_IRRITATING
#FLASHES = -DFLASHES_ARENT_IRRITATING
#COLORS = -DNO_COLORS_PLEASE
#PROGRAMMER_DVORAK = -DPROGRAMMER_DVORAK

# Max length of imported texts.  Set it to 0 or comment it if you don't want
# a limit
LIMIT_LENGTH = -DLIMIT_LENGTH=1024

### That's all ###

#CC      = gcc
PROF    = -g0 -O2
CFLAGS  = $(PROF) -Wall \
	$(PRETTINESS) $(NASTINESS) $(BEEPS) $(FLASHES) $(COLORS) \
	$(LIMIT_LENGTH) $(PROGRAMMER_DVORAK)
LDFLAGS = $(PROF)
LIBS    = -lncurses

OBJECTS = dvorak7min.o lessons.o
HEADERS = lessons.h
TARGET  = dvorak7min

dvorak7min: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

all: dvorak7min

clean:
		rm -f $(OBJECTS) $(TARGET)
install:
		install -d $(INSTALL)
		install -s dvorak7min $(INSTALL)

