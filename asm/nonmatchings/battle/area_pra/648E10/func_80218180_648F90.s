.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218180_648F90
/* 648F90 80218180 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 648F94 80218184 AFB10014 */  sw        $s1, 0x14($sp)
/* 648F98 80218188 0080882D */  daddu     $s1, $a0, $zero
/* 648F9C 8021818C AFBF0020 */  sw        $ra, 0x20($sp)
/* 648FA0 80218190 AFB3001C */  sw        $s3, 0x1c($sp)
/* 648FA4 80218194 AFB20018 */  sw        $s2, 0x18($sp)
/* 648FA8 80218198 AFB00010 */  sw        $s0, 0x10($sp)
/* 648FAC 8021819C 8E30000C */  lw        $s0, 0xc($s1)
/* 648FB0 802181A0 8E050000 */  lw        $a1, ($s0)
/* 648FB4 802181A4 0C0B1EAF */  jal       get_variable
/* 648FB8 802181A8 26100004 */   addiu    $s0, $s0, 4
/* 648FBC 802181AC 8E050000 */  lw        $a1, ($s0)
/* 648FC0 802181B0 26100004 */  addiu     $s0, $s0, 4
/* 648FC4 802181B4 0220202D */  daddu     $a0, $s1, $zero
/* 648FC8 802181B8 0C0B1EAF */  jal       get_variable
/* 648FCC 802181BC 0040982D */   daddu    $s3, $v0, $zero
/* 648FD0 802181C0 8E050000 */  lw        $a1, ($s0)
/* 648FD4 802181C4 26100004 */  addiu     $s0, $s0, 4
/* 648FD8 802181C8 0220202D */  daddu     $a0, $s1, $zero
/* 648FDC 802181CC 0C0B1EAF */  jal       get_variable
/* 648FE0 802181D0 0040902D */   daddu    $s2, $v0, $zero
/* 648FE4 802181D4 0220202D */  daddu     $a0, $s1, $zero
/* 648FE8 802181D8 8E050000 */  lw        $a1, ($s0)
/* 648FEC 802181DC 0C0B1EAF */  jal       get_variable
/* 648FF0 802181E0 0040802D */   daddu    $s0, $v0, $zero
/* 648FF4 802181E4 44936000 */  mtc1      $s3, $f12
/* 648FF8 802181E8 00000000 */  nop       
/* 648FFC 802181EC 46806320 */  cvt.s.w   $f12, $f12
/* 649000 802181F0 44927000 */  mtc1      $s2, $f14
/* 649004 802181F4 00000000 */  nop       
/* 649008 802181F8 468073A0 */  cvt.s.w   $f14, $f14
/* 64900C 802181FC 44900000 */  mtc1      $s0, $f0
/* 649010 80218200 00000000 */  nop       
/* 649014 80218204 46800020 */  cvt.s.w   $f0, $f0
/* 649018 80218208 44060000 */  mfc1      $a2, $f0
/* 64901C 8021820C 0C0B5D30 */  jal       func_802D74C0
/* 649020 80218210 0040382D */   daddu    $a3, $v0, $zero
/* 649024 80218214 8FBF0020 */  lw        $ra, 0x20($sp)
/* 649028 80218218 8FB3001C */  lw        $s3, 0x1c($sp)
/* 64902C 8021821C 8FB20018 */  lw        $s2, 0x18($sp)
/* 649030 80218220 8FB10014 */  lw        $s1, 0x14($sp)
/* 649034 80218224 8FB00010 */  lw        $s0, 0x10($sp)
/* 649038 80218228 24020002 */  addiu     $v0, $zero, 2
/* 64903C 8021822C 03E00008 */  jr        $ra
/* 649040 80218230 27BD0028 */   addiu    $sp, $sp, 0x28
/* 649044 80218234 00000000 */  nop       
/* 649048 80218238 00000000 */  nop       
/* 64904C 8021823C 00000000 */  nop       
