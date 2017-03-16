/*������ɶ���ʽ�����һ���࣬
���ǰ�������Oj�࣬
�������Ѿ�������һ��int�ͳ�Ա����m��Ϊ����ʽ�����ļ�¼��
����ʽ������Ȼ����n=m+1
���⻹��һ��int�͵�ָ�����ָ��һ��һά���飬
��������������n
�벻Ҫʹ���޲ι��캯������ֻ�ǽ��顣����

�ðɣ��ҳ������Լ����ˡ�����
*/

#pragma once
#include<iostream>
#include<cstring>
#include"test.h"
using namespace std;
class Oj
{
private:
	int *p;//ָ�����ʽϵ�������ָ��
	int m;//����ʽ�Ĵ���
	int n;//����ʽ������
	
	
	
	Oj()
	{
		n = 0;
		m = 0;
		p = NULL;
	}
	
	
	
	Oj(int d)//ָ���������ɼ�������ϵ���Ĺ��캯��
	{
		m = d;
		n = d + 1;
		p = new int[n];
		for (int i = 0;i < n;i++)
		{
			cout << "�������" << i << "����ϵ��" << endl;
			cin >> p[i];
		}
	}
	
	
	
	Oj(const Oj &oji)//�������캯��/////////////////////////////�������������oji������oj1���������Ÿ���һ�ε�ʱ���Ϲд
	////////////////////////////////////////////////////////////���У����ǲ��ǵ�����Ԥ�ϵ���Ҫ����һ�Σ�Ҫ��Ȼ��ôֻ��������oji������
	{
		n = oji.n;
		m = oji.m;
		p = new int[oji.n];
		for (int i = 0;i < oji.n;i++)
			p[i] = oji.p[i];
	}



	/*~Oj()//��������
	{
		n = 0;
		delete[]p;
	}///////////////////////////////////////////////�Ժ����������������ˡ�����������������������������*/
	
	
	
	void print_Oj()const//����ʽ���ʵ��
	{
		for (int i = 0;i<get_real_n();i++)
			cout << p[i] << "*x^" << i << "+" << endl;
		cout << "end" << endl;
	}
	

	
	Oj operator+(const Oj &oj1)const//�ӺŲ���������
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



	Oj operator-(const Oj &oj1)const//���Ų���������
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



	int get_real_n()const//��ö���ʽ�����ĳ���
	{
		int i1 = n;
		for (int i = n;i >= 1 && p[i - 1] == 0;i--)
			i1--;
		return i1;
	}



	/*bool operator>(const Oj oj1)const//�Ƚ϶���ʽ�������ȵĴ�С
	{
		return (get_real_n() > oj1.get_real_n());
	}*///�������룬���ǵ��ؼ������е����ò�ֹ�ڴˣ��Ҵ�������дһ��������أ��������£�


	bool operator>(const Oj oj1)const//������ʽ��С�Ƚϣ�ʵ��������ֵ���
	{
		int n = get_real_n();
		int n1 = oj1.get_real_n();
		if (n != n1)
			return (n > n1);
		else
			return (p[n] > oj1.p[n1]);
	}
	

	
	Oj mul_bya(const int a)const//����ʽ���������ʵ��
	{
		Oj oj1 = *this;
		for (int i = 0;i < get_real_n();i++)
			oj1.p[i] *= a;
		return oj1;
	}
	
	
	
	/*Oj div_byOj(const Oj &oj1)const//����ʽ��һ�²�����������׼ȷ��˵�Ƿ��������ʽ��
	{
		if (n > oj1.n)
		{
			int d = n - oj1.n;
			Oj ojd = *this;
			for (int q = n - 1;q >= oj1.n;q--)
				ojd.p[q] = ;
			return ojd;/////////////////////////////////////////////////////////////////////////��ûд�꣬�ȱ���
		}
	}*///���ˣ��һ�������дһ�ΰ�
	
	
	
	Oj upper(const int num)const//����ʽ��������
	{
		Oj oj1;
		oj1.n = get_real_n() + num;
		oj1.m = oj1.n - 1;
		oj1.p = new int[oj1.n];
		for (int i = 0;i < num;i++)
			oj1.p[i] = 0;
		for (int i = num;i < oj1.n;i++)//�����������Űѵ��ں�ȥ����Ȼ����һ�¿����������ܷ��������С�
			//���ڱ��ҷ����ˣ�������oj1.n������n
			//������ԭ���������<=���<�ˣ���˵Ϊɶ�����ء�����//��һ�£�����Ϊʲô����<=������<?
			oj1.p[i] = p[i - num];
		//for (int i = 0;i < n;i++)
			//if (oj1.p[i] = -6.27744e+66)
				//oj1.p[i] = 1;
		return oj1;
	}
	

	
	Oj mod_Oj(const Oj oj1)const//����ʽ���Զ���ʽʱ��ȡ������
	{
		if (get_real_n() > oj1.get_real_n())////////////////////////////////////////////////////////////�߼�����
					  //���t��Ӧ���Ǽ򵥵�n ֮�
					  //׼ȷ��˵����Ӧ�������жϴ���һ�ʼ����
					  //����������ֵĲ�ֵ
					  //�����ҵ���������
					  //���ڶ���һ����������Ѱ��������ְɣ����ǽ��ᾭ��������
		{
			//int t = p[get_real_n() - 1] / oj1.p[oj1.get_real_n() - 1];//�Ұ�double������int�� ��������һ�£���������ٻ��������о�������������ˡ�
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
			//int t = oj1.p[oj1.get_real_n() - 1] / p[get_real_n() - 1];//�Ұ�double������int�� ��������һ�£���������ٻ��������о�������������ˡ�
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
	
	
	
	bool check_Oj()const//�ж϶���ʽ�Ƿ�Ϊ�㣬����Ƿ��ش��󣬷��򷵻���
	{
		{
			int i = 0;
			for (int t = 0;t < n;t++)
			{
				if (p[t] != 0)
					return false;
			}
		}
		return true;//�����Ǹ��Ĺ������ֵ��ԭ���Ƿ��㷵��-1���㷵���㣬�����Ƿ��㷵��FALSE���㷵��TRUE��

	}


	bool operator==(const Oj oj1)const//�ж�������ʽ��ȵ�==����
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


	bool operator!=(const Oj oj1)const//������ʽ�����ж�
	{
		return !(*this == oj1);
	}


	/*void fix()//��������ʽ�ĵ�һ��Ϊ�Ǹ���//�����޸�һ��fix�����������ĳɿ���Լ�����ʽ�ĺ���
	{
		for (int i = 0;i < n;i++)
			p[i] = (p[get_real_n()] >= 0) ? p[i] : (-p[i]);
	}*/


	void fix()//������ʽ��Լ��ʵ��
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



	/*bool divisible(const Oj oj1)const//�ж�������ʽ�Ƿ�����
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
			double time = p[index-1] / oj1.p[index-1];//��Ȼ��������int�ǶԳ�����յġ�������Ȼ�����Ҳ�����ȡ��ֱ��Ū����
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
	
	
	
	/*bool operator>(const Oj &oj1)const//������>�����أ������ж���������ʽ�ӷ�������Ĵ�����С��ԭ�棩
	{
		int i1 = n;
		int i2=oj1.n;
		for (int i = n;p[i - 1] == 0 && i >= 1;i--)
		{
			i1--;
		}
		for (int i = oj1.n;oj1.p[i - 1] == 0 && i >= 1;i--)
			//֮ǰ������������⣬��Ӧ����ÿ��i�Լ�Ȼ��ֵ��i1����Ӧ�ø�i1����ֵ����i1�Լ�
		{
			i2--;
		}
		return (i1 > i2);
	}*/
	

	
	Oj Eured(const Oj oj1)const/////////////////////////////////////////////////////////////////////////ŷ������㷨
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


	friend class EU_TEST;/////////////////////��Ԫ���Ժ�������


};////////////////��ûд�꣬��������<���ˣ������ز�ʵ��֮���ٸ㡣�õ�<д��
/*
�����������������ʵ�ֵģ�
���������������¡�����
��Ҳ�Ƕ��ã�
�����һ����ö�̬����ɡ�


-6.27744e+66��֮���ֳ�����ʲô�����������ҿ�Ҫ����


����������δ���壬С��Խ��֮�����Ժ�Ҫ�ǵã�������


���⣬����һ�㶼��������������ʽ�Ĺ���ʽ��
Ҳ���÷�����ϵ������ȷһЩ��
����ʹ��double��ϵ��ȷʵû��ô���㣬
����һ�뵽�÷��������ٶ���һ�������������
�����з��ӣ���ĸ��Լ�򣬷�ĸ��1����ת��intʲô��
���뻹���´ΰɣ����Ȱ�����뷨ʵ������˵�ɡ�����


��֪�������ֳ��˴��󣬴�����������԰ɡ���


�������Ǵ�������ĳЩ�Ѿ��ͷŵ��ڴ��ڻ����-572662307������֣��ҵ����ҡ�


�Ұ���������ע�͵��ˣ����񲻳����Ǹ������ˣ�������ֽ���ˣ������һ��������ԣ���Ϊ�����������һ�£���������һ��С���󡣡�������
���ϻ����ġ�


����ʶ��Ϊ��ʹ���������һЩ��printҲ�ø�һ����*/