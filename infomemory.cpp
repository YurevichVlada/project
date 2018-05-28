#include <Windows.h>
#include <string>
#include <iostream>
#include "infomemory.h"

using namespace std;
string InfoMemory::getTotalPhys() const
{
    return totalPhys;
}

string InfoMemory::getAvailPhys() const
{
return availPhys;
}

string InfoMemory::getMemoryLoad() const
{
return memoryLoad;
}

string InfoMemory::getTotalVirt() const
{
return totalVirt;
}

string InfoMemory::getAvailVirt() const
{
    return availVirt;
}

string InfoMemory::getTotalPagefile() const
{
    return totalPagefile;
}

void InfoMemory:: getStatus(){

    _MEMORYSTATUSEX ms;
    ms.dwLength=sizeof(ms);
        GlobalMemoryStatusEx(&ms);
        memoryLoad = to_string(static_cast<unsigned long long>(ms.dwMemoryLoad))+"%";
        totalPhys =  to_string(static_cast<unsigned long long>(ms.ullTotalPhys/(1024*1024)))+" MB";
        availPhys =  to_string(static_cast<unsigned long long>(ms.ullAvailPhys/(1024*1024)))+" MB";
        totalVirt = to_string(static_cast<unsigned long long>(ms.ullTotalVirtual/(1024*1024)))+" MB";
        availVirt = to_string(static_cast<unsigned long long>(ms.ullAvailVirtual/(1024*1024)))+" MB";
        totalPagefile = to_string(static_cast<unsigned long long>(ms.ullAvailPageFile/(1024*1024)))+" MB";
      /*    cout<<ms.dwMemoryLoad<<"%"<<endl;
         cout<<ms.ullTotalPhys/(1024*1024)<<endl;
         cout<<ms.ullAvailPhys/(1024*1024)<<endl;
         cout<<ms.ullTotalVirtual/(1024*1024)<<endl;
         cout<<ms.ullAvailVirtual/(1024*1024)<<endl;
         */

}
