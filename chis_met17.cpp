#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double a = 0, x = 0, b = 0, e = 0, A, B, fa, fx, fb;
int iter ;
//ФУНКЦИЯ
double f(double x)
{
	return log(x+2)-1/(x*x-x+1);
}
//ПРОИЗВОДНАЯ ФУНКЦИИ
double fd(double x)
{
	return (2*x+1)/pow((x*x-x+1),2) + 1/(x+2);
}

//МЕТОД ПОЛОВИННОГО ДЕЛЕНИЯ
double POPOLAM(double a, double b, double x, double e)
{
	double x0;
	iter = 0;
	fa = f(a);
    fb = f(b);
    do{
    	x0=x;
		x = (a + b) / 2;
    	fx = f(x);
		iter++;
		if((fa * fx) < 0)
		{	
			b = x;
		}
		else
		{
			a = x;
			fa = fx;
		}
	}while((b - a) > e);
	cout << "Итераций : " << iter << setprecision(17)<<"\nПред последний результат :" << x0 << "\nОтвет : " << x 
		 <<setprecision(3)<<"\nf(x) ="<<f(x)<< "\n xn - xn-1 :"<<x-x0<<"\n";
	return x;		
}
//МЕТОД ХОРД
double HORD(double a, double b, double x,double eps)
{	
double x0;
	iter = 0;
	do{
		x0=x;
		iter++;
		x = a - ( (b - a) * f(x) ) / (f(b) - f(a));
		if(f(a) * f(x) < 0)
			b = x;
		else
			a = x;
	}while(abs(f(x)) > e);
	cout << "Итераций : " << iter << setprecision(17)<<"\nПред последний результат :" << x0 << "\nОтвет : " << x 
		 << setprecision(3)<<"\nf(x) ="<<f(x)<< "\n xn - xn-1 :"<<x-x0<<"\n";
	return x;	
}

//МЕТОД НЬЮТОНА
double NIOTON(double x, double eps) 
{
  	double x0;
	iter = 0;
   	do 
   	{
   		x0 = x;
    	x = x0 -  f(x0) / fd(x0);
    	iter++;
    }while (abs(x - x0) > e );
  	cout << "Итераций : " << iter << setprecision(17)<<"\nПред последний результат :" << x0  << "\nОтвет: "<<x
	  	 <<setprecision(3)<<"\nf(x) ="<<f(x)<< "\n xn - xn-1 :"<<x-x0<<"\n";
  	return 0;
}

//МЕТОД ПРОСТОЙ ИТЕРАЦИИ
double ITER(double x, double e) 
{
	double x0;
	iter = 0;
	do 
	{
		x0=x;
		x = x-f(x);
		iter++;
	}while (fabs(f(x)) > e);
	cout << "Итераций : " << iter << setprecision(17)<<"\nПред последний результат :" << x0  << "\nОтвет :"<<x
		 <<setprecision(3)<<"\nf(x) ="<<f(x)<< "\n xn - xn-1 :"<<x-x0<<"\n";
	return 0;
}

//МЕТОД СЕКУЩЕЦ
double SEC(double a, double x, double e) 
{
  	double c,x0;
  	iter = 0;
  	do 
	{
		x0 = x;
    	c = f(x);
    	x = x - c / (c - f(a)) * (x - a);
    	iter++;
  	}while (fabs(c) > e );
  	cout << "Итераций : " << iter  << setprecision(17)<<"\nПред последний результат :" << x0 << "\nОтвет :" << x 
	  	 <<setprecision(3)<<"\nf(x) ="<<f(x)<< "\n xn - xn-1 :"<<x-x0<<"\n";
  	return 0;
}
//все корни
double VSE(double x,double b,double eps)
{
	double x0;
	iter = 0;
	do 
   	{
   		do
		{
   			x0 = x;
    		x = x0 +  fabs(f(x0)) / 4.23;//1.25 это максимальное возможное значение производной 
    		iter++;
   		}while (abs(x - x0) > e );
   		cout<<"Итераций :"<< iter << setprecision(17)<<"\nПред последний результат :" << x0 <<"\nОтвет :"<< x 
		   	<<setprecision(3)<<"\nf(x) ="<<f(x)<< "\n xn - xn-1 :"<<x-x0<<"\n"<<"\n";
   		x = x + 1e-13;
	}while(x < b);
	return 0;
}

int menu()
{
	int variant;
	cout << "1.Формирования исходных данных. \n"
	     << "2.Деление отрезка пополам. \n"
	     << "3.Ньютона. \n"
	     << "4.Хорд. \n"
	     << "5.Секущих. \n"
	     << "6.Простой итерации \n"
	     << "7.Все корни \n"
		 << "8.Выход.\n"
	     << ">>> ";
	cin >> variant;
	return variant;
}

int main()
{
	setlocale(LC_ALL,"RUS");
	int variant;
	start: variant = menu();
	switch(variant)
	{
		case 1:
		{
			system("cls");
			cout <<"a < b and a!=0 \nНачало отрезка : ";
		//	cin >> a;
			a = 0.1;
			A = a;
			cout << "Конец отрезка : " ;
		//	cin >> b;
			b = 1;
			B = b;
			cout << "Погрешность : " ;
			cin >> e;
			e = 1e-15;
			if(a > b)
			{
				a = B;
				b = A;
			}
			cout << "Исходные данные сформированы!\n\n";
			system("pause");
			system("cls");
			goto start;
		}
    	case 2:
    	{
    		system("cls");
    		POPOLAM(a, b, x, e);
    		x = 0;
			fx = 0;
			fa = 0;
			a = A;
			b = B;
			system("pause");
    		system("cls");
    		goto start;
    	}
		case 3:
		{
			system("cls");
			int iter = 0;
			if(a != 0)
			{
				x = a;
				NIOTON(x, e);
				x = 0;
				fx = 0;
				fa = 0;
				a = A;
				b = B;
 				system("pause");
    			system("cls");
    			goto start;
			}
    		else
    		{
				cout << "вы ввели неверное а";
    			system("pause");
    			system("cls");
    			goto start;
			}
		}
		case 4:
		{
			system("cls");
			HORD(a,b,x,e);
			x = 0;
			fx = 0;
			fa = 0;
			a = A;
			b = B;
 			system("pause");
    		system("cls");
    		goto start;
		}
	    case 5:
	  	{
			system("cls");
  			SEC(a, b, e);
  			x = 0;
			fx = 0;
			fa = 0;
			a = A;
			b = B;
 			system("pause");
    		system("cls");
    		goto start;
		}
	    case 6:	
		{
			system("cls");
			if(a != 0)
			{
				ITER(a, e);
				x = 0;
				fx = 0;
				fa = 0;
				a = A;
				b = B;
				system("pause");
    			system("cls");
    			goto start;
			}
			else
			{
				cout << "задано неверное а";
				system("pause");
    			system("cls");
    			goto start;
			}
		}
		case 7:	
		{
			system("cls");
			VSE(a,b,e);
			x = 0;
			fx = 0;
			fa = 0;
			a = A;
			b = B;
			system("pause");
    		system("cls");
    		goto start;
		}
	    case 8:
		{
			default:
	    	system("cls");
			return 0;
		}
}
	
	return 0;
}
