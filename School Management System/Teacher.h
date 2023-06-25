#pragma once
#include"Person.h"
#include"Student.h"
#include<SFML/GpuPreference.hpp>
#include<string>
using namespace std;
using namespace sf;
const int MaxTeacherTasks = 5;
class Teacher:public Person
{
private:
	/////////////////////////////////////////////////////////////
	//---------------<< SFML MENU VARIABLES >>-------------------
	int MenuOptionSelected;
	Text MenuHeading;
	RectangleShape MenuBackgrounImageShape, AdminloginImageShape;
	Texture MainMenuImage, AdminLoginImage;
	Text MainOptionsProvided[MaxTeacherTasks];
	//------------>> Objects of Fonts......
	Font Algerian, MilkShake, Thunder, TimesNewRoman;
	////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////
	//--------------->> Simplae Data Members
	const int NumberofCourses = 5;
	string T_ID;
	string Courses[3] = {};
	float Salary;
	void GeneratingID();
public:
	//////////////////////////////////////////////////////////////
	//------------------<< Progrm Logic >>------------------------
	//------------------<< Default Constructor >>------------------------
	Teacher();
	//------------------<< Friend Functions >>------------------------
	friend ostream& operator<<(ostream& COUT, Teacher& ProvidedStudent);
	friend istream& operator>>(istream& CIN, Teacher& StudentProvided);
	friend bool is_CourseAvailable();
	//------------------<< CIN operator for class >>------------------------
	istream& operator>>(istream& CIN);
	//------------------<< Cout operator for class >>------------------------
	ostream& operator<<(ostream& COUT);
	//------------------<< Copy Constructor >>------------------------
	Teacher(Teacher& PassedTeacher);
	//------------------<< Assignment Operator >>------------------------
	Teacher operator=(Teacher& ToCopy);
	//------------------<< Seting Courses >>------------------------
	void Set_courses(Teacher*& PassedTeacher, int Index);
	//------------------<< Seting Courses Name >>------------------------
	void set_CourseName(string CourseName, int Index);
	//------------------<< Showing Registered Courses >>------------------------
	void DisplaytoEditTeacher(Teacher*& Staff, int NumberofTeacher);
	//--------------------------------<< Salary >>----------------------------------------
	//---------->> Setter
	void set_Salary(float Salary);
	//---------->> Getter
	float get_Salary();
	//------------------<< Showing Registered Courses >>------------------------
	void RegisteredCourses();
	//------------------<<Mark Attandance >>------------------------
	void MarkAttandance(Student*& ClassofStudents, int NumberofStdents);
	//------------------<<Mark Marks >>------------------------
	void AssigningMarks(Student*& Section, int NumberofStdents);
	//------------------<<Mark Grades >>------------------------
	void AssignGrades(Student*& Section, int NumberofStdents);
	//------------------<< Show Time Table >>------------------------
	void ShowTimeTable(Teacher*& StaffRoom, int Index);
	//--------------------------------<< Id Getter >>----------------------------------------
	//---------->> Setter
	void set_ID(string ID);
	//---------->> Getter
	string get_ID();
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//--------------------->> Menu options and view functions
	//---------------<< SFML MENU FUNCTIONS >>------------------
	Teacher(float Width, float Height);
	//---------------<< MOVE UP Function >>-------------------
	void MoveUp();
	//---------------<< MOVE DOWN Function >>-------------------
	void MoveDown();
	//---------------<< GETTER for selected Option >>------------
	int get_SelectedOption();
	//---------------<< DRAw Functions >>-------------------
	void Draw(RenderWindow& Windows);
	//------------------<< Destructor>>------------------------
	~Teacher() {}
};