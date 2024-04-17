#pragma once

void immediate_push(VM * v, IP * code){

  v->stack[v->stack_p].data = v->ip.argx;
  v->stack_p++;

}

void immediate_mov(VM * v , IP * code){

  v->gpr[v->ip.argx] = v->ip.argy;
  
}
