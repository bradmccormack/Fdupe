/*
 *  utilities.h
 *  Fdupe
 *
 *  Created by Brad Mccormack on 21/04/12.
 *  
 *
 */
#ifdef LINUX
#include "linux/stat.h"
#endif

#ifdef WINDOWS
/* Include dirent compatible implementation */
#endif


#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <assert.h>
#include "dirent.h"

typedef enum {false,true} boolean;

typedef  void* NODEDATA;

struct queuenode{
  NODEDATA data;
  struct queuenode *next;
};

typedef struct queuenode NODE;
typedef struct queuenode* NODELINK;

struct queue{
  int length;
  NODELINK FRONT;
  NODELINK BACK;
};

typedef struct queue QUEUE;

/*
 * The storage mechanism for the MD5 sums will be a hashset of linked lists where the key is the md5 sum and the value is a list of all files matching that sum
 *
 */

/* Will return a list of files in direcory specified by path (recursive) */
void listdir(char* path, QUEUE* files);

/* FIFO Queue related functions */
boolean empty(QUEUE* queue);
void initialize(QUEUE* queue);
void enqueue(QUEUE* queue,NODEDATA* data);
NODEDATA dequeue(QUEUE* queue);

