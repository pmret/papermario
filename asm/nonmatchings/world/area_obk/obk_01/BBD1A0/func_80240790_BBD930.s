.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240790_BBD930
/* BBD930 80240790 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BBD934 80240794 AFB00010 */  sw        $s0, 0x10($sp)
/* BBD938 80240798 0080802D */  daddu     $s0, $a0, $zero
/* BBD93C 8024079C AFBF0014 */  sw        $ra, 0x14($sp)
/* BBD940 802407A0 0C04C3D6 */  jal       get_item_entity
/* BBD944 802407A4 8E040084 */   lw       $a0, 0x84($s0)
/* BBD948 802407A8 8E040084 */  lw        $a0, 0x84($s0)
/* BBD94C 802407AC 0040802D */  daddu     $s0, $v0, $zero
/* BBD950 802407B0 0C04D052 */  jal       set_item_entity_flags
/* BBD954 802407B4 3C050008 */   lui      $a1, 8
/* BBD958 802407B8 240300FF */  addiu     $v1, $zero, 0xff
/* BBD95C 802407BC A203002F */  sb        $v1, 0x2f($s0)
/* BBD960 802407C0 8FBF0014 */  lw        $ra, 0x14($sp)
/* BBD964 802407C4 8FB00010 */  lw        $s0, 0x10($sp)
/* BBD968 802407C8 24020002 */  addiu     $v0, $zero, 2
/* BBD96C 802407CC 03E00008 */  jr        $ra
/* BBD970 802407D0 27BD0018 */   addiu    $sp, $sp, 0x18
/* BBD974 802407D4 00000000 */  nop
/* BBD978 802407D8 00000000 */  nop
/* BBD97C 802407DC 00000000 */  nop
