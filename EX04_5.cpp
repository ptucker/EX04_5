// EX04_5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Course
{
private:
	string courseName;
	string* students;
	int numberOfStudents;
	int capacity;

public:
	Course(const string& courseName, int capacity)
	{
		numberOfStudents = 0;
		this->courseName = courseName;
		this->capacity = capacity;
		students = new string[capacity];
	}
	string getCourseName() const
	{
		return courseName;
	}
	void dropStudent(const string& name)
	{
		for (int i = 0; i < numberOfStudents; i++)
		{
			if (students[i] == name)
				students[i] = "";
		}

		numberOfStudents--;
	}
	void addStudent(const string& name)
	{
		if (numberOfStudents > this->capacity)
		{
			string* newList = new string[capacity * 2];

			for (int i = 0; i < capacity; i++)
			{
				newList[i] = students[i];
			}
		}

		students[numberOfStudents] = name;
		numberOfStudents++;

		string* newStudentArray = new string[numberOfStudents * 2];

	}
	string* getStudents() const
	{
		return students;
	}
	int getNumberOfStudents() const
	{
		return numberOfStudents;
	}
	void clear()
	{
		for (int i = 0; i < numberOfStudents; i++)
		{
			if (students[i] != "")
				students[i] = "";
			numberOfStudents--;
		}
	}
	Course(const Course& course)
	{
		courseName = course.courseName;
		numberOfStudents = course.numberOfStudents;
		capacity = course.capacity;
		students = new string[capacity];
	}
	~Course()
	{
		delete [] students;
	}
};

int main()
{
	Course c1("Calc", 3);
	Course c2(c1);
	c1.addStudent("Chris");
	c1.addStudent("Nikki");
	c1.addStudent("John");

	c1.dropStudent("John");

	c1.clear();

	string* studentList = c1.getStudents();
	int numOfStu = c1.getNumberOfStudents();
	for (int i = 0; i < numOfStu; i++)
		cout << studentList[i] << endl;

	delete [] studentList;

    return 0;
}

