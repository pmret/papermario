.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel npc_move_heading
/* 015E54 8003AA54 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 015E58 8003AA58 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 015E5C 8003AA5C 4485B000 */  mtc1  $a1, $f22
/* 015E60 8003AA60 3C0140C9 */  lui   $at, 0x40c9
/* 015E64 8003AA64 34210FD0 */  ori   $at, $at, 0xfd0
/* 015E68 8003AA68 44810000 */  mtc1  $at, $f0
/* 015E6C 8003AA6C 44862000 */  mtc1  $a2, $f4
/* 015E70 8003AA70 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 015E74 8003AA74 46002502 */  mul.s $f20, $f4, $f0
/* 015E78 8003AA78 00000000 */  nop   
/* 015E7C 8003AA7C AFB00010 */  sw    $s0, 0x10($sp)
/* 015E80 8003AA80 3C0143B4 */  lui   $at, 0x43b4
/* 015E84 8003AA84 44810000 */  mtc1  $at, $f0
/* 015E88 8003AA88 0080802D */  daddu $s0, $a0, $zero
/* 015E8C 8003AA8C AFBF0014 */  sw    $ra, 0x14($sp)
/* 015E90 8003AA90 4600A503 */  div.s $f20, $f20, $f0
/* 015E94 8003AA94 0C00A85B */  jal   sin_rad
/* 015E98 8003AA98 4600A306 */   mov.s $f12, $f20
/* 015E9C 8003AA9C 4600A306 */  mov.s $f12, $f20
/* 015EA0 8003AAA0 0C00A874 */  jal   cos_rad
/* 015EA4 8003AAA4 46000506 */   mov.s $f20, $f0
/* 015EA8 8003AAA8 4614B502 */  mul.s $f20, $f22, $f20
/* 015EAC 8003AAAC 00000000 */  nop   
/* 015EB0 8003AAB0 4600B587 */  neg.s $f22, $f22
/* 015EB4 8003AAB4 4600B582 */  mul.s $f22, $f22, $f0
/* 015EB8 8003AAB8 00000000 */  nop   
/* 015EBC 8003AABC C6020038 */  lwc1  $f2, 0x38($s0)
/* 015EC0 8003AAC0 46141080 */  add.s $f2, $f2, $f20
/* 015EC4 8003AAC4 C6000040 */  lwc1  $f0, 0x40($s0)
/* 015EC8 8003AAC8 46160000 */  add.s $f0, $f0, $f22
/* 015ECC 8003AACC E6020038 */  swc1  $f2, 0x38($s0)
/* 015ED0 8003AAD0 E6000040 */  swc1  $f0, 0x40($s0)
/* 015ED4 8003AAD4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 015ED8 8003AAD8 8FB00010 */  lw    $s0, 0x10($sp)
/* 015EDC 8003AADC D7B60020 */  ldc1  $f22, 0x20($sp)
/* 015EE0 8003AAE0 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 015EE4 8003AAE4 03E00008 */  jr    $ra
/* 015EE8 8003AAE8 27BD0028 */   addiu $sp, $sp, 0x28

