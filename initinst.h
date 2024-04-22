#pragma once

#include "mytypes.h"

#include "implied.h"
#include "immediate.h"
#include "register_direct.h"
#include "indirect.h"

void (*AM_decode[5][19])(VM * v , IP * code);

void illegal_instruction(VM * v , IP * code){

  printf("Illegal Instruction detected \nExiting\n");
  exit(EXIT_FAILURE);
  
}

void implied_hlt(VM * v , IP * code){

}


void init_instructions(){
  
  for ( int i = 0 ; i < 19 ; i++){
    AM_decode[IMPLIED][i] = illegal_instruction;
    AM_decode[IMMEDIATE][i] = illegal_instruction;
    AM_decode[REGISTER_DIRECT][i] = illegal_instruction;
    AM_decode[REGISTER_INDIRECT][i] = illegal_instruction;
    AM_decode[INDIRECT][i] = illegal_instruction;

  }

  AM_decode[IMPLIED][CALL] = implied_call;
  AM_decode[IMPLIED][RET] = implied_ret;
  AM_decode[IMPLIED][JE] = implied_je;
  AM_decode[IMPLIED][JNE] = implied_jne;
  AM_decode[IMPLIED][JG] = implied_jg;
  AM_decode[IMPLIED][JL] = implied_jl;
  AM_decode[IMPLIED][CLF] = implied_clf;
  AM_decode[IMPLIED][OP_LABEL] = implied_label;
  AM_decode[IMPLIED][SYSCALL] = implied_syscall;
  AM_decode[IMPLIED][HLT] = implied_hlt;


  AM_decode[IMMEDIATE][MOV] = immediate_mov;
  AM_decode[IMMEDIATE][PUSH] = immediate_push;

  AM_decode[REGISTER_DIRECT][PUSH] = register_direct_push;
  AM_decode[REGISTER_DIRECT][MOV] = register_direct_mov;
  AM_decode[REGISTER_DIRECT][CMP] = register_direct_cmp;
  AM_decode[REGISTER_DIRECT][POP] = register_direct_pop;
  AM_decode[REGISTER_DIRECT][ADD] = register_direct_add;
  AM_decode[REGISTER_DIRECT][SUB] = register_direct_sub;
  AM_decode[REGISTER_DIRECT][DIV] = register_direct_div;
  AM_decode[REGISTER_DIRECT][MUL] = register_direct_mul;
  AM_decode[REGISTER_DIRECT][MOD] = register_direct_mod;

  AM_decode[INDIRECT][MOV] = indirect_mov;
  AM_decode[INDIRECT][PUSH] = indirect_push;
  
  
  
}


void execute(VM * v ,IP * code){

  AM_decode[v->ip.mode][v->ip.code](v , code);
  
}

