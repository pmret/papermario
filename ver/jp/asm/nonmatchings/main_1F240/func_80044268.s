.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80044268
/* 1F668 80044268 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1F66C 8004426C AFBF0010 */  sw        $ra, 0x10($sp)
/* 1F670 80044270 8C82000C */  lw        $v0, 0xc($a0)
/* 1F674 80044274 8C830148 */  lw        $v1, 0x148($a0)
/* 1F678 80044278 8C450000 */  lw        $a1, ($v0)
/* 1F67C 8004427C 0C0B2026 */  jal       func_802C8098
/* 1F680 80044280 8C6600C4 */   lw       $a2, 0xc4($v1)
/* 1F684 80044284 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1F688 80044288 24020002 */  addiu     $v0, $zero, 2
/* 1F68C 8004428C 03E00008 */  jr        $ra
/* 1F690 80044290 27BD0018 */   addiu    $sp, $sp, 0x18
