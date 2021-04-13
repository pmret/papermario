.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003DE90
/* 19290 8003DE90 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19294 8003DE94 AFB00018 */  sw        $s0, 0x18($sp)
/* 19298 8003DE98 0080802D */  daddu     $s0, $a0, $zero
/* 1929C 8003DE9C 3C048007 */  lui       $a0, %hi(D_80077C0A)
/* 192A0 8003DEA0 24847C0A */  addiu     $a0, $a0, %lo(D_80077C0A)
/* 192A4 8003DEA4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 192A8 8003DEA8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 192AC 8003DEAC 94820000 */  lhu       $v0, ($a0)
/* 192B0 8003DEB0 24430001 */  addiu     $v1, $v0, 1
/* 192B4 8003DEB4 00021400 */  sll       $v0, $v0, 0x10
/* 192B8 8003DEB8 00021403 */  sra       $v0, $v0, 0x10
/* 192BC 8003DEBC 28420004 */  slti      $v0, $v0, 4
/* 192C0 8003DEC0 14400032 */  bnez      $v0, .L8003DF8C
/* 192C4 8003DEC4 A4830000 */   sh       $v1, ($a0)
/* 192C8 8003DEC8 C60C000C */  lwc1      $f12, 0xc($s0)
/* 192CC 8003DECC A4800000 */  sh        $zero, ($a0)
/* 192D0 8003DED0 0C00A6B9 */  jal       func_80029AE4
/* 192D4 8003DED4 46006307 */   neg.s    $f12, $f12
/* 192D8 8003DED8 3C0140C9 */  lui       $at, 0x40c9
/* 192DC 8003DEDC 34210FD0 */  ori       $at, $at, 0xfd0
/* 192E0 8003DEE0 44811000 */  mtc1      $at, $f2
/* 192E4 8003DEE4 00000000 */  nop
/* 192E8 8003DEE8 46020502 */  mul.s     $f20, $f0, $f2
/* 192EC 8003DEEC 00000000 */  nop
/* 192F0 8003DEF0 3C0143B4 */  lui       $at, 0x43b4
/* 192F4 8003DEF4 44810000 */  mtc1      $at, $f0
/* 192F8 8003DEF8 00000000 */  nop
/* 192FC 8003DEFC 4600A503 */  div.s     $f20, $f20, $f0
/* 19300 8003DF00 0C00A84B */  jal       func_8002A12C
/* 19304 8003DF04 4600A306 */   mov.s    $f12, $f20
/* 19308 8003DF08 4600A306 */  mov.s     $f12, $f20
/* 1930C 8003DF0C 0C00A864 */  jal       func_8002A190
/* 19310 8003DF10 46000506 */   mov.s    $f20, $f0
/* 19314 8003DF14 860200A6 */  lh        $v0, 0xa6($s0)
/* 19318 8003DF18 44821000 */  mtc1      $v0, $f2
/* 1931C 8003DF1C 00000000 */  nop
/* 19320 8003DF20 468010A0 */  cvt.s.w   $f2, $f2
/* 19324 8003DF24 46141502 */  mul.s     $f20, $f2, $f20
/* 19328 8003DF28 00000000 */  nop
/* 1932C 8003DF2C 46001082 */  mul.s     $f2, $f2, $f0
/* 19330 8003DF30 00000000 */  nop
/* 19334 8003DF34 3C013E4C */  lui       $at, 0x3e4c
/* 19338 8003DF38 3421CCCD */  ori       $at, $at, 0xcccd
/* 1933C 8003DF3C 44810000 */  mtc1      $at, $f0
/* 19340 8003DF40 00000000 */  nop
/* 19344 8003DF44 4600A502 */  mul.s     $f20, $f20, $f0
/* 19348 8003DF48 00000000 */  nop
/* 1934C 8003DF4C 46001082 */  mul.s     $f2, $f2, $f0
/* 19350 8003DF50 00000000 */  nop
/* 19354 8003DF54 C6000038 */  lwc1      $f0, 0x38($s0)
/* 19358 8003DF58 C606003C */  lwc1      $f6, 0x3c($s0)
/* 1935C 8003DF5C 46140000 */  add.s     $f0, $f0, $f20
/* 19360 8003DF60 44802000 */  mtc1      $zero, $f4
/* 19364 8003DF64 00000000 */  nop
/* 19368 8003DF68 46043180 */  add.s     $f6, $f6, $f4
/* 1936C 8003DF6C 44050000 */  mfc1      $a1, $f0
/* 19370 8003DF70 C6000040 */  lwc1      $f0, 0x40($s0)
/* 19374 8003DF74 46020000 */  add.s     $f0, $f0, $f2
/* 19378 8003DF78 44063000 */  mfc1      $a2, $f6
/* 1937C 8003DF7C 44070000 */  mfc1      $a3, $f0
/* 19380 8003DF80 0000202D */  daddu     $a0, $zero, $zero
/* 19384 8003DF84 0C01C164 */  jal       func_80070590
/* 19388 8003DF88 E7A40010 */   swc1     $f4, 0x10($sp)
.L8003DF8C:
/* 1938C 8003DF8C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19390 8003DF90 8FB00018 */  lw        $s0, 0x18($sp)
/* 19394 8003DF94 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 19398 8003DF98 03E00008 */  jr        $ra
/* 1939C 8003DF9C 27BD0028 */   addiu    $sp, $sp, 0x28
