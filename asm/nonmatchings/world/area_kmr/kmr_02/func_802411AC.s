.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411AC
/* 8B121C 802411AC 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 8B1220 802411B0 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 8B1224 802411B4 10A00002 */  beqz      $a1, .L802411C0
/* 8B1228 802411B8 2402003C */   addiu    $v0, $zero, 0x3c
/* 8B122C 802411BC AC820070 */  sw        $v0, 0x70($a0)
.L802411C0:
/* 8B1230 802411C0 C4620080 */  lwc1      $f2, 0x80($v1)
/* 8B1234 802411C4 3C0141F0 */  lui       $at, 0x41f0
/* 8B1238 802411C8 44810000 */  mtc1      $at, $f0
/* 8B123C 802411CC 00000000 */  nop       
/* 8B1240 802411D0 46001000 */  add.s     $f0, $f2, $f0
/* 8B1244 802411D4 3C0143B4 */  lui       $at, 0x43b4
/* 8B1248 802411D8 44811000 */  mtc1      $at, $f2
/* 8B124C 802411DC 00000000 */  nop       
/* 8B1250 802411E0 4600103E */  c.le.s    $f2, $f0
/* 8B1254 802411E4 00000000 */  nop       
/* 8B1258 802411E8 45000003 */  bc1f      .L802411F8
/* 8B125C 802411EC E4600080 */   swc1     $f0, 0x80($v1)
/* 8B1260 802411F0 46020001 */  sub.s     $f0, $f0, $f2
/* 8B1264 802411F4 E4600080 */  swc1      $f0, 0x80($v1)
.L802411F8:
/* 8B1268 802411F8 8C820070 */  lw        $v0, 0x70($a0)
/* 8B126C 802411FC 2442FFFF */  addiu     $v0, $v0, -1
/* 8B1270 80241200 AC820070 */  sw        $v0, 0x70($a0)
/* 8B1274 80241204 000217C3 */  sra       $v0, $v0, 0x1f
/* 8B1278 80241208 03E00008 */  jr        $ra
/* 8B127C 8024120C 30420002 */   andi     $v0, $v0, 2
