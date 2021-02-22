.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B93440
/* B93440 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B93444 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* B93448 80240008 0C046ED4 */  jal       enable_world_fog
/* B9344C 8024000C 00000000 */   nop
/* B93450 80240010 240403DE */  addiu     $a0, $zero, 0x3de
/* B93454 80240014 0C046EDD */  jal       set_world_fog_dist
/* B93458 80240018 240503E8 */   addiu    $a1, $zero, 0x3e8
/* B9345C 8024001C 0000202D */  daddu     $a0, $zero, $zero
/* B93460 80240020 0080282D */  daddu     $a1, $a0, $zero
/* B93464 80240024 0080302D */  daddu     $a2, $a0, $zero
/* B93468 80240028 0C046EE2 */  jal       set_world_fog_color
/* B9346C 8024002C 240700FF */   addiu    $a3, $zero, 0xff
/* B93470 80240030 0C048BFB */  jal       enable_entity_fog
/* B93474 80240034 00000000 */   nop
/* B93478 80240038 240403DE */  addiu     $a0, $zero, 0x3de
/* B9347C 8024003C 0C048C04 */  jal       set_entity_fog_dist
/* B93480 80240040 240503E8 */   addiu    $a1, $zero, 0x3e8
/* B93484 80240044 0000202D */  daddu     $a0, $zero, $zero
/* B93488 80240048 0080282D */  daddu     $a1, $a0, $zero
/* B9348C 8024004C 0080302D */  daddu     $a2, $a0, $zero
/* B93490 80240050 0C048C0A */  jal       set_entity_fog_color
/* B93494 80240054 240700FF */   addiu    $a3, $zero, 0xff
/* B93498 80240058 8FBF0010 */  lw        $ra, 0x10($sp)
/* B9349C 8024005C 24020002 */  addiu     $v0, $zero, 2
/* B934A0 80240060 03E00008 */  jr        $ra
/* B934A4 80240064 27BD0018 */   addiu    $sp, $sp, 0x18
/* B934A8 80240068 00000000 */  nop
/* B934AC 8024006C 00000000 */  nop
