// #include "window.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int
main (int argc, char const *argv[])
{
    if (argc < 1)
        {
            fprintf (stderr, "n tem arquivo nenhum boiola\n");
            return -1;
        }
    // FILE *file = fopen (argv[1], "r");
    // if (file == NULL)
    //     {
    //         fprintf (stderr, "nao consegui abri\n");
    //         return -1;
    //     }
    readFile(argv[1]);
    // float v1, v2, v3;
    // while (fscanf (file, "v %f %f %f\n", &v1, &v2, &v3) == 3 ) 
    //     {
    //         printf ("%f %f %f\n", v1, v2, v3);
    //     }
    // int i[3];
    // while(fscanf (file, "v %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d", &i[0], &i[1], &i[2], &i[3]) == 4 ){
    //     printf("%d %d %d", i[0], i[2], i[3], i[4]);
    // }
    return 0;
}
