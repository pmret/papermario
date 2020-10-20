.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024023C_BB72AC
/* BB72AC 8024023C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BB72B0 80240240 AFB00018 */  sw        $s0, 0x18($sp)
/* BB72B4 80240244 0080802D */  daddu     $s0, $a0, $zero
/* BB72B8 80240248 AFBF001C */  sw        $ra, 0x1c($sp)
/* BB72BC 8024024C F7B40020 */  sdc1      $f20, 0x20($sp)
/* BB72C0 80240250 8E02000C */  lw        $v0, 0xc($s0)
/* BB72C4 80240254 0C0B210B */  jal       get_float_variable
/* BB72C8 80240258 8C450000 */   lw       $a1, ($v0)
/* BB72CC 8024025C 27A40010 */  addiu     $a0, $sp, 0x10
/* BB72D0 80240260 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* BB72D4 80240264 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* BB72D8 80240268 44060000 */  mfc1      $a2, $f0
/* BB72DC 8024026C C4400028 */  lwc1      $f0, 0x28($v0)
/* BB72E0 80240270 C4420030 */  lwc1      $f2, 0x30($v0)
/* BB72E4 80240274 E7A00010 */  swc1      $f0, 0x10($sp)
/* BB72E8 80240278 E7A20014 */  swc1      $f2, 0x14($sp)
/* BB72EC 8024027C 8C470080 */  lw        $a3, 0x80($v0)
/* BB72F0 80240280 C454002C */  lwc1      $f20, 0x2c($v0)
/* BB72F4 80240284 0C00A7E7 */  jal       add_vec2D_polar
/* BB72F8 80240288 27A50014 */   addiu    $a1, $sp, 0x14
/* BB72FC 8024028C 0200202D */  daddu     $a0, $s0, $zero
/* BB7300 80240290 3C05FE36 */  lui       $a1, 0xfe36
/* BB7304 80240294 8FA60010 */  lw        $a2, 0x10($sp)
/* BB7308 80240298 0C0B2190 */  jal       set_float_variable
/* BB730C 8024029C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* BB7310 802402A0 0200202D */  daddu     $a0, $s0, $zero
/* BB7314 802402A4 3C05FE36 */  lui       $a1, 0xfe36
/* BB7318 802402A8 4406A000 */  mfc1      $a2, $f20
/* BB731C 802402AC 0C0B2190 */  jal       set_float_variable
/* BB7320 802402B0 34A53C81 */   ori      $a1, $a1, 0x3c81
/* BB7324 802402B4 0200202D */  daddu     $a0, $s0, $zero
/* BB7328 802402B8 3C05FE36 */  lui       $a1, 0xfe36
/* BB732C 802402BC 8FA60014 */  lw        $a2, 0x14($sp)
/* BB7330 802402C0 0C0B2190 */  jal       set_float_variable
/* BB7334 802402C4 34A53C82 */   ori      $a1, $a1, 0x3c82
/* BB7338 802402C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* BB733C 802402CC 8FB00018 */  lw        $s0, 0x18($sp)
/* BB7340 802402D0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* BB7344 802402D4 24020002 */  addiu     $v0, $zero, 2
/* BB7348 802402D8 03E00008 */  jr        $ra
/* BB734C 802402DC 27BD0028 */   addiu    $sp, $sp, 0x28
