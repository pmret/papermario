.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218BF8_4B1DE8
/* 4B1DE8 80218BF8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4B1DEC 80218BFC AFB10014 */  sw        $s1, 0x14($sp)
/* 4B1DF0 80218C00 0080882D */  daddu     $s1, $a0, $zero
/* 4B1DF4 80218C04 AFBF0020 */  sw        $ra, 0x20($sp)
/* 4B1DF8 80218C08 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4B1DFC 80218C0C AFB20018 */  sw        $s2, 0x18($sp)
/* 4B1E00 80218C10 AFB00010 */  sw        $s0, 0x10($sp)
/* 4B1E04 80218C14 8E30000C */  lw        $s0, 0xc($s1)
/* 4B1E08 80218C18 8E050000 */  lw        $a1, ($s0)
/* 4B1E0C 80218C1C 0C0B1EAF */  jal       get_variable
/* 4B1E10 80218C20 26100004 */   addiu    $s0, $s0, 4
/* 4B1E14 80218C24 8E050000 */  lw        $a1, ($s0)
/* 4B1E18 80218C28 26100004 */  addiu     $s0, $s0, 4
/* 4B1E1C 80218C2C 0220202D */  daddu     $a0, $s1, $zero
/* 4B1E20 80218C30 0C0B1EAF */  jal       get_variable
/* 4B1E24 80218C34 0040982D */   daddu    $s3, $v0, $zero
/* 4B1E28 80218C38 8E050000 */  lw        $a1, ($s0)
/* 4B1E2C 80218C3C 26100004 */  addiu     $s0, $s0, 4
/* 4B1E30 80218C40 0220202D */  daddu     $a0, $s1, $zero
/* 4B1E34 80218C44 0C0B1EAF */  jal       get_variable
/* 4B1E38 80218C48 0040902D */   daddu    $s2, $v0, $zero
/* 4B1E3C 80218C4C 0220202D */  daddu     $a0, $s1, $zero
/* 4B1E40 80218C50 8E050000 */  lw        $a1, ($s0)
/* 4B1E44 80218C54 0C0B1EAF */  jal       get_variable
/* 4B1E48 80218C58 0040802D */   daddu    $s0, $v0, $zero
/* 4B1E4C 80218C5C 24040006 */  addiu     $a0, $zero, 6
/* 4B1E50 80218C60 3C058023 */  lui       $a1, %hi(D_802362D0)
/* 4B1E54 80218C64 24A562D0 */  addiu     $a1, $a1, %lo(D_802362D0)
/* 4B1E58 80218C68 44930000 */  mtc1      $s3, $f0
/* 4B1E5C 80218C6C 00000000 */  nop
/* 4B1E60 80218C70 46800020 */  cvt.s.w   $f0, $f0
/* 4B1E64 80218C74 E4A00028 */  swc1      $f0, 0x28($a1)
/* 4B1E68 80218C78 44920000 */  mtc1      $s2, $f0
/* 4B1E6C 80218C7C 00000000 */  nop
/* 4B1E70 80218C80 46800020 */  cvt.s.w   $f0, $f0
/* 4B1E74 80218C84 0040382D */  daddu     $a3, $v0, $zero
/* 4B1E78 80218C88 3C014120 */  lui       $at, 0x4120
/* 4B1E7C 80218C8C 44811000 */  mtc1      $at, $f2
/* 4B1E80 80218C90 3C063F80 */  lui       $a2, 0x3f80
/* 4B1E84 80218C94 46020001 */  sub.s     $f0, $f0, $f2
/* 4B1E88 80218C98 44901000 */  mtc1      $s0, $f2
/* 4B1E8C 80218C9C 00000000 */  nop
/* 4B1E90 80218CA0 468010A0 */  cvt.s.w   $f2, $f2
/* 4B1E94 80218CA4 E4A20030 */  swc1      $f2, 0x30($a1)
/* 4B1E98 80218CA8 0C01C4B4 */  jal       func_800712D0
/* 4B1E9C 80218CAC E4A0002C */   swc1     $f0, 0x2c($a1)
/* 4B1EA0 80218CB0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4B1EA4 80218CB4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4B1EA8 80218CB8 8FB20018 */  lw        $s2, 0x18($sp)
/* 4B1EAC 80218CBC 8FB10014 */  lw        $s1, 0x14($sp)
/* 4B1EB0 80218CC0 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B1EB4 80218CC4 24020002 */  addiu     $v0, $zero, 2
/* 4B1EB8 80218CC8 03E00008 */  jr        $ra
/* 4B1EBC 80218CCC 27BD0028 */   addiu    $sp, $sp, 0x28
