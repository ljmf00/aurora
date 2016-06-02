#include <Aurora/InfoRAM.h>

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <sys/sysinfo.h>
#elif __APPLE__
// #include <sys/sysctl.h>
#include <sys/vmmeter.h>
#endif

namespace InfoRAM
{
    // Total virtual memory size in bytes
    unsigned int getTotalVirtualMemory()
    {
        #ifdef __linux__
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return (mem_temp.totalram + mem_temp.totalswap) * mem_temp.mem_unit;
        #elif _WIN32
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullTotalVirtual;
        #elif defined(__MACH__) && defined(__APPLE__)
        struct vmtotal mem_temp;
        vmtotal (&mem_temp);
        return mem_temp.t_vm;
        #endif
    }
    
    // Used virtual memory size in bytes
    unsigned int getUsedVirtualMemory()
    {
        #ifdef __linux
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return ((memInfo.totalram - memInfo.freeram) + (memInfo.totalswap - memInfo.freeswap)) * mem_temp.mem_unit;
        #elif _WIN32
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullTotalVirtual - mem_temp.ullAvailVirtual;
        #elif defined(__MACH__) && defined(__APPLE__)
        struct vmtotal mem_temp;
        struct xsw_usage swmem_temp;
        vmtotal (&mem_temp);
        return mem_temp.t_vm - mem_temp.t_free;
        #endif
    }
    
    // Free virtual memory size in bytes
    unsigned int getFreeVirtualMemory()
    {
        #ifdef __linux__
        struct sysinfo mem_t emp;
        sysinfo (&mem_temp);
        return ((memInfo.totalram + memInfo.totalswap) - ((memInfo.totalram - memInfo.freeram) + (memInfo.totalswap - memInfo.freeswap))) * mem_temp.mem_unit;
        #elif _WIN32
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullAvailVirtual;
        #elif defined(__MACH__) && defined(__APPLE__)
        struct vmtotal mem_temp;
        struct xsw_usage swmem_temp;
        vmtotal (&mem_temp);
        return mem_temp.t_free;
        #endif
    }
    
    // Total pysical memory size in bytes
    unsigned int getTotalPhysicalMemory()
    {
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return mem_temp.totalram * mem_temp.mem_unit;
    }
    
    // Used pysical memory size in bytes
    unsigned int getUsedPhysicalMemory()
    {
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return (mem_temp.totalram - mem_temp.freeram) * mem_temp.mem_unit;
    }
    
    // Free pysical memory size in bytes
    unsigned int getFreePhysicalMemory()
    {
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return mem_temp.freeram * mem_temp.mem_unit;
    }
}