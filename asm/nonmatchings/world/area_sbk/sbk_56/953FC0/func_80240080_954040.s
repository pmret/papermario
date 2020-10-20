.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240080_954040
/* 954040 80240080 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 954044 80240084 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 954048 80240088 8C620000 */  lw        $v0, ($v1)
/* 95404C 8024008C 34420040 */  ori       $v0, $v0, 0x40
/* 954050 80240090 AC620000 */  sw        $v0, ($v1)
/* 954054 80240094 03E00008 */  jr        $ra
/* 954058 80240098 24020002 */   addiu    $v0, $zero, 2
