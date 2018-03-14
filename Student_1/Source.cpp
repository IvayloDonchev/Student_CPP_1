#include "Student.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	//Student s("Ivan Ivanov", 18001, "Informatics", 2);
	//s.Show();
	//s.Evaluate();
	//cout << "Average result: " << s.Average() << endl;

	//Student s2{s};    //copy constructor
	//cout << "--------------------------------------------\n";
	//s2.Show();
	//cout << "Average result: " << s2.Average() << endl;

	//Student s3;		//default constructor
	//s3 = s;			//copy assignment
	//cout << "--------------------------------------------\n";
	//s3.Show();
	//cout << "Average result: " << s3.Average() << endl;


	const int N = 5;
	Student group[N];
	// ��������� �� ����� �� ����������
	for (int i = 0; i < N; i++)
		group[i].ReadStudent();
	// ��������� �� ������ �� ����� �������
	for (int i = 0; i < N; i++)
		group[i].Evaluate();
	// ���������
	sort(begin(group), end(group));
	// ��������� �� ���������� ������
	cout << "----- Sorted List ---------\n";
	for (int i = 0; i < N; i++)
	{
		group[i].Show();
		cout << "Average result: " << group[i].Average() << endl;
	}

	system("pause");
}
