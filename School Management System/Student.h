#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include"Person.h"
using namespace std;
using namespace sf;
const int MaxStudentTasks = 4;
class Student:public Person
{
private:
	/////////////////////////////////////////////////////////////
	//---------------<< SFML MENU VARIABLES >>-------------------
	int MenuOptionSelected;
	Text MenuHeading;
	RectangleShape MenuBackgrounImageShape,  loginImageShape;
	Texture MainMenuImage, LoginImage;
	Text MainOptionsProvided[MaxStudentTasks];
	//------------>> Objects of Fonts......
	Font Algerian, MilkShake, Thunder, TimesNewRoman;
	////////////////////////////////////////////////////////////
	const int NumberofCourses = 5;
	string S_ID;
	string Courses[3] = {};
	void GeneratingID();
public:
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//--------------------->> Menu options and view functions
	//---------------<< SFML MENU FUNCTIONS >>------------------
	Student(float Width, float Height);
	//---------------<< MOVE UP Function >>-------------------
	void MoveUp();
	//---------------<< MOVE DOWN Function >>-------------------
	void MoveDown();
	//---------------<< GETTER for selected Option >>------------
	int get_SelectedOption();
	//---------------<< DRAw Functions >>-------------------
	void Draw(RenderWindow& Windows);
	//------------------<< Destructor>>------------------------
	~Student() {}
	//////////////////////////////////////////////////////////////
	//------------------<< Progrm Logic >>------------------------
	//------------------<< Default Constructor >>------------------------
	Student();
	//------------------<< friend Class >>------------------------
	friend class Teacher;
	//------------------<< Friend Functions >>------------------------
	friend ostream& operator<<(ostream& COUT, Student& ProvidedStudent);
	friend bool is_CourseAvailable();
	friend istream& operator>>(istream& CIN, Student& StudentProvided);
	//------------------<< Showing user name  >>------------------------
	void DisplaytoEditStudents(Student*& Section, int NumberofStudents);
	//------------------<< CIN operator for class >>------------------------
	istream& operator>>(istream& CIN);
	//------------------<< Copy Constructor >>------------------------
	Student(Student& PassedStudent);
	//------------------<< Assignment Operator >>------------------------
	Student operator=(Student& ToCopy);
	//------------------<< Cout operator for class >>------------------------
	ostream& operator<<(ostream& COUT);
	//------------------<< Seting Courses >>------------------------
	void Set_courses(Student*& PassedStudent, int Index);
	//------------------<< Seting Courses Name >>------------------------
	void set_CourseName(string CourseName, int Index);
	//------------------<< Showing Registered Courses >>------------------------
	void RegisteredCourses();
	//------------------<< Showing Attandance >>------------------------
	void veiwAttandance(Student*& ClassofStudents, int Index);
	//------------------<< Showing Marks >>------------------------
	void veiwMarks(Student*& ClassofStudents, int Index);
	//------------------<< Showing Grades >>------------------------
	void veiwGrades(Student*& ClassofStudents, int Index);
	//--------------------------------<< Id Getter >>----------------------------------------
	//---------->> Setter
	void set_ID(string ID);
	//---------->> Getter
	string get_ID();
	/////////////////////////////////////////////////////////////
};