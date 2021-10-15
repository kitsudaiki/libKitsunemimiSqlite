#include <iostream>

#include <libKitsunemimiSqlite/cpu.h>
#include <libKitsunemimiCommon/threading/thread.h>

int main()
{
    std::cout<<"cpus: "<<Kitsunemimi::Cpu::getNumberOfCpuThreads()<<std::endl;
    return 0;
}
