.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_6CC070
/* 6CC070 80218000 3C028022 */  lui       $v0, %hi(func_80218DF4_465284)
/* 6CC074 80218004 24428DF4 */  addiu     $v0, $v0, %lo(func_80218DF4_465284)
/* 6CC078 80218008 24030001 */  addiu     $v1, $zero, 1
/* 6CC07C 8021800C AC43000C */  sw        $v1, 0xc($v0)
/* 6CC080 80218010 8C830148 */  lw        $v1, 0x148($a0)
/* 6CC084 80218014 AC430010 */  sw        $v1, 0x10($v0)
/* 6CC088 80218018 03E00008 */  jr        $ra
/* 6CC08C 8021801C 24020002 */   addiu    $v0, $zero, 2
