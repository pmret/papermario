.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BAD940
/* BAD940 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BAD944 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* BAD948 80240008 0C046ED4 */  jal       enable_world_fog
/* BAD94C 8024000C 00000000 */   nop      
/* BAD950 80240010 240403DE */  addiu     $a0, $zero, 0x3de
/* BAD954 80240014 0C046EDD */  jal       set_world_fog_dist
/* BAD958 80240018 240503E8 */   addiu    $a1, $zero, 0x3e8
/* BAD95C 8024001C 0000202D */  daddu     $a0, $zero, $zero
/* BAD960 80240020 0080282D */  daddu     $a1, $a0, $zero
/* BAD964 80240024 0080302D */  daddu     $a2, $a0, $zero
/* BAD968 80240028 0C046EE2 */  jal       set_world_fog_color
/* BAD96C 8024002C 240700FF */   addiu    $a3, $zero, 0xff
/* BAD970 80240030 0C048BFB */  jal       enable_entity_fog
/* BAD974 80240034 00000000 */   nop      
/* BAD978 80240038 240403DE */  addiu     $a0, $zero, 0x3de
/* BAD97C 8024003C 0C048C04 */  jal       set_entity_fog_dist
/* BAD980 80240040 240503E8 */   addiu    $a1, $zero, 0x3e8
/* BAD984 80240044 0000202D */  daddu     $a0, $zero, $zero
/* BAD988 80240048 0080282D */  daddu     $a1, $a0, $zero
/* BAD98C 8024004C 0080302D */  daddu     $a2, $a0, $zero
/* BAD990 80240050 0C048C0A */  jal       set_entity_fog_color
/* BAD994 80240054 240700FF */   addiu    $a3, $zero, 0xff
/* BAD998 80240058 8FBF0010 */  lw        $ra, 0x10($sp)
/* BAD99C 8024005C 24020002 */  addiu     $v0, $zero, 2
/* BAD9A0 80240060 03E00008 */  jr        $ra
/* BAD9A4 80240064 27BD0018 */   addiu    $sp, $sp, 0x18
