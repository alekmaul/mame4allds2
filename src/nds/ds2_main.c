//ds2_main.c

#include <stdio.h>
#include "console.h"
#include "fs_api.h"
#include "ds2io.h"

extern void main(int argc, char* argv[]);

void ds2_main(void)
{
	int err;

	//Initial video and audio and other input and output
	err = ds2io_initb(512,22050,0,0);
	if(err) goto _failure;

	//Initial file system
	err = fat_init();
	if(err) goto _failure;

	//go to user main funtion
	main(0, 0);

_failure:
	ds2_plug_exit();
}

