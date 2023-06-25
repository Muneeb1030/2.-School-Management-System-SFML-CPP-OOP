#include"AllLibIncluded.h"
//---------------<< SFML MENU FUNCTIONS >>-------------------
Admin::Admin(float Width, float Height)
{
	Algerian.loadFromFile("Fonts/Algerian.ttf");
	MilkShake.loadFromFile("Fonts/Milkshake.ttf");
	Thunder.loadFromFile("Fonts/Thunder.ttf");
	TimesNewRoman.loadFromFile("Fonts/TimesNewRoman.ttf");
	MainMenuImage.loadFromFile("Backgrounds/AdminBackground.jpg");

	MenuBackgrounImageShape.setSize(Vector2f(1000, 650));
	MenuBackgrounImageShape.setTexture(&MainMenuImage);

	MenuHeading.setFont(Algerian);
	MenuHeading.setString("Operations");
	MenuHeading.setFillColor(Color(255, 255, 255, 1500));
	MenuHeading.setCharacterSize(70);
	MenuHeading.setOutlineThickness(3);
	MenuHeading.setOutlineColor(Color(0, 0, 0));
	MenuHeading.setPosition(Vector2f(20, 30));

	TeacherSubHeading.setFont(Algerian);
	TeacherSubHeading.setString("Teacher");
	TeacherSubHeading.setFillColor(Color(0, 0, 0, 700));
	TeacherSubHeading.setCharacterSize(60);
	TeacherSubHeading.setOutlineThickness(3);
	TeacherSubHeading.setOutlineColor(Color(255, 255, 255, 200));
	TeacherSubHeading.setPosition(Vector2f(70, 105));

	StudentSubheading.setFont(Algerian);
	StudentSubheading.setString("Students");
	StudentSubheading.setFillColor(Color(0, 0, 0, 700));
	StudentSubheading.setCharacterSize(60);
	StudentSubheading.setOutlineThickness(3);
	StudentSubheading.setOutlineColor(Color(255, 255, 255, 200));
	StudentSubheading.setPosition(Vector2f(300, 270));

	TeacherbackgroundShade.setSize(Vector2f(170, 200));
	TeacherbackgroundShade.setFillColor(Color(255, 255, 255, 100));
	TeacherbackgroundShade.setOutlineThickness(4);
	TeacherbackgroundShade.setOutlineColor(Color(105, 105, 105, 200));
	TeacherbackgroundShade.setPosition(Vector2f(Width / 9, 180));

	StudentbackgroundShade.setSize(Vector2f(170, 200));
	StudentbackgroundShade.setFillColor(Color(255, 255, 255, 100));
	StudentbackgroundShade.setOutlineThickness(4);
	StudentbackgroundShade.setOutlineColor(Color(105, 105, 105, 200));
	StudentbackgroundShade.setPosition(Vector2f(Width / 2.9, 340));

	MainOptionsProvided[0].setFont(MilkShake);
	MainOptionsProvided[0].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[0].setString("Hire");
	MainOptionsProvided[0].setCharacterSize(45);
	MainOptionsProvided[0].setOutlineColor(Color::Black);
	MainOptionsProvided[0].setOutlineThickness(3);
	MainOptionsProvided[0].setPosition(Vector2f(Width / 6.9, 180));

	MainOptionsProvided[1].setFont(MilkShake);
	MainOptionsProvided[1].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[1].setString("Edit");
	MainOptionsProvided[1].setCharacterSize(45);
	MainOptionsProvided[1].setOutlineColor(Color::Black);
	MainOptionsProvided[1].setOutlineThickness(3);
	MainOptionsProvided[1].setPosition(Vector2f(Width / 6.9, 250));

	MainOptionsProvided[2].setFont(MilkShake);
	MainOptionsProvided[2].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[2].setString("Details");
	MainOptionsProvided[2].setCharacterSize(45);
	MainOptionsProvided[2].setOutlineColor(Color::Black);
	MainOptionsProvided[2].setOutlineThickness(3);
	MainOptionsProvided[2].setPosition(Vector2f(Width / 7.9, 310));

	MainOptionsProvided[3].setFont(MilkShake);
	MainOptionsProvided[3].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[3].setString("Enroll");
	MainOptionsProvided[3].setCharacterSize(45);
	MainOptionsProvided[3].setOutlineColor(Color::Black);
	MainOptionsProvided[3].setOutlineThickness(3);
	MainOptionsProvided[3].setPosition(Vector2f(Width / 2.7, 340));

	MainOptionsProvided[4].setFont(MilkShake);
	MainOptionsProvided[4].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[4].setString("Edit");
	MainOptionsProvided[4].setCharacterSize(45);
	MainOptionsProvided[4].setOutlineColor(Color::Black);
	MainOptionsProvided[4].setOutlineThickness(3);
	MainOptionsProvided[4].setPosition(Vector2f(Width / 2.6, 410));

	MainOptionsProvided[5].setFont(MilkShake);
	MainOptionsProvided[5].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[5].setString("Details");
	MainOptionsProvided[5].setCharacterSize(45);
	MainOptionsProvided[5].setOutlineColor(Color::Black);
	MainOptionsProvided[5].setOutlineThickness(3);
	MainOptionsProvided[5].setPosition(Vector2f(Width / 2.8, 470));

	MainOptionsProvided[6].setFont(MilkShake);
	MainOptionsProvided[6].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[6].setString("Exit");
	MainOptionsProvided[6].setCharacterSize(70);
	MainOptionsProvided[6].setOutlineColor(Color::Black);
	MainOptionsProvided[6].setOutlineThickness(3);
	MainOptionsProvided[6].setPosition(Vector2f(Width / 6.5, 520));

	MenuOptionSelected = 0;
}
//---------------<< DRAw Functions >>-------------------
void Admin::Draw(RenderWindow& Windows)
{
	Windows.draw(MenuBackgrounImageShape);
	Windows.draw(TeacherbackgroundShade);
	Windows.draw(StudentbackgroundShade);
	Windows.draw(MenuHeading);
	Windows.draw(TeacherSubHeading);
	for (int i = 0; i < MaxMenuOptions; i++)
	{
		Windows.draw(MainOptionsProvided[i]);
	}
	Windows.draw(StudentSubheading);
}
//---------------<< MOVE UP Function >>-------------------
void Admin::MoveUp()
{
	if (MenuOptionSelected - 1 >= 0)
	{
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(255, 255, 255, 1500));
		MenuOptionSelected--;
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(105, 105, 105));
	}
}
//---------------<< MOVE DOWN Function >>-------------------
void Admin::MoveDown()
{
	if (MenuOptionSelected + 1 < MaxMenuOptions)
	{
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(255, 255, 255, 1500));
		MenuOptionSelected++;
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(105, 105, 105));
	}
}
//---------------<< GETTER for selected Option >>-------------------
int Admin::get_SelectedOption()
{
	return MenuOptionSelected;
}
//////////////////////////////////////////////////////////////
//------------------<< Progrm Logic >>------------------------
//------------------<< Default Constructor >>------------------------
Admin::Admin()
{
	UserName = Password = "\0";
}
//------------------<< ADD Teacher >>------------------------
void Admin::AddTeacher(Teacher*& StaffRoom, int& NumberofTeachers)
{
	system("color 2F");
	cout << "\n\t  ***********************************************************\n"
		<< "\n\t                         NEW TEACHER                        "
		<< "\n\t  ***********************************************************\n";
	//---------->> Number of Teacher to Add
	int Enternship;
	cout << "\n\t  Number of Teachers        |              ";
	cin >> Enternship;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\n\t  Number of Teachers        |              ";
		cin >> Enternship;
	}
	cout << "\n\t  ***********************************************************\n";
	Enternship += NumberofTeachers;
	//--------->> New Array havng space for new teacher
	Teacher* NewHiring = new Teacher[Enternship];
	for (int i = 0; i < NumberofTeachers; i++)
	{
		//copying the data of previous Teacher
		NewHiring[i] = StaffRoom[i];
	}
	for (int i = NumberofTeachers; i < Enternship; i++)
	{
		//---------->> Getting new teacher details....
		cin >> NewHiring[i];
	}
	//--------->> Deleting previous memory allocated
	delete[] StaffRoom;
	//---------->> Avioding NULL ptr
	StaffRoom = nullptr;
	//------->> Assigning the address of new larger array
	StaffRoom = NewHiring;
	//------->> Avoiding any future inconvenience.
	NewHiring = nullptr;
	//------>> Increasing the number of Teacher in Main also
	NumberofTeachers = Enternship;
	//---------->> Saving Data in Files.
	SaveTeachersData(StaffRoom, NumberofTeachers);
	cout << "\n\n\t";
	system("pause");
	system("cls");
}
//------------------<< EDIT Teacher >>------------------------
void Admin::EditTeacher(Teacher*& StaffRoom, int NumberofTeachers)
{
	system("color 4F");
	cout << "\n\t  ***********************************************************\n"
		<< "\n\t                         EDIT TEACHER                        "
		<< "\n\t  ***********************************************************\n";
	string ToEditTeacher;
	//------->> Display the user name of all teachers
	StaffRoom->DisplaytoEditTeacher(StaffRoom, NumberofTeachers);
	bool matchName = false;
	do
	{
		cout << "\n\t  UserName                  |              ";
		cin >> ToEditTeacher;
		for (int i = 0; i < NumberofTeachers; i++)
		{
			//if the input user name is not correct
			if (ToEditTeacher == StaffRoom[i].get_UserName())
			{
				matchName = true;
				break;
			}
		}
	} while (!matchName);
	for (int i = 0; i < NumberofTeachers; i++)
	{
		if (ToEditTeacher == StaffRoom[i].get_UserName())
		{
			//Overloaded Operator to Take Input since it is different from other
			StaffRoom[i].operator>>(cin);
			break;
		}
	}
	SaveTeachersData(StaffRoom, NumberofTeachers);
	cout << "\n\n\t";
	system("pause");
	system("cls");
}
//------------------<< VEIW FUNCTION >>------------------------
void Admin::VeiwTeahers(Teacher*& StaffRoom, int NumberofTeachers)
{
	system("color 5F");
	string ToVeiw;
	bool MenuBreak = false;
	bool CheckTeacherEnrollment = false;
	int Option;
	cout << "\n\t  ***********************************************************\n"
		<< "\n\t                         DISPLAY MENU                         \n\n"
		<< "\n\n\t  ***********************************************************\n";
	do
	{
		cout << "\n\t   1. All Teachers"
			<< "\n\t   2. Teacher ID"
			<< "\n\t   3. Teacher Department"
			<< "\n\t   4. Exit\n";
		cout << "\n\t  ***********************************************************\n";
		cout << "\n\t  Option                  |              ";
		cin >> Option;
		switch (Option)
		{
		case 1:
			system("color 6F");
			for (int i = 0; i < NumberofTeachers; i++)
			{
				StaffRoom[i].operator<<(cout);
			}
			break;
		case 2:
			system("color 7F");
			cin.ignore();
			cout << "\n\t  ID                  |              ";
			getline(cin, ToVeiw);
			for (int i = 0; i < NumberofTeachers; i++)
			{
				if (ToVeiw == StaffRoom[i].get_ID())
				{
					CheckTeacherEnrollment == true;
					StaffRoom[i].operator<<(cout);
				}
			}
			if (CheckTeacherEnrollment == false)
			{
				cout << "\n\n\t\tNo Teacher Found\n";
			}
			break;
		case 3:
			system("color 8F");
			cin.ignore();
			cout << "\n\t  Department          |              ";
			getline(cin, ToVeiw);
			for (int i = 0; i < NumberofTeachers; i++)
			{
				if (ToVeiw == StaffRoom[i].get_DepartmentName())
				{
					CheckTeacherEnrollment == true;
					StaffRoom[i].operator<<(cout);
				}
			}
			if (CheckTeacherEnrollment == false)
			{
				cout << "\n\n\t\tNo Teacher Found\n";
			}
			break;
		case 4:
			MenuBreak = true;
			break;
		default:
			cout << "\n\tPlease Enter Valid Option\n";
			break;
		}
		cout << "\n\nt";
		system("pause");
		system("cls");
	} while (MenuBreak == false);
}
//------------------<< SAVING DATA Teacher >>------------------------
void Admin::SaveTeachersData(Teacher*& StaffRoom, int NumberofTeachers)
{
	ofstream Write_it;
	Write_it.open("Files/Teachers.txt");
	for (int i = 0; i < NumberofTeachers; i++)
	{
		Write_it << "\n  ***********************************************************\n"
			<< "\n                          TEACHER                           \n"
			<< "\n  ***********************************************************\n"
			<< "\n  First Name                |              " << StaffRoom[i].get_FirstName() << endl
			<< "\n  Last Name                 |              " << StaffRoom[i].get_LastName() << endl
			<< "\n  Department                |              " << StaffRoom[i].get_DepartmentName() << endl
			<< "\n  ID                        |              " << StaffRoom[i].get_ID() << endl
			<< "\n  Regisration Date          |              " << StaffRoom[i].get_RegistrationDate() << endl
			<< "\n  Gender                    |              " << StaffRoom[i].get_Gender() << endl
			<< "\n  Contact No                |              " << StaffRoom[i].get_ContactNo() << endl
			<< "\n  Salary                    |              " << StaffRoom[i].get_Salary() << endl
			<< "\n  Qualifications            |              " << StaffRoom[i].get_Qualifications() << endl
			<< "\n  Blood Group               |              " << StaffRoom[i].get_BloodGroup() << endl
			<< "\n  Address                   |              " << StaffRoom[i].get_Address() << endl
			<< "\n  ***********************************************************\n";
	}
	cout << "\n\tData Has Been Saved / Updated\n";
	Write_it.close();
}
//////////////////////////////////////////////////////////////////////////////
//------------------<< ADD Student >>------------------------
void Admin::AddStdent(Student*& Section, int& NumberofStudents)
{
	system("color 2F");
	//---------->> Number of Student to Add
	cout << "\n\t  ***********************************************************\n"
		<< "\n\t                         NEW STUDENT                        "
		<< "\n\n\t  ***********************************************************\n";
	int Enroll;
	cout << "\n\t  Number of Students        |              ";
	cin >> Enroll;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n\t  ***********************************************************\n";
	//--------->> New Array havng space for new Student
	Enroll += NumberofStudents;
	Student* NewAdmissions = new Student[Enroll];
	for (int i = 0; i < NumberofStudents; i++)
	{
		//copying the data of previous Teacher
		NewAdmissions[i] = Section[i];
	}
	for (int i = NumberofStudents; i < Enroll; i++)
	{
		//getting input in new rray with increased size
		cin >> NewAdmissions[i];
	}
	//--------->> Deleting previous memory allocated
	delete[] Section;
	//---------->> Avioding NULL ptr
	Section = nullptr;
	//------->> Assigning the address of new larger arra
	Section = NewAdmissions;
	//------->> Avoiding any future inconvenience.
	NewAdmissions = nullptr;
	//------>> Increasing the number of Teacher in Main 
	NumberofStudents = Enroll;
	//---------->> Saving Data in Files.
	SaveStudentsData(Section, NumberofStudents);
	cout << "\n\n\t";
	system("pause");
	system("cls");
}
//------------------<< EDIT Student >>------------------------
void Admin::EditStudent(Student*& Section, int NumberofStudents)
{
	system("color 4F");
	bool matchName = false;
	cout << "\n\t  ***********************************************************\n"
		<< "\n\t                         EDIT STUDENT                        "
		<< "\n\n\t  ***********************************************************\n";
	string ToEditStudent;
	Section->DisplaytoEditStudents(Section, NumberofStudents);
	do
	{
		cout << "\n\t  UserName                  |              ";
		cin >> ToEditStudent;
		for (int i = 0; i < NumberofStudents; i++)
		{
			//if the input user name is not correct
			if (ToEditStudent == Section[i].get_UserName())
			{
				matchName = true;
				break;
			}
		}
	} while (!matchName);
	for (int i = 0; i < NumberofStudents; i++)
	{
		if (ToEditStudent == Section[i].get_UserName())
		{
			//Overloaded Operator to Take Input since it is different from other
			Section[i].operator>>(cin);
			break;
		}
	}
	SaveStudentsData(Section, NumberofStudents);
	cout << "\n\n\t";
	system("pause");
	system("cls");
}
//------------------<< VEIW FNCTION >>------------------------
void Admin::VeiwStudents(Student*& Section, int NumberofStudents)
{
	system("color 5F");
	string ToVeiw;
	bool CheckStudentEnrollment = false;
	bool MenuBreak = false;
	int Option;
	cout << "\n\t  ***********************************************************\n"
		<< "\n\t                         DISPLAY MENU                         \n\n"
		<< "\n\n\t  ***********************************************************\n";
	do
	{
		cout << "\n\t   1. All Students"
			<< "\n\t   2. Student ID"
			<< "\n\t   3. Student Department"
			<< "\n\t   4. Student FeeStatus"
			<< "\n\t   5. Exit\n";
		cout << "\n\t  ***********************************************************\n";
		cout << "\n\t  Option                  |              ";
		cin >> Option;
		switch (Option)
		{
		case 1:
			system("color 6F");
			for (int i = 0; i < NumberofStudents; i++)
			{
				Section[i].operator<<(cout);
			}
			break;
		case 2:
			system("color 7F");
			cin.ignore();
			cout << "\n\t  ID                  |              ";
			getline(cin, ToVeiw);
			for (int i = 0; i < NumberofStudents; i++)
			{
				if (ToVeiw == Section[i].get_ID())
				{
					Section[i].operator<<(cout);
					CheckStudentEnrollment = true;
				}
			}
			if (CheckStudentEnrollment == false)
			{
				cout << "\n\n\t\tNo Student Found\n";
			}
			break;
		case 3:
			system("color 8F");
			cin.ignore();
			cout << "\n\t  Department          |              ";
			getline(cin, ToVeiw);
			for (int i = 0; i < NumberofStudents; i++)
			{
				if (ToVeiw == Section[i].get_DepartmentName())
				{
					Section[i].operator<<(cout);
					CheckStudentEnrollment = true;
				}
			}
			if (CheckStudentEnrollment == false)
			{
				cout << "\n\n\t\tNo Student Found\n";
			}
			break;
		case 4:
			system("color 9F");
			VeiwFeeStatus(Section, NumberofStudents);
			break;
		case 5:
			MenuBreak = true;
			break;
		default:
			cout << "\n\tPlease Enter Valid Option\n";
			break;
		}
		cout << "\n\nt";
		system("pause");
		system("cls");
	} while (MenuBreak == false);
}
//------------------<< FEES STATUS OF STUDENTS >>------------------------
void Admin::VeiwFeeStatus(Student*& Section, int NumberofStudent)
{
	system("color 6F");
	for (int i = 0; i < NumberofStudent; i++)
	{
		cout << "\n  ***********************************************************\n"
			<< "\n                          STUDENT                           \n"
			<< "\n  ***********************************************************\n"
			<< "\n  First Name                |              " << Section[i].get_FirstName() << endl;
		cout << "\n  Last Name                 |              " << Section[i].get_LastName() << endl;
		cout << "\n  Fee Status                |              " << Section[i].get_FeeStatus() << endl;

	}
}
//------------------<< SAVING Student Size to File >>------------------------
void Admin::SaveStudentsData(Student*& Scetion, int NumberofStudentss)
{
	ofstream Write_it;
	Write_it.open("Files/Teachers.txt");
	for (int i = 0; i < NumberofStudentss; i++)
	{
		Write_it << "\n  ***********************************************************\n"
			<< "\n                          Student                           \n"
			<< "\n\n  ***********************************************************\n"
			<< "\n  First Name                |              " << Scetion[i].get_FirstName() << endl
			<< "\n  Last Name                 |              " << Scetion[i].get_LastName() << endl
			<< "\n  Department                |              " << Scetion[i].get_DepartmentName() << endl
			<< "\n  ID                        |              " << Scetion[i].get_ID() << endl
			<< "\n  Regisration Date          |              " << Scetion[i].get_RegistrationDate() << endl
			<< "\n  Gender                    |              " << Scetion[i].get_Gender() << endl
			<< "\n  Contact No                |              " << Scetion[i].get_ContactNo() << endl
			<< "\n  Fee Status                |              " << Scetion[i].get_FeeStatus() << endl
			<< "\n  Qualifications            |              " << Scetion[i].get_Qualifications() << endl
			<< "\n  Blood Group               |              " << Scetion[i].get_BloodGroup() << endl
			<< "\n  Address                   |              " << Scetion[i].get_Address() << endl
			<< "\n  ***********************************************************\n";
	}
	cout << "\n\tData Has Been Saved / Updated\n";
	Write_it.close();
}
