.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404E0_A8CF60
/* A8CF60 802404E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A8CF64 802404E4 AFB3001C */  sw        $s3, 0x1c($sp)
/* A8CF68 802404E8 0080982D */  daddu     $s3, $a0, $zero
/* A8CF6C 802404EC AFBF0020 */  sw        $ra, 0x20($sp)
/* A8CF70 802404F0 AFB20018 */  sw        $s2, 0x18($sp)
/* A8CF74 802404F4 AFB10014 */  sw        $s1, 0x14($sp)
/* A8CF78 802404F8 AFB00010 */  sw        $s0, 0x10($sp)
/* A8CF7C 802404FC 8E720148 */  lw        $s2, 0x148($s3)
/* A8CF80 80240500 86440008 */  lh        $a0, 8($s2)
/* A8CF84 80240504 0C00EABB */  jal       get_npc_unsafe
/* A8CF88 80240508 00A0882D */   daddu    $s1, $a1, $zero
/* A8CF8C 8024050C 8E240008 */  lw        $a0, 8($s1)
/* A8CF90 80240510 0040802D */  daddu     $s0, $v0, $zero
/* A8CF94 80240514 00041FC2 */  srl       $v1, $a0, 0x1f
/* A8CF98 80240518 00832021 */  addu      $a0, $a0, $v1
/* A8CF9C 8024051C 00042043 */  sra       $a0, $a0, 1
/* A8CFA0 80240520 0C00A67F */  jal       rand_int
/* A8CFA4 80240524 24840001 */   addiu    $a0, $a0, 1
/* A8CFA8 80240528 8E230008 */  lw        $v1, 8($s1)
/* A8CFAC 8024052C 240400B4 */  addiu     $a0, $zero, 0xb4
/* A8CFB0 80240530 00032FC2 */  srl       $a1, $v1, 0x1f
/* A8CFB4 80240534 00651821 */  addu      $v1, $v1, $a1
/* A8CFB8 80240538 00031843 */  sra       $v1, $v1, 1
/* A8CFBC 8024053C 00621821 */  addu      $v1, $v1, $v0
/* A8CFC0 80240540 0C00A67F */  jal       rand_int
/* A8CFC4 80240544 A603008E */   sh       $v1, 0x8e($s0)
/* A8CFC8 80240548 C60C000C */  lwc1      $f12, 0xc($s0)
/* A8CFCC 8024054C 44820000 */  mtc1      $v0, $f0
/* A8CFD0 80240550 00000000 */  nop       
/* A8CFD4 80240554 46800020 */  cvt.s.w   $f0, $f0
/* A8CFD8 80240558 46006300 */  add.s     $f12, $f12, $f0
/* A8CFDC 8024055C 3C0142B4 */  lui       $at, 0x42b4
/* A8CFE0 80240560 44810000 */  mtc1      $at, $f0
/* A8CFE4 80240564 0C00A6C9 */  jal       clamp_angle
/* A8CFE8 80240568 46006301 */   sub.s    $f12, $f12, $f0
/* A8CFEC 8024056C E600000C */  swc1      $f0, 0xc($s0)
/* A8CFF0 80240570 8E4200CC */  lw        $v0, 0xcc($s2)
/* A8CFF4 80240574 8C420000 */  lw        $v0, ($v0)
/* A8CFF8 80240578 AE020028 */  sw        $v0, 0x28($s0)
/* A8CFFC 8024057C 24020003 */  addiu     $v0, $zero, 3
/* A8D000 80240580 AE620070 */  sw        $v0, 0x70($s3)
/* A8D004 80240584 8FBF0020 */  lw        $ra, 0x20($sp)
/* A8D008 80240588 8FB3001C */  lw        $s3, 0x1c($sp)
/* A8D00C 8024058C 8FB20018 */  lw        $s2, 0x18($sp)
/* A8D010 80240590 8FB10014 */  lw        $s1, 0x14($sp)
/* A8D014 80240594 8FB00010 */  lw        $s0, 0x10($sp)
/* A8D018 80240598 03E00008 */  jr        $ra
/* A8D01C 8024059C 27BD0028 */   addiu    $sp, $sp, 0x28
