.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osVirtualToPhysical
/* 03D290 80061E90 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03D294 80061E94 3C031FFF */  lui   $v1, 0x1fff
/* 03D298 80061E98 3463FFFF */  ori   $v1, $v1, 0xffff
/* 03D29C 80061E9C 3C028000 */  lui   $v0, 0x8000
/* 03D2A0 80061EA0 00821023 */  subu  $v0, $a0, $v0
/* 03D2A4 80061EA4 0062102B */  sltu  $v0, $v1, $v0
/* 03D2A8 80061EA8 1040000A */  beqz  $v0, .L80061ED4
/* 03D2AC 80061EAC AFBF0010 */   sw    $ra, 0x10($sp)
/* 03D2B0 80061EB0 3C026000 */  lui   $v0, 0x6000
/* 03D2B4 80061EB4 00821021 */  addu  $v0, $a0, $v0
/* 03D2B8 80061EB8 0062102B */  sltu  $v0, $v1, $v0
/* 03D2BC 80061EBC 10400006 */  beqz  $v0, .L80061ED8
/* 03D2C0 80061EC0 00831024 */   and   $v0, $a0, $v1
/* 03D2C4 80061EC4 0C019A18 */  jal   osProbeTLB
/* 03D2C8 80061EC8 00000000 */   nop   
/* 03D2CC 80061ECC 080187B6 */  j     .L80061ED8
/* 03D2D0 80061ED0 00000000 */   nop   

.L80061ED4:
/* 03D2D4 80061ED4 00831024 */  and   $v0, $a0, $v1
.L80061ED8:
/* 03D2D8 80061ED8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03D2DC 80061EDC 03E00008 */  jr    $ra
/* 03D2E0 80061EE0 27BD0018 */   addiu $sp, $sp, 0x18

/* 03D2E4 80061EE4 00000000 */  nop   
/* 03D2E8 80061EE8 00000000 */  nop   
/* 03D2EC 80061EEC 00000000 */  nop   

.set reorder
