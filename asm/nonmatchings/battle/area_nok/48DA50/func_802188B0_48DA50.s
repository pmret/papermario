.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802188B0_48DA50
/* 48DA50 802188B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 48DA54 802188B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 48DA58 802188B8 0080882D */  daddu     $s1, $a0, $zero
/* 48DA5C 802188BC AFBF0020 */  sw        $ra, 0x20($sp)
/* 48DA60 802188C0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 48DA64 802188C4 AFB20018 */  sw        $s2, 0x18($sp)
/* 48DA68 802188C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 48DA6C 802188CC 8E30000C */  lw        $s0, 0xc($s1)
/* 48DA70 802188D0 8E050000 */  lw        $a1, ($s0)
/* 48DA74 802188D4 0C0B1EAF */  jal       get_variable
/* 48DA78 802188D8 26100004 */   addiu    $s0, $s0, 4
/* 48DA7C 802188DC 8E050000 */  lw        $a1, ($s0)
/* 48DA80 802188E0 26100004 */  addiu     $s0, $s0, 4
/* 48DA84 802188E4 0220202D */  daddu     $a0, $s1, $zero
/* 48DA88 802188E8 0C0B1EAF */  jal       get_variable
/* 48DA8C 802188EC 0040982D */   daddu    $s3, $v0, $zero
/* 48DA90 802188F0 8E050000 */  lw        $a1, ($s0)
/* 48DA94 802188F4 26100004 */  addiu     $s0, $s0, 4
/* 48DA98 802188F8 0220202D */  daddu     $a0, $s1, $zero
/* 48DA9C 802188FC 0C0B1EAF */  jal       get_variable
/* 48DAA0 80218900 0040902D */   daddu    $s2, $v0, $zero
/* 48DAA4 80218904 0220202D */  daddu     $a0, $s1, $zero
/* 48DAA8 80218908 8E050000 */  lw        $a1, ($s0)
/* 48DAAC 8021890C 0C0B1EAF */  jal       get_variable
/* 48DAB0 80218910 0040802D */   daddu    $s0, $v0, $zero
/* 48DAB4 80218914 44936000 */  mtc1      $s3, $f12
/* 48DAB8 80218918 00000000 */  nop       
/* 48DABC 8021891C 46806320 */  cvt.s.w   $f12, $f12
/* 48DAC0 80218920 44927000 */  mtc1      $s2, $f14
/* 48DAC4 80218924 00000000 */  nop       
/* 48DAC8 80218928 468073A0 */  cvt.s.w   $f14, $f14
/* 48DACC 8021892C 44900000 */  mtc1      $s0, $f0
/* 48DAD0 80218930 00000000 */  nop       
/* 48DAD4 80218934 46800020 */  cvt.s.w   $f0, $f0
/* 48DAD8 80218938 44060000 */  mfc1      $a2, $f0
/* 48DADC 8021893C 0C0B5D18 */  jal       func_802D7460
/* 48DAE0 80218940 0040382D */   daddu    $a3, $v0, $zero
/* 48DAE4 80218944 8FBF0020 */  lw        $ra, 0x20($sp)
/* 48DAE8 80218948 8FB3001C */  lw        $s3, 0x1c($sp)
/* 48DAEC 8021894C 8FB20018 */  lw        $s2, 0x18($sp)
/* 48DAF0 80218950 8FB10014 */  lw        $s1, 0x14($sp)
/* 48DAF4 80218954 8FB00010 */  lw        $s0, 0x10($sp)
/* 48DAF8 80218958 24020002 */  addiu     $v0, $zero, 2
/* 48DAFC 8021895C 03E00008 */  jr        $ra
/* 48DB00 80218960 27BD0028 */   addiu    $sp, $sp, 0x28
