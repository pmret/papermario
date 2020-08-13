.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel HasMerleeCasts
/* 01A7F4 8003F3F4 AC800084 */  sw    $zero, 0x84($a0)
/* 01A7F8 8003F3F8 3C028011 */  lui   $v0, 0x8011
/* 01A7FC 8003F3FC 8042F51A */  lb    $v0, -0xae6($v0)
/* 01A800 8003F400 18400002 */  blez  $v0, .L8003F40C
/* 01A804 8003F404 24020001 */   addiu $v0, $zero, 1
/* 01A808 8003F408 AC820084 */  sw    $v0, 0x84($a0)
.L8003F40C:
/* 01A80C 8003F40C 03E00008 */  jr    $ra
/* 01A810 8003F410 24020002 */   addiu $v0, $zero, 2

/* 01A814 8003F414 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 01A818 8003F418 AFB1001C */  sw    $s1, 0x1c($sp)
/* 01A81C 8003F41C 0080882D */  daddu $s1, $a0, $zero
/* 01A820 8003F420 AFBF0024 */  sw    $ra, 0x24($sp)
/* 01A824 8003F424 AFB20020 */  sw    $s2, 0x20($sp)
/* 01A828 8003F428 AFB00018 */  sw    $s0, 0x18($sp)
/* 01A82C 8003F42C 8E30000C */  lw    $s0, 0xc($s1)
/* 01A830 8003F430 8E050000 */  lw    $a1, ($s0)
/* 01A834 8003F434 0C0B1EAF */  jal   get_variable
/* 01A838 8003F438 26100004 */   addiu $s0, $s0, 4
/* 01A83C 8003F43C 8E050000 */  lw    $a1, ($s0)
/* 01A840 8003F440 26100004 */  addiu $s0, $s0, 4
/* 01A844 8003F444 0220202D */  daddu $a0, $s1, $zero
/* 01A848 8003F448 0C0B1EAF */  jal   get_variable
/* 01A84C 8003F44C 0040902D */   daddu $s2, $v0, $zero
/* 01A850 8003F450 0220202D */  daddu $a0, $s1, $zero
/* 01A854 8003F454 8E050000 */  lw    $a1, ($s0)
/* 01A858 8003F458 0C0B1EAF */  jal   get_variable
/* 01A85C 8003F45C 0040802D */   daddu $s0, $v0, $zero
/* 01A860 8003F460 24040006 */  addiu $a0, $zero, 6
/* 01A864 8003F464 44921000 */  mtc1  $s2, $f2
/* 01A868 8003F468 00000000 */  nop   
/* 01A86C 8003F46C 468010A0 */  cvt.s.w $f2, $f2
/* 01A870 8003F470 44051000 */  mfc1  $a1, $f2
/* 01A874 8003F474 44901000 */  mtc1  $s0, $f2
/* 01A878 8003F478 00000000 */  nop   
/* 01A87C 8003F47C 468010A0 */  cvt.s.w $f2, $f2
/* 01A880 8003F480 44061000 */  mfc1  $a2, $f2
/* 01A884 8003F484 44821000 */  mtc1  $v0, $f2
/* 01A888 8003F488 00000000 */  nop   
/* 01A88C 8003F48C 468010A0 */  cvt.s.w $f2, $f2
/* 01A890 8003F490 3C013F99 */  lui   $at, 0x3f99
/* 01A894 8003F494 3421999A */  ori   $at, $at, 0x999a
/* 01A898 8003F498 44810000 */  mtc1  $at, $f0
/* 01A89C 8003F49C 44071000 */  mfc1  $a3, $f2
/* 01A8A0 8003F4A0 2403001E */  addiu $v1, $zero, 0x1e
/* 01A8A4 8003F4A4 AFA30014 */  sw    $v1, 0x14($sp)
/* 01A8A8 8003F4A8 0C01C82C */  jal   func_800720B0
/* 01A8AC 8003F4AC E7A00010 */   swc1  $f0, 0x10($sp)
/* 01A8B0 8003F4B0 8FBF0024 */  lw    $ra, 0x24($sp)
/* 01A8B4 8003F4B4 8FB20020 */  lw    $s2, 0x20($sp)
/* 01A8B8 8003F4B8 8FB1001C */  lw    $s1, 0x1c($sp)
/* 01A8BC 8003F4BC 8FB00018 */  lw    $s0, 0x18($sp)
/* 01A8C0 8003F4C0 24020002 */  addiu $v0, $zero, 2
/* 01A8C4 8003F4C4 03E00008 */  jr    $ra
/* 01A8C8 8003F4C8 27BD0028 */   addiu $sp, $sp, 0x28

/* 01A8CC 8003F4CC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 01A8D0 8003F4D0 AFB1001C */  sw    $s1, 0x1c($sp)
/* 01A8D4 8003F4D4 0080882D */  daddu $s1, $a0, $zero
/* 01A8D8 8003F4D8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 01A8DC 8003F4DC AFB20020 */  sw    $s2, 0x20($sp)
/* 01A8E0 8003F4E0 AFB00018 */  sw    $s0, 0x18($sp)
/* 01A8E4 8003F4E4 8E30000C */  lw    $s0, 0xc($s1)
/* 01A8E8 8003F4E8 8E050000 */  lw    $a1, ($s0)
/* 01A8EC 8003F4EC 0C0B1EAF */  jal   get_variable
/* 01A8F0 8003F4F0 26100004 */   addiu $s0, $s0, 4
/* 01A8F4 8003F4F4 8E050000 */  lw    $a1, ($s0)
/* 01A8F8 8003F4F8 26100004 */  addiu $s0, $s0, 4
/* 01A8FC 8003F4FC 0220202D */  daddu $a0, $s1, $zero
/* 01A900 8003F500 0C0B1EAF */  jal   get_variable
/* 01A904 8003F504 0040902D */   daddu $s2, $v0, $zero
/* 01A908 8003F508 0220202D */  daddu $a0, $s1, $zero
/* 01A90C 8003F50C 8E050000 */  lw    $a1, ($s0)
/* 01A910 8003F510 0C0B1EAF */  jal   get_variable
/* 01A914 8003F514 0040802D */   daddu $s0, $v0, $zero
/* 01A918 8003F518 24040009 */  addiu $a0, $zero, 9
/* 01A91C 8003F51C 44921000 */  mtc1  $s2, $f2
/* 01A920 8003F520 00000000 */  nop   
/* 01A924 8003F524 468010A0 */  cvt.s.w $f2, $f2
/* 01A928 8003F528 44051000 */  mfc1  $a1, $f2
/* 01A92C 8003F52C 44901000 */  mtc1  $s0, $f2
/* 01A930 8003F530 00000000 */  nop   
/* 01A934 8003F534 468010A0 */  cvt.s.w $f2, $f2
/* 01A938 8003F538 44061000 */  mfc1  $a2, $f2
/* 01A93C 8003F53C 44821000 */  mtc1  $v0, $f2
/* 01A940 8003F540 00000000 */  nop   
/* 01A944 8003F544 468010A0 */  cvt.s.w $f2, $f2
/* 01A948 8003F548 3C0140A0 */  lui   $at, 0x40a0
/* 01A94C 8003F54C 44810000 */  mtc1  $at, $f0
/* 01A950 8003F550 44071000 */  mfc1  $a3, $f2
/* 01A954 8003F554 2403000F */  addiu $v1, $zero, 0xf
/* 01A958 8003F558 AFA30014 */  sw    $v1, 0x14($sp)
/* 01A95C 8003F55C 0C01C5D4 */  jal   func_80071750
/* 01A960 8003F560 E7A00010 */   swc1  $f0, 0x10($sp)
/* 01A964 8003F564 8FBF0024 */  lw    $ra, 0x24($sp)
/* 01A968 8003F568 8FB20020 */  lw    $s2, 0x20($sp)
/* 01A96C 8003F56C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 01A970 8003F570 8FB00018 */  lw    $s0, 0x18($sp)
/* 01A974 8003F574 24020002 */  addiu $v0, $zero, 2
/* 01A978 8003F578 03E00008 */  jr    $ra
/* 01A97C 8003F57C 27BD0028 */   addiu $sp, $sp, 0x28

