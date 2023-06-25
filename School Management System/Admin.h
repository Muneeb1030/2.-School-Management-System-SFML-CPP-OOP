#pragma once
#include<SFML/Graphics.hpp>
#include"Teacher.h"
#include"Student.h"
using namespace sf;
const int MaxMenuOptions = 7;
class Admin
{
	/////////////////////////////////////////////////////////////
	//---------------<< SFML MENU VARIABLES >>-------------------
	int MenuOptionSelected;
	Text MenuHeading, TeacherSubHeading, StudentSubheading;
	RectangleShape MenuBackgrounImageShape, 
		TeacherbackgroundShade, StudentbackgroundShade,
		AdminloginImageShape;
	Texture MainMenuImage, AdminLoginImage;
	Text MainOptionsProvided[MaxMenuOptions];
	//------------>> Objects of Fonts
	Font Algerian, MilkShake, Thunder, TimesNewRoman;
	////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////
	//--------------->> Simplae Data Members
	string UserName, Password;
public:
	/////////////////////////////////////////////////////////////
	//---------------<< SFML MENU FUNCTIONS >>-------------------
	Admin(float Width, float Height);
	//---------------<< MOVE UP Function >>-------------------
	void MoveUp();
	//---------------<< MOVE DOWN Function >>-------------------
	void MoveDown();
	//---------------<< GETTER for selected Option >>-------------------
	int get_SelectedOption();
	//---------------<< DRAw Functions >>-------------------
	void Draw(RenderWindow& Windows);
	//////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////
	//------------------<< Progrm Logic >>------------------------
	//------------------<< Default Constructor >>------------------------
	Admin();
	//------------------<< ADD Teacher >>------------------------
	void AddTeacher(Teacher*& StaffRoom, int& NumberofTeachers);
	//------------------<< EDIT Teacher >>------------------------
	void EditTeacher(Teacher*& StaffRoom, int NumberofTeachers);
	//------------------<< VEIW FUNCTION >>------------------------
	void VeiwTeahers(Teacher*& StaffRoom, int NumberofTeachers);
	//------------------<< SAVING DATA Teacher >>------------------------
	void SaveTeachersData(Teacher*& StaffRoom, int NumberofTeachers);
	//////////////////////////////////////////////////////////////////////////////
	//------------------<< ADD Student >>------------------------
	void AddStdent(Student*& Section, int& NumberofStudents);
	//------------------<< EDIT Student >>------------------------
	void EditStudent(Student*& Section, int NumberofStudents);
	//------------------<< VEIW FNCTION >>------------------------
	void VeiwStudents(Student*& Section, int NumberofStudents);
	//------------------<< FEES STATUS OF STUDENTS >>------------------------
	void VeiwFeeStatus(Student*& Section, int NumberofStudent);
	//------------------<< SAVING Student Size to File >>------------------------
	void SaveStudentsData(Student*& Scetion, int NumberofStudentss);
	//------------------<< Destructor >>------------------------
	~Admin() {}
};