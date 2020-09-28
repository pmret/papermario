.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003F414
/* 1A814 8003F414 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1A818 8003F418 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1A81C 8003F41C 0080882D */  daddu     $s1, $a0, $zero
/* 1A820 8003F420 AFBF0024 */  sw        $ra, 0x24($sp)
/* 1A824 8003F424 AFB20020 */  sw        $s2, 0x20($sp)
/* 1A828 8003F428 AFB00018 */  sw        $s0, 0x18($sp)
/* 1A82C 8003F42C 8E30000C */  lw        $s0, 0xc($s1)
/* 1A830 8003F430 8E050000 */  lw        $a1, ($s0)
/* 1A834 8003F434 0C0B1EAF */  jal       get_variable
/* 1A838 8003F438 26100004 */   addiu    $s0, $s0, 4
/* 1A83C 8003F43C 8E050000 */  lw        $a1, ($s0)
/* 1A840 8003F440 26100004 */  addiu     $s0, $s0, 4
/* 1A844 8003F444 0220202D */  daddu     $a0, $s1, $zero
/* 1A848 8003F448 0C0B1EAF */  jal       get_variable
/* 1A84C 8003F44C 0040902D */   daddu    $s2, $v0, $zero
/* 1A850 8003F450 0220202D */  daddu     $a0, $s1, $zero
/* 1A854 8003F454 8E050000 */  lw        $a1, ($s0)
/* 1A858 8003F458 0C0B1EAF */  jal       get_variable
/* 1A85C 8003F45C 0040802D */   daddu    $s0, $v0, $zero
/* 1A860 8003F460 24040006 */  addiu     $a0, $zero, 6
/* 1A864 8003F464 44921000 */  mtc1      $s2, $f2
/* 1A868 8003F468 00000000 */  nop       
/* 1A86C 8003F46C 468010A0 */  cvt.s.w   $f2, $f2
/* 1A870 8003F470 44051000 */  mfc1      $a1, $f2
/* 1A874 8003F474 44901000 */  mtc1      $s0, $f2
/* 1A878 8003F478 00000000 */  nop       
/* 1A87C 8003F47C 468010A0 */  cvt.s.w   $f2, $f2
/* 1A880 8003F480 44061000 */  mfc1      $a2, $f2
/* 1A884 8003F484 44821000 */  mtc1      $v0, $f2
/* 1A888 8003F488 00000000 */  nop       
/* 1A88C 8003F48C 468010A0 */  cvt.s.w   $f2, $f2
/* 1A890 8003F490 3C013F99 */  lui       $at, 0x3f99
/* 1A894 8003F494 3421999A */  ori       $at, $at, 0x999a
/* 1A898 8003F498 44810000 */  mtc1      $at, $f0
/* 1A89C 8003F49C 44071000 */  mfc1      $a3, $f2
/* 1A8A0 8003F4A0 2403001E */  addiu     $v1, $zero, 0x1e
/* 1A8A4 8003F4A4 AFA30014 */  sw        $v1, 0x14($sp)
/* 1A8A8 8003F4A8 0C01C82C */  jal       func_800720B0
/* 1A8AC 8003F4AC E7A00010 */   swc1     $f0, 0x10($sp)
/* 1A8B0 8003F4B0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1A8B4 8003F4B4 8FB20020 */  lw        $s2, 0x20($sp)
/* 1A8B8 8003F4B8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1A8BC 8003F4BC 8FB00018 */  lw        $s0, 0x18($sp)
/* 1A8C0 8003F4C0 24020002 */  addiu     $v0, $zero, 2
/* 1A8C4 8003F4C4 03E00008 */  jr        $ra
/* 1A8C8 8003F4C8 27BD0028 */   addiu    $sp, $sp, 0x28
