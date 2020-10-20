.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024023C_8B02AC
/* 8B02AC 8024023C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8B02B0 80240240 AFB00018 */  sw        $s0, 0x18($sp)
/* 8B02B4 80240244 0080802D */  daddu     $s0, $a0, $zero
/* 8B02B8 80240248 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8B02BC 8024024C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 8B02C0 80240250 8E02000C */  lw        $v0, 0xc($s0)
/* 8B02C4 80240254 0C0B210B */  jal       get_float_variable
/* 8B02C8 80240258 8C450000 */   lw       $a1, ($v0)
/* 8B02CC 8024025C 27A40010 */  addiu     $a0, $sp, 0x10
/* 8B02D0 80240260 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 8B02D4 80240264 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 8B02D8 80240268 44060000 */  mfc1      $a2, $f0
/* 8B02DC 8024026C C4400028 */  lwc1      $f0, 0x28($v0)
/* 8B02E0 80240270 C4420030 */  lwc1      $f2, 0x30($v0)
/* 8B02E4 80240274 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8B02E8 80240278 E7A20014 */  swc1      $f2, 0x14($sp)
/* 8B02EC 8024027C 8C470080 */  lw        $a3, 0x80($v0)
/* 8B02F0 80240280 C454002C */  lwc1      $f20, 0x2c($v0)
/* 8B02F4 80240284 0C00A7E7 */  jal       add_vec2D_polar
/* 8B02F8 80240288 27A50014 */   addiu    $a1, $sp, 0x14
/* 8B02FC 8024028C 0200202D */  daddu     $a0, $s0, $zero
/* 8B0300 80240290 3C05FE36 */  lui       $a1, 0xfe36
/* 8B0304 80240294 8FA60010 */  lw        $a2, 0x10($sp)
/* 8B0308 80240298 0C0B2190 */  jal       set_float_variable
/* 8B030C 8024029C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 8B0310 802402A0 0200202D */  daddu     $a0, $s0, $zero
/* 8B0314 802402A4 3C05FE36 */  lui       $a1, 0xfe36
/* 8B0318 802402A8 4406A000 */  mfc1      $a2, $f20
/* 8B031C 802402AC 0C0B2190 */  jal       set_float_variable
/* 8B0320 802402B0 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 8B0324 802402B4 0200202D */  daddu     $a0, $s0, $zero
/* 8B0328 802402B8 3C05FE36 */  lui       $a1, 0xfe36
/* 8B032C 802402BC 8FA60014 */  lw        $a2, 0x14($sp)
/* 8B0330 802402C0 0C0B2190 */  jal       set_float_variable
/* 8B0334 802402C4 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 8B0338 802402C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8B033C 802402CC 8FB00018 */  lw        $s0, 0x18($sp)
/* 8B0340 802402D0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 8B0344 802402D4 24020002 */  addiu     $v0, $zero, 2
/* 8B0348 802402D8 03E00008 */  jr        $ra
/* 8B034C 802402DC 27BD0028 */   addiu    $sp, $sp, 0x28
