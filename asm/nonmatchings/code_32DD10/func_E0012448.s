.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0012448
/* 32E158 E0012448 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 32E15C E001244C AFB40020 */  sw        $s4, 0x20($sp)
/* 32E160 E0012450 0080A02D */  daddu     $s4, $a0, $zero
/* 32E164 E0012454 AFB20018 */  sw        $s2, 0x18($sp)
/* 32E168 E0012458 0000902D */  daddu     $s2, $zero, $zero
/* 32E16C E001245C AFB3001C */  sw        $s3, 0x1c($sp)
/* 32E170 E0012460 AFBF0024 */  sw        $ra, 0x24($sp)
/* 32E174 E0012464 AFB10014 */  sw        $s1, 0x14($sp)
/* 32E178 E0012468 AFB00010 */  sw        $s0, 0x10($sp)
/* 32E17C E001246C 8E820008 */  lw        $v0, 8($s4)
/* 32E180 E0012470 8E90000C */  lw        $s0, 0xc($s4)
/* 32E184 E0012474 18400017 */  blez      $v0, .LE00124D4
/* 32E188 E0012478 0240982D */   daddu    $s3, $s2, $zero
/* 32E18C E001247C 26110006 */  addiu     $s1, $s0, 6
.LE0012480:
/* 32E190 E0012480 8E020000 */  lw        $v0, ($s0)
/* 32E194 E0012484 5040000E */  beql      $v0, $zero, .LE00124C0
/* 32E198 E0012488 26520001 */   addiu    $s2, $s2, 1
/* 32E19C E001248C 96220000 */  lhu       $v0, ($s1)
/* 32E1A0 E0012490 2442FFFF */  addiu     $v0, $v0, -1
/* 32E1A4 E0012494 A6220000 */  sh        $v0, ($s1)
/* 32E1A8 E0012498 00021400 */  sll       $v0, $v0, 0x10
/* 32E1AC E001249C 5C400003 */  bgtzl     $v0, .LE00124AC
/* 32E1B0 E00124A0 24130001 */   addiu    $s3, $zero, 1
/* 32E1B4 E00124A4 0800492F */  j         .LE00124BC
/* 32E1B8 E00124A8 AE000000 */   sw       $zero, ($s0)
.LE00124AC:
/* 32E1BC E00124AC 0C004841 */  jal       func_E0012104
/* 32E1C0 E00124B0 0200202D */   daddu    $a0, $s0, $zero
/* 32E1C4 E00124B4 0C004800 */  jal       func_E0012000
/* 32E1C8 E00124B8 0200202D */   daddu    $a0, $s0, $zero
.LE00124BC:
/* 32E1CC E00124BC 26520001 */  addiu     $s2, $s2, 1
.LE00124C0:
/* 32E1D0 E00124C0 26310098 */  addiu     $s1, $s1, 0x98
/* 32E1D4 E00124C4 8E820008 */  lw        $v0, 8($s4)
/* 32E1D8 E00124C8 0242102A */  slt       $v0, $s2, $v0
/* 32E1DC E00124CC 1440FFEC */  bnez      $v0, .LE0012480
/* 32E1E0 E00124D0 26100098 */   addiu    $s0, $s0, 0x98
.LE00124D4:
/* 32E1E4 E00124D4 16600003 */  bnez      $s3, .LE00124E4
/* 32E1E8 E00124D8 00000000 */   nop      
/* 32E1EC E00124DC 0C080128 */  jal       func_E02004A0
/* 32E1F0 E00124E0 0280202D */   daddu    $a0, $s4, $zero
.LE00124E4:
/* 32E1F4 E00124E4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 32E1F8 E00124E8 8FB40020 */  lw        $s4, 0x20($sp)
/* 32E1FC E00124EC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 32E200 E00124F0 8FB20018 */  lw        $s2, 0x18($sp)
/* 32E204 E00124F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 32E208 E00124F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 32E20C E00124FC 03E00008 */  jr        $ra
/* 32E210 E0012500 27BD0028 */   addiu    $sp, $sp, 0x28
