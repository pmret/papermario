.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240494_907EC4
/* 907EC4 80240494 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 907EC8 80240498 AFB1001C */  sw        $s1, 0x1c($sp)
/* 907ECC 8024049C 0080882D */  daddu     $s1, $a0, $zero
/* 907ED0 802404A0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 907ED4 802404A4 AFB00018 */  sw        $s0, 0x18($sp)
/* 907ED8 802404A8 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 907EDC 802404AC 8E30000C */  lw        $s0, 0xc($s1)
/* 907EE0 802404B0 8E050000 */  lw        $a1, ($s0)
/* 907EE4 802404B4 0C0B210B */  jal       evt_get_float_variable
/* 907EE8 802404B8 26100004 */   addiu    $s0, $s0, 4
/* 907EEC 802404BC 0220202D */  daddu     $a0, $s1, $zero
/* 907EF0 802404C0 8E050000 */  lw        $a1, ($s0)
/* 907EF4 802404C4 0C0B1EAF */  jal       evt_get_variable
/* 907EF8 802404C8 46000506 */   mov.s    $f20, $f0
/* 907EFC 802404CC 0220202D */  daddu     $a0, $s1, $zero
/* 907F00 802404D0 3C05FD05 */  lui       $a1, 0xfd05
/* 907F04 802404D4 34A50F80 */  ori       $a1, $a1, 0xf80
/* 907F08 802404D8 0C0B1EAF */  jal       evt_get_variable
/* 907F0C 802404DC 0040802D */   daddu    $s0, $v0, $zero
/* 907F10 802404E0 C4420004 */  lwc1      $f2, 4($v0)
/* 907F14 802404E4 3C014180 */  lui       $at, 0x4180
/* 907F18 802404E8 44810000 */  mtc1      $at, $f0
/* 907F1C 802404EC E7B40010 */  swc1      $f20, 0x10($sp)
/* 907F20 802404F0 AFB00014 */  sw        $s0, 0x14($sp)
/* 907F24 802404F4 46001080 */  add.s     $f2, $f2, $f0
/* 907F28 802404F8 8C450000 */  lw        $a1, ($v0)
/* 907F2C 802404FC 8C470008 */  lw        $a3, 8($v0)
/* 907F30 80240500 44061000 */  mfc1      $a2, $f2
/* 907F34 80240504 0C01C2EC */  jal       playFX_33
/* 907F38 80240508 2404000E */   addiu    $a0, $zero, 0xe
/* 907F3C 8024050C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 907F40 80240510 8FB1001C */  lw        $s1, 0x1c($sp)
/* 907F44 80240514 8FB00018 */  lw        $s0, 0x18($sp)
/* 907F48 80240518 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 907F4C 8024051C 24020002 */  addiu     $v0, $zero, 2
/* 907F50 80240520 03E00008 */  jr        $ra
/* 907F54 80240524 27BD0030 */   addiu    $sp, $sp, 0x30
