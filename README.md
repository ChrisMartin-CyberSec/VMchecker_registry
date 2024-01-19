# Registry Virtual Machine Checker

Method #3 in the **VM Checker** series.

Here we are querying two registry subkeys:
- `HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\SystemInformation\SystemProductName`
- `HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\SystemInformation\BIOSVersion`

## Purpose
Malware authors regularly utilize `anti-VM` and `anti-sandbox` techniques to evade detection and analysis. 
In the previous two **VM Checker** series, we utilized *CPUID* calls and *WMI Object* queries to determine whether or not we were in a Virtual Machine.
As previously noted, CPUID query responses from a Virtual Machine can be spoofed, tricking malware into thinking the system is a host machine.
In this code, we query the *Windows Registry* to look for additional indications of virtualization.
Employing multiple methods of checking for virtualization can increase the likelihood of evasion.

## Respone in a Windows Host
> ![RegNotVMOutput](https://github.com/ChrisMartin-CyberSec/VMchecker_registry/assets/111389653/2b81df93-ce29-45d0-8f36-42203b72205a)



## Response in a Virtual Machine (VBox)
> ![RegInVMOutput](https://github.com/ChrisMartin-CyberSec/VMchecker_registry/assets/111389653/089b4195-9d37-40fd-ac6a-4b6bda463268)
