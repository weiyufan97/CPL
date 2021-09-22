#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int main(int argc, char* argv[]) {
    // read each line from two files
    // compare and terminate when two lines differ
    if (argc != 3)
        fprintf(stderr, "Usage: file1 file2");
    char* prog = argv[0];
    
    FILE* fp1, *fp2;
    char line1[MAXLINE], line2[MAXLINE];

    if ((fp1 = fopen(argv[1], "r")) == NULL)
        fprintf(stderr, "%s can't open %s\n", prog, argv[1]);
    
    if ((fp2 = fopen(argv[2], "r")) == NULL)
        fprintf(stderr, "%s can't open %s\n", prog, argv[2]);
    
    while (fgets(line1, MAXLINE, fp1) != NULL &&
           fgets(line2, MAXLINE, fp2) != NULL) {
               if (strcmp(line1, line2)) {
                   printf("First occurance:\nfile1: %s\nfile2: %s\n", line1, line2);
                    break;
               }
           }
    
    return 0;
}