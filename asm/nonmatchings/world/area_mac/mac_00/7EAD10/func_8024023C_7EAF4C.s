.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024023C_7EAF4C
/* 7EAF4C 8024023C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7EAF50 80240240 AFB00018 */  sw        $s0, 0x18($sp)
/* 7EAF54 80240244 0080802D */  daddu     $s0, $a0, $zero
/* 7EAF58 80240248 AFBF001C */  sw        $ra, 0x1c($sp)
/* 7EAF5C 8024024C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 7EAF60 80240250 8E02000C */  lw        $v0, 0xc($s0)
/* 7EAF64 80240254 0C0B210B */  jal       get_float_variable
/* 7EAF68 80240258 8C450000 */   lw       $a1, ($v0)
/* 7EAF6C 8024025C 27A40010 */  addiu     $a0, $sp, 0x10
/* 7EAF70 80240260 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 7EAF74 80240264 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 7EAF78 80240268 44060000 */  mfc1      $a2, $f0
/* 7EAF7C 8024026C C4400028 */  lwc1      $f0, 0x28($v0)
/* 7EAF80 80240270 C4420030 */  lwc1      $f2, 0x30($v0)
/* 7EAF84 80240274 E7A00010 */  swc1      $f0, 0x10($sp)
/* 7EAF88 80240278 E7A20014 */  swc1      $f2, 0x14($sp)
/* 7EAF8C 8024027C 8C470080 */  lw        $a3, 0x80($v0)
/* 7EAF90 80240280 C454002C */  lwc1      $f20, 0x2c($v0)
/* 7EAF94 80240284 0C00A7E7 */  jal       add_vec2D_polar
/* 7EAF98 80240288 27A50014 */   addiu    $a1, $sp, 0x14
/* 7EAF9C 8024028C 0200202D */  daddu     $a0, $s0, $zero
/* 7EAFA0 80240290 3C05FE36 */  lui       $a1, 0xfe36
/* 7EAFA4 80240294 8FA60010 */  lw        $a2, 0x10($sp)
/* 7EAFA8 80240298 0C0B2190 */  jal       set_float_variable
/* 7EAFAC 8024029C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 7EAFB0 802402A0 0200202D */  daddu     $a0, $s0, $zero
/* 7EAFB4 802402A4 3C05FE36 */  lui       $a1, 0xfe36
/* 7EAFB8 802402A8 4406A000 */  mfc1      $a2, $f20
/* 7EAFBC 802402AC 0C0B2190 */  jal       set_float_variable
/* 7EAFC0 802402B0 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 7EAFC4 802402B4 0200202D */  daddu     $a0, $s0, $zero
/* 7EAFC8 802402B8 3C05FE36 */  lui       $a1, 0xfe36
/* 7EAFCC 802402BC 8FA60014 */  lw        $a2, 0x14($sp)
/* 7EAFD0 802402C0 0C0B2190 */  jal       set_float_variable
/* 7EAFD4 802402C4 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 7EAFD8 802402C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7EAFDC 802402CC 8FB00018 */  lw        $s0, 0x18($sp)
/* 7EAFE0 802402D0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 7EAFE4 802402D4 24020002 */  addiu     $v0, $zero, 2
/* 7EAFE8 802402D8 03E00008 */  jr        $ra
/* 7EAFEC 802402DC 27BD0028 */   addiu    $sp, $sp, 0x28
