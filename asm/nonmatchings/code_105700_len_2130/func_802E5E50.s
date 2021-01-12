.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E5E50
/* 1076D0 802E5E50 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1076D4 802E5E54 AFB10024 */  sw        $s1, 0x24($sp)
/* 1076D8 802E5E58 0080882D */  daddu     $s1, $a0, $zero
/* 1076DC 802E5E5C AFBF0028 */  sw        $ra, 0x28($sp)
/* 1076E0 802E5E60 AFB00020 */  sw        $s0, 0x20($sp)
/* 1076E4 802E5E64 0C0B9607 */  jal       func_802E581C
/* 1076E8 802E5E68 8E300040 */   lw       $s0, 0x40($s1)
/* 1076EC 802E5E6C 9202000A */  lbu       $v0, 0xa($s0)
/* 1076F0 802E5E70 54400001 */  bnel      $v0, $zero, .L802E5E78
/* 1076F4 802E5E74 AE20003C */   sw       $zero, 0x3c($s1)
.L802E5E78:
/* 1076F8 802E5E78 C62C0064 */  lwc1      $f12, 0x64($s1)
/* 1076FC 802E5E7C 3C014008 */  lui       $at, 0x4008
/* 107700 802E5E80 44810800 */  mtc1      $at, $f1
/* 107704 802E5E84 44800000 */  mtc1      $zero, $f0
/* 107708 802E5E88 46006321 */  cvt.d.s   $f12, $f12
/* 10770C 802E5E8C 46206300 */  add.d     $f12, $f12, $f0
/* 107710 802E5E90 0C00A6C9 */  jal       clamp_angle
/* 107714 802E5E94 46206320 */   cvt.s.d  $f12, $f12
/* 107718 802E5E98 E6200064 */  swc1      $f0, 0x64($s1)
/* 10771C 802E5E9C 960200D0 */  lhu       $v0, 0xd0($s0)
/* 107720 802E5EA0 00021080 */  sll       $v0, $v0, 2
/* 107724 802E5EA4 02021021 */  addu      $v0, $s0, $v0
/* 107728 802E5EA8 E44000D4 */  swc1      $f0, 0xd4($v0)
/* 10772C 802E5EAC 960200D0 */  lhu       $v0, 0xd0($s0)
/* 107730 802E5EB0 24420001 */  addiu     $v0, $v0, 1
/* 107734 802E5EB4 A60200D0 */  sh        $v0, 0xd0($s0)
/* 107738 802E5EB8 3042FFFF */  andi      $v0, $v0, 0xffff
/* 10773C 802E5EBC 2C420015 */  sltiu     $v0, $v0, 0x15
/* 107740 802E5EC0 50400001 */  beql      $v0, $zero, .L802E5EC8
/* 107744 802E5EC4 A60000D0 */   sh       $zero, 0xd0($s0)
.L802E5EC8:
/* 107748 802E5EC8 9202000A */  lbu       $v0, 0xa($s0)
/* 10774C 802E5ECC 1440001B */  bnez      $v0, .L802E5F3C
/* 107750 802E5ED0 00000000 */   nop
/* 107754 802E5ED4 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 107758 802E5ED8 8C42A650 */  lw        $v0, %lo(D_8009A650)($v0)
/* 10775C 802E5EDC 14400017 */  bnez      $v0, .L802E5F3C
/* 107760 802E5EE0 00000000 */   nop
/* 107764 802E5EE4 92020002 */  lbu       $v0, 2($s0)
/* 107768 802E5EE8 2442FFFF */  addiu     $v0, $v0, -1
/* 10776C 802E5EEC A2020002 */  sb        $v0, 2($s0)
/* 107770 802E5EF0 00021600 */  sll       $v0, $v0, 0x18
/* 107774 802E5EF4 1C400011 */  bgtz      $v0, .L802E5F3C
/* 107778 802E5EF8 24020032 */   addiu    $v0, $zero, 0x32
/* 10777C 802E5EFC 3C0141B0 */  lui       $at, 0x41b0
/* 107780 802E5F00 44810000 */  mtc1      $at, $f0
/* 107784 802E5F04 3C014100 */  lui       $at, 0x4100
/* 107788 802E5F08 44811000 */  mtc1      $at, $f2
/* 10778C 802E5F0C A2020002 */  sb        $v0, 2($s0)
/* 107790 802E5F10 24020004 */  addiu     $v0, $zero, 4
/* 107794 802E5F14 AFA20018 */  sw        $v0, 0x18($sp)
/* 107798 802E5F18 24020014 */  addiu     $v0, $zero, 0x14
/* 10779C 802E5F1C AFA2001C */  sw        $v0, 0x1c($sp)
/* 1077A0 802E5F20 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1077A4 802E5F24 E7A20014 */  swc1      $f2, 0x14($sp)
/* 1077A8 802E5F28 8E250048 */  lw        $a1, 0x48($s1)
/* 1077AC 802E5F2C 8E26004C */  lw        $a2, 0x4c($s1)
/* 1077B0 802E5F30 8E270050 */  lw        $a3, 0x50($s1)
/* 1077B4 802E5F34 0C01C154 */  jal       func_80070550
/* 1077B8 802E5F38 24040003 */   addiu    $a0, $zero, 3
.L802E5F3C:
/* 1077BC 802E5F3C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 1077C0 802E5F40 8FB10024 */  lw        $s1, 0x24($sp)
/* 1077C4 802E5F44 8FB00020 */  lw        $s0, 0x20($sp)
/* 1077C8 802E5F48 03E00008 */  jr        $ra
/* 1077CC 802E5F4C 27BD0030 */   addiu    $sp, $sp, 0x30
