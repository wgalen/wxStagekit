/*
 * This code (stagekit.h & stagekit.c) is intended to allow control over
 * the Rock Band Stage Kit made by PDP. I intended this header to be
 * fairly self-documenting to assist anyone that may wish to impliment
 * support for the device in another API/OS. To get started, #include this
 * file in your program, call sk_init(filename), where filename is the event
 * file matching the stagekit (such as /dev/input/event5), then call the
 * various sk_* macros such as sk_faststrobe(); or sk_setred(0xFF);
 */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * You can contact the author by email at this address:
 * Wayne M. Galen <wayne.galen@gmail.com>
 */

#ifndef STAGEKIT_H_INCLUDED
#define STAGEKIT_H_INCLUDED
#include <unistd.h>

#define STAGEKIT_ALLOFF 0xFFFF
#define STAGEKIT_NO_STROBE 0x700
#define STAGEKIT_SLOW_STROBE 0x300
#define STAGEKIT_MEDIUM_STROBE 0x400
#define STAGEKIT_FAST_STROBE 0x500
#define STAGEKIT_FASTEST_STROBE 0x600
#define STAGEKIT_FOG_ON 0x100
#define STAGEKIT_FOG_OFF 0x200
#define STAGEKIT_RED 0x8000
#define STAGEKIT_YELLOW 0x6000
#define STAGEKIT_GREEN 0x4000
#define STAGEKIT_BLUE 0x2000

extern int sk_init(char *filename);
extern int send_raw_value(unsigned short left, unsigned short right);
extern void sk_close(void);

#define sk_alloff() send_raw_value(0,STAGEKIT_ALLOFF);usleep(10000);send_raw_value(0,STAGEKIT_ALLOFF)   //sending this twice ensures the command is recieved. in testing, it would sometimes get stuck with only one off call. no clue why
#define sk_nostrobe() send_raw_value(0,STAGEKIT_NO_STROBE);usleep(10000)
#define sk_slowstrobe() send_raw_value(0,STAGEKIT_SLOW_STROBE);usleep(10000)
#define sk_medstrobe() send_raw_value(0,STAGEKIT_MEDIUM_STROBE);usleep(10000)
#define sk_faststrobe() send_raw_value(0,STAGEKIT_FAST_STROBE);usleep(10000)
#define sk_fasteststrobe() send_raw_value(0,STAGEKIT_FAST_STROBE);usleep(10000)
#define sk_fogon() send_raw_value(0,STAGEKIT_FOG_ON);usleep(10000)
#define sk_fogoff() send_raw_value(0,STAGEKIT_FOG_OFF);usleep(10000)
#define sk_setred(i) send_raw_value(i<<8,STAGEKIT_RED);usleep(10000)
#define sk_setyellow(i) send_raw_value(i<<8,STAGEKIT_YELLOW);usleep(10000)
#define sk_setgreen(i) send_raw_value(i<<8,STAGEKIT_GREEN);usleep(10000)
#define sk_setblue(i) send_raw_value(i<<8,STAGEKIT_BLUE);usleep(10000)
#define sk_setleds(r,y,g,b) send_raw_value(r<<8,STAGEKIT_RED);usleep(10000);send_raw_value(y<<8,STAGEKIT_YELLOW);usleep(10000);send_raw_value(g<<8,STAGEKIT_GREEN);usleep(10000);send_raw_value(b<<8,STAGEKIT_BLUE);usleep(10000)

#endif // STAGEKIT_H_INCLUDED
