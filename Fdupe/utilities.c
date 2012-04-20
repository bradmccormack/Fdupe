/*
 *  utilities.c
 *  Fdupe
 *
 *  Created by Sarina Mccormack on 21/04/12.
 *  Copyright 2012 NerdonCoffee. All rights reserved.
 *
 */

#include "utilities.h"


LINK listdir( char* path ) {
    //Recursively walks through a path
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
                printf( "%s\n", apath );
            
            if( stat( apath, &attribut ) == -1 )
                printf( "stat(%s) failed\n", apath );
            else if( ( attribut.st_mode & S_IFDIR ) && strstr( apath, "." ) == NULL )
                listdir( apath );
        }
    }
    else
        printf("opendir(%s) failed\n", path);
    
    closedir( dir );
	
	
	//Delete me just so the compiler can pass for now
	LINK temp=malloc(sizeof(NODE));
	return temp;
	
}