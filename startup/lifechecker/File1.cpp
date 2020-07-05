#include <vcl.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <System.IniFiles.hpp>
#include <stdio.h>
#include <iostream>

struct EnumData {
    DWORD dwProcessId;
    HWND hWnd;
};

BOOL CALLBACK EnumProc(HWND hWnd, LPARAM lParam)
{
	EnumData& ed = *(EnumData *)lParam;
	DWORD dwProcessId = 0x0;
	GetWindowThreadProcessId(hWnd, &dwProcessId);
    if (ed.dwProcessId == dwProcessId)
    {
		ed.hWnd = hWnd;
        ::SetLastError(ERROR_SUCCESS);
        return FALSE;
	}
    return TRUE;
}

HWND FindWindowFromProcessId(DWORD dwProcessId)
{
    EnumData ed = {dwProcessId};
    if (!EnumWindows(EnumProc, (LPARAM)&ed) && (GetLastError() == ERROR_SUCCESS))
    {
        return ed.hWnd;
	}
    return NULL;
}

HWND FindWindowFromProcess(HANDLE hProcess)
{
    return FindWindowFromProcessId(GetProcessId(hProcess));
}

int _tmain(int argc, _TCHAR* argv[])
{
 TIniFile * Ini  = new TIniFile(ExtractFilePath(ParamStr(0))+"SaO.ini");
 TIniFile * CIni = new TIniFile(ExtractFilePath(ParamStr(0))+"info\\info.ini");
 bool is = false, quit = false;
 STARTUPINFO cif;
 PROCESS_INFORMATION pi;
 String FNX  = ExtractFilePath(ParamStr(0))+"UniversalS.exe";
 while (!is) {
  ZeroMemory(&cif,sizeof(STARTUPINFO));
  ZeroMemory(&pi,sizeof(PROCESS_INFORMATION));
  is = CreateProcess(FNX.t_str(),NULL,NULL,NULL,NULL,false,NULL,NULL,&cif,&pi);
  if (is == true) {
   std::cout << "Process started\n";
   } else {
	std::cout << "Process not started. Retry in 10 seconds\n";
	Sleep(10000);  }
 }
 Sleep(5000);
 HWND Wnd = 0;
 while (Wnd != 0){
  Wnd = FindWindowFromProcessId(pi.dwProcessId);
 }
 std::cout << "Starting check for life of program\n";
 int seed = CIni->ReadInteger("Debug","WS",0), cseed, counter = 0;
 while (!quit) {
	cseed = CIni->ReadInteger("Debug","WS",0);
	if (cseed == seed)  {
	seed = cseed;
	 while (counter != 7) {
	  cseed = CIni->ReadInteger("Debug","WS",0);
	  if (seed != cseed) {
		counter = 0;
		break;
	  }
	  Sleep(1000);
	  counter++;
	 }
	}
	if (counter == 50) {
	TerminateProcess(pi.hProcess,0);
	std::cout << "App is died. Restarting\n";
	is = false;
	 while (is != true) {
	   ZeroMemory(&cif,sizeof(STARTUPINFO));
	   ZeroMemory(&pi,sizeof(PROCESS_INFORMATION));
	   Ini->WriteBool("Debug","FParam",true);
	   is = CreateProcess(FNX.t_str(),NULL,NULL,NULL,NULL,false,NULL,NULL,&cif,&pi);
	   if (is != true) {
		 std::cout << "Process is not started. Retry in 5 sec\n";
		 Sleep(5000);
	   } else {
		 std::cout << "Process started\n";
		 std::cout << "Starting check for life of program\n";
		 break;
	   }
	 }
	seed = CIni->ReadInteger("Debug","WS",0);
	counter = 0;
  }
 }
 return 0;
}
