.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242870
/* 8EE690 80242870 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8EE694 80242874 0000202D */  daddu     $a0, $zero, $zero
/* 8EE698 80242878 3C05FD05 */  lui       $a1, 0xfd05
/* 8EE69C 8024287C 34A50F8A */  ori       $a1, $a1, 0xf8a
/* 8EE6A0 80242880 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8EE6A4 80242884 0C0B1EAF */  jal       get_variable
/* 8EE6A8 80242888 AFB00018 */   sw       $s0, 0x18($sp)
/* 8EE6AC 8024288C 0040802D */  daddu     $s0, $v0, $zero
/* 8EE6B0 80242890 96030000 */  lhu       $v1, ($s0)
/* 8EE6B4 80242894 2C620005 */  sltiu     $v0, $v1, 5
/* 8EE6B8 80242898 10400053 */  beqz      $v0, .L802429E8
/* 8EE6BC 8024289C 00031080 */   sll      $v0, $v1, 2
/* 8EE6C0 802428A0 3C018025 */  lui       $at, 0x8025
/* 8EE6C4 802428A4 00220821 */  addu      $at, $at, $v0
/* 8EE6C8 802428A8 8C223040 */  lw        $v0, 0x3040($at)
/* 8EE6CC 802428AC 00400008 */  jr        $v0
/* 8EE6D0 802428B0 00000000 */   nop      
/* 8EE6D4 802428B4 2404021C */  addiu     $a0, $zero, 0x21c
/* 8EE6D8 802428B8 0000282D */  daddu     $a1, $zero, $zero
/* 8EE6DC 802428BC 00A0302D */  daddu     $a2, $a1, $zero
/* 8EE6E0 802428C0 24020001 */  addiu     $v0, $zero, 1
/* 8EE6E4 802428C4 A6000018 */  sh        $zero, 0x18($s0)
/* 8EE6E8 802428C8 A6000008 */  sh        $zero, 8($s0)
/* 8EE6EC 802428CC A600000A */  sh        $zero, 0xa($s0)
/* 8EE6F0 802428D0 AE000004 */  sw        $zero, 4($s0)
/* 8EE6F4 802428D4 0C015478 */  jal       func_800551E0
/* 8EE6F8 802428D8 A6020000 */   sh       $v0, ($s0)
/* 8EE6FC 802428DC 3C054200 */  lui       $a1, 0x4200
/* 8EE700 802428E0 8E020004 */  lw        $v0, 4($s0)
/* 8EE704 802428E4 3C06437F */  lui       $a2, 0x437f
/* 8EE708 802428E8 24420001 */  addiu     $v0, $v0, 1
/* 8EE70C 802428EC AE020004 */  sw        $v0, 4($s0)
/* 8EE710 802428F0 24020003 */  addiu     $v0, $zero, 3
/* 8EE714 802428F4 AFA20010 */  sw        $v0, 0x10($sp)
/* 8EE718 802428F8 8E070004 */  lw        $a3, 4($s0)
/* 8EE71C 802428FC 0C00A8ED */  jal       update_lerp
/* 8EE720 80242900 0000202D */   daddu    $a0, $zero, $zero
/* 8EE724 80242904 8E020004 */  lw        $v0, 4($s0)
/* 8EE728 80242908 4600008D */  trunc.w.s $f2, $f0
/* 8EE72C 8024290C 44031000 */  mfc1      $v1, $f2
/* 8EE730 80242910 00000000 */  nop       
/* 8EE734 80242914 A603001A */  sh        $v1, 0x1a($s0)
/* 8EE738 80242918 28420003 */  slti      $v0, $v0, 3
/* 8EE73C 8024291C 14400032 */  bnez      $v0, .L802429E8
/* 8EE740 80242920 A603001C */   sh       $v1, 0x1c($s0)
/* 8EE744 80242924 24020002 */  addiu     $v0, $zero, 2
/* 8EE748 80242928 A6020000 */  sh        $v0, ($s0)
/* 8EE74C 8024292C 240200FF */  addiu     $v0, $zero, 0xff
/* 8EE750 80242930 A602001A */  sh        $v0, 0x1a($s0)
/* 8EE754 80242934 08090A7A */  j         .L802429E8
/* 8EE758 80242938 A602001C */   sh       $v0, 0x1c($s0)
/* 8EE75C 8024293C 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 8EE760 80242940 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 8EE764 80242944 240200FF */  addiu     $v0, $zero, 0xff
/* 8EE768 80242948 A602001A */  sh        $v0, 0x1a($s0)
/* 8EE76C 8024294C A602001C */  sh        $v0, 0x1c($s0)
/* 8EE770 80242950 8C620000 */  lw        $v0, ($v1)
/* 8EE774 80242954 3042C000 */  andi      $v0, $v0, 0xc000
/* 8EE778 80242958 10400002 */  beqz      $v0, .L80242964
/* 8EE77C 8024295C 24020003 */   addiu    $v0, $zero, 3
/* 8EE780 80242960 A6020000 */  sh        $v0, ($s0)
.L80242964:
/* 8EE784 80242964 96030000 */  lhu       $v1, ($s0)
/* 8EE788 80242968 24020003 */  addiu     $v0, $zero, 3
/* 8EE78C 8024296C 1462001E */  bne       $v1, $v0, .L802429E8
/* 8EE790 80242970 00000000 */   nop      
/* 8EE794 80242974 240400CA */  addiu     $a0, $zero, 0xca
/* 8EE798 80242978 0000282D */  daddu     $a1, $zero, $zero
/* 8EE79C 8024297C 00A0302D */  daddu     $a2, $a1, $zero
/* 8EE7A0 80242980 24020004 */  addiu     $v0, $zero, 4
/* 8EE7A4 80242984 AE000004 */  sw        $zero, 4($s0)
/* 8EE7A8 80242988 0C015478 */  jal       func_800551E0
/* 8EE7AC 8024298C A6020000 */   sh       $v0, ($s0)
/* 8EE7B0 80242990 0000202D */  daddu     $a0, $zero, $zero
/* 8EE7B4 80242994 8E020004 */  lw        $v0, 4($s0)
/* 8EE7B8 80242998 8603001C */  lh        $v1, 0x1c($s0)
/* 8EE7BC 8024299C 24420001 */  addiu     $v0, $v0, 1
/* 8EE7C0 802429A0 AE020004 */  sw        $v0, 4($s0)
/* 8EE7C4 802429A4 24020003 */  addiu     $v0, $zero, 3
/* 8EE7C8 802429A8 44831000 */  mtc1      $v1, $f2
/* 8EE7CC 802429AC 00000000 */  nop       
/* 8EE7D0 802429B0 468010A0 */  cvt.s.w   $f2, $f2
/* 8EE7D4 802429B4 AFA20010 */  sw        $v0, 0x10($sp)
/* 8EE7D8 802429B8 8E070004 */  lw        $a3, 4($s0)
/* 8EE7DC 802429BC 44051000 */  mfc1      $a1, $f2
/* 8EE7E0 802429C0 0C00A8ED */  jal       update_lerp
/* 8EE7E4 802429C4 0000302D */   daddu    $a2, $zero, $zero
/* 8EE7E8 802429C8 8E020004 */  lw        $v0, 4($s0)
/* 8EE7EC 802429CC 4600008D */  trunc.w.s $f2, $f0
/* 8EE7F0 802429D0 44031000 */  mfc1      $v1, $f2
/* 8EE7F4 802429D4 28420003 */  slti      $v0, $v0, 3
/* 8EE7F8 802429D8 14400003 */  bnez      $v0, .L802429E8
/* 8EE7FC 802429DC A603001A */   sh       $v1, 0x1a($s0)
/* 8EE800 802429E0 24020005 */  addiu     $v0, $zero, 5
/* 8EE804 802429E4 A6020000 */  sh        $v0, ($s0)
.L802429E8:
/* 8EE808 802429E8 8605001A */  lh        $a1, 0x1a($s0)
/* 8EE80C 802429EC 0C090868 */  jal       func_802421A0
/* 8EE810 802429F0 0200202D */   daddu    $a0, $s0, $zero
/* 8EE814 802429F4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8EE818 802429F8 8FB00018 */  lw        $s0, 0x18($sp)
/* 8EE81C 802429FC 03E00008 */  jr        $ra
/* 8EE820 80242A00 27BD0020 */   addiu    $sp, $sp, 0x20
