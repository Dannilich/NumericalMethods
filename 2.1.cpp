//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//const double PI = acos(-1.0);
//const int STEP_AMOUNT = 30;
//const double MAX_RANGE = PI, MIN_RANGE = 0;
//const double STEP = (MAX_RANGE - MIN_RANGE) / STEP_AMOUNT;
//
//const double EPS_3 = pow(10, -3), EPS_4 = pow(10, -4), EPS_5 = pow(10, -5);
//
//
//long int factorialN(int n)
//{
//    long int mul = 1;
//    for (int i = 1; i < n + 1; i++)
//    {
//        mul *= i;
//    }
//
//    return mul;
//}
//
//
//double doubleRecMacklorensin(double x, double epsilon)
//{
//    double sum = x, next = -x*x*x/6;
//    int i = 3, factorial = 6;
//
//    
//    while (abs(next) >= epsilon)
//    {
//        sum += next;
//
//        next *= -x*x /((i + 1)*(i + 2));
//        i+=2; 
//    }
//
//    if (x == 0) i=5;
//    cout << (i-1)/2 -1<< " | " << next << " | " << sum << " | " << sin(x) << " | " << abs(sin(x) - sum) << " | " << epsilon << endl;
//
//    return sum;
//}
//void doubleRecTable(int step_amount, double eps) {
//    cout << "Double рекурентно до "<< step_amount/30 << "PI c точностью до "<< eps<< ":" << endl;
//    cout << "i x:  Кол-во членов | Следующий член | Сумма | Точное значение | абс. погрешн. | погрешность" << endl << endl;
//    double x = 0;
//    for (int i = 0; i <= step_amount; i++)
//    {
//        if (i < 10) cout << 0;
//        cout << i << "  " << x << ":  ";
//        doubleRecMacklorensin(x, eps);
//
//        x += STEP;
//    }
//    cout << "\n\n\n";
//}
//
//
//double doubleAnMacklorensin(double x, double epsilon)
//{
//    long double sum = x, next = -x * x * x / 6;
//    int i = 2;
//
//
//    while (abs(next) - epsilon > 0)
//    {
//        sum += next;
//
//        i ++;
//        
//        next = pow(-1, i - 1) * long double(pow(x, 2*i -1)) / factorialN(2 * i - 1);
//        if (i == 7)
//        {
//            //cout << pow(x, 2 * i - 1) << " /  " << factorialN(2 * i - 1)<< " ="<< pow(x, 2 * i - 1) / factorialN(2 * i - 1);
//            if (x - PI < EPS_3)
//            {
//                break;
//            }
//        }
//
//        //cout << "  " << next;
//    }
//
//    if (x == 0) i = 2;
//    cout << i-1 << " | " << next << " | " << sum << " | " << sin(x) << " | " << abs(sin(x) - sum) << " | " << epsilon << endl;
//
//    return sum;
//}
//void doubleAnTable(int step_amount, double eps) {
//    cout << "Double аналитически до " << step_amount / 30 << "PI c точностью до " << eps << ":" << endl;
//    cout << "i x:  Кол-во членов | Следующий член | Сумма | Точное значение | абс. погрешн. | погрешность" << endl << endl;
//    double x = 0;
//    for (int i = 0; i <= step_amount; i++)
//    {
//        if (i < 10) cout << 0;
//        cout << i << "  " << x << ":  ";
//        doubleAnMacklorensin(x, eps);
//
//        x += STEP;
//    }
//    cout << "\n\n\n";
//}
//
//
//
//void doubleRecTable(double a, double b, double eps) {
//    //double h = (b - a) / n;
//    double n = (b - a) / STEP;
//    cout << "Double  ["<< a<<","<<b << "] c точностью до " << eps << ":" << endl;
//    cout << "i x:  Кол-во членов | Следующий член | Сумма | Точное значение | абс. погрешн. | погрешность" << endl << endl;
//    double x = a;
//    for (int i = 0; i <= n; i++)
//    {
//        if (i < 10) cout << 0;
//        cout << i << "  " << x << ":  ";
//        doubleRecMacklorensin(x, eps);
//
//        x += STEP;
//    }
//    cout << "\n\n\n";
//}
//void doubleAnTable(double a, double b, double eps) {
//    double n = (b - a) / STEP;
//    cout << "Double аналитически [" << a << "," << b << "]c точностью до " << eps << ":" << endl;
//    cout << "i x:  Кол-во членов | Следующий член | Сумма | Точное значение | абс. погрешн. | погрешность" << endl << endl;
//    double x = a;
//    for (int i = 0; i <= n; i++)
//    {
//        if (i < 10) cout << 0;
//        cout << i << "  " << x << ":  ";
//        doubleAnMacklorensin(x, eps);
//
//        x += STEP;
//    }
//    cout << "\n\n\n";
//}
//
//
//
//float floatRecMacklorensin(float x, double epsilon)
//{
//    float sum = x, next = -x * x * x / 6;
//    int i = 3, factorial = 6;
//
//
//    while (abs(next) >= epsilon)
//    {
//        sum += next;
//
//        next *= -x * x / ((i + 1) * (i + 2));
//        i += 2;
//    }
//
//    if (x == 0) i = 5;
//    cout << (i - 1) / 2 - 1 << " | " << next << " | " << sum << " | " << sin(x) << " | " << abs(sin(x) - sum) << " | " << epsilon << endl;
//
//    return sum;
//}
//void floatRecTable(int step_amount, double eps) {
//    cout << "float рекурентно до " << step_amount / 30 << "PI c точностью до " << eps << ":" << endl;
//    cout << "i x:  Кол-во членов | Следующий член | Сумма | Точное значение | абс. погрешн. | погрешность" << endl << endl;
//    float x = 0;
//    for (int i = 0; i <= step_amount; i++)
//    {
//        if (i < 10) cout << 0;
//        cout << i << "  " << x << ":  ";
//        floatRecMacklorensin(x, eps);
//
//        x += STEP;
//    }
//    cout << "\n\n\n";
//}
//
//
//float floatAnMacklorensin(float x, double epsilon)
//{
//    long float sum = x, next = -x * x * x / 6;
//    int i = 2;
//
//
//    while (abs(next) > epsilon )
//    {
//        sum += next;
//
//        i++;
//
//        next = pow(-1, i - 1) * long float(pow(x, 2 * i - 1)) / factorialN(2 * i - 1);
//        if (i == 6)
//        {
//            //cout << pow(x, 2 * i - 1) << " /  " << factorialN(2 * i - 1)<< " ="<< pow(x, 2 * i - 1) / factorialN(2 * i - 1);
//            if (x - PI < EPS_3)
//            {
//                break;
//            }
//        }
//
//        //cout << "  " << next;
//    }
//
//    if (x == 0) i = 2;
//    cout << i - 1 << " | " << next << " | " << sum << " | " << sin(x) << " | " << abs(sin(x) - sum) << " | " << epsilon << endl;
//
//    return sum;
//}
//void floatAnTable(int step_amount, double eps) {
//    cout << "float аналитически до " << step_amount / 30 << "PI c точностью до " << eps << ":" << endl;
//    cout << "i x:  Кол-во членов | Следующий член | Сумма | Точное значение | абс. погрешн. | погрешность" << endl << endl;
//    float x = 0;
//    for (int i = 0; i <= step_amount; i++)
//    {
//        if (i < 10) cout << 0;
//        cout << i << "  " << x << ":  ";
//        floatAnMacklorensin(x, eps);
//
//        x += STEP;
//    }
//    cout << "\n\n\n";
//}
//
//
//int maindd()
//{
//    setlocale(LC_ALL, "Ru");
//
//    
//
//    //floatRecTable(STEP_AMOUNT, EPS_3);
//    //floatRecTable(STEP_AMOUNT, EPS_4);
//    //floatRecTable(STEP_AMOUNT, EPS_5);
//
//    //floatRecTable(STEP_AMOUNT * 12, EPS_3);
//    //floatRecTable(STEP_AMOUNT * 12, EPS_4);
//    //floatRecTable(STEP_AMOUNT * 12, EPS_5);
//    
//    //doubleRecTable(STEP_AMOUNT * 12, EPS_3);
//    //doubleRecTable(STEP_AMOUNT * 12, EPS_4);
//    //doubleRecTable(STEP_AMOUNT * 12, EPS_5);
//
//    floatAnTable(STEP_AMOUNT * 12, EPS_3);
//    floatAnTable(STEP_AMOUNT * 12, EPS_4);
//    floatAnTable(STEP_AMOUNT * 12, EPS_5);
//
//   /* doubleRecTable(STEP_AMOUNT, EPS_3);
//    doubleRecTable(0,PI, EPS_3);
//
//    doubleRecTable(STEP_AMOUNT, EPS_4);
//    doubleRecTable(STEP_AMOUNT, EPS_5);*/
//
//    doubleAnTable(STEP_AMOUNT * 12, EPS_3);
//    doubleAnTable(STEP_AMOUNT * 12, EPS_4);
//    doubleAnTable(STEP_AMOUNT * 12, EPS_5);
//
//    return 0;
//}
