.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800505B0
/* 2B9B0 800505B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2B9B4 800505B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 2B9B8 800505B8 0080882D */  daddu     $s1, $a0, $zero
/* 2B9BC 800505BC AFB00010 */  sw        $s0, 0x10($sp)
/* 2B9C0 800505C0 0000802D */  daddu     $s0, $zero, $zero
/* 2B9C4 800505C4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 2B9C8 800505C8 320500FF */  andi      $a1, $s0, 0xff
.L800505CC:
/* 2B9CC 800505CC 000510C0 */  sll       $v0, $a1, 3
/* 2B9D0 800505D0 00451021 */  addu      $v0, $v0, $a1
/* 2B9D4 800505D4 000210C0 */  sll       $v0, $v0, 3
/* 2B9D8 800505D8 8E230000 */  lw        $v1, ($s1)
/* 2B9DC 800505DC 24421320 */  addiu     $v0, $v0, 0x1320
/* 2B9E0 800505E0 00622021 */  addu      $a0, $v1, $v0
/* 2B9E4 800505E4 90830045 */  lbu       $v1, 0x45($a0)
/* 2B9E8 800505E8 92220234 */  lbu       $v0, 0x234($s1)
/* 2B9EC 800505EC 14620003 */  bne       $v1, $v0, .L800505FC
/* 2B9F0 800505F0 26100001 */   addiu    $s0, $s0, 1
/* 2B9F4 800505F4 0C014D5D */  jal       func_80053574
/* 2B9F8 800505F8 00000000 */   nop
.L800505FC:
/* 2B9FC 800505FC 320200FF */  andi      $v0, $s0, 0xff
/* 2BA00 80050600 2C420018 */  sltiu     $v0, $v0, 0x18
/* 2BA04 80050604 1440FFF1 */  bnez      $v0, .L800505CC
/* 2BA08 80050608 320500FF */   andi     $a1, $s0, 0xff
/* 2BA0C 8005060C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 2BA10 80050610 8FB10014 */  lw        $s1, 0x14($sp)
/* 2BA14 80050614 8FB00010 */  lw        $s0, 0x10($sp)
/* 2BA18 80050618 03E00008 */  jr        $ra
/* 2BA1C 8005061C 27BD0020 */   addiu    $sp, $sp, 0x20
