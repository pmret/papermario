.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241104_B98D04
/* B98D04 80241104 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B98D08 80241108 AFBF0010 */  sw        $ra, 0x10($sp)
/* B98D0C 8024110C 8C82000C */  lw        $v0, 0xc($a0)
/* B98D10 80241110 0C0B1EAF */  jal       get_variable
/* B98D14 80241114 8C450000 */   lw       $a1, ($v0)
/* B98D18 80241118 3C018024 */  lui       $at, %hi(D_802416B0_B992B0)
/* B98D1C 8024111C AC2216B0 */  sw        $v0, %lo(D_802416B0_B992B0)($at)
/* B98D20 80241120 24020002 */  addiu     $v0, $zero, 2
/* B98D24 80241124 8FBF0010 */  lw        $ra, 0x10($sp)
/* B98D28 80241128 24030001 */  addiu     $v1, $zero, 1
/* B98D2C 8024112C 3C018024 */  lui       $at, %hi(D_802416AC_B992AC)
/* B98D30 80241130 AC2316AC */  sw        $v1, %lo(D_802416AC_B992AC)($at)
/* B98D34 80241134 03E00008 */  jr        $ra
/* B98D38 80241138 27BD0018 */   addiu    $sp, $sp, 0x18
