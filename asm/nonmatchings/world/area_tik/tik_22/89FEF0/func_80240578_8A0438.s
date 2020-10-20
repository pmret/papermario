.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240578_8A0438
/* 8A0438 80240578 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8A043C 8024057C AFB00018 */  sw        $s0, 0x18($sp)
/* 8A0440 80240580 0080802D */  daddu     $s0, $a0, $zero
/* 8A0444 80240584 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8A0448 80240588 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 8A044C 8024058C 8E02000C */  lw        $v0, 0xc($s0)
/* 8A0450 80240590 0C0B210B */  jal       get_float_variable
/* 8A0454 80240594 8C450000 */   lw       $a1, ($v0)
/* 8A0458 80240598 27A40010 */  addiu     $a0, $sp, 0x10
/* 8A045C 8024059C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 8A0460 802405A0 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 8A0464 802405A4 44060000 */  mfc1      $a2, $f0
/* 8A0468 802405A8 C4400028 */  lwc1      $f0, 0x28($v0)
/* 8A046C 802405AC C4420030 */  lwc1      $f2, 0x30($v0)
/* 8A0470 802405B0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8A0474 802405B4 E7A20014 */  swc1      $f2, 0x14($sp)
/* 8A0478 802405B8 8C470080 */  lw        $a3, 0x80($v0)
/* 8A047C 802405BC C454002C */  lwc1      $f20, 0x2c($v0)
/* 8A0480 802405C0 0C00A7E7 */  jal       add_vec2D_polar
/* 8A0484 802405C4 27A50014 */   addiu    $a1, $sp, 0x14
/* 8A0488 802405C8 0200202D */  daddu     $a0, $s0, $zero
/* 8A048C 802405CC 3C05FE36 */  lui       $a1, 0xfe36
/* 8A0490 802405D0 8FA60010 */  lw        $a2, 0x10($sp)
/* 8A0494 802405D4 0C0B2190 */  jal       set_float_variable
/* 8A0498 802405D8 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 8A049C 802405DC 0200202D */  daddu     $a0, $s0, $zero
/* 8A04A0 802405E0 3C05FE36 */  lui       $a1, 0xfe36
/* 8A04A4 802405E4 4406A000 */  mfc1      $a2, $f20
/* 8A04A8 802405E8 0C0B2190 */  jal       set_float_variable
/* 8A04AC 802405EC 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 8A04B0 802405F0 0200202D */  daddu     $a0, $s0, $zero
/* 8A04B4 802405F4 3C05FE36 */  lui       $a1, 0xfe36
/* 8A04B8 802405F8 8FA60014 */  lw        $a2, 0x14($sp)
/* 8A04BC 802405FC 0C0B2190 */  jal       set_float_variable
/* 8A04C0 80240600 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 8A04C4 80240604 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8A04C8 80240608 8FB00018 */  lw        $s0, 0x18($sp)
/* 8A04CC 8024060C D7B40020 */  ldc1      $f20, 0x20($sp)
/* 8A04D0 80240610 24020002 */  addiu     $v0, $zero, 2
/* 8A04D4 80240614 03E00008 */  jr        $ra
/* 8A04D8 80240618 27BD0028 */   addiu    $sp, $sp, 0x28
