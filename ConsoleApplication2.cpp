#include <iostream>
int SolveSquare(float a, float b, float c, float* x1, float* x2);
int LinearSolver(float a, float b, float c, float* x1);
void ScanReader(float* a, float* b, float* c);
enum AnswerNumber
{
    Infinity = 3,
    Two = 2,
    One = 1,
    Zero = 0
};
   int main()
{
    printf("#solver for square equation be yan\n"
    "#2021\n");
    printf("Parameters should be written by one and divided by gaps \n"); 
    printf("Enter the name of file\n");
    float a, b, c;
    int typeOfAnswer;
    ScanReader(&a, &b, &c);
    float x1, x2;
    typeOfAnswer = SolveSquare(a, b, c, &x1, &x2);
    switch (typeOfAnswer)
    {
    case Zero:
        printf("equation does not have any answers");
        break;
    case One:
        printf("equation has 1 answer x = ");
        printf("%f", x1);
        break;
    case Two:
        printf("equation has 2 answer x1 = ");
        printf("%f", x1);
        printf(", x2 = ");
        printf("%f", x2);
        break;
    case Infinity:
        printf("equation has infinite number of answers");
        break;
    }

}
int SolveSquare(float a, float b, float c, float* x1, float* x2)
{
    if (a == 0) 
    {
        int linearAnswer = LinearSolver(a, b, c, x1);
        *x2 = *x1;
        return linearAnswer;
    }
    else
    {
        float d = b * b - 4 * a * c;
        if (d > 0)
        {
            *x1 = (-b + sqrt(d)) / (2 * a);
            *x2 = (-b - sqrt(d)) / (2 * a);
            return Two;
        }
        else if (d == 0)
        {
            *x1 = (-b) / (2 * a);
            *x2 = *x1;
            return One;
        }
        else
        {
            return Zero;
        }
    }
 }
int LinearSolver(float a, float b, float c, float* x1)
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                return Infinity;
            }
            else
            {
                return Zero;
            }
        }
        else
        {
            *x1 = b / c;
            return One;
        }
    }
}
void ScanReader(float *a,float *b,float *c)
{
    int succesfully_added = 0;
    while (succesfully_added != 3)
    {
        succesfully_added += scanf("%f %f %f", a, b, c);
    }
}
