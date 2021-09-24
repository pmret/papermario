.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80247B58_EE6518
.word L80242ABC_EE147C, L80242AC8_EE1488, L80242AC8_EE1488, L80242AC8_EE1488, L80242AC8_EE1488, L80242AC8_EE1488, L80242AC8_EE1488, L80242AC8_EE1488, L80242ABC_EE147C, L80242AC8_EE1488, L80242ABC_EE147C, L80242AC8_EE1488, L80242ABC_EE147C, L80242AC8_EE1488, L80242ABC_EE147C, L80242AC8_EE1488, L80242AC8_EE1488, L80242AC8_EE1488, L80242ABC_EE147C, L80242AC8_EE1488, L80242ABC_EE147C, 0

.section .text

glabel func_80242684_EE1044
/* EE1044 80242684 27BDFF90 */  addiu     $sp, $sp, -0x70
/* EE1048 80242688 AFB3005C */  sw        $s3, 0x5c($sp)
/* EE104C 8024268C 0080982D */  daddu     $s3, $a0, $zero
/* EE1050 80242690 AFBF0068 */  sw        $ra, 0x68($sp)
/* EE1054 80242694 AFB50064 */  sw        $s5, 0x64($sp)
/* EE1058 80242698 AFB40060 */  sw        $s4, 0x60($sp)
/* EE105C 8024269C AFB20058 */  sw        $s2, 0x58($sp)
/* EE1060 802426A0 AFB10054 */  sw        $s1, 0x54($sp)
/* EE1064 802426A4 AFB00050 */  sw        $s0, 0x50($sp)
/* EE1068 802426A8 8E710148 */  lw        $s1, 0x148($s3)
/* EE106C 802426AC 86240008 */  lh        $a0, 8($s1)
/* EE1070 802426B0 0C00F92F */  jal       dead_get_npc_unsafe
/* EE1074 802426B4 00A0802D */   daddu    $s0, $a1, $zero
/* EE1078 802426B8 8E63000C */  lw        $v1, 0xc($s3)
/* EE107C 802426BC 0260202D */  daddu     $a0, $s3, $zero
/* EE1080 802426C0 8C650000 */  lw        $a1, ($v1)
/* EE1084 802426C4 0C0B53A3 */  jal       dead_evt_get_variable
/* EE1088 802426C8 0040902D */   daddu    $s2, $v0, $zero
/* EE108C 802426CC AFA00028 */  sw        $zero, 0x28($sp)
/* EE1090 802426D0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EE1094 802426D4 8C630030 */  lw        $v1, 0x30($v1)
/* EE1098 802426D8 AFA3002C */  sw        $v1, 0x2c($sp)
/* EE109C 802426DC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EE10A0 802426E0 8C63001C */  lw        $v1, 0x1c($v1)
/* EE10A4 802426E4 AFA30030 */  sw        $v1, 0x30($sp)
/* EE10A8 802426E8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EE10AC 802426EC 8C630024 */  lw        $v1, 0x24($v1)
/* EE10B0 802426F0 AFA30034 */  sw        $v1, 0x34($sp)
/* EE10B4 802426F4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EE10B8 802426F8 8C630028 */  lw        $v1, 0x28($v1)
/* EE10BC 802426FC AFA30038 */  sw        $v1, 0x38($sp)
/* EE10C0 80242700 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EE10C4 80242704 3C0142C8 */  lui       $at, 0x42c8
/* EE10C8 80242708 44810000 */  mtc1      $at, $f0
/* EE10CC 8024270C 8C63002C */  lw        $v1, 0x2c($v1)
/* EE10D0 80242710 E7A00040 */  swc1      $f0, 0x40($sp)
/* EE10D4 80242714 A7A00044 */  sh        $zero, 0x44($sp)
/* EE10D8 80242718 AFA3003C */  sw        $v1, 0x3c($sp)
/* EE10DC 8024271C C6400038 */  lwc1      $f0, 0x38($s2)
/* EE10E0 80242720 E6200108 */  swc1      $f0, 0x108($s1)
/* EE10E4 80242724 C640003C */  lwc1      $f0, 0x3c($s2)
/* EE10E8 80242728 27B50028 */  addiu     $s5, $sp, 0x28
/* EE10EC 8024272C E620010C */  swc1      $f0, 0x10c($s1)
/* EE10F0 80242730 3C013C23 */  lui       $at, 0x3c23
/* EE10F4 80242734 3421D70A */  ori       $at, $at, 0xd70a
/* EE10F8 80242738 44810000 */  mtc1      $at, $f0
/* EE10FC 8024273C C6420040 */  lwc1      $f2, 0x40($s2)
/* EE1100 80242740 0040A02D */  daddu     $s4, $v0, $zero
/* EE1104 80242744 E6200114 */  swc1      $f0, 0x114($s1)
/* EE1108 80242748 E6200118 */  swc1      $f0, 0x118($s1)
/* EE110C 8024274C 12000009 */  beqz      $s0, .L80242774
/* EE1110 80242750 E6220110 */   swc1     $f2, 0x110($s1)
/* EE1114 80242754 864300A8 */  lh        $v1, 0xa8($s2)
/* EE1118 80242758 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EE111C 8024275C AE20008C */  sw        $zero, 0x8c($s1)
/* EE1120 80242760 A22000B5 */  sb        $zero, 0xb5($s1)
/* EE1124 80242764 34420008 */  ori       $v0, $v0, 8
/* EE1128 80242768 AE230084 */  sw        $v1, 0x84($s1)
/* EE112C 8024276C 080909E1 */  j         .L80242784
/* EE1130 80242770 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80242774:
/* EE1134 80242774 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EE1138 80242778 30420004 */  andi      $v0, $v0, 4
/* EE113C 8024277C 10400047 */  beqz      $v0, .L8024289C
/* EE1140 80242780 00000000 */   nop
.L80242784:
/* EE1144 80242784 AE600070 */  sw        $zero, 0x70($s3)
/* EE1148 80242788 A640008E */  sh        $zero, 0x8e($s2)
/* EE114C 8024278C 8E2300CC */  lw        $v1, 0xcc($s1)
/* EE1150 80242790 2404F7FF */  addiu     $a0, $zero, -0x801
/* EE1154 80242794 A2200007 */  sb        $zero, 7($s1)
/* EE1158 80242798 8E420000 */  lw        $v0, ($s2)
/* EE115C 8024279C 8C630000 */  lw        $v1, ($v1)
/* EE1160 802427A0 00441024 */  and       $v0, $v0, $a0
/* EE1164 802427A4 AE420000 */  sw        $v0, ($s2)
/* EE1168 802427A8 AE430028 */  sw        $v1, 0x28($s2)
/* EE116C 802427AC 96220086 */  lhu       $v0, 0x86($s1)
/* EE1170 802427B0 A64200A8 */  sh        $v0, 0xa8($s2)
/* EE1174 802427B4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EE1178 802427B8 AE200090 */  sw        $zero, 0x90($s1)
/* EE117C 802427BC 8C420034 */  lw        $v0, 0x34($v0)
/* EE1180 802427C0 14400006 */  bnez      $v0, .L802427DC
/* EE1184 802427C4 2403FDFF */   addiu    $v1, $zero, -0x201
/* EE1188 802427C8 8E420000 */  lw        $v0, ($s2)
/* EE118C 802427CC 2403FFF7 */  addiu     $v1, $zero, -9
/* EE1190 802427D0 34420200 */  ori       $v0, $v0, 0x200
/* EE1194 802427D4 080909FA */  j         .L802427E8
/* EE1198 802427D8 00431024 */   and      $v0, $v0, $v1
.L802427DC:
/* EE119C 802427DC 8E420000 */  lw        $v0, ($s2)
/* EE11A0 802427E0 00431024 */  and       $v0, $v0, $v1
/* EE11A4 802427E4 34420008 */  ori       $v0, $v0, 8
.L802427E8:
/* EE11A8 802427E8 AE420000 */  sw        $v0, ($s2)
/* EE11AC 802427EC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EE11B0 802427F0 30420004 */  andi      $v0, $v0, 4
/* EE11B4 802427F4 1040001E */  beqz      $v0, .L80242870
/* EE11B8 802427F8 24040002 */   addiu    $a0, $zero, 2
/* EE11BC 802427FC 0240282D */  daddu     $a1, $s2, $zero
/* EE11C0 80242800 0000302D */  daddu     $a2, $zero, $zero
/* EE11C4 80242804 24020063 */  addiu     $v0, $zero, 0x63
/* EE11C8 80242808 AE620070 */  sw        $v0, 0x70($s3)
/* EE11CC 8024280C AE600074 */  sw        $zero, 0x74($s3)
/* EE11D0 80242810 864300A8 */  lh        $v1, 0xa8($s2)
/* EE11D4 80242814 3C013F80 */  lui       $at, 0x3f80
/* EE11D8 80242818 44810000 */  mtc1      $at, $f0
/* EE11DC 8024281C 3C014000 */  lui       $at, 0x4000
/* EE11E0 80242820 44811000 */  mtc1      $at, $f2
/* EE11E4 80242824 3C01C1A0 */  lui       $at, 0xc1a0
/* EE11E8 80242828 44812000 */  mtc1      $at, $f4
/* EE11EC 8024282C 24020028 */  addiu     $v0, $zero, 0x28
/* EE11F0 80242830 AFA2001C */  sw        $v0, 0x1c($sp)
/* EE11F4 80242834 44833000 */  mtc1      $v1, $f6
/* EE11F8 80242838 00000000 */  nop
/* EE11FC 8024283C 468031A0 */  cvt.s.w   $f6, $f6
/* EE1200 80242840 44073000 */  mfc1      $a3, $f6
/* EE1204 80242844 27A20048 */  addiu     $v0, $sp, 0x48
/* EE1208 80242848 AFA20020 */  sw        $v0, 0x20($sp)
/* EE120C 8024284C E7A00010 */  swc1      $f0, 0x10($sp)
/* EE1210 80242850 E7A20014 */  swc1      $f2, 0x14($sp)
/* EE1214 80242854 0C01D444 */  jal       dead_fx_emote
/* EE1218 80242858 E7A40018 */   swc1     $f4, 0x18($sp)
/* EE121C 8024285C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EE1220 80242860 2403FFFB */  addiu     $v1, $zero, -5
/* EE1224 80242864 00431024 */  and       $v0, $v0, $v1
/* EE1228 80242868 08090A27 */  j         .L8024289C
/* EE122C 8024286C AE2200B0 */   sw       $v0, 0xb0($s1)
.L80242870:
/* EE1230 80242870 8E220000 */  lw        $v0, ($s1)
/* EE1234 80242874 3C034000 */  lui       $v1, 0x4000
/* EE1238 80242878 00431024 */  and       $v0, $v0, $v1
/* EE123C 8024287C 10400007 */  beqz      $v0, .L8024289C
/* EE1240 80242880 3C03BFFF */   lui      $v1, 0xbfff
/* EE1244 80242884 2402000C */  addiu     $v0, $zero, 0xc
/* EE1248 80242888 AE620070 */  sw        $v0, 0x70($s3)
/* EE124C 8024288C 8E220000 */  lw        $v0, ($s1)
/* EE1250 80242890 3463FFFF */  ori       $v1, $v1, 0xffff
/* EE1254 80242894 00431024 */  and       $v0, $v0, $v1
/* EE1258 80242898 AE220000 */  sw        $v0, ($s1)
.L8024289C:
/* EE125C 8024289C 8E220090 */  lw        $v0, 0x90($s1)
/* EE1260 802428A0 1840000C */  blez      $v0, .L802428D4
/* EE1264 802428A4 2442FFFF */   addiu    $v0, $v0, -1
/* EE1268 802428A8 14400087 */  bnez      $v0, L80242AC8_EE1488
/* EE126C 802428AC AE220090 */   sw       $v0, 0x90($s1)
/* EE1270 802428B0 3C03FFAA */  lui       $v1, 0xffaa
/* EE1274 802428B4 8E420028 */  lw        $v0, 0x28($s2)
/* EE1278 802428B8 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* EE127C 802428BC 00431021 */  addu      $v0, $v0, $v1
/* EE1280 802428C0 2C420002 */  sltiu     $v0, $v0, 2
/* EE1284 802428C4 10400003 */  beqz      $v0, .L802428D4
/* EE1288 802428C8 3C020055 */   lui      $v0, 0x55
/* EE128C 802428CC 3442000C */  ori       $v0, $v0, 0xc
/* EE1290 802428D0 AE420028 */  sw        $v0, 0x28($s2)
.L802428D4:
/* EE1294 802428D4 8E630070 */  lw        $v1, 0x70($s3)
/* EE1298 802428D8 2402000C */  addiu     $v0, $zero, 0xc
/* EE129C 802428DC 10620048 */  beq       $v1, $v0, .L80242A00
/* EE12A0 802428E0 2862000D */   slti     $v0, $v1, 0xd
/* EE12A4 802428E4 1040000F */  beqz      $v0, .L80242924
/* EE12A8 802428E8 24100001 */   addiu    $s0, $zero, 1
/* EE12AC 802428EC 1070001E */  beq       $v1, $s0, .L80242968
/* EE12B0 802428F0 28620002 */   slti     $v0, $v1, 2
/* EE12B4 802428F4 10400005 */  beqz      $v0, .L8024290C
/* EE12B8 802428F8 24020002 */   addiu    $v0, $zero, 2
/* EE12BC 802428FC 10600015 */  beqz      $v1, .L80242954
/* EE12C0 80242900 0260202D */   daddu    $a0, $s3, $zero
/* EE12C4 80242904 08090A97 */  j         .L80242A5C
/* EE12C8 80242908 00000000 */   nop
.L8024290C:
/* EE12CC 8024290C 1062001C */  beq       $v1, $v0, .L80242980
/* EE12D0 80242910 24020003 */   addiu    $v0, $zero, 3
/* EE12D4 80242914 10620035 */  beq       $v1, $v0, .L802429EC
/* EE12D8 80242918 0260202D */   daddu    $a0, $s3, $zero
/* EE12DC 8024291C 08090A97 */  j         .L80242A5C
/* EE12E0 80242920 00000000 */   nop
.L80242924:
/* EE12E4 80242924 2402000E */  addiu     $v0, $zero, 0xe
/* EE12E8 80242928 1062003F */  beq       $v1, $v0, .L80242A28
/* EE12EC 8024292C 0062102A */   slt      $v0, $v1, $v0
/* EE12F0 80242930 14400038 */  bnez      $v0, .L80242A14
/* EE12F4 80242934 0260202D */   daddu    $a0, $s3, $zero
/* EE12F8 80242938 2402000F */  addiu     $v0, $zero, 0xf
/* EE12FC 8024293C 10620040 */  beq       $v1, $v0, .L80242A40
/* EE1300 80242940 24020063 */   addiu    $v0, $zero, 0x63
/* EE1304 80242944 10620043 */  beq       $v1, $v0, .L80242A54
/* EE1308 80242948 00000000 */   nop
/* EE130C 8024294C 08090A97 */  j         .L80242A5C
/* EE1310 80242950 00000000 */   nop
.L80242954:
/* EE1314 80242954 0280282D */  daddu     $a1, $s4, $zero
/* EE1318 80242958 0C013670 */  jal       func_8004D9C0
/* EE131C 8024295C 02A0302D */   daddu    $a2, $s5, $zero
/* EE1320 80242960 96220086 */  lhu       $v0, 0x86($s1)
/* EE1324 80242964 A64200A8 */  sh        $v0, 0xa8($s2)
.L80242968:
/* EE1328 80242968 0260202D */  daddu     $a0, $s3, $zero
/* EE132C 8024296C 0280282D */  daddu     $a1, $s4, $zero
/* EE1330 80242970 0C0136B6 */  jal       func_8004DAD8
/* EE1334 80242974 02A0302D */   daddu    $a2, $s5, $zero
/* EE1338 80242978 08090A97 */  j         .L80242A5C
/* EE133C 8024297C 00000000 */   nop
.L80242980:
/* EE1340 80242980 0260202D */  daddu     $a0, $s3, $zero
/* EE1344 80242984 0280282D */  daddu     $a1, $s4, $zero
/* EE1348 80242988 0C0137D9 */  jal       func_8004DF64
/* EE134C 8024298C 02A0302D */   daddu    $a2, $s5, $zero
/* EE1350 80242990 8E230088 */  lw        $v1, 0x88($s1)
/* EE1354 80242994 24020006 */  addiu     $v0, $zero, 6
/* EE1358 80242998 14620014 */  bne       $v1, $v0, .L802429EC
/* EE135C 8024299C 0260202D */   daddu    $a0, $s3, $zero
/* EE1360 802429A0 0C00AB3B */  jal       dead_rand_int
/* EE1364 802429A4 24040064 */   addiu    $a0, $zero, 0x64
/* EE1368 802429A8 28420021 */  slti      $v0, $v0, 0x21
/* EE136C 802429AC 5040000F */  beql      $v0, $zero, .L802429EC
/* EE1370 802429B0 0260202D */   daddu    $a0, $s3, $zero
/* EE1374 802429B4 8E22008C */  lw        $v0, 0x8c($s1)
/* EE1378 802429B8 10400005 */  beqz      $v0, .L802429D0
/* EE137C 802429BC 3C020055 */   lui      $v0, 0x55
/* EE1380 802429C0 3442002F */  ori       $v0, $v0, 0x2f
/* EE1384 802429C4 AE20008C */  sw        $zero, 0x8c($s1)
/* EE1388 802429C8 08090A77 */  j         .L802429DC
/* EE138C 802429CC A22000B5 */   sb       $zero, 0xb5($s1)
.L802429D0:
/* EE1390 802429D0 3442002E */  ori       $v0, $v0, 0x2e
/* EE1394 802429D4 AE30008C */  sw        $s0, 0x8c($s1)
/* EE1398 802429D8 A23000B5 */  sb        $s0, 0xb5($s1)
.L802429DC:
/* EE139C 802429DC AE420028 */  sw        $v0, 0x28($s2)
/* EE13A0 802429E0 24020007 */  addiu     $v0, $zero, 7
/* EE13A4 802429E4 08090AB2 */  j         L80242AC8_EE1488
/* EE13A8 802429E8 AE220090 */   sw       $v0, 0x90($s1)
.L802429EC:
/* EE13AC 802429EC 0280282D */  daddu     $a1, $s4, $zero
/* EE13B0 802429F0 0C013809 */  jal       func_8004E024
/* EE13B4 802429F4 02A0302D */   daddu    $a2, $s5, $zero
/* EE13B8 802429F8 08090A97 */  j         .L80242A5C
/* EE13BC 802429FC 00000000 */   nop
.L80242A00:
/* EE13C0 80242A00 0260202D */  daddu     $a0, $s3, $zero
/* EE13C4 80242A04 0280282D */  daddu     $a1, $s4, $zero
/* EE13C8 80242A08 0C0908BC */  jal       EDEA00_set_script_owner_npc_anim
/* EE13CC 80242A0C 02A0302D */   daddu    $a2, $s5, $zero
/* EE13D0 80242A10 0260202D */  daddu     $a0, $s3, $zero
.L80242A14:
/* EE13D4 80242A14 0280282D */  daddu     $a1, $s4, $zero
/* EE13D8 80242A18 0C0908DB */  jal       EDEA00_UnkDistFunc
/* EE13DC 80242A1C 02A0302D */   daddu    $a2, $s5, $zero
/* EE13E0 80242A20 08090A97 */  j         .L80242A5C
/* EE13E4 80242A24 00000000 */   nop
.L80242A28:
/* EE13E8 80242A28 0260202D */  daddu     $a0, $s3, $zero
/* EE13EC 80242A2C 0280282D */  daddu     $a1, $s4, $zero
/* EE13F0 80242A30 0C090928 */  jal       EDEA00_UnkNpcAIFunc12
/* EE13F4 80242A34 02A0302D */   daddu    $a2, $s5, $zero
/* EE13F8 80242A38 08090A97 */  j         .L80242A5C
/* EE13FC 80242A3C 00000000 */   nop
.L80242A40:
/* EE1400 80242A40 0280282D */  daddu     $a1, $s4, $zero
/* EE1404 80242A44 0C090981 */  jal       EDEA00_set_script_owner_npc_col_height
/* EE1408 80242A48 02A0302D */   daddu    $a2, $s5, $zero
/* EE140C 80242A4C 08090A97 */  j         .L80242A5C
/* EE1410 80242A50 00000000 */   nop
.L80242A54:
/* EE1414 80242A54 0C013AE3 */  jal       func_8004EB8C
/* EE1418 80242A58 0260202D */   daddu    $a0, $s3, $zero
.L80242A5C:
/* EE141C 80242A5C 8E230088 */  lw        $v1, 0x88($s1)
/* EE1420 80242A60 24020006 */  addiu     $v0, $zero, 6
/* EE1424 80242A64 14620019 */  bne       $v1, $v0, .L80242ACC
/* EE1428 80242A68 0000102D */   daddu    $v0, $zero, $zero
/* EE142C 80242A6C 8E22008C */  lw        $v0, 0x8c($s1)
/* EE1430 80242A70 10400003 */  beqz      $v0, .L80242A80
/* EE1434 80242A74 24020001 */   addiu    $v0, $zero, 1
/* EE1438 80242A78 08090AA1 */  j         .L80242A84
/* EE143C 80242A7C A22200B5 */   sb       $v0, 0xb5($s1)
.L80242A80:
/* EE1440 80242A80 A22000B5 */  sb        $zero, 0xb5($s1)
.L80242A84:
/* EE1444 80242A84 8E22008C */  lw        $v0, 0x8c($s1)
/* EE1448 80242A88 1040000F */  beqz      $v0, L80242AC8_EE1488
/* EE144C 80242A8C 3C03FFAA */   lui      $v1, 0xffaa
/* EE1450 80242A90 8E420028 */  lw        $v0, 0x28($s2)
/* EE1454 80242A94 3463FFFC */  ori       $v1, $v1, 0xfffc
/* EE1458 80242A98 00431821 */  addu      $v1, $v0, $v1
/* EE145C 80242A9C 2C620015 */  sltiu     $v0, $v1, 0x15
/* EE1460 80242AA0 10400009 */  beqz      $v0, L80242AC8_EE1488
/* EE1464 80242AA4 00031080 */   sll      $v0, $v1, 2
/* EE1468 80242AA8 3C018024 */  lui       $at, %hi(jtbl_80247B58_EE6518)
/* EE146C 80242AAC 00220821 */  addu      $at, $at, $v0
/* EE1470 80242AB0 8C227B58 */  lw        $v0, %lo(jtbl_80247B58_EE6518)($at)
/* EE1474 80242AB4 00400008 */  jr        $v0
/* EE1478 80242AB8 00000000 */   nop
glabel L80242ABC_EE147C
/* EE147C 80242ABC 8E420028 */  lw        $v0, 0x28($s2)
/* EE1480 80242AC0 24420001 */  addiu     $v0, $v0, 1
/* EE1484 80242AC4 AE420028 */  sw        $v0, 0x28($s2)
glabel L80242AC8_EE1488
/* EE1488 80242AC8 0000102D */  daddu     $v0, $zero, $zero
.L80242ACC:
/* EE148C 80242ACC 8FBF0068 */  lw        $ra, 0x68($sp)
/* EE1490 80242AD0 8FB50064 */  lw        $s5, 0x64($sp)
/* EE1494 80242AD4 8FB40060 */  lw        $s4, 0x60($sp)
/* EE1498 80242AD8 8FB3005C */  lw        $s3, 0x5c($sp)
/* EE149C 80242ADC 8FB20058 */  lw        $s2, 0x58($sp)
/* EE14A0 80242AE0 8FB10054 */  lw        $s1, 0x54($sp)
/* EE14A4 80242AE4 8FB00050 */  lw        $s0, 0x50($sp)
/* EE14A8 80242AE8 03E00008 */  jr        $ra
/* EE14AC 80242AEC 27BD0070 */   addiu    $sp, $sp, 0x70
