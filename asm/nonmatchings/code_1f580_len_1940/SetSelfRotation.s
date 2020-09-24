.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetSelfRotation
/* 2085C 8004545C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 20860 80045460 AFB10014 */  sw        $s1, 0x14($sp)
/* 20864 80045464 0080882D */  daddu     $s1, $a0, $zero
/* 20868 80045468 AFBF0020 */  sw        $ra, 0x20($sp)
/* 2086C 8004546C AFB3001C */  sw        $s3, 0x1c($sp)
/* 20870 80045470 AFB20018 */  sw        $s2, 0x18($sp)
/* 20874 80045474 AFB00010 */  sw        $s0, 0x10($sp)
/* 20878 80045478 8E24014C */  lw        $a0, 0x14c($s1)
/* 2087C 8004547C 0C00EABB */  jal       get_npc_unsafe
/* 20880 80045480 8E30000C */   lw       $s0, 0xc($s1)
/* 20884 80045484 8E050000 */  lw        $a1, ($s0)
/* 20888 80045488 26100004 */  addiu     $s0, $s0, 4
/* 2088C 8004548C 0220202D */  daddu     $a0, $s1, $zero
/* 20890 80045490 0C0B1EAF */  jal       get_variable
/* 20894 80045494 0040902D */   daddu    $s2, $v0, $zero
/* 20898 80045498 8E050000 */  lw        $a1, ($s0)
/* 2089C 8004549C 26100004 */  addiu     $s0, $s0, 4
/* 208A0 800454A0 0220202D */  daddu     $a0, $s1, $zero
/* 208A4 800454A4 0C0B1EAF */  jal       get_variable
/* 208A8 800454A8 0040982D */   daddu    $s3, $v0, $zero
/* 208AC 800454AC 0220202D */  daddu     $a0, $s1, $zero
/* 208B0 800454B0 8E050000 */  lw        $a1, ($s0)
/* 208B4 800454B4 0C0B1EAF */  jal       get_variable
/* 208B8 800454B8 0040802D */   daddu    $s0, $v0, $zero
/* 208BC 800454BC 44821000 */  mtc1      $v0, $f2
/* 208C0 800454C0 00000000 */  nop       
/* 208C4 800454C4 468010A0 */  cvt.s.w   $f2, $f2
/* 208C8 800454C8 44930000 */  mtc1      $s3, $f0
/* 208CC 800454CC 00000000 */  nop       
/* 208D0 800454D0 46800020 */  cvt.s.w   $f0, $f0
/* 208D4 800454D4 E6400044 */  swc1      $f0, 0x44($s2)
/* 208D8 800454D8 44900000 */  mtc1      $s0, $f0
/* 208DC 800454DC 00000000 */  nop       
/* 208E0 800454E0 46800020 */  cvt.s.w   $f0, $f0
/* 208E4 800454E4 E6400048 */  swc1      $f0, 0x48($s2)
/* 208E8 800454E8 E642004C */  swc1      $f2, 0x4c($s2)
/* 208EC 800454EC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 208F0 800454F0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 208F4 800454F4 8FB20018 */  lw        $s2, 0x18($sp)
/* 208F8 800454F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 208FC 800454FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 20900 80045500 24020002 */  addiu     $v0, $zero, 2
/* 20904 80045504 03E00008 */  jr        $ra
/* 20908 80045508 27BD0028 */   addiu    $sp, $sp, 0x28
