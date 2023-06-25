#pragma once
//------------------------<< MAIN HEADER FILE >>-------------------------------
//------------>> All the Libraries, Header Files and Galobal Variables that
//will be used in the program will be declared in this Header File
//In order to provide easy understanding and effective code alignment...
//------------>>header file for SFML MAIN MENU
#include"Menu.h"	
#include"Admin.h"	
#include"Person.h"
#include"Teacher.h"
#include"Student.h"
//------------>>AUDIO LIBRARY OF SFML
#include<SFML/Audio.hpp>	
#include<SFML/Graphics.hpp>	
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<exception>
//------------>>TO CONVERT STRING INTO INT
#include<sstream>	
#include<Windows.h>
//------------>>FOR RANDOM FUNCTION
#include<cstdlib>	
#include<time.h>
#include<stdlib.h>
using namespace std;
using namespace sf;
//---------------->> FOR ERROR MESSAGES
void Notification(Text PassedDisplay, string& PassedMessage);	