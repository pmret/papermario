.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400AC_D53D5C
/* D53D5C 802400AC 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* D53D60 802400B0 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* D53D64 802400B4 C4620080 */  lwc1      $f2, 0x80($v1)
/* D53D68 802400B8 44800000 */  mtc1      $zero, $f0
/* D53D6C 802400BC 00000000 */  nop       
/* D53D70 802400C0 4602003E */  c.le.s    $f0, $f2
/* D53D74 802400C4 00000000 */  nop       
/* D53D78 802400C8 4500000A */  bc1f      .L802400F4
/* D53D7C 802400CC 00000000 */   nop      
/* D53D80 802400D0 3C014334 */  lui       $at, 0x4334
/* D53D84 802400D4 44810000 */  mtc1      $at, $f0
/* D53D88 802400D8 00000000 */  nop       
/* D53D8C 802400DC 4600103C */  c.lt.s    $f2, $f0
/* D53D90 802400E0 00000000 */  nop       
/* D53D94 802400E4 45000006 */  bc1f      .L80240100
/* D53D98 802400E8 240200A5 */   addiu    $v0, $zero, 0xa5
/* D53D9C 802400EC AC820084 */  sw        $v0, 0x84($a0)
/* D53DA0 802400F0 C4620080 */  lwc1      $f2, 0x80($v1)
.L802400F4:
/* D53DA4 802400F4 3C014334 */  lui       $at, 0x4334
/* D53DA8 802400F8 44810000 */  mtc1      $at, $f0
/* D53DAC 802400FC 00000000 */  nop       
.L80240100:
/* D53DB0 80240100 4602003E */  c.le.s    $f0, $f2
/* D53DB4 80240104 00000000 */  nop       
/* D53DB8 80240108 45000009 */  bc1f      .L80240130
/* D53DBC 8024010C 00000000 */   nop      
/* D53DC0 80240110 3C0143B4 */  lui       $at, 0x43b4
/* D53DC4 80240114 44810000 */  mtc1      $at, $f0
/* D53DC8 80240118 00000000 */  nop       
/* D53DCC 8024011C 4600103C */  c.lt.s    $f2, $f0
/* D53DD0 80240120 00000000 */  nop       
/* D53DD4 80240124 45000002 */  bc1f      .L80240130
/* D53DD8 80240128 24020046 */   addiu    $v0, $zero, 0x46
/* D53DDC 8024012C AC820084 */  sw        $v0, 0x84($a0)
.L80240130:
/* D53DE0 80240130 03E00008 */  jr        $ra
/* D53DE4 80240134 24020002 */   addiu    $v0, $zero, 2
