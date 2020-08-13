.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024A1E8
/* 13D528 8024A1E8 25670007 */   addiu $a3, $t3, 7
/* 13D52C 8024A1EC 24020080 */  addiu $v0, $zero, 0x80
/* 13D530 8024A1F0 0809287F */  j     func_8024A1FC
/* 13D534 8024A1F4 AFA20020 */   sw    $v0, 0x20($sp)

.L8024A1F8:
/* 13D538 8024A1F8 AFA00020 */  sw    $zero, 0x20($sp)
