.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel trd_04_UnkFunc5
/* 9AB3F0 80243000 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 9AB3F4 80243004 AFB00028 */  sw        $s0, 0x28($sp)
/* 9AB3F8 80243008 00A0802D */  daddu     $s0, $a1, $zero
/* 9AB3FC 8024300C AFB1002C */  sw        $s1, 0x2c($sp)
/* 9AB400 80243010 00C0882D */  daddu     $s1, $a2, $zero
/* 9AB404 80243014 AFBF0034 */  sw        $ra, 0x34($sp)
/* 9AB408 80243018 AFB20030 */  sw        $s2, 0x30($sp)
/* 9AB40C 8024301C AE200070 */  sw        $zero, 0x70($s1)
/* 9AB410 80243020 8C830000 */  lw        $v1, ($a0)
/* 9AB414 80243024 2402FDFF */  addiu     $v0, $zero, -0x201
/* 9AB418 80243028 A480008E */  sh        $zero, 0x8e($a0)
/* 9AB41C 8024302C 00621824 */  and       $v1, $v1, $v0
/* 9AB420 80243030 34650800 */  ori       $a1, $v1, 0x800
/* 9AB424 80243034 AC850000 */  sw        $a1, ($a0)
/* 9AB428 80243038 8E0200D0 */  lw        $v0, 0xd0($s0)
/* 9AB42C 8024303C 8C420034 */  lw        $v0, 0x34($v0)
/* 9AB430 80243040 10400003 */  beqz      $v0, .L80243050
/* 9AB434 80243044 00E0902D */   daddu    $s2, $a3, $zero
/* 9AB438 80243048 08090C16 */  j         .L80243058
/* 9AB43C 8024304C 34620808 */   ori      $v0, $v1, 0x808
.L80243050:
/* 9AB440 80243050 2402FFF7 */  addiu     $v0, $zero, -9
/* 9AB444 80243054 00A21024 */  and       $v0, $a1, $v0
.L80243058:
/* 9AB448 80243058 AC820000 */  sw        $v0, ($a0)
/* 9AB44C 8024305C 27A20024 */  addiu     $v0, $sp, 0x24
/* 9AB450 80243060 27A50018 */  addiu     $a1, $sp, 0x18
/* 9AB454 80243064 C4800038 */  lwc1      $f0, 0x38($a0)
/* 9AB458 80243068 C482003C */  lwc1      $f2, 0x3c($a0)
/* 9AB45C 8024306C C4840040 */  lwc1      $f4, 0x40($a0)
/* 9AB460 80243070 3C01447A */  lui       $at, 0x447a
/* 9AB464 80243074 44813000 */  mtc1      $at, $f6
/* 9AB468 80243078 27A6001C */  addiu     $a2, $sp, 0x1c
/* 9AB46C 8024307C E7A00018 */  swc1      $f0, 0x18($sp)
/* 9AB470 80243080 E7A2001C */  swc1      $f2, 0x1c($sp)
/* 9AB474 80243084 E7A40020 */  swc1      $f4, 0x20($sp)
/* 9AB478 80243088 E7A60024 */  swc1      $f6, 0x24($sp)
/* 9AB47C 8024308C AFA20010 */  sw        $v0, 0x10($sp)
/* 9AB480 80243090 8C840080 */  lw        $a0, 0x80($a0)
/* 9AB484 80243094 0C0372DF */  jal       func_800DCB7C
/* 9AB488 80243098 27A70020 */   addiu    $a3, $sp, 0x20
/* 9AB48C 8024309C C7A20024 */  lwc1      $f2, 0x24($sp)
/* 9AB490 802430A0 3C014059 */  lui       $at, 0x4059
/* 9AB494 802430A4 44812800 */  mtc1      $at, $f5
/* 9AB498 802430A8 44802000 */  mtc1      $zero, $f4
/* 9AB49C 802430AC 460010A1 */  cvt.d.s   $f2, $f2
/* 9AB4A0 802430B0 46241082 */  mul.d     $f2, $f2, $f4
/* 9AB4A4 802430B4 00000000 */  nop
/* 9AB4A8 802430B8 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 9AB4AC 802430BC 46000021 */  cvt.d.s   $f0, $f0
/* 9AB4B0 802430C0 46240002 */  mul.d     $f0, $f0, $f4
/* 9AB4B4 802430C4 00000000 */  nop
/* 9AB4B8 802430C8 3C013FE0 */  lui       $at, 0x3fe0
/* 9AB4BC 802430CC 44812800 */  mtc1      $at, $f5
/* 9AB4C0 802430D0 44802000 */  mtc1      $zero, $f4
/* 9AB4C4 802430D4 00000000 */  nop
/* 9AB4C8 802430D8 46241080 */  add.d     $f2, $f2, $f4
/* 9AB4CC 802430DC AE000074 */  sw        $zero, 0x74($s0)
/* 9AB4D0 802430E0 46240000 */  add.d     $f0, $f0, $f4
/* 9AB4D4 802430E4 AE000090 */  sw        $zero, 0x90($s0)
/* 9AB4D8 802430E8 4620120D */  trunc.w.d $f8, $f2
/* 9AB4DC 802430EC E6080078 */  swc1      $f8, 0x78($s0)
/* 9AB4E0 802430F0 4620020D */  trunc.w.d $f8, $f0
/* 9AB4E4 802430F4 E6080088 */  swc1      $f8, 0x88($s0)
/* 9AB4E8 802430F8 8E420014 */  lw        $v0, 0x14($s2)
/* 9AB4EC 802430FC AE220074 */  sw        $v0, 0x74($s1)
/* 9AB4F0 80243100 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 9AB4F4 80243104 34420010 */  ori       $v0, $v0, 0x10
/* 9AB4F8 80243108 AE0200B0 */  sw        $v0, 0xb0($s0)
/* 9AB4FC 8024310C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 9AB500 80243110 8FB20030 */  lw        $s2, 0x30($sp)
/* 9AB504 80243114 8FB1002C */  lw        $s1, 0x2c($sp)
/* 9AB508 80243118 8FB00028 */  lw        $s0, 0x28($sp)
/* 9AB50C 8024311C 03E00008 */  jr        $ra
/* 9AB510 80243120 27BD0038 */   addiu    $sp, $sp, 0x38
