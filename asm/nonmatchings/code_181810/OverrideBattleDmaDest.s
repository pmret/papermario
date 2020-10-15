.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel OverrideBattleDmaDest
/* 181ED8 802535F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 181EDC 802535FC AFBF0010 */  sw        $ra, 0x10($sp)
/* 181EE0 80253600 8C82000C */  lw        $v0, 0xc($a0)
/* 181EE4 80253604 0C0B1EAF */  jal       get_variable
/* 181EE8 80253608 8C450000 */   lw       $a1, ($v0)
/* 181EEC 8025360C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 181EF0 80253610 3C018028 */  lui       $at, 0x8028
/* 181EF4 80253614 AC224000 */  sw        $v0, 0x4000($at)
/* 181EF8 80253618 24020002 */  addiu     $v0, $zero, 2
/* 181EFC 8025361C 03E00008 */  jr        $ra
/* 181F00 80253620 27BD0018 */   addiu    $sp, $sp, 0x18
