.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240680_886A40
/* 886A40 80240680 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 886A44 80240684 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 886A48 80240688 8C620000 */  lw        $v0, ($v1)
/* 886A4C 8024068C 34420040 */  ori       $v0, $v0, 0x40
/* 886A50 80240690 AC620000 */  sw        $v0, ($v1)
/* 886A54 80240694 03E00008 */  jr        $ra
/* 886A58 80240698 24020002 */   addiu    $v0, $zero, 2
