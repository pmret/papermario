.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_4A10A0
/* 4A10A0 80218000 3C028022 */  lui       $v0, %hi(D_8021A4E8_4A3588)
/* 4A10A4 80218004 2442A4E8 */  addiu     $v0, $v0, %lo(D_8021A4E8_4A3588)
/* 4A10A8 80218008 24030001 */  addiu     $v1, $zero, 1
/* 4A10AC 8021800C AC43000C */  sw        $v1, 0xc($v0)
/* 4A10B0 80218010 8C830148 */  lw        $v1, 0x148($a0)
/* 4A10B4 80218014 AC430010 */  sw        $v1, 0x10($v0)
/* 4A10B8 80218018 03E00008 */  jr        $ra
/* 4A10BC 8021801C 24020002 */   addiu    $v0, $zero, 2
