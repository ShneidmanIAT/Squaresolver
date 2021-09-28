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
    printf("#solver for square equation be yan\n#2021\n");
    printf("Parameters should be written by one and divided by gaps\n"); 
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
        printf("%s %f", "equation has 1 answer x =", x1);
        break;
    case Two:
        printf("%s %f%s %f", "equation has 2 answers: x1 =", x1, ", x2 =", x2);
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

void ScanReader(float *a, float *b, float *c)
{
    int succesfully_added = 0;
    bool input_correct = false;
    while (!input_correct)
    {
        succesfully_added += scanf("%f %f %f", a, b, c);
        if (succesfully_added != 3)
        {
            printf("Wrong type of input! Retry please:\n");
            succesfully_added = 0;
        }
        else
        {
            input_correct = true;
        }
    }
}
