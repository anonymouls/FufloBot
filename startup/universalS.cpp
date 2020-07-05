//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.IniFiles.hpp>

#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit3.cpp", Form3);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
 TIniFile * DEV = new TIniFile(ExtractFilePath(Application->ExeName)+"DEBUG.ini");
	try
	{
	 HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, 0, L"ACRG");
	  if(!hMutex)
	   hMutex = CreateMutex(0, 0, L"ACRG");
	  else {
	   HWND hWnd = FindWindow(0, L"ACRG");
	   SetForegroundWindow(hWnd);
	   ShowWindow(hWnd, SW_SHOW);
	   }
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->Run();
		ReleaseMutex(hMutex);
		CloseHandle(hMutex);
	}
	catch (Exception &exception)
	{
		DEV->WriteString("Error",rand()+1,exception.Message);
		DEV->Free();
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			DEV->WriteString("Error",rand()+1,exception.Message);
			DEV->Free();
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
