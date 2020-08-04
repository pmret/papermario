.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80048170
/* 023570 80048170 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 023574 80048174 00041040 */  sll   $v0, $a0, 1
/* 023578 80048178 00441021 */  addu  $v0, $v0, $a0
/* 02357C 8004817C 00021080 */  sll   $v0, $v0, 2
/* 023580 80048180 00441023 */  subu  $v0, $v0, $a0
/* 023584 80048184 3C03800A */  lui   $v1, 0x800a
/* 023588 80048188 8C630F44 */  lw    $v1, 0xf44($v1)
/* 02358C 8004818C 00021100 */  sll   $v0, $v0, 4
/* 023590 80048190 AFBF0018 */  sw    $ra, 0x18($sp)
/* 023594 80048194 AFB10014 */  sw    $s1, 0x14($sp)
/* 023598 80048198 AFB00010 */  sw    $s0, 0x10($sp)
/* 02359C 8004819C 00628821 */  addu  $s1, $v1, $v0
/* 0235A0 800481A0 2403F7FF */  addiu $v1, $zero, -0x801
/* 0235A4 800481A4 8E220000 */  lw    $v0, ($s1)
/* 0235A8 800481A8 822400A8 */  lb    $a0, 0xa8($s1)
/* 0235AC 800481AC 00431024 */  and   $v0, $v0, $v1
/* 0235B0 800481B0 1480000E */  bnez  $a0, .L800481EC
/* 0235B4 800481B4 AE220000 */   sw    $v0, ($s1)
/* 0235B8 800481B8 3C048011 */  lui   $a0, 0x8011
/* 0235BC 800481BC 24848A14 */  addiu $a0, $a0, -0x75ec
/* 0235C0 800481C0 24020001 */  addiu $v0, $zero, 1
/* 0235C4 800481C4 0C050529 */  jal   create_icon
/* 0235C8 800481C8 A22200A8 */   sb    $v0, 0xa8($s1)
/* 0235CC 800481CC 0040802D */  daddu $s0, $v0, $zero
/* 0235D0 800481D0 0200202D */  daddu $a0, $s0, $zero
/* 0235D4 800481D4 0C051280 */  jal   set_icon_flags
/* 0235D8 800481D8 24050002 */   addiu $a1, $zero, 2
/* 0235DC 800481DC 0200202D */  daddu $a0, $s0, $zero
/* 0235E0 800481E0 0C051280 */  jal   set_icon_flags
/* 0235E4 800481E4 24050080 */   addiu $a1, $zero, 0x80
/* 0235E8 800481E8 AE3000AC */  sw    $s0, 0xac($s1)
.L800481EC:
/* 0235EC 800481EC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0235F0 800481F0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0235F4 800481F4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0235F8 800481F8 03E00008 */  jr    $ra
/* 0235FC 800481FC 27BD0020 */   addiu $sp, $sp, 0x20

