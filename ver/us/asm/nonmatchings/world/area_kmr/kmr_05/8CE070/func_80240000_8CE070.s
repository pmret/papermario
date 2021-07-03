.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80243440_8D14B0
.double 32767.0

.section .text

glabel func_80240000_8CE070
/* 8CE070 80240000 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 8CE074 80240004 AFB3002C */  sw        $s3, 0x2c($sp)
/* 8CE078 80240008 0080982D */  daddu     $s3, $a0, $zero
/* 8CE07C 8024000C AFBF0030 */  sw        $ra, 0x30($sp)
/* 8CE080 80240010 AFB20028 */  sw        $s2, 0x28($sp)
/* 8CE084 80240014 AFB10024 */  sw        $s1, 0x24($sp)
/* 8CE088 80240018 AFB00020 */  sw        $s0, 0x20($sp)
/* 8CE08C 8024001C 8E710148 */  lw        $s1, 0x148($s3)
/* 8CE090 80240020 86240008 */  lh        $a0, 8($s1)
/* 8CE094 80240024 0C00EABB */  jal       get_npc_unsafe
/* 8CE098 80240028 00A0902D */   daddu    $s2, $a1, $zero
/* 8CE09C 8024002C 8E440004 */  lw        $a0, 4($s2)
/* 8CE0A0 80240030 0040802D */  daddu     $s0, $v0, $zero
/* 8CE0A4 80240034 00041FC2 */  srl       $v1, $a0, 0x1f
/* 8CE0A8 80240038 00832021 */  addu      $a0, $a0, $v1
/* 8CE0AC 8024003C 00042043 */  sra       $a0, $a0, 1
/* 8CE0B0 80240040 0C00A67F */  jal       rand_int
/* 8CE0B4 80240044 24840001 */   addiu    $a0, $a0, 1
/* 8CE0B8 80240048 8E430004 */  lw        $v1, 4($s2)
/* 8CE0BC 8024004C 000327C2 */  srl       $a0, $v1, 0x1f
/* 8CE0C0 80240050 00641821 */  addu      $v1, $v1, $a0
/* 8CE0C4 80240054 00031843 */  sra       $v1, $v1, 1
/* 8CE0C8 80240058 00621821 */  addu      $v1, $v1, $v0
/* 8CE0CC 8024005C A603008E */  sh        $v1, 0x8e($s0)
/* 8CE0D0 80240060 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 8CE0D4 80240064 C6000040 */  lwc1      $f0, 0x40($s0)
/* 8CE0D8 80240068 C4640000 */  lwc1      $f4, ($v1)
/* 8CE0DC 8024006C 46802120 */  cvt.s.w   $f4, $f4
/* 8CE0E0 80240070 C4620008 */  lwc1      $f2, 8($v1)
/* 8CE0E4 80240074 468010A0 */  cvt.s.w   $f2, $f2
/* 8CE0E8 80240078 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8CE0EC 8024007C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8CE0F0 80240080 44061000 */  mfc1      $a2, $f2
/* 8CE0F4 80240084 C440000C */  lwc1      $f0, 0xc($v0)
/* 8CE0F8 80240088 46800020 */  cvt.s.w   $f0, $f0
/* 8CE0FC 8024008C E7A00014 */  swc1      $f0, 0x14($sp)
/* 8CE100 80240090 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8CE104 80240094 44052000 */  mfc1      $a1, $f4
/* 8CE108 80240098 C4400010 */  lwc1      $f0, 0x10($v0)
/* 8CE10C 8024009C 46800020 */  cvt.s.w   $f0, $f0
/* 8CE110 802400A0 E7A00018 */  swc1      $f0, 0x18($sp)
/* 8CE114 802400A4 8C640018 */  lw        $a0, 0x18($v1)
/* 8CE118 802400A8 0C0123F5 */  jal       is_point_within_region
/* 8CE11C 802400AC 8E070038 */   lw       $a3, 0x38($s0)
/* 8CE120 802400B0 1040000E */  beqz      $v0, .L802400EC
/* 8CE124 802400B4 00000000 */   nop
/* 8CE128 802400B8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8CE12C 802400BC C60C0038 */  lwc1      $f12, 0x38($s0)
/* 8CE130 802400C0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 8CE134 802400C4 C4460000 */  lwc1      $f6, ($v0)
/* 8CE138 802400C8 468031A0 */  cvt.s.w   $f6, $f6
/* 8CE13C 802400CC 44063000 */  mfc1      $a2, $f6
/* 8CE140 802400D0 C4460008 */  lwc1      $f6, 8($v0)
/* 8CE144 802400D4 468031A0 */  cvt.s.w   $f6, $f6
/* 8CE148 802400D8 44073000 */  mfc1      $a3, $f6
/* 8CE14C 802400DC 0C00A720 */  jal       atan2
/* 8CE150 802400E0 00000000 */   nop
/* 8CE154 802400E4 08090047 */  j         .L8024011C
/* 8CE158 802400E8 E600000C */   swc1     $f0, 0xc($s0)
.L802400EC:
/* 8CE15C 802400EC 0C00A67F */  jal       rand_int
/* 8CE160 802400F0 2404003C */   addiu    $a0, $zero, 0x3c
/* 8CE164 802400F4 C60C000C */  lwc1      $f12, 0xc($s0)
/* 8CE168 802400F8 44820000 */  mtc1      $v0, $f0
/* 8CE16C 802400FC 00000000 */  nop
/* 8CE170 80240100 46800020 */  cvt.s.w   $f0, $f0
/* 8CE174 80240104 46006300 */  add.s     $f12, $f12, $f0
/* 8CE178 80240108 3C0141F0 */  lui       $at, 0x41f0
/* 8CE17C 8024010C 44810000 */  mtc1      $at, $f0
/* 8CE180 80240110 0C00A6C9 */  jal       clamp_angle
/* 8CE184 80240114 46006301 */   sub.s    $f12, $f12, $f0
/* 8CE188 80240118 E600000C */  swc1      $f0, 0xc($s0)
.L8024011C:
/* 8CE18C 8024011C 8E2200CC */  lw        $v0, 0xcc($s1)
/* 8CE190 80240120 8C420004 */  lw        $v0, 4($v0)
/* 8CE194 80240124 AE020028 */  sw        $v0, 0x28($s0)
/* 8CE198 80240128 AE600074 */  sw        $zero, 0x74($s3)
/* 8CE19C 8024012C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8CE1A0 80240130 8C420014 */  lw        $v0, 0x14($v0)
/* 8CE1A4 80240134 04410004 */  bgez      $v0, .L80240148
/* 8CE1A8 80240138 00000000 */   nop
/* 8CE1AC 8024013C C6400000 */  lwc1      $f0, ($s2)
/* 8CE1B0 80240140 0809005A */  j         .L80240168
/* 8CE1B4 80240144 E6000018 */   swc1     $f0, 0x18($s0)
.L80240148:
/* 8CE1B8 80240148 3C018024 */  lui       $at, %hi(D_80243440_8D14B0)
/* 8CE1BC 8024014C D4223440 */  ldc1      $f2, %lo(D_80243440_8D14B0)($at)
/* 8CE1C0 80240150 44820000 */  mtc1      $v0, $f0
/* 8CE1C4 80240154 00000000 */  nop
/* 8CE1C8 80240158 46800021 */  cvt.d.w   $f0, $f0
/* 8CE1CC 8024015C 46220003 */  div.d     $f0, $f0, $f2
/* 8CE1D0 80240160 46200020 */  cvt.s.d   $f0, $f0
/* 8CE1D4 80240164 E6000018 */  swc1      $f0, 0x18($s0)
.L80240168:
/* 8CE1D8 80240168 C600003C */  lwc1      $f0, 0x3c($s0)
/* 8CE1DC 8024016C 3C014059 */  lui       $at, 0x4059
/* 8CE1E0 80240170 44811800 */  mtc1      $at, $f3
/* 8CE1E4 80240174 44801000 */  mtc1      $zero, $f2
/* 8CE1E8 80240178 46000021 */  cvt.d.s   $f0, $f0
/* 8CE1EC 8024017C 46220002 */  mul.d     $f0, $f0, $f2
/* 8CE1F0 80240180 00000000 */  nop
/* 8CE1F4 80240184 24020001 */  addiu     $v0, $zero, 1
/* 8CE1F8 80240188 4620018D */  trunc.w.d $f6, $f0
/* 8CE1FC 8024018C E626007C */  swc1      $f6, 0x7c($s1)
/* 8CE200 80240190 AE620070 */  sw        $v0, 0x70($s3)
/* 8CE204 80240194 8FBF0030 */  lw        $ra, 0x30($sp)
/* 8CE208 80240198 8FB3002C */  lw        $s3, 0x2c($sp)
/* 8CE20C 8024019C 8FB20028 */  lw        $s2, 0x28($sp)
/* 8CE210 802401A0 8FB10024 */  lw        $s1, 0x24($sp)
/* 8CE214 802401A4 8FB00020 */  lw        $s0, 0x20($sp)
/* 8CE218 802401A8 03E00008 */  jr        $ra
/* 8CE21C 802401AC 27BD0038 */   addiu    $sp, $sp, 0x38
