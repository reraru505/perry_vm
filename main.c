#include "vm.h"
#include "loadfile.h"

int main(int argc , char ** argv){

  IP * code = loadcode("b.out");

  VM * v = (VM *) malloc(sizeof(VM));

  init_vm(v, code);
  
  prefetch_data_segment(v , code);
  
}
