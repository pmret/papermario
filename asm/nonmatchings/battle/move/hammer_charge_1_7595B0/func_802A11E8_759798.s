.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A11E8_759798
/* 759798 802A11E8 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 75979C 802A11EC AFB20020 */  sw        $s2, 0x20($sp)
/* 7597A0 802A11F0 0080902D */  daddu     $s2, $a0, $zero
/* 7597A4 802A11F4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 7597A8 802A11F8 AFB30024 */  sw        $s3, 0x24($sp)
/* 7597AC 802A11FC AFB1001C */  sw        $s1, 0x1c($sp)
/* 7597B0 802A1200 AFB00018 */  sw        $s0, 0x18($sp)
/* 7597B4 802A1204 F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 7597B8 802A1208 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 7597BC 802A120C F7B60038 */  sdc1      $f22, 0x38($sp)
/* 7597C0 802A1210 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 7597C4 802A1214 8E50000C */  lw        $s0, 0xc($s2)
/* 7597C8 802A1218 8E050000 */  lw        $a1, ($s0)
/* 7597CC 802A121C 0C0B1EAF */  jal       get_variable
/* 7597D0 802A1220 26100004 */   addiu    $s0, $s0, 4
/* 7597D4 802A1224 8E050000 */  lw        $a1, ($s0)
/* 7597D8 802A1228 26100004 */  addiu     $s0, $s0, 4
/* 7597DC 802A122C 0240202D */  daddu     $a0, $s2, $zero
/* 7597E0 802A1230 0C0B1EAF */  jal       get_variable
/* 7597E4 802A1234 0040982D */   daddu    $s3, $v0, $zero
/* 7597E8 802A1238 8E050000 */  lw        $a1, ($s0)
/* 7597EC 802A123C 26100004 */  addiu     $s0, $s0, 4
/* 7597F0 802A1240 0240202D */  daddu     $a0, $s2, $zero
/* 7597F4 802A1244 0C0B1EAF */  jal       get_variable
/* 7597F8 802A1248 0040882D */   daddu    $s1, $v0, $zero
/* 7597FC 802A124C 0240202D */  daddu     $a0, $s2, $zero
/* 759800 802A1250 8E050000 */  lw        $a1, ($s0)
/* 759804 802A1254 0C0B210B */  jal       get_float_variable
/* 759808 802A1258 0040802D */   daddu    $s0, $v0, $zero
/* 75980C 802A125C 24040006 */  addiu     $a0, $zero, 6
/* 759810 802A1260 2673000A */  addiu     $s3, $s3, 0xa
/* 759814 802A1264 4493D000 */  mtc1      $s3, $f26
/* 759818 802A1268 00000000 */  nop
/* 75981C 802A126C 4680D6A0 */  cvt.s.w   $f26, $f26
/* 759820 802A1270 26310012 */  addiu     $s1, $s1, 0x12
/* 759824 802A1274 4491C000 */  mtc1      $s1, $f24
/* 759828 802A1278 00000000 */  nop
/* 75982C 802A127C 4680C620 */  cvt.s.w   $f24, $f24
/* 759830 802A1280 4490A000 */  mtc1      $s0, $f20
/* 759834 802A1284 00000000 */  nop
/* 759838 802A1288 4680A520 */  cvt.s.w   $f20, $f20
/* 75983C 802A128C 46000586 */  mov.s     $f22, $f0
/* 759840 802A1290 4405D000 */  mfc1      $a1, $f26
/* 759844 802A1294 4406C000 */  mfc1      $a2, $f24
/* 759848 802A1298 4407A000 */  mfc1      $a3, $f20
/* 75984C 802A129C 2402002D */  addiu     $v0, $zero, 0x2d
/* 759850 802A12A0 E7B60010 */  swc1      $f22, 0x10($sp)
/* 759854 802A12A4 0C01C82C */  jal       func_800720B0
/* 759858 802A12A8 AFA20014 */   sw       $v0, 0x14($sp)
/* 75985C 802A12AC 2404000C */  addiu     $a0, $zero, 0xc
/* 759860 802A12B0 4405D000 */  mfc1      $a1, $f26
/* 759864 802A12B4 4406C000 */  mfc1      $a2, $f24
/* 759868 802A12B8 4407A000 */  mfc1      $a3, $f20
/* 75986C 802A12BC 2402001E */  addiu     $v0, $zero, 0x1e
/* 759870 802A12C0 E7B60010 */  swc1      $f22, 0x10($sp)
/* 759874 802A12C4 0C01C2EC */  jal       func_80070BB0
/* 759878 802A12C8 AFA20014 */   sw       $v0, 0x14($sp)
/* 75987C 802A12CC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 759880 802A12D0 8FB30024 */  lw        $s3, 0x24($sp)
/* 759884 802A12D4 8FB20020 */  lw        $s2, 0x20($sp)
/* 759888 802A12D8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 75988C 802A12DC 8FB00018 */  lw        $s0, 0x18($sp)
/* 759890 802A12E0 D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 759894 802A12E4 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 759898 802A12E8 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 75989C 802A12EC D7B40030 */  ldc1      $f20, 0x30($sp)
/* 7598A0 802A12F0 24020002 */  addiu     $v0, $zero, 2
/* 7598A4 802A12F4 03E00008 */  jr        $ra
/* 7598A8 802A12F8 27BD0050 */   addiu    $sp, $sp, 0x50
