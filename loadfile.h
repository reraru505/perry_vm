#pragma once
#include "mytypes.h"

IP * loadcode(char * src){

  FILE * f = fopen(src,"rb");

  fseek(f , 0 , SEEK_END);
  u32 len = ftell(f);
  rewind(f);

  char * buffer = (char*) calloc(len , sizeof(char));

  fread(buffer , sizeof(char ) , len , f);

  IP * retval = (IP *) buffer;
  
  for(int i = 0 ; i < (retval[0].mode + 1) ; i++){
    printf(" %d ",retval[i].mode);
    printf(" %d ",retval[i].code);
    printf(" %d ",retval[i].argx);
    printf(" %d ",retval[i].argy);
    printf(" %d \n",retval[i].argz);
    
  }
  
  

  return retval;
  
}
