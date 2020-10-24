.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802437DC_95E9DC
/* 95E9DC 802437DC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 95E9E0 802437E0 AFB00018 */  sw        $s0, 0x18($sp)
/* 95E9E4 802437E4 0080802D */  daddu     $s0, $a0, $zero
/* 95E9E8 802437E8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 95E9EC 802437EC F7B40020 */  sdc1      $f20, 0x20($sp)
/* 95E9F0 802437F0 8E02000C */  lw        $v0, 0xc($s0)
/* 95E9F4 802437F4 0C0B210B */  jal       get_float_variable
/* 95E9F8 802437F8 8C450000 */   lw       $a1, ($v0)
/* 95E9FC 802437FC 27A40010 */  addiu     $a0, $sp, 0x10
/* 95EA00 80243800 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 95EA04 80243804 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 95EA08 80243808 44060000 */  mfc1      $a2, $f0
/* 95EA0C 8024380C C4400028 */  lwc1      $f0, 0x28($v0)
/* 95EA10 80243810 C4420030 */  lwc1      $f2, 0x30($v0)
/* 95EA14 80243814 E7A00010 */  swc1      $f0, 0x10($sp)
/* 95EA18 80243818 E7A20014 */  swc1      $f2, 0x14($sp)
/* 95EA1C 8024381C 8C470080 */  lw        $a3, 0x80($v0)
/* 95EA20 80243820 C454002C */  lwc1      $f20, 0x2c($v0)
/* 95EA24 80243824 0C00A7E7 */  jal       add_vec2D_polar
/* 95EA28 80243828 27A50014 */   addiu    $a1, $sp, 0x14
/* 95EA2C 8024382C 0200202D */  daddu     $a0, $s0, $zero
/* 95EA30 80243830 3C05FE36 */  lui       $a1, 0xfe36
/* 95EA34 80243834 8FA60010 */  lw        $a2, 0x10($sp)
/* 95EA38 80243838 0C0B2190 */  jal       set_float_variable
/* 95EA3C 8024383C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 95EA40 80243840 0200202D */  daddu     $a0, $s0, $zero
/* 95EA44 80243844 3C05FE36 */  lui       $a1, 0xfe36
/* 95EA48 80243848 4406A000 */  mfc1      $a2, $f20
/* 95EA4C 8024384C 0C0B2190 */  jal       set_float_variable
/* 95EA50 80243850 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 95EA54 80243854 0200202D */  daddu     $a0, $s0, $zero
/* 95EA58 80243858 3C05FE36 */  lui       $a1, 0xfe36
/* 95EA5C 8024385C 8FA60014 */  lw        $a2, 0x14($sp)
/* 95EA60 80243860 0C0B2190 */  jal       set_float_variable
/* 95EA64 80243864 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 95EA68 80243868 8FBF001C */  lw        $ra, 0x1c($sp)
/* 95EA6C 8024386C 8FB00018 */  lw        $s0, 0x18($sp)
/* 95EA70 80243870 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 95EA74 80243874 24020002 */  addiu     $v0, $zero, 2
/* 95EA78 80243878 03E00008 */  jr        $ra
/* 95EA7C 8024387C 27BD0028 */   addiu    $sp, $sp, 0x28
