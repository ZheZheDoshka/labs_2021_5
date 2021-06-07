// крипта1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream text("hyp.txt", ios::in | ios::binary);
	ofstream text2("hyp2.txt", ios::in | ios::binary);
	ofstream text3("hyp3.txt", ios::in | ios::binary);
	string str;
	int filt = 0;

	char m[35] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ";
	char M[35] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ ";

	for (char c; text.get(c); text3.put(c))
	{
		filt = 0;
		for (int i = 0; i < 34; i++)
		{
			if ((c == m[i]) || (c == M[i]))
			{
				filt = 1;
				continue;
			}
		}
		if (filt == 0)
		{
			c = ' ';
		}
	}

	int p[34];
	int d1[34][34];
	int d2[33][33];
	int d1_[34][34];
	int d2_[33][33];

	for (int i = 0; i < 34; i++) {
		for (int j = 0; j < 34; j++)
		{
			d1[i][j] = 0;
			if ((i < 33) && (j < 33))
			{ 
				d2[i][j] = 0; 
			}
		}
	}

	for (int i = 0; i < 34; i++) {
		for (int j = 0; j < 34; j++)
		{
			d1_[i][j] = 0;
			if ((i < 33) && (j < 33)) 
			{ 
				d2_[i][j] = 0; 
			}
		}
	}

	for (int i = 0; i < 34; i++) 
	{ 
		p[i] = 0;
	}
	text3.close();

	//подсчет символов

	ifstream text31("hyp3.txt", ios::in | ios::binary);
	int sp = 0;
	for (char c; text31.get(c); text2.put(c) )
	{
		for (int i = 0; i < 34; i++)
		{
			if ((c == m[i])||(c == M[i]))
			{
				if ((i == 33) && (sp == 1))
				{
					continue;
				}
				p[i]++;
				if (i != 33)
				{
					sp = 0; 
				}
				else 
				{ 
					sp = 1;
				}
			
				break;
			
			}
		}
	}


	double total=0;
	double total2 = 0;
	for (int i = 0; i < 33; i++)
		total = total + p[i];
	for (int i = 0; i < 34; i++)
		total2 = total2 + p[i];
	double pi[33];
	double pi_[34];
	for (int i = 0; i < 33; i++)
		pi[i]=p[i]/total;
	for (int i = 0; i < 34; i++)
		pi_[i] = p[i] / total2;
	for (int i = 0; i < 34; i++)
		cout << m[i]<<": " << p[i] << " ";
	long double H=0, H_=0;
	for (int i = 0; i < 33; i++)
	{
		if (pi[i] == 0)
		{
			continue;
		}
		H = H + pi[i] * (log(pi[i]) / log(2));
	}
	for (int i = 0; i < 34; i++)
	{
		if (pi_[i] == 0)
		{
			continue;
		}
		H_ = H_ + pi_[i] * (log(pi_[i]) / log(2));
	}

	cout << endl << "total without probel " << total<<endl;
	cout << "total with probel" << total2;
	H = H * (-1);
	H_ = H_ * (-1);
	cout<< endl <<"H = "<< H << endl<<"H_ = "<<H_;
	text31.close();
	int r = 0;

	ifstream text32("hyp3.txt", ios::in | ios::binary); //подсчет биграмм
	char a1;
	char a2;
	char b1;
	char b2;
	int k=0;
	int k1 = 1;
	int k2 = 1;
	double d1t=0, d1i=0;
	double d2t=0, d2i=0;
	for (char c; text32.get(c); text2.put(c))
	{
		if (k == 0)
		{
		k = 1;
		for (int i = 0; i < 33; i++)
		{
			if ((c == m[i]) || (c == M[i]))
			{
				a1 = i;
				a2 = i;
			}
		}
		for (int i = 0; i < 34; i++)
		{
			if ((c == m[i]) || (c == M[i]))
			{
				b1 = i;
				b2 = i;
			}
		}
		continue;
		}
		for (int i = 0; i < 33; i++)
		{
			if ((c == m[i]) || (c == M[i]))
			{
				d2[a1][i]++; 
				a1 = i; 
				d2t++;
				break;
			}
		}

		for (int i = 0; i < 34; i++)
		{
			if ((c == m[i]) || (c == M[i]))
			{
				if (b1 * i != 1089)
				{
					d1[b1][i]++;
					d1t++;
				}
				b1 = i;
				break;
			}
		}

		for (int i = 0; i < 33; i++)
		{
			if ((c == m[i]) || (c == M[i]))
			{
				if (k1 % 2 == 0)
				{

					d2_[a2][i]++;
					d2i++;
				}
				a2 = i; 
				k1++; 
				break;

			}
		}

		for (int i = 0; i < 34; i++)
		{
			if ((c == m[i]) || (c == M[i]))
			{
					if (k2 % 2 == 0)
					{
						if (b2 * i != 1089)
						{
							d1_[b2][i]++;
							d1i++;
						}
					}
					b2 = i; 
					k2++; 
					break;
			}
		}
	}


	string stroka = " ";
	ofstream file4;
	string abc = " ;";
	file4.open("table.csv");
	file4 << "Dvoyna s peresecheniyami bez probelov\n";
	for (int i = 0; i < 33; i++) {
		abc = abc + m[i] + ";";
		stroka = stroka+ m[i] + ";";
		for (int j = 0; j < 33; j++)
		{
			stroka = stroka + to_string(d2[i][j]) + ";";
		}
		stroka = stroka + "\n";
		file4 << stroka;
		stroka = " ";
	}
	abc = abc + "\n";
	file4 << abc;
	file4 << "Dvoyna s peresecheniyami s probelami\n";
	file4 << abc;
	for (int i = 0; i < 34; i++) {
		stroka = stroka + m[i] + ";";
		for (int j = 0; j < 34; j++)	
		{
			stroka = stroka + to_string(d1[i][j]) + ";";
		}
		stroka = stroka + "\n";
		file4 << stroka;
		stroka = " ";
	}

	file4 << "Dvoyna bez peresecheniy bez probelov\n";
	file4 << abc;
	for (int i = 0; i < 33; i++) {
		stroka = stroka + m[i] + ";";
		for (int j = 0; j < 33; j++)
		{
			stroka = stroka + to_string(d2_[i][j]) + ";";
		}
		stroka = stroka + "\n";
		file4 << stroka;
		stroka = " ";
	}
	file4 << "Dvoyna bez peresecheniy s probelami\n";
	file4 << abc;
	for (int i = 0; i < 34; i++) {
		stroka = stroka + m[i] + ";";
		for (int j = 0; j < 34; j++)
		{
			stroka = stroka + to_string(d1_[i][j]) + ";";
		}
		stroka = stroka + "\n";
		file4 << stroka;
		stroka = " ";
	}

	file4.close();


	double p2i[33][33];
	double p1i[34][34];
	double p2[33][33];
	double p1[34][34];
	for (int i = 0; i < 34; i++) {
		for (int j = 0; j < 34; j++)
		{
			p1i[i][j] = d1[i][j] / d1t;
			p1[i][j] = d1_[i][j] / d1i;
			if ((i < 33) && (j < 33)) {
				p2i[i][j] = d2[i][j] / d2t;
				p2[i][j] = d2_[i][j] / d2i;
			}
		}
	}
	double H2 = 0, H2_ = 0, H2i = 0, H2i_ = 0;
	for (int i = 0; i < 34; i++) {
		for (int j = 0; j < 34; j++)
		{
			if (p1[i][j] != 0) 
			{ 
				H2_ = H2_ + p1[i][j] * (log(p1[i][j]) / log(2));
			}
			if (p1i[i][j] != 0) 
			{ 
				H2i_ = H2i_ + p1i[i][j] * (log(p1i[i][j]) / log(2)); 
			}
			if ((i < 33) && (j < 33))
			{
				if (p2[i][j] != 0) 
				{ 
					H2 = H2 + p2[i][j] * (log(p2[i][j]) / log(2)); 
				}
				if (p2i[i][j] != 0) 
				{
					H2i = H2i + p2i[i][j] * (log(p2i[i][j]) / log(2)); 
				}
			}
		}
		}
	H2 = -H2/2; H2_ = -H2_/2; H2i = -H2i/2; H2i_ = -H2i_/2;
	cout << endl << "H2 - neperesek = " << H2;
	cout << endl << "H2_ - neperesek s prob = " << H2_;
	cout << endl << "H2i - peresek = " << H2i;
	cout << endl << "H2i_ - peresek s prob = " << H2i_;
	double R, Ri;
	double Hin = (2.7 + 3.1) / 2; //с розовой программки
	R = 1 - Hin / 5.121;
	cout << endl << "R = " << R;

	return 0;
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
