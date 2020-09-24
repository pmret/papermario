.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_badges_get_column
/* 13A518 802471D8 00041040 */  sll       $v0, $a0, 1
/* 13A51C 802471DC 00441021 */  addu      $v0, $v0, $a0
/* 13A520 802471E0 00021080 */  sll       $v0, $v0, 2
/* 13A524 802471E4 3C018027 */  lui       $at, 0x8027
/* 13A528 802471E8 00220821 */  addu      $at, $at, $v0
/* 13A52C 802471EC 9022028A */  lbu       $v0, 0x28a($at)
/* 13A530 802471F0 14400002 */  bnez      $v0, .L802471FC
/* 13A534 802471F4 00A2001A */   div      $zero, $a1, $v0
/* 13A538 802471F8 0007000D */  break     7
.L802471FC:
/* 13A53C 802471FC 2401FFFF */   addiu    $at, $zero, -1
/* 13A540 80247200 14410004 */  bne       $v0, $at, .L80247214
/* 13A544 80247204 3C018000 */   lui      $at, 0x8000
/* 13A548 80247208 14A10002 */  bne       $a1, $at, .L80247214
/* 13A54C 8024720C 00000000 */   nop      
/* 13A550 80247210 0006000D */  break     6
.L80247214:
/* 13A554 80247214 00001010 */   mfhi     $v0
/* 13A558 80247218 03E00008 */  jr        $ra
/* 13A55C 8024721C 00000000 */   nop      
