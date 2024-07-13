#include <stdio.h>
#define STREAM_LENGHT 256
int
readFile (char *path)
{
    FILE *file = fopen (path, "r");
    if (file == NULL)
        {
            fprintf (stderr, "cant open file %s", path);
        }
    while (1)
        {
            if (feof (file))
                break;

            char nxt[2] = { getc (file), getc (file) };
            printf("next = %s", nxt);
            // char nxt[2] = {'v' ,' '} != "v ";
            if (nxt == "v ")
                {
                    float rt[3];
                    fscanf (file, "%f %f %f\n", &rt[0], &rt[1], &rt[2]);
                }
            else if (nxt == "f ")
                {
                    float rt[3];
                    printf ("face:");

                    while (fscanf (file, "%f/%f/%f ", &rt[0], &rt[1], &rt[2])
                           == 3)
                        {
                            printf ("%fe%fe%f");
                        }
                    printf ("\n");
                }
            else
                {
                    ungetc (nxt[1], file);
                    ungetc (nxt[0], file);
                }
        }
}
