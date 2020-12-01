.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802620F8
/* 1909D8 802620F8 8C8200BC */  lw        $v0, 0xbc($a0)
/* 1909DC 802620FC 3C03802A */  lui       $v1, %hi(D_8029FBB0)
/* 1909E0 80262100 2463FBB0 */  addiu     $v1, $v1, %lo(D_8029FBB0)
/* 1909E4 80262104 00021080 */  sll       $v0, $v0, 2
/* 1909E8 80262108 00431821 */  addu      $v1, $v0, $v1
/* 1909EC 8026210C 8C620000 */  lw        $v0, ($v1)
/* 1909F0 80262110 14400003 */  bnez      $v0, .L80262120
/* 1909F4 80262114 2442FFFF */   addiu    $v0, $v0, -1
/* 1909F8 80262118 03E00008 */  jr        $ra
/* 1909FC 8026211C 24020002 */   addiu    $v0, $zero, 2
.L80262120:
/* 190A00 80262120 AC620000 */  sw        $v0, ($v1)
/* 190A04 80262124 03E00008 */  jr        $ra
/* 190A08 80262128 0000102D */   daddu    $v0, $zero, $zero
/* 190A0C 8026212C 00000000 */  nop       
