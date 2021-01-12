.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240200_B9DB60
/* B9DB60 80240200 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* B9DB64 80240204 AFB00030 */  sw        $s0, 0x30($sp)
/* B9DB68 80240208 0080802D */  daddu     $s0, $a0, $zero
/* B9DB6C 8024020C AFBF0040 */  sw        $ra, 0x40($sp)
/* B9DB70 80240210 AFB3003C */  sw        $s3, 0x3c($sp)
/* B9DB74 80240214 AFB20038 */  sw        $s2, 0x38($sp)
/* B9DB78 80240218 AFB10034 */  sw        $s1, 0x34($sp)
/* B9DB7C 8024021C F7B60050 */  sdc1      $f22, 0x50($sp)
/* B9DB80 80240220 F7B40048 */  sdc1      $f20, 0x48($sp)
/* B9DB84 80240224 8E130148 */  lw        $s3, 0x148($s0)
/* B9DB88 80240228 00A0882D */  daddu     $s1, $a1, $zero
/* B9DB8C 8024022C 86640008 */  lh        $a0, 8($s3)
/* B9DB90 80240230 0C00EABB */  jal       get_npc_unsafe
/* B9DB94 80240234 00C0902D */   daddu    $s2, $a2, $zero
/* B9DB98 80240238 0200202D */  daddu     $a0, $s0, $zero
/* B9DB9C 8024023C 0220282D */  daddu     $a1, $s1, $zero
/* B9DBA0 80240240 0240302D */  daddu     $a2, $s2, $zero
/* B9DBA4 80240244 0C012568 */  jal       func_800495A0
/* B9DBA8 80240248 0040802D */   daddu    $s0, $v0, $zero
/* B9DBAC 8024024C 8E020000 */  lw        $v0, ($s0)
/* B9DBB0 80240250 2404002D */  addiu     $a0, $zero, 0x2d
/* B9DBB4 80240254 34420800 */  ori       $v0, $v0, 0x800
/* B9DBB8 80240258 0C00A67F */  jal       rand_int
/* B9DBBC 8024025C AE020000 */   sw       $v0, ($s0)
/* B9DBC0 80240260 0200202D */  daddu     $a0, $s0, $zero
/* B9DBC4 80240264 3C05B000 */  lui       $a1, 0xb000
/* B9DBC8 80240268 34A50017 */  ori       $a1, $a1, 0x17
/* B9DBCC 8024026C 44820000 */  mtc1      $v0, $f0
/* B9DBD0 80240270 00000000 */  nop
/* B9DBD4 80240274 46800021 */  cvt.d.w   $f0, $f0
/* B9DBD8 80240278 3C014024 */  lui       $at, 0x4024
/* B9DBDC 8024027C 44811800 */  mtc1      $at, $f3
/* B9DBE0 80240280 44801000 */  mtc1      $zero, $f2
/* B9DBE4 80240284 3C014020 */  lui       $at, 0x4020
/* B9DBE8 80240288 44812800 */  mtc1      $at, $f5
/* B9DBEC 8024028C 44802000 */  mtc1      $zero, $f4
/* B9DBF0 80240290 46220003 */  div.d     $f0, $f0, $f2
/* B9DBF4 80240294 46240000 */  add.d     $f0, $f0, $f4
/* B9DBF8 80240298 3C013FC0 */  lui       $at, 0x3fc0
/* B9DBFC 8024029C 44811000 */  mtc1      $at, $f2
/* B9DC00 802402A0 0000302D */  daddu     $a2, $zero, $zero
/* B9DC04 802402A4 E6020014 */  swc1      $f2, 0x14($s0)
/* B9DC08 802402A8 46200020 */  cvt.s.d   $f0, $f0
/* B9DC0C 802402AC 0C012530 */  jal       func_800494C0
/* B9DC10 802402B0 E600001C */   swc1     $f0, 0x1c($s0)
/* B9DC14 802402B4 8E6300D0 */  lw        $v1, 0xd0($s3)
/* B9DC18 802402B8 C6000040 */  lwc1      $f0, 0x40($s0)
/* B9DC1C 802402BC C4620000 */  lwc1      $f2, ($v1)
/* B9DC20 802402C0 468010A0 */  cvt.s.w   $f2, $f2
/* B9DC24 802402C4 C4640008 */  lwc1      $f4, 8($v1)
/* B9DC28 802402C8 46802120 */  cvt.s.w   $f4, $f4
/* B9DC2C 802402CC E7A00010 */  swc1      $f0, 0x10($sp)
/* B9DC30 802402D0 8E6200D0 */  lw        $v0, 0xd0($s3)
/* B9DC34 802402D4 44051000 */  mfc1      $a1, $f2
/* B9DC38 802402D8 C440000C */  lwc1      $f0, 0xc($v0)
/* B9DC3C 802402DC 46800020 */  cvt.s.w   $f0, $f0
/* B9DC40 802402E0 E7A00014 */  swc1      $f0, 0x14($sp)
/* B9DC44 802402E4 8E6200D0 */  lw        $v0, 0xd0($s3)
/* B9DC48 802402E8 44062000 */  mfc1      $a2, $f4
/* B9DC4C 802402EC C4400010 */  lwc1      $f0, 0x10($v0)
/* B9DC50 802402F0 46800020 */  cvt.s.w   $f0, $f0
/* B9DC54 802402F4 E7A00018 */  swc1      $f0, 0x18($sp)
/* B9DC58 802402F8 8C640018 */  lw        $a0, 0x18($v1)
/* B9DC5C 802402FC 0C0123F5 */  jal       is_point_within_region
/* B9DC60 80240300 8E070038 */   lw       $a3, 0x38($s0)
/* B9DC64 80240304 10400035 */  beqz      $v0, .L802403DC
/* B9DC68 80240308 00000000 */   nop
/* B9DC6C 8024030C C60C0038 */  lwc1      $f12, 0x38($s0)
/* B9DC70 80240310 3C0141C8 */  lui       $at, 0x41c8
/* B9DC74 80240314 4481B000 */  mtc1      $at, $f22
/* B9DC78 80240318 8E6200D0 */  lw        $v0, 0xd0($s3)
/* B9DC7C 8024031C C60E0040 */  lwc1      $f14, 0x40($s0)
/* B9DC80 80240320 C4480000 */  lwc1      $f8, ($v0)
/* B9DC84 80240324 46804220 */  cvt.s.w   $f8, $f8
/* B9DC88 80240328 44064000 */  mfc1      $a2, $f8
/* B9DC8C 8024032C C4480008 */  lwc1      $f8, 8($v0)
/* B9DC90 80240330 46804220 */  cvt.s.w   $f8, $f8
/* B9DC94 80240334 44074000 */  mfc1      $a3, $f8
/* B9DC98 80240338 3C01403E */  lui       $at, 0x403e
/* B9DC9C 8024033C 4481A800 */  mtc1      $at, $f21
/* B9DCA0 80240340 4480A000 */  mtc1      $zero, $f20
/* B9DCA4 80240344 0C00A720 */  jal       atan2
/* B9DCA8 80240348 0000882D */   daddu    $s1, $zero, $zero
/* B9DCAC 8024034C C6020038 */  lwc1      $f2, 0x38($s0)
/* B9DCB0 80240350 C604003C */  lwc1      $f4, 0x3c($s0)
/* B9DCB4 80240354 C6060040 */  lwc1      $f6, 0x40($s0)
/* B9DCB8 80240358 E600000C */  swc1      $f0, 0xc($s0)
/* B9DCBC 8024035C E7A20020 */  swc1      $f2, 0x20($sp)
/* B9DCC0 80240360 E7A40024 */  swc1      $f4, 0x24($sp)
/* B9DCC4 80240364 E7A60028 */  swc1      $f6, 0x28($sp)
.L80240368:
/* B9DCC8 80240368 E7B60010 */  swc1      $f22, 0x10($sp)
/* B9DCCC 8024036C C600000C */  lwc1      $f0, 0xc($s0)
/* B9DCD0 80240370 E7A00014 */  swc1      $f0, 0x14($sp)
/* B9DCD4 80240374 860200A8 */  lh        $v0, 0xa8($s0)
/* B9DCD8 80240378 27A50020 */  addiu     $a1, $sp, 0x20
/* B9DCDC 8024037C 44820000 */  mtc1      $v0, $f0
/* B9DCE0 80240380 00000000 */  nop
/* B9DCE4 80240384 46800020 */  cvt.s.w   $f0, $f0
/* B9DCE8 80240388 E7A00018 */  swc1      $f0, 0x18($sp)
/* B9DCEC 8024038C 860200A6 */  lh        $v0, 0xa6($s0)
/* B9DCF0 80240390 27A60024 */  addiu     $a2, $sp, 0x24
/* B9DCF4 80240394 44820000 */  mtc1      $v0, $f0
/* B9DCF8 80240398 00000000 */  nop
/* B9DCFC 8024039C 46800020 */  cvt.s.w   $f0, $f0
/* B9DD00 802403A0 E7A0001C */  swc1      $f0, 0x1c($sp)
/* B9DD04 802403A4 8E040080 */  lw        $a0, 0x80($s0)
/* B9DD08 802403A8 0C037711 */  jal       func_800DDC44
/* B9DD0C 802403AC 27A70028 */   addiu    $a3, $sp, 0x28
/* B9DD10 802403B0 10400016 */  beqz      $v0, .L8024040C
/* B9DD14 802403B4 26310001 */   addiu    $s1, $s1, 1
/* B9DD18 802403B8 C600000C */  lwc1      $f0, 0xc($s0)
/* B9DD1C 802403BC 46000021 */  cvt.d.s   $f0, $f0
/* B9DD20 802403C0 46340000 */  add.d     $f0, $f0, $f20
/* B9DD24 802403C4 2A220006 */  slti      $v0, $s1, 6
/* B9DD28 802403C8 46200020 */  cvt.s.d   $f0, $f0
/* B9DD2C 802403CC 1440FFE6 */  bnez      $v0, .L80240368
/* B9DD30 802403D0 E600000C */   swc1     $f0, 0xc($s0)
/* B9DD34 802403D4 08090103 */  j         .L8024040C
/* B9DD38 802403D8 00000000 */   nop
.L802403DC:
/* B9DD3C 802403DC 0C00A67F */  jal       rand_int
/* B9DD40 802403E0 2404003C */   addiu    $a0, $zero, 0x3c
/* B9DD44 802403E4 C60C000C */  lwc1      $f12, 0xc($s0)
/* B9DD48 802403E8 44820000 */  mtc1      $v0, $f0
/* B9DD4C 802403EC 00000000 */  nop
/* B9DD50 802403F0 46800020 */  cvt.s.w   $f0, $f0
/* B9DD54 802403F4 46006300 */  add.s     $f12, $f12, $f0
/* B9DD58 802403F8 3C0141F0 */  lui       $at, 0x41f0
/* B9DD5C 802403FC 44810000 */  mtc1      $at, $f0
/* B9DD60 80240400 0C00A6C9 */  jal       clamp_angle
/* B9DD64 80240404 46006301 */   sub.s    $f12, $f12, $f0
/* B9DD68 80240408 E600000C */  swc1      $f0, 0xc($s0)
.L8024040C:
/* B9DD6C 8024040C 8FBF0040 */  lw        $ra, 0x40($sp)
/* B9DD70 80240410 8FB3003C */  lw        $s3, 0x3c($sp)
/* B9DD74 80240414 8FB20038 */  lw        $s2, 0x38($sp)
/* B9DD78 80240418 8FB10034 */  lw        $s1, 0x34($sp)
/* B9DD7C 8024041C 8FB00030 */  lw        $s0, 0x30($sp)
/* B9DD80 80240420 D7B60050 */  ldc1      $f22, 0x50($sp)
/* B9DD84 80240424 D7B40048 */  ldc1      $f20, 0x48($sp)
/* B9DD88 80240428 03E00008 */  jr        $ra
/* B9DD8C 8024042C 27BD0058 */   addiu    $sp, $sp, 0x58
