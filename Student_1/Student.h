#pragma once
#include <string>
class Student
{
private:
	struct Assessment {	     //оценяване
		std::string course;  //учебен предмет
		int grade;			 //оценка
	};
	char *name;     //име
	int fn;         //факултетен номер
	char *program;  //специалност
	int year;       //курс (година)
	Assessment results[5]; //оценки по 5 предмета
public:
	Student() :name(nullptr), fn(0), program(nullptr), year(0) {}
	Student(const char*, int, const char*, int);
	Student(const Student&);	          // копиращ конструктор
	Student& operator=(const Student&);   // копиращо присвояване
	Student& operator=(Student&&);	      // преместващо присвояване
	Student(Student&&);		              // преместващ конструктор
	~Student();                           // деструктор
	void Show() const;
	void Evaluate();	//въвежда оценките от клавиатурата
	double Average() const;   //средно аритметично от оценките
	bool operator<(const Student&); //предефинирана операция <
	void ReadStudent();  //въвежда данни за студента от клавиатурата
};

