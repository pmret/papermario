.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD100_31DE70
/* 31DE70 802BD100 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31DE74 802BD104 2404FFFC */  addiu     $a0, $zero, -4
/* 31DE78 802BD108 AFBF0014 */  sw        $ra, 0x14($sp)
/* 31DE7C 802BD10C 0C00EABB */  jal       get_npc_unsafe
/* 31DE80 802BD110 AFB00010 */   sw       $s0, 0x10($sp)
/* 31DE84 802BD114 C4400038 */  lwc1      $f0, 0x38($v0)
/* 31DE88 802BD118 3C014180 */  lui       $at, 0x4180
/* 31DE8C 802BD11C 44811000 */  mtc1      $at, $f2
/* 31DE90 802BD120 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 31DE94 802BD124 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 31DE98 802BD128 E6000028 */  swc1      $f0, 0x28($s0)
/* 31DE9C 802BD12C C440003C */  lwc1      $f0, 0x3c($v0)
/* 31DEA0 802BD130 46020000 */  add.s     $f0, $f0, $f2
/* 31DEA4 802BD134 C60400A8 */  lwc1      $f4, 0xa8($s0)
/* 31DEA8 802BD138 E600002C */  swc1      $f0, 0x2c($s0)
/* 31DEAC 802BD13C C4400040 */  lwc1      $f0, 0x40($v0)
/* 31DEB0 802BD140 E6000030 */  swc1      $f0, 0x30($s0)
/* 31DEB4 802BD144 3C0142B4 */  lui       $at, 0x42b4
/* 31DEB8 802BD148 44810000 */  mtc1      $at, $f0
/* 31DEBC 802BD14C C442000C */  lwc1      $f2, 0xc($v0)
/* 31DEC0 802BD150 4600203C */  c.lt.s    $f4, $f0
/* 31DEC4 802BD154 00000000 */  nop
/* 31DEC8 802BD158 45010008 */  bc1t      .L802BD17C
/* 31DECC 802BD15C E6020080 */   swc1     $f2, 0x80($s0)
/* 31DED0 802BD160 3C014387 */  lui       $at, 0x4387
/* 31DED4 802BD164 44810000 */  mtc1      $at, $f0
/* 31DED8 802BD168 00000000 */  nop
/* 31DEDC 802BD16C 4604003C */  c.lt.s    $f0, $f4
/* 31DEE0 802BD170 00000000 */  nop
/* 31DEE4 802BD174 45000002 */  bc1f      .L802BD180
/* 31DEE8 802BD178 24030008 */   addiu    $v1, $zero, 8
.L802BD17C:
/* 31DEEC 802BD17C 2403FFF8 */  addiu     $v1, $zero, -8
.L802BD180:
/* 31DEF0 802BD180 3C02800B */  lui       $v0, %hi(gCameras)
/* 31DEF4 802BD184 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 31DEF8 802BD188 C44C006C */  lwc1      $f12, 0x6c($v0)
/* 31DEFC 802BD18C C60000A8 */  lwc1      $f0, 0xa8($s0)
/* 31DF00 802BD190 46006300 */  add.s     $f12, $f12, $f0
/* 31DF04 802BD194 3C0142B4 */  lui       $at, 0x42b4
/* 31DF08 802BD198 44810000 */  mtc1      $at, $f0
/* 31DF0C 802BD19C 00000000 */  nop
/* 31DF10 802BD1A0 46006301 */  sub.s     $f12, $f12, $f0
/* 31DF14 802BD1A4 44830000 */  mtc1      $v1, $f0
/* 31DF18 802BD1A8 00000000 */  nop
/* 31DF1C 802BD1AC 46800020 */  cvt.s.w   $f0, $f0
/* 31DF20 802BD1B0 46006300 */  add.s     $f12, $f12, $f0
/* 31DF24 802BD1B4 3C0140C9 */  lui       $at, 0x40c9
/* 31DF28 802BD1B8 34210FD0 */  ori       $at, $at, 0xfd0
/* 31DF2C 802BD1BC 44810000 */  mtc1      $at, $f0
/* 31DF30 802BD1C0 00000000 */  nop
/* 31DF34 802BD1C4 46006302 */  mul.s     $f12, $f12, $f0
/* 31DF38 802BD1C8 00000000 */  nop
/* 31DF3C 802BD1CC 3C0143B4 */  lui       $at, 0x43b4
/* 31DF40 802BD1D0 44810000 */  mtc1      $at, $f0
/* 31DF44 802BD1D4 0C00A874 */  jal       cos_rad
/* 31DF48 802BD1D8 46006303 */   div.s    $f12, $f12, $f0
/* 31DF4C 802BD1DC 3C01C080 */  lui       $at, 0xc080
/* 31DF50 802BD1E0 44811000 */  mtc1      $at, $f2
/* 31DF54 802BD1E4 00000000 */  nop
/* 31DF58 802BD1E8 46020002 */  mul.s     $f0, $f0, $f2
/* 31DF5C 802BD1EC 00000000 */  nop
/* 31DF60 802BD1F0 C6020030 */  lwc1      $f2, 0x30($s0)
/* 31DF64 802BD1F4 46001081 */  sub.s     $f2, $f2, $f0
/* 31DF68 802BD1F8 E6020030 */  swc1      $f2, 0x30($s0)
/* 31DF6C 802BD1FC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 31DF70 802BD200 8FB00010 */  lw        $s0, 0x10($sp)
/* 31DF74 802BD204 03E00008 */  jr        $ra
/* 31DF78 802BD208 27BD0018 */   addiu    $sp, $sp, 0x18
