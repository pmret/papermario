.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_12_update
/* 32F834 E00182B4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 32F838 E00182B8 AFB40020 */  sw        $s4, 0x20($sp)
/* 32F83C E00182BC 0080A02D */  daddu     $s4, $a0, $zero
/* 32F840 E00182C0 AFB20018 */  sw        $s2, 0x18($sp)
/* 32F844 E00182C4 0000902D */  daddu     $s2, $zero, $zero
/* 32F848 E00182C8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 32F84C E00182CC AFBF0024 */  sw        $ra, 0x24($sp)
/* 32F850 E00182D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 32F854 E00182D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 32F858 E00182D8 8E820008 */  lw        $v0, 8($s4)
/* 32F85C E00182DC 8E91000C */  lw        $s1, 0xc($s4)
/* 32F860 E00182E0 18400019 */  blez      $v0, .LE0018348
/* 32F864 E00182E4 0240982D */   daddu    $s3, $s2, $zero
/* 32F868 E00182E8 26300008 */  addiu     $s0, $s1, 8
.LE00182EC:
/* 32F86C E00182EC 8E220000 */  lw        $v0, ($s1)
/* 32F870 E00182F0 50400010 */  beql      $v0, $zero, .LE0018334
/* 32F874 E00182F4 26520001 */   addiu    $s2, $s2, 1
/* 32F878 E00182F8 9602FFFE */  lhu       $v0, -2($s0)
/* 32F87C E00182FC 2442FFFF */  addiu     $v0, $v0, -1
/* 32F880 E0018300 A602FFFE */  sh        $v0, -2($s0)
/* 32F884 E0018304 00021400 */  sll       $v0, $v0, 0x10
/* 32F888 E0018308 1C400003 */  bgtz      $v0, .LE0018318
/* 32F88C E001830C 00000000 */   nop
/* 32F890 E0018310 080060CC */  j         .LE0018330
/* 32F894 E0018314 AE200000 */   sw       $zero, ($s1)
.LE0018318:
/* 32F898 E0018318 0C006000 */  jal       func_E0018000
/* 32F89C E001831C 0220202D */   daddu    $a0, $s1, $zero
/* 32F8A0 E0018320 92020000 */  lbu       $v0, ($s0)
/* 32F8A4 E0018324 24130001 */  addiu     $s3, $zero, 1
/* 32F8A8 E0018328 2442FFFE */  addiu     $v0, $v0, -2
/* 32F8AC E001832C A2020000 */  sb        $v0, ($s0)
.LE0018330:
/* 32F8B0 E0018330 26520001 */  addiu     $s2, $s2, 1
.LE0018334:
/* 32F8B4 E0018334 26100098 */  addiu     $s0, $s0, 0x98
/* 32F8B8 E0018338 8E820008 */  lw        $v0, 8($s4)
/* 32F8BC E001833C 0242102A */  slt       $v0, $s2, $v0
/* 32F8C0 E0018340 1440FFEA */  bnez      $v0, .LE00182EC
/* 32F8C4 E0018344 26310098 */   addiu    $s1, $s1, 0x98
.LE0018348:
/* 32F8C8 E0018348 16600003 */  bnez      $s3, .LE0018358
/* 32F8CC E001834C 00000000 */   nop
/* 32F8D0 E0018350 0C080128 */  jal       shim_remove_effect
/* 32F8D4 E0018354 0280202D */   daddu    $a0, $s4, $zero
.LE0018358:
/* 32F8D8 E0018358 8FBF0024 */  lw        $ra, 0x24($sp)
/* 32F8DC E001835C 8FB40020 */  lw        $s4, 0x20($sp)
/* 32F8E0 E0018360 8FB3001C */  lw        $s3, 0x1c($sp)
/* 32F8E4 E0018364 8FB20018 */  lw        $s2, 0x18($sp)
/* 32F8E8 E0018368 8FB10014 */  lw        $s1, 0x14($sp)
/* 32F8EC E001836C 8FB00010 */  lw        $s0, 0x10($sp)
/* 32F8F0 E0018370 03E00008 */  jr        $ra
/* 32F8F4 E0018374 27BD0028 */   addiu    $sp, $sp, 0x28
