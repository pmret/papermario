.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024026C
/* 8EC08C 8024026C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8EC090 80240270 AFB00018 */  sw        $s0, 0x18($sp)
/* 8EC094 80240274 0080802D */  daddu     $s0, $a0, $zero
/* 8EC098 80240278 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8EC09C 8024027C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 8EC0A0 80240280 8E02000C */  lw        $v0, 0xc($s0)
/* 8EC0A4 80240284 0C0B210B */  jal       get_float_variable
/* 8EC0A8 80240288 8C450000 */   lw       $a1, ($v0)
/* 8EC0AC 8024028C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8EC0B0 80240290 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 8EC0B4 80240294 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 8EC0B8 80240298 44060000 */  mfc1      $a2, $f0
/* 8EC0BC 8024029C C4400028 */  lwc1      $f0, 0x28($v0)
/* 8EC0C0 802402A0 C4420030 */  lwc1      $f2, 0x30($v0)
/* 8EC0C4 802402A4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8EC0C8 802402A8 E7A20014 */  swc1      $f2, 0x14($sp)
/* 8EC0CC 802402AC 8C470080 */  lw        $a3, 0x80($v0)
/* 8EC0D0 802402B0 C454002C */  lwc1      $f20, 0x2c($v0)
/* 8EC0D4 802402B4 0C00A7E7 */  jal       add_vec2D_polar
/* 8EC0D8 802402B8 27A50014 */   addiu    $a1, $sp, 0x14
/* 8EC0DC 802402BC 0200202D */  daddu     $a0, $s0, $zero
/* 8EC0E0 802402C0 3C05FE36 */  lui       $a1, 0xfe36
/* 8EC0E4 802402C4 8FA60010 */  lw        $a2, 0x10($sp)
/* 8EC0E8 802402C8 0C0B2190 */  jal       set_float_variable
/* 8EC0EC 802402CC 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 8EC0F0 802402D0 0200202D */  daddu     $a0, $s0, $zero
/* 8EC0F4 802402D4 3C05FE36 */  lui       $a1, 0xfe36
/* 8EC0F8 802402D8 4406A000 */  mfc1      $a2, $f20
/* 8EC0FC 802402DC 0C0B2190 */  jal       set_float_variable
/* 8EC100 802402E0 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 8EC104 802402E4 0200202D */  daddu     $a0, $s0, $zero
/* 8EC108 802402E8 3C05FE36 */  lui       $a1, 0xfe36
/* 8EC10C 802402EC 8FA60014 */  lw        $a2, 0x14($sp)
/* 8EC110 802402F0 0C0B2190 */  jal       set_float_variable
/* 8EC114 802402F4 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 8EC118 802402F8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8EC11C 802402FC 8FB00018 */  lw        $s0, 0x18($sp)
/* 8EC120 80240300 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 8EC124 80240304 24020002 */  addiu     $v0, $zero, 2
/* 8EC128 80240308 03E00008 */  jr        $ra
/* 8EC12C 8024030C 27BD0028 */   addiu    $sp, $sp, 0x28
