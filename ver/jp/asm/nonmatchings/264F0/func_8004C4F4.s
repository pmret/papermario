.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004C4F4
/* 278F4 8004C4F4 948300B8 */  lhu       $v1, 0xb8($a0)
/* 278F8 8004C4F8 84A2005C */  lh        $v0, 0x5c($a1)
/* 278FC 8004C4FC 00620018 */  mult      $v1, $v0
/* 27900 8004C500 90A2009A */  lbu       $v0, 0x9a($a1)
/* 27904 8004C504 30420004 */  andi      $v0, $v0, 4
/* 27908 8004C508 00003012 */  mflo      $a2
/* 2790C 8004C50C 14400006 */  bnez      $v0, .L8004C528
/* 27910 8004C510 00061BC3 */   sra      $v1, $a2, 0xf
/* 27914 8004C514 84A200A6 */  lh        $v0, 0xa6($a1)
/* 27918 8004C518 10400003 */  beqz      $v0, .L8004C528
/* 2791C 8004C51C 00620018 */   mult     $v1, $v0
/* 27920 8004C520 00003012 */  mflo      $a2
/* 27924 8004C524 00061BC3 */  sra       $v1, $a2, 0xf
.L8004C528:
/* 27928 8004C528 00031400 */  sll       $v0, $v1, 0x10
/* 2792C 8004C52C 03E00008 */  jr        $ra
/* 27930 8004C530 00021403 */   sra      $v0, $v0, 0x10
