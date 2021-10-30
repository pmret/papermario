.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005E660
/* 39A60 8005E660 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 39A64 8005E664 AFB40028 */  sw        $s4, 0x28($sp)
/* 39A68 8005E668 0080A02D */  daddu     $s4, $a0, $zero
/* 39A6C 8005E66C AFB30024 */  sw        $s3, 0x24($sp)
/* 39A70 8005E670 00A0982D */  daddu     $s3, $a1, $zero
/* 39A74 8005E674 3C04800E */  lui       $a0, %hi(D_800DAA8C)
/* 39A78 8005E678 2484AA8C */  addiu     $a0, $a0, %lo(D_800DAA8C)
/* 39A7C 8005E67C 24020001 */  addiu     $v0, $zero, 1
/* 39A80 8005E680 24030002 */  addiu     $v1, $zero, 2
/* 39A84 8005E684 AFBF002C */  sw        $ra, 0x2c($sp)
/* 39A88 8005E688 AFB20020 */  sw        $s2, 0x20($sp)
/* 39A8C 8005E68C AFB1001C */  sw        $s1, 0x1c($sp)
/* 39A90 8005E690 AFB00018 */  sw        $s0, 0x18($sp)
/* 39A94 8005E694 A482F994 */  sh        $v0, -0x66c($a0)
/* 39A98 8005E698 326200FF */  andi      $v0, $s3, 0xff
/* 39A9C 8005E69C AC82000C */  sw        $v0, 0xc($a0)
/* 39AA0 8005E6A0 A0830011 */  sb        $v1, 0x11($a0)
/* 39AA4 8005E6A4 3C028000 */  lui       $v0, %hi(osTvType)
/* 39AA8 8005E6A8 8C420300 */  lw        $v0, %lo(osTvType)($v0)
/* 39AAC 8005E6AC A483F996 */  sh        $v1, -0x66a($a0)
/* 39AB0 8005E6B0 2483F994 */  addiu     $v1, $a0, -0x66c
/* 39AB4 8005E6B4 AC800000 */  sw        $zero, ($a0)
/* 39AB8 8005E6B8 AC800004 */  sw        $zero, 4($a0)
/* 39ABC 8005E6BC AC800008 */  sw        $zero, 8($a0)
/* 39AC0 8005E6C0 14400004 */  bnez      $v0, .L8005E6D4
/* 39AC4 8005E6C4 AC80FFFC */   sw       $zero, -4($a0)
/* 39AC8 8005E6C8 24020032 */  addiu     $v0, $zero, 0x32
/* 39ACC 8005E6CC 080179B7 */  j         .L8005E6DC
/* 39AD0 8005E6D0 A062067C */   sb       $v0, 0x67c($v1)
.L8005E6D4:
/* 39AD4 8005E6D4 2402003C */  addiu     $v0, $zero, 0x3c
/* 39AD8 8005E6D8 A0820010 */  sb        $v0, 0x10($a0)
.L8005E6DC:
/* 39ADC 8005E6DC 3C10800E */  lui       $s0, %hi(D_800DA494)
/* 39AE0 8005E6E0 2610A494 */  addiu     $s0, $s0, %lo(D_800DA494)
/* 39AE4 8005E6E4 0200202D */  daddu     $a0, $s0, $zero
/* 39AE8 8005E6E8 26050018 */  addiu     $a1, $s0, 0x18
/* 39AEC 8005E6EC 3C01800A */  lui       $at, %hi(D_8009A590)
/* 39AF0 8005E6F0 A020A590 */  sb        $zero, %lo(D_8009A590)($at)
/* 39AF4 8005E6F4 0C019554 */  jal       func_80065550
/* 39AF8 8005E6F8 24060008 */   addiu    $a2, $zero, 8
/* 39AFC 8005E6FC 26120038 */  addiu     $s2, $s0, 0x38
/* 39B00 8005E700 0240202D */  daddu     $a0, $s2, $zero
/* 39B04 8005E704 26050050 */  addiu     $a1, $s0, 0x50
/* 39B08 8005E708 0C019554 */  jal       func_80065550
/* 39B0C 8005E70C 24060008 */   addiu    $a2, $zero, 8
/* 39B10 8005E710 26110070 */  addiu     $s1, $s0, 0x70
/* 39B14 8005E714 0220202D */  daddu     $a0, $s1, $zero
/* 39B18 8005E718 26050088 */  addiu     $a1, $s0, 0x88
/* 39B1C 8005E71C 0C019554 */  jal       func_80065550
/* 39B20 8005E720 24060008 */   addiu    $a2, $zero, 8
/* 39B24 8005E724 2604FFC8 */  addiu     $a0, $s0, -0x38
/* 39B28 8005E728 2605FFE0 */  addiu     $a1, $s0, -0x20
/* 39B2C 8005E72C 0C019554 */  jal       func_80065550
/* 39B30 8005E730 24060008 */   addiu    $a2, $zero, 8
/* 39B34 8005E734 2604FF90 */  addiu     $a0, $s0, -0x70
/* 39B38 8005E738 2605FFA8 */  addiu     $a1, $s0, -0x58
/* 39B3C 8005E73C 0C019554 */  jal       func_80065550
/* 39B40 8005E740 24060008 */   addiu    $a2, $zero, 8
/* 39B44 8005E744 260400A8 */  addiu     $a0, $s0, 0xa8
/* 39B48 8005E748 260500C0 */  addiu     $a1, $s0, 0xc0
/* 39B4C 8005E74C 0C019554 */  jal       func_80065550
/* 39B50 8005E750 24060008 */   addiu    $a2, $zero, 8
/* 39B54 8005E754 0C019A90 */  jal       func_80066A40
/* 39B58 8005E758 240400FE */   addiu    $a0, $zero, 0xfe
/* 39B5C 8005E75C 328200FF */  andi      $v0, $s4, 0xff
/* 39B60 8005E760 00022080 */  sll       $a0, $v0, 2
/* 39B64 8005E764 00822021 */  addu      $a0, $a0, $v0
/* 39B68 8005E768 00042100 */  sll       $a0, $a0, 4
/* 39B6C 8005E76C 3C028009 */  lui       $v0, %hi(D_80094680)
/* 39B70 8005E770 24424680 */  addiu     $v0, $v0, %lo(D_80094680)
/* 39B74 8005E774 0C019B78 */  jal       func_80066DE0
/* 39B78 8005E778 00822021 */   addu     $a0, $a0, $v0
/* 39B7C 8005E77C 0C019CD4 */  jal       func_80067350
/* 39B80 8005E780 24040001 */   addiu    $a0, $zero, 1
/* 39B84 8005E784 0200202D */  daddu     $a0, $s0, $zero
/* 39B88 8005E788 2405029A */  addiu     $a1, $zero, 0x29a
/* 39B8C 8005E78C 0C019B60 */  jal       func_80066D80
/* 39B90 8005E790 326600FF */   andi     $a2, $s3, 0xff
/* 39B94 8005E794 24040004 */  addiu     $a0, $zero, 4
/* 39B98 8005E798 0240282D */  daddu     $a1, $s2, $zero
/* 39B9C 8005E79C 0C019648 */  jal       func_80065920
/* 39BA0 8005E7A0 2406029B */   addiu    $a2, $zero, 0x29b
/* 39BA4 8005E7A4 24040009 */  addiu     $a0, $zero, 9
/* 39BA8 8005E7A8 0220282D */  daddu     $a1, $s1, $zero
/* 39BAC 8005E7AC 0C019648 */  jal       func_80065920
/* 39BB0 8005E7B0 2406029C */   addiu    $a2, $zero, 0x29c
/* 39BB4 8005E7B4 2404000E */  addiu     $a0, $zero, 0xe
/* 39BB8 8005E7B8 0200282D */  daddu     $a1, $s0, $zero
/* 39BBC 8005E7BC 0C019648 */  jal       func_80065920
/* 39BC0 8005E7C0 2406029D */   addiu    $a2, $zero, 0x29d
/* 39BC4 8005E7C4 261200E4 */  addiu     $s2, $s0, 0xe4
/* 39BC8 8005E7C8 0240202D */  daddu     $a0, $s2, $zero
/* 39BCC 8005E7CC 24050013 */  addiu     $a1, $zero, 0x13
/* 39BD0 8005E7D0 3C068006 */  lui       $a2, %hi(func_8005EC58)
/* 39BD4 8005E7D4 24C6EC58 */  addiu     $a2, $a2, %lo(func_8005EC58)
/* 39BD8 8005E7D8 2611FF8C */  addiu     $s1, $s0, -0x74
/* 39BDC 8005E7DC 0220382D */  daddu     $a3, $s1, $zero
/* 39BE0 8005E7E0 3C02800A */  lui       $v0, %hi(D_800A63E0)
/* 39BE4 8005E7E4 244263E0 */  addiu     $v0, $v0, %lo(D_800A63E0)
/* 39BE8 8005E7E8 AFA20010 */  sw        $v0, 0x10($sp)
/* 39BEC 8005E7EC 24020078 */  addiu     $v0, $zero, 0x78
/* 39BF0 8005E7F0 0C01978C */  jal       func_80065E30
/* 39BF4 8005E7F4 AFA20014 */   sw       $v0, 0x14($sp)
/* 39BF8 8005E7F8 0C0197FC */  jal       func_80065FF0
/* 39BFC 8005E7FC 0240202D */   daddu    $a0, $s2, $zero
/* 39C00 8005E800 26120294 */  addiu     $s2, $s0, 0x294
/* 39C04 8005E804 0240202D */  daddu     $a0, $s2, $zero
/* 39C08 8005E808 24050012 */  addiu     $a1, $zero, 0x12
/* 39C0C 8005E80C 3C068006 */  lui       $a2, %hi(func_8005E890)
/* 39C10 8005E810 24C6E890 */  addiu     $a2, $a2, %lo(func_8005E890)
/* 39C14 8005E814 0220382D */  daddu     $a3, $s1, $zero
/* 39C18 8005E818 3C02800B */  lui       $v0, %hi(D_800A83E0)
/* 39C1C 8005E81C 244283E0 */  addiu     $v0, $v0, %lo(D_800A83E0)
/* 39C20 8005E820 AFA20010 */  sw        $v0, 0x10($sp)
/* 39C24 8005E824 2402006E */  addiu     $v0, $zero, 0x6e
/* 39C28 8005E828 0C01978C */  jal       func_80065E30
/* 39C2C 8005E82C AFA20014 */   sw       $v0, 0x14($sp)
/* 39C30 8005E830 0C0197FC */  jal       func_80065FF0
/* 39C34 8005E834 0240202D */   daddu    $a0, $s2, $zero
/* 39C38 8005E838 26100444 */  addiu     $s0, $s0, 0x444
/* 39C3C 8005E83C 0200202D */  daddu     $a0, $s0, $zero
/* 39C40 8005E840 24050011 */  addiu     $a1, $zero, 0x11
/* 39C44 8005E844 3C068006 */  lui       $a2, %hi(D_8005E9C4)
/* 39C48 8005E848 24C6E9C4 */  addiu     $a2, $a2, %lo(D_8005E9C4)
/* 39C4C 8005E84C 0220382D */  daddu     $a3, $s1, $zero
/* 39C50 8005E850 3C02800B */  lui       $v0, %hi(D_800AA3E0)
/* 39C54 8005E854 2442A3E0 */  addiu     $v0, $v0, %lo(D_800AA3E0)
/* 39C58 8005E858 AFA20010 */  sw        $v0, 0x10($sp)
/* 39C5C 8005E85C 24020064 */  addiu     $v0, $zero, 0x64
/* 39C60 8005E860 0C01978C */  jal       func_80065E30
/* 39C64 8005E864 AFA20014 */   sw       $v0, 0x14($sp)
/* 39C68 8005E868 0C0197FC */  jal       func_80065FF0
/* 39C6C 8005E86C 0200202D */   daddu    $a0, $s0, $zero
/* 39C70 8005E870 8FBF002C */  lw        $ra, 0x2c($sp)
/* 39C74 8005E874 8FB40028 */  lw        $s4, 0x28($sp)
/* 39C78 8005E878 8FB30024 */  lw        $s3, 0x24($sp)
/* 39C7C 8005E87C 8FB20020 */  lw        $s2, 0x20($sp)
/* 39C80 8005E880 8FB1001C */  lw        $s1, 0x1c($sp)
/* 39C84 8005E884 8FB00018 */  lw        $s0, 0x18($sp)
/* 39C88 8005E888 03E00008 */  jr        $ra
/* 39C8C 8005E88C 27BD0030 */   addiu    $sp, $sp, 0x30
