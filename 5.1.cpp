#include <iostream>
#include <conio.h>
#include <cmath>


using namespace std;


const double A = 1, B = 2, EPS=0.001, EPS_3 = pow(10,-3)/2, EPS_4 = pow(10, -4) / 2, EPS_5 = pow(10, -5) / 2;
double f(double x) { return (pow(10*x - 1, 3)); }
//double f(double x) { return x * x; }

const double refValOfIntegral = 1 / 3.0;
double integralSimpleN(double a, double b, int n) {
	double h = (b-a) / n;
	double sum = 0;
	int i;
	for ( i = 0; i < n; i++)
	{
		sum += (f(a+h*i) + f(a + h*(i+1) )) / 2.0;
	}
	sum *= h;

	cout <<i<< "Интеграл на ["<<a<<","<<b<<"] = " << sum << ":  h= " << h<<" n= "<<n << " I="<<refValOfIntegral<< " delta= "<< abs(refValOfIntegral - sum)<< "\n\n";

	return sum;
}
double integralN(double a, double b, int n) {
	double h = (b-a) / n;
	double sum = (f(a) + f(b))/ 2.0;
	int i;
	for ( i = 1; i <= n-1; i++)
	{
		sum += f(a + h*i);
	}
	sum *= h;

	cout <<i-1<< "Интеграл на ["<<a<<","<<b<<"] = " << sum << ":  h= " << h<<" n= "<<n << " I="<<refValOfIntegral<< " delta= "<< abs(refValOfIntegral - sum)<< "\n\n";

	return sum;
}
double integralH(double a, double b, double h) {
	
	double sum = (f(a) + f(b))/ 2.0;
	int i=0;
	while (a+h * i  < b)
	{
		sum += f(a + h * i);
		i++;
	}
	sum *= h;

	cout <<i-1<< "Интеграл на ["<<a<<","<<b<<"] = " << sum << ":  h= " << h << " I="<<refValOfIntegral<< " delta= "<< abs(refValOfIntegral - sum)<< "\n\n";

	return sum;
}
double integralH2(double a, double b, int n, double h) {
	double I = integralH(a, b, h);
	//n *= 2;
	//double h = (b-a) / n;
	double sum = 0.0;
	int i;
	for ( i = 1; i <= n; i++)
	{
		sum += f(a + (2 * i - 1) * h / 2);
	}
	sum = I/2 + h/2 * sum;
	
	cout <<i-1<< "h/2 Интеграл на ["<<a<<","<<b<<"] = " << sum << ":  h= " << h<<" n= "<<n << " I="<<refValOfIntegral<< " delta= "<< abs(refValOfIntegral - sum)<< "\n\n";

	return sum;
}
double integralEps(double a, double b, double eps) {
	streamsize ss = cout.precision();
	double h,I,I2, r = 1, n=1;
	int i = 0;
	while (r > eps)
	{
		h = 1. / n;
		I = integralH(a, b, h);
		I2 = integralH2(a, b, n,h);
		r = abs(I2 - I)/3;

		n *= 2;
		i++;
	}
	double sum = I;


	cout << i << "Eps Интеграл на [" << a << "," << b << "] = ";
	cout.scientific;
	cout.precision(i+1);
	cout << sum;
	cout.precision(cout.precision(ss));
	cout << ":  h= " << h << " n= " << n << " I=" << refValOfIntegral;

	cout.precision(2);
	cout << " delta= " << abs(refValOfIntegral - sum) << "\n\n";
	cout.precision(cout.precision(ss));

	return sum;
}

//void vsc(double delta, double x) {
//	for (int i = 0; i < length; i++)
//	{
//
//	}
//}

int main() {
	setlocale(LC_ALL, "Ru");

	//integralN(A, B, 1);
	cout << "Простая формула\n";
	for (int i = 1; i <= 256; i*=2)
	{
		integralSimpleN(A, B, i);
	}
	cout << "////////////////////////////////////////////////////////////////////\n";
	cout << "Составная\n";
	for (int i = 1; i <= 256; i*=2)
	{
		integralN(A, B, i);
	}
	cout << "////////////////////////////////////////////////////////////////////\n";
	cout << "постоянный шаг\n";
	double h = (B - A) / 1;
	for (int i = 1; i <= 256; i *= 2)
	{
		integralH(A, B, (B - A) / i);
	}
	

	cout << "////////////////////////////////////////////////////////////////////\n";
	cout << "h/2\n";
	for (int i = 1; i <= 256; i *= 2)
	{
		integralH2(A, B, i, (B - A) / i);
	}
	/*cout << "////////////////////////////////////////////////////////////////////\n";
	cout << "C точностью"<<EPS_3<<"\n";
	integralEps(A, B, EPS_3);
	cout << "////////////////////////////////////////////////////////////////////\n";
	cout << "C точностью" << EPS_4 << "\n";
	integralEps(A, B, EPS_4); 
	cout << "////////////////////////////////////////////////////////////////////\n";
	cout << "C точностью" << EPS_5 << "\n";
	integralEps(A, B, EPS_5);
	*/
	
	

	return 0;
}