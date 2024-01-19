#pragma once

#include <Windows.h>
#include <iostream>

#ifndef REGCHECK_H
#define REGCHECK_H

typedef struct __regstruct
{
	__regstruct(HKEY hKey = 0, const char* lpSubKey = "", const char* lpValueName = "") : hKey{ hKey }, lpSubKey{ lpSubKey }, lpValueName{ lpValueName } {};

	HKEY hKey{};
	char SysProdValue[1024]{};
	char BiosValue[1024]{};
	const char* lpSubKey{};
	const char* lpValueName{};

	bool RegKeyCompare(char* regvalue);
	char* vendors[2] = { VB, VM };									// Change if adding more vendors
	size_t vendorlistsize = sizeof(vendors)/sizeof(vendors[0]);

private:
	char VB[100] = "VirtualBox";	
	char VM[100] = "VMWare";
																	// Add more vendors here

}regstruct, * pRegStruct;


#endif