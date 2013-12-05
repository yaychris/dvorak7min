/*
 *  Dvorak 7min 1.6.1, a Dvorak typing tutor
 *  Copyright (C) 1998-2003  Ragnar Hojland Espinosa 
 * 			     <ragnar@ragnar-hojland.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */ 

/*
 * It's horrible code. I agree.
 * I wanted it. I needed it. I now have it. 
 * I hope it ends my frustration learning dvorak.
 * Otherwise I'm gonna kill someone. Soon.
 * Do I sound desesperate?
 *
 * Try truning on the nastiness option.
 * You can use the space bar or the enter key interchangeably.
 * 
 * As far as 1.1, the code doesn't look that bad now thanks to Smoke,
 * so mental SANity loss is reduced from 1d100 to merely 1d10.
 *
 *
 * Smoke/CRAP here - I just hacked 1.3 up and it's pretty late
 *                   a great excuse for messing up the code even more :)
 *
 * Hm, 1.5 and I'm pondering on sumbitting it to the Ofuscated C contest...
 * It'll take a few versions more and some extra "features", and who knows.
 * This baby is fun :)
 *  
 */

#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <curses.h>
#include <getopt.h>
#include <errno.h>
#include <sys/stat.h>

#include "lessons.h"

/* these three represent the visualization of the key on screen */
#define PRESSED_NOT       0
#define PRESSED_REQUESTED 1
#define PRESSED_BY_USER   2

/* Update cp[sm] every LATENCY tenths of second */
#define LATENCY 1

#ifdef NOT_SO_PRETTY
int tryToBePretty = 0;
#else
int tryToBePretty = 1;
#endif

#ifdef BEEPS_ARENT_IRRITATING
int beepsArentIrritating = 1;
#else
int beepsArentIrritating = 0;
#endif

#ifdef FLASHES_ARENT_IRRITATING
int flashesArentIrritating = 1;
#else
int flashesArentIrritating = 0;
#endif

#ifdef NASTY_AS_USUAL
int nastiness = 1;
#else
int nastiness = 0;
#endif

#ifdef NO_COLORS_PLEASE
int colorSupport = 0;
#else
int colorSupport = 1;
#endif

#ifdef NO_KEYS
int hideKeys = 1;
#else
int hideKeys = 0;
#endif

int max_editable_lines = 6;
int right_margin = 70;

const char *postmortem = "undefined postmortem";

/* all typable characters */
char typables[] = "`1234567890[]',.pyfgcrl/=\\aoeuidhtns-;qjkxbmwvz"
                  "~!@#$%^&*(){}\"<>PYFGCRL?+|AOEUIDHTNS_:QJKXBMWVZ\n ";

#ifdef PROGRAMMER_DVORAK
char map[] =
{
      '$', '~', '&', '%', '[', '7', '{', '5', '}', '3', '(', '1', '=', '9',
      '*', '0', ')', '2', '+', '4', ']', '6', '!', '8', '#', '`', 0, 
   3, ';', ':', ',', '<', '.', '>', 'P', 'Y', 'F', 'G', 'C', 'R', 'L', 
      '/', '?', '@', '^',  0,
   5, 'A', 'O', 'E', 'U', 'I', 'D', 'H', 'T', 'N', 'S', '-', '_', 
      '\\', '|', 0,
   7, '\'', '"', 'Q', 'J', 'K', 'X', 'B', 'M', 'W', 'V', 'Z', 0,
   0
};
#else
char map[] =
{
      '`', '~', '1', '!', '2', '@', '3', '#', '4', '$', '5', '%', '6', '^',
      '7', '&', '8', '*', '9', '(', '0', ')', '[', '{', ']', '}', 0, 
   3, '\'', '"', ',', '?', '.', '?', 'P', 'Y', 'F', 'G', 'C', 'R', 'L', 
      '/', '?', '=', '+',  0,
   5, 'A', 'O', 'E', 'U', 'I', 'D', 'H', 'T', 'N', 'S', '-', '_', 
      '\\', '|', 0,
   2, '<', '>', ';', ':', 'Q', 'J', 'K', 'X', 'B', 'M', 'W', 'V', 'Z', 0,
   0
};
#endif

#ifdef PROGRAMMER_DVORAK
char colormap[] =
{
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   3, -5, -5, -4, -4, -3, -3, -2, -2, 2, 2, 3, 4, 5, 
      0, 0, 0, 0,  0,
   5, -5, -4, -3, -2, -2, 2, 2, 3, 4, 5, 0, 0, 
      0, 0, 0,
   7, -5, -5, -4, -3, -2, -2, 2, 2, 3, 4, 5, 0,
   0
};
#else
char colormap[] =
{
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   3, -5, -5, -4, -4, -3, -3, -2, -2, 2, 2, 3, 4, 5, 
      0, 0, 0, 0,  0,
   5, -5, -4, -3, -2, -2, 2, 2, 3, 4, 5, 0, 0, 
      0, 0, 0,
   2, 0, 0, -5, -5, -4, -3, -2, -2, 2, 2, 3, 4, 5, 0,
   0
};
#endif

int helpInterval;
int helpLength;
time_t nextHelp;

int myGetch(char shouldBe)
{
   int deviation;
   int ch;

   ch = getch();
   
   if (ch != ERR) {
      helpInterval = 10000 + (random() % 10000);
      deviation = random() % 300;
      nextHelp = time(0) + (helpInterval + deviation) / 1000;
      helpLength = 1;
      return ch;
   }

   if (time(0) < nextHelp) {
     return ch;
   }
   
   if ((helpLength--) == 0) {
      helpInterval = random() % 1000;
      helpLength = random() % 8;
   }
   deviation = random() % 300;      
   nextHelp = time(0) + (helpInterval + deviation) / 1000;

   if ((random() % 26) == 0) {
     return KEY_BACKSPACE;
   } else {
     return shouldBe;
   }
}        


/* calculate typing speed in a given interval */
inline float calcSpeed (time_t timeStart, time_t timeFinish, int hits)
{
    return (float) hits / (timeFinish - timeStart);
}


/* Import an ASCII text to use as a lesson. Allocates memory for *buf.
   return length of read text on success, -1 on error

   tabstops are skipped, as are blanks on the beginning and end of
   lines */
int importText (char const * const fileName, char** buf, unsigned int length)
{
   FILE* file;
   int c;
   int i = 0;
   int lines = 0;
   int column;
   struct stat st;
   
   file = fopen (fileName, "r");
   if (!file) {
      postmortem = sys_errlist[errno];
      return -1;
   }
   
   fstat (fileno(file), &st);
   if (st.st_size > length) {
      length = st.st_size;
   }
#if defined(LIMIT_LENGTH) && (LIMIT_LENGTH > 0)
   if (length > LIMIT_LENGTH) {
      length = LIMIT_LENGTH;
   }
#endif   
   
   *buf = (char*) malloc (length+1+1);
   if (!*buf) {
      postmortem = "memory allocation failed";
      fclose (file);
      return -1;
   }
   
   column = 0;
   (*buf[i++]) = '\x2';
   
   while (1) {
      c = fgetc (file);
      if (errno) {
	 postmortem = sys_errlist[errno];
	 fclose (file);
	 return -1;
      }
      if (c == EOF) {
	 fclose (file);
	 (*buf)[i] = '\x1';
	 break;
      }
      
      if (index(typables, c) == NULL) {
	 continue;
      }
      
      if (c == '\n' || column > right_margin) {
	 if (column > right_margin) {
	    (*buf)[i++] = '\n';
	 }
	 
	 while (i > 0) {
	    if ((*buf)[i-1] == ' ') {
	       --i;
	    } else {
	       break;
	    }
	 }
	 column = 0;
	 ++lines;
	 
	 if (c == ' ') {
	    continue;
	 }
      }
      
      if (lines == max_editable_lines) {
	 lines = 0;
	 (*buf)[i++] = '\x1';
      } else {
	 (*buf)[i++] = (char) c;
	 ++column;
      }
      
      if (i >= length - 1) {
	 fclose (file);
	 (*buf)[i] = '\x1';
	 break;
      }
   }

   /* strip unwanted whitespace from the end */
   while (i > 0) {
      if ((*buf)[i-1] == ' ' || (*buf)[i-1] == '\n' || (*buf)[i-1] == '\x1') {
	 --i;
      } else {
	 break;
      }
   }
   
   (*buf)[i] = '\0';
   return i;
}

void boxed(int x, int y, char u, char d, char pressed, int key)
{ 
   if (pressed == PRESSED_REQUESTED) {
      attron (A_REVERSE);
   }
   if (pressed == PRESSED_BY_USER) {
      attron (A_BOLD);
   }
   if (colorSupport) {
      attron (COLOR_PAIR (7-abs(colormap[key])));
   }
   
   if (tryToBePretty) {
      move (y+0, x); addch (ACS_ULCORNER); addch (ACS_HLINE); addch (ACS_HLINE); addch (ACS_HLINE); addch (ACS_URCORNER);
      move (y+1, x); addch (ACS_VLINE); addch (u); addch (' '); addch (' '); addch (ACS_VLINE);
      move (y+2, x); addch (ACS_VLINE); addch (' '); addch (' '); addch (d); addch (ACS_VLINE);
      move (y+3, x); addch (ACS_LLCORNER); addch (ACS_HLINE); addch (ACS_HLINE); addch (ACS_HLINE); addch (ACS_LRCORNER);
   } else {
      mvprintw (y+0, x, ".---.");
      mvprintw (y+1, x, "|%c  |", u);
      mvprintw (y+2, x, "|  %c|", d); 
      mvprintw (y+3, x, "`---'");
   }
   
   if (colorSupport) {
      attron (COLOR_PAIR(7));
   }
   if (pressed == PRESSED_REQUESTED) {
      attroff (A_REVERSE);
   }
   if (pressed == PRESSED_BY_USER) {
      attroff (A_BOLD);
   }
}

void show_layout(char pressedKey, char pressed)
{
    int key = 0;
    int x = 0, y = 0;
    
    if (hideKeys) {
       return;
    }
   
    while (map[key]) {
        while (map[key]) {
            char u = map[key];
            char d;
            if (isupper(u)) {
                        /* hack, to fix the keymap i wrote erroneusly.. */
                d = u;
                u = tolower (d);
            } else {
                ++key;
                d = map[key];
            }

            if ((u == pressedKey) || (d == pressedKey)) {
	       boxed (x, y, d, u, pressed, key);
            } else {
	       if (pressed != PRESSED_REQUESTED) {
		  boxed (x, y, d, u, PRESSED_NOT, key);
	       }
            }
            
            x += 6;
            ++key;
        }
        ++key;
        y += 4;
        x = map[key];
        ++key;
    }
    refresh();
}

void myaddnstr (char const * text, int lenght)
{
   char *buf = malloc (lenght);  
   char *obuf = buf;
   int i = lenght;
   
   while (--i) {
      if (*text != '\x2') {
	 *(buf++) = *(text);
      }
      ++text;
   }

   addnstr (obuf, lenght);
   free (obuf);
}

void do_text (char * const text)
{
    int hits, misses;
    int this_page_size;

    time_t timeStart, timeFinish, timeCurrent;
    float speed;
   
    char *p = text;
    char *i;
    char *this_page_start;

    curs_set (FALSE);
    show_layout(' ', PRESSED_NOT);
    mvaddstr (LINES - 1, 0, "[ ] Press a key to start");
    
    i = (char*) index (text, 0x1);
    this_page_start = text;
    this_page_size  = i ? i - this_page_start : strlen(this_page_start);

    move ((hideKeys ? 0 : 17), 0);

    myaddnstr (text, this_page_size);  
    hits = 0; misses = 0;
    refresh();
    noecho();
    move (LINES - 1, 1);
    getch();
    
    halfdelay (LATENCY);

    move (LINES - 1, 0);
    clrtoeol();
    timeStart = 0;
    nextHelp = time(0) + (helpInterval / 1000);       
   
    while (*p) {
       int ch = 0;

       if (*p == 0x2) {
	  ++p;
	  if (!timeStart) {
	     timeStart = time(0);
	  }
       }
       
       if (*p > 27) {
	  show_layout(*p, PRESSED_REQUESTED);
       }

       do {
	  ch = myGetch (*p);
	  if (timeStart) {
	     float ratio = hits - misses;
	     ratio = (ratio < 0) ? 0 : (100.0 * ratio / hits);
	     timeCurrent = time(0);
	     speed = calcSpeed (timeStart, timeCurrent, hits);
	     mvprintw (LINES - 1, 0, "CPS %.2f  CPM %.2f Hits: %d Misses: %d Seconds: %d Ratio: %.2f%%", speed, speed * 60, hits, misses, time(0) - timeStart, ratio);
	     clrtoeol();
	  }
       } while (ch == ERR);
       
       show_layout(ch, PRESSED_BY_USER);
        
        if (ch == *p || (*p == '\n' && ch == ' ')) {
            ++p;
            ++hits;
        } else {
	    /* any other possibilities? */	   
            if ( (ch == 8 || ch == KEY_BACKSPACE || ch == KEY_DC || ch == 127)
                 && p > this_page_start) {
                --p;
	       if (*p == '\x2') {
		  --p;
	       }
            } else if (ch == 27 || ch == KEY_END) {
                break;
            } else {
                if (beepsArentIrritating) {
		   beep();
		}
		if (flashesArentIrritating) {
		   flash();
		}

                ++misses;
                if (nastiness && p > this_page_start) {
		   --hits;
                   --p;
		   if (*p == '\x2') {
		      --p;
		   } 	   
                }
            }
        }
      
	move ((hideKeys ? 0 : 17), 0);
        i = this_page_start;
        attron (A_BOLD);
        while (i < p) {
	   if (*i != 0x2) {
	      addch(*i);
	   }
	   ++i;
        }
        if (*i == '\x2') {
	   ++i;
	}
        attroff (A_BOLD);
        attron (A_REVERSE);
        if (*i != 0x2) {
 	   addch(*i);
        }
        ++i;       
        attroff (A_REVERSE);
        while (*i && i < this_page_start + this_page_size) {
	   if (*i != 0x2) {
	      addch(*i);
	   }
	   ++i;
        }
        
        if (*p == 0x1) {
	   char *next;
	   ++p;
	   next = (char*) index (p, 0x1);
	   this_page_start = p;
	   this_page_size  = next ? next - this_page_start : strlen(this_page_start);
	   move ((hideKeys ? 0 : 17), 0);
	   clrtobot();
	   myaddnstr (this_page_start, this_page_size);
        } 
    }

    timeFinish = time(0);
    speed = calcSpeed(timeStart, timeFinish, hits);
    clear();
    cbreak();
    if (!timeStart) {
       mvprintw (0, 0, "You haven't done enough to get a good benchmark.");
    } else {
       float ratio = hits - misses;
       ratio = (ratio < 0) ? 0 : (100.0 * ratio / hits);
       mvprintw (0, 0, "Elapsed time: %d seconds", timeFinish - timeStart);
       mvprintw (1, 0, "Total: %d  Misses: %d  Ratio: %.2f%%", hits, misses, ratio);
       mvprintw (2, 0, "CPS: %.2f  CPM: %.2f", speed, speed * 60);
    }
   
   mvprintw (4, 0, "[ ] Press ESCAPE to continue.");
   move (4, 1);       
   refresh();
    
   while (getch() != 27);
    
   curs_set (TRUE);
   echo();
   clear();
   refresh(); 
}

void menuInteractive()
{
    int i, num;
    char buf[255];
    
    while (1) {
        mvprintw (2, 0, "Dvorak7Min, Ragnar Hojland Espinosa, 1998-2003" );
        mvprintw (3, 0, "enhanced by Smoke of CRAP, 1999 and Nopik, 2003");
        for (i = 0; lessons[i*2]; ++i) {
            mvprintw (i/2 + 5, (i%2) * 40, "%2d. %s", i+1, lessons[i*2]);
        }
        move (21, 0); clrtobot();
        mvprintw (21, 0, "Type a lesson number ([N]astiness [H]ide keyboard [Q]uit)? ");
        refresh();
        echo();
        getnstr (buf, sizeof(buf));
        buf[0] = toupper(buf[0]);
        if (buf[0] == 'N') {
            nastiness = !nastiness;
            if (nastiness)
                mvprintw (23, 0, "Nastiness is now turned ON. Press any key.");
            else
                mvprintw (23, 0, "Nastiness is now turned OFF. Press any key.");
            getch();
            continue;
        }

        if (buf[0] == 'H') {
            hideKeys = !hideKeys;
            if (hideKeys)
                mvprintw (23, 0, "Keyboard layout is now OFF. Press any key.");
            else
                mvprintw (23, 0, "Keyboard layout is now ON. Press any key.");
            getch();
            continue;
        }
	
        if (buf[0] == 'Q' || buf[0] == 27) {
            clear();
            move (0,0);
            refresh();
            return;
        }
        num = atoi (buf);
        if (!buf[0] || num < 1 || num > i) {
            mvprintw (23, 0, "Invalid lesson number. Press any key.");
            getch();
            continue;
        }
        
        clear();
        refresh();
        do_text(lessons[(num-1)*2+1]);
    }
}


int initColors()
{
   start_color();
    
   if (!has_colors()) {
      colorSupport = 0;
      return -1;
   }
        
   init_pair( 1, COLOR_BLUE , COLOR_BLACK );
   init_pair( 2, COLOR_GREEN , COLOR_BLACK );
   init_pair( 3, COLOR_CYAN , COLOR_BLACK );
   init_pair( 4, COLOR_RED , COLOR_BLACK );
   init_pair( 5, COLOR_MAGENTA , COLOR_BLACK );
   init_pair( 6, COLOR_YELLOW , COLOR_BLACK );
   init_pair( 7, COLOR_WHITE , COLOR_BLACK );

   return 0;
}


void initApp()
{
   initscr();

   right_margin = COLS - 10;
   max_editable_lines = LINES - 18 - 1;
   helpInterval = 10000 + (random() % 10000);
   helpLength = 1;

   if (colorSupport) {
     initColors();
   }
}


  

void closeApp()
{
    move (0, 0);
    clear();
    refresh();
    endwin();
}

int playFile(char *filename)
{
   char *buffer;
   int r;
   int len = 0;
   
#ifdef LIMIT_LENGTH
   len = LIMIT_LENGTH;
#endif   
   
   r = importText (filename, &buffer, len);
   if (r <= 0) {
      return -1;
   }

   do_text (buffer);
   return 0;
}

void showHelp()
{
   printf("Usage: dvorak7min [OPTION]... [FILE]...\n\n"
	  "  -b, --bell                   beep on error\n"
          "  -f, --flash                  flash the screen on error\n"
	  "  -u, --ugly                   use low ascii for artwork\n"
	  "  -n, --nastiness              set nastiness on by default\n"
	  "  -k, --hidekeys               hides keyboard layout\n"
	  "      --help                   display this help and exit\n"
	  "      --version                output version information and exit\n"
	  "\n");
}

void showVersionInfo()
{
    printf ("dvorak 7min tutor hack 1.6 - FREE Software with NO Warranty\n"
            "(C) 1998-2001 Ragnar Hojland Espinosa <ragnar@ragnar-hojland.com>\n"
            "Lessons are (C) 1995 Dan Wood <danwood@karelia.com>\n"
            "Enhancements in 1999 by Smoke of Crap aka Tijs van Bakel <smoke@casema.net>\n"
						"and in 2003 by Nopik aka Kamil Burzynski <K.Burzynski@adbglobal.com>\n"
	    "\n");
}
    
int main ( int argc, char *argv[] )
{
   struct option long_opts[] = {
	 { "help",      0, 0, 'H' },
	 { "version",   0, 0, 'V' },
	 { "nastiness", 0, 0, 'n' },
	 { "bell",      0, 0, 'b' },
	 { "flash",     0, 0, 'f' },
	 { "ugly",      0, 0, 'u' },
         { "hidekeys",  0, 0, 'k' },
	 { 0, 0, 0, 0 }
   };
   
   int opt_index = 0;
   int c;
   
   while (1) {
      c = getopt_long(argc, argv, "HVnbfuk", long_opts, &opt_index);
      if (c == -1) {
	 break;
      }
      
      switch (c) {
       case 'H':
	 showHelp();
	 return 1;
       case 'V':
	 showVersionInfo();
	 return 1;
       case 'b':
	 beepsArentIrritating = 1;
	 break;
       case 'f':
	 flashesArentIrritating = 1;
	 break;
       case 'n':
	 nastiness = 1;
	 break;
       case 'u':
	 tryToBePretty = 0;
	 break;
       case 'k':
	 hideKeys = 1;
	 break;
      }
   }
   
   initApp();

   if (optind < argc) {
      while (optind < argc) {
	 if (playFile(argv[optind]) < 0) {
	    closeApp();
	    printf ("%s: %s: %s\n", argv[0], argv[optind], postmortem);
	    return 1;
	 }
	 ++optind;
      }
   } else {
      menuInteractive();
   }
   
   closeApp();
   showVersionInfo();
    
   return 0;
}
