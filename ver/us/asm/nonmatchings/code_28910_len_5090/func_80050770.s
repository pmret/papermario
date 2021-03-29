.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050770
/* 2BB70 80050770 44852000 */  mtc1      $a1, $f4
/* 2BB74 80050774 3C014000 */  lui       $at, 0x4000
/* 2BB78 80050778 44810800 */  mtc1      $at, $f1
/* 2BB7C 8005077C 44800000 */  mtc1      $zero, $f0
/* 2BB80 80050780 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2BB84 80050784 AFB00010 */  sw        $s0, 0x10($sp)
/* 2BB88 80050788 0080802D */  daddu     $s0, $a0, $zero
/* 2BB8C 8005078C 460020A1 */  cvt.d.s   $f2, $f4
/* 2BB90 80050790 4622003C */  c.lt.d    $f0, $f2
/* 2BB94 80050794 00000000 */  nop
/* 2BB98 80050798 45000005 */  bc1f      .L800507B0
/* 2BB9C 8005079C AFBF0014 */   sw       $ra, 0x14($sp)
/* 2BBA0 800507A0 3C014000 */  lui       $at, 0x4000
/* 2BBA4 800507A4 44812000 */  mtc1      $at, $f4
/* 2BBA8 800507A8 080141F6 */  j         .L800507D8
/* 2BBAC 800507AC 00000000 */   nop
.L800507B0:
/* 2BBB0 800507B0 3C013FD0 */  lui       $at, 0x3fd0
/* 2BBB4 800507B4 44810800 */  mtc1      $at, $f1
/* 2BBB8 800507B8 44800000 */  mtc1      $zero, $f0
/* 2BBBC 800507BC 00000000 */  nop
/* 2BBC0 800507C0 4620103C */  c.lt.d    $f2, $f0
/* 2BBC4 800507C4 00000000 */  nop
/* 2BBC8 800507C8 45000003 */  bc1f      .L800507D8
/* 2BBCC 800507CC 00000000 */   nop
/* 2BBD0 800507D0 3C013E80 */  lui       $at, 0x3e80
/* 2BBD4 800507D4 44812000 */  mtc1      $at, $f4
.L800507D8:
/* 2BBD8 800507D8 96050208 */  lhu       $a1, 0x208($s0)
/* 2BBDC 800507DC 0200202D */  daddu     $a0, $s0, $zero
/* 2BBE0 800507E0 0C013F02 */  jal       snd_bpm_to_tempo
/* 2BBE4 800507E4 E60400D0 */   swc1     $f4, 0xd0($s0)
/* 2BBE8 800507E8 00021880 */  sll       $v1, $v0, 2
/* 2BBEC 800507EC 00621821 */  addu      $v1, $v1, $v0
/* 2BBF0 800507F0 00031840 */  sll       $v1, $v1, 1
/* 2BBF4 800507F4 AE0200B0 */  sw        $v0, 0xb0($s0)
/* 2BBF8 800507F8 AE030008 */  sw        $v1, 8($s0)
/* 2BBFC 800507FC AE0000BC */  sw        $zero, 0xbc($s0)
/* 2BC00 80050800 AE0000B8 */  sw        $zero, 0xb8($s0)
/* 2BC04 80050804 AE0000B4 */  sw        $zero, 0xb4($s0)
/* 2BC08 80050808 8FBF0014 */  lw        $ra, 0x14($sp)
/* 2BC0C 8005080C 8FB00010 */  lw        $s0, 0x10($sp)
/* 2BC10 80050810 03E00008 */  jr        $ra
/* 2BC14 80050814 27BD0018 */   addiu    $sp, $sp, 0x18
