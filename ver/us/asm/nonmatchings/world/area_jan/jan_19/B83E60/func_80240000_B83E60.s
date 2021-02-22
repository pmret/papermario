.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B83E60
/* B83E60 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B83E64 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* B83E68 80240008 0C046ED4 */  jal       enable_world_fog
/* B83E6C 8024000C 00000000 */   nop
/* B83E70 80240010 8FBF0010 */  lw        $ra, 0x10($sp)
/* B83E74 80240014 24020002 */  addiu     $v0, $zero, 2
/* B83E78 80240018 03E00008 */  jr        $ra
/* B83E7C 8024001C 27BD0018 */   addiu    $sp, $sp, 0x18
