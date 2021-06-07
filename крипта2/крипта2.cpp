// крипта2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	ofstream text2("t2.txt", ios::in | ios::binary);
	char m[33] = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
	/*string k2 = "аб";
	string k3 = "том";*/
	int k2[2] = { 0,1 }; //aб
	int k3[3] = { 18,14,12 }; //том
	int k4[4] = { 15,0,24,0 }; //паша
	int k5[5] = { 15,11,5,18,28 }; //плеть
	int k10[10] = { 15,11,5,18,28,14,16,4,0,5 }; //плетьордае
	int k12[12] = { 2,14,17,11,0,2,19,15,11,5,18,8 };//вославуплети
	int k20[20] = { 2,14,17,11,0,2,19,15,11,5,18,8,8,14,16,4,27,18,14,12 };//вославуплетииордытом
	int v[32][21];
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 21; j++)
		{
			v[i][j] = 0;
		}
	}
	double Ir[21];
	for (int i = 0; i < 21; i++)
	{
		Ir[i] = 0;
	}

	int sp = 0, size = 0;
	ifstream text("t1.txt", ios::in | ios::binary); //кодируем + считаем количество всего что есть
	for (char c; text.get(c); text2.put(c))
	{
		for (int i = 0; i < 32; i++)
		{
			if (c == m[i])
			{
				c = m[(i + k2[sp]) % 32];
				v[(i + k2[sp]) % 32][2]++;
				v[i][0]++;
				size++;
				sp = (sp + 1) % 2;
				break;
			}
		}
	}
	text2 << "\n";
	text.close();
	sp = 0;
	ifstream text3("t1.txt", ios::in | ios::binary);
	for (char c; text3.get(c); text2.put(c))
	{
		for (int i = 0; i < 32; i++)
		{
			if (c == m[i])
			{
				c = m[(i + k3[sp]) % 32];

				v[(i + k3[sp]) % 32][3]++;
				sp = (sp + 1) % 3;
				break;
			}
		}
	}
	text2 << "\n";
	text3.close();


	sp = 0;
	ifstream text4("t1.txt", ios::in | ios::binary);
	for (char c; text4.get(c); text2.put(c))
	{
		for (int i = 0; i < 32; i++)
		{
			if (c == m[i])
			{
				c = m[(i + k4[sp]) % 32];

				v[(i + k4[sp]) % 32][4]++;
				sp = (sp + 1) % 4;
				break;
			}
		}
	}
	text2 << "\n";
	text4.close();


	sp = 0;
	ifstream text5("t1.txt", ios::in | ios::binary);
	for (char c; text5.get(c); text2.put(c))
	{
		for (int i = 0; i < 32; i++)
		{
			if (c == m[i])
			{
				c = m[(i + k5[sp]) % 32];

				v[(i + k5[sp]) % 32][5]++;
				sp = (sp + 1) % 5;
				break;
			}
		}
	}
	text2 << "\n";
	text5.close();

	sp = 0;
	ifstream text10("t1.txt", ios::in | ios::binary);
	for (char c; text10.get(c); text2.put(c))
	{
		for (int i = 0; i < 32; i++)
		{
			if (c == m[i])
			{
				c = m[(i + k10[sp]) % 32];
				v[(i + k10[sp]) % 32][10]++;
				sp = (sp + 1) % 10;
				break;
			}
		}
	}
	text2 << "\n";
	text10.close();

	sp = 0;
	ifstream text12("t1.txt", ios::in | ios::binary);
	for (char c; text12.get(c); text2.put(c))
	{
		for (int i = 0; i < 32; i++)
		{
			if (c == m[i])
			{
				c = m[(i + k12[sp]) % 32];
				v[(i + k12[sp]) % 32][12]++;
				sp = (sp + 1) % 12;
				break;
			}
		}
	}
	text2 << "\n";
	text12.close();

	sp = 0;
	ifstream text20("t1.txt", ios::in | ios::binary);
	for (char c; text20.get(c); text2.put(c))
	{
		for (int i = 0; i < 32; i++)
		{
			if (c == m[i])
			{
				c = m[(i + k20[sp]) % 32];

				v[(i + k20[sp]) % 32][20]++;
				sp = (sp + 1) % 20;
				break;
			}
		}
	}
	text2 << "\n";
	text20.close();

	text2.close();

	double k = 0;
	for (int i = 0; i < 21; i++)  //подсчет I для закодированных сообщений
	{
		k = 0;
		for (int j = 0; j < 32; j++)
		{
			k = k + (v[j][i] * (v[j][i] - 1));
		}
		Ir[i] = k / (size * (size - 1));
	}

	for (int i = 0; i < 21; i++)
	{
		if ((i == 0) || (i == 2) || (i == 3) || (i == 4) || (i == 5) || (i == 10) || (i == 12) || (i == 20))
		{
			cout << "I" << i << " = " << Ir[i] << endl;
		}
	}

	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 21; j++)
		{
			v[i][j] = 0;
		}
	}
	size = 0;
	char C[31];
	int D[31];
	sp = 0;
	int flag = 0;
	for (int j = 0; j < 31; j++)
	{
		D[j] = 0;
	}

	int si[30] = { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0 }; //размеры У1, У2, У3, У4, У5. Ноль тут что бы ничего не сломалось
	ifstream cyf("cyf1.txt", ios::in | ios::binary);
	ofstream junk("cyf2.txt", ios::in | ios::binary);
	char a[30][30];
	int frst = 0;
	char db;
	flag = 0;
	int first[30] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 };
	for (char c; cyf.get(c); junk.put(c))
	{
		for (int i = 0; i < 32; i++)
		{
			if (c == m[i])					///ошибка доступа к памяти ТОЛЬКО в циклах фор снизу?
			{
				db = c;
				if (frst<30) {
					for (int j = 6; j < 30; j++)
					{
						//if (first[j] >= 0)
						//{

						a[frst][j] = db;
						first[j]--;
						//}
						
					}
					frst++;
				}

				for (int j = 6; j < 30; j++)
				{
					if (first[j]<=0)
					{
						if (a[size % j][j] == db)
						{
							D[j]++;
						}
						else
						{
							a[size % j][j] = db;
						}
					}
				}
				v[i][0]++;
				size++;
				break;
			}
		}
	}
	double Irc;
	k = 0;
	for (int j = 0; j < 32; j++)
	{
		k = k + (v[j][0] * (v[j][0] - 1));
	}
	Irc = k / (size * (size - 1)); //I шифротекста
	cout << "Ir cyfer" << " = " << Irc;
	if (Irc < Ir[5])
	{
		cout << " Ir < I5 => r=?";
	}
	cout << endl;

	for (int j = 5; j < 31; j++)
	{
		cout << "D" << j << " = " << D[j] << endl;
	}

	int max = D[0];
	int r = 0;
	for (int j = 5; j < 31; j++)
	{
		if (D[j] > max)
		{
			max = D[j];
			r = j;
		}
	}
	junk.close();
	cyf.close();

	ifstream cyf3("cyf1.txt", ios::in | ios::binary);
	cout << "r = " << r << endl;

	for (char c; cyf3.get(c); junk.put(c))
	{
		for (int i = 0; i < 32; i++)
		{
			if (c == m[i])					///ошибка доступа к памяти ТОЛЬКО в циклах фор снизу?
			{
				v[i][(size % r) + 1]++;
				si[(size % r)]++;
				size++;
				break;
			}
		}
	}

	double p[32] = { 0.082958,0.017372,0.04663,0.018062,0.029658,0.08741,
		0.0113,0.016431,0.066482,0.010445,0.034384,0.050668,0.029172,0.069214,
		0.114348,0.024613,0.040003,0.052973,0.059914,0.027304,0.001055,0.007804,
		0.002746,0.016647,0.008697,0.002982,0.000279,0.018733,0.019896,0.003533,
		0.006345,0.021941 };
	double M[30] = { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0 };
	double b=0;
	int maxim[30] = {0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0 };
	for (int k = 0; k < r; k++)
	{
		b = 0;
		for (int i = 0; i < 32; i++)
		{
			M[k] = 0;
			for (int j = 0; j < 32; j++)
			{
				M[k] = M[k] + p[j] * v[(j + i) % 32][k+1];
			}
			if (M[k] >= b)
			{
				b = M[k];
				maxim[k] = i;
			}
		}
		cout << "M" << k+1 << " max = " << b << endl;
		cout << "i = " << maxim[k] << endl;

	}
	if (maxim[0] == 9)
	{
		for (int k = 0; k < r; k++)
		{
			cout << m[maxim[(k+6)%r]];
		}
		cout << endl;

		ifstream cyf2("cyf2.txt", ios::in | ios::binary);
		ofstream dec("dec.txt", ios::in | ios::binary);
		size = 0;
		for (char c; cyf2.get(c); dec.put(c))
		{
			for (int i = 0; i < 32; i++)
			{
				if (c == m[i])
				{
					c = m[((i + 32 - maxim[(size+6) % r])) % 32];
					size++;
					break;
				}
			}
		}
	}
	else {
		for (int k = 0; k < r; k++)
		{
			cout << m[maxim[k]];
		}
		cout << endl;
		int temp;
		int temporal;

		ifstream cyf2("cyf2.txt", ios::in | ios::binary);
		ofstream dec("dec.txt", ios::in | ios::binary);
		size = 0;
		for (char c; cyf2.get(c); dec.put(c))
		{
			for (int i = 0; i < 32; i++)
			{
				if (c == m[i])
				{
					c = m[((i + 32 - maxim[size % r])) % 32];
					size++;
					break;
				}
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
