.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BA0_B075A0
/* B075A0 80240BA0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B075A4 80240BA4 AFB10014 */  sw        $s1, 0x14($sp)
/* B075A8 80240BA8 0080882D */  daddu     $s1, $a0, $zero
/* B075AC 80240BAC AFBF0020 */  sw        $ra, 0x20($sp)
/* B075B0 80240BB0 AFB3001C */  sw        $s3, 0x1c($sp)
/* B075B4 80240BB4 AFB20018 */  sw        $s2, 0x18($sp)
/* B075B8 80240BB8 AFB00010 */  sw        $s0, 0x10($sp)
/* B075BC 80240BBC 8E30000C */  lw        $s0, 0xc($s1)
/* B075C0 80240BC0 8E050000 */  lw        $a1, ($s0)
/* B075C4 80240BC4 0C0B1EAF */  jal       get_variable
/* B075C8 80240BC8 26100004 */   addiu    $s0, $s0, 4
/* B075CC 80240BCC 8E050000 */  lw        $a1, ($s0)
/* B075D0 80240BD0 26100004 */  addiu     $s0, $s0, 4
/* B075D4 80240BD4 0220202D */  daddu     $a0, $s1, $zero
/* B075D8 80240BD8 0C0B1EAF */  jal       get_variable
/* B075DC 80240BDC 0040902D */   daddu    $s2, $v0, $zero
/* B075E0 80240BE0 8E050000 */  lw        $a1, ($s0)
/* B075E4 80240BE4 26100004 */  addiu     $s0, $s0, 4
/* B075E8 80240BE8 0220202D */  daddu     $a0, $s1, $zero
/* B075EC 80240BEC 0C0B1EAF */  jal       get_variable
/* B075F0 80240BF0 0040982D */   daddu    $s3, $v0, $zero
/* B075F4 80240BF4 0220202D */  daddu     $a0, $s1, $zero
/* B075F8 80240BF8 8E050000 */  lw        $a1, ($s0)
/* B075FC 80240BFC 0C0B1EAF */  jal       get_variable
/* B07600 80240C00 0040802D */   daddu    $s0, $v0, $zero
/* B07604 80240C04 8E43000C */  lw        $v1, 0xc($s2)
/* B07608 80240C08 44930000 */  mtc1      $s3, $f0
/* B0760C 80240C0C 00000000 */  nop       
/* B07610 80240C10 46800020 */  cvt.s.w   $f0, $f0
/* B07614 80240C14 E4600004 */  swc1      $f0, 4($v1)
/* B07618 80240C18 8E43000C */  lw        $v1, 0xc($s2)
/* B0761C 80240C1C 44900000 */  mtc1      $s0, $f0
/* B07620 80240C20 00000000 */  nop       
/* B07624 80240C24 46800020 */  cvt.s.w   $f0, $f0
/* B07628 80240C28 E4600008 */  swc1      $f0, 8($v1)
/* B0762C 80240C2C 8E43000C */  lw        $v1, 0xc($s2)
/* B07630 80240C30 44820000 */  mtc1      $v0, $f0
/* B07634 80240C34 00000000 */  nop       
/* B07638 80240C38 46800020 */  cvt.s.w   $f0, $f0
/* B0763C 80240C3C E460000C */  swc1      $f0, 0xc($v1)
/* B07640 80240C40 8FBF0020 */  lw        $ra, 0x20($sp)
/* B07644 80240C44 8FB3001C */  lw        $s3, 0x1c($sp)
/* B07648 80240C48 8FB20018 */  lw        $s2, 0x18($sp)
/* B0764C 80240C4C 8FB10014 */  lw        $s1, 0x14($sp)
/* B07650 80240C50 8FB00010 */  lw        $s0, 0x10($sp)
/* B07654 80240C54 24020002 */  addiu     $v0, $zero, 2
/* B07658 80240C58 03E00008 */  jr        $ra
/* B0765C 80240C5C 27BD0028 */   addiu    $sp, $sp, 0x28
