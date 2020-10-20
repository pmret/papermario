.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405F0_897BD0
/* 897BD0 802405F0 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 897BD4 802405F4 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 897BD8 802405F8 8C620000 */  lw        $v0, ($v1)
/* 897BDC 802405FC 34420040 */  ori       $v0, $v0, 0x40
/* 897BE0 80240600 AC620000 */  sw        $v0, ($v1)
/* 897BE4 80240604 03E00008 */  jr        $ra
/* 897BE8 80240608 24020002 */   addiu    $v0, $zero, 2
