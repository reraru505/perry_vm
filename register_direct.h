#pragma once
#include "mytypes.h"

void register_direct_push(VM * v , IP * code){

  v->stack[v->stack_p].data = v->gpr[v->ip.argx];
  if((v->stack_p + 1) > STACK_SIZE){
    printf("Stack Overflow detected\nExiting\n");
    exit(EXIT_FAILURE);
  }
  v->stack_p++;

}

void register_direct_mov(VM * v , IP * code){

  v->gpr[v->ip.argx] = v->ip.argy;
  
}

void register_direct_cmp(VM * v , IP * code){


  if(v->gpr[v->ip.argx] == v->gpr[v->ip.argy]){
    v->flag.equal = true;
    v->flag.greater = false;
  }
  
  if(v->gpr[v->ip.argx] > v->gpr[v->ip.argy]){
    v->flag.equal = false;
    v->flag.greater = true;
  }
  
  if(v->gpr[v->ip.argx] < v->gpr[v->ip.argy]){
    v->flag.equal = false;
    v->flag.greater = false;
  }
}

void register_direct_pop(VM * v , IP * code){
  if((v->stack_p - 1) > v->base_p){
    printf("Stack Underflow detected\nExiting\n");
    exit(EXIT_FAILURE);
  }
  v->gpr[v->ip.argx] = v->stack[v->stack_p - 1].data;
  v->stack_p--;
  
}


void register_direct_add(VM * v , IP * code){

  v->gpr[v->ip.argx] = v->gpr[v->ip.argy] + v->gpr[v->ip.argz]; 

}


void register_direct_sub(VM * v , IP * code){

  v->gpr[v->ip.argx] = v->gpr[v->ip.argy] - v->gpr[v->ip.argz]; 

}


void register_direct_div(VM * v , IP * code){

  v->gpr[v->ip.argx] = v->gpr[v->ip.argy] / v->gpr[v->ip.argz]; 

}


void register_direct_mul(VM * v , IP * code){

  v->gpr[v->ip.argx] = v->gpr[v->ip.argy] * v->gpr[v->ip.argz]; 

}


void register_direct_mod(VM * v , IP * code){

  v->gpr[v->ip.argx] = v->gpr[v->ip.argy] % v->gpr[v->ip.argz]; 

}
