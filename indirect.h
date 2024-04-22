#pragma once

void indirect_mov(VM * v , IP * code){
  if(v->ip.argx < STACK_SIZE){
    v->gpr[v->ip.argx] = v->stack[v->ip.argx].data;
  }
  
}

void indirect_push(VM * v , IP * code){
  if(v->ip.argx < STACK_SIZE){
    v->stack[v->stack_p].data = v->stack[v->ip.argx].data;
    v->stack_p = v->stack_p + 1 ;
  }
  
}
