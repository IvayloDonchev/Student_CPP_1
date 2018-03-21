#pragma once
#include <string>
class Student
{
private:
	struct Assessment {	     //���������
		std::string course;  //������ �������
		int grade;			 //������
	};
	char *name;     //���
	int fn;         //���������� �����
	char *program;  //�����������
	int year;       //���� (������)
	Assessment results[5]; //������ �� 5 ��������
public:
	Student() :name(nullptr), fn(0), program(nullptr), year(0) {}
	Student(const char*, int, const char*, int);
	Student(const Student&);	          // ������� �����������
	Student& operator=(const Student&);   // �������� �����������
	Student& operator=(Student&&);	      // ����������� �����������
	Student(Student&&);		              // ���������� �����������
	~Student();                           // ����������
	void Show() const;
	void Evaluate();	//������� �������� �� ������������
	double Average() const;   //������ ����������� �� ��������
	bool operator<(const Student&); //������������� �������� <
	void ReadStudent();  //������� ����� �� �������� �� ������������
};

