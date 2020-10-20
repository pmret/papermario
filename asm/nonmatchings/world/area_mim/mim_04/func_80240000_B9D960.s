.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B9D960
/* B9D960 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B9D964 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* B9D968 80240008 0C046ED4 */  jal       enable_world_fog
/* B9D96C 8024000C 00000000 */   nop      
/* B9D970 80240010 240403DE */  addiu     $a0, $zero, 0x3de
/* B9D974 80240014 0C046EDD */  jal       set_world_fog_dist
/* B9D978 80240018 240503E8 */   addiu    $a1, $zero, 0x3e8
/* B9D97C 8024001C 0000202D */  daddu     $a0, $zero, $zero
/* B9D980 80240020 0080282D */  daddu     $a1, $a0, $zero
/* B9D984 80240024 0080302D */  daddu     $a2, $a0, $zero
/* B9D988 80240028 0C046EE2 */  jal       set_world_fog_color
/* B9D98C 8024002C 240700FF */   addiu    $a3, $zero, 0xff
/* B9D990 80240030 0C048BFB */  jal       enable_entity_fog
/* B9D994 80240034 00000000 */   nop      
/* B9D998 80240038 240403DE */  addiu     $a0, $zero, 0x3de
/* B9D99C 8024003C 0C048C04 */  jal       set_entity_fog_dist
/* B9D9A0 80240040 240503E8 */   addiu    $a1, $zero, 0x3e8
/* B9D9A4 80240044 0000202D */  daddu     $a0, $zero, $zero
/* B9D9A8 80240048 0080282D */  daddu     $a1, $a0, $zero
/* B9D9AC 8024004C 0080302D */  daddu     $a2, $a0, $zero
/* B9D9B0 80240050 0C048C0A */  jal       set_entity_fog_color
/* B9D9B4 80240054 240700FF */   addiu    $a3, $zero, 0xff
/* B9D9B8 80240058 8FBF0010 */  lw        $ra, 0x10($sp)
/* B9D9BC 8024005C 24020002 */  addiu     $v0, $zero, 2
/* B9D9C0 80240060 03E00008 */  jr        $ra
/* B9D9C4 80240064 27BD0018 */   addiu    $sp, $sp, 0x18
/* B9D9C8 80240068 00000000 */  nop       
/* B9D9CC 8024006C 00000000 */  nop       
