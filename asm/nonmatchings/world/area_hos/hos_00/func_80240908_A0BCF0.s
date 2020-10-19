.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240908_A0C5F8
/* A0C5F8 80240908 24020001 */  addiu     $v0, $zero, 1
/* A0C5FC 8024090C 3C018011 */  lui       $at, 0x8011
/* A0C600 80240910 A022F29A */  sb        $v0, -0xd66($at)
/* A0C604 80240914 03E00008 */  jr        $ra
/* A0C608 80240918 24020002 */   addiu    $v0, $zero, 2
