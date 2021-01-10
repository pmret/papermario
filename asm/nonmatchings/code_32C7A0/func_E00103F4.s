.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00103F4
/* 32CB94 E00103F4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 32CB98 E00103F8 AFB40020 */  sw        $s4, 0x20($sp)
/* 32CB9C E00103FC 0080A02D */  daddu     $s4, $a0, $zero
/* 32CBA0 E0010400 AFB20018 */  sw        $s2, 0x18($sp)
/* 32CBA4 E0010404 0000902D */  daddu     $s2, $zero, $zero
/* 32CBA8 E0010408 AFB3001C */  sw        $s3, 0x1c($sp)
/* 32CBAC E001040C AFBF0024 */  sw        $ra, 0x24($sp)
/* 32CBB0 E0010410 AFB10014 */  sw        $s1, 0x14($sp)
/* 32CBB4 E0010414 AFB00010 */  sw        $s0, 0x10($sp)
/* 32CBB8 E0010418 8E820008 */  lw        $v0, 8($s4)
/* 32CBBC E001041C 8E90000C */  lw        $s0, 0xc($s4)
/* 32CBC0 E0010420 18400017 */  blez      $v0, .LE0010480
/* 32CBC4 E0010424 0240982D */   daddu    $s3, $s2, $zero
/* 32CBC8 E0010428 26110006 */  addiu     $s1, $s0, 6
.LE001042C:
/* 32CBCC E001042C 8E020000 */  lw        $v0, ($s0)
/* 32CBD0 E0010430 5040000E */  beql      $v0, $zero, .LE001046C
/* 32CBD4 E0010434 26520001 */   addiu    $s2, $s2, 1
/* 32CBD8 E0010438 96220000 */  lhu       $v0, ($s1)
/* 32CBDC E001043C 2442FFFF */  addiu     $v0, $v0, -1
/* 32CBE0 E0010440 A6220000 */  sh        $v0, ($s1)
/* 32CBE4 E0010444 00021400 */  sll       $v0, $v0, 0x10
/* 32CBE8 E0010448 5C400003 */  bgtzl     $v0, .LE0010458
/* 32CBEC E001044C 24130001 */   addiu    $s3, $zero, 1
/* 32CBF0 E0010450 0800411A */  j         .LE0010468
/* 32CBF4 E0010454 AE000000 */   sw       $zero, ($s0)
.LE0010458:
/* 32CBF8 E0010458 0C004041 */  jal       func_E0010104
/* 32CBFC E001045C 0200202D */   daddu    $a0, $s0, $zero
/* 32CC00 E0010460 0C004000 */  jal       func_E0010000
/* 32CC04 E0010464 0200202D */   daddu    $a0, $s0, $zero
.LE0010468:
/* 32CC08 E0010468 26520001 */  addiu     $s2, $s2, 1
.LE001046C:
/* 32CC0C E001046C 26310098 */  addiu     $s1, $s1, 0x98
/* 32CC10 E0010470 8E820008 */  lw        $v0, 8($s4)
/* 32CC14 E0010474 0242102A */  slt       $v0, $s2, $v0
/* 32CC18 E0010478 1440FFEC */  bnez      $v0, .LE001042C
/* 32CC1C E001047C 26100098 */   addiu    $s0, $s0, 0x98
.LE0010480:
/* 32CC20 E0010480 16600003 */  bnez      $s3, .LE0010490
/* 32CC24 E0010484 00000000 */   nop      
/* 32CC28 E0010488 0C080128 */  jal       func_E02004A0
/* 32CC2C E001048C 0280202D */   daddu    $a0, $s4, $zero
.LE0010490:
/* 32CC30 E0010490 8FBF0024 */  lw        $ra, 0x24($sp)
/* 32CC34 E0010494 8FB40020 */  lw        $s4, 0x20($sp)
/* 32CC38 E0010498 8FB3001C */  lw        $s3, 0x1c($sp)
/* 32CC3C E001049C 8FB20018 */  lw        $s2, 0x18($sp)
/* 32CC40 E00104A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 32CC44 E00104A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 32CC48 E00104A8 03E00008 */  jr        $ra
/* 32CC4C E00104AC 27BD0028 */   addiu    $sp, $sp, 0x28
