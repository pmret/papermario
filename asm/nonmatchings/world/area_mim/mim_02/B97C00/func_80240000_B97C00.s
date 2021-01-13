.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B97C00
/* B97C00 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B97C04 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* B97C08 80240008 0C046ED4 */  jal       enable_world_fog
/* B97C0C 8024000C 00000000 */   nop
/* B97C10 80240010 240403DE */  addiu     $a0, $zero, 0x3de
/* B97C14 80240014 0C046EDD */  jal       set_world_fog_dist
/* B97C18 80240018 240503E8 */   addiu    $a1, $zero, 0x3e8
/* B97C1C 8024001C 0000202D */  daddu     $a0, $zero, $zero
/* B97C20 80240020 0080282D */  daddu     $a1, $a0, $zero
/* B97C24 80240024 0080302D */  daddu     $a2, $a0, $zero
/* B97C28 80240028 0C046EE2 */  jal       set_world_fog_color
/* B97C2C 8024002C 240700FF */   addiu    $a3, $zero, 0xff
/* B97C30 80240030 0C048BFB */  jal       enable_entity_fog
/* B97C34 80240034 00000000 */   nop
/* B97C38 80240038 240403DE */  addiu     $a0, $zero, 0x3de
/* B97C3C 8024003C 0C048C04 */  jal       set_entity_fog_dist
/* B97C40 80240040 240503E8 */   addiu    $a1, $zero, 0x3e8
/* B97C44 80240044 0000202D */  daddu     $a0, $zero, $zero
/* B97C48 80240048 0080282D */  daddu     $a1, $a0, $zero
/* B97C4C 8024004C 0080302D */  daddu     $a2, $a0, $zero
/* B97C50 80240050 0C048C0A */  jal       set_entity_fog_color
/* B97C54 80240054 240700FF */   addiu    $a3, $zero, 0xff
/* B97C58 80240058 8FBF0010 */  lw        $ra, 0x10($sp)
/* B97C5C 8024005C 24020002 */  addiu     $v0, $zero, 2
/* B97C60 80240060 03E00008 */  jr        $ra
/* B97C64 80240064 27BD0018 */   addiu    $sp, $sp, 0x18
/* B97C68 80240068 00000000 */  nop
/* B97C6C 8024006C 00000000 */  nop
