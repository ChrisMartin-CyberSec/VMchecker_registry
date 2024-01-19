#include "regcheck.h"


int main()
{
	regstruct SysProdName("SystemProductName");

	std::cout << "[*] CHECKING SYSTEM PRODUCT NAME..." << std::endl;

	if (!SysProdName.GetRegKeyValue()) return 1;

	SysProdName.isVM();


	regstruct BiosVersion("BIOSVersion");

	std::cout << "[*] CHECKING SYSTEM BIOS VERSION..." << std::endl;

	if (!BiosVersion.GetRegKeyValue()) return 1;

	BiosVersion.isVM();


	return 0;
}
