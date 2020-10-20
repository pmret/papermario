.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415EC_D3BBBC
/* D3BBBC 802415EC 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* D3BBC0 802415F0 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* D3BBC4 802415F4 10A00002 */  beqz      $a1, .L80241600
/* D3BBC8 802415F8 2402003C */   addiu    $v0, $zero, 0x3c
/* D3BBCC 802415FC AC820070 */  sw        $v0, 0x70($a0)
.L80241600:
/* D3BBD0 80241600 C4620080 */  lwc1      $f2, 0x80($v1)
/* D3BBD4 80241604 3C0141F0 */  lui       $at, 0x41f0
/* D3BBD8 80241608 44810000 */  mtc1      $at, $f0
/* D3BBDC 8024160C 00000000 */  nop       
/* D3BBE0 80241610 46001000 */  add.s     $f0, $f2, $f0
/* D3BBE4 80241614 3C0143B4 */  lui       $at, 0x43b4
/* D3BBE8 80241618 44811000 */  mtc1      $at, $f2
/* D3BBEC 8024161C 00000000 */  nop       
/* D3BBF0 80241620 4600103E */  c.le.s    $f2, $f0
/* D3BBF4 80241624 00000000 */  nop       
/* D3BBF8 80241628 45000003 */  bc1f      .L80241638
/* D3BBFC 8024162C E4600080 */   swc1     $f0, 0x80($v1)
/* D3BC00 80241630 46020001 */  sub.s     $f0, $f0, $f2
/* D3BC04 80241634 E4600080 */  swc1      $f0, 0x80($v1)
.L80241638:
/* D3BC08 80241638 8C820070 */  lw        $v0, 0x70($a0)
/* D3BC0C 8024163C 2442FFFF */  addiu     $v0, $v0, -1
/* D3BC10 80241640 AC820070 */  sw        $v0, 0x70($a0)
/* D3BC14 80241644 000217C3 */  sra       $v0, $v0, 0x1f
/* D3BC18 80241648 03E00008 */  jr        $ra
/* D3BC1C 8024164C 30420002 */   andi     $v0, $v0, 2
