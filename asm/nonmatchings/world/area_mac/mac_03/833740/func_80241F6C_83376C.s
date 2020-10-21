.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F6C_83376C
/* 83376C 80241F6C 3C028011 */  lui       $v0, 0x8011
/* 833770 80241F70 8442F29C */  lh        $v0, -0xd64($v0)
/* 833774 80241F74 AC820084 */  sw        $v0, 0x84($a0)
/* 833778 80241F78 03E00008 */  jr        $ra
/* 83377C 80241F7C 24020002 */   addiu    $v0, $zero, 2
