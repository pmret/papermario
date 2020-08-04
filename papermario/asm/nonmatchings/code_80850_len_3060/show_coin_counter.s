.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel show_coin_counter
/* 0829C8 800E9518 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0829CC 800E951C AFB00028 */  sw    $s0, 0x28($sp)
/* 0829D0 800E9520 3C108011 */  lui   $s0, 0x8011
/* 0829D4 800E9524 2610CD10 */  addiu $s0, $s0, -0x32f0
/* 0829D8 800E9528 AFBF0030 */  sw    $ra, 0x30($sp)
/* 0829DC 800E952C AFB1002C */  sw    $s1, 0x2c($sp)
/* 0829E0 800E9530 86020000 */  lh    $v0, ($s0)
/* 0829E4 800E9534 3C118011 */  lui   $s1, 0x8011
/* 0829E8 800E9538 2631EF58 */  addiu $s1, $s1, -0x10a8
/* 0829EC 800E953C 14400005 */  bnez  $v0, .L800E9554
/* 0829F0 800E9540 24040014 */   addiu $a0, $zero, 0x14
/* 0829F4 800E9544 3C028011 */  lui   $v0, 0x8011
/* 0829F8 800E9548 8442CD12 */  lh    $v0, -0x32ee($v0)
/* 0829FC 800E954C 10400012 */  beqz  $v0, .L800E9598
/* 082A00 800E9550 00000000 */   nop   
.L800E9554:
/* 082A04 800E9554 0C051F9F */  jal   func_80147E7C
/* 082A08 800E9558 24050002 */   addiu $a1, $zero, 2
/* 082A0C 800E955C 8E220064 */  lw    $v0, 0x64($s1)
/* 082A10 800E9560 04420009 */  bltzl $v0, .L800E9588
/* 082A14 800E9564 A220006C */   sb    $zero, 0x6c($s1)
/* 082A18 800E9568 8E24005C */  lw    $a0, 0x5c($s1)
/* 082A1C 800E956C 0C05123D */  jal   free_icon
/* 082A20 800E9570 00000000 */   nop   
/* 082A24 800E9574 0C05123D */  jal   free_icon
/* 082A28 800E9578 8E240060 */   lw    $a0, 0x60($s1)
/* 082A2C 800E957C 2402FFFF */  addiu $v0, $zero, -1
/* 082A30 800E9580 AE220064 */  sw    $v0, 0x64($s1)
/* 082A34 800E9584 A220006C */  sb    $zero, 0x6c($s1)
.L800E9588:
/* 082A38 800E9588 A220006D */  sb    $zero, 0x6d($s1)
/* 082A3C 800E958C A6000000 */  sh    $zero, ($s0)
/* 082A40 800E9590 3C018011 */  lui   $at, 0x8011
/* 082A44 800E9594 A420CD12 */  sh    $zero, -0x32ee($at)
.L800E9598:
/* 082A48 800E9598 8222006C */  lb    $v0, 0x6c($s1)
/* 082A4C 800E959C 14400039 */  bnez  $v0, .L800E9684
/* 082A50 800E95A0 24040014 */   addiu $a0, $zero, 0x14
/* 082A54 800E95A4 24050020 */  addiu $a1, $zero, 0x20
/* 082A58 800E95A8 240600A4 */  addiu $a2, $zero, 0xa4
/* 082A5C 800E95AC 24070040 */  addiu $a3, $zero, 0x40
/* 082A60 800E95B0 0080102D */  daddu $v0, $a0, $zero
/* 082A64 800E95B4 AFA20010 */  sw    $v0, 0x10($sp)
/* 082A68 800E95B8 24020015 */  addiu $v0, $zero, 0x15
/* 082A6C 800E95BC AFA20014 */  sw    $v0, 0x14($sp)
/* 082A70 800E95C0 3C02800F */  lui   $v0, 0x800f
/* 082A74 800E95C4 244292D8 */  addiu $v0, $v0, -0x6d28
/* 082A78 800E95C8 AFA20018 */  sw    $v0, 0x18($sp)
/* 082A7C 800E95CC 2402FFFF */  addiu $v0, $zero, -1
/* 082A80 800E95D0 AFA0001C */  sw    $zero, 0x1c($sp)
/* 082A84 800E95D4 0C051F32 */  jal   func_80147CC8
/* 082A88 800E95D8 AFA20020 */   sw    $v0, 0x20($sp)
/* 082A8C 800E95DC 3C058014 */  lui   $a1, 0x8014
/* 082A90 800E95E0 24A57474 */  addiu $a1, $a1, 0x7474
/* 082A94 800E95E4 0C051F9F */  jal   func_80147E7C
/* 082A98 800E95E8 24040014 */   addiu $a0, $zero, 0x14
/* 082A9C 800E95EC 3C048011 */  lui   $a0, 0x8011
/* 082AA0 800E95F0 24849270 */  addiu $a0, $a0, -0x6d90
/* 082AA4 800E95F4 0C050529 */  jal   create_icon
/* 082AA8 800E95F8 00000000 */   nop   
/* 082AAC 800E95FC 0040802D */  daddu $s0, $v0, $zero
/* 082AB0 800E9600 0200202D */  daddu $a0, $s0, $zero
/* 082AB4 800E9604 24050080 */  addiu $a1, $zero, 0x80
/* 082AB8 800E9608 0C051280 */  jal   set_icon_flags
/* 082ABC 800E960C AE30005C */   sw    $s0, 0x5c($s1)
/* 082AC0 800E9610 0200202D */  daddu $a0, $s0, $zero
/* 082AC4 800E9614 240500FF */  addiu $a1, $zero, 0xff
/* 082AC8 800E9618 00A0302D */  daddu $a2, $a1, $zero
/* 082ACC 800E961C 0C0513BF */  jal   func_80144EFC
/* 082AD0 800E9620 00A0382D */   daddu $a3, $a1, $zero
/* 082AD4 800E9624 3C048011 */  lui   $a0, 0x8011
/* 082AD8 800E9628 24848558 */  addiu $a0, $a0, -0x7aa8
/* 082ADC 800E962C 0C050529 */  jal   create_icon
/* 082AE0 800E9630 00000000 */   nop   
/* 082AE4 800E9634 0040802D */  daddu $s0, $v0, $zero
/* 082AE8 800E9638 0200202D */  daddu $a0, $s0, $zero
/* 082AEC 800E963C 24050080 */  addiu $a1, $zero, 0x80
/* 082AF0 800E9640 0C051280 */  jal   set_icon_flags
/* 082AF4 800E9644 AE300060 */   sw    $s0, 0x60($s1)
/* 082AF8 800E9648 0200202D */  daddu $a0, $s0, $zero
/* 082AFC 800E964C 240500FF */  addiu $a1, $zero, 0xff
/* 082B00 800E9650 00A0302D */  daddu $a2, $a1, $zero
/* 082B04 800E9654 0C0513BF */  jal   func_80144EFC
/* 082B08 800E9658 00A0382D */   daddu $a3, $a1, $zero
/* 082B0C 800E965C 8222006E */  lb    $v0, 0x6e($s1)
/* 082B10 800E9660 04410003 */  bgez  $v0, .L800E9670
/* 082B14 800E9664 A220006C */   sb    $zero, 0x6c($s1)
/* 082B18 800E9668 92220044 */  lbu   $v0, 0x44($s1)
/* 082B1C 800E966C A222006E */  sb    $v0, 0x6e($s1)
.L800E9670:
/* 082B20 800E9670 24020001 */  addiu $v0, $zero, 1
/* 082B24 800E9674 A2220044 */  sb    $v0, 0x44($s1)
/* 082B28 800E9678 24020001 */  addiu $v0, $zero, 1
/* 082B2C 800E967C 3C018011 */  lui   $at, 0x8011
/* 082B30 800E9680 A422CD10 */  sh    $v0, -0x32f0($at)
.L800E9684:
/* 082B34 800E9684 8FBF0030 */  lw    $ra, 0x30($sp)
/* 082B38 800E9688 8FB1002C */  lw    $s1, 0x2c($sp)
/* 082B3C 800E968C 8FB00028 */  lw    $s0, 0x28($sp)
/* 082B40 800E9690 03E00008 */  jr    $ra
/* 082B44 800E9694 27BD0038 */   addiu $sp, $sp, 0x38

