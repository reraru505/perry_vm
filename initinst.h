#pragma once

#include "mytypes.h"

#include "implied.h"
#include "immediate.h"
#include "register_direct.h"
#include "indirect.h"

void (** AM_decode[5])(VM * v , IP * code);


void (* implied[19]) (VM * v , IP * code);

void (* immediate[19]) (VM * v , IP * code);

void (* register_direct[19]) (VM * v , IP * code);

void (* register_indirect[19]) (VM * v , IP * code);

void (* indirect[19]) (VM * v , IP * code);

void illegal_instruction(VM * v , IP * code){

  printf("Illegal Instruction detected \nExiting\n");
  exit(EXIT_FAILURE);
  
}

void init_instructions(){


  AM_decode[IMPLIED] = implied;
  AM_decode[IMMEDIATE] = immediate;
  AM_decode[REGISTER_DIRECT] = register_direct;
  AM_decode[REGISTER_INDIRECT] = register_indirect;
  AM_decode[INDIRECT] = indirect;
  

  for ( int i = 0 ; i < 19 ; i++){
    implied[i] = illegal_instruction;
    immediate[i] = illegal_instruction;
    register_direct[i] = illegal_instruction;
    register_indirect[i] = illegal_instruction;
    indirect[i] = illegal_instruction;

  }

  implied[CALL] = implied_call;
  implied[RET] = implied_ret;
  implied[JE] = implied_je;
  implied[JNE] = implied_jne;
  implied[JG] = implied_jg;
  implied[JL] = implied_jl;
  implied[CLF] = implied_clf;
  implied[OP_LABEL] = implied_label;
  implied[SYSCALL] = implied_syscall;


  immediate[MOV] = immediate_mov;
  immediate[PUSH] = immediate_push;

  register_direct[PUSH] = register_direct_push;
  register_direct[MOV] = register_direct_mov;
  register_direct[CMP] = register_direct_cmp;
  register_direct[POP] = register_direct_pop;
  register_direct[ADD] = register_direct_add;
  register_direct[SUB] = register_direct_sub;
  register_direct[DIV] = register_direct_div;
  register_direct[MUL] = register_direct_mul;
  register_direct[MOD] = register_direct_mod;

  indirect[MOV] = indirect_mov;
  indirect[PUSH] = indirect_push;
  
  
  
}


