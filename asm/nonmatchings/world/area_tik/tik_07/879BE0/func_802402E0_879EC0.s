.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402E0_879EC0
/* 879EC0 802402E0 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 879EC4 802402E4 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 879EC8 802402E8 8C620000 */  lw        $v0, ($v1)
/* 879ECC 802402EC 34420040 */  ori       $v0, $v0, 0x40
/* 879ED0 802402F0 AC620000 */  sw        $v0, ($v1)
/* 879ED4 802402F4 03E00008 */  jr        $ra
/* 879ED8 802402F8 24020002 */   addiu    $v0, $zero, 2
