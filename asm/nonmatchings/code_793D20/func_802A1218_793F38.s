.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1218_793F38
/* 793F38 802A1218 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 793F3C 802A121C AFB1002C */  sw        $s1, 0x2c($sp)
/* 793F40 802A1220 0080882D */  daddu     $s1, $a0, $zero
/* 793F44 802A1224 AFBF0034 */  sw        $ra, 0x34($sp)
/* 793F48 802A1228 AFB20030 */  sw        $s2, 0x30($sp)
/* 793F4C 802A122C AFB00028 */  sw        $s0, 0x28($sp)
/* 793F50 802A1230 8E30000C */  lw        $s0, 0xc($s1)
/* 793F54 802A1234 8E050000 */  lw        $a1, ($s0)
/* 793F58 802A1238 0C0B1EAF */  jal       get_variable
/* 793F5C 802A123C 26100004 */   addiu    $s0, $s0, 4
/* 793F60 802A1240 8E050000 */  lw        $a1, ($s0)
/* 793F64 802A1244 26100004 */  addiu     $s0, $s0, 4
/* 793F68 802A1248 0220202D */  daddu     $a0, $s1, $zero
/* 793F6C 802A124C 0C0B1EAF */  jal       get_variable
/* 793F70 802A1250 0040902D */   daddu    $s2, $v0, $zero
/* 793F74 802A1254 0220202D */  daddu     $a0, $s1, $zero
/* 793F78 802A1258 8E050000 */  lw        $a1, ($s0)
/* 793F7C 802A125C 0C0B1EAF */  jal       get_variable
/* 793F80 802A1260 0040802D */   daddu    $s0, $v0, $zero
/* 793F84 802A1264 24040004 */  addiu     $a0, $zero, 4
/* 793F88 802A1268 44922000 */  mtc1      $s2, $f4
/* 793F8C 802A126C 00000000 */  nop       
/* 793F90 802A1270 46802120 */  cvt.s.w   $f4, $f4
/* 793F94 802A1274 44052000 */  mfc1      $a1, $f4
/* 793F98 802A1278 44902000 */  mtc1      $s0, $f4
/* 793F9C 802A127C 00000000 */  nop       
/* 793FA0 802A1280 46802120 */  cvt.s.w   $f4, $f4
/* 793FA4 802A1284 44062000 */  mfc1      $a2, $f4
/* 793FA8 802A1288 44822000 */  mtc1      $v0, $f4
/* 793FAC 802A128C 00000000 */  nop       
/* 793FB0 802A1290 46802120 */  cvt.s.w   $f4, $f4
/* 793FB4 802A1294 3C0141A0 */  lui       $at, 0x41a0
/* 793FB8 802A1298 44810000 */  mtc1      $at, $f0
/* 793FBC 802A129C 3C013F80 */  lui       $at, 0x3f80
/* 793FC0 802A12A0 44811000 */  mtc1      $at, $f2
/* 793FC4 802A12A4 44072000 */  mfc1      $a3, $f4
/* 793FC8 802A12A8 2403000A */  addiu     $v1, $zero, 0xa
/* 793FCC 802A12AC AFA3001C */  sw        $v1, 0x1c($sp)
/* 793FD0 802A12B0 2403000F */  addiu     $v1, $zero, 0xf
/* 793FD4 802A12B4 AFA30020 */  sw        $v1, 0x20($sp)
/* 793FD8 802A12B8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 793FDC 802A12BC E7A00014 */  swc1      $f0, 0x14($sp)
/* 793FE0 802A12C0 0C01C8D4 */  jal       func_80072350
/* 793FE4 802A12C4 E7A20018 */   swc1     $f2, 0x18($sp)
/* 793FE8 802A12C8 8FBF0034 */  lw        $ra, 0x34($sp)
/* 793FEC 802A12CC 8FB20030 */  lw        $s2, 0x30($sp)
/* 793FF0 802A12D0 8FB1002C */  lw        $s1, 0x2c($sp)
/* 793FF4 802A12D4 8FB00028 */  lw        $s0, 0x28($sp)
/* 793FF8 802A12D8 24020002 */  addiu     $v0, $zero, 2
/* 793FFC 802A12DC 03E00008 */  jr        $ra
/* 794000 802A12E0 27BD0038 */   addiu    $sp, $sp, 0x38
