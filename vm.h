#pragma once
#include "mytypes.h"
#include "initinst.h"
#include "string.h"

/*
  ______________________
  |VM header           |
  |____________________|
  |total file len      |
  |--------------------|
  |data segment len    |
  |--------------------|
  |text segment len    |
  |--------------------|
  |entry point address |
  |--------------------|
  |padding             |
  |--------------------|
*/

void init_vm(VM * v , IP * code){
  v->stack = (s32 *) calloc(STACK_SIZE , sizeof(s32));
  v->pc = code[0].argy + code[0].code + 1;
  v->stack_p = code[0].code * 5;
  v->base_p = code[0].code * 5;
  
}


void prefetch_data_segment(VM * v , IP * code){

  char * c = (char *)v->stack;
  char * d = (char *)code;


  //this gives me no hope for C
  //why the FUCK is this even possible
  
  for(u32 i = 0 ; i < ((sizeof(IP)* code[0].code)/sizeof(char)); i++){

    c[i] = d[(sizeof(IP)/sizeof(char))+i];
    
  }
  
  //printf("\n%s\n",c);

  c = nullptr;
  d = nullptr;
  
}

  

void fetch(VM * v , IP * code){

  v->ip = code[v->pc];
  v->pc++;
  
}

//void vm_start(){
//
//  VM * vm = malloc(sizeof(vm));
//
//  //  IP * code = loader(/*source of the code*/);
//
//  init_vm(vm , code);
//  init_instructions();
//  
//  
//  while(vm->ip.code != HLT){
//
//    
//    
//  }
//
//  free(code);
//  free(vm->stack);
//  
//}
