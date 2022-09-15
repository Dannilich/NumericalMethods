#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Сумма ряда 1/(n^2)
    //const double REFERENCE_VALUE = 1.64493406685; //google calc pi^2 /6
    const double REFERENCE_VALUE =   1.6449330668487264; // округление
    //const double REFERENCE_VALUE = 1.64493306684872643630574849998; // более точное значение онлайн калькулятора
    
    const int MAX_RANGE  = pow(10,6), MIN_RANGE = 1;
    
    float tempF;
    double tempD;
    
//*****************  
    float qSumF = 0;
    double qSumD = 0;
    
    for (int i = MIN_RANGE; i < MAX_RANGE ; i++) {
        
        tempF = float(1 / pow(i,2));
        qSumF += tempF;
        
        tempD = double(1 / pow(i,2));
        qSumD += tempD;
    }
    
    float DqF = abs( REFERENCE_VALUE - qSumF );
    double DqD = abs( REFERENCE_VALUE - qSumD );
    
 //**** обратный обход ******  
//*****************************    
    float rSumF = 0;
    double rSumD = 0;
    
    for (int i = MAX_RANGE; i > MIN_RANGE ; i--) {
        
        tempF = float(1 / pow(i,2));
        rSumF += tempF;
        
        tempD = double(1 / pow(i,2));
        rSumD += tempD;
    }
    
    float DrF = abs( REFERENCE_VALUE - rSumF );
    double DrD = abs( REFERENCE_VALUE - rSumD );
 
 //**** Итог ******   
//*****************************     
    cout << fixed;
    cout.precision(30);
    
    cout << "Эталонное значение: "<< REFERENCE_VALUE << endl << endl;
    
    cout << endl << "Обход с начала:"<< endl << endl;
    cout << "Double: " << qSumD << endl << "Абс. погрешность: " << DqD << endl<< endl;
    cout << "Float: " << qSumF  << endl << "Абс. погрешность: " << DqF << endl<< endl<< endl;
    
    cout << endl << "Обход с конца:"<< endl << endl;
    cout << "Double: " << rSumD << endl << "Абс. погрешность: " << DrD << endl<< endl;
    cout << "Float: " << rSumF  << endl << "Абс. погрешность: " << DrF << endl<< endl;
    
    
    cout << "Выводы:"<< endl << endl;
    
    cout << "* число не храниться точно) "<< 1.64493306684872643630574849998 - REFERENCE_VALUE << endl;
    
    const double inaccuracyD = DqD + DrD, inaccuracyF = DrF + DqF;
    
    if ( inaccuracyD < inaccuracyF){
        cout << "* double точнее" << endl;
    
    }else if (inaccuracyD > inaccuracyF){
        cout << "* float точнее" << endl;
    
    }else{
        cout << "* тип данных не влияет на точность" << endl;
    }
    
    const double forwardInaccuracy = DqD + DqF, reverseInaccuracy = DrD + DrF;
    
    if ( forwardInaccuracy < reverseInaccuracy){
        cout << "* прямой порядок точнее" << endl;
    
    }else if (forwardInaccuracy > reverseInaccuracy){
        cout << "* обратный порядок точнее" << endl;
    
    }else{
        cout << "* порядок не влияет на точность" << endl;
    }
    
    
}
