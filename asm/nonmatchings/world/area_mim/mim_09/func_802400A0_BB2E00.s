.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400A0_BB2EA0
/* BB2EA0 802400A0 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* BB2EA4 802400A4 AFB00030 */  sw        $s0, 0x30($sp)
/* BB2EA8 802400A8 0080802D */  daddu     $s0, $a0, $zero
/* BB2EAC 802400AC AFBF0040 */  sw        $ra, 0x40($sp)
/* BB2EB0 802400B0 AFB3003C */  sw        $s3, 0x3c($sp)
/* BB2EB4 802400B4 AFB20038 */  sw        $s2, 0x38($sp)
/* BB2EB8 802400B8 AFB10034 */  sw        $s1, 0x34($sp)
/* BB2EBC 802400BC F7B60050 */  sdc1      $f22, 0x50($sp)
/* BB2EC0 802400C0 F7B40048 */  sdc1      $f20, 0x48($sp)
/* BB2EC4 802400C4 8E130148 */  lw        $s3, 0x148($s0)
/* BB2EC8 802400C8 00A0882D */  daddu     $s1, $a1, $zero
/* BB2ECC 802400CC 86640008 */  lh        $a0, 8($s3)
/* BB2ED0 802400D0 0C00EABB */  jal       get_npc_unsafe
/* BB2ED4 802400D4 00C0902D */   daddu    $s2, $a2, $zero
/* BB2ED8 802400D8 0200202D */  daddu     $a0, $s0, $zero
/* BB2EDC 802400DC 0220282D */  daddu     $a1, $s1, $zero
/* BB2EE0 802400E0 0240302D */  daddu     $a2, $s2, $zero
/* BB2EE4 802400E4 0C012568 */  jal       func_800495A0
/* BB2EE8 802400E8 0040802D */   daddu    $s0, $v0, $zero
/* BB2EEC 802400EC 8E020000 */  lw        $v0, ($s0)
/* BB2EF0 802400F0 2404002D */  addiu     $a0, $zero, 0x2d
/* BB2EF4 802400F4 34420800 */  ori       $v0, $v0, 0x800
/* BB2EF8 802400F8 0C00A67F */  jal       rand_int
/* BB2EFC 802400FC AE020000 */   sw       $v0, ($s0)
/* BB2F00 80240100 0200202D */  daddu     $a0, $s0, $zero
/* BB2F04 80240104 3C05B000 */  lui       $a1, 0xb000
/* BB2F08 80240108 34A50017 */  ori       $a1, $a1, 0x17
/* BB2F0C 8024010C 44820000 */  mtc1      $v0, $f0
/* BB2F10 80240110 00000000 */  nop       
/* BB2F14 80240114 46800021 */  cvt.d.w   $f0, $f0
/* BB2F18 80240118 3C014024 */  lui       $at, 0x4024
/* BB2F1C 8024011C 44811800 */  mtc1      $at, $f3
/* BB2F20 80240120 44801000 */  mtc1      $zero, $f2
/* BB2F24 80240124 3C014020 */  lui       $at, 0x4020
/* BB2F28 80240128 44812800 */  mtc1      $at, $f5
/* BB2F2C 8024012C 44802000 */  mtc1      $zero, $f4
/* BB2F30 80240130 46220003 */  div.d     $f0, $f0, $f2
/* BB2F34 80240134 46240000 */  add.d     $f0, $f0, $f4
/* BB2F38 80240138 3C013FC0 */  lui       $at, 0x3fc0
/* BB2F3C 8024013C 44811000 */  mtc1      $at, $f2
/* BB2F40 80240140 0000302D */  daddu     $a2, $zero, $zero
/* BB2F44 80240144 E6020014 */  swc1      $f2, 0x14($s0)
/* BB2F48 80240148 46200020 */  cvt.s.d   $f0, $f0
/* BB2F4C 8024014C 0C012530 */  jal       func_800494C0
/* BB2F50 80240150 E600001C */   swc1     $f0, 0x1c($s0)
/* BB2F54 80240154 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BB2F58 80240158 C6000040 */  lwc1      $f0, 0x40($s0)
/* BB2F5C 8024015C C4620000 */  lwc1      $f2, ($v1)
/* BB2F60 80240160 468010A0 */  cvt.s.w   $f2, $f2
/* BB2F64 80240164 C4640008 */  lwc1      $f4, 8($v1)
/* BB2F68 80240168 46802120 */  cvt.s.w   $f4, $f4
/* BB2F6C 8024016C E7A00010 */  swc1      $f0, 0x10($sp)
/* BB2F70 80240170 8E6200D0 */  lw        $v0, 0xd0($s3)
/* BB2F74 80240174 44051000 */  mfc1      $a1, $f2
/* BB2F78 80240178 C440000C */  lwc1      $f0, 0xc($v0)
/* BB2F7C 8024017C 46800020 */  cvt.s.w   $f0, $f0
/* BB2F80 80240180 E7A00014 */  swc1      $f0, 0x14($sp)
/* BB2F84 80240184 8E6200D0 */  lw        $v0, 0xd0($s3)
/* BB2F88 80240188 44062000 */  mfc1      $a2, $f4
/* BB2F8C 8024018C C4400010 */  lwc1      $f0, 0x10($v0)
/* BB2F90 80240190 46800020 */  cvt.s.w   $f0, $f0
/* BB2F94 80240194 E7A00018 */  swc1      $f0, 0x18($sp)
/* BB2F98 80240198 8C640018 */  lw        $a0, 0x18($v1)
/* BB2F9C 8024019C 0C0123F5 */  jal       is_point_within_region
/* BB2FA0 802401A0 8E070038 */   lw       $a3, 0x38($s0)
/* BB2FA4 802401A4 10400035 */  beqz      $v0, .L8024027C
/* BB2FA8 802401A8 00000000 */   nop      
/* BB2FAC 802401AC C60C0038 */  lwc1      $f12, 0x38($s0)
/* BB2FB0 802401B0 3C0141C8 */  lui       $at, 0x41c8
/* BB2FB4 802401B4 4481B000 */  mtc1      $at, $f22
/* BB2FB8 802401B8 8E6200D0 */  lw        $v0, 0xd0($s3)
/* BB2FBC 802401BC C60E0040 */  lwc1      $f14, 0x40($s0)
/* BB2FC0 802401C0 C4480000 */  lwc1      $f8, ($v0)
/* BB2FC4 802401C4 46804220 */  cvt.s.w   $f8, $f8
/* BB2FC8 802401C8 44064000 */  mfc1      $a2, $f8
/* BB2FCC 802401CC C4480008 */  lwc1      $f8, 8($v0)
/* BB2FD0 802401D0 46804220 */  cvt.s.w   $f8, $f8
/* BB2FD4 802401D4 44074000 */  mfc1      $a3, $f8
/* BB2FD8 802401D8 3C01403E */  lui       $at, 0x403e
/* BB2FDC 802401DC 4481A800 */  mtc1      $at, $f21
/* BB2FE0 802401E0 4480A000 */  mtc1      $zero, $f20
/* BB2FE4 802401E4 0C00A720 */  jal       atan2
/* BB2FE8 802401E8 0000882D */   daddu    $s1, $zero, $zero
/* BB2FEC 802401EC C6020038 */  lwc1      $f2, 0x38($s0)
/* BB2FF0 802401F0 C604003C */  lwc1      $f4, 0x3c($s0)
/* BB2FF4 802401F4 C6060040 */  lwc1      $f6, 0x40($s0)
/* BB2FF8 802401F8 E600000C */  swc1      $f0, 0xc($s0)
/* BB2FFC 802401FC E7A20020 */  swc1      $f2, 0x20($sp)
/* BB3000 80240200 E7A40024 */  swc1      $f4, 0x24($sp)
/* BB3004 80240204 E7A60028 */  swc1      $f6, 0x28($sp)
.L80240208:
/* BB3008 80240208 E7B60010 */  swc1      $f22, 0x10($sp)
/* BB300C 8024020C C600000C */  lwc1      $f0, 0xc($s0)
/* BB3010 80240210 E7A00014 */  swc1      $f0, 0x14($sp)
/* BB3014 80240214 860200A8 */  lh        $v0, 0xa8($s0)
/* BB3018 80240218 27A50020 */  addiu     $a1, $sp, 0x20
/* BB301C 8024021C 44820000 */  mtc1      $v0, $f0
/* BB3020 80240220 00000000 */  nop       
/* BB3024 80240224 46800020 */  cvt.s.w   $f0, $f0
/* BB3028 80240228 E7A00018 */  swc1      $f0, 0x18($sp)
/* BB302C 8024022C 860200A6 */  lh        $v0, 0xa6($s0)
/* BB3030 80240230 27A60024 */  addiu     $a2, $sp, 0x24
/* BB3034 80240234 44820000 */  mtc1      $v0, $f0
/* BB3038 80240238 00000000 */  nop       
/* BB303C 8024023C 46800020 */  cvt.s.w   $f0, $f0
/* BB3040 80240240 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BB3044 80240244 8E040080 */  lw        $a0, 0x80($s0)
/* BB3048 80240248 0C037711 */  jal       func_800DDC44
/* BB304C 8024024C 27A70028 */   addiu    $a3, $sp, 0x28
/* BB3050 80240250 10400016 */  beqz      $v0, .L802402AC
/* BB3054 80240254 26310001 */   addiu    $s1, $s1, 1
/* BB3058 80240258 C600000C */  lwc1      $f0, 0xc($s0)
/* BB305C 8024025C 46000021 */  cvt.d.s   $f0, $f0
/* BB3060 80240260 46340000 */  add.d     $f0, $f0, $f20
/* BB3064 80240264 2A220006 */  slti      $v0, $s1, 6
/* BB3068 80240268 46200020 */  cvt.s.d   $f0, $f0
/* BB306C 8024026C 1440FFE6 */  bnez      $v0, .L80240208
/* BB3070 80240270 E600000C */   swc1     $f0, 0xc($s0)
/* BB3074 80240274 080900AB */  j         .L802402AC
/* BB3078 80240278 00000000 */   nop      
.L8024027C:
/* BB307C 8024027C 0C00A67F */  jal       rand_int
/* BB3080 80240280 2404003C */   addiu    $a0, $zero, 0x3c
/* BB3084 80240284 C60C000C */  lwc1      $f12, 0xc($s0)
/* BB3088 80240288 44820000 */  mtc1      $v0, $f0
/* BB308C 8024028C 00000000 */  nop       
/* BB3090 80240290 46800020 */  cvt.s.w   $f0, $f0
/* BB3094 80240294 46006300 */  add.s     $f12, $f12, $f0
/* BB3098 80240298 3C0141F0 */  lui       $at, 0x41f0
/* BB309C 8024029C 44810000 */  mtc1      $at, $f0
/* BB30A0 802402A0 0C00A6C9 */  jal       clamp_angle
/* BB30A4 802402A4 46006301 */   sub.s    $f12, $f12, $f0
/* BB30A8 802402A8 E600000C */  swc1      $f0, 0xc($s0)
.L802402AC:
/* BB30AC 802402AC 8FBF0040 */  lw        $ra, 0x40($sp)
/* BB30B0 802402B0 8FB3003C */  lw        $s3, 0x3c($sp)
/* BB30B4 802402B4 8FB20038 */  lw        $s2, 0x38($sp)
/* BB30B8 802402B8 8FB10034 */  lw        $s1, 0x34($sp)
/* BB30BC 802402BC 8FB00030 */  lw        $s0, 0x30($sp)
/* BB30C0 802402C0 D7B60050 */  ldc1      $f22, 0x50($sp)
/* BB30C4 802402C4 D7B40048 */  ldc1      $f20, 0x48($sp)
/* BB30C8 802402C8 03E00008 */  jr        $ra
/* BB30CC 802402CC 27BD0058 */   addiu    $sp, $sp, 0x58
