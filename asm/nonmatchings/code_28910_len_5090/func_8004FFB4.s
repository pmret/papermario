.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FFB4
/* 2B3B4 8004FFB4 948300D4 */  lhu       $v1, 0xd4($a0)
/* 2B3B8 8004FFB8 24020001 */  addiu     $v0, $zero, 1
/* 2B3BC 8004FFBC A0A20040 */  sb        $v0, 0x40($a1)
/* 2B3C0 8004FFC0 03E00008 */  jr        $ra
/* 2B3C4 8004FFC4 A4A30038 */   sh       $v1, 0x38($a1)
