.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024268C_DCF35C
/* DCF35C 8024268C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* DCF360 80242690 AFB20038 */  sw        $s2, 0x38($sp)
/* DCF364 80242694 0080902D */  daddu     $s2, $a0, $zero
/* DCF368 80242698 AFBF003C */  sw        $ra, 0x3c($sp)
/* DCF36C 8024269C AFB10034 */  sw        $s1, 0x34($sp)
/* DCF370 802426A0 AFB00030 */  sw        $s0, 0x30($sp)
/* DCF374 802426A4 8E510148 */  lw        $s1, 0x148($s2)
/* DCF378 802426A8 0C00EABB */  jal       get_npc_unsafe
/* DCF37C 802426AC 86240008 */   lh       $a0, 8($s1)
/* DCF380 802426B0 0040802D */  daddu     $s0, $v0, $zero
/* DCF384 802426B4 9602008E */  lhu       $v0, 0x8e($s0)
/* DCF388 802426B8 2442FFFF */  addiu     $v0, $v0, -1
/* DCF38C 802426BC A602008E */  sh        $v0, 0x8e($s0)
/* DCF390 802426C0 00021400 */  sll       $v0, $v0, 0x10
/* DCF394 802426C4 1C40002B */  bgtz      $v0, .L80242774
/* DCF398 802426C8 00000000 */   nop      
/* DCF39C 802426CC 0C0908D6 */  jal       func_80242358
/* DCF3A0 802426D0 0240202D */   daddu    $a0, $s2, $zero
/* DCF3A4 802426D4 0040202D */  daddu     $a0, $v0, $zero
/* DCF3A8 802426D8 0481001A */  bgez      $a0, .L80242744
/* DCF3AC 802426DC 2402000F */   addiu    $v0, $zero, 0xf
/* DCF3B0 802426E0 24040002 */  addiu     $a0, $zero, 2
/* DCF3B4 802426E4 860300A8 */  lh        $v1, 0xa8($s0)
/* DCF3B8 802426E8 AFA2001C */  sw        $v0, 0x1c($sp)
/* DCF3BC 802426EC 27A20028 */  addiu     $v0, $sp, 0x28
/* DCF3C0 802426F0 0200282D */  daddu     $a1, $s0, $zero
/* DCF3C4 802426F4 3C013F80 */  lui       $at, 0x3f80
/* DCF3C8 802426F8 44810000 */  mtc1      $at, $f0
/* DCF3CC 802426FC 3C014000 */  lui       $at, 0x4000
/* DCF3D0 80242700 44811000 */  mtc1      $at, $f2
/* DCF3D4 80242704 3C01C1A0 */  lui       $at, 0xc1a0
/* DCF3D8 80242708 44812000 */  mtc1      $at, $f4
/* DCF3DC 8024270C 44833000 */  mtc1      $v1, $f6
/* DCF3E0 80242710 00000000 */  nop       
/* DCF3E4 80242714 468031A0 */  cvt.s.w   $f6, $f6
/* DCF3E8 80242718 44073000 */  mfc1      $a3, $f6
/* DCF3EC 8024271C 0000302D */  daddu     $a2, $zero, $zero
/* DCF3F0 80242720 AFA20020 */  sw        $v0, 0x20($sp)
/* DCF3F4 80242724 E7A00010 */  swc1      $f0, 0x10($sp)
/* DCF3F8 80242728 E7A20014 */  swc1      $f2, 0x14($sp)
/* DCF3FC 8024272C 0C01BFA4 */  jal       fx_emote
/* DCF400 80242730 E7A40018 */   swc1     $f4, 0x18($sp)
/* DCF404 80242734 8E2200CC */  lw        $v0, 0xcc($s1)
/* DCF408 80242738 8C420000 */  lw        $v0, ($v0)
/* DCF40C 8024273C 080909D9 */  j         .L80242764
/* DCF410 80242740 AE020028 */   sw       $v0, 0x28($s0)
.L80242744:
/* DCF414 80242744 8E2200CC */  lw        $v0, 0xcc($s1)
/* DCF418 80242748 8C420024 */  lw        $v0, 0x24($v0)
/* DCF41C 8024274C 0C00FB3A */  jal       get_enemy
/* DCF420 80242750 AE020028 */   sw       $v0, 0x28($s0)
/* DCF424 80242754 86240008 */  lh        $a0, 8($s1)
/* DCF428 80242758 24030001 */  addiu     $v1, $zero, 1
/* DCF42C 8024275C AC43006C */  sw        $v1, 0x6c($v0)
/* DCF430 80242760 AC44007C */  sw        $a0, 0x7c($v0)
.L80242764:
/* DCF434 80242764 96220076 */  lhu       $v0, 0x76($s1)
/* DCF438 80242768 A602008E */  sh        $v0, 0x8e($s0)
/* DCF43C 8024276C 24020021 */  addiu     $v0, $zero, 0x21
/* DCF440 80242770 AE420070 */  sw        $v0, 0x70($s2)
.L80242774:
/* DCF444 80242774 8FBF003C */  lw        $ra, 0x3c($sp)
/* DCF448 80242778 8FB20038 */  lw        $s2, 0x38($sp)
/* DCF44C 8024277C 8FB10034 */  lw        $s1, 0x34($sp)
/* DCF450 80242780 8FB00030 */  lw        $s0, 0x30($sp)
/* DCF454 80242784 03E00008 */  jr        $ra
/* DCF458 80242788 27BD0040 */   addiu    $sp, $sp, 0x40
