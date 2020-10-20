.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024023C_E1E69C
/* E1E69C 8024023C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E1E6A0 80240240 AFB00018 */  sw        $s0, 0x18($sp)
/* E1E6A4 80240244 0080802D */  daddu     $s0, $a0, $zero
/* E1E6A8 80240248 AFBF001C */  sw        $ra, 0x1c($sp)
/* E1E6AC 8024024C F7B40020 */  sdc1      $f20, 0x20($sp)
/* E1E6B0 80240250 8E02000C */  lw        $v0, 0xc($s0)
/* E1E6B4 80240254 0C0B210B */  jal       get_float_variable
/* E1E6B8 80240258 8C450000 */   lw       $a1, ($v0)
/* E1E6BC 8024025C 27A40010 */  addiu     $a0, $sp, 0x10
/* E1E6C0 80240260 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* E1E6C4 80240264 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* E1E6C8 80240268 44060000 */  mfc1      $a2, $f0
/* E1E6CC 8024026C C4400028 */  lwc1      $f0, 0x28($v0)
/* E1E6D0 80240270 C4420030 */  lwc1      $f2, 0x30($v0)
/* E1E6D4 80240274 E7A00010 */  swc1      $f0, 0x10($sp)
/* E1E6D8 80240278 E7A20014 */  swc1      $f2, 0x14($sp)
/* E1E6DC 8024027C 8C470080 */  lw        $a3, 0x80($v0)
/* E1E6E0 80240280 C454002C */  lwc1      $f20, 0x2c($v0)
/* E1E6E4 80240284 0C00A7E7 */  jal       add_vec2D_polar
/* E1E6E8 80240288 27A50014 */   addiu    $a1, $sp, 0x14
/* E1E6EC 8024028C 0200202D */  daddu     $a0, $s0, $zero
/* E1E6F0 80240290 3C05FE36 */  lui       $a1, 0xfe36
/* E1E6F4 80240294 8FA60010 */  lw        $a2, 0x10($sp)
/* E1E6F8 80240298 0C0B2190 */  jal       set_float_variable
/* E1E6FC 8024029C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* E1E700 802402A0 0200202D */  daddu     $a0, $s0, $zero
/* E1E704 802402A4 3C05FE36 */  lui       $a1, 0xfe36
/* E1E708 802402A8 4406A000 */  mfc1      $a2, $f20
/* E1E70C 802402AC 0C0B2190 */  jal       set_float_variable
/* E1E710 802402B0 34A53C81 */   ori      $a1, $a1, 0x3c81
/* E1E714 802402B4 0200202D */  daddu     $a0, $s0, $zero
/* E1E718 802402B8 3C05FE36 */  lui       $a1, 0xfe36
/* E1E71C 802402BC 8FA60014 */  lw        $a2, 0x14($sp)
/* E1E720 802402C0 0C0B2190 */  jal       set_float_variable
/* E1E724 802402C4 34A53C82 */   ori      $a1, $a1, 0x3c82
/* E1E728 802402C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* E1E72C 802402CC 8FB00018 */  lw        $s0, 0x18($sp)
/* E1E730 802402D0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* E1E734 802402D4 24020002 */  addiu     $v0, $zero, 2
/* E1E738 802402D8 03E00008 */  jr        $ra
/* E1E73C 802402DC 27BD0028 */   addiu    $sp, $sp, 0x28
