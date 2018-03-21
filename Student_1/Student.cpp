#include "Student.h"
#include <cstring>
#include <iostream>

Student::Student(const char *n, int f, const char *p, int y)
{
	size_t sz = strlen(n) + 1;  //размер на необходимата памет за името
	name = new char[sz];
	strcpy_s(name, sz, n);
	fn = f;
	sz = strlen(p) + 1;			//размер на необходимата памет за специалността
	program = new char[sz];
	strcpy_s(program, sz, p);
	year = y;
}

Student::Student(const Student &other)
{
	size_t sz = strlen(other.name) + 1;
	name = new char[sz];
	strcpy_s(name, sz, other.name);
	fn = other.fn;
	sz = strlen(other.program) + 1;
	program = new char[sz];
	strcpy_s(program, sz, other.program);
	year = other.year;
	for (size_t i = 0; i < 5; i++)
		results[i] = other.results[i];
}

Student& Student::operator=(const Student &other)
{
	if (this == &other) return *this;   //self assignment
	if (name) delete[] name;            //ако обектът отляво е инициализиран
	size_t sz = strlen(other.name) + 1; //определяне на размера на необходимата памет
	name = new char[sz];				//заделяне на памет
	strcpy_s(name, sz, other.name);     //копиране на данните
	fn = other.fn;
	if (program) delete[] program;
	sz = strlen(other.program) + 1;
	program = new char[sz];
	strcpy_s(program, sz, other.program);
	year = other.year;
	//results = other.results; // Грешка! 
	for (size_t i = 0; i < 5; i++)
		results[i] = other.results[i];
	return *this;
}

Student & Student::operator=(Student &&other)
{
	if (this == &other) return *this;
	if (name) delete[] name;
	name = std::move(other.name);
	fn = std::move(other.fn);
	if (program) delete[] program;
	program = std::move(other.program);
	year = std::move(other.year);
	for (size_t i = 0; i < 5; i++)
		results[i] = other.results[i];
	other.name = nullptr;
	other.fn = 0;
	other.program = nullptr;
	other.year = 0;
	for (size_t i = 0; i < 5; i++)
	{
		other.results[i].course = "";
		other.results[i].grade = 0;
	}
	return *this;
}

Student::Student(Student &&other)
{
	*this = std::move(other);
}

Student::~Student()
{
	if(name) delete[] name;		   //if(name != nullptr)
	if(program) delete[] program;
}

void Student::Show() const
{
	std::cout << "---- Student Record ----" << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Faculty number: " << fn << std::endl;
	std::cout << "Program: " << program << std::endl;
	std::cout << "Year: " << year << std::endl << std::endl;
}

void Student::Evaluate()
{
	std::cout << "Enter grades for student " << name << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Course name: ";
		std::cin >> results[i].course;
		std::cout << "Grade: ";
		std::cin >> results[i].grade;
	}
}

double Student::Average() const
{
	double sum = 0.0;
	for (int i = 0; i < 5; i++)
		sum += results[i].grade;
	return sum/5;
}

bool Student::operator<(const Student &other)
{
	return Average() > other.Average();  // >, за да сортира в низходящ ред
}

void Student::ReadStudent()
{
	char buf[50];
	size_t sz;
	if (name) delete[] name;
	std::cout << "Name: ";
	std::cin >> buf;
	sz = strlen(buf) + 1;
	name = new char[sz];
	strcpy_s(name, sz, buf);
	std::cout << "Fak. number: ";
	std::cin >> fn;
	std::cout << "Program: ";
	std::cin >> buf;
	sz = strlen(buf) + 1;
	if (program) delete[] program;
	program = new char[sz];
	strcpy_s(program, sz, buf);
	std::cout << "Year: ";
	std::cin >> year;
}