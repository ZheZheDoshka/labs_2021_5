// крипта4TheNewHope.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct xi
{
	int x[1024];
	bool x2[1024];
};

int* boolform(int a);
xi generatorS(int x[]);
xi generatorY(int x[]);
xi s_generatorY(int x[]);
xi generatorX(int x[]);
xi s_generatorX(int x[]);
void boolform(int a, int xy[]);
void boolform2(int xy[]);
void boolform3(int xy[]);
xi geffe(xi x, xi y, xi s);

int n1 = 26, n2 = 27, n3 = 28;

int main()
{
	int x[26]= { 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,0 };
	//int x[26] = { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, };

	int y[27];
	int s[28]= { 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,0,0,0 };
	xi z, xs, ys, ss,zzz;
	ifstream text("var12.txt", ios::in | ios::binary);
	int N1, N2, N3;//=0.1; double N2 = 0.1; double N3 = 0.1;
	double C1; double C2; double C3;
	double a = 0.01;
	double ta = 2.35; //2.4?
	double tb1 = 5.42;//6.118;
		double tb2 = 5.55;//6.21;
		double tb3 = 5.66;//6.3;
		char zz;
		int R;

	N1= (tb1 + ta * sqrt(3) / 2)* (tb1 + ta * sqrt(3) / 2) *4; //222
	N2= (tb2 + ta * sqrt(3) / 2) * (tb2 + ta * (sqrt(3) / 2))*4; //230
	N3 =(tb3 + ta * sqrt(3) /2) * (tb3 + ta * (sqrt(3) / 2))*4; //236
	C1 = N1 / 4 + ta * sqrt(3) / 2; //58
	C2 = N2 / 4 + ta * sqrt(3) / 2; //60
	C3 = N3/ 4 + ta * sqrt(3) / 2; //62
	C2 = C2 + 2; //better?
	cout << C1 << " "<<C2 << " " <<C3<< " ";
	int zi = 0;
	while((text)&&(zi<1024))
	{
		text.get(zz);
		z.x[zi] = zz - '0';
		zi++;
	}
	ofstream L1;
	L1.open("L1.txt");
	ofstream L2;
	L2.open("L2.txt");
	for (int j = 1; j < 67108864; j++)//6522710 33554432?
	{
		boolform2(x);
		R = 0;
		xs = s_generatorX(x);
		for (int i = 0; i < N1; i++)
		{
			R = R + (xs.x[i] + z.x[i]) % 2;
		}
		if (R < C1) {
			for (int i = 0; i < n1; i++)
			{
				L1 << to_string(x[i]);
			}
			L1 << '\n';
		}
		for (int i = 0; i < 26; i++)
		{
			y[i] = x[i];
		}
		y[26] = 0;
		while (y[26] < 2) {
			ys = s_generatorY(y);
			R = 0;
			for (int i = 0; i < N2; i++)
			{
				R = R + (ys.x[i] + z.x[i]) % 2;
			}
			if (R < C2) {					//too big?
				for (int i = 0; i < n1; i++)
				{
					L2 << to_string(x[i]);
				}
				L2<<y[26];
				L2 << '\n';
			}
			y[26]++;
		}
	}
	
	L1.close();
	L2.close(); //вернуть! Убрать!*/
	string ex; string ey;
	int flag[1];
	int br;
	ofstream L3;
	L3.open("L3.txt");
		flag[0] = 0;
	ifstream L1c("L1.txt", ios::in | ios::binary);
	ifstream L2c("L2.txt", ios::in | ios::binary);
	int Lx[26][26];
	int Ly[27][27];
	int Ls[28][28];
	int xc = 0;
	int yc = 0;
	int sc = 0;
	while (getline(L1c, ex))
	{
		for (int i = 0; i < 26; i++)
		{
			Lx[i][xc] = int(ex[i] - '0');
			
		}
		xc++;
	}
	while (getline(L2c, ey))
	{
		for (int i = 0; i < 27; i++)
		{
			Ly[i][yc] = int(ey[i]-'0');
			
		}
		yc++;
	}
	xi xxs[10];
	xi xys[10];
	for (int i = 0; i < xc; i++)
	{
		for (int l = 0; l < 26; l++)
		{
			x[l] = Lx[l][i];
		}
		xxs[i] = generatorX(x);
	}
	for (int i = 0; i < yc; i++)
	{
		for (int l = 0; l < 26; l++)
		{
			y[l] = Ly[l][i];
		}
		xys[i] = generatorY(y);
	}
	int xc1 = 0;
	int yc1 = 0;
	fstream L3t;
	L3t.open("L3t.txt");
	for (int j = 0; j < 268435456; j++)
	{
		boolform3(s);
		xc1 = 0;
		while (xc1<xc) {
			yc1 = 0;
			while (yc1<yc) {
				br = 0;
				flag[0] = 0;
				for (int i = 0; i < 28; i++)
				{
					if (br == 1) { break; }
					if (xxs[xc1].x[i] != xys[yc1].x[i])
					{
						if (z.x[i] == xxs[xc1].x[i])
						{
							if (s[i] == 1)
							{
								flag[0]++;
							}
							else { flag[0] = 0; br = 1;  break; }
						}
						else {

							if (s[i] == 0)
							{
								flag[0]++;
							}
							else { flag[0] = 0; br = 1; break;  }
						}
					}	
				}
				if (flag[0] != 0)
				{
					for (int i = 0; i < n3; i++)
					{
						L3 << to_string(s[i]);
					}
					L3 << endl;
					sc++;
				}
				flag[0] = 0;
				yc1++;
			}
			xc1++;
		}
	}
	xi* sss = new xi[sc];
	L3.close();
	int ssc = 0;
	int count = 0;
	xi l1; xi l2; xi l3;
	ifstream L3c("L3.txt", ios::in | ios::binary);
	while (getline(L3c, ex))
	{
		for (int i = 0; i < 28; i++)
		{
			s[i] = int(ex[i] - '0');
		}
		sss[ssc] = generatorS(s);
		ssc++;
	}
	for (int i = 0; i < sc; i++)
	{
		for (int j = 0; j < yc; j++)
		{
			for (int k = 0; k < xc; k++)
			{
				count = 0;
				zzz = geffe(xxs[k], xys[j], sss[i]);
				for (int m = 0; m < N3; m++)
				{
					if (z.x[m] != zzz.x[m])
					{
						count = 0;  break;
					}
					else
					{
						count++;
					}
				}
				if (count > 1)
				{
					L3t << "L1: ";
					for (int o = 0; o < n1; o++)
					{
						L3t << to_string(xxs[k].x[o]);
					}
					l1 = xxs[k];
					l2 = xys[j];
					l3 = sss[i];
					L3t << '\n';
					L3t << "L2: ";
					for (int o = 0; o < n2; o++)
					{
						L3t << to_string(xys[j].x[o]);
					}
					L3t << '\n';
					L3t << "L3: ";
					for (int o = 0; o < n3; o++)
					{
						L3t << to_string(sss[i].x[o]);
					}
					L3t << '\n';
				}
			}
			
		}
	}
	zzz = geffe(l1, l2, l3);
	cout << endl << "z = "<<endl;
	for (int i = 0; i<1024; i++)
	{
		cout << z.x[i];
	}
	cout << endl << "z found = " << endl;
	for (int i = 0; i < 1024; i++)
	{
		cout << zzz.x[i];
	}
	cout << endl << "L1 = ";
	for (int i = 0; i < n1-1; i++)
	{
		cout << l1.x[i];
	}
	cout << endl << "L2 = ";
	for (int i = 0; i < n2-1; i++)
	{
		cout << l2.x[i];
	}
	cout << endl << "L3 = ";
	for (int i = 0; i < n3-1; i++)
	{
		cout << l3.x[i];
	}
}

xi geffe(xi x, xi y, xi s)
{
	xi z;
	for (int i = 0; i < 1024; i++)
	{
		z.x[i] = (s.x[i]*x.x[i] + ((1+s.x[i])%2)*y.x[i]) % 2;
	}
	return z;
}



xi generatorX(int x[] )
{
	xi x1;
	for (int i = 0; i < n1; i++)
	{
		x1.x[i] = x[i];
	}
	for (int i = 0; i < 1024-n1+1; i++)
	{
		x1.x[i + 25] = (x1.x[i] + x1.x[i +3])%2;
	}
	return x1;
}

xi s_generatorX(int x[])
{
	xi x1;
	for (int i = 0; i < n1; i++)
	{
		x1.x[i] = x[i];
	}
	for (int i = 0; i < 350 - n1 + 1; i++)
	{
		x1.x[i + 25] = (x1.x[i] + x1.x[i + 3]) % 2;
	}
	return x1;
}

xi generatorY(int x[])
{
	xi x1;
	for (int i = 0; i < n2; i++)
	{
		x1.x[i] = x[i];
	}
	for (int i = 0; i < 1024 - n2+1; i++)
	{
		x1.x[i + 26] = (x1.x[i] + x1.x[i + 1]+ x1.x[i + 2]+ x1.x[i+6])%2;
	}
	return x1;
}

xi s_generatorY(int x[])
{
	xi x1;
	for (int i = 0; i < n2; i++)
	{
		x1.x[i] = x[i];
	}
	for (int i = 0; i < 350 - n2 + 1; i++)
	{
		x1.x[i + 26] = (x1.x[i] + x1.x[i + 1] + x1.x[i + 2] + x1.x[i + 6]) % 2;
	}
	return x1;
}

xi generatorS(int x[])
{
	xi x1;
	for (int i = 0; i < n3; i++)
	{
		x1.x[i] = x[i];
	}
	for (int i = 0; i < 1024 - n3+1; i++)
	{
		x1.x[i + 27] = (x1.x[i] + x1.x[i + 1] + x1.x[i + 2] + x1.x[i + 5]) % 2;
	}
	return x1;
}


void boolform2(int xy[]) //что-бы вернуть массив
{
	for (int i = 25; i > -1; i=i)
	{
		if (xy[i] == 0)
		{
			xy[i] = 1;
			break;
		}
		else
		{
			while (xy[i] == 1)
			{
				xy[i] = 0;
				i -- ;
			}
		}
	}
}


void boolform3(int xy[]) //что-бы вернуть массив
{
	for (int i = 27; i > -1; i = i)
	{
		if (xy[i] == 0)
		{
			xy[i] = 1;
			break;
		}
		else
		{
			while (xy[i] == 1)
			{
				xy[i] = 0;
				i--;
			}
		}
	}
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
