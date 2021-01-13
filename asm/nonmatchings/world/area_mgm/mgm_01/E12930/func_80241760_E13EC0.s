.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241760_E13EC0
/* E13EC0 80241760 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E13EC4 80241764 AFBF0010 */  sw        $ra, 0x10($sp)
/* E13EC8 80241768 0C03A5B2 */  jal       func_800E96C8
/* E13ECC 8024176C 00000000 */   nop
/* E13ED0 80241770 8FBF0010 */  lw        $ra, 0x10($sp)
/* E13ED4 80241774 24020002 */  addiu     $v0, $zero, 2
/* E13ED8 80241778 03E00008 */  jr        $ra
/* E13EDC 8024177C 27BD0018 */   addiu    $sp, $sp, 0x18
