.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800DFC74
/* 079124 800DFC74 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 079128 800DFC78 AFB00010 */  sw    $s0, 0x10($sp)
/* 07912C 800DFC7C 3C108011 */  lui   $s0, 0x8011
/* 079130 800DFC80 2610EFC8 */  addiu $s0, $s0, -0x1038
/* 079134 800DFC84 0200202D */  daddu $a0, $s0, $zero
/* 079138 800DFC88 AFBF0014 */  sw    $ra, 0x14($sp)
/* 07913C 800DFC8C 0C00A580 */  jal   mem_clear
/* 079140 800DFC90 24050288 */   addiu $a1, $zero, 0x288
/* 079144 800DFC94 24020001 */  addiu $v0, $zero, 1
/* 079148 800DFC98 0C038817 */  jal   func_800E205C
/* 07914C 800DFC9C AE020000 */   sw    $v0, ($s0)
/* 079150 800DFCA0 8E050028 */  lw    $a1, 0x28($s0)
/* 079154 800DFCA4 8E06002C */  lw    $a2, 0x2c($s0)
/* 079158 800DFCA8 8E070030 */  lw    $a3, 0x30($s0)
/* 07915C 800DFCAC 0C044898 */  jal   create_shadow_type
/* 079160 800DFCB0 0000202D */   daddu $a0, $zero, $zero
/* 079164 800DFCB4 0C039ADA */  jal   func_800E6B68
/* 079168 800DFCB8 AE0200CC */   sw    $v0, 0xcc($s0)
/* 07916C 800DFCBC 0C0382C5 */  jal   func_800E0B14
/* 079170 800DFCC0 00000000 */   nop   
/* 079174 800DFCC4 0C0381A7 */  jal   func_800E069C
/* 079178 800DFCC8 00000000 */   nop   
/* 07917C 800DFCCC 0C038145 */  jal   func_800E0514
/* 079180 800DFCD0 00000000 */   nop   
/* 079184 800DFCD4 0C0380DD */  jal   func_800E0374
/* 079188 800DFCD8 00000000 */   nop   
/* 07918C 800DFCDC 0C039548 */  jal   func_800E5520
/* 079190 800DFCE0 00000000 */   nop   
/* 079194 800DFCE4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 079198 800DFCE8 8FB00010 */  lw    $s0, 0x10($sp)
/* 07919C 800DFCEC 03E00008 */  jr    $ra
/* 0791A0 800DFCF0 27BD0018 */   addiu $sp, $sp, 0x18

