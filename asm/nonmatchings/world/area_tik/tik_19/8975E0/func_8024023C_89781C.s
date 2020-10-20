.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024023C_89781C
/* 89781C 8024023C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 897820 80240240 AFB00018 */  sw        $s0, 0x18($sp)
/* 897824 80240244 0080802D */  daddu     $s0, $a0, $zero
/* 897828 80240248 AFBF001C */  sw        $ra, 0x1c($sp)
/* 89782C 8024024C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 897830 80240250 8E02000C */  lw        $v0, 0xc($s0)
/* 897834 80240254 0C0B210B */  jal       get_float_variable
/* 897838 80240258 8C450000 */   lw       $a1, ($v0)
/* 89783C 8024025C 27A40010 */  addiu     $a0, $sp, 0x10
/* 897840 80240260 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 897844 80240264 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 897848 80240268 44060000 */  mfc1      $a2, $f0
/* 89784C 8024026C C4400028 */  lwc1      $f0, 0x28($v0)
/* 897850 80240270 C4420030 */  lwc1      $f2, 0x30($v0)
/* 897854 80240274 E7A00010 */  swc1      $f0, 0x10($sp)
/* 897858 80240278 E7A20014 */  swc1      $f2, 0x14($sp)
/* 89785C 8024027C 8C470080 */  lw        $a3, 0x80($v0)
/* 897860 80240280 C454002C */  lwc1      $f20, 0x2c($v0)
/* 897864 80240284 0C00A7E7 */  jal       add_vec2D_polar
/* 897868 80240288 27A50014 */   addiu    $a1, $sp, 0x14
/* 89786C 8024028C 0200202D */  daddu     $a0, $s0, $zero
/* 897870 80240290 3C05FE36 */  lui       $a1, 0xfe36
/* 897874 80240294 8FA60010 */  lw        $a2, 0x10($sp)
/* 897878 80240298 0C0B2190 */  jal       set_float_variable
/* 89787C 8024029C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 897880 802402A0 0200202D */  daddu     $a0, $s0, $zero
/* 897884 802402A4 3C05FE36 */  lui       $a1, 0xfe36
/* 897888 802402A8 4406A000 */  mfc1      $a2, $f20
/* 89788C 802402AC 0C0B2190 */  jal       set_float_variable
/* 897890 802402B0 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 897894 802402B4 0200202D */  daddu     $a0, $s0, $zero
/* 897898 802402B8 3C05FE36 */  lui       $a1, 0xfe36
/* 89789C 802402BC 8FA60014 */  lw        $a2, 0x14($sp)
/* 8978A0 802402C0 0C0B2190 */  jal       set_float_variable
/* 8978A4 802402C4 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 8978A8 802402C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8978AC 802402CC 8FB00018 */  lw        $s0, 0x18($sp)
/* 8978B0 802402D0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 8978B4 802402D4 24020002 */  addiu     $v0, $zero, 2
/* 8978B8 802402D8 03E00008 */  jr        $ra
/* 8978BC 802402DC 27BD0028 */   addiu    $sp, $sp, 0x28
