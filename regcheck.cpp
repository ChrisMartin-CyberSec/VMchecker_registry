#include "regcheck.h"


bool __regstruct::RegKeyCompare(char* regvalue)
{


	HKEY hkResult = nullptr;															
	if (RegOpenKeyExA(hKey, lpSubKey, NULL, KEY_READ, &hkResult) != ERROR_SUCCESS)
	{
		std::cout << "[-] COULD NOT ACCESS REGISTRY..." << std::endl;
		return FALSE;
	}

	char value[1024]{};
	DWORD sizeof_value = sizeof(value);

	if (RegQueryValueExA(hkResult, lpValueName, NULL, NULL, (LPBYTE)value, &sizeof_value) != ERROR_SUCCESS)
	{
		std::cout << "[-] COULD NOT ACCESS REGISTRY VALUE..." << std::endl;
		return FALSE;
	}

	strcpy_s(regvalue, sizeof(value), value);

	return TRUE;
}
