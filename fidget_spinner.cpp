#include <iostream>
#include <windows.h>

using namespace std;

void barel_roll()
{
    DEVMODE dm;

    dm.dmSize=sizeof(DEVMODE);
    dm.dmDriverExtra=0;

    for (int i = 3; i > -1; i--){
        EnumDisplaySettings(NULL,ENUM_CURRENT_SETTINGS,&dm);
        
        DWORD temp=dm.dmPelsHeight;
        
		dm.dmPelsHeight=dm.dmPelsWidth;
        dm.dmPelsWidth=temp;
        dm.dmDisplayOrientation=i;
        
		Sleep(800);

        if (ChangeDisplaySettings(&dm,0) != DISP_CHANGE_SUCCESSFUL)
	    // L is used to inform the MSVC compiler of required conversion to unicode. GCC compiles without it:
            MessageBox(NULL, L"noce se vrtet", L"neeee error", MB_OK); 
    }
}

int main(int argc, char *argv[])
{
    while(true) 
		barel_roll();
		
    return 0;
}
