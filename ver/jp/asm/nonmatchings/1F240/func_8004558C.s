.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004558C
/* 2098C 8004558C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 20990 80045590 AFBF0010 */  sw        $ra, 0x10($sp)
/* 20994 80045594 8C820148 */  lw        $v0, 0x148($a0)
/* 20998 80045598 8C420018 */  lw        $v0, 0x18($v0)
/* 2099C 8004559C 8C83000C */  lw        $v1, 0xc($a0)
/* 209A0 800455A0 9446002A */  lhu       $a2, 0x2a($v0)
/* 209A4 800455A4 8C650000 */  lw        $a1, ($v1)
/* 209A8 800455A8 0C0B2026 */  jal       func_802C8098
/* 209AC 800455AC 30C60008 */   andi     $a2, $a2, 8
/* 209B0 800455B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 209B4 800455B4 24020002 */  addiu     $v0, $zero, 2
/* 209B8 800455B8 03E00008 */  jr        $ra
/* 209BC 800455BC 27BD0018 */   addiu    $sp, $sp, 0x18
