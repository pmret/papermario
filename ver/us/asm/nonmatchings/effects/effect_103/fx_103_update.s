.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_103_update
/* 3D2CE4 E00CE224 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3D2CE8 E00CE228 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3D2CEC E00CE22C 8C830000 */  lw        $v1, ($a0)
/* 3D2CF0 E00CE230 8C85000C */  lw        $a1, 0xc($a0)
/* 3D2CF4 E00CE234 30620010 */  andi      $v0, $v1, 0x10
/* 3D2CF8 E00CE238 10400005 */  beqz      $v0, .LE00CE250
/* 3D2CFC E00CE23C 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3D2D00 E00CE240 00621024 */  and       $v0, $v1, $v0
/* 3D2D04 E00CE244 AC820000 */  sw        $v0, ($a0)
/* 3D2D08 E00CE248 24020010 */  addiu     $v0, $zero, 0x10
/* 3D2D0C E00CE24C ACA20010 */  sw        $v0, 0x10($a1)
.LE00CE250:
/* 3D2D10 E00CE250 8CA30010 */  lw        $v1, 0x10($a1)
/* 3D2D14 E00CE254 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3D2D18 E00CE258 10400002 */  beqz      $v0, .LE00CE264
/* 3D2D1C E00CE25C 2462FFFF */   addiu    $v0, $v1, -1
/* 3D2D20 E00CE260 ACA20010 */  sw        $v0, 0x10($a1)
.LE00CE264:
/* 3D2D24 E00CE264 8CA20014 */  lw        $v0, 0x14($a1)
/* 3D2D28 E00CE268 8CA30010 */  lw        $v1, 0x10($a1)
/* 3D2D2C E00CE26C 24460001 */  addiu     $a2, $v0, 1
/* 3D2D30 E00CE270 04610005 */  bgez      $v1, .LE00CE288
/* 3D2D34 E00CE274 ACA60014 */   sw       $a2, 0x14($a1)
/* 3D2D38 E00CE278 0C080128 */  jal       shim_remove_effect
/* 3D2D3C E00CE27C 00000000 */   nop
/* 3D2D40 E00CE280 08033907 */  j         .LE00CE41C
/* 3D2D44 E00CE284 00000000 */   nop
.LE00CE288:
/* 3D2D48 E00CE288 C4AC0034 */  lwc1      $f12, 0x34($a1)
/* 3D2D4C E00CE28C 28620010 */  slti      $v0, $v1, 0x10
/* 3D2D50 E00CE290 10400002 */  beqz      $v0, .LE00CE29C
/* 3D2D54 E00CE294 00031100 */   sll      $v0, $v1, 4
/* 3D2D58 E00CE298 ACA20024 */  sw        $v0, 0x24($a1)
.LE00CE29C:
/* 3D2D5C E00CE29C 28C20010 */  slti      $v0, $a2, 0x10
/* 3D2D60 E00CE2A0 10400003 */  beqz      $v0, .LE00CE2B0
/* 3D2D64 E00CE2A4 00061100 */   sll      $v0, $a2, 4
/* 3D2D68 E00CE2A8 2442000F */  addiu     $v0, $v0, 0xf
/* 3D2D6C E00CE2AC ACA20024 */  sw        $v0, 0x24($a1)
.LE00CE2B0:
/* 3D2D70 E00CE2B0 24040007 */  addiu     $a0, $zero, 7
/* 3D2D74 E00CE2B4 24060018 */  addiu     $a2, $zero, 0x18
/* 3D2D78 E00CE2B8 24A3001C */  addiu     $v1, $a1, 0x1c
/* 3D2D7C E00CE2BC 3C014080 */  lui       $at, 0x4080
/* 3D2D80 E00CE2C0 44817000 */  mtc1      $at, $f14
/* 3D2D84 E00CE2C4 3C0142B4 */  lui       $at, 0x42b4
/* 3D2D88 E00CE2C8 44815000 */  mtc1      $at, $f10
/* 3D2D8C E00CE2CC 3C01C2B4 */  lui       $at, 0xc2b4
/* 3D2D90 E00CE2D0 44814000 */  mtc1      $at, $f8
/* 3D2D94 E00CE2D4 C4A40004 */  lwc1      $f4, 4($a1)
/* 3D2D98 E00CE2D8 C4A60008 */  lwc1      $f6, 8($a1)
/* 3D2D9C E00CE2DC 3C0140A0 */  lui       $at, 0x40a0
/* 3D2DA0 E00CE2E0 44810000 */  mtc1      $at, $f0
/* 3D2DA4 E00CE2E4 C4A2000C */  lwc1      $f2, 0xc($a1)
/* 3D2DA8 E00CE2E8 46006302 */  mul.s     $f12, $f12, $f0
/* 3D2DAC E00CE2EC 00000000 */  nop
/* 3D2DB0 E00CE2F0 E4A40038 */  swc1      $f4, 0x38($a1)
/* 3D2DB4 E00CE2F4 E4A60058 */  swc1      $f6, 0x58($a1)
/* 3D2DB8 E00CE2F8 E4A20078 */  swc1      $f2, 0x78($a1)
.LE00CE2FC:
/* 3D2DBC E00CE2FC 00A61021 */  addu      $v0, $a1, $a2
/* 3D2DC0 E00CE300 C4400038 */  lwc1      $f0, 0x38($v0)
/* 3D2DC4 E00CE304 C4620038 */  lwc1      $f2, 0x38($v1)
/* 3D2DC8 E00CE308 46020001 */  sub.s     $f0, $f0, $f2
/* 3D2DCC E00CE30C 460E0002 */  mul.s     $f0, $f0, $f14
/* 3D2DD0 E00CE310 00000000 */  nop
/* 3D2DD4 E00CE314 E4600118 */  swc1      $f0, 0x118($v1)
/* 3D2DD8 E00CE318 C4400038 */  lwc1      $f0, 0x38($v0)
/* 3D2DDC E00CE31C E4600038 */  swc1      $f0, 0x38($v1)
/* 3D2DE0 E00CE320 C4400058 */  lwc1      $f0, 0x58($v0)
/* 3D2DE4 E00CE324 460C0000 */  add.s     $f0, $f0, $f12
/* 3D2DE8 E00CE328 C4620118 */  lwc1      $f2, 0x118($v1)
/* 3D2DEC E00CE32C E4600058 */  swc1      $f0, 0x58($v1)
/* 3D2DF0 E00CE330 C4400078 */  lwc1      $f0, 0x78($v0)
/* 3D2DF4 E00CE334 4602503C */  c.lt.s    $f10, $f2
/* 3D2DF8 E00CE338 00000000 */  nop
/* 3D2DFC E00CE33C 45000003 */  bc1f      .LE00CE34C
/* 3D2E00 E00CE340 E4600078 */   swc1     $f0, 0x78($v1)
/* 3D2E04 E00CE344 080338D7 */  j         .LE00CE35C
/* 3D2E08 E00CE348 E46A0118 */   swc1     $f10, 0x118($v1)
.LE00CE34C:
/* 3D2E0C E00CE34C 4608103C */  c.lt.s    $f2, $f8
/* 3D2E10 E00CE350 00000000 */  nop
/* 3D2E14 E00CE354 45030001 */  bc1tl     .LE00CE35C
/* 3D2E18 E00CE358 E4680118 */   swc1     $f8, 0x118($v1)
.LE00CE35C:
/* 3D2E1C E00CE35C 24C6FFFC */  addiu     $a2, $a2, -4
/* 3D2E20 E00CE360 2484FFFF */  addiu     $a0, $a0, -1
/* 3D2E24 E00CE364 1C80FFE5 */  bgtz      $a0, .LE00CE2FC
/* 3D2E28 E00CE368 2463FFFC */   addiu    $v1, $v1, -4
/* 3D2E2C E00CE36C C4A40138 */  lwc1      $f4, 0x138($a1)
/* 3D2E30 E00CE370 3C014120 */  lui       $at, 0x4120
/* 3D2E34 E00CE374 44810000 */  mtc1      $at, $f0
/* 3D2E38 E00CE378 00000000 */  nop
/* 3D2E3C E00CE37C 46002100 */  add.s     $f4, $f4, $f0
/* 3D2E40 E00CE380 C4A0013C */  lwc1      $f0, 0x13c($a1)
/* 3D2E44 E00CE384 3C01E00D */  lui       $at, %hi(D_E00CEE60)
/* 3D2E48 E00CE388 D422EE60 */  ldc1      $f2, %lo(D_E00CEE60)($at)
/* 3D2E4C E00CE38C 46000021 */  cvt.d.s   $f0, $f0
/* 3D2E50 E00CE390 46220000 */  add.d     $f0, $f0, $f2
/* 3D2E54 E00CE394 3C01E00D */  lui       $at, %hi(D_E00CEE68)
/* 3D2E58 E00CE398 D422EE68 */  ldc1      $f2, %lo(D_E00CEE68)($at)
/* 3D2E5C E00CE39C E4A40138 */  swc1      $f4, 0x138($a1)
/* 3D2E60 E00CE3A0 46200020 */  cvt.s.d   $f0, $f0
/* 3D2E64 E00CE3A4 E4A0013C */  swc1      $f0, 0x13c($a1)
/* 3D2E68 E00CE3A8 C4A00140 */  lwc1      $f0, 0x140($a1)
/* 3D2E6C E00CE3AC C4A4013C */  lwc1      $f4, 0x13c($a1)
/* 3D2E70 E00CE3B0 46000021 */  cvt.d.s   $f0, $f0
/* 3D2E74 E00CE3B4 46220000 */  add.d     $f0, $f0, $f2
/* 3D2E78 E00CE3B8 3C014280 */  lui       $at, 0x4280
/* 3D2E7C E00CE3BC 44811000 */  mtc1      $at, $f2
/* 3D2E80 E00CE3C0 00000000 */  nop
/* 3D2E84 E00CE3C4 4604103C */  c.lt.s    $f2, $f4
/* 3D2E88 E00CE3C8 46200020 */  cvt.s.d   $f0, $f0
/* 3D2E8C E00CE3CC 45000003 */  bc1f      .LE00CE3DC
/* 3D2E90 E00CE3D0 E4A00140 */   swc1     $f0, 0x140($a1)
/* 3D2E94 E00CE3D4 46022001 */  sub.s     $f0, $f4, $f2
/* 3D2E98 E00CE3D8 E4A0013C */  swc1      $f0, 0x13c($a1)
.LE00CE3DC:
/* 3D2E9C E00CE3DC C4A00140 */  lwc1      $f0, 0x140($a1)
/* 3D2EA0 E00CE3E0 4600103C */  c.lt.s    $f2, $f0
/* 3D2EA4 E00CE3E4 00000000 */  nop
/* 3D2EA8 E00CE3E8 45000003 */  bc1f      .LE00CE3F8
/* 3D2EAC E00CE3EC 0000202D */   daddu    $a0, $zero, $zero
/* 3D2EB0 E00CE3F0 46020001 */  sub.s     $f0, $f0, $f2
/* 3D2EB4 E00CE3F4 E4A00140 */  swc1      $f0, 0x140($a1)
.LE00CE3F8:
/* 3D2EB8 E00CE3F8 00A0182D */  daddu     $v1, $a1, $zero
.LE00CE3FC:
/* 3D2EBC E00CE3FC C46000B8 */  lwc1      $f0, 0xb8($v1)
/* 3D2EC0 E00CE400 C46200D8 */  lwc1      $f2, 0xd8($v1)
/* 3D2EC4 E00CE404 46020000 */  add.s     $f0, $f0, $f2
/* 3D2EC8 E00CE408 24840001 */  addiu     $a0, $a0, 1
/* 3D2ECC E00CE40C 28820008 */  slti      $v0, $a0, 8
/* 3D2ED0 E00CE410 E46000B8 */  swc1      $f0, 0xb8($v1)
/* 3D2ED4 E00CE414 1440FFF9 */  bnez      $v0, .LE00CE3FC
/* 3D2ED8 E00CE418 24630004 */   addiu    $v1, $v1, 4
.LE00CE41C:
/* 3D2EDC E00CE41C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3D2EE0 E00CE420 03E00008 */  jr        $ra
/* 3D2EE4 E00CE424 27BD0018 */   addiu    $sp, $sp, 0x18
