/*

Name: 2.c
Author: Aniket Kumar
Decsription: Write a simple program to execute in an infinite loop at the background. 
            Go to /proc directory and identify all the process related information in the corresponding proc directory.
Date: September 6th, 2025
*/

#include <stdio.h>
#include <unistd.h>

int main(){
    while(1){
        printf("Process running with PID = %d\n", getpid());
        sleep(5);  
    }
    return 0;
}

/*
Terminal 1: Input:
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Process running with PID = 12812
Process running with PID = 12812
Process running with PID = 12812
...


Terminal 2: Output:
trafalgarlaw@ANIKETKUMAROMEN:/proc/12788$ cd /proc/12812
trafalgarlaw@ANIKETKUMAROMEN:/proc/12812$ ls
arch_status         fdinfo             ns             smaps_rollup
attr                gid_map            numa_maps      stack
autogroup           io                 oom_adj        stat
auxv                ksm_merging_pages  oom_score      statm
cgroup              ksm_stat           oom_score_adj  status
clear_refs          latency            pagemap        syscall
cmdline             limits             patch_state    task
comm                loginuid           personality    timens_offsets
coredump_filter     map_files          projid_map     timers
cpu_resctrl_groups  maps               root           timerslack_ns
cpuset              mem                sched          uid_map
cwd                 mountinfo          schedstat      wchan
environ             mounts             sessionid
exe                 mountstats         setgroups
fd                  net                smaps


*/