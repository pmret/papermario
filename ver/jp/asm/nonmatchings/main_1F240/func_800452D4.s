.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800452D4
/* 206D4 800452D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 206D8 800452D8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 206DC 800452DC 8C82000C */  lw        $v0, 0xc($a0)
/* 206E0 800452E0 8C830148 */  lw        $v1, 0x148($a0)
/* 206E4 800452E4 8C450000 */  lw        $a1, ($v0)
/* 206E8 800452E8 0C0B2026 */  jal       func_802C8098
/* 206EC 800452EC 84660008 */   lh       $a2, 8($v1)
/* 206F0 800452F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 206F4 800452F4 24020002 */  addiu     $v0, $zero, 2
/* 206F8 800452F8 03E00008 */  jr        $ra
/* 206FC 800452FC 27BD0018 */   addiu    $sp, $sp, 0x18
