#include "vm.h"
#include "loadfile.h"

int main(int argc , char ** argv){

  IP * code = loadcode("b.out");

  VM * v = (VM *) malloc(sizeof(VM));

  init_vm(v, code);
  
  prefetch_data_segment(v , code);

  init_instructions();
  
  while(v->ip.code != HLT){

    fetch(v,code);

    u32 * c = (u32 *) v->stack;

    printf("current stack => ");
    for(int i = 0 ; i < v->stack_p ; i++){
      printf("%d ",c[i]);
    }
    printf("\n");

    c = nullptr;
    
    execute(v,code);
    
  }

  free(code);
  free(v->stack);

  
}
