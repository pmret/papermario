.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BB2E00
/* BB2E00 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BB2E04 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* BB2E08 80240008 0C046ED4 */  jal       enable_world_fog
/* BB2E0C 8024000C 00000000 */   nop
/* BB2E10 80240010 240403DE */  addiu     $a0, $zero, 0x3de
/* BB2E14 80240014 0C046EDD */  jal       set_world_fog_dist
/* BB2E18 80240018 240503E8 */   addiu    $a1, $zero, 0x3e8
/* BB2E1C 8024001C 0000202D */  daddu     $a0, $zero, $zero
/* BB2E20 80240020 0080282D */  daddu     $a1, $a0, $zero
/* BB2E24 80240024 0080302D */  daddu     $a2, $a0, $zero
/* BB2E28 80240028 0C046EE2 */  jal       set_world_fog_color
/* BB2E2C 8024002C 240700FF */   addiu    $a3, $zero, 0xff
/* BB2E30 80240030 0C048BFB */  jal       enable_entity_fog
/* BB2E34 80240034 00000000 */   nop
/* BB2E38 80240038 240403DE */  addiu     $a0, $zero, 0x3de
/* BB2E3C 8024003C 0C048C04 */  jal       set_entity_fog_dist
/* BB2E40 80240040 240503E8 */   addiu    $a1, $zero, 0x3e8
/* BB2E44 80240044 0000202D */  daddu     $a0, $zero, $zero
/* BB2E48 80240048 0080282D */  daddu     $a1, $a0, $zero
/* BB2E4C 8024004C 0080302D */  daddu     $a2, $a0, $zero
/* BB2E50 80240050 0C048C0A */  jal       set_entity_fog_color
/* BB2E54 80240054 240700FF */   addiu    $a3, $zero, 0xff
/* BB2E58 80240058 8FBF0010 */  lw        $ra, 0x10($sp)
/* BB2E5C 8024005C 24020002 */  addiu     $v0, $zero, 2
/* BB2E60 80240060 03E00008 */  jr        $ra
/* BB2E64 80240064 27BD0018 */   addiu    $sp, $sp, 0x18
