.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005DFD4
/* 393D4 8005DFD4 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 393D8 8005DFD8 AFB20030 */  sw        $s2, 0x30($sp)
/* 393DC 8005DFDC 0080902D */  daddu     $s2, $a0, $zero
/* 393E0 8005DFE0 27A6001C */  addiu     $a2, $sp, 0x1c
/* 393E4 8005DFE4 27A70020 */  addiu     $a3, $sp, 0x20
/* 393E8 8005DFE8 AFBF0038 */  sw        $ra, 0x38($sp)
/* 393EC 8005DFEC AFB30034 */  sw        $s3, 0x34($sp)
/* 393F0 8005DFF0 AFB1002C */  sw        $s1, 0x2c($sp)
/* 393F4 8005DFF4 AFB00028 */  sw        $s0, 0x28($sp)
/* 393F8 8005DFF8 8E510020 */  lw        $s1, 0x20($s2)
/* 393FC 8005DFFC 27A20024 */  addiu     $v0, $sp, 0x24
/* 39400 8005E000 AFA20010 */  sw        $v0, 0x10($sp)
/* 39404 8005E004 8E24028C */  lw        $a0, 0x28c($s1)
/* 39408 8005E008 0C017784 */  jal       get_npc_pos
/* 3940C 8005E00C 27A50018 */   addiu    $a1, $sp, 0x18
/* 39410 8005E010 8E220280 */  lw        $v0, 0x280($s1)
/* 39414 8005E014 00021100 */  sll       $v0, $v0, 4
/* 39418 8005E018 02228021 */  addu      $s0, $s1, $v0
/* 3941C 8005E01C 8FA20024 */  lw        $v0, 0x24($sp)
/* 39420 8005E020 82030000 */  lb        $v1, ($s0)
/* 39424 8005E024 10600003 */  beqz      $v1, .L8005E034
/* 39428 8005E028 0002982B */   sltu     $s3, $zero, $v0
/* 3942C 8005E02C 16600038 */  bnez      $s3, .L8005E110
/* 39430 8005E030 00000000 */   nop
.L8005E034:
/* 39434 8005E034 1660000E */  bnez      $s3, .L8005E070
/* 39438 8005E038 00000000 */   nop
/* 3943C 8005E03C 8FA60018 */  lw        $a2, 0x18($sp)
/* 39440 8005E040 8FA70020 */  lw        $a3, 0x20($sp)
/* 39444 8005E044 C64C0038 */  lwc1      $f12, 0x38($s2)
/* 39448 8005E048 0C00A7B5 */  jal       dist2D
/* 3944C 8005E04C C64E0040 */   lwc1     $f14, 0x40($s2)
/* 39450 8005E050 C622029C */  lwc1      $f2, 0x29c($s1)
/* 39454 8005E054 4602003E */  c.le.s    $f0, $f2
/* 39458 8005E058 00000000 */  nop
/* 3945C 8005E05C 45000004 */  bc1f      .L8005E070
/* 39460 8005E060 00000000 */   nop
/* 39464 8005E064 82020000 */  lb        $v0, ($s0)
/* 39468 8005E068 10400029 */  beqz      $v0, .L8005E110
/* 3946C 8005E06C 00000000 */   nop
.L8005E070:
/* 39470 8005E070 8E220280 */  lw        $v0, 0x280($s1)
/* 39474 8005E074 C7A00018 */  lwc1      $f0, 0x18($sp)
/* 39478 8005E078 00021100 */  sll       $v0, $v0, 4
/* 3947C 8005E07C 02228021 */  addu      $s0, $s1, $v0
/* 39480 8005E080 C6020004 */  lwc1      $f2, 4($s0)
/* 39484 8005E084 46001032 */  c.eq.s    $f2, $f0
/* 39488 8005E088 00000000 */  nop
/* 3948C 8005E08C 4500000D */  bc1f      .L8005E0C4
/* 39490 8005E090 00000000 */   nop
/* 39494 8005E094 C6020008 */  lwc1      $f2, 8($s0)
/* 39498 8005E098 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 3949C 8005E09C 46001032 */  c.eq.s    $f2, $f0
/* 394A0 8005E0A0 00000000 */  nop
/* 394A4 8005E0A4 45000007 */  bc1f      .L8005E0C4
/* 394A8 8005E0A8 00000000 */   nop
/* 394AC 8005E0AC C602000C */  lwc1      $f2, 0xc($s0)
/* 394B0 8005E0B0 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 394B4 8005E0B4 46001032 */  c.eq.s    $f2, $f0
/* 394B8 8005E0B8 00000000 */  nop
/* 394BC 8005E0BC 45010014 */  bc1t      .L8005E110
/* 394C0 8005E0C0 00000000 */   nop
.L8005E0C4:
/* 394C4 8005E0C4 8E220280 */  lw        $v0, 0x280($s1)
/* 394C8 8005E0C8 8E230284 */  lw        $v1, 0x284($s1)
/* 394CC 8005E0CC 24420001 */  addiu     $v0, $v0, 1
/* 394D0 8005E0D0 1062000F */  beq       $v1, $v0, .L8005E110
/* 394D4 8005E0D4 00000000 */   nop
/* 394D8 8005E0D8 AE220280 */  sw        $v0, 0x280($s1)
/* 394DC 8005E0DC 28420028 */  slti      $v0, $v0, 0x28
/* 394E0 8005E0E0 50400001 */  beql      $v0, $zero, .L8005E0E8
/* 394E4 8005E0E4 AE200280 */   sw       $zero, 0x280($s1)
.L8005E0E8:
/* 394E8 8005E0E8 8E220280 */  lw        $v0, 0x280($s1)
/* 394EC 8005E0EC C7A00018 */  lwc1      $f0, 0x18($sp)
/* 394F0 8005E0F0 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* 394F4 8005E0F4 C7A40020 */  lwc1      $f4, 0x20($sp)
/* 394F8 8005E0F8 00021100 */  sll       $v0, $v0, 4
/* 394FC 8005E0FC 02228021 */  addu      $s0, $s1, $v0
/* 39500 8005E100 E6000004 */  swc1      $f0, 4($s0)
/* 39504 8005E104 E6020008 */  swc1      $f2, 8($s0)
/* 39508 8005E108 E604000C */  swc1      $f4, 0xc($s0)
/* 3950C 8005E10C A2130000 */  sb        $s3, ($s0)
.L8005E110:
/* 39510 8005E110 8FBF0038 */  lw        $ra, 0x38($sp)
/* 39514 8005E114 8FB30034 */  lw        $s3, 0x34($sp)
/* 39518 8005E118 8FB20030 */  lw        $s2, 0x30($sp)
/* 3951C 8005E11C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 39520 8005E120 8FB00028 */  lw        $s0, 0x28($sp)
/* 39524 8005E124 03E00008 */  jr        $ra
/* 39528 8005E128 27BD0040 */   addiu    $sp, $sp, 0x40
