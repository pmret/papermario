.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004C844
/* 27C44 8004C844 948300B8 */  lhu       $v1, 0xb8($a0)
/* 27C48 8004C848 84A2005C */  lh        $v0, 0x5c($a1)
/* 27C4C 8004C84C 00620018 */  mult      $v1, $v0
/* 27C50 8004C850 90A2009A */  lbu       $v0, 0x9a($a1)
/* 27C54 8004C854 30420004 */  andi      $v0, $v0, 4
/* 27C58 8004C858 00003012 */  mflo      $a2
/* 27C5C 8004C85C 14400006 */  bnez      $v0, .L8004C878
/* 27C60 8004C860 00061BC3 */   sra      $v1, $a2, 0xf
/* 27C64 8004C864 84A200A6 */  lh        $v0, 0xa6($a1)
/* 27C68 8004C868 10400003 */  beqz      $v0, .L8004C878
/* 27C6C 8004C86C 00620018 */   mult     $v1, $v0
/* 27C70 8004C870 00003012 */  mflo      $a2
/* 27C74 8004C874 00061BC3 */  sra       $v1, $a2, 0xf
.L8004C878:
/* 27C78 8004C878 00031400 */  sll       $v0, $v1, 0x10
/* 27C7C 8004C87C 03E00008 */  jr        $ra
/* 27C80 8004C880 00021403 */   sra      $v0, $v0, 0x10
