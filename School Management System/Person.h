#pragma once
#include<string>
using namespace std;
const int DepartmentNumber = 5;
class Person
{
private:
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//-----------------------------<< Data Members >>-------------------------------
	string FirstName, LastName, UserName, Password;
	string RegistrationDate, FeeStatus;
	char Gender;
	string ContactNo;
	string BloodGroup;
	string Address;
	string Qualifications;
	string DepartmentName;
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//--------------------------------<< Contructors >>----------------------------------------
	//--------------------------------<< Default >>----------------------------------------
	Person();
	//--------------------------------<< copy constructor >>---------------------------------------
	Person(Person& PassedArgument)
	{
		this->FirstName = PassedArgument.FirstName;
		this->LastName = PassedArgument.LastName;
		this->RegistrationDate = PassedArgument.RegistrationDate;
		this->Address = PassedArgument.Address;
		this->Qualifications = PassedArgument.Qualifications;
		this->ContactNo = PassedArgument.ContactNo;
		this->Gender = PassedArgument.Gender;
		this->UserName = PassedArgument.UserName;
		this->Password = PassedArgument.Password;
		this->BloodGroup = PassedArgument.BloodGroup;
		this->DepartmentName = PassedArgument.DepartmentName;
		this->FeeStatus = PassedArgument.FeeStatus;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//--------------------------------<< Getter Setters >>----------------------------------------
	//--------------------------------<< First Name >>----------------------------------------
	//--------->> Settter
	void set_FirstName(string firstname);
	//--------->> Getter
	string get_FirstName();
	//--------------------------------<< Last Name >>----------------------------------------
	//--------->> Settter
	void set_LastName(string lastname);
	//--------->> Gettter
	string get_LastName();

	//--------------------------------<< Blood Group >>----------------------------------------
	//--------->> Settter
	void set_BloodGroup(string bloodgroup);
	//--------->> Gettter
	string get_BloodGroup();
	//--------------------------------<< Qualifications >>----------------------------------------
	//--------->> Settter
	void set_Qualifications(string qualifications);
	//--------->> Gettter
	string get_Qualifications();
	//--------------------------------<< Address >>----------------------------------------
	//--------->> Settter
	void set_Address(string address);
	//--------->> Gettter
	string get_Address();
	//--------------------------------<< Registration Date >>----------------------------------------
	//--------->> Settter
	void set_RegistrationDate(string registrationdate);
	//--------->> Gettter
	string get_RegistrationDate();
	//--------------------------------<< Contact Number >>----------------------------------------
	//--------->> Settter
	void set_ContactNo(string Contact);
	//--------->> Gettter
	string get_ContactNo();
	//--------------------------------<< Fee Status >>----------------------------------------
	//--------->> Settter
	void set_FeeStatus(string status);
	//--------->> Gettter
	string get_FeeStatus();
	//--------------------------------<< Gender >>----------------------------------------
	//--------->> Settter
	void set_Gender(char gender);
	//--------->> Gettter
	char get_Gender();
	//--------------------------------<< Password >>----------------------------------------
	//--------->> Settter
	void set_Password(string password);
	//--------->> Getter
	string get_Password();
	//--------------------------------<< User Name >>----------------------------------------
	//--------->> Settter
	void set_UserName(string username);
	//--------->> Gettter
	string get_UserName();
	//--------------------------------<< User Name >>----------------------------------------
	//--------->> Settter
	void set_Department();
	void set_DepartmentName(string department);
	//---------->> Getter
	string get_DepartmentName();
};