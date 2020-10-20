.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802432C0_A1E3C0
/* A1E3C0 802432C0 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* A1E3C4 802432C4 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* A1E3C8 802432C8 10A00002 */  beqz      $a1, .L802432D4
/* A1E3CC 802432CC 2402003C */   addiu    $v0, $zero, 0x3c
/* A1E3D0 802432D0 AC820070 */  sw        $v0, 0x70($a0)
.L802432D4:
/* A1E3D4 802432D4 C4620080 */  lwc1      $f2, 0x80($v1)
/* A1E3D8 802432D8 3C0141F0 */  lui       $at, 0x41f0
/* A1E3DC 802432DC 44810000 */  mtc1      $at, $f0
/* A1E3E0 802432E0 00000000 */  nop       
/* A1E3E4 802432E4 46001000 */  add.s     $f0, $f2, $f0
/* A1E3E8 802432E8 3C0143B4 */  lui       $at, 0x43b4
/* A1E3EC 802432EC 44811000 */  mtc1      $at, $f2
/* A1E3F0 802432F0 00000000 */  nop       
/* A1E3F4 802432F4 4600103E */  c.le.s    $f2, $f0
/* A1E3F8 802432F8 00000000 */  nop       
/* A1E3FC 802432FC 45000003 */  bc1f      .L8024330C
/* A1E400 80243300 E4600080 */   swc1     $f0, 0x80($v1)
/* A1E404 80243304 46020001 */  sub.s     $f0, $f0, $f2
/* A1E408 80243308 E4600080 */  swc1      $f0, 0x80($v1)
.L8024330C:
/* A1E40C 8024330C 8C820070 */  lw        $v0, 0x70($a0)
/* A1E410 80243310 2442FFFF */  addiu     $v0, $v0, -1
/* A1E414 80243314 AC820070 */  sw        $v0, 0x70($a0)
/* A1E418 80243318 000217C3 */  sra       $v0, $v0, 0x1f
/* A1E41C 8024331C 03E00008 */  jr        $ra
/* A1E420 80243320 30420002 */   andi     $v0, $v0, 2
