.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B68_CEEDC8
/* CEEDC8 80240B68 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CEEDCC 80240B6C AFB10014 */  sw        $s1, 0x14($sp)
/* CEEDD0 80240B70 0080882D */  daddu     $s1, $a0, $zero
/* CEEDD4 80240B74 AFBF0020 */  sw        $ra, 0x20($sp)
/* CEEDD8 80240B78 AFB3001C */  sw        $s3, 0x1c($sp)
/* CEEDDC 80240B7C AFB20018 */  sw        $s2, 0x18($sp)
/* CEEDE0 80240B80 AFB00010 */  sw        $s0, 0x10($sp)
/* CEEDE4 80240B84 8E30000C */  lw        $s0, 0xc($s1)
/* CEEDE8 80240B88 8E050000 */  lw        $a1, ($s0)
/* CEEDEC 80240B8C 0C0B1EAF */  jal       get_variable
/* CEEDF0 80240B90 26100004 */   addiu    $s0, $s0, 4
/* CEEDF4 80240B94 8E050000 */  lw        $a1, ($s0)
/* CEEDF8 80240B98 26100004 */  addiu     $s0, $s0, 4
/* CEEDFC 80240B9C 0220202D */  daddu     $a0, $s1, $zero
/* CEEE00 80240BA0 0C0B1EAF */  jal       get_variable
/* CEEE04 80240BA4 0040982D */   daddu    $s3, $v0, $zero
/* CEEE08 80240BA8 8E050000 */  lw        $a1, ($s0)
/* CEEE0C 80240BAC 26100004 */  addiu     $s0, $s0, 4
/* CEEE10 80240BB0 0220202D */  daddu     $a0, $s1, $zero
/* CEEE14 80240BB4 0C0B1EAF */  jal       get_variable
/* CEEE18 80240BB8 0040902D */   daddu    $s2, $v0, $zero
/* CEEE1C 80240BBC 0220202D */  daddu     $a0, $s1, $zero
/* CEEE20 80240BC0 8E050000 */  lw        $a1, ($s0)
/* CEEE24 80240BC4 0C0B1EAF */  jal       get_variable
/* CEEE28 80240BC8 0040882D */   daddu    $s1, $v0, $zero
/* CEEE2C 80240BCC 0260202D */  daddu     $a0, $s3, $zero
/* CEEE30 80240BD0 0C04C3D6 */  jal       get_item_entity
/* CEEE34 80240BD4 0040802D */   daddu    $s0, $v0, $zero
/* CEEE38 80240BD8 0040182D */  daddu     $v1, $v0, $zero
/* CEEE3C 80240BDC 44920000 */  mtc1      $s2, $f0
/* CEEE40 80240BE0 00000000 */  nop
/* CEEE44 80240BE4 46800020 */  cvt.s.w   $f0, $f0
/* CEEE48 80240BE8 E4600008 */  swc1      $f0, 8($v1)
/* CEEE4C 80240BEC 44910000 */  mtc1      $s1, $f0
/* CEEE50 80240BF0 00000000 */  nop
/* CEEE54 80240BF4 46800020 */  cvt.s.w   $f0, $f0
/* CEEE58 80240BF8 E460000C */  swc1      $f0, 0xc($v1)
/* CEEE5C 80240BFC 44900000 */  mtc1      $s0, $f0
/* CEEE60 80240C00 00000000 */  nop
/* CEEE64 80240C04 46800020 */  cvt.s.w   $f0, $f0
/* CEEE68 80240C08 E4600010 */  swc1      $f0, 0x10($v1)
/* CEEE6C 80240C0C 8FBF0020 */  lw        $ra, 0x20($sp)
/* CEEE70 80240C10 8FB3001C */  lw        $s3, 0x1c($sp)
/* CEEE74 80240C14 8FB20018 */  lw        $s2, 0x18($sp)
/* CEEE78 80240C18 8FB10014 */  lw        $s1, 0x14($sp)
/* CEEE7C 80240C1C 8FB00010 */  lw        $s0, 0x10($sp)
/* CEEE80 80240C20 24020002 */  addiu     $v0, $zero, 2
/* CEEE84 80240C24 03E00008 */  jr        $ra
/* CEEE88 80240C28 27BD0028 */   addiu    $sp, $sp, 0x28
