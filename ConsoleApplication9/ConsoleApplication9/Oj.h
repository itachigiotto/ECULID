/*这是完成多项式运算的一个类，
我们把它叫做Oj类，
其中我已经定义了一个int型成员变量m作为多项式次数的记录，
多项式项数自然就是n=m+1
另外还有一个int型的指针变量指向一个一维数组，
这个数组的项数是n
请不要使用无参构造函数，我只是建议。。。

好吧，我承认我自己用了。。。
*/

#pragma once
#include<iostream>
#include<cstring>
#include"test.h"
using namespace std;
class Oj
{
private:
	int *p;//指向多项式系数数组的指针
	int m;//多项式的次数
	int n;//多项式的项数
	
	
	
	Oj()
	{
		n = 0;
		m = 0;
		p = NULL;
	}
	
	
	
	Oj(int d)//指定次数并由键盘输入系数的构造函数
	{
		m = d;
		n = d + 1;
		p = new int[n];
		for (int i = 0;i < n;i++)
		{
			cout << "请输入第" << i << "次项系数" << endl;
			cin >> p[i];
		}
	}
	
	
	
	Oj(const Oj &oji)//拷贝构造函数/////////////////////////////看清楚，这里是oji，不是oj1，自作主张改这一段的时候别瞎写
	////////////////////////////////////////////////////////////还有，我是不是当初就预料到我要改这一段，要不然怎么只有这里是oji。。。
	{
		n = oji.n;
		m = oji.m;
		p = new int[oji.n];
		for (int i = 0;i < oji.n;i++)
			p[i] = oji.p[i];
	}



	/*~Oj()//析构函数
	{
		n = 0;
		delete[]p;
	}///////////////////////////////////////////////以后别随便用析构函数了。！！！！！！！！！！！！！！*/
	
	
	
	void print_Oj()const//多项式输出实现
	{
		for (int i = 0;i<get_real_n();i++)
			cout << p[i] << "*x^" << i << "+" << endl;
		cout << "end" << endl;
	}
	

	
	Oj operator+(const Oj &oj1)const//加号操作符重载
	{
		if (n < oj1.n)
		{
			Oj oj2 = oj1;
			for (int r = 0;r < n;r++)
				oj2.p[r] += p[r];
			return oj2;
		}
		else
		{
			Oj oj3 = *this;
			for (int r = 0;r < oj1.n;r++)
				oj3.p[r] += oj1.p[r];
			return oj3;
		}

	}



	Oj operator-(const Oj &oj1)const//减号操作符重载
	{
		if (n < oj1.n)
		{
			Oj oj2 = oj1;
			for (int r = 0;r < n;r++)
				oj2.p[r] -= p[r];
			return oj2;
		}
		else
		{
			Oj oj3 = *this;
			for (int r = 0;r < oj1.n;r++)
				oj3.p[r] -= oj1.p[r];
			return oj3;
		}
	}



	int get_real_n()const//获得多项式真正的长度
	{
		int i1 = n;
		for (int i = n;i >= 1 && p[i - 1] == 0;i--)
			i1--;
		return i1;
	}



	/*bool operator>(const Oj oj1)const//比较多项式真正长度的大小
	{
		return (get_real_n() > oj1.get_real_n());
	}*///我想了想，考虑到关键函数中的运用不止于此，我打算重新写一遍这个重载，具体如下：


	bool operator>(const Oj oj1)const//两多项式大小比较，实长，首项，字典序
	{
		int n = get_real_n();
		int n1 = oj1.get_real_n();
		if (n != n1)
			return (n > n1);
		else
			return (p[n] > oj1.p[n1]);
	}
	

	
	Oj mul_bya(const int a)const//多项式数乘运算的实现
	{
		Oj oj1 = *this;
		for (int i = 0;i < get_real_n();i++)
			oj1.p[i] *= a;
		return oj1;
	}
	
	
	
	/*Oj div_byOj(const Oj &oj1)const//多项式除一下并返回余数（准确地说是返回余多项式）
	{
		if (n > oj1.n)
		{
			int d = n - oj1.n;
			Oj ojd = *this;
			for (int q = n - 1;q >= oj1.n;q--)
				ojd.p[q] = ;
			return ojd;/////////////////////////////////////////////////////////////////////////还没写完，先别用
		}
	}*///算了，我还是重新写一段吧
	
	
	
	Oj upper(const int num)const//多项式升幂运算
	{
		Oj oj1;
		oj1.n = get_real_n() + num;
		oj1.m = oj1.n - 1;
		oj1.p = new int[oj1.n];
		for (int i = 0;i < num;i++)
			oj1.p[i] = 0;
		for (int i = num;i < oj1.n;i++)//现在我先试着把等于号去掉，然后试一下看升幂运算能否正常运行。
			//终于被我发现了，这里是oj1.n而不是n
			//嘻嘻，原来是这里把<=打成<了，我说为啥出怪呢。。。//等一下，这里为什么会是<=而不是<?
			oj1.p[i] = p[i - num];
		//for (int i = 0;i < n;i++)
			//if (oj1.p[i] = -6.27744e+66)
				//oj1.p[i] = 1;
		return oj1;
	}
	

	
	Oj mod_Oj(const Oj oj1)const//多项式除以多项式时的取余运算
	{
		if (get_real_n() > oj1.get_real_n())////////////////////////////////////////////////////////////逻辑错误，
					  //这里，t不应该是简单的n 之差，
					  //准确的说我们应该先行判断从哪一项开始非零
					  //再算这个数字的差值
					  //终于找到啦！！！
					  //现在定义一个函数用来寻找这个数字吧，我们将会经常调用它
		{
			//int t = p[get_real_n() - 1] / oj1.p[oj1.get_real_n() - 1];//我把double换成了int， 现在先试一下，如果不行再换回来，感觉就是这里出错了。
			int d = get_real_n() - oj1.get_real_n();
			//cout << d << endl;
			Oj oj2 = oj1.upper(d);
			//oj2.print_Oj();
			Oj oj3 = oj2.mul_bya(p[get_real_n()-1]);
			//oj3.print_Oj();
			Oj oj4 = mul_bya(oj1.p[oj1.get_real_n() - 1]);
			//oj4.print_Oj();
			Oj oj5 = oj3 - oj4;
			return oj5;
		}
		else if (get_real_n() < oj1.get_real_n())
		{
			//int t = oj1.p[oj1.get_real_n() - 1] / p[get_real_n() - 1];//我把double换成了int， 现在先试一下，如果不行再换回来，感觉就是这里出错了。
			int d = oj1.get_real_n() - get_real_n();
			//cout << d << endl;
			Oj oj2 = upper(d);
			//oj2.print_Oj();
			Oj oj3 = oj2.mul_bya(oj1.p[oj1.get_real_n()-1]);
			//oj3.print_Oj();
			Oj oj4 = oj1.mul_bya(p[get_real_n()-1]);
			//oj4.print_Oj();
			Oj oj5 = oj4 - oj3;
			return oj5;
		}
		else
		{
			Oj oj3 = oj1.mul_bya(p[get_real_n() - 1]);
			Oj oj4 = mul_bya(oj1.p[oj1.get_real_n() - 1]);
			Oj oj5 = oj3 - oj4;
			return oj5;
		}
	}
	
	
	
	bool check_Oj()const//判断多项式是否为零，如果是返回错误，否则返回零
	{
		{
			int i = 0;
			for (int t = 0;t < n;t++)
			{
				if (p[t] != 0)
					return false;
			}
		}
		return true;//这里是更改过的输出值，原来是非零返回-1，零返回零，现在是非零返回FALSE，零返回TRUE。

	}


	bool operator==(const Oj oj1)const//判断两多项式相等的==重载
	{
		if (n > oj1.n)
		{
			for (int i = 0;i < oj1.n;i++)
			{
				if (p[i] != oj1.p[i])
					return false;
			}
			for (int i = oj1.n;i < n;i++)
			{
				if (p[i] != 0)
					return false;
			}
		}
		else
		{
			for (int i = 0;i < n;i++)
			{
				if (p[i] != oj1.p[i])
					return false;
			}
			for (int i = n;i < oj1.n;i++)
			{
				if (oj1.p[i] != 0)
					return false;
			}

		}
		return true;
	}


	bool operator!=(const Oj oj1)const//两多项式不等判断
	{
		return !(*this == oj1);
	}


	/*void fix()//修正多项式的第一项为非负数//决定修改一下fix函数，把它改成可以约简多项式的函数
	{
		for (int i = 0;i < n;i++)
			p[i] = (p[get_real_n()] >= 0) ? p[i] : (-p[i]);
	}*/


	void fix()//将多项式的约简实现
	{
		int *p1,*p2;
		p1 = NULL;
		p2 = NULL;
		p2 = new int[get_real_n()];
		for (int i = 0;i < get_real_n();i++)
			p2[i] = p[i];
		for (int index = get_real_n() - 1;index > 0;index--)
		{
			p1 = new int[index + 1];
			for (int i = 0;i < index + 1;i++)
				p1[i] = p2[i];
			for (int i = 0;i < index;i++)
				p2[i] = gcd(p1[i], p1[i + 1]);
		}
		int d = p2[0];
		for (int i = 0;i < get_real_n();i++)
			p[i] /= d;
	}



	bool divisible(const Oj oj1)const
	{
		Oj oj2 = oj1.mod_Oj(*this);
		return (oj2.check_Oj() == true);
	}



	/*bool divisible(const Oj oj1)const//判断两多项式是否整除
	{
		int r = 0;
		int e = 0;
		if (check_Oj() == true || oj1.check_Oj() == true)
		{
			cout << "o0 o0" << endl;
			return true;
		}
		else if (get_real_n() != oj1.get_real_n())
		{
			cout << "!=" << endl;
			return false;
		}
		else
		{
			int index = get_real_n();
			double time = p[index-1] / oj1.p[index-1];//居然忘了这里int是对除法封闭的。。。既然这样我不如用取余直接弄算了
			cout << p[index - 1] << "  " << oj1.p[index - 1];
			cout << "time is" << time << endl;
			for (int k = index-1;k >= 0;k--)
			{
				cout << p[k] << "  " << oj1.p[k] << endl;
				if (p[k] == 0 && oj1.p[k] == 0)
					continue;
				else if (p[k] == 0 && oj1.p[k] != 0)
				{
					return false;
				}
				else if (p[k] != 0 && oj1.p[k] == 0)
				{
					return false;
				}
				else
					if (p[k] / oj1.p[k] != time)
					{
						return false;
					}
					else
						e++;		

			}
				return true;
		}
	}*/
	
	
	
	/*bool operator>(const Oj &oj1)const//操作符>号重载，用于判断两个多项式从非零项起的次数大小（原版）
	{
		int i1 = n;
		int i2=oj1.n;
		for (int i = n;p[i - 1] == 0 && i >= 1;i--)
		{
			i1--;
		}
		for (int i = oj1.n;oj1.p[i - 1] == 0 && i >= 1;i--)
			//之前是这里出了问题，不应该用每次i自减然后赋值给i1，而应该给i1赋初值再让i1自减
		{
			i2--;
		}
		return (i1 > i2);
	}*/
	

	
	Oj Eured(const Oj oj1)const/////////////////////////////////////////////////////////////////////////欧几里得算法
	{
		Oj ojf = *this;
		Oj ojs = oj1;
		//int index = 0;
		while (ojf.divisible(ojs) == false&&ojf.check_Oj() != true && ojs.check_Oj() != true/*&&index<=get_real_n()+oj1.get_real_n()*/)
		{
			if (ojf > ojs)
			{
				//cout << "          "<<index << endl;
				//ojf.print_Oj();
				//ojs.print_Oj();
				ojf = ojs.mod_Oj(ojf);
				//ojf.print_Oj();
				ojf.fix();
				//ojf.print_Oj();
				//index++;
				//cout << ">" << endl;
			}
			else
			{
				//cout << "          "<<index << endl;
				//ojs.print_Oj();
				//ojf.print_Oj();
				ojs = ojs.mod_Oj(ojf);
				//ojs.print_Oj();
				ojs.fix();
				//ojs.print_Oj();
				//index++;
				//cout << "<=" << endl;
			}
		}//cout << "babalala" << endl;
		if (ojs.check_Oj() == true)
		{
			return ojf;
			//cout << "baba" << endl;
		}
		else
		{
			return ojs;
			//cout << "lala" << endl;
		}
		//cout << "balabala" << endl;
		return 0;
		//cout << "please stop it" << endl;
	}


	int gcd(int a, int b);


	friend class EU_TEST;/////////////////////友元测试函数声明


};////////////////还没写完，忘了重载<号了，先重载并实验之后再搞。好的<写了
/*
本来有想过用链表来实现的，
但是敲链表这种事。。。
你也是懂得，
于是我还是用动态数组吧。


-6.27744e+66迷之数字出现是什么东西。。。我快要疯了


、、、、、未定义，小标越界之谬误，以后要记得！！！！


另外，我们一般都是求有理数多项式的公因式，
也许用分数做系数更精确一些，
并且使用double做系数确实没那么方便，
但是一想到用分数还得再定义一个类出来。。。
分数有分子，分母，约简，分母是1还得转成int什么的
想想还是下次吧，我先把这个想法实现了再说吧。。。


不知道哪里又出了错误，待会儿再来调试吧。。


看来我是触及到了某些已经释放的内存在会出现-572662307这个数字，我得找找。


我把析构函数注释掉了，好像不出现那个数字了，好像出现结果了，但是我还得再试试，因为它好像多算了一下，因此造成了一点小错误。。。。。
马上回来改。


我意识到为了使得输出美观一些，print也该改一下了*/