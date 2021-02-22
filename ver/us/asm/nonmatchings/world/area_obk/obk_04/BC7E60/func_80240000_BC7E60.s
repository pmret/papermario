.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BC7E60
/* BC7E60 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BC7E64 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* BC7E68 80240008 0080802D */  daddu     $s0, $a0, $zero
/* BC7E6C 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* BC7E70 80240010 0C04C3D6 */  jal       get_item_entity
/* BC7E74 80240014 8E040084 */   lw       $a0, 0x84($s0)
/* BC7E78 80240018 8E040084 */  lw        $a0, 0x84($s0)
/* BC7E7C 8024001C 0040802D */  daddu     $s0, $v0, $zero
/* BC7E80 80240020 0C04D052 */  jal       set_item_entity_flags
/* BC7E84 80240024 3C050008 */   lui      $a1, 8
/* BC7E88 80240028 240300FF */  addiu     $v1, $zero, 0xff
/* BC7E8C 8024002C A203002F */  sb        $v1, 0x2f($s0)
/* BC7E90 80240030 8FBF0014 */  lw        $ra, 0x14($sp)
/* BC7E94 80240034 8FB00010 */  lw        $s0, 0x10($sp)
/* BC7E98 80240038 24020002 */  addiu     $v0, $zero, 2
/* BC7E9C 8024003C 03E00008 */  jr        $ra
/* BC7EA0 80240040 27BD0018 */   addiu    $sp, $sp, 0x18
/* BC7EA4 80240044 00000000 */  nop
/* BC7EA8 80240048 00000000 */  nop
/* BC7EAC 8024004C 00000000 */  nop
