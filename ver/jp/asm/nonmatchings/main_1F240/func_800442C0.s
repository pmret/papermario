.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800442C0
/* 1F6C0 800442C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1F6C4 800442C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1F6C8 800442C8 8C82000C */  lw        $v0, 0xc($a0)
/* 1F6CC 800442CC 8C830148 */  lw        $v1, 0x148($a0)
/* 1F6D0 800442D0 8C450000 */  lw        $a1, ($v0)
/* 1F6D4 800442D4 0C0B2026 */  jal       func_802C8098
/* 1F6D8 800442D8 80660005 */   lb       $a2, 5($v1)
/* 1F6DC 800442DC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1F6E0 800442E0 24020002 */  addiu     $v0, $zero, 2
/* 1F6E4 800442E4 03E00008 */  jr        $ra
/* 1F6E8 800442E8 27BD0018 */   addiu    $sp, $sp, 0x18
