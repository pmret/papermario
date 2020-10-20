.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0
/* 91E860 802402F0 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 91E864 802402F4 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 91E868 802402F8 8C620000 */  lw        $v0, ($v1)
/* 91E86C 802402FC 34420040 */  ori       $v0, $v0, 0x40
/* 91E870 80240300 AC620000 */  sw        $v0, ($v1)
/* 91E874 80240304 03E00008 */  jr        $ra
/* 91E878 80240308 24020002 */   addiu    $v0, $zero, 2
