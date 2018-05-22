#ifndef INFOCPU_H
#define INFOCPU_H

#include <Windows.h>
#include <string>
#include <iostream>
#include "info.h"

using namespace std;

class InfoCPU: public Info{
    string numberOfProcessors;
    string procArchitecture;
    string procType;
public:
    InfoCPU(){ getStatus();}
    ~InfoCPU(){}
    void getStatus();
    string getNumberOfProcessors() const;
    string getProcArchitecture() const;
    string getProcType() const;
};

#endif // INFOCPU_H

