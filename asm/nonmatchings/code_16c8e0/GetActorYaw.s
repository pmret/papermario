.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetActorYaw
/* 199CA8 8026B3C8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 199CAC 8026B3CC AFB10014 */  sw    $s1, 0x14($sp)
/* 199CB0 8026B3D0 0080882D */  daddu $s1, $a0, $zero
/* 199CB4 8026B3D4 AFBF0018 */  sw    $ra, 0x18($sp)
/* 199CB8 8026B3D8 AFB00010 */  sw    $s0, 0x10($sp)
/* 199CBC 8026B3DC 8E30000C */  lw    $s0, 0xc($s1)
/* 199CC0 8026B3E0 8E050000 */  lw    $a1, ($s0)
/* 199CC4 8026B3E4 0C0B1EAF */  jal   get_variable
/* 199CC8 8026B3E8 26100004 */   addiu $s0, $s0, 4
/* 199CCC 8026B3EC 0040202D */  daddu $a0, $v0, $zero
/* 199CD0 8026B3F0 2402FF81 */  addiu $v0, $zero, -0x7f
/* 199CD4 8026B3F4 14820002 */  bne   $a0, $v0, .L8026B400
/* 199CD8 8026B3F8 00000000 */   nop   
/* 199CDC 8026B3FC 8E240148 */  lw    $a0, 0x148($s1)
.L8026B400:
/* 199CE0 8026B400 0C09A75B */  jal   get_actor
/* 199CE4 8026B404 8E100000 */   lw    $s0, ($s0)
/* 199CE8 8026B408 0220202D */  daddu $a0, $s1, $zero
/* 199CEC 8026B40C C440018C */  lwc1  $f0, 0x18c($v0)
/* 199CF0 8026B410 4600008D */  trunc.w.s $f2, $f0
/* 199CF4 8026B414 44061000 */  mfc1  $a2, $f2
/* 199CF8 8026B418 0C0B2026 */  jal   set_variable
/* 199CFC 8026B41C 0200282D */   daddu $a1, $s0, $zero
/* 199D00 8026B420 8FBF0018 */  lw    $ra, 0x18($sp)
/* 199D04 8026B424 8FB10014 */  lw    $s1, 0x14($sp)
/* 199D08 8026B428 8FB00010 */  lw    $s0, 0x10($sp)
/* 199D0C 8026B42C 24020002 */  addiu $v0, $zero, 2
/* 199D10 8026B430 03E00008 */  jr    $ra
/* 199D14 8026B434 27BD0020 */   addiu $sp, $sp, 0x20

