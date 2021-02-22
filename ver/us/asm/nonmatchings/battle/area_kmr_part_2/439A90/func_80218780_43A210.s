.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218780_43A210
/* 43A210 80218780 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 43A214 80218784 AFBF0010 */  sw        $ra, 0x10($sp)
/* 43A218 80218788 0C09A75B */  jal       get_actor
/* 43A21C 8021878C 8C840148 */   lw       $a0, 0x148($a0)
/* 43A220 80218790 8C440008 */  lw        $a0, 8($v0)
/* 43A224 80218794 90830006 */  lbu       $v1, 6($a0)
/* 43A228 80218798 24020002 */  addiu     $v0, $zero, 2
/* 43A22C 8021879C 00431806 */  srlv      $v1, $v1, $v0
/* 43A230 802187A0 A0830006 */  sb        $v1, 6($a0)
/* 43A234 802187A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 43A238 802187A8 03E00008 */  jr        $ra
/* 43A23C 802187AC 27BD0018 */   addiu    $sp, $sp, 0x18
