// крипта3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

int obrat(int a, int b, int& u, int& v);
int gcd(int a, int b, int& u, int& v);

using namespace std;
int m = 31 * 31;

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream text("12.txt", ios::in | ios::binary);
	ofstream text2("junk.txt", ios::in | ios::binary);
	ofstream key_write;
	string abc = " ;";
	key_write.open("keys.txt");
	string keyin = "";
	string str;
	int filt = 0;
	double eps = 0.02;
	double p[31] = { 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0 };

	double p_c[31] = { 0.082958,0.017372,0.04663,0.018062,0.029658,0.08741,
			0.0113,0.016431,0.066482,0.010445,0.034384,0.050668,0.029172,0.069214,
			0.114348,0.024613,0.040003,0.052973,0.059914,0.027304,0.001055,0.007804,
			0.002746,0.016647,0.008697,0.002982,0.000279,0.018733 + 0.019896,0.003533,
			0.006345,0.021941 };
	int max[5] = { 0,0,0,0,0 }; int pi[5] = { 0,0,0,0,0 }, qi[5] = { 0,0,0,0,0 };
	int k1 = 0;
	int d2t=0;
	int a2;
	int u; int v;
	int rev = 15;
	double d2[31][31];
	char A[32] = "абвгдежзийклмнопрстуфхцчшщьыэюя"; //18,14
	char M[32] = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩьыЭЮЯ";
	char cou[20] = "тоноонсттснаенне";//тснаенне
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			d2[i][j] = 0;

		}
	}
	for (char c; text.get(c); text2.put(c))
	{
		for (int i = 0; i < 31; i++)
		{
			if ((c == A[i]) || (c == M[i]))
			{
				p[i]++;
				if (k1 % 2 == 1)
				{
					d2[a2][i]++;
					d2t++;
				}
				a2 = i;
				k1++;
				break;
			}
		}
	}
	/*u=obrat(rev, m, u, v);
	cout << u;*/


	/*for (int i = 0; i < 8; i++)
	{
		cout << xi[i] <<" ";
	}*/

	int a_r[961];			//a^-1
	for (int a = 1; a < 961; a++)
	{
		u = obrat(a, m, u, v);
		a_r[a] = (u + 961) % 961;
	}
	int pain[5] = { 0,0,0,0,0 };
	int painq[5] = { 0,0,0,0,0 };
	int painp[5] = { 0,0,0,0,0 };
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			for (int l = 0; l < 5; l++)
			{
				if (d2[i][j] > max[l])
				{
					for (int k = l; k < 5; k++) //tut
					{
						pain[k] = max[k];
						painq[k] = qi[k];
						painp[k] = pi[k];
					}
					for (int k = 1 + l; k < 4; k++)
					{
						max[k] = pain[k - 1];
						pi[k] = painp[k - 1];
						qi[k] = painq[k - 1];
					}
					max[l] = d2[i][j];
					pi[l] = i; qi[0] = j;
					break;
				}
			}
		}
	}
	cout << endl << "Самые частые: ";
	for (int i = 0; i < 5; i++)
	{
		cout << A[pi[i]] << A[qi[i]]<<" ";
	}
	cout << endl << "их номера: ";
	for (int i = 0; i < 5; i++)
	{
		cout <<max[i] << " ";
	}
	cout << endl;
	int x1, x2;
	int xi[10] = { 0,0,0,0,0,0,0,0,0,0 }; //Xi
	int yi[5];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			if (cou[2 * i] == A[j])
			{
				x1 = j;
			}
			if (cou[2 * i + 1] == A[j])
			{
				x2 = j;
			}
		}
		xi[i] = x1 * 31 + x2;
	}
	for (int i = 0; i < 5; i++) 
	{
		yi[i] = pi[i] * 31 + qi[i];
		cout << yi[i] << " ";
	}

	int keys[2];//костыль
	int keys_b[1024][2];
	int keys_count=0;
	int key_y, key_x, kx, ky, d=1, kn = 0, kl = 0, nkl=0, num = 0; //kl - костыль, kln - количество костылей
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i!=j)
			{ 
			key_x = (xi[i] - xi[j] + (961)) % 961;
			for (int i1 = 0; i1 < 5; i1++)
			{
				for (int i2 = 0; i2 < 5; i2++)
				{
					if(i1!=i2)
					{
					key_y = (yi[i1] - yi[i2] + (961)) % 961; //Ya^-1 = Xmod m^2 //a^-1 = X*Y^-1 mod m^2  
															 /* 	if (d > 1)
					{
						kx = key_x;
						ky = key_y;
						kx = kx / d; ky = ky / d;
						aa = a_r[(kx * a_r[ky] + 961) % 961];
						keys[0] = aa;
						keys[1] = (yi[i1] - xi[i] * keys[0] + 961 * 961) % 961;
						keyin = to_string(keys[0]) + " " + to_string(keys[1]) + "\n";
						key_write << keyin;
						keys_b[num][0] = keys[0];
						keys_b[num][1] = keys[1];
						num++;
					}
					else
					{
						aa = a_r[(kx * a_r[ky] + 961) % 961];
						keys[0] = aa; */
					kx = key_x;
					ky = key_y;
					d = gcd(ky, kx, u, v);
					for (int a = 0; a < 961; a++)
					{
						if (a % 31 != 0)
						{

							kx = key_x;
							ky = key_y;
							if (d > 1)
							{
								kx = key_x;
								ky = key_y;
								kx = kx / d; ky = ky / d;
								if (ky == (((kx * a) + 961) % 961))
								{
									keys[0] = a;
									keys[1] = (yi[i1] - xi[i] * keys[0] + 961 * 961) % 961;
									keyin = to_string(keys[0]) + " " + to_string(keys[1]) + "\n";
									key_write << keyin;
									keys_b[num][0] = keys[0];
									keys_b[num][1] = keys[1];
									num++;
								}
							}
							else
							{
								if (ky == (((kx * a) + 961) % 961))
								{
									keys[0] = a;
									keys[1] = (yi[i1] - xi[i] * keys[0] + 961 * 961) % 961;
									keyin = to_string(keys[0]) + " " + to_string(keys[1]) + "\n";
									key_write << keyin;
									keys_b[num][0] = keys[0];
									keys_b[num][1] = keys[1];
									num++;
								}
							}
						}
					}
					}
				}
			}
			}
		}
	}
	cout << num;
	char g, h;
	text.close();
	int Y, X, p1, q1, p2, q2;
	int a, b;
	ifstream text_b("12.txt");
	ofstream dec("decyph.txt");
	for (int o = 0; o < num; o++)
	{
		a = keys_b[o][0];
		b = keys_b[o][1];
		while (text_b.get(g) && text_b.get(h))
		{
			for (int i = 0; i < 31; i++)
			{
				if ((g == A[i]) || (g == M[i]))
				{
					p1 = i;
					break;
				}
			}
			for (int i = 0; i < 31; i++)
			{
				if ((h == A[i])||(h == M[i]))
				{
					q1 = i;
					break;
				}
			}
			Y = 31 * p1 + q1;
			X = (((Y - b) + 961) * a_r[a] + 961) % 961;
			p2 = (X / 31);
			q2 = X - p2 * 31;
			dec<<A[p2]<<A[q2];
		}
		dec << '\n';
		text_b.clear();
		text_b.seekg(0, ios::beg);
	}

	dec.close();
	text_b.close();
	text2.close();
	key_write.close();

	double p_d[31] = { 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0 };
	string line;
	int size;
	k1 = 0; d2t = 0;
	int d2_d[31][31];
	double check;
	int hm;
	int check2;
	ifstream dec_s("decyph.txt");
	ofstream dec2("decyph2.txt");
	while(getline(dec_s, line))
	{
		hm = 0;
		for (int i = 0; i < 31; i++)
		{
			for (int s = 0; s < 31; s++)
			{
				d2_d[i][s] = 0;

			}
		}
		for (int i = 0; i < 31; i++)
		{
			p_d[i] = 0;
		}
		k1 = 0; d2t = 0;
		size = line.length();
		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < 31; i++)
			{
				if ((line[j] == A[i]) || (line[j] == M[i]))
				{
					p_d[i]++;
					if (k1 % 2 == 1)
					{
						d2_d[a2][i]++;
						d2t++;
					}
					a2 = i;
					k1++;
					break;
				}
			}
		}
		check2 = 0;
		for (int s = 0; s < 31; s++)
		{
			
			check = double(p_d[s]) / double(k1);
			if ((check <= (p_c[s] + eps)) && (check >= (p_c[s] - eps)))
			{
				hm++;
			}
			
		}
		if (hm >=20)
		{
			dec2 << line;
			dec2 << '\n';
		}
	}
}

int obrat(int a, int b, int& u, int& v) 
{							
	if (a == 0) 
	{
		u = 0; v = 1;
		return b;
	}
	int u1, v1;
	int d = obrat(b % a, a, u1, v1); //а, понял. Не нравится мне это
	u = v1 - (b / a) * u1; //все, понял, это завуалированный обратный ход.
	v = u1; //страшная штука
	return u;
}

int gcd(int a, int b, int& u, int& v)
{							//почему и н*Ц879368247
	if (a == 0)
	{
		u = 0; v = 1;
		return b;
	}
	int u1, v1;
	int d = gcd(b % a, a, u1, v1); //а, понял. Не нравится мне это
	u = v1 - (b / a) * u1; //все, понял, это завуалированный обратный ход.
	v = u1; //страшная штука
	return d;
}

/*int reverse(int a) чертов обратный ход
{
	int k = 1;
	int r[50];
	int q[50];
	int r2;
	int i = 1;
	r[0] = m;
	r[1] = a;
	int r1 = m, r0 = a;
	int v, u = 0;
	while (k != 0)
	{
		q[i] = r[i - 1] / r[i];
		r[i + 1] = r[i - 1] - q[i] * r[i];
		k = r[i + 1];
	}
}*/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
