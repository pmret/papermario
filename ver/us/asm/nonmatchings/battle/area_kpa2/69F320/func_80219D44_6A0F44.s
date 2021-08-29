.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219D44_6A0F44
/* 6A0F44 80219D44 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6A0F48 80219D48 AFB20018 */  sw        $s2, 0x18($sp)
/* 6A0F4C 80219D4C 0080902D */  daddu     $s2, $a0, $zero
/* 6A0F50 80219D50 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6A0F54 80219D54 AFB10014 */  sw        $s1, 0x14($sp)
/* 6A0F58 80219D58 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A0F5C 80219D5C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 6A0F60 80219D60 10A00044 */  beqz      $a1, .L80219E74
/* 6A0F64 80219D64 8E50000C */   lw       $s0, 0xc($s2)
/* 6A0F68 80219D68 0C00AB39 */  jal       heap_malloc
/* 6A0F6C 80219D6C 24040024 */   addiu    $a0, $zero, 0x24
/* 6A0F70 80219D70 0040882D */  daddu     $s1, $v0, $zero
/* 6A0F74 80219D74 AE510070 */  sw        $s1, 0x70($s2)
/* 6A0F78 80219D78 8E050000 */  lw        $a1, ($s0)
/* 6A0F7C 80219D7C 26100004 */  addiu     $s0, $s0, 4
/* 6A0F80 80219D80 0C0B1EAF */  jal       evt_get_variable
/* 6A0F84 80219D84 0240202D */   daddu    $a0, $s2, $zero
/* 6A0F88 80219D88 AE220020 */  sw        $v0, 0x20($s1)
/* 6A0F8C 80219D8C 8E050000 */  lw        $a1, ($s0)
/* 6A0F90 80219D90 26100004 */  addiu     $s0, $s0, 4
/* 6A0F94 80219D94 0C0B210B */  jal       evt_get_float_variable
/* 6A0F98 80219D98 0240202D */   daddu    $a0, $s2, $zero
/* 6A0F9C 80219D9C E6200000 */  swc1      $f0, ($s1)
/* 6A0FA0 80219DA0 8E050000 */  lw        $a1, ($s0)
/* 6A0FA4 80219DA4 26100004 */  addiu     $s0, $s0, 4
/* 6A0FA8 80219DA8 0C0B210B */  jal       evt_get_float_variable
/* 6A0FAC 80219DAC 0240202D */   daddu    $a0, $s2, $zero
/* 6A0FB0 80219DB0 E6200004 */  swc1      $f0, 4($s1)
/* 6A0FB4 80219DB4 8E050000 */  lw        $a1, ($s0)
/* 6A0FB8 80219DB8 26100004 */  addiu     $s0, $s0, 4
/* 6A0FBC 80219DBC 0C0B210B */  jal       evt_get_float_variable
/* 6A0FC0 80219DC0 0240202D */   daddu    $a0, $s2, $zero
/* 6A0FC4 80219DC4 E6200008 */  swc1      $f0, 8($s1)
/* 6A0FC8 80219DC8 8E050000 */  lw        $a1, ($s0)
/* 6A0FCC 80219DCC 26100004 */  addiu     $s0, $s0, 4
/* 6A0FD0 80219DD0 0C0B1EAF */  jal       evt_get_variable
/* 6A0FD4 80219DD4 0240202D */   daddu    $a0, $s2, $zero
/* 6A0FD8 80219DD8 AE22001C */  sw        $v0, 0x1c($s1)
/* 6A0FDC 80219DDC 8E050000 */  lw        $a1, ($s0)
/* 6A0FE0 80219DE0 0C0B210B */  jal       evt_get_float_variable
/* 6A0FE4 80219DE4 0240202D */   daddu    $a0, $s2, $zero
/* 6A0FE8 80219DE8 8E240020 */  lw        $a0, 0x20($s1)
/* 6A0FEC 80219DEC 0C04C3D6 */  jal       get_item_entity
/* 6A0FF0 80219DF0 E6200010 */   swc1     $f0, 0x10($s1)
/* 6A0FF4 80219DF4 0040802D */  daddu     $s0, $v0, $zero
/* 6A0FF8 80219DF8 C60C0008 */  lwc1      $f12, 8($s0)
/* 6A0FFC 80219DFC C60E0010 */  lwc1      $f14, 0x10($s0)
/* 6A1000 80219E00 8E260000 */  lw        $a2, ($s1)
/* 6A1004 80219E04 0C00A7B5 */  jal       dist2D
/* 6A1008 80219E08 8E270008 */   lw       $a3, 8($s1)
/* 6A100C 80219E0C C60C0008 */  lwc1      $f12, 8($s0)
/* 6A1010 80219E10 C60E0010 */  lwc1      $f14, 0x10($s0)
/* 6A1014 80219E14 8E260000 */  lw        $a2, ($s1)
/* 6A1018 80219E18 8E270008 */  lw        $a3, 8($s1)
/* 6A101C 80219E1C 0C00A720 */  jal       atan2
/* 6A1020 80219E20 46000506 */   mov.s    $f20, $f0
/* 6A1024 80219E24 C6240010 */  lwc1      $f4, 0x10($s1)
/* 6A1028 80219E28 C626001C */  lwc1      $f6, 0x1c($s1)
/* 6A102C 80219E2C 468031A0 */  cvt.s.w   $f6, $f6
/* 6A1030 80219E30 46062102 */  mul.s     $f4, $f4, $f6
/* 6A1034 80219E34 00000000 */  nop
/* 6A1038 80219E38 3C013F00 */  lui       $at, 0x3f00
/* 6A103C 80219E3C 44811000 */  mtc1      $at, $f2
/* 6A1040 80219E40 00000000 */  nop
/* 6A1044 80219E44 46022102 */  mul.s     $f4, $f4, $f2
/* 6A1048 80219E48 00000000 */  nop
/* 6A104C 80219E4C E620000C */  swc1      $f0, 0xc($s1)
/* 6A1050 80219E50 C6200004 */  lwc1      $f0, 4($s1)
/* 6A1054 80219E54 C602000C */  lwc1      $f2, 0xc($s0)
/* 6A1058 80219E58 46020001 */  sub.s     $f0, $f0, $f2
/* 6A105C 80219E5C 46003086 */  mov.s     $f2, $f6
/* 6A1060 80219E60 46060003 */  div.s     $f0, $f0, $f6
/* 6A1064 80219E64 46002100 */  add.s     $f4, $f4, $f0
/* 6A1068 80219E68 4602A503 */  div.s     $f20, $f20, $f2
/* 6A106C 80219E6C E6340014 */  swc1      $f20, 0x14($s1)
/* 6A1070 80219E70 E6240018 */  swc1      $f4, 0x18($s1)
.L80219E74:
/* 6A1074 80219E74 8E510070 */  lw        $s1, 0x70($s2)
/* 6A1078 80219E78 0C04C3D6 */  jal       get_item_entity
/* 6A107C 80219E7C 8E240020 */   lw       $a0, 0x20($s1)
/* 6A1080 80219E80 0040802D */  daddu     $s0, $v0, $zero
/* 6A1084 80219E84 16000005 */  bnez      $s0, .L80219E9C
/* 6A1088 80219E88 00000000 */   nop
/* 6A108C 80219E8C 0C00AB4B */  jal       heap_free
/* 6A1090 80219E90 8E440070 */   lw       $a0, 0x70($s2)
/* 6A1094 80219E94 080867D0 */  j         .L80219F40
/* 6A1098 80219E98 24020002 */   addiu    $v0, $zero, 2
.L80219E9C:
/* 6A109C 80219E9C C62C000C */  lwc1      $f12, 0xc($s1)
/* 6A10A0 80219EA0 0C00A8BB */  jal       sin_deg
/* 6A10A4 80219EA4 00000000 */   nop
/* 6A10A8 80219EA8 C6220014 */  lwc1      $f2, 0x14($s1)
/* 6A10AC 80219EAC 46001082 */  mul.s     $f2, $f2, $f0
/* 6A10B0 80219EB0 00000000 */  nop
/* 6A10B4 80219EB4 C6000008 */  lwc1      $f0, 8($s0)
/* 6A10B8 80219EB8 46020000 */  add.s     $f0, $f0, $f2
/* 6A10BC 80219EBC E6000008 */  swc1      $f0, 8($s0)
/* 6A10C0 80219EC0 0C00A8D4 */  jal       cos_deg
/* 6A10C4 80219EC4 C62C000C */   lwc1     $f12, 0xc($s1)
/* 6A10C8 80219EC8 C6220014 */  lwc1      $f2, 0x14($s1)
/* 6A10CC 80219ECC 46001082 */  mul.s     $f2, $f2, $f0
/* 6A10D0 80219ED0 00000000 */  nop
/* 6A10D4 80219ED4 C6000010 */  lwc1      $f0, 0x10($s0)
/* 6A10D8 80219ED8 46020001 */  sub.s     $f0, $f0, $f2
/* 6A10DC 80219EDC E6000010 */  swc1      $f0, 0x10($s0)
/* 6A10E0 80219EE0 C600000C */  lwc1      $f0, 0xc($s0)
/* 6A10E4 80219EE4 C6220018 */  lwc1      $f2, 0x18($s1)
/* 6A10E8 80219EE8 46020000 */  add.s     $f0, $f0, $f2
/* 6A10EC 80219EEC E600000C */  swc1      $f0, 0xc($s0)
/* 6A10F0 80219EF0 C6200018 */  lwc1      $f0, 0x18($s1)
/* 6A10F4 80219EF4 C6220010 */  lwc1      $f2, 0x10($s1)
/* 6A10F8 80219EF8 8E22001C */  lw        $v0, 0x1c($s1)
/* 6A10FC 80219EFC 46020001 */  sub.s     $f0, $f0, $f2
/* 6A1100 80219F00 2442FFFF */  addiu     $v0, $v0, -1
/* 6A1104 80219F04 AE22001C */  sw        $v0, 0x1c($s1)
/* 6A1108 80219F08 04400003 */  bltz      $v0, .L80219F18
/* 6A110C 80219F0C E6200018 */   swc1     $f0, 0x18($s1)
/* 6A1110 80219F10 080867D0 */  j         .L80219F40
/* 6A1114 80219F14 0000102D */   daddu    $v0, $zero, $zero
.L80219F18:
/* 6A1118 80219F18 C6200000 */  lwc1      $f0, ($s1)
/* 6A111C 80219F1C E6000008 */  swc1      $f0, 8($s0)
/* 6A1120 80219F20 C6200004 */  lwc1      $f0, 4($s1)
/* 6A1124 80219F24 E600000C */  swc1      $f0, 0xc($s0)
/* 6A1128 80219F28 C6200008 */  lwc1      $f0, 8($s1)
/* 6A112C 80219F2C E6000010 */  swc1      $f0, 0x10($s0)
/* 6A1130 80219F30 AE200018 */  sw        $zero, 0x18($s1)
/* 6A1134 80219F34 0C00AB4B */  jal       heap_free
/* 6A1138 80219F38 8E440070 */   lw       $a0, 0x70($s2)
/* 6A113C 80219F3C 24020001 */  addiu     $v0, $zero, 1
.L80219F40:
/* 6A1140 80219F40 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6A1144 80219F44 8FB20018 */  lw        $s2, 0x18($sp)
/* 6A1148 80219F48 8FB10014 */  lw        $s1, 0x14($sp)
/* 6A114C 80219F4C 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A1150 80219F50 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 6A1154 80219F54 03E00008 */  jr        $ra
/* 6A1158 80219F58 27BD0028 */   addiu    $sp, $sp, 0x28
