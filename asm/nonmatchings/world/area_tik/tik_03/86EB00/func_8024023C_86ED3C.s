.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024023C_86ED3C
/* 86ED3C 8024023C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 86ED40 80240240 AFB00018 */  sw        $s0, 0x18($sp)
/* 86ED44 80240244 0080802D */  daddu     $s0, $a0, $zero
/* 86ED48 80240248 AFBF001C */  sw        $ra, 0x1c($sp)
/* 86ED4C 8024024C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 86ED50 80240250 8E02000C */  lw        $v0, 0xc($s0)
/* 86ED54 80240254 0C0B210B */  jal       get_float_variable
/* 86ED58 80240258 8C450000 */   lw       $a1, ($v0)
/* 86ED5C 8024025C 27A40010 */  addiu     $a0, $sp, 0x10
/* 86ED60 80240260 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 86ED64 80240264 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 86ED68 80240268 44060000 */  mfc1      $a2, $f0
/* 86ED6C 8024026C C4400028 */  lwc1      $f0, 0x28($v0)
/* 86ED70 80240270 C4420030 */  lwc1      $f2, 0x30($v0)
/* 86ED74 80240274 E7A00010 */  swc1      $f0, 0x10($sp)
/* 86ED78 80240278 E7A20014 */  swc1      $f2, 0x14($sp)
/* 86ED7C 8024027C 8C470080 */  lw        $a3, 0x80($v0)
/* 86ED80 80240280 C454002C */  lwc1      $f20, 0x2c($v0)
/* 86ED84 80240284 0C00A7E7 */  jal       add_vec2D_polar
/* 86ED88 80240288 27A50014 */   addiu    $a1, $sp, 0x14
/* 86ED8C 8024028C 0200202D */  daddu     $a0, $s0, $zero
/* 86ED90 80240290 3C05FE36 */  lui       $a1, 0xfe36
/* 86ED94 80240294 8FA60010 */  lw        $a2, 0x10($sp)
/* 86ED98 80240298 0C0B2190 */  jal       set_float_variable
/* 86ED9C 8024029C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 86EDA0 802402A0 0200202D */  daddu     $a0, $s0, $zero
/* 86EDA4 802402A4 3C05FE36 */  lui       $a1, 0xfe36
/* 86EDA8 802402A8 4406A000 */  mfc1      $a2, $f20
/* 86EDAC 802402AC 0C0B2190 */  jal       set_float_variable
/* 86EDB0 802402B0 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 86EDB4 802402B4 0200202D */  daddu     $a0, $s0, $zero
/* 86EDB8 802402B8 3C05FE36 */  lui       $a1, 0xfe36
/* 86EDBC 802402BC 8FA60014 */  lw        $a2, 0x14($sp)
/* 86EDC0 802402C0 0C0B2190 */  jal       set_float_variable
/* 86EDC4 802402C4 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 86EDC8 802402C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 86EDCC 802402CC 8FB00018 */  lw        $s0, 0x18($sp)
/* 86EDD0 802402D0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 86EDD4 802402D4 24020002 */  addiu     $v0, $zero, 2
/* 86EDD8 802402D8 03E00008 */  jr        $ra
/* 86EDDC 802402DC 27BD0028 */   addiu    $sp, $sp, 0x28
