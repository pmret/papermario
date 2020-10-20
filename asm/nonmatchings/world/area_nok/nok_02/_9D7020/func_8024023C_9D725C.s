.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024023C_9D725C
/* 9D725C 8024023C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9D7260 80240240 AFB00018 */  sw        $s0, 0x18($sp)
/* 9D7264 80240244 0080802D */  daddu     $s0, $a0, $zero
/* 9D7268 80240248 AFBF001C */  sw        $ra, 0x1c($sp)
/* 9D726C 8024024C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 9D7270 80240250 8E02000C */  lw        $v0, 0xc($s0)
/* 9D7274 80240254 0C0B210B */  jal       get_float_variable
/* 9D7278 80240258 8C450000 */   lw       $a1, ($v0)
/* 9D727C 8024025C 27A40010 */  addiu     $a0, $sp, 0x10
/* 9D7280 80240260 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 9D7284 80240264 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 9D7288 80240268 44060000 */  mfc1      $a2, $f0
/* 9D728C 8024026C C4400028 */  lwc1      $f0, 0x28($v0)
/* 9D7290 80240270 C4420030 */  lwc1      $f2, 0x30($v0)
/* 9D7294 80240274 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9D7298 80240278 E7A20014 */  swc1      $f2, 0x14($sp)
/* 9D729C 8024027C 8C470080 */  lw        $a3, 0x80($v0)
/* 9D72A0 80240280 C454002C */  lwc1      $f20, 0x2c($v0)
/* 9D72A4 80240284 0C00A7E7 */  jal       add_vec2D_polar
/* 9D72A8 80240288 27A50014 */   addiu    $a1, $sp, 0x14
/* 9D72AC 8024028C 0200202D */  daddu     $a0, $s0, $zero
/* 9D72B0 80240290 3C05FE36 */  lui       $a1, 0xfe36
/* 9D72B4 80240294 8FA60010 */  lw        $a2, 0x10($sp)
/* 9D72B8 80240298 0C0B2190 */  jal       set_float_variable
/* 9D72BC 8024029C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 9D72C0 802402A0 0200202D */  daddu     $a0, $s0, $zero
/* 9D72C4 802402A4 3C05FE36 */  lui       $a1, 0xfe36
/* 9D72C8 802402A8 4406A000 */  mfc1      $a2, $f20
/* 9D72CC 802402AC 0C0B2190 */  jal       set_float_variable
/* 9D72D0 802402B0 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 9D72D4 802402B4 0200202D */  daddu     $a0, $s0, $zero
/* 9D72D8 802402B8 3C05FE36 */  lui       $a1, 0xfe36
/* 9D72DC 802402BC 8FA60014 */  lw        $a2, 0x14($sp)
/* 9D72E0 802402C0 0C0B2190 */  jal       set_float_variable
/* 9D72E4 802402C4 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 9D72E8 802402C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9D72EC 802402CC 8FB00018 */  lw        $s0, 0x18($sp)
/* 9D72F0 802402D0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 9D72F4 802402D4 24020002 */  addiu     $v0, $zero, 2
/* 9D72F8 802402D8 03E00008 */  jr        $ra
/* 9D72FC 802402DC 27BD0028 */   addiu    $sp, $sp, 0x28
