#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "config.h"
#include "generateXml.h"
#include "library.h"

int main(void) {
    
    //createConfig();
    //createParent("test");
    char * dir = "./xml/";
    char * path;
    DIR * rep = opendir(dir);
    FILE * pf = fopen("test.xml", "a");
    
    if (rep != NULL)
    {
        struct dirent * ent;
        
        while ((ent = readdir(rep)) != NULL)
        {
            if(strcmp(ent->d_name, ".") && strcmp(ent->d_name, "..")) {
                path = malloc(strlen(dir) + strlen(ent->d_name));
                strcat(strcat(path, dir), ent->d_name);
                fprintf(pf, "%s", init(path));
                fprintf(pf, "%s", "\n");
                free(path);
            }
        }
        fclose(pf);
        closedir(rep);
    }
    
    return 0;
}

