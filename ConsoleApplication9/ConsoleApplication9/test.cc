#include<iostream>
#include"Oj.h"
using namespace std;
void test()
{
	//int x1, x2,i;
	//cout << "�������һ������ʽ����" << endl;
	//cin >> x1;
	//Oj oj1(x1);
	//cout << "������ڶ�������ʽ����" << endl;
	//cin >> x2;
	//Oj oj2(x2);
	//if (oj1.divisible(oj2) == true)
	//	cout << "1true" << endl;
	//else
	//	cout << "1false" << endl;
	//if (oj1.check_Oj() == 0)
		//cout << "1 0" << endl;
	//else if (oj2.check_Oj() == 0)
		//cout << "2 0" << endl;
	//else
		//cout << "no 0" << endl;

	//Oj ojm = oj1.Eured(oj2);
	//ojm.print_Oj();
	//cout << "������1  ȡ�ࣺ2" << endl;
	//cout << "enter a integer" << endl;
	//cin >> i;
	//if (i = 1)
	//{
	//Oj ojg = oj1.upper(i);
	//ojg.print_Oj();
	//}
	//else
	//{
	//	Oj ojg = oj1.mod_Oj(oj2);
	//	ojg.print_Oj();
	//	Oj ojh = oj1.mod_Oj(ojg);
	//	ojh.print_Oj();
	//	Oj ojj = ojh.mod_Oj(ojg);
	//	ojj.print_Oj();
	//
	//}
	int i = 0;
	cout << "���ܲ���" << endl;
	cout << "������ʽ�Ƿ�Ϊ�㣺1" << endl
		<< "���������ʽ�Ƿ�������2" << endl
		<< "������ʽ��һ����Ϊ������3" << endl
		<< "������ʽȡ��ʽ���㣺4" << endl
		<< "����ʽ�޲ι��죺5" << endl
		<< "����ʽ�������죺6" << endl
		<< "����ʽint�ι��죺7" << endl
		<< "����ʽ�����жϣ�8" << endl
		<< "����ʽ����жϣ�9" << endl
		<< "��ӡ����ʽ��10" << endl
		<< "����ʽ���ݣ�11" << endl
		<< "����ʽתʵn��12" << endl
		<< "����ʽ�������㣺13" << endl
		<< "������ʽ������14" << endl
		<< "������ʽ�ӷ���15" << endl
		<< "����ʽ�ȴ�С��16" << endl
		<< "�����ʽ�����ʽ��17" << endl
		<< "���������18" << endl
		<< "Լ�����ʽ��19" << endl;
	cin >> i;
	int x1 = 0;
	int x2 = 0;
	cout << "�������һ������ʽ����" << endl;
	cin >> x1;
	Oj oj1(x1);
	cout << "������ڶ�������ʽ����" << endl;
	cin >> x2;
	Oj oj2(x2);
	if (i == 1)///////////////////////////////////////////////////////////////                                         1
	{
		if (oj1.check_Oj() == true)
			cout << "0" << endl;
		else if (oj1.check_Oj() == false)
			cout << "not 0" << endl;
		else
			cout << "error" << endl;
	}
	else if (i == 2)/////////////////////////////////////////////////////////                                          2
	{
		if (oj1.divisible(oj2) == true)
			cout << "����" << endl;
		else if (oj1.divisible(oj2) == false)
			cout << "������" << endl;
		else
			cout << "error" << endl;
	}
	else if (i == 3)////////////////////////////////////////////////////////                                           3
	{
		oj1.fix();
		oj1.print_Oj();
	}
	else if (i == 4)////////////////////////////////////////////////////////                                           4
	{
		Oj oj3 = oj1.mod_Oj(oj2);
		oj3.print_Oj();
	}
	else if (i == 5)////////////////////////////////////////////////////////                                           5
	{
		Oj oj3;
		oj3.print_Oj();
	}
	else if (i == 6)
	{
		Oj oj3 = oj1;
		oj3.print_Oj();
	}
	else if (i == 7)
	{
		int x3;
		cout << "x3" << endl;
		cin >> x3;
		Oj oj3(x3);
		oj3.print_Oj();
	}
	else if (i == 8 || i == 9)
	{
		if (oj1 != oj2)
			cout << "����" << endl;
		else if (oj1 == oj2)
			cout << "���" << endl;
	}
	else if (i == 10)
	{
		oj1.print_Oj();
	}
	else if (i == 11)
	{
		int d;
		cout << "������" << endl;
		cin >> d;
		Oj oj3 = oj1.upper(d);
		oj3.print_Oj();
	}
	else if (i == 12)
	{
		int q = oj1.get_real_n();
		cout << q << endl;
	}
	else if (i == 13)
	{
		int d;
		cout << "������" << endl;
		cin >> d;
		Oj oj3 = oj1.mul_bya(d);
		oj3.print_Oj();
	}
	else if (i == 14)
	{
		Oj oj3 = oj1 - oj2;
		oj3.print_Oj();
	}
	else if (i == 15)
	{
		Oj oj3 = oj1 + oj2;
		oj3.print_Oj();
	}
	else if (i == 16)
	{
		if (oj1 > oj2)
			cout << "oj1>oj2" << endl;
		else
			cout << "oj1<=oj2" << endl;
	}
	else if (i == 17)
	{
		Oj oj3 = oj1.Eured(oj2);
		oj3.print_Oj();
	}
	else if (i == 18)
	{
		cout << "an integer" << endl;
		cin >> x1;
		cout << "an integer" << endl;
		cin >> x2;
		cout << gcd(x1, x2) << endl;
	}
	else if (i == 19)
	{
		oj1.fix();
		oj1.print_Oj();
	}
	else
		cout << "default" << endl;
	return 0;
}//ÿдһ����һ��