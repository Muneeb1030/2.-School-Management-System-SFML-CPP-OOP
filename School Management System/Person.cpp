#include"AllLibIncluded.h"
void Person::set_Department()
{
	cout << "\n\t\t  *************************************************\n"
		<< "\n\t\t                     DEPARTMENT                           ";
	string departemnt;
	string Departments[DepartmentNumber];
	Departments[0] = "Computer Science";
	Departments[1] = "Electric Engineering";
	Departments[2] = "Software Engineering";
	Departments[3] = "Business";
	Departments[4] = "Social Sciences";
	for (int i = 0; i < DepartmentNumber; i++)
	{
		cout << "\n\t\t   " << i + 1 << ". " << Departments[i];
	}
	cout << "\n\t\t  *************************************************\n";
	int Option;
	cout << "\n\t  Department Number         |              ";
	cin >> Option;
	switch (Option)
	{
	case 1:
		departemnt = Departments[0];
		break;
	case 2:
		departemnt = Departments[1];
		break;
	case 3:
		departemnt = Departments[2];
		break;
	case 4:
		departemnt = Departments[3];
		break;
	case 5:
		departemnt = Departments[4];
		break;
	default:
		cout << "\n\n\tPlease Select Valid Option\n";
		break;
	}
	set_DepartmentName(departemnt);
}
//----------------------<< Default Constructor >>--------------------------
Person::Person()
{
	FirstName = LastName = Address = RegistrationDate = Qualifications = "\0";
	ContactNo = "\0";
	Gender = '\0';
	DepartmentName = "\0";
	UserName = FeeStatus = Password = BloodGroup = "\0";
}
//--------------------------------<< First Name >>----------------------------------------
//--------->> Settter
void Person::set_FirstName(string firstname)
{
	FirstName = firstname;
}
//--------->> Getter
string Person::get_FirstName()
{
	return FirstName;
}
//--------------------------------<< Last Name >>----------------------------------------
//--------->> Settter
void Person::set_LastName(string lastname)
{
	LastName = lastname;
}
//--------->> Gettter
string Person::get_LastName()
{
	return LastName;
}
//--------------------------------<< Blood Group >>----------------------------------------
//--------->> Settter
void Person::set_BloodGroup(string blood)
{
	BloodGroup = blood;
}
//--------->> Gettter
string Person::get_BloodGroup()
{
	return BloodGroup;
}
//--------------------------------<< Qualifications >>----------------------------------------
//--------->> Settter
void Person::set_Qualifications(string qualifications)
{
	Qualifications = qualifications;
}
//--------->> Gettter
string Person::get_Qualifications()
{
	return Qualifications;
}
//--------------------------------<< Department >>----------------------------------------
//--------->> Settter
void Person::set_DepartmentName(string departemnt)
{
	DepartmentName = departemnt;
}
//--------->> Gettter
string Person::get_DepartmentName()
{
	return DepartmentName;
}
//--------------------------------<< Address >>----------------------------------------
//--------->> Settter
void Person::set_Address(string address)
{
	Address = address;
}
//--------->> Gettter
string Person::get_Address()
{
	return Address;
}
//--------------------------------<< Fee Status >>----------------------------------------
//--------->> Settter
void Person::set_FeeStatus(string status)
{
	FeeStatus = status;
}
//--------->> Gettter
string Person::get_FeeStatus()
{
	return FeeStatus;
}
//--------------------------------<< Registration Date >>----------------------------------------
	//--------->> Settter
void Person::set_RegistrationDate(string registrationdate)
{
	RegistrationDate = registrationdate;
}
//--------->> Gettter
string Person::get_RegistrationDate()
{
	return RegistrationDate;
}
//--------------------------------<< Contact Number >>----------------------------------------
//--------->> Settter
void Person::set_ContactNo(string Contact)
{
	ContactNo = Contact;
}
//--------->> Gettter
string Person::get_ContactNo()
{
	return ContactNo;
}
//--------------------------------<< Gender >>----------------------------------------
//--------->> Settter
void Person::set_Gender(char gender)
{
	Gender = gender;
}
//--------->> Gettter
char Person::get_Gender()
{
	return Gender;
}
//--------------------------------<< User Name >>----------------------------------------
//--------->> Settter
void Person::set_UserName(string username)
{
	UserName = username;
}
//--------->> Getter
string Person::get_UserName()
{
	return UserName;
}
//--------------------------------<< Password >>----------------------------------------
//--------->> Settter
void Person::set_Password(string password)
{
	Password = password;
}
//--------->> Gettter
string Person::get_Password()
{
	return Password;
}