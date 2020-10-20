.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403F0_BDABA0
/* BDABA0 802403F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BDABA4 802403F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* BDABA8 802403F8 0C04C3D6 */  jal       get_item_entity
/* BDABAC 802403FC 8C840084 */   lw       $a0, 0x84($a0)
/* BDABB0 80240400 3C013F19 */  lui       $at, 0x3f19
/* BDABB4 80240404 3421999A */  ori       $at, $at, 0x999a
/* BDABB8 80240408 44810000 */  mtc1      $at, $f0
/* BDABBC 8024040C 00000000 */  nop       
/* BDABC0 80240410 E4400030 */  swc1      $f0, 0x30($v0)
/* BDABC4 80240414 8FBF0010 */  lw        $ra, 0x10($sp)
/* BDABC8 80240418 24020002 */  addiu     $v0, $zero, 2
/* BDABCC 8024041C 03E00008 */  jr        $ra
/* BDABD0 80240420 27BD0018 */   addiu    $sp, $sp, 0x18
/* BDABD4 80240424 00000000 */  nop       
/* BDABD8 80240428 00000000 */  nop       
/* BDABDC 8024042C 00000000 */  nop       
