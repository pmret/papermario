.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003F4CC
/* 1A8CC 8003F4CC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1A8D0 8003F4D0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1A8D4 8003F4D4 0080882D */  daddu     $s1, $a0, $zero
/* 1A8D8 8003F4D8 AFBF0024 */  sw        $ra, 0x24($sp)
/* 1A8DC 8003F4DC AFB20020 */  sw        $s2, 0x20($sp)
/* 1A8E0 8003F4E0 AFB00018 */  sw        $s0, 0x18($sp)
/* 1A8E4 8003F4E4 8E30000C */  lw        $s0, 0xc($s1)
/* 1A8E8 8003F4E8 8E050000 */  lw        $a1, ($s0)
/* 1A8EC 8003F4EC 0C0B1EAF */  jal       get_variable
/* 1A8F0 8003F4F0 26100004 */   addiu    $s0, $s0, 4
/* 1A8F4 8003F4F4 8E050000 */  lw        $a1, ($s0)
/* 1A8F8 8003F4F8 26100004 */  addiu     $s0, $s0, 4
/* 1A8FC 8003F4FC 0220202D */  daddu     $a0, $s1, $zero
/* 1A900 8003F500 0C0B1EAF */  jal       get_variable
/* 1A904 8003F504 0040902D */   daddu    $s2, $v0, $zero
/* 1A908 8003F508 0220202D */  daddu     $a0, $s1, $zero
/* 1A90C 8003F50C 8E050000 */  lw        $a1, ($s0)
/* 1A910 8003F510 0C0B1EAF */  jal       get_variable
/* 1A914 8003F514 0040802D */   daddu    $s0, $v0, $zero
/* 1A918 8003F518 24040009 */  addiu     $a0, $zero, 9
/* 1A91C 8003F51C 44921000 */  mtc1      $s2, $f2
/* 1A920 8003F520 00000000 */  nop       
/* 1A924 8003F524 468010A0 */  cvt.s.w   $f2, $f2
/* 1A928 8003F528 44051000 */  mfc1      $a1, $f2
/* 1A92C 8003F52C 44901000 */  mtc1      $s0, $f2
/* 1A930 8003F530 00000000 */  nop       
/* 1A934 8003F534 468010A0 */  cvt.s.w   $f2, $f2
/* 1A938 8003F538 44061000 */  mfc1      $a2, $f2
/* 1A93C 8003F53C 44821000 */  mtc1      $v0, $f2
/* 1A940 8003F540 00000000 */  nop       
/* 1A944 8003F544 468010A0 */  cvt.s.w   $f2, $f2
/* 1A948 8003F548 3C0140A0 */  lui       $at, 0x40a0
/* 1A94C 8003F54C 44810000 */  mtc1      $at, $f0
/* 1A950 8003F550 44071000 */  mfc1      $a3, $f2
/* 1A954 8003F554 2403000F */  addiu     $v1, $zero, 0xf
/* 1A958 8003F558 AFA30014 */  sw        $v1, 0x14($sp)
/* 1A95C 8003F55C 0C01C5D4 */  jal       func_80071750
/* 1A960 8003F560 E7A00010 */   swc1     $f0, 0x10($sp)
/* 1A964 8003F564 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1A968 8003F568 8FB20020 */  lw        $s2, 0x20($sp)
/* 1A96C 8003F56C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1A970 8003F570 8FB00018 */  lw        $s0, 0x18($sp)
/* 1A974 8003F574 24020002 */  addiu     $v0, $zero, 2
/* 1A978 8003F578 03E00008 */  jr        $ra
/* 1A97C 8003F57C 27BD0028 */   addiu    $sp, $sp, 0x28
