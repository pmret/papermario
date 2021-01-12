.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BF6060
/* BF6060 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BF6064 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* BF6068 80240008 0C04417A */  jal       get_entity_by_index
/* BF606C 8024000C 0000202D */   daddu    $a0, $zero, $zero
/* BF6070 80240010 50400007 */  beql      $v0, $zero, .L80240030
/* BF6074 80240014 0000102D */   daddu    $v0, $zero, $zero
/* BF6078 80240018 84440014 */  lh        $a0, 0x14($v0)
/* BF607C 8024001C 3C050000 */  lui       $a1, 0
/* BF6080 80240020 24A501E4 */  addiu     $a1, $a1, 0x1e4
/* BF6084 80240024 0C048052 */  jal       play_model_animation
/* BF6088 80240028 00000000 */   nop
/* BF608C 8024002C 24020002 */  addiu     $v0, $zero, 2
.L80240030:
/* BF6090 80240030 8FBF0010 */  lw        $ra, 0x10($sp)
/* BF6094 80240034 03E00008 */  jr        $ra
/* BF6098 80240038 27BD0018 */   addiu    $sp, $sp, 0x18
/* BF609C 8024003C 00000000 */  nop
