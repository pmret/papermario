.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E008A188
/* 38C778 E008A188 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 38C77C E008A18C AFB1002C */  sw        $s1, 0x2c($sp)
/* 38C780 E008A190 0080882D */  daddu     $s1, $a0, $zero
/* 38C784 E008A194 AFB30034 */  sw        $s3, 0x34($sp)
/* 38C788 E008A198 00A0982D */  daddu     $s3, $a1, $zero
/* 38C78C E008A19C 27A40010 */  addiu     $a0, $sp, 0x10
/* 38C790 E008A1A0 3C02E009 */  lui       $v0, %hi(func_E008A288)
/* 38C794 E008A1A4 2442A288 */  addiu     $v0, $v0, %lo(func_E008A288)
/* 38C798 E008A1A8 AFA20018 */  sw        $v0, 0x18($sp)
/* 38C79C E008A1AC 3C02E009 */  lui       $v0, %hi(func_E008A53C)
/* 38C7A0 E008A1B0 2442A53C */  addiu     $v0, $v0, %lo(func_E008A53C)
/* 38C7A4 E008A1B4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 38C7A8 E008A1B8 3C02E009 */  lui       $v0, %hi(func_E008A6E4)
/* 38C7AC E008A1BC 2442A6E4 */  addiu     $v0, $v0, %lo(func_E008A6E4)
/* 38C7B0 E008A1C0 AFA20020 */  sw        $v0, 0x20($sp)
/* 38C7B4 E008A1C4 24020045 */  addiu     $v0, $zero, 0x45
/* 38C7B8 E008A1C8 AFB00028 */  sw        $s0, 0x28($sp)
/* 38C7BC E008A1CC 26700001 */  addiu     $s0, $s3, 1
/* 38C7C0 E008A1D0 AFBF0038 */  sw        $ra, 0x38($sp)
/* 38C7C4 E008A1D4 AFB20030 */  sw        $s2, 0x30($sp)
/* 38C7C8 E008A1D8 AFA00010 */  sw        $zero, 0x10($sp)
/* 38C7CC E008A1DC AFA00024 */  sw        $zero, 0x24($sp)
/* 38C7D0 E008A1E0 0C080124 */  jal       func_E0200490
/* 38C7D4 E008A1E4 AFA20014 */   sw       $v0, 0x14($sp)
/* 38C7D8 E008A1E8 00102040 */  sll       $a0, $s0, 1
/* 38C7DC E008A1EC 00902021 */  addu      $a0, $a0, $s0
/* 38C7E0 E008A1F0 00042080 */  sll       $a0, $a0, 2
/* 38C7E4 E008A1F4 00902021 */  addu      $a0, $a0, $s0
/* 38C7E8 E008A1F8 00042080 */  sll       $a0, $a0, 2
/* 38C7EC E008A1FC 0040902D */  daddu     $s2, $v0, $zero
/* 38C7F0 E008A200 0C08012C */  jal       func_E02004B0
/* 38C7F4 E008A204 AE500008 */   sw       $s0, 8($s2)
/* 38C7F8 E008A208 0040802D */  daddu     $s0, $v0, $zero
/* 38C7FC E008A20C 16000003 */  bnez      $s0, .LE008A21C
/* 38C800 E008A210 AE50000C */   sw       $s0, 0xc($s2)
.LE008A214:
/* 38C804 E008A214 08022885 */  j         .LE008A214
/* 38C808 E008A218 00000000 */   nop
.LE008A21C:
/* 38C80C E008A21C 24020064 */  addiu     $v0, $zero, 0x64
/* 38C810 E008A220 AE020020 */  sw        $v0, 0x20($s0)
/* 38C814 E008A224 240200FF */  addiu     $v0, $zero, 0xff
/* 38C818 E008A228 AE020028 */  sw        $v0, 0x28($s0)
/* 38C81C E008A22C 24020001 */  addiu     $v0, $zero, 1
/* 38C820 E008A230 AE000024 */  sw        $zero, 0x24($s0)
/* 38C824 E008A234 AE110004 */  sw        $s1, 4($s0)
/* 38C828 E008A238 AE13002C */  sw        $s3, 0x2c($s0)
/* 38C82C E008A23C AE020000 */  sw        $v0, ($s0)
/* 38C830 E008A240 26100034 */  addiu     $s0, $s0, 0x34
/* 38C834 E008A244 1A600008 */  blez      $s3, .LE008A268
/* 38C838 E008A248 0000882D */   daddu    $s1, $zero, $zero
.LE008A24C:
/* 38C83C E008A24C 0C022800 */  jal       func_E008A000
/* 38C840 E008A250 0200202D */   daddu    $a0, $s0, $zero
/* 38C844 E008A254 AE000030 */  sw        $zero, 0x30($s0)
/* 38C848 E008A258 26310001 */  addiu     $s1, $s1, 1
/* 38C84C E008A25C 0233102A */  slt       $v0, $s1, $s3
/* 38C850 E008A260 1440FFFA */  bnez      $v0, .LE008A24C
/* 38C854 E008A264 26100034 */   addiu    $s0, $s0, 0x34
.LE008A268:
/* 38C858 E008A268 0240102D */  daddu     $v0, $s2, $zero
/* 38C85C E008A26C 8FBF0038 */  lw        $ra, 0x38($sp)
/* 38C860 E008A270 8FB30034 */  lw        $s3, 0x34($sp)
/* 38C864 E008A274 8FB20030 */  lw        $s2, 0x30($sp)
/* 38C868 E008A278 8FB1002C */  lw        $s1, 0x2c($sp)
/* 38C86C E008A27C 8FB00028 */  lw        $s0, 0x28($sp)
/* 38C870 E008A280 03E00008 */  jr        $ra
/* 38C874 E008A284 27BD0040 */   addiu    $sp, $sp, 0x40
