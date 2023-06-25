#include"AllLibIncluded.h"
//////////////////////////////////////////////////////////////////////
//--------------------->> Menu options and view functions
//---------------<< SFML MENU FUNCTIONS >>------------------
Student::Student(float Width, float Height)
{
	Algerian.loadFromFile("Fonts/Algerian.ttf");
	MilkShake.loadFromFile("Fonts/Milkshake.ttf");
	Thunder.loadFromFile("Fonts/Thunder.ttf");
	TimesNewRoman.loadFromFile("Fonts/TimesNewRoman.ttf");
	MainMenuImage.loadFromFile("Backgrounds/AdminBackground.jpg");

	MenuBackgrounImageShape.setSize(Vector2f(1000, 650));
	MenuBackgrounImageShape.setTexture(&MainMenuImage);

	MenuHeading.setFont(Algerian);
	MenuHeading.setString("Student");
	MenuHeading.setFillColor(Color(255, 255, 255, 1500));
	MenuHeading.setCharacterSize(70);
	MenuHeading.setOutlineThickness(3);
	MenuHeading.setOutlineColor(Color(0, 0, 0));
	MenuHeading.setPosition(Vector2f(40, 50));

	MainOptionsProvided[0].setFont(MilkShake);
	MainOptionsProvided[0].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[0].setString("Attandance");
	MainOptionsProvided[0].setCharacterSize(45);
	MainOptionsProvided[0].setOutlineColor(Color::Black);
	MainOptionsProvided[0].setOutlineThickness(3);
	MainOptionsProvided[0].setPosition(Vector2f(Width / 6.9, 180));

	MainOptionsProvided[1].setFont(MilkShake);
	MainOptionsProvided[1].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[1].setString("Grades");
	MainOptionsProvided[1].setCharacterSize(45);
	MainOptionsProvided[1].setOutlineColor(Color::Black);
	MainOptionsProvided[1].setOutlineThickness(3);
	MainOptionsProvided[1].setPosition(Vector2f(Width / 6.9, 270));

	MainOptionsProvided[2].setFont(MilkShake);
	MainOptionsProvided[2].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[2].setString("Marks");
	MainOptionsProvided[2].setCharacterSize(45);
	MainOptionsProvided[2].setOutlineColor(Color::Black);
	MainOptionsProvided[2].setOutlineThickness(3);
	MainOptionsProvided[2].setPosition(Vector2f(Width / 7.9, 360));

	MainOptionsProvided[3].setFont(MilkShake);
	MainOptionsProvided[3].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[3].setString("Exit");
	MainOptionsProvided[3].setCharacterSize(70);
	MainOptionsProvided[3].setOutlineColor(Color::Black);
	MainOptionsProvided[3].setOutlineThickness(3);
	MainOptionsProvided[3].setPosition(Vector2f(Width / 6.5, 520));

	MenuOptionSelected = 0;
}
//---------------<< DRAw Functions >>-------------------
void Student::Draw(RenderWindow& Windows)
{
	Windows.draw(MenuBackgrounImageShape);
	Windows.draw(MenuHeading);
	for (int i = 0; i < MaxStudentTasks; i++)
	{
		Windows.draw(MainOptionsProvided[i]);
	}
}
//---------------<< MOVE UP Function >>-------------------
void Student::MoveUp()
{
	if (MenuOptionSelected - 1 >= 0)
	{
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(255, 255, 255, 1500));
		MenuOptionSelected--;
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(105, 105, 105));
	}
}
//---------------<< MOVE DOWN Function >>-------------------
void Student::MoveDown()
{
	if (MenuOptionSelected + 1 < MaxTeacherTasks)
	{
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(255, 255, 255, 1500));
		MenuOptionSelected++;
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(105, 105, 105));
	}
}
//---------------<< GETTER for selected Option >>------------
int Student::get_SelectedOption()
{
	return MenuOptionSelected;
}
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//------------------<< Progrm Logic >>------------------------
//------------------<< Default Constructor >>------------------------
Student::Student() {}
//------------------<< Setting ID >>------------------------
void Student::GeneratingID()
{
	srand(time(NULL));

	int IDLast4Digits = rand() % 9999 + 1;

	string Savingint;
	string Studentid;
	stringstream intConverting;
	intConverting << IDLast4Digits;
	intConverting >> Savingint;
	if (get_DepartmentName() == "Computer Science")
	{
		IDLast4Digits += 1;
		Studentid = "20F-" + Savingint;
	}
	else if (get_DepartmentName() == "Electric Engineering")
	{
		IDLast4Digits += 2;
		Studentid = "20F-" + Savingint;
	}
	else if (get_DepartmentName() == "Software Engineering")
	{
		IDLast4Digits += 3;
		Studentid = "20F-" + Savingint;
	}
	else if (get_DepartmentName() == "Business")
	{
		IDLast4Digits += 4;
		Studentid = "20F-" + Savingint;
	}
	else if (get_DepartmentName() == "Social Sciences")
	{
		IDLast4Digits += 5;
		Studentid = "20F-" + Savingint;
	}
	set_ID(Studentid);
	cout << "\n\t  ID                        |              " << S_ID << endl;
}
//------------------<< Friend Functions >>------------------------
ostream& operator<<(ostream& COUT, Student& StudentProvided)
{
	cout << "\n  ***********************************************************\n"
		<< "\n                          STUDENT                           \n"
		<< "\n  ***********************************************************\n"
		<< "\n  First Name                |              " << StudentProvided.get_FirstName() << endl;
	cout << "\n  Last Name                 |              " << StudentProvided.get_LastName() << endl;
	cout << "\n  Department                |              " << StudentProvided.get_DepartmentName() << endl;
	cout << "\n  ID                        |              " << StudentProvided.get_ID() << endl;
	cout << "\n  Regisration Date          |              " << StudentProvided.get_RegistrationDate() << endl;
	cout << "\n  Gender                    |              " << StudentProvided.get_Gender() << endl;
	cout << "\n  Contact No                |              " << StudentProvided.get_ContactNo() << endl;
	cout << "\n  Fee Status                |              " << StudentProvided.get_FeeStatus() << endl;
	cout << "\n  Qualifications            |              " << StudentProvided.get_Qualifications() << endl;
	cout << "\n  Blood Group               |              " << StudentProvided.get_BloodGroup() << endl;
	cout << "\n  Address                   |              " << StudentProvided.get_Address() << endl;
	cout << "\n  ***********************************************************\n";
	return COUT;
}
istream& operator>>(istream& CIN, Student& StudentProvided)
{
	string firstName, lastName, registrationDate, addRess, qualification;
	string Contact, username, password, bloodgroup, feeStatus;
	char genDer = '\0';
	cout << "\n\t  First Name                |              ";
	cin >> firstName;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n\t  Last Name                 |              ";
	getline(cin, lastName);
	cout << "\n\t  Regsration Date           |(DD/MM/YYYY) ";
	getline(cin, registrationDate);
	StudentProvided.set_Department();
	StudentProvided.GeneratingID();
	username = StudentProvided.get_ID() + "@nu.edu.pk";
	cout << "\n\t  User Name                 |              " << username << endl;
	cin.ignore();
	cout << "\n\t  Password                  |              ";
	getline(cin, password);
	do {
		cout << "\n\t  Gender                    |              ";
		cin >> genDer;
		genDer = toupper(genDer);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (genDer != 'M' && genDer != 'F');
	cout << "\n\t  Blood Group               |              ";
	cin >> bloodgroup;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n\t  Qualification             |              ";
	getline(cin, qualification);
	cout << "\n\t  ContactNo                 |              ";
	getline(cin, Contact);
	cout << "\n\t  Address                   |              ";
	getline(cin, addRess);
	cout << "\n\t  Fee Status                |              "
		<< "\n\t\t1. Paid"
		<< "\n\t\t2. UnPaid\n\t\t\t\t";
	int Option;
	cin >> Option;
	if (Option == 1)
	{
		feeStatus = "Paid";
	}
	else
	{
		feeStatus = "UnPaid";
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n\t  ***********************************************************\n";
	StudentProvided.set_FirstName(firstName);
	StudentProvided.set_LastName(lastName);
	StudentProvided.set_RegistrationDate(registrationDate);
	StudentProvided.set_ContactNo(Contact);
	StudentProvided.set_Gender(genDer);
	StudentProvided.set_Address(addRess);
	StudentProvided.set_Qualifications(qualification);
	StudentProvided.set_BloodGroup(bloodgroup);
	StudentProvided.set_FeeStatus(feeStatus);
	StudentProvided.set_UserName(username);
	StudentProvided.set_Password(password);
	ofstream WriteData;
	WriteData.open("StudentUeerNames.txt", ios::app);
	WriteData << username << " " << password << endl;
	WriteData.close();
	return CIN;
}
//------------------<< Showing user name  >>------------------------
void Student::DisplaytoEditStudents(Student*& Section, int NumberofStudents)
{
	for (int i = 0; i < NumberofStudents; i++)
	{

		cout << "\n\t  Name                      |              "
			<< Section[i].get_FirstName() << " " << Section[i].get_LastName() << endl;
		cout << "\n\t  User Name                 |              "
			<< Section[i].get_UserName() << endl;
	}
}
//------------------<< CIN operator for class >>------------------------
istream& Student::operator>>(istream& CIN)
{
	string firstName, lastName, addRess, qualification;
	string Contact, feeStatus;
	cout << "\n\t  First Name                |              ";
	cin >> firstName;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n\t  Last Name                 |              ";
	getline(cin, lastName);
	set_Department();
	cout << "\n\t  Qualification             |              ";
	getline(cin, qualification);
	cout << "\n\t  ContactNo                 |              ";
	getline(cin, Contact);
	cout << "\n\t  Address                   |              ";
	getline(cin, addRess);
	cout << "\n\t  Fee Status                |              "
		<< "\n\t\t1. Paid"
		<< "\n\t\t2. UnPaid\n\t\t\t\t";
	int Option;
	cin >> Option;
	if (Option == 1)
	{
		feeStatus = "Paid";
	}
	else
	{
		feeStatus = "UnPaid";
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n\t  ***********************************************************\n";
	set_FirstName(firstName);
	set_LastName(lastName);
	set_ContactNo(Contact);
	set_Address(addRess);
	set_Qualifications(qualification);
	set_FeeStatus(feeStatus);
	return CIN;
}
//------------------<< Copy Constructor >>------------------------
Student::Student(Student& PassedStudent) :Person(PassedStudent)
{
	this->S_ID = PassedStudent.S_ID;
}
//------------------<< Assignment Operator >>------------------------
Student Student::operator=(Student& ToCopy)
{
	this->Student::Student(ToCopy);
	return *this;
}
//------------------<< Cout operator for class >>------------------------
ostream& Student::operator<<(ostream& COUT)
{
	cout << "\n  ***********************************************************\n"
		<< "\n                          STUDENT                           \n"
		<< "\n  ***********************************************************\n"
		<< "\n  First Name                |              " << get_FirstName() << endl;
	cout << "\n  Last Name                 |              " << get_LastName() << endl;
	cout << "\n  Department                |              " << get_DepartmentName() << endl;
	cout << "\n  ID                        |              " << get_ID() << endl;
	cout << "\n  Regisration Date          |              " << get_RegistrationDate() << endl;
	cout << "\n  Gender                    |              " << get_Gender() << endl;
	cout << "\n\t  *******************************************"
		<< "\n                        COURSE                           \n";
	for (int j = 0; j < 3; j++)
	{
		cout << "\t " << j + 1 << ". " << Courses[j] << endl;
	}
	cout << "\n\t  *******************************************\n";
	cout << "\n  Contact No                |              " << get_ContactNo() << endl;
	cout << "\n  Fee Status                |              " << get_FeeStatus() << endl;
	cout << "\n  Qualifications            |              " << get_Qualifications() << endl;
	cout << "\n  Blood Group               |              " << get_BloodGroup() << endl;
	cout << "\n  Address                   |              " << get_Address() << endl;
	cout << "\n  ***********************************************************\n";
	return COUT;
}
//------------------<< Seting Courses >>------------------------
void Student::Set_courses(Student*& PassedStudent, int Index)
{
	Algerian.loadFromFile("Fonts/Algerian.ttf");
	MilkShake.loadFromFile("Fonts/Milkshake.ttf");
	cout << "\n\t  ***********************************************************\n"
		<< "\n\t                           COURSE                            "
		<< "\n\n\t  ***********************************************************\n";
	const int NumberofCoursesOffered = 5;
	ifstream read_DepartmentName;
	read_DepartmentName.open("Files/CoursesOffered.txt");
	string ReadingDepartment;
	string ReadingCourses;
	string CourseNameHolder[5];
	Text Heading;
	while (read_DepartmentName.good())
	{
		getline(read_DepartmentName, ReadingDepartment);
		if (PassedStudent[Index].get_DepartmentName() == ReadingDepartment)
		{
			for (int i = 0; i < NumberofCoursesOffered; i++)
			{
				getline(read_DepartmentName, ReadingCourses);
				CourseNameHolder[i] = ReadingCourses;
			}
			break;
		}
	}
	Text PassedDisplay;
	string Course1, Course2, Course3, Course4, Course5;
	Course1 = CourseNameHolder[0];
	Course2 = CourseNameHolder[1];
	Course3 = CourseNameHolder[2];
	Course4 = CourseNameHolder[3];
	Course5 = CourseNameHolder[4];
	RenderWindow Popup(VideoMode(500, 300), "Courses!");
	while (Popup.isOpen())
	{
		Event evnt1;
		while (Popup.pollEvent(evnt1))
		{
			if (evnt1.type == Event::Closed() /*|| Mouse::isButtonPressed(Mouse::Left)*/)
			{
				Popup.close();
			}
		}
		Heading.setFont(Algerian);
		Heading.setFillColor(Color(139, 28, 98));                  //
		Heading.setPosition(Vector2f(20, 15));                     //    
		Heading.setOutlineThickness(3);
		Heading.setCharacterSize(50);
		Heading.setOutlineColor(Color::White);                     //
		Heading.setString("Courses");
		PassedDisplay.setFont(MilkShake);
		PassedDisplay.setFillColor(Color(139, 28, 98));                  //
		PassedDisplay.setPosition(Vector2f(60, 70));                     //    
		PassedDisplay.setOutlineThickness(3);
		PassedDisplay.setCharacterSize(30);
		PassedDisplay.setOutlineColor(Color::White);                     //
		PassedDisplay.setString(Course1);
		Popup.clear(Color(238, 58, 140));
		Popup.draw(Heading);
		Popup.draw(PassedDisplay);
		PassedDisplay.setString(Course2);
		PassedDisplay.setPosition(Vector2f(60, 100));
		Popup.draw(PassedDisplay);
		PassedDisplay.setString(Course3);
		PassedDisplay.setPosition(Vector2f(60, 130));
		Popup.draw(PassedDisplay);
		PassedDisplay.setString(Course4);
		PassedDisplay.setPosition(Vector2f(60, 160));
		Popup.draw(PassedDisplay);
		PassedDisplay.setString(Course5);
		PassedDisplay.setPosition(Vector2f(60, 190));
		Popup.draw(PassedDisplay);
		Popup.display();
		int Option;
		for (int i = 0; i < 3; i++)
		{
			do
			{
				cout << "\n\tPlease Select One Valid Course = ";
				cin >> Option;
				for (int k = 0; k < 3; k++)
				{
					if (Courses[k] == CourseNameHolder[Option - 1])
					{
						cout << "\n\tPlease Select One Course not already Selected = ";
						cin >> Option;
					}
				}
			} while (Option < 1 || Option>5);
			switch (Option)
			{
			case 1:
				Courses[i] = CourseNameHolder[0];
				break;
			case 2:
				Courses[i] = CourseNameHolder[1];
				break;
			case 3:
				Courses[i] = CourseNameHolder[2];
				break;
			case 4:
				Courses[i] = CourseNameHolder[3];
				break;
			case 5:
				Courses[i] = CourseNameHolder[4];
				break;
			}
		}
		break;
	}
}
//------------------<< Seting Courses Name >>------------------------
void Student::set_CourseName(string CourseName, int Index)
{
	Courses[Index] = CourseName;
}
//------------------<< Showing Registered Courses >>------------------------
void Student::RegisteredCourses()
{
	cout << "\n\t  ***********************************************************\n"
		<< "\n					     REGISTERED COURSES                    ";
	for (int i = 0; i < 3; i++)
	{
		cout << "\n\t" << i + 1 << ". " << Courses[i];
	}
	cout << "\n\n\t  ***********************************************************\n";
}
//------------------<< Showing Attandance >>------------------------
void Student::veiwAttandance(Student*& ClassofStudents, int Index)
{
	cout << "\n\t  ***********************************************************\n"
		<< "\n\t                          ATTANDANCE                          \n"
		<< "\n\t  ***********************************************************\n";
	ifstream ReadAttandance;
	ReadAttandance.open("Files/Attandance.txt");
	string username, Date, Day, Attandance;
	while (ReadAttandance.good())
	{
		ReadAttandance >> username;
		ReadAttandance >> Date;
		ReadAttandance >> Day;
		ReadAttandance >> Attandance;
		if (username == ClassofStudents[Index].get_UserName())
		{
			cout << Date << "\t" << Day << "\t" << Attandance << endl;
		}

	}
	ReadAttandance.close();
}
//------------------<< Showing Marks >>------------------------
void Student::veiwMarks(Student*& ClassofStudents, int Index)
{
	cout << "\n\t  ***********************************************************\n"
		<< "\n\t                          MARKS                          \n"
		<< "\n\n\t  ***********************************************************\n";
	ifstream ReadMarks;
	ReadMarks.open("Files/Marks.txt");
	string username, Subject, Marks;
	while (ReadMarks.good())
	{
		ReadMarks >> username;
		ReadMarks >> Subject;
		ReadMarks >> Marks;
		if (username == ClassofStudents[Index].get_UserName())
		{
			cout << Subject << "\t" << Marks << "\n";
		}
	}
	ReadMarks.close();
}
//------------------<< Showing Grades >>------------------------
void Student::veiwGrades(Student*& ClassofStudents, int Index)
{
	cout << "\n\t  ***********************************************************\n"
		<< "\n\t                            GRADES                             \n"
		<< "\n\n\t  ***********************************************************\n";
	ifstream ReadMarks;
	ReadMarks.open("Files/Grades.txt");
	string username, Subject, Marks;
	while (ReadMarks.good())
	{
		ReadMarks >> username;
		ReadMarks >> Subject;
		ReadMarks >> Marks;
		if (username == ClassofStudents[Index].get_UserName())
		{
			cout << Subject << "\t" << Marks << "\n";
		}
	}
	ReadMarks.close();
}
//--------------------------------<< Id Getter >>----------------------------------------
//---------->> Setter
void Student::set_ID(string ID)
{
	S_ID = ID;
}
//---------->> Getter
string Student::get_ID()
{
	return S_ID;
}
/////////////////////////////////////////////////////////////