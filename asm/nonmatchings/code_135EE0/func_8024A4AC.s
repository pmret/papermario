.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024A4AC
.L8024A4AC:
/* 13D7EC 8024A4AC 8FBF00A4 */  lw    $ra, 0xa4($sp)
/* 13D7F0 8024A4B0 8FBE00A0 */  lw    $fp, 0xa0($sp)
/* 13D7F4 8024A4B4 8FB7009C */  lw    $s7, 0x9c($sp)
/* 13D7F8 8024A4B8 8FB60098 */  lw    $s6, 0x98($sp)
/* 13D7FC 8024A4BC 8FB50094 */  lw    $s5, 0x94($sp)
/* 13D800 8024A4C0 8FB40090 */  lw    $s4, 0x90($sp)
/* 13D804 8024A4C4 8FB3008C */  lw    $s3, 0x8c($sp)
/* 13D808 8024A4C8 8FB20088 */  lw    $s2, 0x88($sp)
/* 13D80C 8024A4CC 8FB10084 */  lw    $s1, 0x84($sp)
/* 13D810 8024A4D0 8FB00080 */  lw    $s0, 0x80($sp)
/* 13D814 8024A4D4 03E00008 */  jr    $ra
/* 13D818 8024A4D8 27BD00A8 */   addiu $sp, $sp, 0xa8

