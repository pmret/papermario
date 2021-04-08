.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240274_ED9094
/* ED9094 80240274 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* ED9098 80240278 AFB00018 */  sw        $s0, 0x18($sp)
/* ED909C 8024027C 0080802D */  daddu     $s0, $a0, $zero
/* ED90A0 80240280 AFBF001C */  sw        $ra, 0x1c($sp)
/* ED90A4 80240284 F7B40020 */  sdc1      $f20, 0x20($sp)
/* ED90A8 80240288 8E02000C */  lw        $v0, 0xc($s0)
/* ED90AC 8024028C 0C0B55FF */  jal       dead_get_float_variable
/* ED90B0 80240290 8C450000 */   lw       $a1, ($v0)
/* ED90B4 80240294 27A40010 */  addiu     $a0, $sp, 0x10
/* ED90B8 80240298 3C028011 */  lui       $v0, %hi(D_80117578)
/* ED90BC 8024029C 24427578 */  addiu     $v0, $v0, %lo(D_80117578)
/* ED90C0 802402A0 44060000 */  mfc1      $a2, $f0
/* ED90C4 802402A4 C4400028 */  lwc1      $f0, 0x28($v0)
/* ED90C8 802402A8 C4420030 */  lwc1      $f2, 0x30($v0)
/* ED90CC 802402AC E7A00010 */  swc1      $f0, 0x10($sp)
/* ED90D0 802402B0 E7A20014 */  swc1      $f2, 0x14($sp)
/* ED90D4 802402B4 8C470080 */  lw        $a3, 0x80($v0)
/* ED90D8 802402B8 C454002C */  lwc1      $f20, 0x2c($v0)
/* ED90DC 802402BC 0C00ACA3 */  jal       func_8002B28C
/* ED90E0 802402C0 27A50014 */   addiu    $a1, $sp, 0x14
/* ED90E4 802402C4 0200202D */  daddu     $a0, $s0, $zero
/* ED90E8 802402C8 3C05FE36 */  lui       $a1, 0xfe36
/* ED90EC 802402CC 8FA60010 */  lw        $a2, 0x10($sp)
/* ED90F0 802402D0 0C0B5684 */  jal       dead_set_float_variable
/* ED90F4 802402D4 34A53C80 */   ori      $a1, $a1, 0x3c80
/* ED90F8 802402D8 0200202D */  daddu     $a0, $s0, $zero
/* ED90FC 802402DC 3C05FE36 */  lui       $a1, 0xfe36
/* ED9100 802402E0 4406A000 */  mfc1      $a2, $f20
/* ED9104 802402E4 0C0B5684 */  jal       dead_set_float_variable
/* ED9108 802402E8 34A53C81 */   ori      $a1, $a1, 0x3c81
/* ED910C 802402EC 0200202D */  daddu     $a0, $s0, $zero
/* ED9110 802402F0 3C05FE36 */  lui       $a1, 0xfe36
/* ED9114 802402F4 8FA60014 */  lw        $a2, 0x14($sp)
/* ED9118 802402F8 0C0B5684 */  jal       dead_set_float_variable
/* ED911C 802402FC 34A53C82 */   ori      $a1, $a1, 0x3c82
/* ED9120 80240300 8FBF001C */  lw        $ra, 0x1c($sp)
/* ED9124 80240304 8FB00018 */  lw        $s0, 0x18($sp)
/* ED9128 80240308 D7B40020 */  ldc1      $f20, 0x20($sp)
/* ED912C 8024030C 24020002 */  addiu     $v0, $zero, 2
/* ED9130 80240310 03E00008 */  jr        $ra
/* ED9134 80240314 27BD0028 */   addiu    $sp, $sp, 0x28
