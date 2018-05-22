#include <Windows.h>
#include <string>
#include <iostream>
#include "infocpu.h"

using namespace std;


string InfoCPU::getProcArchitecture() const
{
    return procArchitecture;
}

string InfoCPU::getProcType() const
{
return procType;
}

string InfoCPU::getNumberOfProcessors() const
{
    return numberOfProcessors;
}

void InfoCPU::getStatus(){
    _SYSTEM_INFO si;
    GetSystemInfo(&si);
    numberOfProcessors=to_string(si.dwNumberOfProcessors);
    switch (si.wProcessorArchitecture) {
    case 0: {procArchitecture="x86"; break;};
    case 9: {procArchitecture="x64 (AMD or Intel)"; break;};
    case 5: {procArchitecture="ARM"; break;};
    case 6: {procArchitecture="Intel Itanium-based"; break;};
    case 12: {procArchitecture="ARM64"; break;};
    default: procArchitecture="Unknown architecture.";
    }
    switch (si.dwProcessorType) {
    case 386:{procType="Intel 386";    break;}
    case 486:{procType="Intel 486";    break;}
    case 586:{procType="Intel Pentium";    break;}
    case 2200:{procType="Intel IA64";    break;}
    case 8664:{procType="AMD_X8664";    break;}
    default:
        break;
    }
}
