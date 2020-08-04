.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetIndexFromHome
/* 1989B4 8026A0D4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1989B8 8026A0D8 AFB10014 */  sw    $s1, 0x14($sp)
/* 1989BC 8026A0DC 0080882D */  daddu $s1, $a0, $zero
/* 1989C0 8026A0E0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 1989C4 8026A0E4 AFB00010 */  sw    $s0, 0x10($sp)
/* 1989C8 8026A0E8 8E30000C */  lw    $s0, 0xc($s1)
/* 1989CC 8026A0EC 8E050000 */  lw    $a1, ($s0)
/* 1989D0 8026A0F0 0C0B1EAF */  jal   get_variable
/* 1989D4 8026A0F4 26100004 */   addiu $s0, $s0, 4
/* 1989D8 8026A0F8 0040202D */  daddu $a0, $v0, $zero
/* 1989DC 8026A0FC 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1989E0 8026A100 14820002 */  bne   $a0, $v0, .L8026A10C
/* 1989E4 8026A104 8E100000 */   lw    $s0, ($s0)
/* 1989E8 8026A108 8E240148 */  lw    $a0, 0x148($s1)
.L8026A10C:
/* 1989EC 8026A10C 0C09A75B */  jal   get_actor
/* 1989F0 8026A110 00000000 */   nop   
/* 1989F4 8026A114 8C460140 */  lw    $a2, 0x140($v0)
/* 1989F8 8026A118 C44C0138 */  lwc1  $f12, 0x138($v0)
/* 1989FC 8026A11C 0C09A5A6 */  jal   get_nearest_home_index
/* 198A00 8026A120 C44E013C */   lwc1  $f14, 0x13c($v0)
/* 198A04 8026A124 0220202D */  daddu $a0, $s1, $zero
/* 198A08 8026A128 0200282D */  daddu $a1, $s0, $zero
/* 198A0C 8026A12C 0C0B2026 */  jal   set_variable
/* 198A10 8026A130 0040302D */   daddu $a2, $v0, $zero
/* 198A14 8026A134 8FBF0018 */  lw    $ra, 0x18($sp)
/* 198A18 8026A138 8FB10014 */  lw    $s1, 0x14($sp)
/* 198A1C 8026A13C 8FB00010 */  lw    $s0, 0x10($sp)
/* 198A20 8026A140 24020002 */  addiu $v0, $zero, 2
/* 198A24 8026A144 03E00008 */  jr    $ra
/* 198A28 8026A148 27BD0020 */   addiu $sp, $sp, 0x20

