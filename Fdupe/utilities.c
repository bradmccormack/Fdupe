/*
 *  utilities.c
 *  Fdupe
 *
 *  Created by Brad Mccormack on 21/04/12.
 * 
 *
 */

#define LINUX

#include "utilities.h"

#ifdef LINUX
#include "linux/stat.h"
#endif

#ifdef WINDOWS
/* Include dirent compatible implementation */
#endif


void initialize(QUEUE* queue)
{
  queue -> FRONT = queue -> BACK = NULL;
  queue -> length =0;	
}

void enqueue(QUEUE* queue,NODEDATA* data)
{
  NODELINK addtoqueue;
  
  assert(queue != NULL);
  
  addtoqueue = malloc(sizeof(NODE));
  addtoqueue->next = NULL;
  addtoqueue->data = data;
  
  if(!empty(queue))
  {
    queue -> BACK -> next = addtoqueue;
    queue -> BACK = addtoqueue;
  }
  else
  {
    queue -> FRONT = queue -> BACK = addtoqueue;
  }
  queue -> length++;
}


NODEDATA dequeue(QUEUE* queue)
{
  NODEDATA result= queue -> FRONT -> data;
  NODELINK fn = queue -> FRONT;
  
  queue -> FRONT = fn -> next;
  queue -> length--;
  
  free(fn->data); 
  free(fn);
  
  return result;
}

boolean empty(QUEUE* queue)
{
  return ( (boolean) (queue -> length == 0));
}

void listdir( char* path, QUEUE* files) 
{
  char apath[1024];
  DIR *dir;
  struct dirent *entry;
  struct stat attribut;
  
  if( ( dir = opendir( path ) ) != NULL ) {
    
    while( ( entry = readdir( dir ) ) != NULL ) {
      
      memset( apath, '\0', sizeof( apath ) );
      strcpy( apath, path );
      strcat( apath, "/" );
      strcat( apath, (char*)entry->d_name );
      
      if( strcmp( (char*)entry->d_name, "." ) != 0 && strcmp( (char*)entry->d_name, ".." ) != 0 ) 
      {
	NODEDATA* data= malloc(strlen(apath));
	strcpy( (char*) data , apath);
	enqueue(files,data);
      }
      
      if( stat( apath, &attribut ) == -1 )
      {
	fprintf(stderr,"stat(%s) failed\n", apath );
      }
      else if( ( attribut.st_mode & S_IFDIR ) && strstr( apath, "." ) == NULL )
      {
	listdir(apath, files);
      }
    }
  }
  else
  {
    fprintf(stderr,"Directory(%s) open failed.\n", path);
    closedir(dir);
    return;
  }
  
}