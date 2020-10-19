.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242E78_C742F8
/* C742F8 80242E78 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C742FC 80242E7C AFB3003C */  sw        $s3, 0x3c($sp)
/* C74300 80242E80 0080982D */  daddu     $s3, $a0, $zero
/* C74304 80242E84 AFBF0040 */  sw        $ra, 0x40($sp)
/* C74308 80242E88 AFB20038 */  sw        $s2, 0x38($sp)
/* C7430C 80242E8C AFB10034 */  sw        $s1, 0x34($sp)
/* C74310 80242E90 AFB00030 */  sw        $s0, 0x30($sp)
/* C74314 80242E94 8E720148 */  lw        $s2, 0x148($s3)
/* C74318 80242E98 00A0882D */  daddu     $s1, $a1, $zero
/* C7431C 80242E9C 86440008 */  lh        $a0, 8($s2)
/* C74320 80242EA0 0C00EABB */  jal       get_npc_unsafe
/* C74324 80242EA4 00C0802D */   daddu    $s0, $a2, $zero
/* C74328 80242EA8 0200202D */  daddu     $a0, $s0, $zero
/* C7432C 80242EAC 0240282D */  daddu     $a1, $s2, $zero
/* C74330 80242EB0 AFA00010 */  sw        $zero, 0x10($sp)
/* C74334 80242EB4 8E26000C */  lw        $a2, 0xc($s1)
/* C74338 80242EB8 8E270010 */  lw        $a3, 0x10($s1)
/* C7433C 80242EBC 0C01242D */  jal       func_800490B4
/* C74340 80242EC0 0040882D */   daddu    $s1, $v0, $zero
/* C74344 80242EC4 10400024 */  beqz      $v0, .L80242F58
/* C74348 80242EC8 0220202D */   daddu    $a0, $s1, $zero
/* C7434C 80242ECC 24050322 */  addiu     $a1, $zero, 0x322
/* C74350 80242ED0 0C012530 */  jal       func_800494C0
/* C74354 80242ED4 0000302D */   daddu    $a2, $zero, $zero
/* C74358 80242ED8 0000202D */  daddu     $a0, $zero, $zero
/* C7435C 80242EDC 0220282D */  daddu     $a1, $s1, $zero
/* C74360 80242EE0 0000302D */  daddu     $a2, $zero, $zero
/* C74364 80242EE4 2410000A */  addiu     $s0, $zero, 0xa
/* C74368 80242EE8 862300A8 */  lh        $v1, 0xa8($s1)
/* C7436C 80242EEC 3C013F80 */  lui       $at, 0x3f80
/* C74370 80242EF0 44810000 */  mtc1      $at, $f0
/* C74374 80242EF4 3C014000 */  lui       $at, 0x4000
/* C74378 80242EF8 44811000 */  mtc1      $at, $f2
/* C7437C 80242EFC 3C01C1A0 */  lui       $at, 0xc1a0
/* C74380 80242F00 44812000 */  mtc1      $at, $f4
/* C74384 80242F04 44833000 */  mtc1      $v1, $f6
/* C74388 80242F08 00000000 */  nop       
/* C7438C 80242F0C 468031A0 */  cvt.s.w   $f6, $f6
/* C74390 80242F10 44073000 */  mfc1      $a3, $f6
/* C74394 80242F14 27A20028 */  addiu     $v0, $sp, 0x28
/* C74398 80242F18 AFB0001C */  sw        $s0, 0x1c($sp)
/* C7439C 80242F1C AFA20020 */  sw        $v0, 0x20($sp)
/* C743A0 80242F20 E7A00010 */  swc1      $f0, 0x10($sp)
/* C743A4 80242F24 E7A20014 */  swc1      $f2, 0x14($sp)
/* C743A8 80242F28 0C01BFA4 */  jal       fx_emote
/* C743AC 80242F2C E7A40018 */   swc1     $f4, 0x18($sp)
/* C743B0 80242F30 0220202D */  daddu     $a0, $s1, $zero
/* C743B4 80242F34 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C743B8 80242F38 0C012530 */  jal       func_800494C0
/* C743BC 80242F3C 3C060020 */   lui      $a2, 0x20
/* C743C0 80242F40 8E4200CC */  lw        $v0, 0xcc($s2)
/* C743C4 80242F44 8C420020 */  lw        $v0, 0x20($v0)
/* C743C8 80242F48 AE220028 */  sw        $v0, 0x28($s1)
/* C743CC 80242F4C 9642008E */  lhu       $v0, 0x8e($s2)
/* C743D0 80242F50 A622008E */  sh        $v0, 0x8e($s1)
/* C743D4 80242F54 AE700070 */  sw        $s0, 0x70($s3)
.L80242F58:
/* C743D8 80242F58 8FBF0040 */  lw        $ra, 0x40($sp)
/* C743DC 80242F5C 8FB3003C */  lw        $s3, 0x3c($sp)
/* C743E0 80242F60 8FB20038 */  lw        $s2, 0x38($sp)
/* C743E4 80242F64 8FB10034 */  lw        $s1, 0x34($sp)
/* C743E8 80242F68 8FB00030 */  lw        $s0, 0x30($sp)
/* C743EC 80242F6C 03E00008 */  jr        $ra
/* C743F0 80242F70 27BD0048 */   addiu    $sp, $sp, 0x48
