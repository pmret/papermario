.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800445D4
/* 1F9D4 800445D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1F9D8 800445D8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1F9DC 800445DC 8C82000C */  lw        $v0, 0xc($a0)
/* 1F9E0 800445E0 8C830148 */  lw        $v1, 0x148($a0)
/* 1F9E4 800445E4 8C450000 */  lw        $a1, ($v0)
/* 1F9E8 800445E8 0C0B2026 */  jal       set_variable
/* 1F9EC 800445EC 8C6600C8 */   lw       $a2, 0xc8($v1)
/* 1F9F0 800445F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1F9F4 800445F4 24020002 */  addiu     $v0, $zero, 2
/* 1F9F8 800445F8 03E00008 */  jr        $ra
/* 1F9FC 800445FC 27BD0018 */   addiu    $sp, $sp, 0x18
