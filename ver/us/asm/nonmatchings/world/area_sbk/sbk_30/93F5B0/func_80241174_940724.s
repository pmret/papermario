.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241174_940724
/* 940724 80241174 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 940728 80241178 AFBF0010 */  sw        $ra, 0x10($sp)
/* 94072C 8024117C 8C82000C */  lw        $v0, 0xc($a0)
/* 940730 80241180 0C0B1EAF */  jal       evt_get_variable
/* 940734 80241184 8C450000 */   lw       $a1, ($v0)
/* 940738 80241188 3C018024 */  lui       $at, %hi(D_8024205C_94160C)
/* 94073C 8024118C AC22205C */  sw        $v0, %lo(D_8024205C_94160C)($at)
/* 940740 80241190 24020002 */  addiu     $v0, $zero, 2
/* 940744 80241194 8FBF0010 */  lw        $ra, 0x10($sp)
/* 940748 80241198 24030001 */  addiu     $v1, $zero, 1
/* 94074C 8024119C 3C018024 */  lui       $at, %hi(D_80242058_941608)
/* 940750 802411A0 AC232058 */  sw        $v1, %lo(D_80242058_941608)($at)
/* 940754 802411A4 03E00008 */  jr        $ra
/* 940758 802411A8 27BD0018 */   addiu    $sp, $sp, 0x18
