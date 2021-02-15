.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DB8_E13518
/* E13518 80240DB8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E1351C 80240DBC AFB10014 */  sw        $s1, 0x14($sp)
/* E13520 80240DC0 0080882D */  daddu     $s1, $a0, $zero
/* E13524 80240DC4 0000202D */  daddu     $a0, $zero, $zero
/* E13528 80240DC8 AFBF0018 */  sw        $ra, 0x18($sp)
/* E1352C 80240DCC 0C00FB3A */  jal       get_enemy
/* E13530 80240DD0 AFB00010 */   sw       $s0, 0x10($sp)
/* E13534 80240DD4 0000282D */  daddu     $a1, $zero, $zero
/* E13538 80240DD8 24070003 */  addiu     $a3, $zero, 3
/* E1353C 80240DDC 8C460080 */  lw        $a2, 0x80($v0)
/* E13540 80240DE0 24040009 */  addiu     $a0, $zero, 9
/* E13544 80240DE4 00C0182D */  daddu     $v1, $a2, $zero
.L80240DE8:
/* E13548 80240DE8 8C62007C */  lw        $v0, 0x7c($v1)
/* E1354C 80240DEC 54470005 */  bnel      $v0, $a3, .L80240E04
/* E13550 80240DF0 24A50001 */   addiu    $a1, $a1, 1
/* E13554 80240DF4 8C620074 */  lw        $v0, 0x74($v1)
/* E13558 80240DF8 50440006 */  beql      $v0, $a0, .L80240E14
/* E1355C 80240DFC 0220202D */   daddu    $a0, $s1, $zero
/* E13560 80240E00 24A50001 */  addiu     $a1, $a1, 1
.L80240E04:
/* E13564 80240E04 28A2000B */  slti      $v0, $a1, 0xb
/* E13568 80240E08 1440FFF7 */  bnez      $v0, .L80240DE8
/* E1356C 80240E0C 2463005C */   addiu    $v1, $v1, 0x5c
/* E13570 80240E10 0220202D */  daddu     $a0, $s1, $zero
.L80240E14:
/* E13574 80240E14 00058040 */  sll       $s0, $a1, 1
/* E13578 80240E18 02058021 */  addu      $s0, $s0, $a1
/* E1357C 80240E1C 001080C0 */  sll       $s0, $s0, 3
/* E13580 80240E20 02058023 */  subu      $s0, $s0, $a1
/* E13584 80240E24 00108080 */  sll       $s0, $s0, 2
/* E13588 80240E28 00D08021 */  addu      $s0, $a2, $s0
/* E1358C 80240E2C 8E020084 */  lw        $v0, 0x84($s0)
/* E13590 80240E30 3C05FE36 */  lui       $a1, 0xfe36
/* E13594 80240E34 00021080 */  sll       $v0, $v0, 2
/* E13598 80240E38 3C018024 */  lui       $at, %hi(D_80241AEC_E1424C)
/* E1359C 80240E3C 00220821 */  addu      $at, $at, $v0
/* E135A0 80240E40 C4201AEC */  lwc1      $f0, %lo(D_80241AEC_E1424C)($at)
/* E135A4 80240E44 8E020084 */  lw        $v0, 0x84($s0)
/* E135A8 80240E48 8E060078 */  lw        $a2, 0x78($s0)
/* E135AC 80240E4C 00021080 */  sll       $v0, $v0, 2
/* E135B0 80240E50 E6000094 */  swc1      $f0, 0x94($s0)
/* E135B4 80240E54 3C018024 */  lui       $at, %hi(D_80241B18_E14278)
/* E135B8 80240E58 00220821 */  addu      $at, $at, $v0
/* E135BC 80240E5C C4221B18 */  lwc1      $f2, %lo(D_80241B18_E14278)($at)
/* E135C0 80240E60 3C0142DC */  lui       $at, 0x42dc
/* E135C4 80240E64 44810000 */  mtc1      $at, $f0
/* E135C8 80240E68 34A53C81 */  ori       $a1, $a1, 0x3c81
/* E135CC 80240E6C E600009C */  swc1      $f0, 0x9c($s0)
/* E135D0 80240E70 0C0B2026 */  jal       set_variable
/* E135D4 80240E74 E6020098 */   swc1     $f2, 0x98($s0)
/* E135D8 80240E78 0220202D */  daddu     $a0, $s1, $zero
/* E135DC 80240E7C 3C05FE36 */  lui       $a1, 0xfe36
/* E135E0 80240E80 8E060094 */  lw        $a2, 0x94($s0)
/* E135E4 80240E84 0C0B2190 */  jal       set_float_variable
/* E135E8 80240E88 34A53C85 */   ori      $a1, $a1, 0x3c85
/* E135EC 80240E8C 0220202D */  daddu     $a0, $s1, $zero
/* E135F0 80240E90 3C05FE36 */  lui       $a1, 0xfe36
/* E135F4 80240E94 8E060098 */  lw        $a2, 0x98($s0)
/* E135F8 80240E98 0C0B2190 */  jal       set_float_variable
/* E135FC 80240E9C 34A53C86 */   ori      $a1, $a1, 0x3c86
/* E13600 80240EA0 0220202D */  daddu     $a0, $s1, $zero
/* E13604 80240EA4 3C05FE36 */  lui       $a1, 0xfe36
/* E13608 80240EA8 8E06009C */  lw        $a2, 0x9c($s0)
/* E1360C 80240EAC 0C0B2190 */  jal       set_float_variable
/* E13610 80240EB0 34A53C87 */   ori      $a1, $a1, 0x3c87
/* E13614 80240EB4 8FBF0018 */  lw        $ra, 0x18($sp)
/* E13618 80240EB8 8FB10014 */  lw        $s1, 0x14($sp)
/* E1361C 80240EBC 8FB00010 */  lw        $s0, 0x10($sp)
/* E13620 80240EC0 24020002 */  addiu     $v0, $zero, 2
/* E13624 80240EC4 03E00008 */  jr        $ra
/* E13628 80240EC8 27BD0020 */   addiu    $sp, $sp, 0x20
