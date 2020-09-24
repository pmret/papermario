.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetBattleInputButtons
/* 19C948 8026E068 8C82000C */  lw        $v0, 0xc($a0)
/* 19C94C 8026E06C 8C450000 */  lw        $a1, ($v0)
/* 19C950 8026E070 24420004 */  addiu     $v0, $v0, 4
/* 19C954 8026E074 8C430000 */  lw        $v1, ($v0)
/* 19C958 8026E078 8C440004 */  lw        $a0, 4($v0)
/* 19C95C 8026E07C 3C02800E */  lui       $v0, 0x800e
/* 19C960 8026E080 2442C070 */  addiu     $v0, $v0, -0x3f90
/* 19C964 8026E084 AC450210 */  sw        $a1, 0x210($v0)
/* 19C968 8026E088 AC430214 */  sw        $v1, 0x214($v0)
/* 19C96C 8026E08C AC440218 */  sw        $a0, 0x218($v0)
/* 19C970 8026E090 03E00008 */  jr        $ra
/* 19C974 8026E094 24020002 */   addiu    $v0, $zero, 2
