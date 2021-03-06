/* EXERCISE 3-3  */
/* WRITE A FUNCTION expand(s1,s2) THAT EXPANDS SHORTHAND NOTATIONS  */
/* LIKE a-z IN THE STRING s1 INTO THE EQUIVALENT COMPLETE LIST      */
/* abc...xyz IN s2.  ALLOW FOR LETTERS OF EITHER CASE AND DIGITS,   */
/* AND BE PREPARED TO HANDLE CASES LIKE a-b-c AND a-z0-9 AND -a-z.  */
/* ARRANGE THAT A LEADING OR TRAILING - IS TAKEN LITERALLY.         */

/* RULES:                                                           */
/* EXPAND A RANGE THAT IS EITHER INCREASING OR DECREASING.          */
/* DO NOT EXPAND A ONE-CHAR STRING, SUCH AS b-b, B-B, or 8-8.       */

#include <stdio.h>
#define MAXLEN  41    /* A SMALL NUMBER FOR TESTING  */

int Getline(char s[]);
void expand(char s2[], char s1[]);
int typchar(char c);
int fillin(char s[], int j, char beg, char end);

#define UPPER       1
#define LOWER       2
#define DIGIT       3
#define WHITESPACE  4
#define OTHER       5

int error;

enum boolean {NO, YES};
enum escapes {BELL = '\a', BACKSPACE = '\b', TAB = '\t',
              NEWLINE = '\n', VTAB = '\v', RETURN = '\r'};

main()
{
    int i, len;
    char str_1[MAXLEN], str_2[10 * MAXLEN];

    error = NO;

/* LOAD THE STRING FROM THE INPUT LINE  */
    len = Getline(str_1);

    if (len == 0)
        printf("STRING IS MISSING\n");
    else {
        printf("\nTHE CONVERTED STRING:\n");
        expand(str_2, str_1);
        for (i = 1; str_2[i] != '\0'; i++) {
            putchar(str_2[i]);
            if (i % 50 == 0)
                putchar('\n');
        }
        if ((i - 1) % 50 != 0)     /* PRINT THE LAST NEWLINE CHAR, IF NEC */
            putchar('\n');
    }
    printf("\nEND OF PROGRAM\n");
    return 0;
}

/* GETLINE: LOAD A LINE OF INPUT  */
int Getline(char s[])
{
    int i, c;

    s[0] = ' ';       /* LOAD SPACE TO ELEMENT ZERO */

    for (i = 1; i < MAXLEN - 1 && (c = getchar()) != NEWLINE && c != EOF; ++i)
         s[i] = c;

    if (i >= MAXLEN - 1)
        printf("\nSTRING IS TOO LONG - OVER %d CHARACTERS\n", i - 1);

    if (c == NEWLINE)
        s[i++] = c;

    s[i] = '\0';
    return i;
}

/* EXPAND: EXPAND SHORTHAND NOTATIONS  */
void expand(char s2[], char s1[])
{
    int i, j, typ;

    for (i = j = 0; s1[i] != '\0'; )
        if (s1[i] == '-') {
            if ((typ = typchar(s1[i - 1])) == WHITESPACE || typ == OTHER
              || typ != typchar(s1[i + 1]))
                s2[j++] = s1[i++];
            else
            if (s1[i - 1] == s1[i + 1]) {   /* DO NOT EXPAND A ONE-CHAR RANGE */
                s2[j++] = s1[i++];
                s2[j++] = s1[i++];
            }
            else {
                j = fillin(s2, j, s1[i - 1], s1[i + 1]);  /* FILL IN STRING */
                i += 2;                       /* SKIP THE END-OF-RANGE CHAR */
            }
        }
        else
            s2[j++] = s1[i++];

    s2[j] = '\0';
}

/* TYPCHAR: DETERMINE IF CHAR IS UPPER, LOWER, DIGIT, WHITESPACE, OR OTHER  */
int typchar(char c)
{
    if (c >='A' && c <= 'Z')
        return UPPER;
    if (c >='a' && c <= 'z')
        return LOWER;
    if (c >='0' && c <= '9')
        return DIGIT;

    switch(c) {
    case ' ':
    case BELL:
    case BACKSPACE:
    case TAB:
    case NEWLINE:
    case VTAB:
    case RETURN:
        return WHITESPACE;
    }
    return OTHER;
}

/* FILLIN: FILL IN THE CHARS IN THE ABBREVIATED STRING  */
int fillin(char s[], int j, char beg, char end)
{
    int n = (beg < end) ? 1 : -1;

    beg += n;
    s[j++] = beg;

    while (beg != end) {
        beg += n;
        s[j++] = beg;
    }
    return j;
}
