.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800458CC
/* 20CCC 800458CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 20CD0 800458D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 20CD4 800458D4 8C820148 */  lw        $v0, 0x148($a0)
/* 20CD8 800458D8 8C420018 */  lw        $v0, 0x18($v0)
/* 20CDC 800458DC 8C83000C */  lw        $v1, 0xc($a0)
/* 20CE0 800458E0 9446002A */  lhu       $a2, 0x2a($v0)
/* 20CE4 800458E4 8C650000 */  lw        $a1, ($v1)
/* 20CE8 800458E8 0C0B2026 */  jal       set_variable
/* 20CEC 800458EC 30C60008 */   andi     $a2, $a2, 8
/* 20CF0 800458F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 20CF4 800458F4 24020002 */  addiu     $v0, $zero, 2
/* 20CF8 800458F8 03E00008 */  jr        $ra
/* 20CFC 800458FC 27BD0018 */   addiu    $sp, $sp, 0x18
