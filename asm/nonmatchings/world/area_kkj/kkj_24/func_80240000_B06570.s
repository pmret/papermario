.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B06570
/* B06570 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B06574 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* B06578 80240008 0C046ED4 */  jal       enable_world_fog
/* B0657C 8024000C 00000000 */   nop      
/* B06580 80240010 8FBF0010 */  lw        $ra, 0x10($sp)
/* B06584 80240014 24020002 */  addiu     $v0, $zero, 2
/* B06588 80240018 03E00008 */  jr        $ra
/* B0658C 8024001C 27BD0018 */   addiu    $sp, $sp, 0x18
