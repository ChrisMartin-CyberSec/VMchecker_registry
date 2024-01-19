#include "regcheck.h"


int main()
{
	bool VM = FALSE;

	regstruct SysProdName(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\SystemInformation", "SystemProductName");

	if (!SysProdName.RegKeyCompare(SysProdName.SysProdValue)) return 1;

	std::cout << "[*] CHECKING SYSTEM PRODUCT NAME..." << std::endl;
	std::cout << "\t[i] REGISTRY VALUE: " << SysProdName.SysProdValue << std::endl << std::endl;

	for (int i = 0; i < SysProdName.vendorlistsize; i++)
	{
		if (strstr(SysProdName.SysProdValue, SysProdName.vendors[i])) { VM = TRUE; }
	}

	regstruct BiosVersion(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\SystemInformation", "BIOSVersion");

	if (!BiosVersion.RegKeyCompare(BiosVersion.BiosValue)) return 1;

	std::cout << "[*] CHECKING SYSTEM BIOS VERSION..." << std::endl;
	std::cout << "\t[i] REGISTRY VALUE: " << BiosVersion.BiosValue << std::endl << std::endl;

	for (int i = 0; i < BiosVersion.vendorlistsize; i++)
	{
		if (strstr(BiosVersion.BiosValue, BiosVersion.vendors[i])) { VM = TRUE; }
	}

	if (VM)
	{
		std::cout << "[-] PROBABLY IN A VM..." << std::endl;

		return 0;
	}

	std::cout << "[+] PROBABLY NOT IN A VM!" << std::endl;

	return 0;
}

