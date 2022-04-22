#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
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
        case 1:
            while (getline(&line, &len, stdin) != -1) {
                if ((pNew = (NODE*)malloc(sizeof(NODE))) == NULL) {
                    perror("malloc failed");
                    exit(1);
                }

                if ((pString = (char*)malloc(len)) == NULL) {
                    perror("malloc failed");
                    exit(1);
                }

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
            while (ptr != NULL) {
                printf("%s", ptr->data);
                ptr = ptr->pLast;
            }

            break;
        case 2:
            strcpy(inputFileName, argv[1]);
            inputFile = fopen(inputFileName, "r");
            while (getline(&line, &len, inputFile) != -1) {
                if ((pNew = (NODE*)malloc(sizeof(NODE))) == NULL) {
                    perror("malloc failed");
                    exit(1);
                }

                if ((pString = (char*)malloc(len)) == NULL) {
                    perror("malloc failed");
                    exit(1);
                }

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
            while (ptr != NULL) {
                printf("%s", ptr->data);
                ptr = ptr->pLast;
            }
            fclose(inputFile);
            break;
        case 3:
            strcpy(inputFileName, argv[1]);
            inputFile = fopen(inputFileName, "r");
            while (getline(&line, &len, inputFile) != -1) {
                if ((pNew = (NODE*)malloc(sizeof(NODE))) == NULL) {
                    perror("malloc failed");
                    exit(1);
                }

                if ((pString = (char*)malloc(len)) == NULL) {
                    perror("malloc failed");
                    exit(1);
                }

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
            outputFile = fopen(outputFileName, "w");

            while (ptr != NULL) {
                fprintf(outputFile, "%s", ptr->data);
                ptr = ptr->pLast;
            }

            fclose(inputFile);
            fclose(outputFile);
            break;
        default:
            printf("case default.\n");
    }

    return 0;
}
