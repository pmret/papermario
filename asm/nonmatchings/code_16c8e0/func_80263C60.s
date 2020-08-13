.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80263C60
/* 192540 80263C60 0000202D */  daddu $a0, $zero, $zero
/* 192544 80263C64 3C05800E */  lui   $a1, 0x800e
/* 192548 80263C68 24A5C070 */  addiu $a1, $a1, -0x3f90
/* 19254C 80263C6C 00A0182D */  daddu $v1, $a1, $zero
.L80263C70:
/* 192550 80263C70 8C6200E0 */  lw    $v0, 0xe0($v1)
/* 192554 80263C74 10400004 */  beqz  $v0, .L80263C88
/* 192558 80263C78 24840001 */   addiu $a0, $a0, 1
/* 19255C 80263C7C A44001FA */  sh    $zero, 0x1fa($v0)
/* 192560 80263C80 A44001FC */  sh    $zero, 0x1fc($v0)
/* 192564 80263C84 A0400204 */  sb    $zero, 0x204($v0)
.L80263C88:
/* 192568 80263C88 28820018 */  slti  $v0, $a0, 0x18
/* 19256C 80263C8C 1440FFF8 */  bnez  $v0, .L80263C70
/* 192570 80263C90 24630004 */   addiu $v1, $v1, 4
/* 192574 80263C94 8CA200D8 */  lw    $v0, 0xd8($a1)
/* 192578 80263C98 A44001FA */  sh    $zero, 0x1fa($v0)
/* 19257C 80263C9C A44001FC */  sh    $zero, 0x1fc($v0)
/* 192580 80263CA0 A0400204 */  sb    $zero, 0x204($v0)
/* 192584 80263CA4 8CA200DC */  lw    $v0, 0xdc($a1)
/* 192588 80263CA8 10400004 */  beqz  $v0, .L80263CBC
/* 19258C 80263CAC 00000000 */   nop   
/* 192590 80263CB0 A44001FA */  sh    $zero, 0x1fa($v0)
/* 192594 80263CB4 A44001FC */  sh    $zero, 0x1fc($v0)
/* 192598 80263CB8 A0400204 */  sb    $zero, 0x204($v0)
.L80263CBC:
/* 19259C 80263CBC 03E00008 */  jr    $ra
/* 1925A0 80263CC0 00000000 */   nop   

/* 1925A4 80263CC4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1925A8 80263CC8 AFB00010 */  sw    $s0, 0x10($sp)
/* 1925AC 80263CCC 0080802D */  daddu $s0, $a0, $zero
/* 1925B0 80263CD0 3C048029 */  lui   $a0, 0x8029
/* 1925B4 80263CD4 24843820 */  addiu $a0, $a0, 0x3820
/* 1925B8 80263CD8 2405000A */  addiu $a1, $zero, 0xa
/* 1925BC 80263CDC AFBF0014 */  sw    $ra, 0x14($sp)
/* 1925C0 80263CE0 0C0B0CF8 */  jal   start_script
/* 1925C4 80263CE4 0000302D */   daddu $a2, $zero, $zero
/* 1925C8 80263CE8 AC500084 */  sw    $s0, 0x84($v0)
/* 1925CC 80263CEC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1925D0 80263CF0 8FB00010 */  lw    $s0, 0x10($sp)
/* 1925D4 80263CF4 03E00008 */  jr    $ra
/* 1925D8 80263CF8 27BD0018 */   addiu $sp, $sp, 0x18

