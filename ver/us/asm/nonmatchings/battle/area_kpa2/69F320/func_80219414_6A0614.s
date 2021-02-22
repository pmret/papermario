.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219414_6A0614
/* 6A0614 80219414 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A0618 80219418 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6A061C 8021941C 0C09A75B */  jal       get_actor
/* 6A0620 80219420 8C840148 */   lw       $a0, 0x148($a0)
/* 6A0624 80219424 84440436 */  lh        $a0, 0x436($v0)
/* 6A0628 80219428 A0400224 */  sb        $zero, 0x224($v0)
/* 6A062C 8021942C 0C011EE1 */  jal       func_80047B84
/* 6A0630 80219430 A0400223 */   sb       $zero, 0x223($v0)
/* 6A0634 80219434 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6A0638 80219438 24020002 */  addiu     $v0, $zero, 2
/* 6A063C 8021943C 03E00008 */  jr        $ra
/* 6A0640 80219440 27BD0018 */   addiu    $sp, $sp, 0x18
