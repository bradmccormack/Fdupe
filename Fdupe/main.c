/*
 *  utilities.h
 *  Fdupe
 *
 *  Created by Brad Mccormack on 21/04/12.
 *  
 *
 */

#include <stdio.h>
#include "utilities.h"
#include "opencl.h"


int main (int argc, const char **argv) {
  
  NODEDATA fileinfo;
  QUEUE* files= malloc(sizeof(QUEUE));
  initialize(files);
  
  if(argc==2)
  {
    listdir( (char*) argv[1], files);
    if(files != NULL)
    {
      printf("Files at %s\n",argv[1]);
      while(!empty(files))
      {
		fileinfo = dequeue(files);
		if(fileinfo != NULL)
		{
	  	printf("%s\n",(char*) fileinfo);
		}
      }
    }
  }
  else 
  {
    printf("Syntax: fdupe path\n");
  }
  free(files);
  
  /* Test setting up and freeing of OpenCL related memory/devices */
  OpenCLInit();
  OpenCLFree();
  
  return 0;
}
