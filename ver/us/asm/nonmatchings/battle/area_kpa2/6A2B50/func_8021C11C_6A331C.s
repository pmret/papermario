.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021C11C_6A331C
/* 6A331C 8021C11C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A3320 8021C120 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6A3324 8021C124 0C09A75B */  jal       get_actor
/* 6A3328 8021C128 8C840148 */   lw       $a0, 0x148($a0)
/* 6A332C 8021C12C 84440436 */  lh        $a0, 0x436($v0)
/* 6A3330 8021C130 A0400224 */  sb        $zero, 0x224($v0)
/* 6A3334 8021C134 0C011EE1 */  jal       remove_status_4
/* 6A3338 8021C138 A0400223 */   sb       $zero, 0x223($v0)
/* 6A333C 8021C13C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6A3340 8021C140 24020002 */  addiu     $v0, $zero, 2
/* 6A3344 8021C144 03E00008 */  jr        $ra
/* 6A3348 8021C148 27BD0018 */   addiu    $sp, $sp, 0x18
