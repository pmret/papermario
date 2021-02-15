.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A30_43A4C0
/* 43A4C0 80218A30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 43A4C4 80218A34 AFBF0010 */  sw        $ra, 0x10($sp)
/* 43A4C8 80218A38 0C09A75B */  jal       get_actor
/* 43A4CC 80218A3C 8C840148 */   lw       $a0, 0x148($a0)
/* 43A4D0 80218A40 8C440008 */  lw        $a0, 8($v0)
/* 43A4D4 80218A44 90830006 */  lbu       $v1, 6($a0)
/* 43A4D8 80218A48 24020002 */  addiu     $v0, $zero, 2
/* 43A4DC 80218A4C 00431806 */  srlv      $v1, $v1, $v0
/* 43A4E0 80218A50 A0830006 */  sb        $v1, 6($a0)
/* 43A4E4 80218A54 8FBF0010 */  lw        $ra, 0x10($sp)
/* 43A4E8 80218A58 03E00008 */  jr        $ra
/* 43A4EC 80218A5C 27BD0018 */   addiu    $sp, $sp, 0x18
