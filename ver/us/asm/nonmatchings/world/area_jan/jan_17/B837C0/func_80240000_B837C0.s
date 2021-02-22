.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B837C0
/* B837C0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B837C4 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* B837C8 80240008 0C046ED4 */  jal       enable_world_fog
/* B837CC 8024000C 00000000 */   nop
/* B837D0 80240010 8FBF0010 */  lw        $ra, 0x10($sp)
/* B837D4 80240014 24020002 */  addiu     $v0, $zero, 2
/* B837D8 80240018 03E00008 */  jr        $ra
/* B837DC 8024001C 27BD0018 */   addiu    $sp, $sp, 0x18
