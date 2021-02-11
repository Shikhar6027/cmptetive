/*
 Name -> Shikhar Nigam

Roll NO.-> 19ucs146

Assignment 03

Task1 version 1 & 2
please provide argv[2] as a multiple of argv[1]
************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>

struct NodeModule
{
    double val;
    struct NodeModule *next;
};

struct NodeModule *userTimes;
struct NodeModule *sysTimes;
struct NodeModule *idleTimes;
struct NodeModule *freeMems;
struct NodeModule *freeMemPers;
struct NodeModule *readRates;
struct NodeModule *writeRates;
struct NodeModule *cntxSwitchRates;
struct NodeModule *procCreateRates;

struct NodeModule *insert(struct NodeModule *head, double val)
{
    struct NodeModule *n = (struct NodeModule *)malloc(sizeof(struct NodeModule));
    n->val = val;
    n->next = head;
    return n;
}

double calcAverage(struct NodeModule *head, int l)
{
    double total = 0;
    int c = l;
    while (head && l--)
    {
        total += head->val;
        head = head->next;
    }
    return total / c;
}

void version1()
{
    // Open all the required files
    FILE *cpuinfo = fopen("/proc/cpuinfo", "rb");
    FILE *version = fopen("/proc/version", "rb");
    FILE *meminfo = fopen("/proc/meminfo", "rb");
    FILE *uptime = fopen("/proc/uptime", "rb");

    size_t n = 0;
    char line[100];
    double time = 0;

    while (!feof(cpuinfo))
    {
        fscanf(cpuinfo, "%[^\n]", line);
        if (strstr(line, "model name"))
        {
            printf("%s\n", line);
            break;
        }
    }

    // Print kernel version
    fscanf(version, "%[^\n]", line);
    printf("%s\n", line);

    // Print kernel version
    fscanf(meminfo, "%[^\n]", line);
    printf("%s\n", line);

    // Print uptime since boot
    fscanf(uptime, "%[^\n]", line);
    printf("The uptime since boot is %f\n", time);

    fclose(cpuinfo);
    fclose(version);
    fclose(meminfo);
    fclose(uptime);
}

void processorTime()
{
    FILE *stat = fopen("/proc/stat", "r");
    long long total = 0, ut, st, it, t;
    double up, sp, ip;
    char line[100], ts[10];
    fscanf(stat, "%s", ts);

    for (int i = 1; i <= 10; ++i)
    {
        fscanf(stat, "%lld", &t);
        if (i == 1)
            ut = t;
        else if (i == 3)
            st = t;
        else if (i == 4)
            it = t;
        total += t;
    }
    up = 100.0 * ut / total;
    sp = 100.0 * st / total;
    ip = 100.0 * it / total;

    userTimes = insert(userTimes, up);
    sysTimes = insert(sysTimes, sp);
    idleTimes = insert(idleTimes, ip);
    fclose(stat);
}

void freeMemory()
{
    FILE *meminfo = fopen("/proc/meminfo", "r");
    long long freeMem, total, t;
    double freePer;
    char ts[100];
    fscanf(meminfo, "%s %lld kB", ts, &total);
    fscanf(meminfo, "%s %lld kB", ts, &freeMem);
    freePer = 100.0 * freeMem / total;

    freeMems = insert(freeMems, 1.0 * freeMem);
    freeMemPers = insert(freeMemPers, freePer);
    fclose(meminfo);
}

void processes()
{
    FILE *stat = fopen("/proc/stat", "r");
    long long process, time;
    double rate;
    char line[1000], t[20];
    while (!feof(stat))
    {
        fscanf(stat, "%s", t);
        if (strcmp(t, "processes") == 0)
        {
            fscanf(stat, "%lld", &process);
        }
        else if (strcmp(t, "btime") == 0)
        {
            fscanf(stat, "%lld", &time);
        }
        else
        {
            fscanf(stat, "%[^\n]s", line);
        }
    }
    rate = 1.0 * process / time;

    procCreateRates = insert(procCreateRates, rate);
    fclose(stat);
}

void DiskReadWrite()
{
    FILE *diskstats = fopen("/proc/diskstats", "r");
    long long readS, readT, writeS, writeT, t;
    double readR, writeR;
    char line[100], ts[100];
    size_t n = 0;
    while (!feof(diskstats))
    {
        fscanf(diskstats, "%lld", &t);
        fscanf(diskstats, "%lld", &t);
        fscanf(diskstats, "%s", ts);
        if (strcmp(ts, "sda") == 0)
        {
            for (int i = 1; i <= 11; ++i)
            {
                fscanf(diskstats, "%lld", &t);
                if (i == 3)
                    readS = t;
                else if (i == 4)
                    readT == t;
                else if (i == 7)
                    writeS = t;
                else if (i == 8)
                    writeT = t;
            }
            break;
        }
        else
        {
            fscanf(diskstats, "%[^\n]s", ts);
        }
    }
    readR = readS / readT;
    writeR = writeS / writeT;

    readRates = insert(readRates, readR);
    writeRates = insert(writeRates, writeR);
    fclose(diskstats);
}

void contextSwitching()
{
    FILE *stat = fopen("/proc/stat", "r");
    long long switches, time;
    double rate;
    char line[1000], t[10];
    while (!feof(stat))
    {
        fscanf(stat, "%s", t);
        if (strcmp(t, "ctxt") == 0)
        {
            fscanf(stat, "%lld", &switches);
        }
        else if (strcmp(t, "btime") == 0)
        {
            fscanf(stat, "%lld", &time);
        }
        else
        {
            fscanf(stat, "%[^\n]s", line);
        }
    }
    rate = 1.0 * switches / time;

    cntxSwitchRates = insert(cntxSwitchRates, rate);
    fclose(stat);
}

void delay(int s)
{
    int ms = 1000000 * s;
    clock_t start = clock();
    while (clock() < start + ms)
        ;
}

void version2(int readRate, int writeRate)
{
    int r = writeRate / readRate;
    for (int i = 0; true; ++i)
    {
        processorTime();
        freeMemory();
        DiskReadWrite();
        contextSwitching();
        processes();

        if (i && i % r == 0)
        {
            printf("*********************************\n");
            printf("ROUND %d\n", i / 3);
            printf("User time: %lf percent \n", calcAverage(userTimes, r));
            printf("System time: %lf percent \n", calcAverage(sysTimes, r));
            printf("Idle time: %lf percent \n", calcAverage(idleTimes, r));
            printf("Free memory: %lf kB \n", calcAverage(freeMems, r));
            printf("Free memory percentage: %lf percent \n", calcAverage(freeMemPers, r));
            printf("Read rate: %lf reads/sec \n", calcAverage(readRates, r));
            printf("Write rate: %lf writes/sec \n", calcAverage(writeRates, r));
            printf("Context switching rate: %lf switches/sec \n", calcAverage(cntxSwitchRates, r));
            printf("Process creation rate: %lf processes/sec \n", calcAverage(procCreateRates, r));
            printf("*********************************\n");
        }
        delay(readRate);
    }
}

int main(int argc, char *argv[])
{
    userTimes = NULL;
    sysTimes = NULL;
    idleTimes = NULL;
    freeMems = NULL;
    freeMemPers = NULL;
    readRates = NULL;
    writeRates = NULL;
    cntxSwitchRates = NULL;
    procCreateRates = NULL;
    --argc;
    if (argc == 0)
        version1();
    else
    {
        int readRate, writeRate;
        sscanf(argv[1], "%d", &readRate);
        sscanf(argv[2], "%d", &writeRate);
        version2(readRate, writeRate);
    }
}