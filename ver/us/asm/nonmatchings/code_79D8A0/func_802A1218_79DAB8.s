.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1218_79DAB8
/* 79DAB8 802A1218 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 79DABC 802A121C AFB1002C */  sw        $s1, 0x2c($sp)
/* 79DAC0 802A1220 0080882D */  daddu     $s1, $a0, $zero
/* 79DAC4 802A1224 AFBF0034 */  sw        $ra, 0x34($sp)
/* 79DAC8 802A1228 AFB20030 */  sw        $s2, 0x30($sp)
/* 79DACC 802A122C AFB00028 */  sw        $s0, 0x28($sp)
/* 79DAD0 802A1230 8E30000C */  lw        $s0, 0xc($s1)
/* 79DAD4 802A1234 8E050000 */  lw        $a1, ($s0)
/* 79DAD8 802A1238 0C0B1EAF */  jal       func_802C7ABC_7C435C
/* 79DADC 802A123C 26100004 */   addiu    $s0, $s0, 4
/* 79DAE0 802A1240 8E050000 */  lw        $a1, ($s0)
/* 79DAE4 802A1244 26100004 */  addiu     $s0, $s0, 4
/* 79DAE8 802A1248 0220202D */  daddu     $a0, $s1, $zero
/* 79DAEC 802A124C 0C0B1EAF */  jal       func_802C7ABC_7C435C
/* 79DAF0 802A1250 0040902D */   daddu    $s2, $v0, $zero
/* 79DAF4 802A1254 0220202D */  daddu     $a0, $s1, $zero
/* 79DAF8 802A1258 8E050000 */  lw        $a1, ($s0)
/* 79DAFC 802A125C 0C0B1EAF */  jal       func_802C7ABC_7C435C
/* 79DB00 802A1260 0040802D */   daddu    $s0, $v0, $zero
/* 79DB04 802A1264 24040004 */  addiu     $a0, $zero, 4
/* 79DB08 802A1268 44922000 */  mtc1      $s2, $f4
/* 79DB0C 802A126C 00000000 */  nop
/* 79DB10 802A1270 46802120 */  cvt.s.w   $f4, $f4
/* 79DB14 802A1274 44052000 */  mfc1      $a1, $f4
/* 79DB18 802A1278 44902000 */  mtc1      $s0, $f4
/* 79DB1C 802A127C 00000000 */  nop
/* 79DB20 802A1280 46802120 */  cvt.s.w   $f4, $f4
/* 79DB24 802A1284 44062000 */  mfc1      $a2, $f4
/* 79DB28 802A1288 44822000 */  mtc1      $v0, $f4
/* 79DB2C 802A128C 00000000 */  nop
/* 79DB30 802A1290 46802120 */  cvt.s.w   $f4, $f4
/* 79DB34 802A1294 3C0141A0 */  lui       $at, 0x41a0
/* 79DB38 802A1298 44810000 */  mtc1      $at, $f0
/* 79DB3C 802A129C 3C013F80 */  lui       $at, 0x3f80
/* 79DB40 802A12A0 44811000 */  mtc1      $at, $f2
/* 79DB44 802A12A4 44072000 */  mfc1      $a3, $f4
/* 79DB48 802A12A8 2403000A */  addiu     $v1, $zero, 0xa
/* 79DB4C 802A12AC AFA3001C */  sw        $v1, 0x1c($sp)
/* 79DB50 802A12B0 2403000F */  addiu     $v1, $zero, 0xf
/* 79DB54 802A12B4 AFA30020 */  sw        $v1, 0x20($sp)
/* 79DB58 802A12B8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 79DB5C 802A12BC E7A00014 */  swc1      $f0, 0x14($sp)
/* 79DB60 802A12C0 0C01C8D4 */  jal       func_80072350
/* 79DB64 802A12C4 E7A20018 */   swc1     $f2, 0x18($sp)
/* 79DB68 802A12C8 8FBF0034 */  lw        $ra, 0x34($sp)
/* 79DB6C 802A12CC 8FB20030 */  lw        $s2, 0x30($sp)
/* 79DB70 802A12D0 8FB1002C */  lw        $s1, 0x2c($sp)
/* 79DB74 802A12D4 8FB00028 */  lw        $s0, 0x28($sp)
/* 79DB78 802A12D8 24020002 */  addiu     $v0, $zero, 2
/* 79DB7C 802A12DC 03E00008 */  jr        $ra
/* 79DB80 802A12E0 27BD0038 */   addiu    $sp, $sp, 0x38
