#include<iostream>
#include"Oj.h"
using namespace std;
void test()
{
	//int x1, x2,i;
	//cout << "请输入第一个多项式次数" << endl;
	//cin >> x1;
	//Oj oj1(x1);
	//cout << "请输入第二个多项式次数" << endl;
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
	//cout << "主程序：1  取余：2" << endl;
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
	cout << "功能测试" << endl;
	cout << "检测多项式是否为零：1" << endl
		<< "检测两多项式是否整除：2" << endl
		<< "将多项式第一项修为正数：3" << endl
		<< "两多项式取余式运算：4" << endl
		<< "多项式无参构造：5" << endl
		<< "多项式拷贝构造：6" << endl
		<< "多项式int参构造：7" << endl
		<< "多项式不等判断：8" << endl
		<< "多项式相等判断：9" << endl
		<< "打印多项式：10" << endl
		<< "多项式升幂：11" << endl
		<< "多项式转实n：12" << endl
		<< "多项式数乘运算：13" << endl
		<< "两多项式减法：14" << endl
		<< "两多项式加法：15" << endl
		<< "多项式比大小：16" << endl
		<< "求多项式最大公因式：17" << endl
		<< "最大公因数：18" << endl
		<< "约简多项式：19" << endl;
	cin >> i;
	int x1 = 0;
	int x2 = 0;
	cout << "请输入第一个多项式次数" << endl;
	cin >> x1;
	Oj oj1(x1);
	cout << "请输入第二个多项式次数" << endl;
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
			cout << "整除" << endl;
		else if (oj1.divisible(oj2) == false)
			cout << "不整除" << endl;
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
			cout << "不等" << endl;
		else if (oj1 == oj2)
			cout << "相等" << endl;
	}
	else if (i == 10)
	{
		oj1.print_Oj();
	}
	else if (i == 11)
	{
		int d;
		cout << "升幂数" << endl;
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
		cout << "数乘数" << endl;
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
}//每写一段试一段