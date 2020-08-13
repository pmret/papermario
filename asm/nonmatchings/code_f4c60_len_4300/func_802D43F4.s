.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802D43F4
/* 0F8DA4 802D43F4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F8DA8 802D43F8 3C02802E */  lui   $v0, 0x802e
/* 0F8DAC 802D43FC 8C42B7C0 */  lw    $v0, -0x4840($v0)
/* 0F8DB0 802D4400 00042080 */  sll   $a0, $a0, 2
/* 0F8DB4 802D4404 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F8DB8 802D4408 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F8DBC 802D440C 00822021 */  addu  $a0, $a0, $v0
/* 0F8DC0 802D4410 8C900000 */  lw    $s0, ($a0)
/* 0F8DC4 802D4414 0C048B7F */  jal   func_80122DFC
/* 0F8DC8 802D4418 8E040000 */   lw    $a0, ($s0)
/* 0F8DCC 802D441C 2402FFFF */  addiu $v0, $zero, -1
/* 0F8DD0 802D4420 AE020000 */  sw    $v0, ($s0)
/* 0F8DD4 802D4424 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F8DD8 802D4428 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F8DDC 802D442C 03E00008 */  jr    $ra
/* 0F8DE0 802D4430 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F8DE4 802D4434 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F8DE8 802D4438 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F8DEC 802D443C 0080282D */  daddu $a1, $a0, $zero
/* 0F8DF0 802D4440 0000202D */  daddu $a0, $zero, $zero
.L802D4444:
/* 0F8DF4 802D4444 3C02802E */  lui   $v0, 0x802e
/* 0F8DF8 802D4448 8C42B7C0 */  lw    $v0, -0x4840($v0)
/* 0F8DFC 802D444C 00041880 */  sll   $v1, $a0, 2
/* 0F8E00 802D4450 00621821 */  addu  $v1, $v1, $v0
/* 0F8E04 802D4454 8C620000 */  lw    $v0, ($v1)
/* 0F8E08 802D4458 54450005 */  bnel  $v0, $a1, .L802D4470
/* 0F8E0C 802D445C 24840001 */   addiu $a0, $a0, 1
/* 0F8E10 802D4460 0C0B50FD */  jal   func_802D43F4
/* 0F8E14 802D4464 00000000 */   nop   
/* 0F8E18 802D4468 080B511F */  j     .L802D447C
/* 0F8E1C 802D446C 00000000 */   nop   

.L802D4470:
/* 0F8E20 802D4470 28820040 */  slti  $v0, $a0, 0x40
/* 0F8E24 802D4474 1440FFF3 */  bnez  $v0, .L802D4444
/* 0F8E28 802D4478 00000000 */   nop   
.L802D447C:
/* 0F8E2C 802D447C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F8E30 802D4480 03E00008 */  jr    $ra
/* 0F8E34 802D4484 27BD0018 */   addiu $sp, $sp, 0x18

