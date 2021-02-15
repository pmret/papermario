.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BA4_B5EE54
/* B5EE54 80240BA4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B5EE58 80240BA8 AFBF0018 */  sw        $ra, 0x18($sp)
/* B5EE5C 80240BAC 8C82000C */  lw        $v0, 0xc($a0)
/* B5EE60 80240BB0 0C0B1EAF */  jal       get_variable
/* B5EE64 80240BB4 8C450000 */   lw       $a1, ($v0)
/* B5EE68 80240BB8 0C04417A */  jal       get_entity_by_index
/* B5EE6C 80240BBC 0040202D */   daddu    $a0, $v0, $zero
/* B5EE70 80240BC0 3C013F80 */  lui       $at, 0x3f80
/* B5EE74 80240BC4 44810000 */  mtc1      $at, $f0
/* B5EE78 80240BC8 C442004C */  lwc1      $f2, 0x4c($v0)
/* B5EE7C 80240BCC E7A00010 */  swc1      $f0, 0x10($sp)
/* B5EE80 80240BD0 3C014148 */  lui       $at, 0x4148
/* B5EE84 80240BD4 44810000 */  mtc1      $at, $f0
/* B5EE88 80240BD8 2403004B */  addiu     $v1, $zero, 0x4b
/* B5EE8C 80240BDC AFA30014 */  sw        $v1, 0x14($sp)
/* B5EE90 80240BE0 46001080 */  add.s     $f2, $f2, $f0
/* B5EE94 80240BE4 8C450048 */  lw        $a1, 0x48($v0)
/* B5EE98 80240BE8 8C470050 */  lw        $a3, 0x50($v0)
/* B5EE9C 80240BEC 44061000 */  mfc1      $a2, $f2
/* B5EEA0 80240BF0 0C01C2EC */  jal       func_80070BB0
/* B5EEA4 80240BF4 24040004 */   addiu    $a0, $zero, 4
/* B5EEA8 80240BF8 8FBF0018 */  lw        $ra, 0x18($sp)
/* B5EEAC 80240BFC 24020002 */  addiu     $v0, $zero, 2
/* B5EEB0 80240C00 03E00008 */  jr        $ra
/* B5EEB4 80240C04 27BD0020 */   addiu    $sp, $sp, 0x20
