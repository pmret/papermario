.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FC64
/* 2B064 8004FC64 948300D4 */  lhu       $v1, 0xd4($a0)
/* 2B068 8004FC68 24020001 */  addiu     $v0, $zero, 1
/* 2B06C 8004FC6C A0A20040 */  sb        $v0, 0x40($a1)
/* 2B070 8004FC70 03E00008 */  jr        $ra
/* 2B074 8004FC74 A4A30038 */   sh       $v1, 0x38($a1)
