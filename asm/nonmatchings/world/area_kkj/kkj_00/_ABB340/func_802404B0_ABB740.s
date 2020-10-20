.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404B0_ABB740
/* ABB740 802404B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* ABB744 802404B4 AFB3001C */  sw        $s3, 0x1c($sp)
/* ABB748 802404B8 0080982D */  daddu     $s3, $a0, $zero
/* ABB74C 802404BC AFBF0020 */  sw        $ra, 0x20($sp)
/* ABB750 802404C0 AFB20018 */  sw        $s2, 0x18($sp)
/* ABB754 802404C4 AFB10014 */  sw        $s1, 0x14($sp)
/* ABB758 802404C8 AFB00010 */  sw        $s0, 0x10($sp)
/* ABB75C 802404CC 8E720148 */  lw        $s2, 0x148($s3)
/* ABB760 802404D0 86440008 */  lh        $a0, 8($s2)
/* ABB764 802404D4 0C00EABB */  jal       get_npc_unsafe
/* ABB768 802404D8 00A0882D */   daddu    $s1, $a1, $zero
/* ABB76C 802404DC 8E240008 */  lw        $a0, 8($s1)
/* ABB770 802404E0 0040802D */  daddu     $s0, $v0, $zero
/* ABB774 802404E4 00041FC2 */  srl       $v1, $a0, 0x1f
/* ABB778 802404E8 00832021 */  addu      $a0, $a0, $v1
/* ABB77C 802404EC 00042043 */  sra       $a0, $a0, 1
/* ABB780 802404F0 0C00A67F */  jal       rand_int
/* ABB784 802404F4 24840001 */   addiu    $a0, $a0, 1
/* ABB788 802404F8 8E230008 */  lw        $v1, 8($s1)
/* ABB78C 802404FC 240400B4 */  addiu     $a0, $zero, 0xb4
/* ABB790 80240500 00032FC2 */  srl       $a1, $v1, 0x1f
/* ABB794 80240504 00651821 */  addu      $v1, $v1, $a1
/* ABB798 80240508 00031843 */  sra       $v1, $v1, 1
/* ABB79C 8024050C 00621821 */  addu      $v1, $v1, $v0
/* ABB7A0 80240510 0C00A67F */  jal       rand_int
/* ABB7A4 80240514 A603008E */   sh       $v1, 0x8e($s0)
/* ABB7A8 80240518 C60C000C */  lwc1      $f12, 0xc($s0)
/* ABB7AC 8024051C 44820000 */  mtc1      $v0, $f0
/* ABB7B0 80240520 00000000 */  nop       
/* ABB7B4 80240524 46800020 */  cvt.s.w   $f0, $f0
/* ABB7B8 80240528 46006300 */  add.s     $f12, $f12, $f0
/* ABB7BC 8024052C 3C0142B4 */  lui       $at, 0x42b4
/* ABB7C0 80240530 44810000 */  mtc1      $at, $f0
/* ABB7C4 80240534 0C00A6C9 */  jal       clamp_angle
/* ABB7C8 80240538 46006301 */   sub.s    $f12, $f12, $f0
/* ABB7CC 8024053C E600000C */  swc1      $f0, 0xc($s0)
/* ABB7D0 80240540 8E4200CC */  lw        $v0, 0xcc($s2)
/* ABB7D4 80240544 8C420000 */  lw        $v0, ($v0)
/* ABB7D8 80240548 AE020028 */  sw        $v0, 0x28($s0)
/* ABB7DC 8024054C 24020003 */  addiu     $v0, $zero, 3
/* ABB7E0 80240550 AE620070 */  sw        $v0, 0x70($s3)
/* ABB7E4 80240554 8FBF0020 */  lw        $ra, 0x20($sp)
/* ABB7E8 80240558 8FB3001C */  lw        $s3, 0x1c($sp)
/* ABB7EC 8024055C 8FB20018 */  lw        $s2, 0x18($sp)
/* ABB7F0 80240560 8FB10014 */  lw        $s1, 0x14($sp)
/* ABB7F4 80240564 8FB00010 */  lw        $s0, 0x10($sp)
/* ABB7F8 80240568 03E00008 */  jr        $ra
/* ABB7FC 8024056C 27BD0028 */   addiu    $sp, $sp, 0x28
