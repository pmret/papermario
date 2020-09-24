.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel counter
/* 4605C 8006AC5C 40095800 */  mfc0      $t1, $11
/* 46060 8006AC60 40895800 */  mtc0      $t1, $11
/* 46064 8006AC64 24040018 */  addiu     $a0, $zero, 0x18
/* 46068 8006AC68 0C01ABDF */  jal       send_mesg
/* 4606C 8006AC6C 00000000 */   nop      
/* 46070 8006AC70 3C01FFFF */  lui       $at, 0xffff
/* 46074 8006AC74 34217FFF */  ori       $at, $at, 0x7fff
/* 46078 8006AC78 1000FFE4 */  b         next_interrupt
/* 4607C 8006AC7C 02018024 */   and      $s0, $s0, $at
