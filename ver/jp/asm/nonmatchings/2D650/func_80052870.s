.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80052870
/* 2DC70 80052870 3C02B65C */  lui       $v0, 0xb65c
/* 2DC74 80052874 34426D59 */  ori       $v0, $v0, 0x6d59
/* 2DC78 80052878 00820018 */  mult      $a0, $v0
/* 2DC7C 8005287C 00002810 */  mfhi      $a1
/* 2DC80 80052880 00A41821 */  addu      $v1, $a1, $a0
/* 2DC84 80052884 00031B03 */  sra       $v1, $v1, 0xc
/* 2DC88 80052888 000427C3 */  sra       $a0, $a0, 0x1f
/* 2DC8C 8005288C 00641823 */  subu      $v1, $v1, $a0
/* 2DC90 80052890 00031040 */  sll       $v0, $v1, 1
/* 2DC94 80052894 00431021 */  addu      $v0, $v0, $v1
/* 2DC98 80052898 000210C0 */  sll       $v0, $v0, 3
/* 2DC9C 8005289C 00431023 */  subu      $v0, $v0, $v1
/* 2DCA0 800528A0 03E00008 */  jr        $ra
/* 2DCA4 800528A4 000210C0 */   sll      $v0, $v0, 3
