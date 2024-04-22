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
    char * buffer = (char *)v->stack;

    int len = v->gpr[2] + v->gpr[1] - 1;

    for(int i = v->gpr[1] ; i < len ; i++ ){
      printf("%c",buffer[i]);
    }
    printf("\n");
    buffer = nullptr;
    
  }

}
