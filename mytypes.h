#pragma once

#define STACK_SIZE 10000000
#define or ||
#define and &&

typedef unsigned char  u8;
typedef unsigned int  u32;
typedef unsigned long u64;

typedef float  f32;
typedef double f64;

typedef u8 bool;
#define true 1
#define false 0


typedef enum {
    IMPLIED,
    IMMEDIATE,
    REGISTER_DIRECT,
    REGISTER_INDIRECT,
    INDIRECT,
    INVALID
} AMODE;


typedef enum OPC{

  MOV,
  HLT,
  CALL,
  RET,
  JE,
  JL,
  JG,
  JNE,
  CMP,
  CLF,
  PUSH,
  POP,

  SYSCALL,

  ADD,
  SUB,
  DIV,
  MUL,
  MOD,

  OP_LABEL
  
  
}OPC;


typedef struct Flag {

  bool equal;
  bool greater;
  
} Flag;


typedef struct IP{

  u32 mode; 
  u32 code; 
  u32 argx;
  u32 argy;
  u32 argz;
  
}IP;

typedef union s32{

  u32 data;
  u8 part[4];
  
}s32; 

typedef struct VM{
  
  IP ip;
  u32 pc;
  Flag flag;

  u32 gpr[8];

  u32 ret;


  s32 * stack;
  
  u32 stack_p;
  u32 base_p;

  u32 stack_t;
  u32 stack_b;
  
}VM;
