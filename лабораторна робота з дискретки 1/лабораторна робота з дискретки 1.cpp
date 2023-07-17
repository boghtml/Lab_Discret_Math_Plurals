// лабораторна робота з дискретки 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include <stdlib.h>
#include <ctime>
#include<cmath>
using namespace std;
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	char P;
	do {
		cout << "\tMain" << endl;
		cout << "1 - Визначити, чи рiвнi цi множини, чи одна з них є пiдмножиною iншоi. " << endl;
		cout << "2 - Складiть програму , яка будує всi можливi пiдмножини даноi множини." << endl;
		cout << "3 - Виконайте операцii над множинами. " << endl;
		char Pok_M;
		cin >> Pok_M;
		switch (Pok_M)
		{
		case '1':
		{
			int const size = 5, size1 = 5;
			int Pojuk = 5, sum_SP = 0;
			int a[size], b[size1], ka = 0, kb = 0, Znomera, Znomerb, kil_zero_A = 0, kil_zero_B = 0, max_Zero, True_piv = 0;
			cout << "A:";
			for (int i = 0; i < size; i++)
			{
				cin >> Znomera;
				a[i] = Znomera;
				//cout << a[i] << "\t";
				if (a[i] == 0) kil_zero_A++;
			}
			// задаєм  масив а
			cout << endl;
			cout << "B:";
			for (int j = 0; j < size1; j++)
			{
				cin >> Znomerb;
				b[j] = Znomerb;
				//cout << b[j] << "\t";
				if (b[j] == 0) kil_zero_B++;
			}
			// задаєм  масив b
			cout << endl;
			for (int i = 0; i < size; i++)
			{
				ka = 0;
				for (int j = 0; j < size1; j++)
				{
					if (a[i] == b[j] && a[i] != 0 && b[j] != 0) ka++;
				}
				if (ka > 0) sum_SP++;
			}
			// шукаємо кількість співпаденій між двома множинами
			if (sum_SP == Pojuk) { cout << "множини рiвнi" << endl; True_piv = 1; }
			else cout << "множини НЕ рiвнi" << endl;
			// перевірка чи множини рівні
			if (kil_zero_A > 0 && True_piv == 0 && kil_zero_B == 0)
			{
				if (sum_SP == Pojuk - kil_zero_A)
				{
					cout << "множина А належить множинi B" << endl;
				}
				else cout << "множина А НЕ належить множинi B" << endl;
			}
			// якщо в м. А є нулі і в м. B їх немає і кількість співпавших числ співпадає з Pojuk - kil_zero_A то А є В
			if (kil_zero_B > 0 && True_piv == 0 && kil_zero_A == 0)
			{
				if (sum_SP == Pojuk - kil_zero_B)
				{
					cout << "множина B належить множинi A" << endl;
				}
				else cout << "множина B НЕ належить множинi A" << endl;
			}
			// якщо в м. В є нулі і в м. А їх немає і кількість співпавших числ співпадає з Pojuk - kil_zero_В то В є А
			if (kil_zero_A < kil_zero_B) max_Zero = kil_zero_B;
			else max_Zero = kil_zero_A;
			//пошук макимального 0, щоб в подальшому зрозуіти коли є нулі і там і там що куди входить
			if (kil_zero_B > 0 && kil_zero_A > 0 && True_piv == 0)
			{
				if (sum_SP == Pojuk - max_Zero && max_Zero == kil_zero_B)
				{
					cout << "множина B належить множинi A" << endl;
				}
				else if (sum_SP == Pojuk - max_Zero && max_Zero == kil_zero_A)
				{
					cout << "множина A належить множинi B" << endl;
				}
				else cout << "не має схожостей" << endl;
				cout << sum_SP << "\t" << Pojuk - max_Zero << endl;
			}
			// алгоритм пошуку входження за 2-ма 0
			break;
		}
		case '2':
		{
			cout << "A_Ex:";
			string A_Ex;
			cin >> A_Ex;
			string A_Ex1 = A_Ex;
			cout << "A_Ex:!0\t";
			for (int i = 0; i < A_Ex[i] != '\0'; i++)
			{
				cout << A_Ex[i] << "\t";
			}
			int k = 0;
			for (int i = 0; i < A_Ex[i] != '\0'; i++)
			{
				for (int j = 1; j < A_Ex1[j] != '\0'; j++)
				{
					if (A_Ex1[j] != A_Ex[i])cout << A_Ex[i] << A_Ex1[j] << '\t';

				}
				if (k == 1)break;
				k++;
			}
			cout << A_Ex;
			break;
		}
		case '3':
		{
			int const size_EX = 5, size1_EX = 5, size_Dop_A = 5, size_Dop_B = 5;
			int Pojuk1 = 5, sum_SP_EX = 0;
			int A[size_EX], B[size1_EX], Dop_Znach_A[size_Dop_A], Dop_Znach_B[size_Dop_B], Znomera1, Znomerb1, kil_zero_A1 = 0, kil_zero_B1 = 0, Kspiv = 0;
			cout << "A:";
			for (int i = 0; i < size_EX; i++)
			{
				cin >> Znomera1;
				A[i] = Znomera1;
				//cout << a[i] << "\t";
				if (A[i] == 0) kil_zero_A1++;
			}
			// задаєм  масив а
			cout << endl;
			cout << "B:";
			for (int j = 0; j < size1_EX; j++)
			{
				cin >> Znomerb1;
				B[j] = Znomerb1;
				//cout << b[j] << "\t";
				if (B[j] == 0) kil_zero_B1++;
			}
			// задаєм  масив b
			char O;
			cout << "1 - Перетин" << endl << "2 - об'єднання" << endl << "3 - рiзниця" << endl << "4 - асиметрична рiзниця" << endl;  
			cout << "------------------------" << endl;
			cin >> O;
			if (O == '1')
			{
				for (int i = 0; i < size_EX; i++)
				{
					Kspiv = 0;
					for (int j = 0; j < size1_EX; j++)
					{
						if (A[i] == B[j] && A[i] != 0 && B[j] != 0)
						{
							Kspiv++;
							cout << A[i] << " ";
						}
					}
					if (Kspiv > 0) sum_SP_EX++;
				}
			}
			
			if (O == '2')
			{
				for (int i = 0; i < size_EX; i++)
				{
					if (A[i] != 0)
					{
						cout << A[i] << " ";
					}
				}
				for (int j = 0; j < size1_EX; j++)
				{
					Kspiv = 0;
					for (int i = 0; i < size_EX; i++)
					{
						if (B[j] == A[i] && A[i] != 0 && B[j] != 0)
						{
							Kspiv++;
						}
					}
					if (Kspiv == 0 && B[j] != 0) cout << B[j] << " ";
				}
			}
			if (O == '3')
			{
				for (int i = 0; i < size_EX; i++)
				{
					Kspiv = 0;
					for (int j = 0; j < size1_EX; j++)
					{
						if (A[i] == B[j] && A[i] != 0 && B[j] != 0)
						{
							Kspiv++;
						}
					}
					if (Kspiv == 0 && A[i] != 0) cout << A[i] << " ";
				}
			}
			if (O == '4')
			{
				for (int i = 0; i < size_EX; i++)
				{
					Kspiv = 0;
					for (int j = 0; j < size1_EX; j++)
					{
						if (A[i] == B[j] && A[i] != 0 && B[j] != 0)
						{
							Kspiv++;
						}
					}
					if (Kspiv == 0 && A[i] != 0) Dop_Znach_A[i] = A[i];
				}
				for (int j = 0; j < size1_EX; j++)
				{
					Kspiv = 0;
					for (int i = 0; i < size_EX; i++)
					{
						if (A[i] == B[j] && A[i] != 0 && B[j] != 0)
						{
							Kspiv++;
						}
					}
					if (Kspiv == 0 && B[j] != 0) Dop_Znach_B[j] = B[j];
				}
				cout << endl;
				for (int i = 0; i < size_Dop_A; i++)
				{
					if(Dop_Znach_A[i] > -100) cout << Dop_Znach_A[i] << " ";
				}
				for (int j = 0; j < size_Dop_B; j++)
				{
					if (Dop_Znach_B[j] > -100) cout << Dop_Znach_B[j] << " ";
				}
				//рахую значення різниці спочатку для А, потім для Б та записую його у новий масив числ
			}
			break;
		}
		default:
			cout << "Не вiрне значення" << endl;
			break;
		}
		cout << endl << "Якщо хочете вийти з програм Enter 0" << endl;
		cin >> P;
	}while (P != '0');
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
