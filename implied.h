#pragma once
#include "mytypes.h"
#include "vmsyscall.h"

void implied_call(VM * v , IP * code){

  v->ret = v->pc;
  v->pc =  v->ip.argx;
  
}

void implied_ret(VM * v , IP * code){
  v->pc = v->ret;

}

void implied_je(VM * v , IP * code){
  if(v->flag.equal == true){
    v->ret = v->pc;
    v->pc =  v->ip.argx;
  
  }

}

void implied_jne(VM * v , IP * code){
   if(v->flag.equal == false){
    v->ret = v->pc;
    v->pc =  v->ip.argx;
  
  }
}


void implied_jg(VM * v , IP * code){
   if(v->flag.equal == false and v->flag.greater == true  ){
    v->ret = v->pc;
    v->pc =  v->ip.argx;
  
  }
}


void implied_jl(VM * v , IP * code){
   if(v->flag.equal == false and v->flag.greater == false  ){
    v->ret = v->pc;
    v->pc =  v->ip.argx;
  
  }
}

void implied_clf(VM * v , IP * code){
  v->flag.equal = false;
  v->flag.greater = false;
}


void implied_label(VM * v, IP * code){
  //empty 
}

void implied_syscall(VM * v , IP * code){
  //  handle_syscall(v);
}
