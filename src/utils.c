#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void mysh_parse_command(const char *command, int *argc, char ***argv)
{

  int num = 0;
  char*copycmd = (char*)malloc(sizeof(char)*8096);
  char*temp = (char*)malloc(sizeof(char)*8096);

	(*argv) = (char **) malloc(sizeof(char*)*8096);
	for(int i =0; i< 8096; i++){
	  *(*argv+i) = (char*) malloc(sizeof(char)*8096);
}


	strcpy(copycmd,command);
	
	temp = strtok(copycmd," \n\t"); 
	
  if(temp == NULL){
	strcpy(*(*argv+num),"");
	num++;
}

  while (temp != NULL){
	
	strcpy(*(*argv+num),temp);
	temp = strtok(NULL," \t\n");
	num++;	
 }
//	free(copycmd);
//	free(temp);
	
}
