.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EC0_8DAFC0
/* 8DAFC0 80240EC0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8DAFC4 80240EC4 AFB00010 */  sw        $s0, 0x10($sp)
/* 8DAFC8 80240EC8 0080802D */  daddu     $s0, $a0, $zero
/* 8DAFCC 80240ECC AFBF0014 */  sw        $ra, 0x14($sp)
/* 8DAFD0 80240ED0 0C04417A */  jal       get_entity_by_index
/* 8DAFD4 80240ED4 8E0400AC */   lw       $a0, 0xac($s0)
/* 8DAFD8 80240ED8 0040182D */  daddu     $v1, $v0, $zero
/* 8DAFDC 80240EDC C6000084 */  lwc1      $f0, 0x84($s0)
/* 8DAFE0 80240EE0 46800020 */  cvt.s.w   $f0, $f0
/* 8DAFE4 80240EE4 E4600048 */  swc1      $f0, 0x48($v1)
/* 8DAFE8 80240EE8 C6000088 */  lwc1      $f0, 0x88($s0)
/* 8DAFEC 80240EEC 46800020 */  cvt.s.w   $f0, $f0
/* 8DAFF0 80240EF0 E460004C */  swc1      $f0, 0x4c($v1)
/* 8DAFF4 80240EF4 C600008C */  lwc1      $f0, 0x8c($s0)
/* 8DAFF8 80240EF8 46800020 */  cvt.s.w   $f0, $f0
/* 8DAFFC 80240EFC E4600050 */  swc1      $f0, 0x50($v1)
/* 8DB000 80240F00 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8DB004 80240F04 8FB00010 */  lw        $s0, 0x10($sp)
/* 8DB008 80240F08 24020002 */  addiu     $v0, $zero, 2
/* 8DB00C 80240F0C 03E00008 */  jr        $ra
/* 8DB010 80240F10 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8DB014 80240F14 00000000 */  nop       
/* 8DB018 80240F18 00000000 */  nop       
/* 8DB01C 80240F1C 00000000 */  nop       
