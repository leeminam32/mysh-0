#include <string.h>
#include <stdio.h>
#include "commands.h"
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;
  if (argc == 1)
	chdir(getenv("HOME"));
  else if (argc == 2) {
	if(chdir(argv[1]))
		printf("There is No directory"); 
	}
//  else if (argc > 2) printf("Wrong input");
	
  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;
  char buff[8096];
	
	getcwd(buff, 8096);
	printf("%s\n",buff);
	
  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  if(argc >2 || argc == 0){
  printf("wrong input");
	return 0;
}
  if(strcmp(argv[0], "cd") != 0) return 0;

  return 1;
}

int validate_pwd_argv(int argc, char** argv) {

  if(argc != 1)
	 return 0;
  if(strcmp(argv[0], "pwd") != 0) return 0;
  

  return 1;
}
