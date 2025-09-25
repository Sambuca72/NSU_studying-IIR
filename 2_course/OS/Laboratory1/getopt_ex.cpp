#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <limits.h>
#include <errno.h>

using namespace std;

int main(int argc, char *argv[]){
    char options = "ispducC:vV:"
    int c, invalid;
    int iflg = 0, sflg = 0, pflg = 0, uflg = 0, cflg = 0, dflg = 0, vflg =0;
    string U_arg, C_arg, V_arg;

    cout << "args equals" << argc;
    while(getopt(argc, argv, options) != EOF){
        switch (c)
        {
        case 'i':
            iflg++;
            cout << "Real UID: " << getuid() << "Effective UID: " << geteuid() << endl;
            cout << "Real GID: " << getgid() << "Effective GID: " << getegid() << endl;
            break;

        case 's':
            sflg++;
            if(setpgid(0,0) == -1){
                cerr << "setgpid failed" << stderror(errno) << endl;
            }else{
                cout << "Process set as group leader" << endl;
            }
            break;

        case 'p':
            pflg++;
            cout << "Process ID: " << getpid() <<endl;
            cout << "Parent Process ID: " << getppid() <<endl;
            cout << "Process Group ID: " << getpgrp() <<endl;

            break;

        case 'd':
            
            break;
        case 'u':
            uflg++;
            {
                struct rlimit rlim;
                if (getrlimit(RLIMIT_FSIZE, &rlim) == -1) {
                    std::cerr << "getrlimit RLIMIT_FSIZE failed: " << strerror(errno) << std::endl;
                } else {
                    std::cout << "Current ulimit: " << rlim.rlim_cur << " bytes" << std::endl;
                }
            }
            break;

        case 'U':
            break;

        case 'c':
            break;
        
        case 'C':
            break;
        
        case 'v':
            break;

        case 'V':
            break;

        case '?':
            break;
        }
    }


}