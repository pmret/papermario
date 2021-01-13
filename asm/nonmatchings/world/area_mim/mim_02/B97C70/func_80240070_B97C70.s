.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240070_B97C70
/* B97C70 80240070 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* B97C74 80240074 AFB00030 */  sw        $s0, 0x30($sp)
/* B97C78 80240078 0080802D */  daddu     $s0, $a0, $zero
/* B97C7C 8024007C AFBF0040 */  sw        $ra, 0x40($sp)
/* B97C80 80240080 AFB3003C */  sw        $s3, 0x3c($sp)
/* B97C84 80240084 AFB20038 */  sw        $s2, 0x38($sp)
/* B97C88 80240088 AFB10034 */  sw        $s1, 0x34($sp)
/* B97C8C 8024008C F7B60050 */  sdc1      $f22, 0x50($sp)
/* B97C90 80240090 F7B40048 */  sdc1      $f20, 0x48($sp)
/* B97C94 80240094 8E130148 */  lw        $s3, 0x148($s0)
/* B97C98 80240098 00A0882D */  daddu     $s1, $a1, $zero
/* B97C9C 8024009C 86640008 */  lh        $a0, 8($s3)
/* B97CA0 802400A0 0C00EABB */  jal       get_npc_unsafe
/* B97CA4 802400A4 00C0902D */   daddu    $s2, $a2, $zero
/* B97CA8 802400A8 0200202D */  daddu     $a0, $s0, $zero
/* B97CAC 802400AC 0220282D */  daddu     $a1, $s1, $zero
/* B97CB0 802400B0 0240302D */  daddu     $a2, $s2, $zero
/* B97CB4 802400B4 0C012568 */  jal       func_800495A0
/* B97CB8 802400B8 0040802D */   daddu    $s0, $v0, $zero
/* B97CBC 802400BC 8E020000 */  lw        $v0, ($s0)
/* B97CC0 802400C0 2404002D */  addiu     $a0, $zero, 0x2d
/* B97CC4 802400C4 34420800 */  ori       $v0, $v0, 0x800
/* B97CC8 802400C8 0C00A67F */  jal       rand_int
/* B97CCC 802400CC AE020000 */   sw       $v0, ($s0)
/* B97CD0 802400D0 0200202D */  daddu     $a0, $s0, $zero
/* B97CD4 802400D4 3C05B000 */  lui       $a1, 0xb000
/* B97CD8 802400D8 34A50017 */  ori       $a1, $a1, 0x17
/* B97CDC 802400DC 44820000 */  mtc1      $v0, $f0
/* B97CE0 802400E0 00000000 */  nop
/* B97CE4 802400E4 46800021 */  cvt.d.w   $f0, $f0
/* B97CE8 802400E8 3C014024 */  lui       $at, 0x4024
/* B97CEC 802400EC 44811800 */  mtc1      $at, $f3
/* B97CF0 802400F0 44801000 */  mtc1      $zero, $f2
/* B97CF4 802400F4 3C014020 */  lui       $at, 0x4020
/* B97CF8 802400F8 44812800 */  mtc1      $at, $f5
/* B97CFC 802400FC 44802000 */  mtc1      $zero, $f4
/* B97D00 80240100 46220003 */  div.d     $f0, $f0, $f2
/* B97D04 80240104 46240000 */  add.d     $f0, $f0, $f4
/* B97D08 80240108 3C013FC0 */  lui       $at, 0x3fc0
/* B97D0C 8024010C 44811000 */  mtc1      $at, $f2
/* B97D10 80240110 0000302D */  daddu     $a2, $zero, $zero
/* B97D14 80240114 E6020014 */  swc1      $f2, 0x14($s0)
/* B97D18 80240118 46200020 */  cvt.s.d   $f0, $f0
/* B97D1C 8024011C 0C012530 */  jal       func_800494C0
/* B97D20 80240120 E600001C */   swc1     $f0, 0x1c($s0)
/* B97D24 80240124 8E6300D0 */  lw        $v1, 0xd0($s3)
/* B97D28 80240128 C6000040 */  lwc1      $f0, 0x40($s0)
/* B97D2C 8024012C C4620000 */  lwc1      $f2, ($v1)
/* B97D30 80240130 468010A0 */  cvt.s.w   $f2, $f2
/* B97D34 80240134 C4640008 */  lwc1      $f4, 8($v1)
/* B97D38 80240138 46802120 */  cvt.s.w   $f4, $f4
/* B97D3C 8024013C E7A00010 */  swc1      $f0, 0x10($sp)
/* B97D40 80240140 8E6200D0 */  lw        $v0, 0xd0($s3)
/* B97D44 80240144 44051000 */  mfc1      $a1, $f2
/* B97D48 80240148 C440000C */  lwc1      $f0, 0xc($v0)
/* B97D4C 8024014C 46800020 */  cvt.s.w   $f0, $f0
/* B97D50 80240150 E7A00014 */  swc1      $f0, 0x14($sp)
/* B97D54 80240154 8E6200D0 */  lw        $v0, 0xd0($s3)
/* B97D58 80240158 44062000 */  mfc1      $a2, $f4
/* B97D5C 8024015C C4400010 */  lwc1      $f0, 0x10($v0)
/* B97D60 80240160 46800020 */  cvt.s.w   $f0, $f0
/* B97D64 80240164 E7A00018 */  swc1      $f0, 0x18($sp)
/* B97D68 80240168 8C640018 */  lw        $a0, 0x18($v1)
/* B97D6C 8024016C 0C0123F5 */  jal       is_point_within_region
/* B97D70 80240170 8E070038 */   lw       $a3, 0x38($s0)
/* B97D74 80240174 10400035 */  beqz      $v0, .L8024024C
/* B97D78 80240178 00000000 */   nop
/* B97D7C 8024017C C60C0038 */  lwc1      $f12, 0x38($s0)
/* B97D80 80240180 3C0141C8 */  lui       $at, 0x41c8
/* B97D84 80240184 4481B000 */  mtc1      $at, $f22
/* B97D88 80240188 8E6200D0 */  lw        $v0, 0xd0($s3)
/* B97D8C 8024018C C60E0040 */  lwc1      $f14, 0x40($s0)
/* B97D90 80240190 C4480000 */  lwc1      $f8, ($v0)
/* B97D94 80240194 46804220 */  cvt.s.w   $f8, $f8
/* B97D98 80240198 44064000 */  mfc1      $a2, $f8
/* B97D9C 8024019C C4480008 */  lwc1      $f8, 8($v0)
/* B97DA0 802401A0 46804220 */  cvt.s.w   $f8, $f8
/* B97DA4 802401A4 44074000 */  mfc1      $a3, $f8
/* B97DA8 802401A8 3C01403E */  lui       $at, 0x403e
/* B97DAC 802401AC 4481A800 */  mtc1      $at, $f21
/* B97DB0 802401B0 4480A000 */  mtc1      $zero, $f20
/* B97DB4 802401B4 0C00A720 */  jal       atan2
/* B97DB8 802401B8 0000882D */   daddu    $s1, $zero, $zero
/* B97DBC 802401BC C6020038 */  lwc1      $f2, 0x38($s0)
/* B97DC0 802401C0 C604003C */  lwc1      $f4, 0x3c($s0)
/* B97DC4 802401C4 C6060040 */  lwc1      $f6, 0x40($s0)
/* B97DC8 802401C8 E600000C */  swc1      $f0, 0xc($s0)
/* B97DCC 802401CC E7A20020 */  swc1      $f2, 0x20($sp)
/* B97DD0 802401D0 E7A40024 */  swc1      $f4, 0x24($sp)
/* B97DD4 802401D4 E7A60028 */  swc1      $f6, 0x28($sp)
.L802401D8:
/* B97DD8 802401D8 E7B60010 */  swc1      $f22, 0x10($sp)
/* B97DDC 802401DC C600000C */  lwc1      $f0, 0xc($s0)
/* B97DE0 802401E0 E7A00014 */  swc1      $f0, 0x14($sp)
/* B97DE4 802401E4 860200A8 */  lh        $v0, 0xa8($s0)
/* B97DE8 802401E8 27A50020 */  addiu     $a1, $sp, 0x20
/* B97DEC 802401EC 44820000 */  mtc1      $v0, $f0
/* B97DF0 802401F0 00000000 */  nop
/* B97DF4 802401F4 46800020 */  cvt.s.w   $f0, $f0
/* B97DF8 802401F8 E7A00018 */  swc1      $f0, 0x18($sp)
/* B97DFC 802401FC 860200A6 */  lh        $v0, 0xa6($s0)
/* B97E00 80240200 27A60024 */  addiu     $a2, $sp, 0x24
/* B97E04 80240204 44820000 */  mtc1      $v0, $f0
/* B97E08 80240208 00000000 */  nop
/* B97E0C 8024020C 46800020 */  cvt.s.w   $f0, $f0
/* B97E10 80240210 E7A0001C */  swc1      $f0, 0x1c($sp)
/* B97E14 80240214 8E040080 */  lw        $a0, 0x80($s0)
/* B97E18 80240218 0C037711 */  jal       func_800DDC44
/* B97E1C 8024021C 27A70028 */   addiu    $a3, $sp, 0x28
/* B97E20 80240220 10400016 */  beqz      $v0, .L8024027C
/* B97E24 80240224 26310001 */   addiu    $s1, $s1, 1
/* B97E28 80240228 C600000C */  lwc1      $f0, 0xc($s0)
/* B97E2C 8024022C 46000021 */  cvt.d.s   $f0, $f0
/* B97E30 80240230 46340000 */  add.d     $f0, $f0, $f20
/* B97E34 80240234 2A220006 */  slti      $v0, $s1, 6
/* B97E38 80240238 46200020 */  cvt.s.d   $f0, $f0
/* B97E3C 8024023C 1440FFE6 */  bnez      $v0, .L802401D8
/* B97E40 80240240 E600000C */   swc1     $f0, 0xc($s0)
/* B97E44 80240244 0809009F */  j         .L8024027C
/* B97E48 80240248 00000000 */   nop
.L8024024C:
/* B97E4C 8024024C 0C00A67F */  jal       rand_int
/* B97E50 80240250 2404003C */   addiu    $a0, $zero, 0x3c
/* B97E54 80240254 C60C000C */  lwc1      $f12, 0xc($s0)
/* B97E58 80240258 44820000 */  mtc1      $v0, $f0
/* B97E5C 8024025C 00000000 */  nop
/* B97E60 80240260 46800020 */  cvt.s.w   $f0, $f0
/* B97E64 80240264 46006300 */  add.s     $f12, $f12, $f0
/* B97E68 80240268 3C0141F0 */  lui       $at, 0x41f0
/* B97E6C 8024026C 44810000 */  mtc1      $at, $f0
/* B97E70 80240270 0C00A6C9 */  jal       clamp_angle
/* B97E74 80240274 46006301 */   sub.s    $f12, $f12, $f0
/* B97E78 80240278 E600000C */  swc1      $f0, 0xc($s0)
.L8024027C:
/* B97E7C 8024027C 8FBF0040 */  lw        $ra, 0x40($sp)
/* B97E80 80240280 8FB3003C */  lw        $s3, 0x3c($sp)
/* B97E84 80240284 8FB20038 */  lw        $s2, 0x38($sp)
/* B97E88 80240288 8FB10034 */  lw        $s1, 0x34($sp)
/* B97E8C 8024028C 8FB00030 */  lw        $s0, 0x30($sp)
/* B97E90 80240290 D7B60050 */  ldc1      $f22, 0x50($sp)
/* B97E94 80240294 D7B40048 */  ldc1      $f20, 0x48($sp)
/* B97E98 80240298 03E00008 */  jr        $ra
/* B97E9C 8024029C 27BD0058 */   addiu    $sp, $sp, 0x58
