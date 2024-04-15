#pragma once

void (** AM_decode[5])(VM * v , IP * code);


void (* implied[10]) (VM * v , IP * code);

void (* immediate[10]) (VM * v , IP * code);

void (* register_direct[10]) (VM * v , IP * code);

void (* register_indirect[10]) (VM * v , IP * code);

void (* indirect[10]) (VM * v , IP * code);


void init_instructions(){


  AM_decode[0] = implied;
  AM_decode[0] = immediate;
  AM_decode[0] = register_direct;
  AM_decode[0] = register_indirect;
  AM_decode[0] = indirect;
  

  
  
}


