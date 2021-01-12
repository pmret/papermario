.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1218_78A078
/* 78A078 802A1218 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 78A07C 802A121C AFB1002C */  sw        $s1, 0x2c($sp)
/* 78A080 802A1220 0080882D */  daddu     $s1, $a0, $zero
/* 78A084 802A1224 AFBF0034 */  sw        $ra, 0x34($sp)
/* 78A088 802A1228 AFB20030 */  sw        $s2, 0x30($sp)
/* 78A08C 802A122C AFB00028 */  sw        $s0, 0x28($sp)
/* 78A090 802A1230 8E30000C */  lw        $s0, 0xc($s1)
/* 78A094 802A1234 8E050000 */  lw        $a1, ($s0)
/* 78A098 802A1238 0C0B1EAF */  jal       get_variable
/* 78A09C 802A123C 26100004 */   addiu    $s0, $s0, 4
/* 78A0A0 802A1240 8E050000 */  lw        $a1, ($s0)
/* 78A0A4 802A1244 26100004 */  addiu     $s0, $s0, 4
/* 78A0A8 802A1248 0220202D */  daddu     $a0, $s1, $zero
/* 78A0AC 802A124C 0C0B1EAF */  jal       get_variable
/* 78A0B0 802A1250 0040902D */   daddu    $s2, $v0, $zero
/* 78A0B4 802A1254 0220202D */  daddu     $a0, $s1, $zero
/* 78A0B8 802A1258 8E050000 */  lw        $a1, ($s0)
/* 78A0BC 802A125C 0C0B1EAF */  jal       get_variable
/* 78A0C0 802A1260 0040802D */   daddu    $s0, $v0, $zero
/* 78A0C4 802A1264 24040004 */  addiu     $a0, $zero, 4
/* 78A0C8 802A1268 44922000 */  mtc1      $s2, $f4
/* 78A0CC 802A126C 00000000 */  nop       
/* 78A0D0 802A1270 46802120 */  cvt.s.w   $f4, $f4
/* 78A0D4 802A1274 44052000 */  mfc1      $a1, $f4
/* 78A0D8 802A1278 44902000 */  mtc1      $s0, $f4
/* 78A0DC 802A127C 00000000 */  nop       
/* 78A0E0 802A1280 46802120 */  cvt.s.w   $f4, $f4
/* 78A0E4 802A1284 44062000 */  mfc1      $a2, $f4
/* 78A0E8 802A1288 44822000 */  mtc1      $v0, $f4
/* 78A0EC 802A128C 00000000 */  nop       
/* 78A0F0 802A1290 46802120 */  cvt.s.w   $f4, $f4
/* 78A0F4 802A1294 3C0141A0 */  lui       $at, 0x41a0
/* 78A0F8 802A1298 44810000 */  mtc1      $at, $f0
/* 78A0FC 802A129C 3C013F80 */  lui       $at, 0x3f80
/* 78A100 802A12A0 44811000 */  mtc1      $at, $f2
/* 78A104 802A12A4 44072000 */  mfc1      $a3, $f4
/* 78A108 802A12A8 2403000A */  addiu     $v1, $zero, 0xa
/* 78A10C 802A12AC AFA3001C */  sw        $v1, 0x1c($sp)
/* 78A110 802A12B0 2403000F */  addiu     $v1, $zero, 0xf
/* 78A114 802A12B4 AFA30020 */  sw        $v1, 0x20($sp)
/* 78A118 802A12B8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 78A11C 802A12BC E7A00014 */  swc1      $f0, 0x14($sp)
/* 78A120 802A12C0 0C01C8D4 */  jal       func_80072350
/* 78A124 802A12C4 E7A20018 */   swc1     $f2, 0x18($sp)
/* 78A128 802A12C8 8FBF0034 */  lw        $ra, 0x34($sp)
/* 78A12C 802A12CC 8FB20030 */  lw        $s2, 0x30($sp)
/* 78A130 802A12D0 8FB1002C */  lw        $s1, 0x2c($sp)
/* 78A134 802A12D4 8FB00028 */  lw        $s0, 0x28($sp)
/* 78A138 802A12D8 24020002 */  addiu     $v0, $zero, 2
/* 78A13C 802A12DC 03E00008 */  jr        $ra
/* 78A140 802A12E0 27BD0038 */   addiu    $sp, $sp, 0x38
