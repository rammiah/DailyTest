#include <stdio.h>
#include <stdlib.h>
#define EPS 1e-7

const char SWITCH[] =  "After switch processing,the result is : ";
const char IFELSE[] = "After if-else processing,the result is : ";

void Switch(double numA, double numB, char way)
{
    double result = 0;
    switch (way)
    {
    case '+':
        result = numA + numB;
        break;
    case '-':
        result = numA - numB;
        break;
    case '*':
        result = numA * numB;
    case '/':
        if ((numB > 0 ? numB : -numB) <= EPS)
        {
            exit(0);
        }
        result = numA / numB;
        break;
    default:
        exit(0);
    }
    printf("%s%.2f\n", SWITCH, result);
}

void IfElse(double numA, double numB, char way)
{
    double result;
    if (way == '+')
    {
        result = numA + numB;
    }
    else if (way == '-')
    {
        result = numA - numB;
    }
    else if (way == '*')
    {
        result = numA * numB;
    }
    else if (way == '/')
    {
        if ((numB > 0 ? numB : -numB) <= EPS)
        {
            exit(0);
        }
        result = numA / numB;
    }
    else
    {
        exit(0);
    }
    printf("%s%.2f\n", IFELSE, result);
}

void Process(int choise, double numA, double numB, char way)
{
    switch (choise)
        {
        case 0:
            IfElse(numA, numB, way);
            break;
        case 1:
            Switch(numA, numB, way);
            break;
        case 2:
            IfElse(numA, numB, way);
            Switch(numA, numB, way);
            break;
        default:
            exit(0);
        }
}

int main()
{
    double numA = 0, numB = 0;
    int choise = 0;
    char way;

    // thinking how to process the blank line?????
//    scanf("%d %lf %lf %c", &choise, &numA, &numB, &way);
//    Process(choise, numA, numB, way);
//    do{
//        if (scanf("%d %lf %lf %c", &choise, &numA, &numB, &way) == 4)
//        {
//             printf("\n");
//             Process(choise, numA, numB, way);
//        }
//        else
//        {
//            break;
//        }
//
//    } while(1);
    scanf("%d %lf %lf %c", &choise, &numA, &numB, &way);
    while (1)
    {
        Process(choise, numA, numB, way);

        if (scanf("%d %lf %lf %c", &choise, &numA, &numB, &way) == EOF)
        {
            break;
        }
        else
        {
            printf("\n");
        }
    }

    return 0;
}
/*
After switch processing,the result is : -15.50

After if-else processing,the result is : 4.00
After switch processing,the result is : 4.00

After if-else processing,the result is : 1.60
After switch processing,the result is : 1.60

After if-else processing,the result is : 28.80
*/
