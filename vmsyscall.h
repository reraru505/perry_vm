#include "mytypes.h"

/*

  SYSCALL TABLE
  _________________________________________________________________________
  | Name        |reg0          | reg1                | reg2                |
  --------------------------------------------------------------------------
  | stdout      |  0           | source address      |len                  |
  | stdin       |  1           | destination address |len                  | 
  | malloc      |  3           | size in bytes       | destination address |
  
*/

void vm_call_stdout(VM * v){
  if(v->gpr[1] < STACK_SIZE){
    int start = v->gpr[1];
    char * buffer = (char *) calloc(v->gpr[2],sizeof(char));

    int len;
    if(v->gpr[2]%4 == 0){
      len = v->gpr[2]/4;
    }else{
      len = v->gpr[2]/4 + 1;
    }

    int tracker = 0 ;
    for ( int i = start ; i < len ; i++){
      if(tracker > v->gpr[2]){
	break;
      }
      if(tracker < v->gpr[2]){
	buffer[tracker] = v->stack[i].part[3];
	tracker++;
      }
      if(tracker < v->gpr[2]){
	buffer[tracker] = v->stack[i].part[2];
	tracker++;
      }
      if(tracker < v->gpr[2]){
	buffer[tracker] = v->stack[i].part[1];
	tracker++;
      }
      if(tracker < v->gpr[2]){
	buffer[tracker] = v->stack[i].part[0];
	tracker++;
      }
      
    }

    printf("%s",buffer);

    free(buffer);

    
  }

}
