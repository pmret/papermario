.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802E0DE0
/* 102660 802E0DE0 27BDFF28 */  addiu $sp, $sp, -0xd8
/* 102664 802E0DE4 AFB000A8 */  sw    $s0, 0xa8($sp)
/* 102668 802E0DE8 3C10800A */  lui   $s0, 0x800a
/* 10266C 802E0DEC 8E10A66C */  lw    $s0, -0x5994($s0)
/* 102670 802E0DF0 AFBF00CC */  sw    $ra, 0xcc($sp)
/* 102674 802E0DF4 AFBE00C8 */  sw    $fp, 0xc8($sp)
/* 102678 802E0DF8 AFB700C4 */  sw    $s7, 0xc4($sp)
/* 10267C 802E0DFC AFB600C0 */  sw    $s6, 0xc0($sp)
/* 102680 802E0E00 AFB500BC */  sw    $s5, 0xbc($sp)
/* 102684 802E0E04 AFB400B8 */  sw    $s4, 0xb8($sp)
/* 102688 802E0E08 AFB300B4 */  sw    $s3, 0xb4($sp)
/* 10268C 802E0E0C AFB200B0 */  sw    $s2, 0xb0($sp)
/* 102690 802E0E10 AFB100AC */  sw    $s1, 0xac($sp)
/* 102694 802E0E14 F7B400D0 */  sdc1  $f20, 0xd0($sp)
/* 102698 802E0E18 0C04417A */  jal   get_entity_by_index
/* 10269C 802E0E1C 3C170001 */   lui   $s7, 1
/* 1026A0 802E0E20 27A40018 */  addiu $a0, $sp, 0x18
/* 1026A4 802E0E24 36F71630 */  ori   $s7, $s7, 0x1630
/* 1026A8 802E0E28 3C0DE200 */  lui   $t5, 0xe200
/* 1026AC 802E0E2C 35AD001C */  ori   $t5, $t5, 0x1c
/* 1026B0 802E0E30 AFAD0098 */  sw    $t5, 0x98($sp)
/* 1026B4 802E0E34 3C0DFCFF */  lui   $t5, 0xfcff
/* 1026B8 802E0E38 35ADB3FF */  ori   $t5, $t5, 0xb3ff
/* 1026BC 802E0E3C AFAD009C */  sw    $t5, 0x9c($sp)
/* 1026C0 802E0E40 3C0DFF2C */  lui   $t5, 0xff2c
/* 1026C4 802E0E44 35ADFE7F */  ori   $t5, $t5, 0xfe7f
/* 1026C8 802E0E48 AFAD00A0 */  sw    $t5, 0xa0($sp)
/* 1026CC 802E0E4C 3C0DD838 */  lui   $t5, 0xd838
/* 1026D0 802E0E50 0040B02D */  daddu $s6, $v0, $zero
/* 1026D4 802E0E54 3C140A00 */  lui   $s4, 0xa00
/* 1026D8 802E0E58 26943260 */  addiu $s4, $s4, 0x3260
/* 1026DC 802E0E5C 3294FFFF */  andi  $s4, $s4, 0xffff
/* 1026E0 802E0E60 AFAD00A4 */  sw    $t5, 0xa4($sp)
/* 1026E4 802E0E64 8EC50044 */  lw    $a1, 0x44($s6)
/* 1026E8 802E0E68 8ED20040 */  lw    $s2, 0x40($s6)
/* 1026EC 802E0E6C 0C019D60 */  jal   guMtxL2F
/* 1026F0 802E0E70 00B42821 */   addu  $a1, $a1, $s4
/* 1026F4 802E0E74 27B10058 */  addiu $s1, $sp, 0x58
/* 1026F8 802E0E78 C7A0004C */  lwc1  $f0, 0x4c($sp)
/* 1026FC 802E0E7C 3C014148 */  lui   $at, 0x4148
/* 102700 802E0E80 4481A000 */  mtc1  $at, $f20
/* 102704 802E0E84 44801000 */  mtc1  $zero, $f2
/* 102708 802E0E88 8FAD00A4 */  lw    $t5, 0xa4($sp)
/* 10270C 802E0E8C 3C073F80 */  lui   $a3, 0x3f80
/* 102710 802E0E90 46140000 */  add.s $f0, $f0, $f20
/* 102714 802E0E94 35AD0002 */  ori   $t5, $t5, 2
/* 102718 802E0E98 AFAD00A4 */  sw    $t5, 0xa4($sp)
/* 10271C 802E0E9C E7A0004C */  swc1  $f0, 0x4c($sp)
/* 102720 802E0EA0 86420004 */  lh    $v0, 4($s2)
/* 102724 802E0EA4 44061000 */  mfc1  $a2, $f2
/* 102728 802E0EA8 44822000 */  mtc1  $v0, $f4
/* 10272C 802E0EAC 00000000 */  nop   
/* 102730 802E0EB0 46802120 */  cvt.s.w $f4, $f4
/* 102734 802E0EB4 44052000 */  mfc1  $a1, $f4
/* 102738 802E0EB8 0220202D */  daddu $a0, $s1, $zero
/* 10273C 802E0EBC 0C019EC8 */  jal   guRotateF
/* 102740 802E0EC0 AFA60010 */   sw    $a2, 0x10($sp)
/* 102744 802E0EC4 0220202D */  daddu $a0, $s1, $zero
/* 102748 802E0EC8 27A50018 */  addiu $a1, $sp, 0x18
/* 10274C 802E0ECC 0C019D80 */  jal   guMtxCatF
/* 102750 802E0ED0 0220302D */   daddu $a2, $s1, $zero
/* 102754 802E0ED4 0220202D */  daddu $a0, $s1, $zero
/* 102758 802E0ED8 3C138007 */  lui   $s3, 0x8007
/* 10275C 802E0EDC 267341F0 */  addiu $s3, $s3, 0x41f0
/* 102760 802E0EE0 3C15800A */  lui   $s5, 0x800a
/* 102764 802E0EE4 26B5A674 */  addiu $s5, $s5, -0x598c
/* 102768 802E0EE8 96650000 */  lhu   $a1, ($s3)
/* 10276C 802E0EEC 8EA20000 */  lw    $v0, ($s5)
/* 102770 802E0EF0 00052980 */  sll   $a1, $a1, 6
/* 102774 802E0EF4 00B72821 */  addu  $a1, $a1, $s7
/* 102778 802E0EF8 0C019D40 */  jal   guMtxF2L
/* 10277C 802E0EFC 00452821 */   addu  $a1, $v0, $a1
/* 102780 802E0F00 0200382D */  daddu $a3, $s0, $zero
/* 102784 802E0F04 26100008 */  addiu $s0, $s0, 8
/* 102788 802E0F08 0200402D */  daddu $t0, $s0, $zero
/* 10278C 802E0F0C 26100008 */  addiu $s0, $s0, 8
/* 102790 802E0F10 3C0C0050 */  lui   $t4, 0x50
/* 102794 802E0F14 358C4B50 */  ori   $t4, $t4, 0x4b50
/* 102798 802E0F18 0200302D */  daddu $a2, $s0, $zero
/* 10279C 802E0F1C 26100008 */  addiu $s0, $s0, 8
/* 1027A0 802E0F20 0200482D */  daddu $t1, $s0, $zero
/* 1027A4 802E0F24 26100008 */  addiu $s0, $s0, 8
/* 1027A8 802E0F28 0200502D */  daddu $t2, $s0, $zero
/* 1027AC 802E0F2C 26100008 */  addiu $s0, $s0, 8
/* 1027B0 802E0F30 0200582D */  daddu $t3, $s0, $zero
/* 1027B4 802E0F34 26100008 */  addiu $s0, $s0, 8
/* 1027B8 802E0F38 0220202D */  daddu $a0, $s1, $zero
/* 1027BC 802E0F3C 96650000 */  lhu   $a1, ($s3)
/* 1027C0 802E0F40 3C0DDA38 */  lui   $t5, 0xda38
/* 1027C4 802E0F44 ACED0000 */  sw    $t5, ($a3)
/* 1027C8 802E0F48 8EA30000 */  lw    $v1, ($s5)
/* 1027CC 802E0F4C 30A2FFFF */  andi  $v0, $a1, 0xffff
/* 1027D0 802E0F50 00021180 */  sll   $v0, $v0, 6
/* 1027D4 802E0F54 00571021 */  addu  $v0, $v0, $s7
/* 1027D8 802E0F58 00621821 */  addu  $v1, $v1, $v0
/* 1027DC 802E0F5C ACE30004 */  sw    $v1, 4($a3)
/* 1027E0 802E0F60 8FAD0098 */  lw    $t5, 0x98($sp)
/* 1027E4 802E0F64 241E0040 */  addiu $fp, $zero, 0x40
/* 1027E8 802E0F68 AD0C0004 */  sw    $t4, 4($t0)
/* 1027EC 802E0F6C AD0D0000 */  sw    $t5, ($t0)
/* 1027F0 802E0F70 8FAD009C */  lw    $t5, 0x9c($sp)
/* 1027F4 802E0F74 3C020A00 */  lui   $v0, 0xa00
/* 1027F8 802E0F78 244234E0 */  addiu $v0, $v0, 0x34e0
/* 1027FC 802E0F7C ACCD0000 */  sw    $t5, ($a2)
/* 102800 802E0F80 8FAD00A0 */  lw    $t5, 0xa0($sp)
/* 102804 802E0F84 24A50001 */  addiu $a1, $a1, 1
/* 102808 802E0F88 ACCD0004 */  sw    $t5, 4($a2)
/* 10280C 802E0F8C 3C0DFA00 */  lui   $t5, 0xfa00
/* 102810 802E0F90 AD2D0000 */  sw    $t5, ($t1)
/* 102814 802E0F94 240D0080 */  addiu $t5, $zero, 0x80
/* 102818 802E0F98 AD2D0004 */  sw    $t5, 4($t1)
/* 10281C 802E0F9C 3C0DDE00 */  lui   $t5, 0xde00
/* 102820 802E0FA0 AD4D0000 */  sw    $t5, ($t2)
/* 102824 802E0FA4 AD420004 */  sw    $v0, 4($t2)
/* 102828 802E0FA8 8FAD00A4 */  lw    $t5, 0xa4($sp)
/* 10282C 802E0FAC 3C020A00 */  lui   $v0, 0xa00
/* 102830 802E0FB0 244234F0 */  addiu $v0, $v0, 0x34f0
/* 102834 802E0FB4 AD7E0004 */  sw    $fp, 4($t3)
/* 102838 802E0FB8 AD6D0000 */  sw    $t5, ($t3)
/* 10283C 802E0FBC 8ED20044 */  lw    $s2, 0x44($s6)
/* 102840 802E0FC0 3042FFFF */  andi  $v0, $v0, 0xffff
/* 102844 802E0FC4 A6650000 */  sh    $a1, ($s3)
/* 102848 802E0FC8 02542821 */  addu  $a1, $s2, $s4
/* 10284C 802E0FCC 0C019D60 */  jal   guMtxL2F
/* 102850 802E0FD0 02429021 */   addu  $s2, $s2, $v0
/* 102854 802E0FD4 0200182D */  daddu $v1, $s0, $zero
/* 102858 802E0FD8 26100008 */  addiu $s0, $s0, 8
/* 10285C 802E0FDC 0220202D */  daddu $a0, $s1, $zero
/* 102860 802E0FE0 96650000 */  lhu   $a1, ($s3)
/* 102864 802E0FE4 C7A0008C */  lwc1  $f0, 0x8c($sp)
/* 102868 802E0FE8 8EA20000 */  lw    $v0, ($s5)
/* 10286C 802E0FEC 00052980 */  sll   $a1, $a1, 6
/* 102870 802E0FF0 00B72821 */  addu  $a1, $a1, $s7
/* 102874 802E0FF4 46140000 */  add.s $f0, $f0, $f20
/* 102878 802E0FF8 00452821 */  addu  $a1, $v0, $a1
/* 10287C 802E0FFC 3C02E700 */  lui   $v0, 0xe700
/* 102880 802E1000 E7A0008C */  swc1  $f0, 0x8c($sp)
/* 102884 802E1004 AC620000 */  sw    $v0, ($v1)
/* 102888 802E1008 0C019D40 */  jal   guMtxF2L
/* 10288C 802E100C AC600004 */   sw    $zero, 4($v1)
/* 102890 802E1010 0200402D */  daddu $t0, $s0, $zero
/* 102894 802E1014 26100008 */  addiu $s0, $s0, 8
/* 102898 802E1018 0200482D */  daddu $t1, $s0, $zero
/* 10289C 802E101C 26100008 */  addiu $s0, $s0, 8
/* 1028A0 802E1020 3C0A0050 */  lui   $t2, 0x50
/* 1028A4 802E1024 0200202D */  daddu $a0, $s0, $zero
/* 1028A8 802E1028 26100008 */  addiu $s0, $s0, 8
/* 1028AC 802E102C 0200282D */  daddu $a1, $s0, $zero
/* 1028B0 802E1030 26100008 */  addiu $s0, $s0, 8
/* 1028B4 802E1034 0200302D */  daddu $a2, $s0, $zero
/* 1028B8 802E1038 26100008 */  addiu $s0, $s0, 8
/* 1028BC 802E103C 0200382D */  daddu $a3, $s0, $zero
/* 1028C0 802E1040 26100008 */  addiu $s0, $s0, 8
/* 1028C4 802E1044 96620000 */  lhu   $v0, ($s3)
/* 1028C8 802E1048 3C0DDA38 */  lui   $t5, 0xda38
/* 1028CC 802E104C AD0D0000 */  sw    $t5, ($t0)
/* 1028D0 802E1050 3C01800A */  lui   $at, 0x800a
/* 1028D4 802E1054 AC30A66C */  sw    $s0, -0x5994($at)
/* 1028D8 802E1058 24430001 */  addiu $v1, $v0, 1
/* 1028DC 802E105C 3042FFFF */  andi  $v0, $v0, 0xffff
/* 1028E0 802E1060 00021180 */  sll   $v0, $v0, 6
/* 1028E4 802E1064 A6630000 */  sh    $v1, ($s3)
/* 1028E8 802E1068 8EA30000 */  lw    $v1, ($s5)
/* 1028EC 802E106C 00571021 */  addu  $v0, $v0, $s7
/* 1028F0 802E1070 00621821 */  addu  $v1, $v1, $v0
/* 1028F4 802E1074 AD030004 */  sw    $v1, 4($t0)
/* 1028F8 802E1078 8FAD0098 */  lw    $t5, 0x98($sp)
/* 1028FC 802E107C 354A41D8 */  ori   $t2, $t2, 0x41d8
/* 102900 802E1080 AD2D0000 */  sw    $t5, ($t1)
/* 102904 802E1084 AD2A0004 */  sw    $t2, 4($t1)
/* 102908 802E1088 8FAD009C */  lw    $t5, 0x9c($sp)
/* 10290C 802E108C AC8D0000 */  sw    $t5, ($a0)
/* 102910 802E1090 8FAD00A0 */  lw    $t5, 0xa0($sp)
/* 102914 802E1094 AC8D0004 */  sw    $t5, 4($a0)
/* 102918 802E1098 3C0DFA00 */  lui   $t5, 0xfa00
/* 10291C 802E109C ACAD0000 */  sw    $t5, ($a1)
/* 102920 802E10A0 240D0080 */  addiu $t5, $zero, 0x80
/* 102924 802E10A4 ACAD0004 */  sw    $t5, 4($a1)
/* 102928 802E10A8 3C0DDE00 */  lui   $t5, 0xde00
/* 10292C 802E10AC ACCD0000 */  sw    $t5, ($a2)
/* 102930 802E10B0 ACD20004 */  sw    $s2, 4($a2)
/* 102934 802E10B4 8FAD00A4 */  lw    $t5, 0xa4($sp)
/* 102938 802E10B8 ACED0000 */  sw    $t5, ($a3)
/* 10293C 802E10BC ACFE0004 */  sw    $fp, 4($a3)
/* 102940 802E10C0 8FBF00CC */  lw    $ra, 0xcc($sp)
/* 102944 802E10C4 8FBE00C8 */  lw    $fp, 0xc8($sp)
/* 102948 802E10C8 8FB700C4 */  lw    $s7, 0xc4($sp)
/* 10294C 802E10CC 8FB600C0 */  lw    $s6, 0xc0($sp)
/* 102950 802E10D0 8FB500BC */  lw    $s5, 0xbc($sp)
/* 102954 802E10D4 8FB400B8 */  lw    $s4, 0xb8($sp)
/* 102958 802E10D8 8FB300B4 */  lw    $s3, 0xb4($sp)
/* 10295C 802E10DC 8FB200B0 */  lw    $s2, 0xb0($sp)
/* 102960 802E10E0 8FB100AC */  lw    $s1, 0xac($sp)
/* 102964 802E10E4 8FB000A8 */  lw    $s0, 0xa8($sp)
/* 102968 802E10E8 D7B400D0 */  ldc1  $f20, 0xd0($sp)
/* 10296C 802E10EC 03E00008 */  jr    $ra
/* 102970 802E10F0 27BD00D8 */   addiu $sp, $sp, 0xd8

/* 102974 802E10F4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 102978 802E10F8 AFB10014 */  sw    $s1, 0x14($sp)
/* 10297C 802E10FC 0080882D */  daddu $s1, $a0, $zero
/* 102980 802E1100 AFBF0018 */  sw    $ra, 0x18($sp)
/* 102984 802E1104 AFB00010 */  sw    $s0, 0x10($sp)
/* 102988 802E1108 8E300040 */  lw    $s0, 0x40($s1)
/* 10298C 802E110C 86020004 */  lh    $v0, 4($s0)
/* 102990 802E1110 24420006 */  addiu $v0, $v0, 6
/* 102994 802E1114 44826000 */  mtc1  $v0, $f12
/* 102998 802E1118 00000000 */  nop   
/* 10299C 802E111C 0C00A6C9 */  jal   clamp_angle
/* 1029A0 802E1120 46806320 */   cvt.s.w $f12, $f12
/* 1029A4 802E1124 4600008D */  trunc.w.s $f2, $f0
/* 1029A8 802E1128 44021000 */  mfc1  $v0, $f2
/* 1029AC 802E112C 0220202D */  daddu $a0, $s1, $zero
/* 1029B0 802E1130 0C0B8D94 */  jal   func_802E3650
/* 1029B4 802E1134 A6020004 */   sh    $v0, 4($s0)
/* 1029B8 802E1138 8FBF0018 */  lw    $ra, 0x18($sp)
/* 1029BC 802E113C 8FB10014 */  lw    $s1, 0x14($sp)
/* 1029C0 802E1140 8FB00010 */  lw    $s0, 0x10($sp)
/* 1029C4 802E1144 03E00008 */  jr    $ra
/* 1029C8 802E1148 27BD0020 */   addiu $sp, $sp, 0x20

/* 1029CC 802E114C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1029D0 802E1150 AFBF0010 */  sw    $ra, 0x10($sp)
/* 1029D4 802E1154 0C009C22 */  jal   func_80027088
/* 1029D8 802E1158 24040001 */   addiu $a0, $zero, 1
/* 1029DC 802E115C 0C03805E */  jal   func_800E0178
/* 1029E0 802E1160 00000000 */   nop   
/* 1029E4 802E1164 3C02800F */  lui   $v0, 0x800f
/* 1029E8 802E1168 8C427B30 */  lw    $v0, 0x7b30($v0)
/* 1029EC 802E116C AC400054 */  sw    $zero, 0x54($v0)
/* 1029F0 802E1170 8FBF0010 */  lw    $ra, 0x10($sp)
/* 1029F4 802E1174 03E00008 */  jr    $ra
/* 1029F8 802E1178 27BD0018 */   addiu $sp, $sp, 0x18

/* 1029FC 802E117C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 102A00 802E1180 AFBF0010 */  sw    $ra, 0x10($sp)
/* 102A04 802E1184 0C009C22 */  jal   func_80027088
/* 102A08 802E1188 0000202D */   daddu $a0, $zero, $zero
/* 102A0C 802E118C 0C038069 */  jal   func_800E01A4
/* 102A10 802E1190 00000000 */   nop   
/* 102A14 802E1194 8FBF0010 */  lw    $ra, 0x10($sp)
/* 102A18 802E1198 03E00008 */  jr    $ra
/* 102A1C 802E119C 27BD0018 */   addiu $sp, $sp, 0x18

