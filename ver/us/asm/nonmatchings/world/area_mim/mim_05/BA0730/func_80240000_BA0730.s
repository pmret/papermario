.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BA0730
/* BA0730 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BA0734 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* BA0738 80240008 0C046ED4 */  jal       enable_world_fog
/* BA073C 8024000C 00000000 */   nop
/* BA0740 80240010 240403DE */  addiu     $a0, $zero, 0x3de
/* BA0744 80240014 0C046EDD */  jal       set_world_fog_dist
/* BA0748 80240018 240503E8 */   addiu    $a1, $zero, 0x3e8
/* BA074C 8024001C 0000202D */  daddu     $a0, $zero, $zero
/* BA0750 80240020 0080282D */  daddu     $a1, $a0, $zero
/* BA0754 80240024 0080302D */  daddu     $a2, $a0, $zero
/* BA0758 80240028 0C046EE2 */  jal       set_world_fog_color
/* BA075C 8024002C 240700FF */   addiu    $a3, $zero, 0xff
/* BA0760 80240030 0C048BFB */  jal       enable_entity_fog
/* BA0764 80240034 00000000 */   nop
/* BA0768 80240038 240403DE */  addiu     $a0, $zero, 0x3de
/* BA076C 8024003C 0C048C04 */  jal       set_entity_fog_dist
/* BA0770 80240040 240503E8 */   addiu    $a1, $zero, 0x3e8
/* BA0774 80240044 0000202D */  daddu     $a0, $zero, $zero
/* BA0778 80240048 0080282D */  daddu     $a1, $a0, $zero
/* BA077C 8024004C 0080302D */  daddu     $a2, $a0, $zero
/* BA0780 80240050 0C048C0A */  jal       set_entity_fog_color
/* BA0784 80240054 240700FF */   addiu    $a3, $zero, 0xff
/* BA0788 80240058 8FBF0010 */  lw        $ra, 0x10($sp)
/* BA078C 8024005C 24020002 */  addiu     $v0, $zero, 2
/* BA0790 80240060 03E00008 */  jr        $ra
/* BA0794 80240064 27BD0018 */   addiu    $sp, $sp, 0x18
/* BA0798 80240068 00000000 */  nop
/* BA079C 8024006C 00000000 */  nop
