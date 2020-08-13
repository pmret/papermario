.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80248C4C
/* 13BF8C 80248C4C AFA2001C */  sw    $v0, 0x1c($sp)
/* 13BF90 80248C50 24020140 */  addiu $v0, $zero, 0x140
/* 13BF94 80248C54 AFA20044 */  sw    $v0, 0x44($sp)
/* 13BF98 80248C58 240200F0 */  addiu $v0, $zero, 0xf0
/* 13BF9C 80248C5C AFA00010 */  sw    $zero, 0x10($sp)
/* 13BFA0 80248C60 AFA00020 */  sw    $zero, 0x20($sp)
/* 13BFA4 80248C64 AFA00024 */  sw    $zero, 0x24($sp)
/* 13BFA8 80248C68 AFA00028 */  sw    $zero, 0x28($sp)
/* 13BFAC 80248C6C AFA0002C */  sw    $zero, 0x2c($sp)
/* 13BFB0 80248C70 AFA00030 */  sw    $zero, 0x30($sp)
/* 13BFB4 80248C74 AFA00034 */  sw    $zero, 0x34($sp)
/* 13BFB8 80248C78 AFA00038 */  sw    $zero, 0x38($sp)
/* 13BFBC 80248C7C AFA0003C */  sw    $zero, 0x3c($sp)
/* 13BFC0 80248C80 AFA00040 */  sw    $zero, 0x40($sp)
/* 13BFC4 80248C84 AFA20048 */  sw    $v0, 0x48($sp)
/* 13BFC8 80248C88 AFA0004C */  sw    $zero, 0x4c($sp)
/* 13BFCC 80248C8C 25660043 */  addiu $a2, $t3, 0x43
/* 13BFD0 80248C90 0C03D4B8 */  jal   draw_box
/* 13BFD4 80248C94 2547003C */   addiu $a3, $t2, 0x3c
/* 13BFD8 80248C98 0C093BA0 */  jal   func_8024EE80
/* 13BFDC 80248C9C 2404004A */   addiu $a0, $zero, 0x4a
/* 13BFE0 80248CA0 0040202D */  daddu $a0, $v0, $zero
/* 13BFE4 80248CA4 8FAB00C4 */  lw    $t3, 0xc4($sp)
/* 13BFE8 80248CA8 8FAA00C8 */  lw    $t2, 0xc8($sp)
/* 13BFEC 80248CAC 240700FF */  addiu $a3, $zero, 0xff
/* 13BFF0 80248CB0 AFA00010 */  sw    $zero, 0x10($sp)
/* 13BFF4 80248CB4 AFB00014 */  sw    $s0, 0x14($sp)
/* 13BFF8 80248CB8 08092355 */  j     func_80248D54
/* 13BFFC 80248CBC 25650056 */   addiu $a1, $t3, 0x56

.L80248CC0:
/* 13C000 80248CC0 3C058027 */  lui   $a1, 0x8027
/* 13C004 80248CC4 24A5FBD8 */  addiu $a1, $a1, -0x428
/* 13C008 80248CC8 8FAB00C4 */  lw    $t3, 0xc4($sp)
