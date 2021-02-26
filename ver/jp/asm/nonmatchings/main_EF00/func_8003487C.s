.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003487C
/* FC7C 8003487C 3C02800A */  lui       $v0, %hi(D_8009E732)
/* FC80 80034880 8442E732 */  lh        $v0, %lo(D_8009E732)($v0)
/* FC84 80034884 18400005 */  blez      $v0, .L8003489C
/* FC88 80034888 24020004 */   addiu    $v0, $zero, 4
/* FC8C 8003488C 3C01800A */  lui       $at, %hi(D_8009E731)
/* FC90 80034890 A020E731 */  sb        $zero, %lo(D_8009E731)($at)
/* FC94 80034894 0800D22B */  j         .L800348AC
/* FC98 80034898 00000000 */   nop
.L8003489C:
/* FC9C 8003489C 24020001 */  addiu     $v0, $zero, 1
/* FCA0 800348A0 3C01800A */  lui       $at, %hi(D_8009E731)
/* FCA4 800348A4 A022E731 */  sb        $v0, %lo(D_8009E731)($at)
/* FCA8 800348A8 24020004 */  addiu     $v0, $zero, 4
.L800348AC:
/* FCAC 800348AC 3C01800A */  lui       $at, %hi(D_8009E730)
/* FCB0 800348B0 A022E730 */  sb        $v0, %lo(D_8009E730)($at)
/* FCB4 800348B4 03E00008 */  jr        $ra
/* FCB8 800348B8 00000000 */   nop
