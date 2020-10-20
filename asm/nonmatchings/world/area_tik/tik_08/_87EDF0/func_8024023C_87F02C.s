.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024023C_87F02C
/* 87F02C 8024023C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 87F030 80240240 AFB00018 */  sw        $s0, 0x18($sp)
/* 87F034 80240244 0080802D */  daddu     $s0, $a0, $zero
/* 87F038 80240248 AFBF001C */  sw        $ra, 0x1c($sp)
/* 87F03C 8024024C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 87F040 80240250 8E02000C */  lw        $v0, 0xc($s0)
/* 87F044 80240254 0C0B210B */  jal       get_float_variable
/* 87F048 80240258 8C450000 */   lw       $a1, ($v0)
/* 87F04C 8024025C 27A40010 */  addiu     $a0, $sp, 0x10
/* 87F050 80240260 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 87F054 80240264 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 87F058 80240268 44060000 */  mfc1      $a2, $f0
/* 87F05C 8024026C C4400028 */  lwc1      $f0, 0x28($v0)
/* 87F060 80240270 C4420030 */  lwc1      $f2, 0x30($v0)
/* 87F064 80240274 E7A00010 */  swc1      $f0, 0x10($sp)
/* 87F068 80240278 E7A20014 */  swc1      $f2, 0x14($sp)
/* 87F06C 8024027C 8C470080 */  lw        $a3, 0x80($v0)
/* 87F070 80240280 C454002C */  lwc1      $f20, 0x2c($v0)
/* 87F074 80240284 0C00A7E7 */  jal       add_vec2D_polar
/* 87F078 80240288 27A50014 */   addiu    $a1, $sp, 0x14
/* 87F07C 8024028C 0200202D */  daddu     $a0, $s0, $zero
/* 87F080 80240290 3C05FE36 */  lui       $a1, 0xfe36
/* 87F084 80240294 8FA60010 */  lw        $a2, 0x10($sp)
/* 87F088 80240298 0C0B2190 */  jal       set_float_variable
/* 87F08C 8024029C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 87F090 802402A0 0200202D */  daddu     $a0, $s0, $zero
/* 87F094 802402A4 3C05FE36 */  lui       $a1, 0xfe36
/* 87F098 802402A8 4406A000 */  mfc1      $a2, $f20
/* 87F09C 802402AC 0C0B2190 */  jal       set_float_variable
/* 87F0A0 802402B0 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 87F0A4 802402B4 0200202D */  daddu     $a0, $s0, $zero
/* 87F0A8 802402B8 3C05FE36 */  lui       $a1, 0xfe36
/* 87F0AC 802402BC 8FA60014 */  lw        $a2, 0x14($sp)
/* 87F0B0 802402C0 0C0B2190 */  jal       set_float_variable
/* 87F0B4 802402C4 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 87F0B8 802402C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 87F0BC 802402CC 8FB00018 */  lw        $s0, 0x18($sp)
/* 87F0C0 802402D0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 87F0C4 802402D4 24020002 */  addiu     $v0, $zero, 2
/* 87F0C8 802402D8 03E00008 */  jr        $ra
/* 87F0CC 802402DC 27BD0028 */   addiu    $sp, $sp, 0x28
