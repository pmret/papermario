.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_D53CD0
/* D53CD0 80240020 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* D53CD4 80240024 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* D53CD8 80240028 C4620080 */  lwc1      $f2, 0x80($v1)
/* D53CDC 8024002C 44800000 */  mtc1      $zero, $f0
/* D53CE0 80240030 00000000 */  nop
/* D53CE4 80240034 4602003E */  c.le.s    $f0, $f2
/* D53CE8 80240038 00000000 */  nop
/* D53CEC 8024003C 4500000A */  bc1f      .L80240068
/* D53CF0 80240040 00000000 */   nop
/* D53CF4 80240044 3C014334 */  lui       $at, 0x4334
/* D53CF8 80240048 44810000 */  mtc1      $at, $f0
/* D53CFC 8024004C 00000000 */  nop
/* D53D00 80240050 4600103C */  c.lt.s    $f2, $f0
/* D53D04 80240054 00000000 */  nop
/* D53D08 80240058 45000006 */  bc1f      .L80240074
/* D53D0C 8024005C 24020096 */   addiu    $v0, $zero, 0x96
/* D53D10 80240060 AC820084 */  sw        $v0, 0x84($a0)
/* D53D14 80240064 C4620080 */  lwc1      $f2, 0x80($v1)
.L80240068:
/* D53D18 80240068 3C014334 */  lui       $at, 0x4334
/* D53D1C 8024006C 44810000 */  mtc1      $at, $f0
/* D53D20 80240070 00000000 */  nop
.L80240074:
/* D53D24 80240074 4602003E */  c.le.s    $f0, $f2
/* D53D28 80240078 00000000 */  nop
/* D53D2C 8024007C 45000009 */  bc1f      .L802400A4
/* D53D30 80240080 00000000 */   nop
/* D53D34 80240084 3C0143B4 */  lui       $at, 0x43b4
/* D53D38 80240088 44810000 */  mtc1      $at, $f0
/* D53D3C 8024008C 00000000 */  nop
/* D53D40 80240090 4600103C */  c.lt.s    $f2, $f0
/* D53D44 80240094 00000000 */  nop
/* D53D48 80240098 45000002 */  bc1f      .L802400A4
/* D53D4C 8024009C 2402005F */   addiu    $v0, $zero, 0x5f
/* D53D50 802400A0 AC820084 */  sw        $v0, 0x84($a0)
.L802400A4:
/* D53D54 802400A4 03E00008 */  jr        $ra
/* D53D58 802400A8 24020002 */   addiu    $v0, $zero, 2
