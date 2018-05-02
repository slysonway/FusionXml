//
//  generateXml.c
//  FusionXml
//
//  Created by Pierre Kettmus on 25/04/2018.
//  Copyright © 2018 Pierre Kettmus. All rights reserved.
//

#include <stdlib.h>
#include <string.h>

#include "generateXml.h"
char * createParent(char * parentName){
    char * toReturn;
    char * tmp;
    char * header = "<%s>\n";
    char * footer = "</%s>\n";
    int alloc = 0;
    
    tmp = malloc(strlen(parentName) + strlen(header));
    
    alloc += sprintf(tmp, header, parentName);
    
    toReturn = malloc(alloc);
    
    strcat(toReturn, tmp);
    
    tmp = realloc(tmp, strlen(parentName) + strlen(footer));
    
    alloc += sprintf(tmp, footer, parentName);
    
    toReturn = realloc(toReturn, alloc);

    strcat(toReturn, tmp);
    
    free(tmp);
    
    return toReturn;
}
