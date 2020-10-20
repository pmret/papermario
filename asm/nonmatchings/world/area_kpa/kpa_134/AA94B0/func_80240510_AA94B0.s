.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240510_AA94B0
/* AA94B0 80240510 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AA94B4 80240514 AFB00010 */  sw        $s0, 0x10($sp)
/* AA94B8 80240518 0080802D */  daddu     $s0, $a0, $zero
/* AA94BC 8024051C AFBF0014 */  sw        $ra, 0x14($sp)
/* AA94C0 80240520 0C04417A */  jal       get_entity_by_index
/* AA94C4 80240524 8E0400AC */   lw       $a0, 0xac($s0)
/* AA94C8 80240528 0040182D */  daddu     $v1, $v0, $zero
/* AA94CC 8024052C C6000084 */  lwc1      $f0, 0x84($s0)
/* AA94D0 80240530 46800020 */  cvt.s.w   $f0, $f0
/* AA94D4 80240534 E4600048 */  swc1      $f0, 0x48($v1)
/* AA94D8 80240538 C6000088 */  lwc1      $f0, 0x88($s0)
/* AA94DC 8024053C 46800020 */  cvt.s.w   $f0, $f0
/* AA94E0 80240540 E460004C */  swc1      $f0, 0x4c($v1)
/* AA94E4 80240544 C600008C */  lwc1      $f0, 0x8c($s0)
/* AA94E8 80240548 46800020 */  cvt.s.w   $f0, $f0
/* AA94EC 8024054C E4600050 */  swc1      $f0, 0x50($v1)
/* AA94F0 80240550 8FBF0014 */  lw        $ra, 0x14($sp)
/* AA94F4 80240554 8FB00010 */  lw        $s0, 0x10($sp)
/* AA94F8 80240558 24020002 */  addiu     $v0, $zero, 2
/* AA94FC 8024055C 03E00008 */  jr        $ra
/* AA9500 80240560 27BD0018 */   addiu    $sp, $sp, 0x18
