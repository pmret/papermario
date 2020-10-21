.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242688_C79368
/* C79368 80242688 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C7936C 8024268C AFB40040 */  sw        $s4, 0x40($sp)
/* C79370 80242690 0080A02D */  daddu     $s4, $a0, $zero
/* C79374 80242694 AFBF0044 */  sw        $ra, 0x44($sp)
/* C79378 80242698 AFB3003C */  sw        $s3, 0x3c($sp)
/* C7937C 8024269C AFB20038 */  sw        $s2, 0x38($sp)
/* C79380 802426A0 AFB10034 */  sw        $s1, 0x34($sp)
/* C79384 802426A4 AFB00030 */  sw        $s0, 0x30($sp)
/* C79388 802426A8 8E910148 */  lw        $s1, 0x148($s4)
/* C7938C 802426AC 00A0902D */  daddu     $s2, $a1, $zero
/* C79390 802426B0 86240008 */  lh        $a0, 8($s1)
/* C79394 802426B4 0C00EABB */  jal       get_npc_unsafe
/* C79398 802426B8 00C0982D */   daddu    $s3, $a2, $zero
/* C7939C 802426BC 0040802D */  daddu     $s0, $v0, $zero
/* C793A0 802426C0 9602008E */  lhu       $v0, 0x8e($s0)
/* C793A4 802426C4 2442FFFF */  addiu     $v0, $v0, -1
/* C793A8 802426C8 A602008E */  sh        $v0, 0x8e($s0)
/* C793AC 802426CC 00021400 */  sll       $v0, $v0, 0x10
/* C793B0 802426D0 14400020 */  bnez      $v0, .L80242754
/* C793B4 802426D4 0260202D */   daddu    $a0, $s3, $zero
/* C793B8 802426D8 AFA00010 */  sw        $zero, 0x10($sp)
/* C793BC 802426DC 8E46000C */  lw        $a2, 0xc($s2)
/* C793C0 802426E0 8E470010 */  lw        $a3, 0x10($s2)
/* C793C4 802426E4 0C01242D */  jal       func_800490B4
/* C793C8 802426E8 0220282D */   daddu    $a1, $s1, $zero
/* C793CC 802426EC 54400018 */  bnel      $v0, $zero, .L80242750
/* C793D0 802426F0 A600008E */   sh       $zero, 0x8e($s0)
/* C793D4 802426F4 24040002 */  addiu     $a0, $zero, 2
/* C793D8 802426F8 0200282D */  daddu     $a1, $s0, $zero
/* C793DC 802426FC 0000302D */  daddu     $a2, $zero, $zero
/* C793E0 80242700 860300A8 */  lh        $v1, 0xa8($s0)
/* C793E4 80242704 3C013F80 */  lui       $at, 0x3f80
/* C793E8 80242708 44810000 */  mtc1      $at, $f0
/* C793EC 8024270C 3C014000 */  lui       $at, 0x4000
/* C793F0 80242710 44811000 */  mtc1      $at, $f2
/* C793F4 80242714 3C01C1A0 */  lui       $at, 0xc1a0
/* C793F8 80242718 44812000 */  mtc1      $at, $f4
/* C793FC 8024271C 2402000F */  addiu     $v0, $zero, 0xf
/* C79400 80242720 AFA2001C */  sw        $v0, 0x1c($sp)
/* C79404 80242724 44833000 */  mtc1      $v1, $f6
/* C79408 80242728 00000000 */  nop       
/* C7940C 8024272C 468031A0 */  cvt.s.w   $f6, $f6
/* C79410 80242730 44073000 */  mfc1      $a3, $f6
/* C79414 80242734 27A20028 */  addiu     $v0, $sp, 0x28
/* C79418 80242738 AFA20020 */  sw        $v0, 0x20($sp)
/* C7941C 8024273C E7A00010 */  swc1      $f0, 0x10($sp)
/* C79420 80242740 E7A20014 */  swc1      $f2, 0x14($sp)
/* C79424 80242744 0C01BFA4 */  jal       fx_emote
/* C79428 80242748 E7A40018 */   swc1     $f4, 0x18($sp)
/* C7942C 8024274C A600008E */  sh        $zero, 0x8e($s0)
.L80242750:
/* C79430 80242750 AE800070 */  sw        $zero, 0x70($s4)
.L80242754:
/* C79434 80242754 8FBF0044 */  lw        $ra, 0x44($sp)
/* C79438 80242758 8FB40040 */  lw        $s4, 0x40($sp)
/* C7943C 8024275C 8FB3003C */  lw        $s3, 0x3c($sp)
/* C79440 80242760 8FB20038 */  lw        $s2, 0x38($sp)
/* C79444 80242764 8FB10034 */  lw        $s1, 0x34($sp)
/* C79448 80242768 8FB00030 */  lw        $s0, 0x30($sp)
/* C7944C 8024276C 03E00008 */  jr        $ra
/* C79450 80242770 27BD0048 */   addiu    $sp, $sp, 0x48
