#include <iostream>
#include <math.h>

using namespace std;

double const A = 9, B1 = 10, B2 = 13;
double f1(double x) { return (9 + pow(x-9,7)); }
double f2(double x) { return (9 + pow(x-9,10)); }
double const refValofI1 = 9.125, refValofI2 = 381350;

long int factorialN(int n)
{
    long int mul = 1;
    for (int i = 1; i < n + 1; i++)
    {
        mul *= i;
    }

    return mul;
}


double AA[5][5] = { 
    {2.}, 
    { 1., 1. },  
    { 5. / 9, 8. / 9, 5. / 9 },
    { (18 - sqrt(30)) / 36.,(18 + sqrt(30)) / 36.,(18 + sqrt(30)) / 36.,(18 - sqrt(30)) / 36. },
    { (322 - 13. * sqrt(70)) / 900,(322 + 13. * sqrt(70)) / 900, 128. / 225, (322 + 13. * sqrt(70)) / 900, (322 - 13. * sqrt(70)) / 900 }
};
double TT[5][5] = {
    {0.},
    { -1. / sqrt(3), 1. / sqrt(3) },
    { 5. / 9, 8. / 9, 5. / 9 },
    { -sqrt(3. / 7 + 2. / 7 * sqrt(6. / 5)), -sqrt(3. / 7 - 2. / 7 * sqrt(6. / 5)), sqrt(3. / 7 - 2. / 7 * sqrt(6. / 5)),sqrt(3. / 7 + 2. / 7 * sqrt(6. / 5)) },
    { -1. / 3 * sqrt(5 + 2 * sqrt(10. / 7)), -1. / 3 * sqrt(5 - 2 * sqrt(10. / 7)), 0, 1. / 3 * sqrt(5 - 2 * sqrt(10. / 7)), 1. / 3 * sqrt(5 + 2 * sqrt(10. / 7)) }
};

double r1(double n, double a, double b) {
    double R = pow(b - a, 2 * n + 1) * pow(factorialN(n), 4) / ((2 * n + 1) * pow(factorialN(2 * n), 3));
    double der;

    der = factorialN(7) * abs(pow(b - 6, 7 - 2 * n)) / factorialN(7 - 2 * n);
    R *= der;
    /*if (2 * n > 7)
        R = 0;*/
    return R;
}
double gaussIntegral1(double a, double b, int n) {
    
    double sum = 0, x;
    for (int i = 0; i < n; i++)
    {
        //cout << AA[n-1][i] << "  ";
        x = (b + a) / 2. + ((b - a) / 2.) * TT[n-1][i];
        sum += AA[n-1][i] * f1(x);
    }

    sum *= (b - a) / 2.;
    cout << ": "<< sum << "  "<< " Точное="<< refValofI1<< "  delta="<< abs(refValofI1 - sum)<< "  r(n)=" <<r1(n,a,b)<< endl;
    return sum;
}


double r2(double n, double a, double b) {
    double R = pow(b - a, 2 * n + 1) * pow(factorialN(n), 4) / ((2 * n + 1) * pow(factorialN(2 * n), 3));
    double der;

    der = factorialN(10) * abs(pow(b - 6, 10 - 2 * n)) / factorialN(10 - 2 * n);
    R *= der;
    /*if (2 * n > 7)
        R = 0;*/
    return R;
}
double gaussIntegral2(double a, double b, int n) {
    
    double sum = 0, x;
    for (int i = 0; i < n; i++)
    {
        //cout << AA[n-1][i] << "  ";
        x = (b + a) / 2. + ((b - a) / 2.) * TT[n-1][i];
        sum += AA[n-1][i] * f2(x);
    }

    sum *= (b - a) / 2.;
    cout << ": "<< sum << "  "<< " Точное="<< refValofI2<< "  delta="<< abs(refValofI2 - sum)<< "  r(n)=" <<r2(n,a,b)<< endl;
    return sum;
}

int mainд()
{
	setlocale(LC_ALL, "Ru");

    cout << "\n\n Для f1(x) = 9 + (x-9)^7 :\n";
    for (int i = 1; i <= 5; i++)
    {
        gaussIntegral1(A, B1,i);
    }
    cout << "\n\n Для f2(x) = 9 + (x-9)^10 :\n";
    for (int i = 1; i <= 5; i++)
    {
        gaussIntegral2(A, B2,i);
    }
	return 0;
}