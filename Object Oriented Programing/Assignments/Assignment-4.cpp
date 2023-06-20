#include<iostream>
using namespace std;

class ComplexNumber
{
private:
	int real;
	int imaginary;
public:
	ComplexNumber(int r, int i)
	{
		real = r;
		imaginary = i;
	}
	~ComplexNumber()
	{
	}
	ComplexNumber()
	{
	}
	void Input()
	{
		cout << "Enter Real:\t";
		cin >> real;
		cout << "Enter Imaginary:\t";
		cin >> imaginary;
	}
	void Output()
	{
		if (imaginary >= 0)
		{
			cout << real << " + " << imaginary << "i\n" << endl;
		}
		else
		{
			imaginary = imaginary * -1;
			cout << real << " - " << imaginary << "i\n" << endl;
		}
	}
	bool IsEqual(ComplexNumber& cn)
	{
		if (real != cn.real || imaginary != cn.imaginary)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	ComplexNumber Conjugate()
	{
		ComplexNumber con;
		if (imaginary >= 0)
		{
			cout << real << " - " << imaginary << "i" << endl;
		}
		else
		{
			imaginary = imaginary * -1;
			cout << real << " + " << imaginary << "i" << endl;
		}
		return con;
	}
	ComplexNumber Add(ComplexNumber cn)
	{
		ComplexNumber add;
		add.imaginary = imaginary + cn.imaginary;
		add.real = real + cn.real;
		return add;
	}
	ComplexNumber Subtract(ComplexNumber cn)
	{
		ComplexNumber sub;
		sub.imaginary = imaginary - cn.imaginary;
		sub.real = real - cn.real;
		return sub;
	}
	ComplexNumber Multiplication(ComplexNumber cn)
	{
		ComplexNumber mul;
		mul.imaginary = imaginary * cn.imaginary;
		mul.real = real * cn.real;
		return mul;
	}
	float Magnitude()
	{
		float magnitude = sqrt((real * real) + (imaginary * imaginary));
		return magnitude;
	}
};
int main()
{
	ComplexNumber c1;
	ComplexNumber c2;
	cout << "Enter c1:" << endl;
	c1.Input();
	cout << "\n\nEnter c2:" << endl;
	c2.Input();
	cout << "\nc1=\t";
	c1.Output();
	cout << "c2=\t";
	c2.Output();
	bool check = c1.IsEqual(c2);
	if (check != true)
	{
		cout << "c1 is NOT Equal to c2" << endl;
	}
	else
	{
		cout << "c1 is Equal to c2" << endl;
	}
	cout << "\nConjugate of c1:\t";
	c1.Conjugate();
	cout << "\nConjugate of c2:\t";
	c2.Conjugate();
	ComplexNumber c3;
	cout << "\nc1 + c2 :\t";
	c3 = c1.Add(c2);
	c3.Output();
	cout << "c1 - c2 :\t";
	c3 = c1.Subtract(c2);
	c3.Output();
	cout << "c1 * c2 :\t";
	c3 = c1.Multiplication(c2);
	c3.Output();
	float mag= c1.Magnitude();
	cout << "Magnitude of c1:\t" << mag << endl;
	mag = c2.Magnitude();
	cout << "Magnitude of c2:\t" << mag << endl;
}