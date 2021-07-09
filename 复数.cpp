#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>

//构造复数类型
typedef struct Complex
{
	float Real;
	float Imag;
}Complex, * Pcomplex;

//共轭复数
Pcomplex AdjointComplex(Pcomplex a)
{
	Pcomplex b = (Pcomplex)malloc(sizeof(Complex));
	b->Real = a->Real;
	b->Imag = -(a->Imag);
	return b;
}

//复数打印
void ShowComplex(Complex a)
{
	printf("%.2f + %.2fi\n", a.Real, a.Imag);
}

//复数相加
void AddComplex(Pcomplex c, Complex a, Complex b)
{
	c->Real = a.Real + b.Real;
	c->Imag = a.Imag + b.Imag;
}

//复数相乘
void MultiplyComplex(Pcomplex c, Complex a, Complex b)
{
	c->Real = (a.Real * b.Real) - (a.Imag * b.Imag);
	c->Imag = (a.Imag * b.Real) + (a.Real * b.Imag);
}

//复数相除
void DevideComplex(Pcomplex c, Complex a, Complex b)
{
	Pcomplex pab = AdjointComplex(&b);

	float bottom = (b.Real * b.Real) + (b.Imag * b.Imag);

	MultiplyComplex(c, a, *pab);

	c->Real = c->Real / bottom;
	c->Imag = c->Imag / bottom;
}

int main()
{
	Complex z1, z2, z3, z4, z;
	z1 = {8, 6};
	z2 = {4, 3};

	AddComplex(&z3, z1, z2);
	ShowComplex(z3);

	MultiplyComplex(&z4, z1, z2);
	ShowComplex(z4);
	
	DevideComplex(&z, z4, z3);
	ShowComplex(z);

	return 0;
}