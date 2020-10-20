.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240030_892A50
/* 892A50 80240030 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 892A54 80240034 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 892A58 80240038 8C620000 */  lw        $v0, ($v1)
/* 892A5C 8024003C 34420040 */  ori       $v0, $v0, 0x40
/* 892A60 80240040 AC620000 */  sw        $v0, ($v1)
/* 892A64 80240044 03E00008 */  jr        $ra
/* 892A68 80240048 24020002 */   addiu    $v0, $zero, 2
