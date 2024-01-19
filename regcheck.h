#pragma once

#include <Windows.h>
#include <iostream>

#ifndef REGCHECK_H
#define REGCHECK_H

typedef struct __regstruct
{
	__regstruct(const char* lpValueName = "") : lpValueName{ lpValueName } {};

	char value[1024];
	const char* lpValueName{};
	bool inVM{};
	char* vendors[2] = { VB, VM };		// Change if adding more vendors
	size_t vendorlistsize = sizeof(vendors) / sizeof(vendors[0]);

	bool GetRegKeyValue();
	void isVM();


private:
	HKEY hKey = HKEY_LOCAL_MACHINE;
	const char* lpSubKey = "SYSTEM\\CurrentControlSet\\Control\\SystemInformation";
	char VB[100] = "VirtualBox";
	char VM[100] = "VMWare";
						// Add more vendors here

}regstruct, * pRegStruct;


#endif
