.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800445A8
/* 1F9A8 800445A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1F9AC 800445AC AFBF0010 */  sw        $ra, 0x10($sp)
/* 1F9B0 800445B0 8C82000C */  lw        $v0, 0xc($a0)
/* 1F9B4 800445B4 8C830148 */  lw        $v1, 0x148($a0)
/* 1F9B8 800445B8 8C450000 */  lw        $a1, ($v0)
/* 1F9BC 800445BC 0C0B2026 */  jal       set_variable
/* 1F9C0 800445C0 8C6600C4 */   lw       $a2, 0xc4($v1)
/* 1F9C4 800445C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1F9C8 800445C8 24020002 */  addiu     $v0, $zero, 2
/* 1F9CC 800445CC 03E00008 */  jr        $ra
/* 1F9D0 800445D0 27BD0018 */   addiu    $sp, $sp, 0x18
