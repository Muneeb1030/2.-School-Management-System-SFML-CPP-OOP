#include "AllLibIncluded.h"
//////////////////////////////////////////////////////////////
//------------------<< Progrm Logic >>------------------------
//------------------<< Default Constructor >>------------------------
Teacher::Teacher()
{
	Salary = 0.0;
}
//------------------<< Friend Functions >>------------------------
ostream& operator<<(ostream& COUT, Teacher& StaffRoom)
{
	cout << "\n  ***********************************************************\n"
		<< "\n                          TEACHER                           \n"
		<< "\n  ***********************************************************\n"
		<< "\n  First Name                |              " << StaffRoom.get_FirstName() << endl;
	cout << "\n  Last Name                 |              " << StaffRoom.get_LastName() << endl;
	cout << "\n  Department                |              " << StaffRoom.get_DepartmentName() << endl;
	cout << "\n  ID                        |              " << StaffRoom.get_ID() << endl;
	cout << "\n  Regisration Date          |              " << StaffRoom.get_RegistrationDate() << endl;
	cout << "\n  Gender                    |              " << StaffRoom.get_Gender() << endl;
	cout << "\n  Contact No                |              " << StaffRoom.get_ContactNo() << endl;
	cout << "\n  Salary                    |              " << StaffRoom.get_Salary() << endl;
	cout << "\n  Qualifications            |              " << StaffRoom.get_Qualifications() << endl;
	cout << "\n  Blood Group               |              " << StaffRoom.get_BloodGroup() << endl;
	cout << "\n  Address                   |              " << StaffRoom.get_Address() << endl;
	cout << "\n  ***********************************************************\n";
	return COUT;
}
istream& operator>>(istream& CIN, Teacher& Staff)
{
	string firstName, lastName, registrationDate, addRess, qualification;
	string Contact, username, password, bloodgroup;
	float salary;
	char genDer = '\0';
	cout << "\n\t  First Name                |              ";
	cin >> firstName;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n\t  Last Name                 |              ";
	getline(cin, lastName);
	username = firstName + "." + lastName + "@nu.edu.pk";
	cout << "\n\t  User Name                 |              " << username << endl;
	cout << "\n\t  Join Date                 |(DD/MM/YYYY) ";
	getline(cin, registrationDate);
	cout << "\n\t  Password                  |              ";
	getline(cin, password);
	Staff.set_Department();
	Staff.GeneratingID();
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
	cout << "\n\t  Salary                    |              ";
	cin >> salary;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n\t  ***********************************************************\n";
	Staff.set_FirstName(firstName);
	Staff.set_LastName(lastName);
	Staff.set_RegistrationDate(registrationDate);
	Staff.set_ContactNo(Contact);
	Staff.set_Gender(genDer);
	Staff.set_Address(addRess);
	Staff.set_Qualifications(qualification);
	Staff.set_BloodGroup(bloodgroup);
	Staff.set_Salary(salary);
	Staff.set_UserName(username);
	Staff.set_Password(password);
	ofstream WriteData;
	WriteData.open("TeacherUserName.txt", ios::app);
	WriteData << username << " " << password << endl;
	WriteData.close();
	return CIN;
}
//------------------<< CIN operator for class >>------------------------
istream& Teacher::operator>>(istream& CIN)
{
	string firstName, lastName, addRess;
	string Contact, username;
	float salary;
	cout << "\n\t  First Name                |              ";
	cin >> firstName;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n\t  Last Name                 |              ";
	getline(cin, lastName);
	username = firstName + "." + lastName + "@nu.edu.pk";
	set_Department();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n\t  ContactNo                 |              ";
	getline(cin, Contact);
	cout << "\n\t  Address                   |              ";
	getline(cin, addRess);
	cout << "\n\t  Salary                    |              ";
	cin >> salary;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n\t  ***********************************************************\n";
	set_FirstName(firstName);
	set_LastName(lastName);
	set_ContactNo(Contact);
	set_Address(addRess);
	set_Salary(salary);
	set_UserName(username);
	return CIN;
}
//------------------<< Cout operator for class >>------------------------
ostream& Teacher::operator<<(ostream& COUT)
{
	cout << "\n  ***********************************************************\n"
		<< "\n                          TEACHER                           \n"
		<< "\n  ***********************************************************\n"
		<< "\n  First Name                |              " << get_FirstName() << endl;
	cout << "\n  Last Name                 |              " << get_LastName() << endl;
	cout << "\n  Department                |              " << get_DepartmentName() << endl;
	cout << "\n  ID                        |              " << get_ID() << endl;
	cout << "\n  Regisration Date          |              " << get_RegistrationDate() << endl;
	cout << "\n  Gender                    |              " << get_Gender() << endl;
	cout << "\n  Contact No                |              " << get_ContactNo() << endl;
	cout << "\n  Salary                    |              " << get_Salary() << endl;
	cout << "\n  Qualifications            |              " << get_Qualifications() << endl;
	cout << "\n  Blood Group               |              " << get_BloodGroup() << endl;
	cout << "\n  Address                   |              " << get_Address() << endl;
	cout << "\n\t  *******************************************"
		<< "\n                        COURSE                           \n";
	for (int j = 0; j < 3; j++)
	{
		cout << "\t " << j + 1 << ". " << Courses[j] << endl;
	}
	cout << "\n\t  *******************************************\n";
	return COUT;
}
//------------------<< Copy Constructor >>------------------------
Teacher::Teacher(Teacher& PassedTeacher) :Person(PassedTeacher)
{
	this->Salary = PassedTeacher.Salary;
}
//------------------<< Assignment Operator >>------------------------
Teacher Teacher::operator=(Teacher& ToCopy)
{
	this->Teacher::Teacher(ToCopy);
	return *this;
}
//------------------<< Seting Courses >>------------------------
void Teacher::Set_courses(Teacher*& PassedTeacher, int Index)
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
		if (PassedTeacher[Index].get_DepartmentName() == ReadingDepartment)
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
void Teacher::set_CourseName(string CourseName, int Index)
{
	Courses[Index] = CourseName;
}
//------------------<< Showing Registered Courses >>------------------------
void Teacher::DisplaytoEditTeacher(Teacher*& Staff, int NumberofTeacher)
{
	for (int i = 0; i < NumberofTeacher; i++)
	{

		cout << "\n\t  Name                      |              "
			<< Staff[i].get_FirstName() << " " << Staff[i].get_LastName() << endl;
		cout << "\n\t  User Name                 |              "
			<< Staff[i].get_UserName() << endl;
	}
}
//--------------------------------<< Salary >>----------------------------------------
//---------->> Setter
void Teacher::set_Salary(float Salary)
{
	this->Salary = Salary;
}
//---------->> Getter
float Teacher::get_Salary()
{
	return Salary;
}
//------------------<< Showing Registered Courses >>------------------------
void Teacher::RegisteredCourses()
{
	cout << "\n\t  ***********************************************************\n"
		<< "\n					     REGISTERED COURSES                    ";
	for (int i = 0; i < 3; i++)
	{
		cout << "\n\t" << i + 1 << ". " << Courses[i];
	}
	cout << "\n\n\t  ***********************************************************\n";
}
//------------------<<Mark Attandance >>------------------------
void Teacher::MarkAttandance(Student*& ClassofStudents, int NumberofStdents)
{
	cout << "\n\t  ***********************************************************\n"
		<< "\n\t                          ATTANDANCE                          \n"
		<< "\n\t  ***********************************************************\n";
	ofstream MarkingAttandance;
	MarkingAttandance.open("Files/Attandance.txt", ios::beg | ios::app);
	string Date, Day, Attandance;
	cout << "\n\t  Date                |              ";
	cin >> Date;
	cout << "\n\t  Day                 |              ";
	cin >> Day;
	cout << "\n\t\tAttandance";
	for (int i = 0; i < NumberofStdents; i++)
	{
		MarkingAttandance.ios::beg;
		cout << "\n\t" << ClassofStudents[i].get_ID() << " "
			<< ClassofStudents[i].get_FirstName() << " " << ClassofStudents[i].get_LastName() << " = ";
		cin >> Attandance;
		MarkingAttandance << ClassofStudents[i].get_UserName() << endl;
		MarkingAttandance << Date << "\n" << Day << "\n" << Attandance << endl;
	}
	MarkingAttandance.close();
}
//------------------<<Mark Marks >>------------------------
void Teacher::AssigningMarks(Student*& Section, int NumberofStdents)
{
	cout << "\n\t  ***********************************************************\n"
		<< "\n\t                              MARKS                          \n"
		<< "\n\t  ***********************************************************\n";
	ofstream AssigningMArks;
	int Option;
	AssigningMArks.open("Files/Marks.txt", ios::beg | ios::app);
	string Marks;
	RegisteredCourses();
	cout << "\n\t  Course                    |              ";
	cin >> Option;
	while (Option < 1 || Option>3)
	{
		cout << "\n\t  Course  Valid             |              ";
		cin >> Option;
	}
	for (int i = 0; i < NumberofStdents; i++)
	{
		AssigningMArks.ios::beg;
		for (int j = 0; j < 3; j++)
		{
			if (Courses[Option - 1] == Section[i].Courses[j])
			{
				cout << "\n\t" << Section[i].get_ID() << " "
					<< Section[i].get_FirstName() << " " << Section[i].get_LastName() << " = ";
				cin >> Marks;
				AssigningMArks << Section[i].get_UserName() << endl;
				AssigningMArks << Section[i].Courses[j] << "\n" << Marks << endl;
			}
		}
	}
	AssigningMArks.close();
}
//------------------<<Mark Grades >>------------------------
void Teacher::AssignGrades(Student*& Section, int NumberofStdents)
{
	cout << "\n\t  ***********************************************************\n"
		<< "\n\t                             GRADES                          \n"
		<< "\n\t  ***********************************************************\n";
	ofstream MarkingGrades;
	int Option;
	MarkingGrades.open("Files/Grades.txt", ios::beg | ios::app);
	string Subject, Grade;
	RegisteredCourses();
	cout << "\n\t  Course                    |              ";
	cin >> Option;
	while (Option < 1 || Option>3)
	{
		cout << "\n\t  Course  Valid             |              ";
		cin >> Option;
	}
	for (int i = 0; i < NumberofStdents; i++)
	{
		MarkingGrades.ios::beg;
		for (int j = 0; j < 3; j++)
		{
			if (Courses[Option - 1] == Section[i].Courses[j])
			{
				cout << "\n\t" << Section[i].get_ID() << " "
					<< Section[i].get_FirstName() << " " << Section[i].get_LastName() << " = ";
				cin >> Grade;
				MarkingGrades << Section[i].get_UserName() << endl;
				MarkingGrades << Subject << "\n" << Grade << endl;
			}
		}
	}
	MarkingGrades.close();
}
//------------------<< Show Time Table >>------------------------
void Teacher::ShowTimeTable(Teacher*& StaffRoom, int Index)
{
	TimesNewRoman.loadFromFile("Fonts/TimesNewRoman.ttf");
	Algerian.loadFromFile("Fonts/Algerian.ttf");
	RenderWindow TimeTable(VideoMode(800, 600), "Time Table!");
	Texture TimeTableImage;
	TimeTableImage.loadFromFile("Backgrounds/TimeTable.jpg");
	RectangleShape VeiwofTimeTable;
	VeiwofTimeTable.setSize(Vector2f(800, 650));
	VeiwofTimeTable.setTexture(&TimeTableImage);
	Text Heading;
	Heading.setFont(Algerian);
	Heading.setString("Time table");
	Heading.setCharacterSize(60);
	Heading.setFillColor(Color(255, 255, 255, 100));
	Heading.setOutlineColor(Color::Black);
	Heading.setOutlineThickness(4);
	Heading.setPosition(200, 50);
	Text Monday, Tuesday, Wednesday, Thursday, Friday;
	Monday.setFont(TimesNewRoman);
	Monday.setString("Monday");
	Monday.setCharacterSize(30);
	Monday.setFillColor(Color(255, 255, 255));
	Monday.setOutlineColor(Color(105, 105, 105));
	Monday.setOutlineThickness(4);
	Monday.setPosition(50, 150);

	Tuesday.setFont(TimesNewRoman);
	Tuesday.setString("Tuesday");
	Tuesday.setCharacterSize(30);
	Tuesday.setFillColor(Color(255, 255, 255));
	Tuesday.setOutlineColor(Color(105, 105, 105));
	Tuesday.setOutlineThickness(4);
	Tuesday.setPosition(50, 230);

	Wednesday.setFont(TimesNewRoman);
	Wednesday.setString("Wednesday");
	Wednesday.setCharacterSize(30);
	Wednesday.setFillColor(Color(255, 255, 255));
	Wednesday.setOutlineColor(Color(105, 105, 105));
	Wednesday.setOutlineThickness(4);
	Wednesday.setPosition(50, 310);

	Thursday.setFont(TimesNewRoman);
	Thursday.setString("Thursday");
	Thursday.setCharacterSize(30);
	Thursday.setFillColor(Color(255, 255, 255));
	Thursday.setOutlineColor(Color(105, 105, 105));
	Thursday.setOutlineThickness(4);
	Thursday.setPosition(50, 390);

	Friday.setFont(TimesNewRoman);
	Friday.setString("Friday");
	Friday.setCharacterSize(30);
	Friday.setFillColor(Color(255, 255, 255));
	Friday.setOutlineColor(Color(105, 105, 105));
	Friday.setOutlineThickness(4);
	Friday.setPosition(50, 480);
	ifstream ReadingTimeTable;
	ReadingTimeTable.open("Files/TimeTable.txt");
	string MondayTime, MondayLecture;
	string TuesdayTime, TuesdayLecture;
	string WednesdayTime, WednesdayLecture;
	string ThursdayTime, ThursdayLecture;
	string FridayTime, FridayLecture, Department;
	while (ReadingTimeTable.good())
	{
		getline(ReadingTimeTable, Department);
		if (StaffRoom[Index].get_DepartmentName() == Department)
		{
			ReadingTimeTable >> MondayTime;
			getline(ReadingTimeTable, MondayLecture);
			ReadingTimeTable >> TuesdayTime;
			getline(ReadingTimeTable, TuesdayLecture);
			ReadingTimeTable >> WednesdayTime;
			getline(ReadingTimeTable, WednesdayLecture);
			ReadingTimeTable >> ThursdayTime;
			getline(ReadingTimeTable, ThursdayLecture);
			ReadingTimeTable >> FridayTime;
			getline(ReadingTimeTable, FridayLecture);
		}
	}
	ReadingTimeTable.close();
	Text MondayT, TuesdayT, WednesdayT, ThursdayT, FridayT;
	MondayT.setFont(TimesNewRoman);
	MondayT.setString(MondayTime);
	MondayT.setCharacterSize(20);
	MondayT.setFillColor(Color(255, 255, 255, 100));
	MondayT.setOutlineColor(Color::Black);
	MondayT.setOutlineThickness(4);
	MondayT.setPosition(220, 160);

	TuesdayT.setFont(TimesNewRoman);
	TuesdayT.setString(TuesdayTime);
	TuesdayT.setCharacterSize(20);
	TuesdayT.setFillColor(Color(255, 255, 255, 100));
	TuesdayT.setOutlineColor(Color::Black);
	TuesdayT.setOutlineThickness(4);
	TuesdayT.setPosition(220, 240);

	WednesdayT.setFont(TimesNewRoman);
	WednesdayT.setString(WednesdayTime);
	WednesdayT.setCharacterSize(20);
	WednesdayT.setFillColor(Color(255, 255, 255, 100));
	WednesdayT.setOutlineColor(Color::Black);
	WednesdayT.setOutlineThickness(4);
	WednesdayT.setPosition(220, 320);

	ThursdayT.setFont(TimesNewRoman);
	ThursdayT.setString(ThursdayTime);
	ThursdayT.setCharacterSize(20);
	ThursdayT.setFillColor(Color(255, 255, 255, 100));
	ThursdayT.setOutlineColor(Color::Black);
	ThursdayT.setOutlineThickness(4);
	ThursdayT.setPosition(220, 400);

	FridayT.setFont(TimesNewRoman);
	FridayT.setString(FridayTime);
	FridayT.setCharacterSize(20);
	FridayT.setFillColor(Color(255, 255, 255, 100));
	FridayT.setOutlineColor(Color::Black);
	FridayT.setOutlineThickness(4);
	FridayT.setPosition(220, 490);
	Text MondayLT, TuesdayLT, WednesdayLT, ThursdayLT, FridayLT;
	MondayLT.setFont(TimesNewRoman);
	MondayLT.setString(MondayLecture);
	MondayLT.setCharacterSize(20);
	MondayLT.setFillColor(Color(255, 255, 255));
	MondayLT.setOutlineColor(Color(105, 105, 105));
	MondayLT.setOutlineThickness(4);
	MondayLT.setPosition(350, 160);

	TuesdayLT.setFont(TimesNewRoman);
	TuesdayLT.setString(TuesdayLecture);
	TuesdayLT.setCharacterSize(20);
	TuesdayLT.setFillColor(Color(255, 255, 255));
	TuesdayLT.setOutlineColor(Color(105, 105, 105));
	TuesdayLT.setOutlineThickness(4);
	TuesdayLT.setPosition(350, 240);

	WednesdayLT.setFont(TimesNewRoman);
	WednesdayLT.setString(WednesdayLecture);
	WednesdayLT.setCharacterSize(20);
	WednesdayLT.setFillColor(Color(255, 255, 255));
	WednesdayLT.setOutlineColor(Color(105, 105, 105));
	WednesdayLT.setOutlineThickness(4);
	WednesdayLT.setPosition(350, 320);

	ThursdayLT.setFont(TimesNewRoman);
	ThursdayLT.setString(ThursdayLecture);
	ThursdayLT.setCharacterSize(20);
	ThursdayLT.setFillColor(Color(255, 255, 255));
	ThursdayLT.setOutlineColor(Color(105, 105, 105));
	ThursdayLT.setOutlineThickness(4);
	ThursdayLT.setPosition(350, 400);

	FridayLT.setFont(TimesNewRoman);
	FridayLT.setString(FridayLecture);
	FridayLT.setCharacterSize(20);
	FridayLT.setFillColor(Color(255, 255, 255));
	FridayLT.setOutlineColor(Color(105, 105, 105));
	FridayLT.setOutlineThickness(4);
	FridayLT.setPosition(350, 490);
	while (TimeTable.isOpen())
	{
		Event evnt;
		while (TimeTable.pollEvent(evnt))
		{
			if (evnt.type == Event::Closed() || Mouse::isButtonPressed(Mouse::Left))
			{
				TimeTable.close();
			}
		}
		TimeTable.clear();
		TimeTable.draw(VeiwofTimeTable);
		TimeTable.draw(Heading);
		TimeTable.draw(Monday);
		TimeTable.draw(MondayT);
		TimeTable.draw(MondayLT);
		TimeTable.draw(Tuesday);
		TimeTable.draw(TuesdayT);
		TimeTable.draw(TuesdayLT);
		TimeTable.draw(Wednesday);
		TimeTable.draw(WednesdayT);
		TimeTable.draw(WednesdayLT);
		TimeTable.draw(Thursday);
		TimeTable.draw(ThursdayT);
		TimeTable.draw(ThursdayLT);
		TimeTable.draw(Friday);
		TimeTable.draw(FridayT);
		TimeTable.draw(FridayLT);
		TimeTable.display();
	}
}
//--------------------------------<< ID >>----------------------------------------
void Teacher::GeneratingID()
{
	string Savingint;
	srand(time(NULL));
	int IDLast3Digits = rand() % 999 + 1;
	stringstream intConverting;
	intConverting << IDLast3Digits;
	intConverting >> Savingint;
	if (get_DepartmentName() == "Computer Science")
	{
		IDLast3Digits += 1;
		T_ID = "CS-" + Savingint;
	}
	else if (get_DepartmentName() == "Electric Engineering")
	{
		IDLast3Digits += 2;
		T_ID = "EE-" + Savingint;
	}
	else if (get_DepartmentName() == "Software Engineering")
	{
		IDLast3Digits += 3;
		T_ID = "SE-" + Savingint;
	}
	else if (get_DepartmentName() == "Business")
	{
		IDLast3Digits += 4;
		T_ID = "B-" + Savingint;
	}
	else if (get_DepartmentName() == "Social Sciences")
	{
		IDLast3Digits += 5;
		T_ID = "SS-" + Savingint;
	}
	cout << "\n\t  ID                        |              " << T_ID << endl;
}
//--------------------------------<< ID >>----------------------------------------
//---------->> Setter
void Teacher::set_ID(string ID)
{
	T_ID = ID;
}
//---------->> Getter
string Teacher::get_ID()
{
	return T_ID;
}
//////////////////////////////////////////////////////////////
//--------------------->> Menu options and view functions
//---------------<< SFML MENU FUNCTIONS >>------------------
Teacher::Teacher(float Width, float Height)
{
	Salary = 0;
	Algerian.loadFromFile("Fonts/Algerian.ttf");
	MilkShake.loadFromFile("Fonts/Milkshake.ttf");
	Thunder.loadFromFile("Fonts/Thunder.ttf");
	TimesNewRoman.loadFromFile("Fonts/TimesNewRoman.ttf");
	MainMenuImage.loadFromFile("Backgrounds/AdminBackground.jpg");

	MenuBackgrounImageShape.setSize(Vector2f(1000, 650));
	MenuBackgrounImageShape.setTexture(&MainMenuImage);

	MenuHeading.setFont(Algerian);
	MenuHeading.setString("Teacher");
	MenuHeading.setFillColor(Color(255, 255, 255, 1500));
	MenuHeading.setCharacterSize(70);
	MenuHeading.setOutlineThickness(3);
	MenuHeading.setOutlineColor(Color(0, 0, 0));
	MenuHeading.setPosition(Vector2f(40, 50));

	MainOptionsProvided[0].setFont(MilkShake);
	MainOptionsProvided[0].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[0].setString("Time Table");
	MainOptionsProvided[0].setCharacterSize(45);
	MainOptionsProvided[0].setOutlineColor(Color::Black);
	MainOptionsProvided[0].setOutlineThickness(3);
	MainOptionsProvided[0].setPosition(Vector2f(Width / 6.9, 180));

	MainOptionsProvided[1].setFont(MilkShake);
	MainOptionsProvided[1].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[1].setString("Assign Attandance");
	MainOptionsProvided[1].setCharacterSize(45);
	MainOptionsProvided[1].setOutlineColor(Color::Black);
	MainOptionsProvided[1].setOutlineThickness(3);
	MainOptionsProvided[1].setPosition(Vector2f(Width / 6.9, 270));

	MainOptionsProvided[2].setFont(MilkShake);
	MainOptionsProvided[2].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[2].setString("Assign Grades");
	MainOptionsProvided[2].setCharacterSize(45);
	MainOptionsProvided[2].setOutlineColor(Color::Black);
	MainOptionsProvided[2].setOutlineThickness(3);
	MainOptionsProvided[2].setPosition(Vector2f(Width / 7.9, 360));

	MainOptionsProvided[3].setFont(MilkShake);
	MainOptionsProvided[3].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[3].setString("Assign Marks");
	MainOptionsProvided[3].setCharacterSize(45);
	MainOptionsProvided[3].setOutlineColor(Color::Black);
	MainOptionsProvided[3].setOutlineThickness(3);
	MainOptionsProvided[3].setPosition(Vector2f(Width / 7.9, 450));

	MainOptionsProvided[4].setFont(MilkShake);
	MainOptionsProvided[4].setFillColor(Color(255, 255, 255, 1500));
	MainOptionsProvided[4].setString("Exit");
	MainOptionsProvided[4].setCharacterSize(70);
	MainOptionsProvided[4].setOutlineColor(Color::Black);
	MainOptionsProvided[4].setOutlineThickness(3);
	MainOptionsProvided[4].setPosition(Vector2f(Width / 6.5, 520));

	MenuOptionSelected = 0;
}
//---------------<< MOVE UP Function >>-------------------
void Teacher::MoveUp()
{
	if (MenuOptionSelected - 1 >= 0)
	{
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(255, 255, 255, 1500));
		MenuOptionSelected--;
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(105, 105, 105));
	}
}
//---------------<< MOVE DOWN Function >>-------------------
void Teacher::MoveDown()
{
	if (MenuOptionSelected + 1 < MaxTeacherTasks)
	{
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(255, 255, 255, 1500));
		MenuOptionSelected++;
		MainOptionsProvided[MenuOptionSelected].setFillColor(Color(105, 105, 105));
	}
}
//---------------<< GETTER for selected Option >>------------
int Teacher::get_SelectedOption()
{
	return MenuOptionSelected;
}
//---------------<< DRAw Functions >>-------------------
void Teacher::Draw(RenderWindow& Windows)
{
	Windows.draw(MenuBackgrounImageShape);
	Windows.draw(MenuHeading);
	for (int i = 0; i < MaxTeacherTasks; i++)
	{
		Windows.draw(MainOptionsProvided[i]);
	}
}
//////////////////////////////////////////////////////////////