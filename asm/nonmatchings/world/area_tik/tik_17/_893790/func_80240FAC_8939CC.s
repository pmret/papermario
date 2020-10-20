.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FAC_8939CC
/* 8939CC 80240FAC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8939D0 80240FB0 AFB00018 */  sw        $s0, 0x18($sp)
/* 8939D4 80240FB4 0080802D */  daddu     $s0, $a0, $zero
/* 8939D8 80240FB8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8939DC 80240FBC F7B40020 */  sdc1      $f20, 0x20($sp)
/* 8939E0 80240FC0 8E02000C */  lw        $v0, 0xc($s0)
/* 8939E4 80240FC4 0C0B210B */  jal       get_float_variable
/* 8939E8 80240FC8 8C450000 */   lw       $a1, ($v0)
/* 8939EC 80240FCC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8939F0 80240FD0 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 8939F4 80240FD4 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 8939F8 80240FD8 44060000 */  mfc1      $a2, $f0
/* 8939FC 80240FDC C4400028 */  lwc1      $f0, 0x28($v0)
/* 893A00 80240FE0 C4420030 */  lwc1      $f2, 0x30($v0)
/* 893A04 80240FE4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 893A08 80240FE8 E7A20014 */  swc1      $f2, 0x14($sp)
/* 893A0C 80240FEC 8C470080 */  lw        $a3, 0x80($v0)
/* 893A10 80240FF0 C454002C */  lwc1      $f20, 0x2c($v0)
/* 893A14 80240FF4 0C00A7E7 */  jal       add_vec2D_polar
/* 893A18 80240FF8 27A50014 */   addiu    $a1, $sp, 0x14
/* 893A1C 80240FFC 0200202D */  daddu     $a0, $s0, $zero
/* 893A20 80241000 3C05FE36 */  lui       $a1, 0xfe36
/* 893A24 80241004 8FA60010 */  lw        $a2, 0x10($sp)
/* 893A28 80241008 0C0B2190 */  jal       set_float_variable
/* 893A2C 8024100C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 893A30 80241010 0200202D */  daddu     $a0, $s0, $zero
/* 893A34 80241014 3C05FE36 */  lui       $a1, 0xfe36
/* 893A38 80241018 4406A000 */  mfc1      $a2, $f20
/* 893A3C 8024101C 0C0B2190 */  jal       set_float_variable
/* 893A40 80241020 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 893A44 80241024 0200202D */  daddu     $a0, $s0, $zero
/* 893A48 80241028 3C05FE36 */  lui       $a1, 0xfe36
/* 893A4C 8024102C 8FA60014 */  lw        $a2, 0x14($sp)
/* 893A50 80241030 0C0B2190 */  jal       set_float_variable
/* 893A54 80241034 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 893A58 80241038 8FBF001C */  lw        $ra, 0x1c($sp)
/* 893A5C 8024103C 8FB00018 */  lw        $s0, 0x18($sp)
/* 893A60 80241040 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 893A64 80241044 24020002 */  addiu     $v0, $zero, 2
/* 893A68 80241048 03E00008 */  jr        $ra
/* 893A6C 8024104C 27BD0028 */   addiu    $sp, $sp, 0x28
