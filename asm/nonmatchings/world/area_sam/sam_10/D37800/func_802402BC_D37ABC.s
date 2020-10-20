.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402BC_D37ABC
/* D37ABC 802402BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D37AC0 802402C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* D37AC4 802402C4 0C04C3D6 */  jal       get_item_entity
/* D37AC8 802402C8 8C840084 */   lw       $a0, 0x84($a0)
/* D37ACC 802402CC 3C013F4C */  lui       $at, 0x3f4c
/* D37AD0 802402D0 3421CCCD */  ori       $at, $at, 0xcccd
/* D37AD4 802402D4 44810000 */  mtc1      $at, $f0
/* D37AD8 802402D8 00000000 */  nop       
/* D37ADC 802402DC E4400030 */  swc1      $f0, 0x30($v0)
/* D37AE0 802402E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D37AE4 802402E4 24020002 */  addiu     $v0, $zero, 2
/* D37AE8 802402E8 03E00008 */  jr        $ra
/* D37AEC 802402EC 27BD0018 */   addiu    $sp, $sp, 0x18
