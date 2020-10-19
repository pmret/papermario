.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240070_BAA1B0
/* BAA1B0 80240070 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BAA1B4 80240074 AFBF0010 */  sw        $ra, 0x10($sp)
/* BAA1B8 80240078 0C046ED4 */  jal       enable_world_fog
/* BAA1BC 8024007C 00000000 */   nop      
/* BAA1C0 80240080 240403DE */  addiu     $a0, $zero, 0x3de
/* BAA1C4 80240084 0C046EDD */  jal       set_world_fog_dist
/* BAA1C8 80240088 240503E8 */   addiu    $a1, $zero, 0x3e8
/* BAA1CC 8024008C 0000202D */  daddu     $a0, $zero, $zero
/* BAA1D0 80240090 0080282D */  daddu     $a1, $a0, $zero
/* BAA1D4 80240094 0080302D */  daddu     $a2, $a0, $zero
/* BAA1D8 80240098 0C046EE2 */  jal       set_world_fog_color
/* BAA1DC 8024009C 240700FF */   addiu    $a3, $zero, 0xff
/* BAA1E0 802400A0 0C048BFB */  jal       enable_entity_fog
/* BAA1E4 802400A4 00000000 */   nop      
/* BAA1E8 802400A8 240403DE */  addiu     $a0, $zero, 0x3de
/* BAA1EC 802400AC 0C048C04 */  jal       set_entity_fog_dist
/* BAA1F0 802400B0 240503E8 */   addiu    $a1, $zero, 0x3e8
/* BAA1F4 802400B4 0000202D */  daddu     $a0, $zero, $zero
/* BAA1F8 802400B8 0080282D */  daddu     $a1, $a0, $zero
/* BAA1FC 802400BC 0080302D */  daddu     $a2, $a0, $zero
/* BAA200 802400C0 0C048C0A */  jal       set_entity_fog_color
/* BAA204 802400C4 240700FF */   addiu    $a3, $zero, 0xff
/* BAA208 802400C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* BAA20C 802400CC 24020002 */  addiu     $v0, $zero, 2
/* BAA210 802400D0 03E00008 */  jr        $ra
/* BAA214 802400D4 27BD0018 */   addiu    $sp, $sp, 0x18
