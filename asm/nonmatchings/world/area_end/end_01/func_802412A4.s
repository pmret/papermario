.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412A4
/* E06604 802412A4 27BDFF38 */  addiu     $sp, $sp, -0xc8
/* E06608 802412A8 AFB00088 */  sw        $s0, 0x88($sp)
/* E0660C 802412AC 00A0802D */  daddu     $s0, $a1, $zero
/* E06610 802412B0 AFBF00A0 */  sw        $ra, 0xa0($sp)
/* E06614 802412B4 AFB5009C */  sw        $s5, 0x9c($sp)
/* E06618 802412B8 AFB40098 */  sw        $s4, 0x98($sp)
/* E0661C 802412BC AFB30094 */  sw        $s3, 0x94($sp)
/* E06620 802412C0 AFB20090 */  sw        $s2, 0x90($sp)
/* E06624 802412C4 AFB1008C */  sw        $s1, 0x8c($sp)
/* E06628 802412C8 F7BA00C0 */  sdc1      $f26, 0xc0($sp)
/* E0662C 802412CC F7B800B8 */  sdc1      $f24, 0xb8($sp)
/* E06630 802412D0 F7B600B0 */  sdc1      $f22, 0xb0($sp)
/* E06634 802412D4 F7B400A8 */  sdc1      $f20, 0xa8($sp)
/* E06638 802412D8 C6140010 */  lwc1      $f20, 0x10($s0)
/* E0663C 802412DC 4680A520 */  cvt.s.w   $f20, $f20
/* E06640 802412E0 4480C000 */  mtc1      $zero, $f24
/* E06644 802412E4 3C05437F */  lui       $a1, 0x437f
/* E06648 802412E8 8C820050 */  lw        $v0, 0x50($a0)
/* E0664C 802412EC 4406C000 */  mfc1      $a2, $f24
/* E06650 802412F0 C61A0014 */  lwc1      $f26, 0x14($s0)
/* E06654 802412F4 4680D6A0 */  cvt.s.w   $f26, $f26
/* E06658 802412F8 AFA20010 */  sw        $v0, 0x10($sp)
/* E0665C 802412FC 8E070018 */  lw        $a3, 0x18($s0)
/* E06660 80241300 0C00A8ED */  jal       update_lerp
/* E06664 80241304 2404000B */   addiu    $a0, $zero, 0xb
/* E06668 80241308 4600008D */  trunc.w.s $f2, $f0
/* E0666C 8024130C E7A20014 */  swc1      $f2, 0x14($sp)
/* E06670 80241310 0000202D */  daddu     $a0, $zero, $zero
/* E06674 80241314 24050007 */  addiu     $a1, $zero, 7
/* E06678 80241318 240600FF */  addiu     $a2, $zero, 0xff
/* E0667C 8024131C 00C0382D */  daddu     $a3, $a2, $zero
/* E06680 80241320 00C0A82D */  daddu     $s5, $a2, $zero
/* E06684 80241324 AFB50010 */  sw        $s5, 0x10($sp)
/* E06688 80241328 0C04EAA7 */  jal       func_8013AA9C
/* E0668C 8024132C AFA00018 */   sw       $zero, 0x18($sp)
/* E06690 80241330 27A20038 */  addiu     $v0, $sp, 0x38
/* E06694 80241334 AFA20010 */  sw        $v0, 0x10($sp)
/* E06698 80241338 8E040004 */  lw        $a0, 4($s0)
/* E0669C 8024133C 8E050008 */  lw        $a1, 8($s0)
/* E066A0 80241340 8E060000 */  lw        $a2, ($s0)
/* E066A4 80241344 8E07000C */  lw        $a3, 0xc($s0)
/* E066A8 80241348 0C04BA38 */  jal       func_8012E8E0
/* E066AC 8024134C 3C140001 */   lui      $s4, 1
/* E066B0 80241350 93A20042 */  lbu       $v0, 0x42($sp)
/* E066B4 80241354 3C013FE0 */  lui       $at, 0x3fe0
/* E066B8 80241358 4481B800 */  mtc1      $at, $f23
/* E066BC 8024135C 4480B000 */  mtc1      $zero, $f22
/* E066C0 80241360 44820000 */  mtc1      $v0, $f0
/* E066C4 80241364 00000000 */  nop       
/* E066C8 80241368 46800021 */  cvt.d.w   $f0, $f0
/* E066CC 8024136C 46360002 */  mul.d     $f0, $f0, $f22
/* E066D0 80241370 00000000 */  nop       
/* E066D4 80241374 36941630 */  ori       $s4, $s4, 0x1630
/* E066D8 80241378 4600A521 */  cvt.d.s   $f20, $f20
/* E066DC 8024137C 27B00048 */  addiu     $s0, $sp, 0x48
/* E066E0 80241380 4600D687 */  neg.s     $f26, $f26
/* E066E4 80241384 4620A500 */  add.d     $f20, $f20, $f0
/* E066E8 80241388 4406D000 */  mfc1      $a2, $f26
/* E066EC 8024138C 4407C000 */  mfc1      $a3, $f24
/* E066F0 80241390 4620A520 */  cvt.s.d   $f20, $f20
/* E066F4 80241394 4405A000 */  mfc1      $a1, $f20
/* E066F8 80241398 0C019E40 */  jal       guTranslateF
/* E066FC 8024139C 0200202D */   daddu    $a0, $s0, $zero
/* E06700 802413A0 0200202D */  daddu     $a0, $s0, $zero
/* E06704 802413A4 3C128007 */  lui       $s2, 0x8007
/* E06708 802413A8 265241F0 */  addiu     $s2, $s2, 0x41f0
/* E0670C 802413AC 3C13800A */  lui       $s3, 0x800a
/* E06710 802413B0 2673A674 */  addiu     $s3, $s3, -0x598c
/* E06714 802413B4 96450000 */  lhu       $a1, ($s2)
/* E06718 802413B8 8E620000 */  lw        $v0, ($s3)
/* E0671C 802413BC 00052980 */  sll       $a1, $a1, 6
/* E06720 802413C0 00B42821 */  addu      $a1, $a1, $s4
/* E06724 802413C4 0C019D40 */  jal       guMtxF2L
/* E06728 802413C8 00452821 */   addu     $a1, $v0, $a1
/* E0672C 802413CC 3C03DA38 */  lui       $v1, 0xda38
/* E06730 802413D0 34630002 */  ori       $v1, $v1, 2
/* E06734 802413D4 0000202D */  daddu     $a0, $zero, $zero
/* E06738 802413D8 27A50020 */  addiu     $a1, $sp, 0x20
/* E0673C 802413DC 3C060001 */  lui       $a2, 1
/* E06740 802413E0 34C60040 */  ori       $a2, $a2, 0x40
/* E06744 802413E4 3C11800A */  lui       $s1, 0x800a
/* E06748 802413E8 2631A66C */  addiu     $s1, $s1, -0x5994
/* E0674C 802413EC 0200382D */  daddu     $a3, $s0, $zero
/* E06750 802413F0 8E220000 */  lw        $v0, ($s1)
/* E06754 802413F4 96480000 */  lhu       $t0, ($s2)
/* E06758 802413F8 0040482D */  daddu     $t1, $v0, $zero
/* E0675C 802413FC 24420008 */  addiu     $v0, $v0, 8
/* E06760 80241400 AE220000 */  sw        $v0, ($s1)
/* E06764 80241404 3102FFFF */  andi      $v0, $t0, 0xffff
/* E06768 80241408 00021180 */  sll       $v0, $v0, 6
/* E0676C 8024140C 00541021 */  addu      $v0, $v0, $s4
/* E06770 80241410 AD230000 */  sw        $v1, ($t1)
/* E06774 80241414 8E630000 */  lw        $v1, ($s3)
/* E06778 80241418 25080001 */  addiu     $t0, $t0, 1
/* E0677C 8024141C 00621821 */  addu      $v1, $v1, $v0
/* E06780 80241420 3C028000 */  lui       $v0, 0x8000
/* E06784 80241424 00621821 */  addu      $v1, $v1, $v0
/* E06788 80241428 AD230004 */  sw        $v1, 4($t1)
/* E0678C 8024142C 93A20042 */  lbu       $v0, 0x42($sp)
/* E06790 80241430 8FA3003C */  lw        $v1, 0x3c($sp)
/* E06794 80241434 93A90040 */  lbu       $t1, 0x40($sp)
/* E06798 80241438 93AA0041 */  lbu       $t2, 0x41($sp)
/* E0679C 8024143C 44820000 */  mtc1      $v0, $f0
/* E067A0 80241440 00000000 */  nop       
/* E067A4 80241444 46800021 */  cvt.d.w   $f0, $f0
/* E067A8 80241448 8FA20038 */  lw        $v0, 0x38($sp)
/* E067AC 8024144C 46360002 */  mul.d     $f0, $f0, $f22
/* E067B0 80241450 00000000 */  nop       
/* E067B4 80241454 A6480000 */  sh        $t0, ($s2)
/* E067B8 80241458 A7A0002E */  sh        $zero, 0x2e($sp)
/* E067BC 8024145C A3B50030 */  sb        $s5, 0x30($sp)
/* E067C0 80241460 AFA30024 */  sw        $v1, 0x24($sp)
/* E067C4 80241464 A7A90028 */  sh        $t1, 0x28($sp)
/* E067C8 80241468 A7AA002A */  sh        $t2, 0x2a($sp)
/* E067CC 8024146C AFA20020 */  sw        $v0, 0x20($sp)
/* E067D0 80241470 46200007 */  neg.d     $f0, $f0
/* E067D4 80241474 4620008D */  trunc.w.d $f2, $f0
/* E067D8 80241478 44021000 */  mfc1      $v0, $f2
/* E067DC 8024147C 0C04EBDC */  jal       func_8013AF70
/* E067E0 80241480 A7A2002C */   sh       $v0, 0x2c($sp)
/* E067E4 80241484 3C04D838 */  lui       $a0, 0xd838
/* E067E8 80241488 8E220000 */  lw        $v0, ($s1)
/* E067EC 8024148C 34840002 */  ori       $a0, $a0, 2
/* E067F0 80241490 0040182D */  daddu     $v1, $v0, $zero
/* E067F4 80241494 24420008 */  addiu     $v0, $v0, 8
/* E067F8 80241498 AE220000 */  sw        $v0, ($s1)
/* E067FC 8024149C 24020040 */  addiu     $v0, $zero, 0x40
/* E06800 802414A0 AC640000 */  sw        $a0, ($v1)
/* E06804 802414A4 AC620004 */  sw        $v0, 4($v1)
/* E06808 802414A8 8FBF00A0 */  lw        $ra, 0xa0($sp)
/* E0680C 802414AC 8FB5009C */  lw        $s5, 0x9c($sp)
/* E06810 802414B0 8FB40098 */  lw        $s4, 0x98($sp)
/* E06814 802414B4 8FB30094 */  lw        $s3, 0x94($sp)
/* E06818 802414B8 8FB20090 */  lw        $s2, 0x90($sp)
/* E0681C 802414BC 8FB1008C */  lw        $s1, 0x8c($sp)
/* E06820 802414C0 8FB00088 */  lw        $s0, 0x88($sp)
/* E06824 802414C4 D7BA00C0 */  ldc1      $f26, 0xc0($sp)
/* E06828 802414C8 D7B800B8 */  ldc1      $f24, 0xb8($sp)
/* E0682C 802414CC D7B600B0 */  ldc1      $f22, 0xb0($sp)
/* E06830 802414D0 D7B400A8 */  ldc1      $f20, 0xa8($sp)
/* E06834 802414D4 03E00008 */  jr        $ra
/* E06838 802414D8 27BD00C8 */   addiu    $sp, $sp, 0xc8
