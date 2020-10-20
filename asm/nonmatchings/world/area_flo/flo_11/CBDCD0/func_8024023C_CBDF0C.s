.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024023C_CBDF0C
/* CBDF0C 8024023C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CBDF10 80240240 AFB00018 */  sw        $s0, 0x18($sp)
/* CBDF14 80240244 0080802D */  daddu     $s0, $a0, $zero
/* CBDF18 80240248 AFBF001C */  sw        $ra, 0x1c($sp)
/* CBDF1C 8024024C F7B40020 */  sdc1      $f20, 0x20($sp)
/* CBDF20 80240250 8E02000C */  lw        $v0, 0xc($s0)
/* CBDF24 80240254 0C0B210B */  jal       get_float_variable
/* CBDF28 80240258 8C450000 */   lw       $a1, ($v0)
/* CBDF2C 8024025C 27A40010 */  addiu     $a0, $sp, 0x10
/* CBDF30 80240260 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* CBDF34 80240264 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* CBDF38 80240268 44060000 */  mfc1      $a2, $f0
/* CBDF3C 8024026C C4400028 */  lwc1      $f0, 0x28($v0)
/* CBDF40 80240270 C4420030 */  lwc1      $f2, 0x30($v0)
/* CBDF44 80240274 E7A00010 */  swc1      $f0, 0x10($sp)
/* CBDF48 80240278 E7A20014 */  swc1      $f2, 0x14($sp)
/* CBDF4C 8024027C 8C470080 */  lw        $a3, 0x80($v0)
/* CBDF50 80240280 C454002C */  lwc1      $f20, 0x2c($v0)
/* CBDF54 80240284 0C00A7E7 */  jal       add_vec2D_polar
/* CBDF58 80240288 27A50014 */   addiu    $a1, $sp, 0x14
/* CBDF5C 8024028C 0200202D */  daddu     $a0, $s0, $zero
/* CBDF60 80240290 3C05FE36 */  lui       $a1, 0xfe36
/* CBDF64 80240294 8FA60010 */  lw        $a2, 0x10($sp)
/* CBDF68 80240298 0C0B2190 */  jal       set_float_variable
/* CBDF6C 8024029C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* CBDF70 802402A0 0200202D */  daddu     $a0, $s0, $zero
/* CBDF74 802402A4 3C05FE36 */  lui       $a1, 0xfe36
/* CBDF78 802402A8 4406A000 */  mfc1      $a2, $f20
/* CBDF7C 802402AC 0C0B2190 */  jal       set_float_variable
/* CBDF80 802402B0 34A53C81 */   ori      $a1, $a1, 0x3c81
/* CBDF84 802402B4 0200202D */  daddu     $a0, $s0, $zero
/* CBDF88 802402B8 3C05FE36 */  lui       $a1, 0xfe36
/* CBDF8C 802402BC 8FA60014 */  lw        $a2, 0x14($sp)
/* CBDF90 802402C0 0C0B2190 */  jal       set_float_variable
/* CBDF94 802402C4 34A53C82 */   ori      $a1, $a1, 0x3c82
/* CBDF98 802402C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* CBDF9C 802402CC 8FB00018 */  lw        $s0, 0x18($sp)
/* CBDFA0 802402D0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* CBDFA4 802402D4 24020002 */  addiu     $v0, $zero, 2
/* CBDFA8 802402D8 03E00008 */  jr        $ra
/* CBDFAC 802402DC 27BD0028 */   addiu    $sp, $sp, 0x28
