#include "regcheck.h"


bool __regstruct::GetRegKeyValue()
{
	HKEY hkResult = nullptr;
	if (RegOpenKeyExA(hKey, lpSubKey, NULL, KEY_READ, &hkResult) != ERROR_SUCCESS)
	{
		std::cout << "[-] COULD NOT ACCESS REGISTRY..." << std::endl;
		return FALSE;
	}

	DWORD sizeof_value = sizeof(value);

	if (RegQueryValueExA(hkResult, lpValueName, NULL, NULL, (LPBYTE)value, &sizeof_value) != ERROR_SUCCESS)
	{
		std::cout << "[-] COULD NOT ACCESS REGISTRY VALUE..." << std::endl;
		return FALSE;
	}

	std::cout << "\t[+] REGISTRY VALUE: " << value << std::endl;

	return TRUE;
}

void __regstruct::isVM()
{
	for (int i = 0; i < vendorlistsize; i++)
	{
		if (strstr(value, vendors[i]))
		{
			inVM = TRUE;
			std::cout << "\t[-] PROBABLY IN A VM..." << std::endl << std::endl;
		}
	}
	if (!inVM)
	{
		std::cout << "\t[+] PROBABLY NOT IN A VM!" << std::endl << std::endl;
	}
}
