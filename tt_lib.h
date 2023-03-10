#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>

typedef struct {

    int pid;
    char name[64];
    char state;
    float cpu_usage;
    float mem_usage;

} process;

typedef struct{

    float uptime;
    float clock;

} sysinfo;

void quitting();
void readfile(const char* file_path,char* buf);
int digits_counter(long unsigned int digit);
void ClearInputBuffer();

float compute_cpu_usage(long unsigned int stime, long unsigned int utime, long unsigned int starttime);
float compute_mem_usage(long unsigned int rss);
void sort_processes(process** procs, long unsigned int procs_count);
void build_processes_buffer(process** procs, int count, char* procs_buf);
void setup_process(char* stats, process* proc);
int process_monitor(int mode, char* procs_buf);


void show_procs(int mode);
void manage_procs();