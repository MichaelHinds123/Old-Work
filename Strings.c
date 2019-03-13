#include<stdio.h>
#include<stdlib.h>

// String manipulation, merging, and memory allocation

int length(char *);
char* copy(char *);
char* reverse(char *);
void clear(char *);
char* merge(char *, char *);
int prefix(char *, char *);

int main(int argc, char*s[])
{
    if(argc < 2)                                                                    // Error check for the correct amount of arguments
    {
        fprintf(stderr, "not enough parameters\n");
        exit(1);
    }

    int prefixes;
    int len = length(*(s+1));                                                       // Find the length of the argument
    char *mergeString = malloc(sizeof(char) *len);                                  //
    char *prefixString1 = malloc(sizeof(char) *len);                                // Allocate memory for string merging
    char *finalmerge = malloc(sizeof(char) *100);                                   //
    char *prefixString2 = malloc(sizeof(char) *len);                                //    

    printf("\nInput string is %s", *(s+1));
    printf("\nLength of the string is %d", len);
    printf("\nCopy of the string is %s", copy(*(s+1)));
    printf("\nReverse of the string %s is %s\n", *(s+1), reverse(*(s+1)));          // Take the input string and print it in reverse
    printf("\nEnter a string for the merge operation: \n");
    scanf("%s", mergeString);
    finalmerge = merge(*(s+1), mergeString);                                        // Operation to take user input and merge with previous string
    printf("\nMerged string is %s\n", finalmerge);                                  // Print the final merged string
    printf("\nEnter a string for the prefix operation: \n");
    scanf("%s", prefixString1);
    printf("\nEnter a string to check for prefix: \n");
    scanf("%s", prefixString2);

    prefixes = prefix(prefixString1, prefixString2);                                // Determine whether a string is a prefix or not

    if(prefixes == 1)
    {
        printf("%s is a prefix of the string %s\n", prefixString2, prefixString1);  
    }
    else if(prefixes == 0)
    {
        printf("%s is not a prefix of the string %s\n", prefixString2, prefixString1);
    }

    clear(mergeString);               //
    clear(prefixString1);             //  Free allocated memory
    clear(prefixString2);             //

    return 0;
}

int length(char *s)
{
    int i = 0;

    while(*(s+i) != '\0')
    {
        i++;
    }
    return i;
}

void clear(char *s)
{
    free(s);
}

char* copy(char *s)
{
    int len = length(s)+1;
    char *n = malloc(sizeof(char) * len);
    int i = 0;

    while(*(s+i) != '\0')
    {
        *(n+i) = *(s+i);
        i++;
    }
    return(char *)n;
}

char* reverse(char *s)
{
    int len = length(s);
    int i = 0;
    char *n = malloc(sizeof(char) * len);

    for(i = 0; i < len; i++)
    {
        *(n+(len - 1 - i)) = *(s+i);
    }
    *(n + len) = '\0';
    return n;
}

char *merge(char *s, char *s1)
{
    int i = 0, j = 0;

    while(*(s+i) != '\0')
    {
        i++;
    }

    while(*(s1+j) != '\0')
    {
        *(s+i) = *(s1+j);
        j++;
        i++;
    }
    *(s+i) = '\0';
    return (char *)s+i;
}

int prefix(char *s, char *s2)
{
    int len = length(s2);
    int i = 0;

    if(length(s) < len)
    {
        return 0;
    }

    for(i = 0; i < len; i++)
    {
        if(*(s+i) != *(s2+i))
        {
            return 0;
        }
    }
    return 1;
}
