.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BAA140
/* BAA140 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BAA144 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* BAA148 80240008 0C046ED4 */  jal       enable_world_fog
/* BAA14C 8024000C 00000000 */   nop      
/* BAA150 80240010 240403DE */  addiu     $a0, $zero, 0x3de
/* BAA154 80240014 0C046EDD */  jal       set_world_fog_dist
/* BAA158 80240018 240503E8 */   addiu    $a1, $zero, 0x3e8
/* BAA15C 8024001C 0000202D */  daddu     $a0, $zero, $zero
/* BAA160 80240020 0080282D */  daddu     $a1, $a0, $zero
/* BAA164 80240024 0080302D */  daddu     $a2, $a0, $zero
/* BAA168 80240028 0C046EE2 */  jal       set_world_fog_color
/* BAA16C 8024002C 240700FF */   addiu    $a3, $zero, 0xff
/* BAA170 80240030 0C048BFB */  jal       enable_entity_fog
/* BAA174 80240034 00000000 */   nop      
/* BAA178 80240038 240403DE */  addiu     $a0, $zero, 0x3de
/* BAA17C 8024003C 0C048C04 */  jal       set_entity_fog_dist
/* BAA180 80240040 240503E8 */   addiu    $a1, $zero, 0x3e8
/* BAA184 80240044 0000202D */  daddu     $a0, $zero, $zero
/* BAA188 80240048 0080282D */  daddu     $a1, $a0, $zero
/* BAA18C 8024004C 0080302D */  daddu     $a2, $a0, $zero
/* BAA190 80240050 0C048C0A */  jal       set_entity_fog_color
/* BAA194 80240054 240700FF */   addiu    $a3, $zero, 0xff
/* BAA198 80240058 8FBF0010 */  lw        $ra, 0x10($sp)
/* BAA19C 8024005C 24020002 */  addiu     $v0, $zero, 2
/* BAA1A0 80240060 03E00008 */  jr        $ra
/* BAA1A4 80240064 27BD0018 */   addiu    $sp, $sp, 0x18
/* BAA1A8 80240068 00000000 */  nop       
/* BAA1AC 8024006C 00000000 */  nop       
