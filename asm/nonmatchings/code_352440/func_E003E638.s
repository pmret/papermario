.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E003E638
/* 352A78 E003E638 27BDFF50 */  addiu     $sp, $sp, -0xb0
/* 352A7C E003E63C 0080182D */  daddu     $v1, $a0, $zero
/* 352A80 E003E640 3C05DB06 */  lui       $a1, 0xdb06
/* 352A84 E003E644 34A50024 */  ori       $a1, $a1, 0x24
/* 352A88 E003E648 27A40010 */  addiu     $a0, $sp, 0x10
/* 352A8C E003E64C AFB500A4 */  sw        $s5, 0xa4($sp)
/* 352A90 E003E650 3C150001 */  lui       $s5, 1
/* 352A94 E003E654 AFB20098 */  sw        $s2, 0x98($sp)
/* 352A98 E003E658 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 352A9C E003E65C 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 352AA0 E003E660 AFB600A8 */  sw        $s6, 0xa8($sp)
/* 352AA4 E003E664 3C16E700 */  lui       $s6, 0xe700
/* 352AA8 E003E668 AFBF00AC */  sw        $ra, 0xac($sp)
/* 352AAC E003E66C AFB400A0 */  sw        $s4, 0xa0($sp)
/* 352AB0 E003E670 AFB3009C */  sw        $s3, 0x9c($sp)
/* 352AB4 E003E674 AFB10094 */  sw        $s1, 0x94($sp)
/* 352AB8 E003E678 AFB00090 */  sw        $s0, 0x90($sp)
/* 352ABC E003E67C 8E460000 */  lw        $a2, ($s2)
/* 352AC0 E003E680 8C70000C */  lw        $s0, 0xc($v1)
/* 352AC4 E003E684 00C0102D */  daddu     $v0, $a2, $zero
/* 352AC8 E003E688 24C60008 */  addiu     $a2, $a2, 8
/* 352ACC E003E68C AE460000 */  sw        $a2, ($s2)
/* 352AD0 E003E690 C600005C */  lwc1      $f0, 0x5c($s0)
/* 352AD4 E003E694 3C14DE00 */  lui       $s4, 0xde00
/* 352AD8 E003E698 AC560000 */  sw        $s6, ($v0)
/* 352ADC E003E69C AC400004 */  sw        $zero, 4($v0)
/* 352AE0 E003E6A0 24C20008 */  addiu     $v0, $a2, 8
/* 352AE4 E003E6A4 AE420000 */  sw        $v0, ($s2)
/* 352AE8 E003E6A8 24C20010 */  addiu     $v0, $a2, 0x10
/* 352AEC E003E6AC ACC50000 */  sw        $a1, ($a2)
/* 352AF0 E003E6B0 AE420000 */  sw        $v0, ($s2)
/* 352AF4 E003E6B4 8C630010 */  lw        $v1, 0x10($v1)
/* 352AF8 E003E6B8 24C20018 */  addiu     $v0, $a2, 0x18
/* 352AFC E003E6BC AE420000 */  sw        $v0, ($s2)
/* 352B00 E003E6C0 8C63001C */  lw        $v1, 0x1c($v1)
/* 352B04 E003E6C4 3C020900 */  lui       $v0, 0x900
/* 352B08 E003E6C8 24420200 */  addiu     $v0, $v0, 0x200
/* 352B0C E003E6CC ACC2000C */  sw        $v0, 0xc($a2)
/* 352B10 E003E6D0 3C02FA00 */  lui       $v0, 0xfa00
/* 352B14 E003E6D4 ACC20010 */  sw        $v0, 0x10($a2)
/* 352B18 E003E6D8 3C028000 */  lui       $v0, 0x8000
/* 352B1C E003E6DC ACD40008 */  sw        $s4, 8($a2)
/* 352B20 E003E6E0 00621821 */  addu      $v1, $v1, $v0
/* 352B24 E003E6E4 ACC30004 */  sw        $v1, 4($a2)
/* 352B28 E003E6E8 92020074 */  lbu       $v0, 0x74($s0)
/* 352B2C E003E6EC 92030075 */  lbu       $v1, 0x75($s0)
/* 352B30 E003E6F0 92050076 */  lbu       $a1, 0x76($s0)
/* 352B34 E003E6F4 00021600 */  sll       $v0, $v0, 0x18
/* 352B38 E003E6F8 00031C00 */  sll       $v1, $v1, 0x10
/* 352B3C E003E6FC 00431025 */  or        $v0, $v0, $v1
/* 352B40 E003E700 00052A00 */  sll       $a1, $a1, 8
/* 352B44 E003E704 9203006B */  lbu       $v1, 0x6b($s0)
/* 352B48 E003E708 00451025 */  or        $v0, $v0, $a1
/* 352B4C E003E70C 00431025 */  or        $v0, $v0, $v1
/* 352B50 E003E710 ACC20014 */  sw        $v0, 0x14($a2)
/* 352B54 E003E714 8E050004 */  lw        $a1, 4($s0)
/* 352B58 E003E718 8E060008 */  lw        $a2, 8($s0)
/* 352B5C E003E71C 8E07000C */  lw        $a3, 0xc($s0)
/* 352B60 E003E720 4600008D */  trunc.w.s $f2, $f0
/* 352B64 E003E724 44111000 */  mfc1      $s1, $f2
/* 352B68 E003E728 0C080108 */  jal       func_E0200420
/* 352B6C E003E72C 36B51630 */   ori      $s5, $s5, 0x1630
/* 352B70 E003E730 2604001C */  addiu     $a0, $s0, 0x1c
/* 352B74 E003E734 27A50010 */  addiu     $a1, $sp, 0x10
/* 352B78 E003E738 0C080114 */  jal       func_E0200450
/* 352B7C E003E73C 00A0302D */   daddu    $a2, $a1, $zero
/* 352B80 E003E740 8E050064 */  lw        $a1, 0x64($s0)
/* 352B84 E003E744 27B00050 */  addiu     $s0, $sp, 0x50
/* 352B88 E003E748 0200202D */  daddu     $a0, $s0, $zero
/* 352B8C E003E74C 00A0302D */  daddu     $a2, $a1, $zero
/* 352B90 E003E750 0C080110 */  jal       func_E0200440
/* 352B94 E003E754 00A0382D */   daddu    $a3, $a1, $zero
/* 352B98 E003E758 0200202D */  daddu     $a0, $s0, $zero
/* 352B9C E003E75C 27A50010 */  addiu     $a1, $sp, 0x10
/* 352BA0 E003E760 0C080114 */  jal       func_E0200450
/* 352BA4 E003E764 00A0302D */   daddu    $a2, $a1, $zero
/* 352BA8 E003E768 27A40010 */  addiu     $a0, $sp, 0x10
/* 352BAC E003E76C 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 352BB0 E003E770 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 352BB4 E003E774 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* 352BB8 E003E778 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* 352BBC E003E77C 96050000 */  lhu       $a1, ($s0)
/* 352BC0 E003E780 8E620000 */  lw        $v0, ($s3)
/* 352BC4 E003E784 00052980 */  sll       $a1, $a1, 6
/* 352BC8 E003E788 00B52821 */  addu      $a1, $a1, $s5
/* 352BCC E003E78C 0C080118 */  jal       func_E0200460
/* 352BD0 E003E790 00452821 */   addu     $a1, $v0, $a1
/* 352BD4 E003E794 3C06D838 */  lui       $a2, 0xd838
/* 352BD8 E003E798 8E440000 */  lw        $a0, ($s2)
/* 352BDC E003E79C 34C60002 */  ori       $a2, $a2, 2
/* 352BE0 E003E7A0 0080282D */  daddu     $a1, $a0, $zero
/* 352BE4 E003E7A4 24840008 */  addiu     $a0, $a0, 8
/* 352BE8 E003E7A8 AE440000 */  sw        $a0, ($s2)
/* 352BEC E003E7AC 96020000 */  lhu       $v0, ($s0)
/* 352BF0 E003E7B0 3C03DA38 */  lui       $v1, 0xda38
/* 352BF4 E003E7B4 ACA30000 */  sw        $v1, ($a1)
/* 352BF8 E003E7B8 24430001 */  addiu     $v1, $v0, 1
/* 352BFC E003E7BC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 352C00 E003E7C0 00021180 */  sll       $v0, $v0, 6
/* 352C04 E003E7C4 A6030000 */  sh        $v1, ($s0)
/* 352C08 E003E7C8 8E630000 */  lw        $v1, ($s3)
/* 352C0C E003E7CC 00551021 */  addu      $v0, $v0, $s5
/* 352C10 E003E7D0 00621821 */  addu      $v1, $v1, $v0
/* 352C14 E003E7D4 24820008 */  addiu     $v0, $a0, 8
/* 352C18 E003E7D8 ACA30004 */  sw        $v1, 4($a1)
/* 352C1C E003E7DC AE420000 */  sw        $v0, ($s2)
/* 352C20 E003E7E0 32220FFF */  andi      $v0, $s1, 0xfff
/* 352C24 E003E7E4 3C03F200 */  lui       $v1, 0xf200
/* 352C28 E003E7E8 00431025 */  or        $v0, $v0, $v1
/* 352C2C E003E7EC AC820000 */  sw        $v0, ($a0)
/* 352C30 E003E7F0 3C020010 */  lui       $v0, 0x10
/* 352C34 E003E7F4 26310040 */  addiu     $s1, $s1, 0x40
/* 352C38 E003E7F8 32310FFF */  andi      $s1, $s1, 0xfff
/* 352C3C E003E7FC 02228825 */  or        $s1, $s1, $v0
/* 352C40 E003E800 24820010 */  addiu     $v0, $a0, 0x10
/* 352C44 E003E804 AC910004 */  sw        $s1, 4($a0)
/* 352C48 E003E808 AE420000 */  sw        $v0, ($s2)
/* 352C4C E003E80C 3C020900 */  lui       $v0, 0x900
/* 352C50 E003E810 244204E8 */  addiu     $v0, $v0, 0x4e8
/* 352C54 E003E814 AC82000C */  sw        $v0, 0xc($a0)
/* 352C58 E003E818 24820018 */  addiu     $v0, $a0, 0x18
/* 352C5C E003E81C AC940008 */  sw        $s4, 8($a0)
/* 352C60 E003E820 AE420000 */  sw        $v0, ($s2)
/* 352C64 E003E824 24020040 */  addiu     $v0, $zero, 0x40
/* 352C68 E003E828 AC820014 */  sw        $v0, 0x14($a0)
/* 352C6C E003E82C 24820020 */  addiu     $v0, $a0, 0x20
/* 352C70 E003E830 AC860010 */  sw        $a2, 0x10($a0)
/* 352C74 E003E834 AE420000 */  sw        $v0, ($s2)
/* 352C78 E003E838 AC960018 */  sw        $s6, 0x18($a0)
/* 352C7C E003E83C AC80001C */  sw        $zero, 0x1c($a0)
/* 352C80 E003E840 8FBF00AC */  lw        $ra, 0xac($sp)
/* 352C84 E003E844 8FB600A8 */  lw        $s6, 0xa8($sp)
/* 352C88 E003E848 8FB500A4 */  lw        $s5, 0xa4($sp)
/* 352C8C E003E84C 8FB400A0 */  lw        $s4, 0xa0($sp)
/* 352C90 E003E850 8FB3009C */  lw        $s3, 0x9c($sp)
/* 352C94 E003E854 8FB20098 */  lw        $s2, 0x98($sp)
/* 352C98 E003E858 8FB10094 */  lw        $s1, 0x94($sp)
/* 352C9C E003E85C 8FB00090 */  lw        $s0, 0x90($sp)
/* 352CA0 E003E860 03E00008 */  jr        $ra
/* 352CA4 E003E864 27BD00B0 */   addiu    $sp, $sp, 0xb0
/* 352CA8 E003E868 00000000 */  nop       
/* 352CAC E003E86C 00000000 */  nop       
