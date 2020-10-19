.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241200_A6F5E0
/* A6F5E0 80241200 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A6F5E4 80241204 AFB40040 */  sw        $s4, 0x40($sp)
/* A6F5E8 80241208 0080A02D */  daddu     $s4, $a0, $zero
/* A6F5EC 8024120C AFBF0044 */  sw        $ra, 0x44($sp)
/* A6F5F0 80241210 AFB3003C */  sw        $s3, 0x3c($sp)
/* A6F5F4 80241214 AFB20038 */  sw        $s2, 0x38($sp)
/* A6F5F8 80241218 AFB10034 */  sw        $s1, 0x34($sp)
/* A6F5FC 8024121C AFB00030 */  sw        $s0, 0x30($sp)
/* A6F600 80241220 F7B40048 */  sdc1      $f20, 0x48($sp)
/* A6F604 80241224 8E900148 */  lw        $s0, 0x148($s4)
/* A6F608 80241228 00A0882D */  daddu     $s1, $a1, $zero
/* A6F60C 8024122C 86040008 */  lh        $a0, 8($s0)
/* A6F610 80241230 0C00EABB */  jal       get_npc_unsafe
/* A6F614 80241234 00C0902D */   daddu    $s2, $a2, $zero
/* A6F618 80241238 C60C006C */  lwc1      $f12, 0x6c($s0)
/* A6F61C 8024123C 46806320 */  cvt.s.w   $f12, $f12
/* A6F620 80241240 0040982D */  daddu     $s3, $v0, $zero
/* A6F624 80241244 C6140070 */  lwc1      $f20, 0x70($s0)
/* A6F628 80241248 4680A520 */  cvt.s.w   $f20, $f20
/* A6F62C 8024124C 3C014059 */  lui       $at, 0x4059
/* A6F630 80241250 44810800 */  mtc1      $at, $f1
/* A6F634 80241254 44800000 */  mtc1      $zero, $f0
/* A6F638 80241258 4600A521 */  cvt.d.s   $f20, $f20
/* A6F63C 8024125C 4620A503 */  div.d     $f20, $f20, $f0
/* A6F640 80241260 0C00A8BB */  jal       sin_deg
/* A6F644 80241264 4620A520 */   cvt.s.d  $f20, $f20
/* A6F648 80241268 3C014018 */  lui       $at, 0x4018
/* A6F64C 8024126C 44811800 */  mtc1      $at, $f3
/* A6F650 80241270 44801000 */  mtc1      $zero, $f2
/* A6F654 80241274 46000021 */  cvt.d.s   $f0, $f0
/* A6F658 80241278 46220002 */  mul.d     $f0, $f0, $f2
/* A6F65C 8024127C 00000000 */  nop       
/* A6F660 80241280 4600A0A1 */  cvt.d.s   $f2, $f20
/* A6F664 80241284 46201080 */  add.d     $f2, $f2, $f0
/* A6F668 80241288 462010A0 */  cvt.s.d   $f2, $f2
/* A6F66C 8024128C E662003C */  swc1      $f2, 0x3c($s3)
/* A6F670 80241290 8E02006C */  lw        $v0, 0x6c($s0)
/* A6F674 80241294 2442000A */  addiu     $v0, $v0, 0xa
/* A6F678 80241298 44826000 */  mtc1      $v0, $f12
/* A6F67C 8024129C 00000000 */  nop       
/* A6F680 802412A0 0C00A6C9 */  jal       clamp_angle
/* A6F684 802412A4 46806320 */   cvt.s.w  $f12, $f12
/* A6F688 802412A8 4600018D */  trunc.w.s $f6, $f0
/* A6F68C 802412AC E606006C */  swc1      $f6, 0x6c($s0)
/* A6F690 802412B0 0280202D */  daddu     $a0, $s4, $zero
/* A6F694 802412B4 8E250024 */  lw        $a1, 0x24($s1)
/* A6F698 802412B8 8E260028 */  lw        $a2, 0x28($s1)
/* A6F69C 802412BC 0C0902B9 */  jal       func_80240AE4
/* A6F6A0 802412C0 0240382D */   daddu    $a3, $s2, $zero
/* A6F6A4 802412C4 24030001 */  addiu     $v1, $zero, 1
/* A6F6A8 802412C8 1443001E */  bne       $v0, $v1, .L80241344
/* A6F6AC 802412CC 0000202D */   daddu    $a0, $zero, $zero
/* A6F6B0 802412D0 0260282D */  daddu     $a1, $s3, $zero
/* A6F6B4 802412D4 0000302D */  daddu     $a2, $zero, $zero
/* A6F6B8 802412D8 866300A8 */  lh        $v1, 0xa8($s3)
/* A6F6BC 802412DC 3C013F80 */  lui       $at, 0x3f80
/* A6F6C0 802412E0 44810000 */  mtc1      $at, $f0
/* A6F6C4 802412E4 3C014000 */  lui       $at, 0x4000
/* A6F6C8 802412E8 44811000 */  mtc1      $at, $f2
/* A6F6CC 802412EC 3C01C1A0 */  lui       $at, 0xc1a0
/* A6F6D0 802412F0 44812000 */  mtc1      $at, $f4
/* A6F6D4 802412F4 2402000F */  addiu     $v0, $zero, 0xf
/* A6F6D8 802412F8 AFA2001C */  sw        $v0, 0x1c($sp)
/* A6F6DC 802412FC 44833000 */  mtc1      $v1, $f6
/* A6F6E0 80241300 00000000 */  nop       
/* A6F6E4 80241304 468031A0 */  cvt.s.w   $f6, $f6
/* A6F6E8 80241308 44073000 */  mfc1      $a3, $f6
/* A6F6EC 8024130C 27A20028 */  addiu     $v0, $sp, 0x28
/* A6F6F0 80241310 AFA20020 */  sw        $v0, 0x20($sp)
/* A6F6F4 80241314 E7A00010 */  swc1      $f0, 0x10($sp)
/* A6F6F8 80241318 E7A20014 */  swc1      $f2, 0x14($sp)
/* A6F6FC 8024131C 0C01BFA4 */  jal       fx_emote
/* A6F700 80241320 E7A40018 */   swc1     $f4, 0x18($sp)
/* A6F704 80241324 0260202D */  daddu     $a0, $s3, $zero
/* A6F708 80241328 240502F4 */  addiu     $a1, $zero, 0x2f4
/* A6F70C 8024132C 0C012530 */  jal       func_800494C0
/* A6F710 80241330 3C060020 */   lui      $a2, 0x20
/* A6F714 80241334 24020032 */  addiu     $v0, $zero, 0x32
/* A6F718 80241338 A662008E */  sh        $v0, 0x8e($s3)
/* A6F71C 8024133C 080904D9 */  j         .L80241364
/* A6F720 80241340 24020014 */   addiu    $v0, $zero, 0x14
.L80241344:
/* A6F724 80241344 9662008E */  lhu       $v0, 0x8e($s3)
/* A6F728 80241348 2442FFFF */  addiu     $v0, $v0, -1
/* A6F72C 8024134C A662008E */  sh        $v0, 0x8e($s3)
/* A6F730 80241350 00021400 */  sll       $v0, $v0, 0x10
/* A6F734 80241354 1C400004 */  bgtz      $v0, .L80241368
/* A6F738 80241358 24020005 */   addiu    $v0, $zero, 5
/* A6F73C 8024135C A662008E */  sh        $v0, 0x8e($s3)
/* A6F740 80241360 2402000F */  addiu     $v0, $zero, 0xf
.L80241364:
/* A6F744 80241364 AE820070 */  sw        $v0, 0x70($s4)
.L80241368:
/* A6F748 80241368 8FBF0044 */  lw        $ra, 0x44($sp)
/* A6F74C 8024136C 8FB40040 */  lw        $s4, 0x40($sp)
/* A6F750 80241370 8FB3003C */  lw        $s3, 0x3c($sp)
/* A6F754 80241374 8FB20038 */  lw        $s2, 0x38($sp)
/* A6F758 80241378 8FB10034 */  lw        $s1, 0x34($sp)
/* A6F75C 8024137C 8FB00030 */  lw        $s0, 0x30($sp)
/* A6F760 80241380 D7B40048 */  ldc1      $f20, 0x48($sp)
/* A6F764 80241384 03E00008 */  jr        $ra
/* A6F768 80241388 27BD0050 */   addiu    $sp, $sp, 0x50
