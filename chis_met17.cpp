#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double a = 0, x = 0, b = 0, e = 0, A, B, fa, fx, fb;
int iter ;
//�������
double f(double x)
{
	return log(x+2)-1/(x*x-x+1);
}
//����������� �������
double fd(double x)
{
	return (2*x+1)/pow((x*x-x+1),2) + 1/(x+2);
}

//����� ����������� �������
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
	cout << "�������� : " << iter << setprecision(17)<<"\n���� ��������� ��������� :" << x0 << "\n����� : " << x 
		 <<setprecision(3)<<"\nf(x) ="<<f(x)<< "\n xn - xn-1 :"<<x-x0<<"\n";
	return x;		
}
//����� ����
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
	cout << "�������� : " << iter << setprecision(17)<<"\n���� ��������� ��������� :" << x0 << "\n����� : " << x 
		 << setprecision(3)<<"\nf(x) ="<<f(x)<< "\n xn - xn-1 :"<<x-x0<<"\n";
	return x;	
}

//����� �������
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
  	cout << "�������� : " << iter << setprecision(17)<<"\n���� ��������� ��������� :" << x0  << "\n�����: "<<x
	  	 <<setprecision(3)<<"\nf(x) ="<<f(x)<< "\n xn - xn-1 :"<<x-x0<<"\n";
  	return 0;
}

//����� ������� ��������
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
	cout << "�������� : " << iter << setprecision(17)<<"\n���� ��������� ��������� :" << x0  << "\n����� :"<<x
		 <<setprecision(3)<<"\nf(x) ="<<f(x)<< "\n xn - xn-1 :"<<x-x0<<"\n";
	return 0;
}

//����� �������
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
  	cout << "�������� : " << iter  << setprecision(17)<<"\n���� ��������� ��������� :" << x0 << "\n����� :" << x 
	  	 <<setprecision(3)<<"\nf(x) ="<<f(x)<< "\n xn - xn-1 :"<<x-x0<<"\n";
  	return 0;
}
//��� �����
double VSE(double x,double b,double eps)
{
	double x0;
	iter = 0;
	do 
   	{
   		do
		{
   			x0 = x;
    		x = x0 +  fabs(f(x0)) / 4.23;//1.25 ��� ������������ ��������� �������� ����������� 
    		iter++;
   		}while (abs(x - x0) > e );
   		cout<<"�������� :"<< iter << setprecision(17)<<"\n���� ��������� ��������� :" << x0 <<"\n����� :"<< x 
		   	<<setprecision(3)<<"\nf(x) ="<<f(x)<< "\n xn - xn-1 :"<<x-x0<<"\n"<<"\n";
   		x = x + 1e-13;
	}while(x < b);
	return 0;
}

int menu()
{
	int variant;
	cout << "1.������������ �������� ������. \n"
	     << "2.������� ������� �������. \n"
	     << "3.�������. \n"
	     << "4.����. \n"
	     << "5.�������. \n"
	     << "6.������� �������� \n"
	     << "7.��� ����� \n"
		 << "8.�����.\n"
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
			cout <<"a < b and a!=0 \n������ ������� : ";
		//	cin >> a;
			a = 0.1;
			A = a;
			cout << "����� ������� : " ;
		//	cin >> b;
			b = 1;
			B = b;
			cout << "����������� : " ;
			cin >> e;
			e = 1e-15;
			if(a > b)
			{
				a = B;
				b = A;
			}
			cout << "�������� ������ ������������!\n\n";
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
				cout << "�� ����� �������� �";
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
				cout << "������ �������� �";
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
