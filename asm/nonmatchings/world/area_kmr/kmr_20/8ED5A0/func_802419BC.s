.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419BC
/* 8ED7DC 802419BC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8ED7E0 802419C0 AFB00018 */  sw        $s0, 0x18($sp)
/* 8ED7E4 802419C4 0080802D */  daddu     $s0, $a0, $zero
/* 8ED7E8 802419C8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8ED7EC 802419CC F7B40020 */  sdc1      $f20, 0x20($sp)
/* 8ED7F0 802419D0 8E02000C */  lw        $v0, 0xc($s0)
/* 8ED7F4 802419D4 0C0B210B */  jal       get_float_variable
/* 8ED7F8 802419D8 8C450000 */   lw       $a1, ($v0)
/* 8ED7FC 802419DC 27A40010 */  addiu     $a0, $sp, 0x10
/* 8ED800 802419E0 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 8ED804 802419E4 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 8ED808 802419E8 44060000 */  mfc1      $a2, $f0
/* 8ED80C 802419EC C4400028 */  lwc1      $f0, 0x28($v0)
/* 8ED810 802419F0 C4420030 */  lwc1      $f2, 0x30($v0)
/* 8ED814 802419F4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8ED818 802419F8 E7A20014 */  swc1      $f2, 0x14($sp)
/* 8ED81C 802419FC 8C470080 */  lw        $a3, 0x80($v0)
/* 8ED820 80241A00 C454002C */  lwc1      $f20, 0x2c($v0)
/* 8ED824 80241A04 0C00A7E7 */  jal       add_vec2D_polar
/* 8ED828 80241A08 27A50014 */   addiu    $a1, $sp, 0x14
/* 8ED82C 80241A0C 0200202D */  daddu     $a0, $s0, $zero
/* 8ED830 80241A10 3C05FE36 */  lui       $a1, 0xfe36
/* 8ED834 80241A14 8FA60010 */  lw        $a2, 0x10($sp)
/* 8ED838 80241A18 0C0B2190 */  jal       set_float_variable
/* 8ED83C 80241A1C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 8ED840 80241A20 0200202D */  daddu     $a0, $s0, $zero
/* 8ED844 80241A24 3C05FE36 */  lui       $a1, 0xfe36
/* 8ED848 80241A28 4406A000 */  mfc1      $a2, $f20
/* 8ED84C 80241A2C 0C0B2190 */  jal       set_float_variable
/* 8ED850 80241A30 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 8ED854 80241A34 0200202D */  daddu     $a0, $s0, $zero
/* 8ED858 80241A38 3C05FE36 */  lui       $a1, 0xfe36
/* 8ED85C 80241A3C 8FA60014 */  lw        $a2, 0x14($sp)
/* 8ED860 80241A40 0C0B2190 */  jal       set_float_variable
/* 8ED864 80241A44 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 8ED868 80241A48 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8ED86C 80241A4C 8FB00018 */  lw        $s0, 0x18($sp)
/* 8ED870 80241A50 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 8ED874 80241A54 24020002 */  addiu     $v0, $zero, 2
/* 8ED878 80241A58 03E00008 */  jr        $ra
/* 8ED87C 80241A5C 27BD0028 */   addiu    $sp, $sp, 0x28
