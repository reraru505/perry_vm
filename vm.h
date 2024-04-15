#pragma once
#include "mytypes.h"

/*
  ______________________
  |VM header           |
  |____________________|
  |data segment len    |
  |--------------------|
  |code segment len    |
  |--------------------|
  |entry point address |
  |--------------------|
  |padding             |
  |--------------------|
  |padding             |
  |--------------------|
*/


void init_vm(VM * v , IP * code){
  v->stack = (s32 *) calloc(STACK_SIZE , sizeof(s32));
  v->pc = code[0].argx;
  
  
}


void fetch(VM * v , IP * code){

  v->ip = code[v->pc];
  v->pc++;
  
}

void vm_start(){

  VM * vm = malloc(sizeof(vm));

  IP * code = loader(/*source of the code*/);

  init_vm(vm , code);

  
  
  while(vm->ip.code != HLT){

    
    
  }

  free(code);
  free(v->stack);
  
}
