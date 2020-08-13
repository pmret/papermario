.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel allocate_hit_tables
/* 0362A0 8005AEA0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0362A4 8005AEA4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0362A8 8005AEA8 3C10800B */  lui   $s0, 0x800b
/* 0362AC 8005AEAC 261042E0 */  addiu $s0, $s0, 0x42e0
/* 0362B0 8005AEB0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0362B4 8005AEB4 8604000C */  lh    $a0, 0xc($s0)
/* 0362B8 8005AEB8 0C00AB0A */  jal   general_heap_malloc
/* 0362BC 8005AEBC 000420C0 */   sll   $a0, $a0, 3
/* 0362C0 8005AEC0 0040202D */  daddu $a0, $v0, $zero
/* 0362C4 8005AEC4 8602000C */  lh    $v0, 0xc($s0)
/* 0362C8 8005AEC8 3C01800A */  lui   $at, 0x800a
/* 0362CC 8005AECC AC244264 */  sw    $a0, 0x4264($at)
/* 0362D0 8005AED0 1840000E */  blez  $v0, .L8005AF0C
/* 0362D4 8005AED4 0000282D */   daddu $a1, $zero, $zero
/* 0362D8 8005AED8 00A0302D */  daddu $a2, $a1, $zero
.L8005AEDC:
/* 0362DC 8005AEDC 8E020004 */  lw    $v0, 4($s0)
/* 0362E0 8005AEE0 00461821 */  addu  $v1, $v0, $a2
/* 0362E4 8005AEE4 8C620000 */  lw    $v0, ($v1)
/* 0362E8 8005AEE8 24A50001 */  addiu $a1, $a1, 1
/* 0362EC 8005AEEC AC820000 */  sw    $v0, ($a0)
/* 0362F0 8005AEF0 94620008 */  lhu   $v0, 8($v1)
/* 0362F4 8005AEF4 24C6001C */  addiu $a2, $a2, 0x1c
/* 0362F8 8005AEF8 A4820004 */  sh    $v0, 4($a0)
/* 0362FC 8005AEFC 8602000C */  lh    $v0, 0xc($s0)
/* 036300 8005AF00 00A2102A */  slt   $v0, $a1, $v0
/* 036304 8005AF04 1440FFF5 */  bnez  $v0, .L8005AEDC
/* 036308 8005AF08 24840008 */   addiu $a0, $a0, 8
.L8005AF0C:
/* 03630C 8005AF0C 3C10800E */  lui   $s0, 0x800e
/* 036310 8005AF10 261091D0 */  addiu $s0, $s0, -0x6e30
/* 036314 8005AF14 8604000C */  lh    $a0, 0xc($s0)
/* 036318 8005AF18 0C00AB0A */  jal   general_heap_malloc
/* 03631C 8005AF1C 000420C0 */   sll   $a0, $a0, 3
/* 036320 8005AF20 0040202D */  daddu $a0, $v0, $zero
/* 036324 8005AF24 8602000C */  lh    $v0, 0xc($s0)
/* 036328 8005AF28 3C01800A */  lui   $at, 0x800a
/* 03632C 8005AF2C AC244268 */  sw    $a0, 0x4268($at)
/* 036330 8005AF30 1840000E */  blez  $v0, .L8005AF6C
/* 036334 8005AF34 0000282D */   daddu $a1, $zero, $zero
/* 036338 8005AF38 00A0302D */  daddu $a2, $a1, $zero
.L8005AF3C:
/* 03633C 8005AF3C 8E020004 */  lw    $v0, 4($s0)
/* 036340 8005AF40 00461821 */  addu  $v1, $v0, $a2
/* 036344 8005AF44 8C620000 */  lw    $v0, ($v1)
/* 036348 8005AF48 24A50001 */  addiu $a1, $a1, 1
/* 03634C 8005AF4C AC820000 */  sw    $v0, ($a0)
/* 036350 8005AF50 94620008 */  lhu   $v0, 8($v1)
/* 036354 8005AF54 24C6001C */  addiu $a2, $a2, 0x1c
/* 036358 8005AF58 A4820004 */  sh    $v0, 4($a0)
/* 03635C 8005AF5C 8602000C */  lh    $v0, 0xc($s0)
/* 036360 8005AF60 00A2102A */  slt   $v0, $a1, $v0
/* 036364 8005AF64 1440FFF5 */  bnez  $v0, .L8005AF3C
/* 036368 8005AF68 24840008 */   addiu $a0, $a0, 8
.L8005AF6C:
/* 03636C 8005AF6C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 036370 8005AF70 8FB00010 */  lw    $s0, 0x10($sp)
/* 036374 8005AF74 3C01800E */  lui   $at, 0x800e
/* 036378 8005AF78 A42091DC */  sh    $zero, -0x6e24($at)
/* 03637C 8005AF7C 03E00008 */  jr    $ra
/* 036380 8005AF80 27BD0018 */   addiu $sp, $sp, 0x18

