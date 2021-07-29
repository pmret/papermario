.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219B78_4B2D68
/* 4B2D68 80219B78 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4B2D6C 80219B7C AFB10014 */  sw        $s1, 0x14($sp)
/* 4B2D70 80219B80 0080882D */  daddu     $s1, $a0, $zero
/* 4B2D74 80219B84 AFBF0020 */  sw        $ra, 0x20($sp)
/* 4B2D78 80219B88 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4B2D7C 80219B8C AFB20018 */  sw        $s2, 0x18($sp)
/* 4B2D80 80219B90 AFB00010 */  sw        $s0, 0x10($sp)
/* 4B2D84 80219B94 8E30000C */  lw        $s0, 0xc($s1)
/* 4B2D88 80219B98 8E050000 */  lw        $a1, ($s0)
/* 4B2D8C 80219B9C 0C0B1EAF */  jal       get_variable
/* 4B2D90 80219BA0 26100004 */   addiu    $s0, $s0, 4
/* 4B2D94 80219BA4 8E050000 */  lw        $a1, ($s0)
/* 4B2D98 80219BA8 26100004 */  addiu     $s0, $s0, 4
/* 4B2D9C 80219BAC 0220202D */  daddu     $a0, $s1, $zero
/* 4B2DA0 80219BB0 0C0B1EAF */  jal       get_variable
/* 4B2DA4 80219BB4 0040982D */   daddu    $s3, $v0, $zero
/* 4B2DA8 80219BB8 8E050000 */  lw        $a1, ($s0)
/* 4B2DAC 80219BBC 26100004 */  addiu     $s0, $s0, 4
/* 4B2DB0 80219BC0 0220202D */  daddu     $a0, $s1, $zero
/* 4B2DB4 80219BC4 0C0B1EAF */  jal       get_variable
/* 4B2DB8 80219BC8 0040902D */   daddu    $s2, $v0, $zero
/* 4B2DBC 80219BCC 0220202D */  daddu     $a0, $s1, $zero
/* 4B2DC0 80219BD0 8E050000 */  lw        $a1, ($s0)
/* 4B2DC4 80219BD4 0C0B1EAF */  jal       get_variable
/* 4B2DC8 80219BD8 0040802D */   daddu    $s0, $v0, $zero
/* 4B2DCC 80219BDC 24040006 */  addiu     $a0, $zero, 6
/* 4B2DD0 80219BE0 3C058023 */  lui       $a1, %hi(D_802367F0)
/* 4B2DD4 80219BE4 24A567F0 */  addiu     $a1, $a1, %lo(D_802367F0)
/* 4B2DD8 80219BE8 44930000 */  mtc1      $s3, $f0
/* 4B2DDC 80219BEC 00000000 */  nop
/* 4B2DE0 80219BF0 46800020 */  cvt.s.w   $f0, $f0
/* 4B2DE4 80219BF4 E4A00028 */  swc1      $f0, 0x28($a1)
/* 4B2DE8 80219BF8 44920000 */  mtc1      $s2, $f0
/* 4B2DEC 80219BFC 00000000 */  nop
/* 4B2DF0 80219C00 46800020 */  cvt.s.w   $f0, $f0
/* 4B2DF4 80219C04 0040382D */  daddu     $a3, $v0, $zero
/* 4B2DF8 80219C08 3C014120 */  lui       $at, 0x4120
/* 4B2DFC 80219C0C 44811000 */  mtc1      $at, $f2
/* 4B2E00 80219C10 3C063F80 */  lui       $a2, 0x3f80
/* 4B2E04 80219C14 46020001 */  sub.s     $f0, $f0, $f2
/* 4B2E08 80219C18 44901000 */  mtc1      $s0, $f2
/* 4B2E0C 80219C1C 00000000 */  nop
/* 4B2E10 80219C20 468010A0 */  cvt.s.w   $f2, $f2
/* 4B2E14 80219C24 E4A20030 */  swc1      $f2, 0x30($a1)
/* 4B2E18 80219C28 0C01C4B4 */  jal       playFX_46_whirlwind
/* 4B2E1C 80219C2C E4A0002C */   swc1     $f0, 0x2c($a1)
/* 4B2E20 80219C30 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4B2E24 80219C34 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4B2E28 80219C38 8FB20018 */  lw        $s2, 0x18($sp)
/* 4B2E2C 80219C3C 8FB10014 */  lw        $s1, 0x14($sp)
/* 4B2E30 80219C40 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B2E34 80219C44 24020002 */  addiu     $v0, $zero, 2
/* 4B2E38 80219C48 03E00008 */  jr        $ra
/* 4B2E3C 80219C4C 27BD0028 */   addiu    $sp, $sp, 0x28
