.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218184_6DDF44
/* 6DDF44 80218184 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6DDF48 80218188 AFB10014 */  sw        $s1, 0x14($sp)
/* 6DDF4C 8021818C 0080882D */  daddu     $s1, $a0, $zero
/* 6DDF50 80218190 AFBF0020 */  sw        $ra, 0x20($sp)
/* 6DDF54 80218194 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6DDF58 80218198 AFB20018 */  sw        $s2, 0x18($sp)
/* 6DDF5C 8021819C AFB00010 */  sw        $s0, 0x10($sp)
/* 6DDF60 802181A0 8E30000C */  lw        $s0, 0xc($s1)
/* 6DDF64 802181A4 8E050000 */  lw        $a1, ($s0)
/* 6DDF68 802181A8 0C0B1EAF */  jal       get_variable
/* 6DDF6C 802181AC 26100004 */   addiu    $s0, $s0, 4
/* 6DDF70 802181B0 8E050000 */  lw        $a1, ($s0)
/* 6DDF74 802181B4 26100004 */  addiu     $s0, $s0, 4
/* 6DDF78 802181B8 0220202D */  daddu     $a0, $s1, $zero
/* 6DDF7C 802181BC 0C0B1EAF */  jal       get_variable
/* 6DDF80 802181C0 0040982D */   daddu    $s3, $v0, $zero
/* 6DDF84 802181C4 8E050000 */  lw        $a1, ($s0)
/* 6DDF88 802181C8 26100004 */  addiu     $s0, $s0, 4
/* 6DDF8C 802181CC 0220202D */  daddu     $a0, $s1, $zero
/* 6DDF90 802181D0 0C0B1EAF */  jal       get_variable
/* 6DDF94 802181D4 0040902D */   daddu    $s2, $v0, $zero
/* 6DDF98 802181D8 0220202D */  daddu     $a0, $s1, $zero
/* 6DDF9C 802181DC 8E050000 */  lw        $a1, ($s0)
/* 6DDFA0 802181E0 0C0B1EAF */  jal       get_variable
/* 6DDFA4 802181E4 0040802D */   daddu    $s0, $v0, $zero
/* 6DDFA8 802181E8 44936000 */  mtc1      $s3, $f12
/* 6DDFAC 802181EC 00000000 */  nop       
/* 6DDFB0 802181F0 46806320 */  cvt.s.w   $f12, $f12
/* 6DDFB4 802181F4 44927000 */  mtc1      $s2, $f14
/* 6DDFB8 802181F8 00000000 */  nop       
/* 6DDFBC 802181FC 468073A0 */  cvt.s.w   $f14, $f14
/* 6DDFC0 80218200 44900000 */  mtc1      $s0, $f0
/* 6DDFC4 80218204 00000000 */  nop       
/* 6DDFC8 80218208 46800020 */  cvt.s.w   $f0, $f0
/* 6DDFCC 8021820C 44060000 */  mfc1      $a2, $f0
/* 6DDFD0 80218210 0C0B5D30 */  jal       func_802D74C0
/* 6DDFD4 80218214 0040382D */   daddu    $a3, $v0, $zero
/* 6DDFD8 80218218 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6DDFDC 8021821C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6DDFE0 80218220 8FB20018 */  lw        $s2, 0x18($sp)
/* 6DDFE4 80218224 8FB10014 */  lw        $s1, 0x14($sp)
/* 6DDFE8 80218228 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DDFEC 8021822C 24020002 */  addiu     $v0, $zero, 2
/* 6DDFF0 80218230 03E00008 */  jr        $ra
/* 6DDFF4 80218234 27BD0028 */   addiu    $sp, $sp, 0x28
/* 6DDFF8 80218238 00000000 */  nop       
/* 6DDFFC 8021823C 00000000 */  nop       
