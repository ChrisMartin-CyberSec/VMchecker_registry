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
> ![RegNotVM](https://github.com/ChrisMartin-CyberSec/VMchecker_registry/assets/111389653/09371899-ebdf-4156-974f-33ec912be011)


## Response in a Virtual Machine (VBox)
> ![RegInVM](https://github.com/ChrisMartin-CyberSec/VMchecker_registry/assets/111389653/90f65b4d-5c3c-4e65-aebe-a61b0d5b17c9)
