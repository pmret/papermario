.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel ClearStatusEffects
/* 1AC680 8027DDA0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1AC684 8027DDA4 AFB00010 */  sw    $s0, 0x10($sp)
/* 1AC688 8027DDA8 0080802D */  daddu $s0, $a0, $zero
/* 1AC68C 8027DDAC AFBF0014 */  sw    $ra, 0x14($sp)
/* 1AC690 8027DDB0 8E02000C */  lw    $v0, 0xc($s0)
/* 1AC694 8027DDB4 0C0B1EAF */  jal   get_variable
/* 1AC698 8027DDB8 8C450000 */   lw    $a1, ($v0)
/* 1AC69C 8027DDBC 0040202D */  daddu $a0, $v0, $zero
/* 1AC6A0 8027DDC0 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1AC6A4 8027DDC4 14820002 */  bne   $a0, $v0, .L8027DDD0
/* 1AC6A8 8027DDC8 00000000 */   nop   
/* 1AC6AC 8027DDCC 8E040148 */  lw    $a0, 0x148($s0)
.L8027DDD0:
/* 1AC6B0 8027DDD0 0C09A75B */  jal   get_actor
/* 1AC6B4 8027DDD4 00000000 */   nop   
/* 1AC6B8 8027DDD8 0040802D */  daddu $s0, $v0, $zero
/* 1AC6BC 8027DDDC 82020210 */  lb    $v0, 0x210($s0)
/* 1AC6C0 8027DDE0 10400005 */  beqz  $v0, .L8027DDF8
/* 1AC6C4 8027DDE4 00000000 */   nop   
/* 1AC6C8 8027DDE8 86040436 */  lh    $a0, 0x436($s0)
/* 1AC6CC 8027DDEC A2000211 */  sb    $zero, 0x211($s0)
/* 1AC6D0 8027DDF0 0C011E26 */  jal   func_80047898
/* 1AC6D4 8027DDF4 A2000210 */   sb    $zero, 0x210($s0)
.L8027DDF8:
/* 1AC6D8 8027DDF8 82020212 */  lb    $v0, 0x212($s0)
/* 1AC6DC 8027DDFC 10400005 */  beqz  $v0, .L8027DE14
/* 1AC6E0 8027DE00 00000000 */   nop   
/* 1AC6E4 8027DE04 86040436 */  lh    $a0, 0x436($s0)
/* 1AC6E8 8027DE08 A2000213 */  sb    $zero, 0x213($s0)
/* 1AC6EC 8027DE0C 0C011E68 */  jal   func_800479A0
/* 1AC6F0 8027DE10 A2000212 */   sb    $zero, 0x212($s0)
.L8027DE14:
/* 1AC6F4 8027DE14 82020218 */  lb    $v0, 0x218($s0)
/* 1AC6F8 8027DE18 10400005 */  beqz  $v0, .L8027DE30
/* 1AC6FC 8027DE1C 00000000 */   nop   
/* 1AC700 8027DE20 86040436 */  lh    $a0, 0x436($s0)
/* 1AC704 8027DE24 A2000219 */  sb    $zero, 0x219($s0)
/* 1AC708 8027DE28 0C011EAA */  jal   func_80047AA8
/* 1AC70C 8027DE2C A2000218 */   sb    $zero, 0x218($s0)
.L8027DE30:
/* 1AC710 8027DE30 82020214 */  lb    $v0, 0x214($s0)
/* 1AC714 8027DE34 10400003 */  beqz  $v0, .L8027DE44
/* 1AC718 8027DE38 00000000 */   nop   
/* 1AC71C 8027DE3C A2000215 */  sb    $zero, 0x215($s0)
/* 1AC720 8027DE40 A2000214 */  sb    $zero, 0x214($s0)
.L8027DE44:
/* 1AC724 8027DE44 8E020440 */  lw    $v0, 0x440($s0)
/* 1AC728 8027DE48 A2000216 */  sb    $zero, 0x216($s0)
/* 1AC72C 8027DE4C A2000217 */  sb    $zero, 0x217($s0)
/* 1AC730 8027DE50 8C43000C */  lw    $v1, 0xc($v0)
/* 1AC734 8027DE54 AC60003C */  sw    $zero, 0x3c($v1)
/* 1AC738 8027DE58 A2000221 */  sb    $zero, 0x221($s0)
/* 1AC73C 8027DE5C A2000222 */  sb    $zero, 0x222($s0)
/* 1AC740 8027DE60 A2000220 */  sb    $zero, 0x220($s0)
/* 1AC744 8027DE64 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1AC748 8027DE68 8FB00010 */  lw    $s0, 0x10($sp)
/* 1AC74C 8027DE6C 24020002 */  addiu $v0, $zero, 2
/* 1AC750 8027DE70 03E00008 */  jr    $ra
/* 1AC754 8027DE74 27BD0018 */   addiu $sp, $sp, 0x18

/* 1AC758 8027DE78 00000000 */  nop   
/* 1AC75C 8027DE7C 00000000 */  nop   
