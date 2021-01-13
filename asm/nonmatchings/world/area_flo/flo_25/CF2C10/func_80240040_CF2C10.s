.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_CF2C10
/* CF2C10 80240040 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* CF2C14 80240044 AFB3002C */  sw        $s3, 0x2c($sp)
/* CF2C18 80240048 0080982D */  daddu     $s3, $a0, $zero
/* CF2C1C 8024004C AFBF0030 */  sw        $ra, 0x30($sp)
/* CF2C20 80240050 AFB20028 */  sw        $s2, 0x28($sp)
/* CF2C24 80240054 AFB10024 */  sw        $s1, 0x24($sp)
/* CF2C28 80240058 AFB00020 */  sw        $s0, 0x20($sp)
/* CF2C2C 8024005C 8E710148 */  lw        $s1, 0x148($s3)
/* CF2C30 80240060 86240008 */  lh        $a0, 8($s1)
/* CF2C34 80240064 0C00EABB */  jal       get_npc_unsafe
/* CF2C38 80240068 00A0902D */   daddu    $s2, $a1, $zero
/* CF2C3C 8024006C 8E440004 */  lw        $a0, 4($s2)
/* CF2C40 80240070 0040802D */  daddu     $s0, $v0, $zero
/* CF2C44 80240074 00041FC2 */  srl       $v1, $a0, 0x1f
/* CF2C48 80240078 00832021 */  addu      $a0, $a0, $v1
/* CF2C4C 8024007C 00042043 */  sra       $a0, $a0, 1
/* CF2C50 80240080 0C00A67F */  jal       rand_int
/* CF2C54 80240084 24840001 */   addiu    $a0, $a0, 1
/* CF2C58 80240088 8E430004 */  lw        $v1, 4($s2)
/* CF2C5C 8024008C 000327C2 */  srl       $a0, $v1, 0x1f
/* CF2C60 80240090 00641821 */  addu      $v1, $v1, $a0
/* CF2C64 80240094 00031843 */  sra       $v1, $v1, 1
/* CF2C68 80240098 00621821 */  addu      $v1, $v1, $v0
/* CF2C6C 8024009C A603008E */  sh        $v1, 0x8e($s0)
/* CF2C70 802400A0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CF2C74 802400A4 C6000040 */  lwc1      $f0, 0x40($s0)
/* CF2C78 802400A8 C4640000 */  lwc1      $f4, ($v1)
/* CF2C7C 802400AC 46802120 */  cvt.s.w   $f4, $f4
/* CF2C80 802400B0 C4620008 */  lwc1      $f2, 8($v1)
/* CF2C84 802400B4 468010A0 */  cvt.s.w   $f2, $f2
/* CF2C88 802400B8 E7A00010 */  swc1      $f0, 0x10($sp)
/* CF2C8C 802400BC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CF2C90 802400C0 44061000 */  mfc1      $a2, $f2
/* CF2C94 802400C4 C440000C */  lwc1      $f0, 0xc($v0)
/* CF2C98 802400C8 46800020 */  cvt.s.w   $f0, $f0
/* CF2C9C 802400CC E7A00014 */  swc1      $f0, 0x14($sp)
/* CF2CA0 802400D0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CF2CA4 802400D4 44052000 */  mfc1      $a1, $f4
/* CF2CA8 802400D8 C4400010 */  lwc1      $f0, 0x10($v0)
/* CF2CAC 802400DC 46800020 */  cvt.s.w   $f0, $f0
/* CF2CB0 802400E0 E7A00018 */  swc1      $f0, 0x18($sp)
/* CF2CB4 802400E4 8C640018 */  lw        $a0, 0x18($v1)
/* CF2CB8 802400E8 0C0123F5 */  jal       is_point_within_region
/* CF2CBC 802400EC 8E070038 */   lw       $a3, 0x38($s0)
/* CF2CC0 802400F0 1040000E */  beqz      $v0, .L8024012C
/* CF2CC4 802400F4 00000000 */   nop
/* CF2CC8 802400F8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CF2CCC 802400FC C60C0038 */  lwc1      $f12, 0x38($s0)
/* CF2CD0 80240100 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CF2CD4 80240104 C4460000 */  lwc1      $f6, ($v0)
/* CF2CD8 80240108 468031A0 */  cvt.s.w   $f6, $f6
/* CF2CDC 8024010C 44063000 */  mfc1      $a2, $f6
/* CF2CE0 80240110 C4460008 */  lwc1      $f6, 8($v0)
/* CF2CE4 80240114 468031A0 */  cvt.s.w   $f6, $f6
/* CF2CE8 80240118 44073000 */  mfc1      $a3, $f6
/* CF2CEC 8024011C 0C00A720 */  jal       atan2
/* CF2CF0 80240120 00000000 */   nop
/* CF2CF4 80240124 08090057 */  j         .L8024015C
/* CF2CF8 80240128 E600000C */   swc1     $f0, 0xc($s0)
.L8024012C:
/* CF2CFC 8024012C 0C00A67F */  jal       rand_int
/* CF2D00 80240130 2404003C */   addiu    $a0, $zero, 0x3c
/* CF2D04 80240134 C60C000C */  lwc1      $f12, 0xc($s0)
/* CF2D08 80240138 44820000 */  mtc1      $v0, $f0
/* CF2D0C 8024013C 00000000 */  nop
/* CF2D10 80240140 46800020 */  cvt.s.w   $f0, $f0
/* CF2D14 80240144 46006300 */  add.s     $f12, $f12, $f0
/* CF2D18 80240148 3C0141F0 */  lui       $at, 0x41f0
/* CF2D1C 8024014C 44810000 */  mtc1      $at, $f0
/* CF2D20 80240150 0C00A6C9 */  jal       clamp_angle
/* CF2D24 80240154 46006301 */   sub.s    $f12, $f12, $f0
/* CF2D28 80240158 E600000C */  swc1      $f0, 0xc($s0)
.L8024015C:
/* CF2D2C 8024015C 8E2200CC */  lw        $v0, 0xcc($s1)
/* CF2D30 80240160 8C420004 */  lw        $v0, 4($v0)
/* CF2D34 80240164 AE020028 */  sw        $v0, 0x28($s0)
/* CF2D38 80240168 AE600074 */  sw        $zero, 0x74($s3)
/* CF2D3C 8024016C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CF2D40 80240170 8C420014 */  lw        $v0, 0x14($v0)
/* CF2D44 80240174 04410004 */  bgez      $v0, .L80240188
/* CF2D48 80240178 00000000 */   nop
/* CF2D4C 8024017C C6400000 */  lwc1      $f0, ($s2)
/* CF2D50 80240180 0809006A */  j         .L802401A8
/* CF2D54 80240184 E6000018 */   swc1     $f0, 0x18($s0)
.L80240188:
/* CF2D58 80240188 3C018024 */  lui       $at, %hi(D_80244EE0)
/* CF2D5C 8024018C D4224EE0 */  ldc1      $f2, %lo(D_80244EE0)($at)
/* CF2D60 80240190 44820000 */  mtc1      $v0, $f0
/* CF2D64 80240194 00000000 */  nop
/* CF2D68 80240198 46800021 */  cvt.d.w   $f0, $f0
/* CF2D6C 8024019C 46220003 */  div.d     $f0, $f0, $f2
/* CF2D70 802401A0 46200020 */  cvt.s.d   $f0, $f0
/* CF2D74 802401A4 E6000018 */  swc1      $f0, 0x18($s0)
.L802401A8:
/* CF2D78 802401A8 C600003C */  lwc1      $f0, 0x3c($s0)
/* CF2D7C 802401AC 3C014059 */  lui       $at, 0x4059
/* CF2D80 802401B0 44811800 */  mtc1      $at, $f3
/* CF2D84 802401B4 44801000 */  mtc1      $zero, $f2
/* CF2D88 802401B8 46000021 */  cvt.d.s   $f0, $f0
/* CF2D8C 802401BC 46220002 */  mul.d     $f0, $f0, $f2
/* CF2D90 802401C0 00000000 */  nop
/* CF2D94 802401C4 24020001 */  addiu     $v0, $zero, 1
/* CF2D98 802401C8 4620018D */  trunc.w.d $f6, $f0
/* CF2D9C 802401CC E626007C */  swc1      $f6, 0x7c($s1)
/* CF2DA0 802401D0 AE620070 */  sw        $v0, 0x70($s3)
/* CF2DA4 802401D4 8FBF0030 */  lw        $ra, 0x30($sp)
/* CF2DA8 802401D8 8FB3002C */  lw        $s3, 0x2c($sp)
/* CF2DAC 802401DC 8FB20028 */  lw        $s2, 0x28($sp)
/* CF2DB0 802401E0 8FB10024 */  lw        $s1, 0x24($sp)
/* CF2DB4 802401E4 8FB00020 */  lw        $s0, 0x20($sp)
/* CF2DB8 802401E8 03E00008 */  jr        $ra
/* CF2DBC 802401EC 27BD0038 */   addiu    $sp, $sp, 0x38
