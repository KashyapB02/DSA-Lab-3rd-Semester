#include <stdio.h>
#include <stdlib.h>


struct term
{
    int coefficient;
    int exponent;
};


struct polynomial
{
    int no_of_terms;
    struct term *t;
};


void create(struct polynomial *p)
{
    printf("Number of terms -> ");
    scanf("%d", &p->no_of_terms);

    p->t = (struct term *)malloc(p->no_of_terms * sizeof(struct term));

    printf("\n");

    for (int i = 0; i < p->no_of_terms; i++)
    {
        printf("Term %d:\n", (i + 1));

        printf("Coefficient --> ");
        scanf("%d", &p->t[i].coefficient);

        printf("Exponent    --> ");
        scanf("%d", &p->t[i].exponent);

        printf("\n");
    }
}


void display(struct polynomial p)
{
    if((p.t[0].exponent) == 0)
    {
        printf("%d", p.t[0].coefficient);
    }
    else
    {
        printf("%d(x^%d) ", p.t[0].coefficient, p.t[0].exponent);
    }
    
    for (int i = 1; i < p.no_of_terms; i++)
    {
        if((p.t[i].exponent) == 0)
        {
            printf("+ %d ", p.t[i].coefficient);
        }
        else
        {
            printf("+ %d(x^%d) ", p.t[i].coefficient, p.t[i].exponent);
        }
    }

    printf("\n");
}

struct polynomial *addition (struct polynomial *p1, struct polynomial *p2)
{
    struct polynomial *sum;
    sum = (struct polynomial *)malloc(sizeof(struct polynomial));

    sum->t = (struct term *)malloc((p1->no_of_terms + p2->no_of_terms) * sizeof(struct term));

    int i = 0, j = 0, k = 0;

    while ((i < p1->no_of_terms) && (j < p2->no_of_terms))
    {
        if ((p1->t[i].exponent) > (p2->t[j].exponent))
        {
            sum->t[k++] = p1->t[i++];
        }  
        else if ((p1->t[i].exponent) < (p2->t[j].exponent))
        {
            sum->t[k++] = p2->t[j++];
        }
        else
        {
            sum->t[k].exponent = p1->t[i].exponent;
            sum->t[k++].coefficient = (p1->t[i++].coefficient) + (p2->t[j++].coefficient);
        }
    }

    for (; i < p1->no_of_terms; i++)
    {
        sum->t[k++] = p1->t[i];
    }
    
    for (; j < p2->no_of_terms; j++)
    {
        sum->t[k++] = p2->t[j++];
    }

    sum->no_of_terms = k;

    return sum;
}


int main()
{
    struct polynomial p1, p2, *p3;

    printf("Polynomial 1:\n");
    create(&p1);
    printf("\n");

    printf("Polynomial 2:\n");
    create(&p2);
    printf("\n");

    p3 = addition(&p1, &p2);

    printf("P1(x) = ");
    display(p1);

    printf("P2(x) = ");
    display(p2);

    printf("\n");

    printf("P3(x) = ");
    display(*p3);

    printf("\n");
    return 0;
}