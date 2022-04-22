#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node /* linked list structure */ {
    char *data;
    struct node *pLast, *pNext;
} NODE;

int main(int argc, char *argv[]) {
    FILE *inputFile;
    FILE *outputFile;
    char inputFileName[256];
    char outputFileName[256];
    size_t len = 0;
    char *line = NULL;
    char *pString;
    NODE *pStart = NULL, *pEnd, *pNew, *ptr;

    switch(argc) {
        case 1: /* 1 argument */
            while (getline(&line, &len, stdin) != -1) {
                if ((pNew = (NODE*)malloc(sizeof(NODE))) == NULL) /* linked list node */ {
                    fprintf(stderr, "malloc failed");
                    exit(1);
                }

                if ((pString = (char*)malloc(len)) == NULL) /* node dynamic data */ {
                    fprintf(stderr, "malloc failed");
                    exit(1);
                }

                // in the next section: 
                // 1. line is put to the node
                // 2. linked list order is updated
                strcpy(pString, line);
                pNew->data = pString;
                pNew->pNext = NULL;
                pNew->pLast = NULL;

                if (pStart == NULL) {
                    pStart = pNew;
                    pEnd = pStart;
                } else {
                    ptr = pStart;
                    while (ptr->pNext != NULL) {
                        ptr = ptr->pNext;
                    }
                    ptr->pNext = pNew;
                    pNew->pLast = ptr;
                    pEnd = pNew;
                }            
            }

            // printing all lines from the linked list in reverse order
            ptr = pEnd;
            while (ptr != NULL) {
                printf("%s", ptr->data);
                ptr = ptr->pLast;
            }

            break;
        case 2: /* 2 arguments */
            strcpy(inputFileName, argv[1]);

            if ((inputFile = fopen(inputFileName, "r")) == NULL) /* input file */ {
                fprintf(stderr, "error: cannot open file '%s'\n", inputFileName);
                exit(1);
            }

            while (getline(&line, &len, inputFile) != -1) {
                if ((pNew = (NODE*)malloc(sizeof(NODE))) == NULL) /* linked list node */ {
                    fprintf(stderr, "malloc failed");
                    exit(1);
                }

                if ((pString = (char*)malloc(len)) == NULL) /* node dynamic data */ {
                    fprintf(stderr, "malloc failed");
                    exit(1);
                }


                // in the next section: 
                // 1. line is put to the node
                // 2. linked list order is updated
                strcpy(pString, line);
                pNew->data = pString;
                pNew->pNext = NULL;
                pNew->pLast = NULL;

                if (pStart == NULL) {
                    pStart = pNew;
                    pEnd = pStart;
                } else {
                    ptr = pStart;
                    while (ptr->pNext != NULL) {
                        ptr = ptr->pNext;
                    }
                    ptr->pNext = pNew;
                    pNew->pLast = ptr;
                    pEnd = pNew;
                }
            }

            // printing all lines from the linked list in reverse order
            ptr = pEnd;
            while (ptr != NULL) {
                printf("%s", ptr->data);
                ptr = ptr->pLast;
            }
            fclose(inputFile);
            break;
        case 3: /* 3 arguments */
            if (strcmp(argv[1], argv[2]) == 0) {
                fprintf(stderr, "Input and output file must differ\n");
                exit(1);
            }

            strcpy(inputFileName, argv[1]);

            if((inputFile = fopen(inputFileName, "r")) == NULL) /* input file */ {
                fprintf(stderr, "error: cannot open file '%s'\n", inputFileName);
                exit(1);
            }

            while (getline(&line, &len, inputFile) != -1) {
                if ((pNew = (NODE*)malloc(sizeof(NODE))) == NULL) /* linked list node */ {
                    fprintf(stderr, "malloc failed");
                    exit(1);
                }

                if ((pString = (char*)malloc(len)) == NULL) /* node dynamic data */ {
                    fprintf(stderr, "malloc failed");
                    exit(1);
                }

                // in the next section: 
                // 1. line is put to the node
                // 2. linked list order is updated
                strcpy(pString, line);
                pNew->data = pString;
                pNew->pNext = NULL;
                pNew->pLast = NULL;

                if (pStart == NULL) {
                    pStart = pNew;
                    pEnd = pStart;
                } else {
                    ptr = pStart;
                    while (ptr->pNext != NULL) {
                        ptr = ptr->pNext;
                    }
                    ptr->pNext = pNew;
                    pNew->pLast = ptr;
                    pEnd = pNew;
                }
            }

            ptr = pEnd;
            strcpy(outputFileName, argv[2]);
            if((outputFile = fopen(outputFileName, "w")) == NULL) /* output file */ {
                fprintf(stderr, "error: cannot open file '%s'\n", outputFileName);
                exit(1);
            }

            // outputting all lines from the linked list in reverse order to the file
            while (ptr != NULL) {
                fprintf(outputFile, "%s", ptr->data);
                ptr = ptr->pLast;
            }

            fclose(inputFile);
            fclose(outputFile);
            break;
        default:
            printf("usage: reverse <input> <output>\n");
            return 1;
    }

    return 0;
}
