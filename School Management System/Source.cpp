//------------>> All Libraries that will be used int the programme....
#include"AllLibIncluded.h"
//------------>> Objects of Fonts......
Font TimesNewRoman, Algerian, MilkShake, Thunder;
//----------->> to call login function of particular user
int CurrentUser = 0;
//----------->> Pointers of the class the to make dynamic array later on.
//------->> these are declared globally in order to provided easy access to 
//class objects and easy maintainance....
Teacher* Staff;
Student* Section;
Admin Administrator;
//------->> size of my dynamic arrays of student and teachers in my programme.
int NumberofTeacher, NumberofStudents;
//------->> these variables will be used to get the index of the respective 
//student or teacher that is loged in.....
int TeacherLogedin = -1, StudentLogedin = -1;
//-------------<< Prototypes >>----------------------
//-------------<< First Screen >>--------------------
//of SFML means introduction Screen....
void Introduction();
//---------->> These function are used in order to initalize two two
//dummy values in the programme to use it on the first run without
//any problem...
void TeacherDummyInitialization();
void StudentDummyInitialization();
//-------=--------<< First Menu >>------------------
void MainMenu(RenderWindow& Windows);
//----------------<< Sub Menus >>---------------------
//----------->> Admin Menu<Tasks>
int AdminMenu();
//----------->> Teacher Menu<Tasks>
int TeacherMenu();
//----------->> Student Menu<Tasks>
int StudentMenu();
//--------------<< Login Function >>-------------------
bool Login();
//-------------<< Admin UserName and Password >>--------------
void AdminCredential(string& UserName, string& Password);
//-------------<< Teacher UserName and Password >>--------------
//-------->> UserName and Password would be compared from data from file
void TeacherCredential(string& LoginName, string& LoginKey, bool& Match);
//-------------<< Student UserName and Password >>--------------
//-------->> UserName and Password would be compared from data from file
void StudentCredential(string& LoginName, string& LoginKey, bool& Match);
//------------<< Course Allotment >>---------------------
bool is_CourseAvailable();
//---------------<< Virtual Initailzation of  data >>--------------------
void VirtualInitialization();
int main()
{
    //////////////////////////////////////////////////////////////
    //Dummy Initalization of Student and Teacher Data           //
    //Number of Teacher and Students will be 2 in the starting  //
    // this number can be increased by admin later on           //
    //////////////////////////////////////////////////////////////
    VirtualInitialization();
    //----------------<< Fonts Set >>--------------------
    //////////////////////////////////////////////////////////////////////////
    //The followings are all the fonts that will be used in the program,    //
    //According to the Requirement......                                    // 
    // The Objects of the Fonts are Created int header file...              //
    //////////////////////////////////////////////////////////////////////////
    //--------->> the error Message if a font is found missing
    string MessagetoDisplay = "\0";
    //the Text Object to show the message on SFML Wimdows
    Text DisplayNotification;
    //------>> Loading Fonts from respective folder from font folder
    if (!TimesNewRoman.loadFromFile("Fonts/TimesNewRoman.ttf"))
    {
        MessagetoDisplay = "\n\t\t  Sorry!\n     The Font Style\n\"Times New Roman\"\n    is not Available\n";
        DisplayNotification.setFont(MilkShake);
        DisplayNotification.setCharacterSize(30);
    }
    if (!Algerian.loadFromFile("Fonts/Algerian.ttf"))
    {
        MessagetoDisplay = "\n\t\t  Sorry!\n     The Font Style\n        \"Algerian\"\n    is not Available\n";
        DisplayNotification.setFont(MilkShake);
        DisplayNotification.setCharacterSize(30);
    }
    if (!MilkShake.loadFromFile("Fonts/Milkshake.ttf"))
    {
        MessagetoDisplay = "\n\t\t  Sorry!\n     The Font Style\n      \"MilkShake\"\n    is not Available\n";
        DisplayNotification.setFont(Thunder);
        DisplayNotification.setCharacterSize(30);
    }
    if (!Thunder.loadFromFile("Fonts/Thunder.ttf"))
    {
        MessagetoDisplay = "\n\t\t  Sorry!\n     The Font Style\n        \"Thunder\"\n    is not Available\n";
        DisplayNotification.setFont(MilkShake);
        DisplayNotification.setCharacterSize(30);
    }
    /////////////////////////////////////////////////////////////////////////
    DisplayNotification.setFillColor(Color(139, 28, 98));                  //
    DisplayNotification.setPosition(Vector2f(85, 25));                     //    
    DisplayNotification.setOutlineThickness(3);                            //
    DisplayNotification.setOutlineColor(Color::White);                     //
    DisplayNotification.setString(MessagetoDisplay);                       //       
    /////////////////////////////////////////////////////////////////////////
    //------------------<< The First Screen >>-------------------------
    //Basically the IntroDuction of the Project and group Members
    Introduction();
    ///////////////////////////////////////////////////////////////////////////
    RenderWindow ApplicationInterface(VideoMode(1000, 650), "Manage It", Style::Default | Style::Resize);
    while (ApplicationInterface.isOpen())
    {
        Event evnt;
        while (ApplicationInterface.pollEvent(evnt))
        {
            if (evnt.type == Event::Closed() || evnt.key.code == Keyboard::Escape)
            {
                ApplicationInterface.close();
            }
        }
        //---------->> To display Font Style Error not found Message 
        if (MessagetoDisplay != "\0")
        {
            Notification(DisplayNotification, MessagetoDisplay);
        }
        //---------->> This Function will return the value user wan to exit 
        //the menu..
        MainMenu(ApplicationInterface);
    }
    delete[]Staff;
    delete[]Section;
    Staff = nullptr;
    Section = nullptr;
    system("pause>0");
    return 0;
}
void VirtualInitialization()
{
    //---------->> Initailly the number of teacher nad student will be 2
    NumberofTeacher = 2;
    Staff = new Teacher[NumberofTeacher];//dynamic array of teacher
    //----------->> Function Call
    TeacherDummyInitialization();
    NumberofStudents = 2;
    Section = new Student[NumberofStudents];//dynamic array of student
     //----------->> Function Call
    StudentDummyInitialization();
}
void Introduction()
{
    Texture IntroBackground;//to get image on screen
    IntroBackground.loadFromFile("Backgrounds/Startup.jpg");
    RectangleShape IntroImageShape;//to spacify the size of image
    IntroImageShape.setSize(Vector2f(1000, 650));
    IntroImageShape.setTexture(&IntroBackground);
    //text objects for loading text on screen
    Text ProgramName, Muneeb, Muzaffer;
    //------------>> Heading of the IntroScreen
    //its formating and position alteration.
    ProgramName.setFont(Algerian);
    ProgramName.setString("Management\n\t System");
    ProgramName.setFillColor(Color(255, 165, 0));
    ProgramName.setCharacterSize(65);
    ProgramName.setLineSpacing(0.9);
    ProgramName.setLetterSpacing(2);
    ProgramName.setOutlineThickness(0.5);
    ProgramName.setOutlineColor(Color(0, 0, 0));
    ProgramName.setPosition(Vector2f(260, 60));
   // //------------>> First Group Name on the IntroScreen
   // //its formating and position alteration.
   // Muneeb.setFont(MilkShake);
   // Muneeb.setString("Muneeb\n1030");
   // Muneeb.setFillColor(Color(255, 165, 0));
   // Muneeb.setCharacterSize(30);
   // Muneeb.setLineSpacing(0.9);
   // Muneeb.setLetterSpacing(2);
   // Muneeb.setOutlineThickness(2);
   // Muneeb.setOutlineColor(Color::Black);
   // Muneeb.setPosition(Vector2f(20, 500));
   // //------------>> First Group Name on the IntroScreen
   ////its formating and position alteration.
   // Muzaffer.setFont(MilkShake);
   // Muzaffer.setString("Muzaffer\n20F-0129");
   // Muzaffer.setFillColor(Color(255, 165, 0));
   // Muzaffer.setCharacterSize(30);
   // Muzaffer.setLineSpacing(0.9);
   // Muzaffer.setLetterSpacing(2);
   // Muzaffer.setOutlineThickness(2);
   // Muzaffer.setOutlineColor(Color::Black);
   // Muzaffer.setPosition(Vector2f(830, 500));
    RenderWindow IntroScreen(VideoMode(1000, 650), "Introduction");
    while (IntroScreen.isOpen())
    {
        Event evnt;
        while (IntroScreen.pollEvent(evnt))
        {
            //---------->> Options of Closing The Windows.
            if (evnt.type == Event::Closed() || Mouse::isButtonPressed(Mouse::Left))
            {
                IntroScreen.close();
            }
        }
        //-------->> Printing things on SFML Windows...
        IntroScreen.clear();
        IntroScreen.draw(IntroImageShape);
        IntroScreen.draw(ProgramName);
        IntroScreen.draw(Muneeb);
        IntroScreen.draw(Muzaffer);
        IntroScreen.display();
    }
}
void Notification(Text PassedDisplay, string& PassedMessage)
{
    RenderWindow Popup(VideoMode(400, 300), "Notification!");
    while (Popup.isOpen())
    {
        Event evnt1;
        while (Popup.pollEvent(evnt1))
        {
            //---------->> Options of Closing The Windows.
            if (evnt1.type == Event::Closed() || Mouse::isButtonPressed(Mouse::Left))
            {
                PassedMessage = "\0";
                Popup.close();
            }
        }
        //-------->> Printing things on SFML Windows...
        Popup.clear(Color(238, 58, 140));
        Popup.draw(PassedDisplay);
        Popup.display();
    }
}
void MainMenu(RenderWindow& Windows)
{
    //----------->> SFML Screen for Menu
    //the functions of getsize will give size of main window size 
    //in order to maintain the size of new windows opened.
    Menu MenuScreen(Windows.getSize().x, Windows.getSize().y);
    while (Windows.isOpen())
    {
        Event evnt;
        //-------->> the event performed in the main menu..
        while (Windows.pollEvent(evnt))
        {
            //if any key pressed from keyboard
            if (evnt.type == Event::KeyReleased)
            {
                // the key pressed unicode is equal to up key unicode then
                //this function wil get called
                if (evnt.key.code == Keyboard::Up)
                {
                    MenuScreen.MoveUp();
                }
                // the key pressed unicode is equal to down key unicode then
                //this function wil get called
                else if (evnt.key.code == Keyboard::Down)
                {
                    MenuScreen.MoveDown();
                }
                // the key pressed unicode is equal to Enter key unicode then
                //this function wil get called
                else if (evnt.key.code == Keyboard::Return)
                {
                    //--------->> enter is pressed
                    //this function will get called to run the switch cases.
                    switch (MenuScreen.get_SelectedOption())
                    {
                    case 0:
                        //if admin is pressed 1 will be assigned to current user
                        //ths will allow to call respective login option
                        CurrentUser = 1;
                        AdminMenu();
                        break;
                    case 1:
                        //if Teacher is pressed 2 will be assigned to current user
                        //ths will allow to call respective login option
                        CurrentUser = 2;
                        TeacherMenu();
                        break;
                    case 2:
                        //if Student is pressed 3 will be assigned to current user
                        //ths will allow to call respective login option
                        CurrentUser = 3;
                        StudentMenu();
                        break;
                    case 3:
                        //if Exit is pressed 
                        // close the windows fntion will be called
                        //ths will allow to call respective login option
                        Windows.close();
                        break;
                    default:
                        cout << "\n\tInvalid Option\n";
                        break;
                    }
                }
            }
            if (evnt.type == Event::Closed())
            {
                Windows.close();
            }
        }
        Windows.clear();
        MenuScreen.Draw(Windows);
        Windows.display();
    }
}
int AdminMenu()
{
    //---------->> first Login functionis called to check the 
    //authenticity of the user loged in...
    //if true is returned the programme will proceed until right nput is not 
    //provided.
    if (Login())
    {
        //----------->> creating a new screen for admin menu
        RenderWindow AdminPage(VideoMode(1000, 650), "Admin", Style::Default | Style::Resize);
        Admin AdminScreen(AdminPage.getSize().x, AdminPage.getSize().y);
        //the size passed to the constrctr will automatically change with the
        //render window object this will allow more dynamic presentation
        while (AdminPage.isOpen())
        {
            Event evnt;
            while (AdminPage.pollEvent(evnt))
            {
                //if any key pressed from keyboard
                if (evnt.type == Event::KeyReleased)
                {
                    // the key pressed unicode is equal to up key unicode then
                    //this function wil get called
                    if (evnt.key.code == Keyboard::Up)
                    {
                        AdminScreen.MoveUp();
                    }
                    // the key pressed unicode is equal to down key unicode then
                //this function wil get called
                    else if (evnt.key.code == Keyboard::Down)
                    {
                        AdminScreen.MoveDown();
                    }
                    // the key pressed unicode is equal to Enter key unicode then
                //this function wil get called
                    else if (evnt.key.code == Keyboard::Return)
                    {
                        switch (AdminScreen.get_SelectedOption())
                        {
                        case 0:
                            Administrator.AddTeacher(Staff, NumberofTeacher);
                            break;
                        case 1:
                            Administrator.EditTeacher(Staff, NumberofTeacher);
                            break;
                        case 2:
                            Administrator.VeiwTeahers(Staff, NumberofTeacher);
                            break;
                        case 3:
                            Administrator.AddStdent(Section, NumberofStudents);
                            break;
                        case 4:
                            Administrator.EditStudent(Section, NumberofStudents);
                            break;
                        case 5:
                            Administrator.VeiwStudents(Section, NumberofStudents);
                            break;
                        case 6:
                            AdminPage.close();
                            return 1;
                            break;
                        }
                    }
                }
                if (evnt.type == Event::Closed())
                {
                    AdminPage.close();
                    return 1;
                }
            }
            AdminPage.clear(Color::Transparent);
            AdminScreen.Draw(AdminPage);
            AdminPage.display();
        }
    }
    return 0;
}
bool Login()
{
    system("color 3F");
    //------------->> formatting of the image and the text <Username and Password>
    //that is later on presentedon the console.
    Texture LoginImage;
    LoginImage.loadFromFile("Backgrounds/Login.png");
    RectangleShape LoginImageDisplay;
    LoginImageDisplay.setSize(Vector2f(300, 250));
    LoginImageDisplay.setTexture(&LoginImage);
    string username = "\0", password = "\0";
    Text UserNameDisplay, PasswordDisplay;
    //------------>> Screen for login image
    RenderWindow LoginPage(VideoMode(300, 220), "Login Page");
    //--------->> these two variable are used nly in admin sign in
    string LoginName, LoginKey;
    //-------->> checking Input is required again or not
    bool matchFound = false;

    while (LoginPage.isOpen())
    {
        /////////////////////////////////////////////////////////////////////
        UserNameDisplay.setFont(TimesNewRoman);                            //
        UserNameDisplay.setCharacterSize(20);                              //
        UserNameDisplay.setFillColor(Color(0, 0, 0, 600));                    //
        UserNameDisplay.setPosition(Vector2f(30, 55));                      //    
        UserNameDisplay.setString(username);                               //       
        /////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////
        PasswordDisplay.setFont(TimesNewRoman);                            //
        PasswordDisplay.setCharacterSize(20);                              //
        PasswordDisplay.setFillColor(Color(0, 0, 0, 600));                 //
        PasswordDisplay.setPosition(Vector2f(30, 130));                    //    
        PasswordDisplay.setString(password);                               //       
        /////////////////////////////////////////////////////////////////////
        Event evnt;
        LoginPage.clear();
        LoginPage.draw(LoginImageDisplay);
        LoginPage.draw(UserNameDisplay);
        LoginPage.draw(PasswordDisplay);
        LoginPage.display();
        if (matchFound == false)
        {
            if (CurrentUser == 1)
            {
                cout << "\n\t  ***************************************\n"
                    << "\n\t                 ADMINSTRATION    \n"
                    << "\n\t  ***************************************\n";
                cout << "\n\t  User Name                 |              ";
                cin >> username;
                //------->> to avoid any incnvinience
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n\t  Password                  |              ";
                getline(cin, password);
                AdminCredential(LoginName, LoginKey);
                if (username == LoginName)
                {
                    if (password == LoginKey)
                    {
                        matchFound = true;
                    }
                }
                system("cls");
            }
            else if (CurrentUser == 2)
            {
                TeacherCredential(username, password, matchFound);
            }
            else if (CurrentUser == 3)
            {
                StudentCredential(username, password, matchFound);
            }
        }
        while (LoginPage.pollEvent(evnt))
        {
            if (evnt.type == Event::Closed() || Mouse::isButtonPressed(Mouse::Left))
            {
                LoginPage.close();
            }
        }
    }
    return true;
    system("cls");
    system("color 0F");
}
void AdminCredential(string& UserName, string& Password)
{
    //------>> UserName and Password of Admin
    UserName = "ADMIN";
    Password = "admin";
}
void TeacherDummyInitialization()
{
    //----->> ifstream object to get info from file
    ifstream ReadingTeacherData;
    //------->> Opening File
    ReadingTeacherData.open("Files/DummyTeacherData.txt");
    //------->> if Opening File is not hppening
    if (!ReadingTeacherData.is_open())
    {
        cout << "\n\tFile Does not Exist\n";
    }
    //------>> variables to read data from fle in sequence
    string firstName, lastName, registrationDate, addRess, qualification;
    string Contact, username, password, bloodgroup, Department, ID, Course;
    float salary;
    char genDer;
    //reading Data Until end of file or end of array
    for (int i = 0; !ReadingTeacherData.eof() && i < NumberofTeacher; i++)
    {
        if (!ReadingTeacherData.eof())
        {
            getline(ReadingTeacherData, firstName);
            Staff[i].set_FirstName(firstName);
            getline(ReadingTeacherData, lastName);
            Staff[i].set_LastName(lastName);
            getline(ReadingTeacherData, Department);
            Staff[i].set_DepartmentName(Department);
            getline(ReadingTeacherData, ID);
            Staff[i].set_ID(ID);
            getline(ReadingTeacherData, username);
            Staff[i].set_UserName(username);
            getline(ReadingTeacherData, password);
            Staff[i].set_Password(password);
            getline(ReadingTeacherData, registrationDate);
            Staff[i].set_RegistrationDate(registrationDate);
            getline(ReadingTeacherData, Contact);
            Staff[i].set_ContactNo(Contact);
            ReadingTeacherData >> genDer;
            Staff[i].set_Gender(genDer);
            //since i am not using getline function here so for proper functionality
        //i have cleared the input stream
            ReadingTeacherData.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(ReadingTeacherData, addRess);
            Staff[i].set_Address(addRess);
            getline(ReadingTeacherData, qualification);
            Staff[i].set_Qualifications(qualification);
            getline(ReadingTeacherData, bloodgroup);
            Staff[i].set_BloodGroup(bloodgroup);
            ReadingTeacherData >> salary;
            Staff[i].set_Salary(salary);
            //since i am not using getline function here so for proper functionality
            //i have cleared the input stream
            ReadingTeacherData.ignore(numeric_limits<streamsize>::max(), '\n');
            for (int j = 0; j < 3; j++)
            {
                getline(ReadingTeacherData, Course);
                Staff[i].set_CourseName(Course, j);
            }
        }
    }
}
void StudentDummyInitialization()
{
    //----->> ifstream object to get info from file
    ifstream ReadingStudentData;
    //------->> Opening File
    ReadingStudentData.open("Files/DummyStudentData.txt");
    //------->> if Opening File is not hppening
    if (!ReadingStudentData.is_open())
    {
        cout << "\n\tFile Does not Exist\n";
    }
    //------>> variables to read data from fle in sequence
    string firstName, lastName, registrationDate, addRess, qualification;
    string Contact, username, password, bloodgroup, Department, ID, feeStatus, Course;
    char genDer;
    //reading Data Until end of file or end of array
    for (int i = 0; !ReadingStudentData.eof() && i < NumberofTeacher; i++)
    {
        if (!ReadingStudentData.eof())
        {
            getline(ReadingStudentData, firstName);
            Section[i].set_FirstName(firstName);
            getline(ReadingStudentData, lastName);
            Section[i].set_LastName(lastName);
            getline(ReadingStudentData, Department);
            Section[i].set_DepartmentName(Department);
            getline(ReadingStudentData, ID);
            Section[i].set_ID(ID);
            getline(ReadingStudentData, username);
            Section[i].set_UserName(username);
            getline(ReadingStudentData, password);
            Section[i].set_Password(password);
            getline(ReadingStudentData, registrationDate);
            Section[i].set_RegistrationDate(registrationDate);
            getline(ReadingStudentData, Contact);
            Section[i].set_ContactNo(Contact);
            ReadingStudentData >> genDer;
            Section[i].set_Gender(genDer);
            //since i am not using getline function here so for proper functionality
        //i have cleared the input stream
            ReadingStudentData.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(ReadingStudentData, addRess);
            Section[i].set_Address(addRess);
            getline(ReadingStudentData, qualification);
            Section[i].set_Qualifications(qualification);
            getline(ReadingStudentData, bloodgroup);
            Section[i].set_BloodGroup(bloodgroup);
            getline(ReadingStudentData, feeStatus);
            Section[i].set_FeeStatus(feeStatus);
            for (int j = 0; j < 3; j++)
            {
                getline(ReadingStudentData, Course);
                Section[i].set_CourseName(Course, j);
            }
        }
    }
}
void StudentCredential(string& LoginName, string& LoginKey, bool& Match)
{
    ifstream Read_it;
    string GetfromFileName, getFromFilePassword;
    string username, password;
    do
    {
        //----->> This function will get the user name and password from user and
        //compare them with all the usernames and pssowrds given in the file.
        //if the password and username doesnot match then input is again asked
        //until correct input to proceed furthur.
        Read_it.open("StudentUserNames.txt", ios::beg);
        cout << "\n\t  ***************************************\n"
            << "\n\t                 STUDENT    \n"
            << "\n\t  ***************************************\n";
        cout << "\n\t  User Name      |         ";
        cin >> username;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n\t  Password       |         ";
        getline(cin, password);
        while (!Read_it.eof())
        {
            Read_it >> GetfromFileName;
            Read_it >> getFromFilePassword;
            for (int i = 0; i < NumberofStudents; i++)
            {
                if (username == GetfromFileName)
                {
                    if (password == getFromFilePassword)
                    {
                        Match = true;
                        // getting the index of user signed in.
                        StudentLogedin = i;
                        //setting for output on console..
                        LoginName = username;
                        LoginKey = password;
                        system("cls");
                        return;
                    }
                }
            }
        }
        Read_it.close();
        system("cls");
    } while (Match == false);
}
void TeacherCredential(string& LoginName, string& LoginKey, bool& Match)
{
    //----->> This function will get the user name and password from user and
        //compare them with all the usernames and pssowrds given in the file.
        //if the password and username doesnot match then input is again asked
        //until correct input to proceed furthur.
    ifstream Read_it;
    string GetfromFileName, getFromFilePassword;
    string username, password;
    do
    {
        Read_it.open("TeacherUserName.txt", ios::beg);
        cout << "\n\t  ***************************************\n"
            << "\n\t                 TEACHER    \n"
            << "\n\t  ***************************************\n";
        cout << "\n\t  User Name      |         ";
        cin >> username;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n\t  Password       |         ";
        getline(cin, password);
        while (!Read_it.eof())
        {
            Read_it >> GetfromFileName;
            Read_it >> getFromFilePassword;
            for (int i = 0; i < NumberofTeacher; i++)
            {
                if (username == GetfromFileName)
                {
                    if (password == getFromFilePassword)
                    {
                        Match = true;
                        //-------->> gtting the index of teacher signed in
                        TeacherLogedin = i;
                        //--------->> Setting for output on SFML Screen
                        LoginName = username;
                        LoginKey = password;
                        system("cls");
                        return;
                    }
                }
            }
        }
        Read_it.close();
        system("cls");
    } while (Match == false);
}
int TeacherMenu()
{
    //---------->> first Login functionis called to check the 
    //authenticity of the user loged in...
    //if true is returned the programme will proceed until right nput is not 
    //provided.
    if (Login())
    {
        //----------->> creating a new screen for admin menu
        RenderWindow TeacherPage(VideoMode(1000, 650), "Teacher!", Style::Default | Style::Resize);
        //the size passed to the constrctr will automatically change with the
        //render window object this will allow more dynamic presentation
        Teacher TeacherScreen(TeacherPage.getSize().x, TeacherPage.getSize().y);
        //if teacher have selected the curses already then this function will
        //not be called
        if (!is_CourseAvailable())
        {
            //function to assign subjects to teacher
            Staff->Set_courses(Staff, TeacherLogedin);
        }
        while (TeacherPage.isOpen())
        {
            Event evnt;
            while (TeacherPage.pollEvent(evnt))
            {
                //if any key pressed from keyboard   
                if (evnt.type == Event::KeyReleased)
                {
                    // the key pressed unicode is equal to up key unicode then
                    //this function wil get called
                    if (evnt.key.code == Keyboard::Up)
                    {
                        TeacherScreen.MoveUp();
                    }
                    // the key pressed unicode is equal to down key unicode then
                    //this function wil get called
                    else if (evnt.key.code == Keyboard::Down)
                    {
                        TeacherScreen.MoveDown();
                    }
                    else if (evnt.key.code == Keyboard::Return)
                    {
                        switch (TeacherScreen.get_SelectedOption())
                        {
                        case 0:
                            Staff[TeacherLogedin].ShowTimeTable(Staff, TeacherLogedin);
                            break;
                        case 1:
                            Staff[TeacherLogedin].MarkAttandance(Section, NumberofStudents);
                            break;
                        case 2:
                            Staff[TeacherLogedin].AssignGrades(Section, NumberofStudents);
                            break;
                        case 3:
                            Staff[TeacherLogedin].AssigningMarks(Section, NumberofStudents);
                            break;
                        case 4:
                            TeacherPage.close();
                            return 1;
                            break;
                        }
                    }
                }
                if (evnt.type == Event::Closed())
                {
                    TeacherPage.close();
                    return 1;
                }

            }
            TeacherPage.clear(Color::Transparent);
            TeacherScreen.Draw(TeacherPage);
            TeacherPage.display();
        }
    }
    return 0;
}
int StudentMenu()
{
    //---------->> When student want to do some task
    //this function willbe called mean stdent have to login first...
    //if the username and password entered exists in the file 
    //student will be able to desired tasks
    if (Login())//if true is returned from this function..
    {
        //---->> Student Menu <Task> Windw will Appear
        RenderWindow StudentPage(VideoMode(1000, 650), "STUDENT!", Style::Default | Style::Resize);
        //Overloaded constructor of class student is called in order to show the menu.
        Student StudentScreen(StudentPage.getSize().x, StudentPage.getSize().y);
        //if teacher have selected the curses already then this function will
        //not be called
        if (!is_CourseAvailable)
        {
            Section->Set_courses(Section, StudentLogedin);
        }
        while (StudentPage.isOpen())
        {
            Event evnt;
            while (StudentPage.pollEvent(evnt))
            {
                if (evnt.type == Event::KeyReleased)
                {
                    if (evnt.key.code == Keyboard::Up)
                    {
                        StudentScreen.MoveUp();
                    }
                    else if (evnt.key.code == Keyboard::Down)
                    {
                        StudentScreen.MoveDown();
                    }
                    else if (evnt.key.code == Keyboard::Return)
                    {
                        switch (StudentScreen.get_SelectedOption())
                        {
                        case 0:
                            Section[StudentLogedin].veiwAttandance(Section, StudentLogedin);
                            break;
                        case 1:
                            Section[StudentLogedin].veiwGrades(Section, StudentLogedin);
                            break;
                        case 2:
                            Section[StudentLogedin].veiwMarks(Section, StudentLogedin);
                            break;
                        case 3:
                            StudentPage.close();
                            return 1;
                            break;
                        default:
                            break;
                        }
                    }
                }
                if (evnt.type == Event::Closed())
                {
                    StudentPage.close();
                    return 1;
                }
            }
            StudentPage.clear(Color::Transparent);
            StudentScreen.Draw(StudentPage);
            StudentPage.display();
        }
    }
    return 0;
}
bool is_CourseAvailable()
{
    //---------->> This function is friend to both teacher and student class
    if (CurrentUser == 2)
    {
        //if student have courses then not call the assign course function again
        for (int i = 0; i < NumberofStudents; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (Section[i].Courses[j] != "\0")
                {
                    return true;
                }
            }
        }
    }
    else if (CurrentUser == 1)
    {
        //if teacher have courses then not call the assign course function again
        for (int i = 0; i < NumberofTeacher; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (Staff[i].Courses[j] != "\0")
                {
                    return true;
                }
            }
        }
    }
    else
    {
        return false;
    }
}