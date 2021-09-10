.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel AdjustCam
/* F1010 802CC660 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* F1014 802CC664 AFB10064 */  sw        $s1, 0x64($sp)
/* F1018 802CC668 0080882D */  daddu     $s1, $a0, $zero
/* F101C 802CC66C AFB20068 */  sw        $s2, 0x68($sp)
/* F1020 802CC670 00A0902D */  daddu     $s2, $a1, $zero
/* F1024 802CC674 AFBF0070 */  sw        $ra, 0x70($sp)
/* F1028 802CC678 AFB3006C */  sw        $s3, 0x6c($sp)
/* F102C 802CC67C AFB00060 */  sw        $s0, 0x60($sp)
/* F1030 802CC680 F7BE00A0 */  sdc1      $f30, 0xa0($sp)
/* F1034 802CC684 F7BC0098 */  sdc1      $f28, 0x98($sp)
/* F1038 802CC688 F7BA0090 */  sdc1      $f26, 0x90($sp)
/* F103C 802CC68C F7B80088 */  sdc1      $f24, 0x88($sp)
/* F1040 802CC690 F7B60080 */  sdc1      $f22, 0x80($sp)
/* F1044 802CC694 F7B40078 */  sdc1      $f20, 0x78($sp)
/* F1048 802CC698 8E30000C */  lw        $s0, 0xc($s1)
/* F104C 802CC69C 8E050000 */  lw        $a1, ($s0)
/* F1050 802CC6A0 0C0B1EAF */  jal       evt_get_variable
/* F1054 802CC6A4 26100004 */   addiu    $s0, $s0, 4
/* F1058 802CC6A8 8E050000 */  lw        $a1, ($s0)
/* F105C 802CC6AC 26100004 */  addiu     $s0, $s0, 4
/* F1060 802CC6B0 0220202D */  daddu     $a0, $s1, $zero
/* F1064 802CC6B4 3C06800B */  lui       $a2, %hi(gCameras)
/* F1068 802CC6B8 24C61D80 */  addiu     $a2, $a2, %lo(gCameras)
/* F106C 802CC6BC 00021880 */  sll       $v1, $v0, 2
/* F1070 802CC6C0 00621821 */  addu      $v1, $v1, $v0
/* F1074 802CC6C4 00031880 */  sll       $v1, $v1, 2
/* F1078 802CC6C8 00621823 */  subu      $v1, $v1, $v0
/* F107C 802CC6CC 000310C0 */  sll       $v0, $v1, 3
/* F1080 802CC6D0 00621821 */  addu      $v1, $v1, $v0
/* F1084 802CC6D4 000318C0 */  sll       $v1, $v1, 3
/* F1088 802CC6D8 0C0B210B */  jal       evt_get_float_variable
/* F108C 802CC6DC 00669821 */   addu     $s3, $v1, $a2
/* F1090 802CC6E0 8E050000 */  lw        $a1, ($s0)
/* F1094 802CC6E4 26100004 */  addiu     $s0, $s0, 4
/* F1098 802CC6E8 0220202D */  daddu     $a0, $s1, $zero
/* F109C 802CC6EC 0C0B210B */  jal       evt_get_float_variable
/* F10A0 802CC6F0 E7A00054 */   swc1     $f0, 0x54($sp)
/* F10A4 802CC6F4 8E050000 */  lw        $a1, ($s0)
/* F10A8 802CC6F8 26100004 */  addiu     $s0, $s0, 4
/* F10AC 802CC6FC 0220202D */  daddu     $a0, $s1, $zero
/* F10B0 802CC700 0C0B210B */  jal       evt_get_float_variable
/* F10B4 802CC704 E7A00058 */   swc1     $f0, 0x58($sp)
/* F10B8 802CC708 8E050000 */  lw        $a1, ($s0)
/* F10BC 802CC70C 26100004 */  addiu     $s0, $s0, 4
/* F10C0 802CC710 0220202D */  daddu     $a0, $s1, $zero
/* F10C4 802CC714 0C0B210B */  jal       evt_get_float_variable
/* F10C8 802CC718 46000786 */   mov.s    $f30, $f0
/* F10CC 802CC71C 0220202D */  daddu     $a0, $s1, $zero
/* F10D0 802CC720 8E050000 */  lw        $a1, ($s0)
/* F10D4 802CC724 0C0B210B */  jal       evt_get_float_variable
/* F10D8 802CC728 46000706 */   mov.s    $f28, $f0
/* F10DC 802CC72C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* F10E0 802CC730 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* F10E4 802CC734 1240004E */  beqz      $s2, .L802CC870
/* F10E8 802CC738 46000686 */   mov.s    $f26, $f0
/* F10EC 802CC73C 3C0146FF */  lui       $at, 0x46ff
/* F10F0 802CC740 3421FE00 */  ori       $at, $at, 0xfe00
/* F10F4 802CC744 44811000 */  mtc1      $at, $f2
/* F10F8 802CC748 44802000 */  mtc1      $zero, $f4
/* F10FC 802CC74C 3C01BF80 */  lui       $at, 0xbf80
/* F1100 802CC750 44810000 */  mtc1      $at, $f0
/* F1104 802CC754 3C014120 */  lui       $at, 0x4120
/* F1108 802CC758 44817000 */  mtc1      $at, $f14
/* F110C 802CC75C 27A20038 */  addiu     $v0, $sp, 0x38
/* F1110 802CC760 E7A20044 */  swc1      $f2, 0x44($sp)
/* F1114 802CC764 AFA20018 */  sw        $v0, 0x18($sp)
/* F1118 802CC768 27A2003C */  addiu     $v0, $sp, 0x3c
/* F111C 802CC76C AFA2001C */  sw        $v0, 0x1c($sp)
/* F1120 802CC770 27A20040 */  addiu     $v0, $sp, 0x40
/* F1124 802CC774 AFA20020 */  sw        $v0, 0x20($sp)
/* F1128 802CC778 27A20044 */  addiu     $v0, $sp, 0x44
/* F112C 802CC77C AFA20024 */  sw        $v0, 0x24($sp)
/* F1130 802CC780 27A20048 */  addiu     $v0, $sp, 0x48
/* F1134 802CC784 AFA20028 */  sw        $v0, 0x28($sp)
/* F1138 802CC788 27A2004C */  addiu     $v0, $sp, 0x4c
/* F113C 802CC78C E7A00010 */  swc1      $f0, 0x10($sp)
/* F1140 802CC790 E7A40014 */  swc1      $f4, 0x14($sp)
/* F1144 802CC794 AFA2002C */  sw        $v0, 0x2c($sp)
/* F1148 802CC798 C476002C */  lwc1      $f22, 0x2c($v1)
/* F114C 802CC79C 27A20050 */  addiu     $v0, $sp, 0x50
/* F1150 802CC7A0 AFA20030 */  sw        $v0, 0x30($sp)
/* F1154 802CC7A4 C4740030 */  lwc1      $f20, 0x30($v1)
/* F1158 802CC7A8 C4780028 */  lwc1      $f24, 0x28($v1)
/* F115C 802CC7AC 44072000 */  mfc1      $a3, $f4
/* F1160 802CC7B0 460EB380 */  add.s     $f14, $f22, $f14
/* F1164 802CC7B4 4406A000 */  mfc1      $a2, $f20
/* F1168 802CC7B8 0C017449 */  jal       test_ray_zones
/* F116C 802CC7BC 4600C306 */   mov.s    $f12, $f24
/* F1170 802CC7C0 0040182D */  daddu     $v1, $v0, $zero
/* F1174 802CC7C4 0460001A */  bltz      $v1, .L802CC830
/* F1178 802CC7C8 000310C0 */   sll      $v0, $v1, 3
/* F117C 802CC7CC 00431023 */  subu      $v0, $v0, $v1
/* F1180 802CC7D0 3C03800E */  lui       $v1, %hi(D_800D91D4)
/* F1184 802CC7D4 8C6391D4 */  lw        $v1, %lo(D_800D91D4)($v1)
/* F1188 802CC7D8 00021080 */  sll       $v0, $v0, 2
/* F118C 802CC7DC 00431021 */  addu      $v0, $v0, $v1
/* F1190 802CC7E0 8C420010 */  lw        $v0, 0x10($v0)
/* F1194 802CC7E4 266304D8 */  addiu     $v1, $s3, 0x4d8
/* F1198 802CC7E8 24440020 */  addiu     $a0, $v0, 0x20
.L802CC7EC:
/* F119C 802CC7EC 8C480000 */  lw        $t0, ($v0)
/* F11A0 802CC7F0 8C490004 */  lw        $t1, 4($v0)
/* F11A4 802CC7F4 8C4A0008 */  lw        $t2, 8($v0)
/* F11A8 802CC7F8 8C4B000C */  lw        $t3, 0xc($v0)
/* F11AC 802CC7FC AC680000 */  sw        $t0, ($v1)
/* F11B0 802CC800 AC690004 */  sw        $t1, 4($v1)
/* F11B4 802CC804 AC6A0008 */  sw        $t2, 8($v1)
/* F11B8 802CC808 AC6B000C */  sw        $t3, 0xc($v1)
/* F11BC 802CC80C 24420010 */  addiu     $v0, $v0, 0x10
/* F11C0 802CC810 1444FFF6 */  bne       $v0, $a0, .L802CC7EC
/* F11C4 802CC814 24630010 */   addiu    $v1, $v1, 0x10
/* F11C8 802CC818 8C480000 */  lw        $t0, ($v0)
/* F11CC 802CC81C 8C490004 */  lw        $t1, 4($v0)
/* F11D0 802CC820 8C4A0008 */  lw        $t2, 8($v0)
/* F11D4 802CC824 AC680000 */  sw        $t0, ($v1)
/* F11D8 802CC828 AC690004 */  sw        $t1, 4($v1)
/* F11DC 802CC82C AC6A0008 */  sw        $t2, 8($v1)
.L802CC830:
/* F11E0 802CC830 E67604B4 */  swc1      $f22, 0x4b4($s3)
/* F11E4 802CC834 E67404B8 */  swc1      $f20, 0x4b8($s3)
/* F11E8 802CC838 E67E04DC */  swc1      $f30, 0x4dc($s3)
/* F11EC 802CC83C E67C04E0 */  swc1      $f28, 0x4e0($s3)
/* F11F0 802CC840 E67A04FC */  swc1      $f26, 0x4fc($s3)
/* F11F4 802CC844 C7A60054 */  lwc1      $f6, 0x54($sp)
/* F11F8 802CC848 24030001 */  addiu     $v1, $zero, 1
/* F11FC 802CC84C E6660490 */  swc1      $f6, 0x490($s3)
/* F1200 802CC850 A6630506 */  sh        $v1, 0x506($s3)
/* F1204 802CC854 C7A60058 */  lwc1      $f6, 0x58($sp)
/* F1208 802CC858 0000102D */  daddu     $v0, $zero, $zero
/* F120C 802CC85C 4606C000 */  add.s     $f0, $f24, $f6
/* F1210 802CC860 A6630504 */  sh        $v1, 0x504($s3)
/* F1214 802CC864 AE600508 */  sw        $zero, 0x508($s3)
/* F1218 802CC868 080B3225 */  j         .L802CC894
/* F121C 802CC86C E66004B0 */   swc1     $f0, 0x4b0($s3)
.L802CC870:
/* F1220 802CC870 C6620484 */  lwc1      $f2, 0x484($s3)
/* F1224 802CC874 3C013F80 */  lui       $at, 0x3f80
/* F1228 802CC878 44810000 */  mtc1      $at, $f0
/* F122C 802CC87C 00000000 */  nop
/* F1230 802CC880 4602003E */  c.le.s    $f0, $f2
/* F1234 802CC884 00000000 */  nop
/* F1238 802CC888 45010002 */  bc1t      .L802CC894
/* F123C 802CC88C 24020002 */   addiu    $v0, $zero, 2
/* F1240 802CC890 0000102D */  daddu     $v0, $zero, $zero
.L802CC894:
/* F1244 802CC894 8FBF0070 */  lw        $ra, 0x70($sp)
/* F1248 802CC898 8FB3006C */  lw        $s3, 0x6c($sp)
/* F124C 802CC89C 8FB20068 */  lw        $s2, 0x68($sp)
/* F1250 802CC8A0 8FB10064 */  lw        $s1, 0x64($sp)
/* F1254 802CC8A4 8FB00060 */  lw        $s0, 0x60($sp)
/* F1258 802CC8A8 D7BE00A0 */  ldc1      $f30, 0xa0($sp)
/* F125C 802CC8AC D7BC0098 */  ldc1      $f28, 0x98($sp)
/* F1260 802CC8B0 D7BA0090 */  ldc1      $f26, 0x90($sp)
/* F1264 802CC8B4 D7B80088 */  ldc1      $f24, 0x88($sp)
/* F1268 802CC8B8 D7B60080 */  ldc1      $f22, 0x80($sp)
/* F126C 802CC8BC D7B40078 */  ldc1      $f20, 0x78($sp)
/* F1270 802CC8C0 03E00008 */  jr        $ra
/* F1274 802CC8C4 27BD00A8 */   addiu    $sp, $sp, 0xa8
