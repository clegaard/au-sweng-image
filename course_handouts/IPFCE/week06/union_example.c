#include <stdio.h>  /* scanf, printf */
#include <stdlib.h> /* abort */
#include <assert.h> /* assert */

typedef enum
{
    CHARV,
    INTV
} vtype;

typedef struct
{
    vtype typ; /* type of the value */
    union {
        int intv;   /* the number if vtype == INTV */
        char charv; /* the character if vtype == CHARV */
    };
} value;

int main(void)
{
    char yn;
    value val;

    printf("To input a character 'c' type 'yc'.\n");
    printf("To input an int 'x' 'nx'.\n");

    scanf("%c", &yn);

    /* precondition: the first character must by 'y' or 'n' */
    assert(yn == 'y' || yn == 'n');

    /* read the next value depending on the first character */
    if (yn == 'y')
    {
        val.typ = CHARV;
        scanf("%c", &val.charv);
    }
    else
    { /* yn must equal 'n' */
        val.typ = INTV;
        scanf("%d", &val.intv);
    }

    /* print value of the struct val */
    switch (val.typ)
    {
    case CHARV:
        printf("%c\n", val.charv);
        break;
    case INTV:
        printf("%d\n", val.intv);
        break;
    default:
        abort();
    }

    return 0;
}

// 3-by-3 matrix using union
typedef union {

    float mat[3][3];
    float mat[9];

} Matrix33;