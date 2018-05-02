//
//  library.c
//  FusionXml
//
//  Created by Pierre Kettmus on 02/05/2018.
//  Copyright © 2018 Pierre Kettmus. All rights reserved.
//

#include "library.h"
#include <stdlib.h>
#include <string.h>
int fileSize(FILE *pf) {
    int size = 0;
    
    fseek(pf, 0, SEEK_END);
    size = (int)ftell(pf);
    fseek(pf, 0, SEEK_SET);
    
    return size;
}

char * init(char * file) {
    FILE * pf = fopen(file, "r");
    int size = fileSize(pf);
    char * tmp = malloc(size);
    char * toReturn = malloc(1);
    int takeLine = 0;
    
    while(fgets(tmp, size, pf) != NULL) {
        if ((strstr(tmp, "information") != NULL )) {
            if (!takeLine)
                takeLine = 1;
            else
                takeLine = 0;
        }
        
        if (takeLine || strstr(tmp, "information") != NULL) {
            toReturn = realloc(toReturn, strlen(tmp) + strlen(toReturn));
            strcat(toReturn, tmp);
        }
    }
    free(tmp);
    fclose(pf);
    
    return toReturn;
}




