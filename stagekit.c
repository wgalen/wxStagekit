
/*
 *
 * This code is modified version of the fftest.c program
 * which Tests the force feedback driver by Johan Deneux.
 * Modifications to incorporate into Word War vi
 * by Stephen M.Cameron
 *
 * Additional modifications to create a support library for the Rock Band Stage Kit from PDP
 * by Wayne M. Galen
 *
 * Copyright 2001-2002 Johann Deneux <deneux@ifrance.com>
 * Copyright 2008 Stephen M. Cameron <smcameron@yahoo.com>
 * Copyright 2010 Wayne M. Galen <wayne.galen@gmail.com>
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
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <dirent.h>
#include "stagekit.h"

#ifdef __linux__
#define HAS_LINUX_JOYSTICK_INTERFACE 1
#endif

#ifdef HAS_LINUX_JOYSTICK_INTERFACE
#include <linux/input.h>
#endif

#define BITS_PER_LONG (sizeof(long) * 8)
#define OFF(x)  ((x)%BITS_PER_LONG)
#define BIT(x)  (1UL<<OFF(x))
#define LONG(x) ((x)/BITS_PER_LONG)
#define test_bit(bit, array)    ((array[LONG(bit)] >> OFF(bit)) & 1)



#ifdef HAS_LINUX_JOYSTICK_INTERFACE


static int event_fd;
static char *default_event_file = "/dev/input/event6";
static unsigned long features[4];
static struct ff_effect effect;


#endif /* HAS_LINUX_JOYSTICK_INTERFACE */

int send_raw_value(unsigned short left, unsigned short right)
{
#ifdef HAS_LINUX_JOYSTICK_INTERFACE
    struct input_event play;
    /* download the effect */
    effect.u.rumble.strong_magnitude = left;
    effect.u.rumble.weak_magnitude = right;

	if (ioctl(event_fd, EVIOCSFF, &effect) == -1) {
		printf("failed to upload effect: %s\n", strerror(errno));
		;
	}
    play.type=EV_FF;
    play.code=effect.id;
    play.value=1;

    if (write(event_fd,(const void*) &play, sizeof(play)) == -1)
        return -1;
#endif
    return 0;
}

void sk_close(void)
{
#ifdef HAS_LINUX_JOYSTICK_INTERFACE
	close(event_fd);
#endif
}

int sk_init(char *filename)
{
#ifdef HAS_LINUX_JOYSTICK_INTERFACE
	if (filename == NULL)
	{
	    struct dirent *dp;
	    const char *dir_path="/dev/input";
	    DIR *dir = opendir(dir_path);
	    printf("No event interface file passed. Probing for stagekit.\n");
	    struct input_id device_info;
	    while((dp=readdir(dir))!=NULL)
	    {
	        if (strspn(dp->d_name,"event"))
	        {
	            char tryfile[256]="";
                //printf("%i. %s\n", i, dp->d_name);
                strcpy(tryfile, dir_path);
                strcat(tryfile,"/");
                strcat(tryfile,dp->d_name);
                printf("Looking for stage kit on %s\n",tryfile);
                event_fd=open(tryfile, O_RDWR);
                if (event_fd < 0) {
                    fprintf(stderr, "Can't open %s: %s\n",
                    tryfile, strerror(errno));
                }
                else
                {
                    ioctl(event_fd, EVIOCGID, &device_info);
                    //printf("vendor %04hx product %04hx version %04hx", device_info.vendor, device_info.product, device_info.version);
                    if ((device_info.vendor == 0x0e6f) && (device_info.product == 0x0103))
                    {
                        printf("Stage kit found on %s\n",tryfile);
                        break;
                    }
                    else
                    {
                        close(event_fd);
                    }
                }
	        }
	    }
	}
	else
	{

		filename = default_event_file;

        event_fd = open(filename, O_RDWR);
        if (event_fd < 0) {
            fprintf(stderr, "Can't open %s: %s\n",
                filename, strerror(errno));
            return -1;
        }

        printf("Device %s opened\n", filename);
	}
	/* Query device */
	if (ioctl(event_fd, EVIOCGBIT(EV_FF, sizeof(unsigned long) * 4), features) == -1) {
		fprintf(stderr, "Query of rumble device failed: %s:%s\n",
			filename, strerror(errno));
		return -1;
	}

	/* download a lights out effect */
	effect.type = FF_RUMBLE;
	effect.id = -1;
	effect.direction = 0;
	effect.trigger.button = 0;
	effect.trigger.interval = 0;
	if (ioctl(event_fd, EVIOCSFF, &effect) == -1) {
		fprintf(stdout, "%s: failed to allocate effect: %s\n",
				filename, strerror(errno));
	}
	//sk_alloff();
	return 0;
#else
	return -1;
#endif
}
