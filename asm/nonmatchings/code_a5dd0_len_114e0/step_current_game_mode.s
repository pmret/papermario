.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel step_current_game_mode
/* 0A9578 80112E78 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A957C 80112E7C AFB00010 */  sw    $s0, 0x10($sp)
/* 0A9580 80112E80 3C108015 */  lui   $s0, 0x8015
/* 0A9584 80112E84 26101700 */  addiu $s0, $s0, 0x1700
/* 0A9588 80112E88 AFB10014 */  sw    $s1, 0x14($sp)
/* 0A958C 80112E8C 0000882D */  daddu $s1, $zero, $zero
/* 0A9590 80112E90 AFBF0018 */  sw    $ra, 0x18($sp)
.L80112E94:
/* 0A9594 80112E94 96040000 */  lhu   $a0, ($s0)
/* 0A9598 80112E98 5080000C */  beql  $a0, $zero, .L80112ECC
/* 0A959C 80112E9C 26310001 */   addiu $s1, $s1, 1
/* 0A95A0 80112EA0 30820004 */  andi  $v0, $a0, 4
/* 0A95A4 80112EA4 54400009 */  bnel  $v0, $zero, .L80112ECC
/* 0A95A8 80112EA8 26310001 */   addiu $s1, $s1, 1
/* 0A95AC 80112EAC 30820008 */  andi  $v0, $a0, 8
/* 0A95B0 80112EB0 54400006 */  bnel  $v0, $zero, .L80112ECC
/* 0A95B4 80112EB4 26310001 */   addiu $s1, $s1, 1
/* 0A95B8 80112EB8 8E030008 */  lw    $v1, 8($s0)
/* 0A95BC 80112EBC 3082FFFD */  andi  $v0, $a0, 0xfffd
/* 0A95C0 80112EC0 0060F809 */  jalr  $v1
/* 0A95C4 80112EC4 A6020000 */  sh    $v0, ($s0)
/* 0A95C8 80112EC8 26310001 */  addiu $s1, $s1, 1
.L80112ECC:
/* 0A95CC 80112ECC 2A220002 */  slti  $v0, $s1, 2
/* 0A95D0 80112ED0 1440FFF0 */  bnez  $v0, .L80112E94
/* 0A95D4 80112ED4 26100018 */   addiu $s0, $s0, 0x18
/* 0A95D8 80112ED8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0A95DC 80112EDC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0A95E0 80112EE0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0A95E4 80112EE4 03E00008 */  jr    $ra
/* 0A95E8 80112EE8 27BD0020 */   addiu $sp, $sp, 0x20

/* 0A95EC 80112EEC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A95F0 80112EF0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0A95F4 80112EF4 3C108015 */  lui   $s0, 0x8015
/* 0A95F8 80112EF8 26101700 */  addiu $s0, $s0, 0x1700
/* 0A95FC 80112EFC AFB10014 */  sw    $s1, 0x14($sp)
/* 0A9600 80112F00 0000882D */  daddu $s1, $zero, $zero
/* 0A9604 80112F04 AFBF0018 */  sw    $ra, 0x18($sp)
.L80112F08:
/* 0A9608 80112F08 96030000 */  lhu   $v1, ($s0)
/* 0A960C 80112F0C 5060000A */  beql  $v1, $zero, .L80112F38
/* 0A9610 80112F10 26310001 */   addiu $s1, $s1, 1
/* 0A9614 80112F14 30620004 */  andi  $v0, $v1, 4
/* 0A9618 80112F18 14400007 */  bnez  $v0, .L80112F38
/* 0A961C 80112F1C 26310001 */   addiu $s1, $s1, 1
/* 0A9620 80112F20 30620010 */  andi  $v0, $v1, 0x10
/* 0A9624 80112F24 14400004 */  bnez  $v0, .L80112F38
/* 0A9628 80112F28 00000000 */   nop   
/* 0A962C 80112F2C 8E02000C */  lw    $v0, 0xc($s0)
/* 0A9630 80112F30 0040F809 */  jalr  $v0
/* 0A9634 80112F34 00000000 */  nop   
.L80112F38:
/* 0A9638 80112F38 2A220002 */  slti  $v0, $s1, 2
/* 0A963C 80112F3C 1440FFF2 */  bnez  $v0, .L80112F08
/* 0A9640 80112F40 26100018 */   addiu $s0, $s0, 0x18
/* 0A9644 80112F44 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0A9648 80112F48 8FB10014 */  lw    $s1, 0x14($sp)
/* 0A964C 80112F4C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0A9650 80112F50 03E00008 */  jr    $ra
/* 0A9654 80112F54 27BD0020 */   addiu $sp, $sp, 0x20

