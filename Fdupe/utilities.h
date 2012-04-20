/*
 *  utilities.h
 *  Fdupe
 *
 *  Created by Brad Mccormack on 21/04/12.
 *  
 *
 */

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "dirent.h"

/*
 struct invoice{
 2	        char* code;
 3	        char date[20];
 4	    };
 */

typedef  char* NODEDATA;

typedef struct {
	NODEDATA data;
	struct list *next;
} NODE; 

typedef NODE *LINK;


// Will return a list of files in direcory specified by path (recursive)
LINK listdir( char* path );




