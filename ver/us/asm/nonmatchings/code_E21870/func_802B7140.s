.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B7140
/* E219B0 802B7140 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E219B4 802B7144 AFB00010 */  sw        $s0, 0x10($sp)
/* E219B8 802B7148 3C10802B */  lui       $s0, 0x802b
/* E219BC 802B714C 26107D18 */  addiu     $s0, $s0, 0x7d18
/* E219C0 802B7150 AFBF0014 */  sw        $ra, 0x14($sp)
/* E219C4 802B7154 8E040000 */  lw        $a0, ($s0)
/* E219C8 802B7158 0C00A580 */  jal       mem_clear
/* E219CC 802B715C 24050028 */   addiu    $a1, $zero, 0x28
/* E219D0 802B7160 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* E219D4 802B7164 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* E219D8 802B7168 8E030000 */  lw        $v1, ($s0)
/* E219DC 802B716C C4800028 */  lwc1      $f0, 0x28($a0)
/* E219E0 802B7170 E4600000 */  swc1      $f0, ($v1)
/* E219E4 802B7174 848200B0 */  lh        $v0, 0xb0($a0)
/* E219E8 802B7178 C480002C */  lwc1      $f0, 0x2c($a0)
/* E219EC 802B717C 44821000 */  mtc1      $v0, $f2
/* E219F0 802B7180 00000000 */  nop
/* E219F4 802B7184 468010A0 */  cvt.s.w   $f2, $f2
/* E219F8 802B7188 46020000 */  add.s     $f0, $f0, $f2
/* E219FC 802B718C 3C014100 */  lui       $at, 0x4100
/* E21A00 802B7190 44811000 */  mtc1      $at, $f2
/* E21A04 802B7194 00000000 */  nop
/* E21A08 802B7198 46020000 */  add.s     $f0, $f0, $f2
/* E21A0C 802B719C E4600004 */  swc1      $f0, 4($v1)
/* E21A10 802B71A0 C4800030 */  lwc1      $f0, 0x30($a0)
/* E21A14 802B71A4 E4600008 */  swc1      $f0, 8($v1)
/* E21A18 802B71A8 8C820004 */  lw        $v0, 4($a0)
/* E21A1C 802B71AC 34420040 */  ori       $v0, $v0, 0x40
/* E21A20 802B71B0 AC820004 */  sw        $v0, 4($a0)
/* E21A24 802B71B4 8FBF0014 */  lw        $ra, 0x14($sp)
/* E21A28 802B71B8 8FB00010 */  lw        $s0, 0x10($sp)
/* E21A2C 802B71BC 3C03802B */  lui       $v1, 0x802b
/* E21A30 802B71C0 246374F0 */  addiu     $v1, $v1, 0x74f0
/* E21A34 802B71C4 3C018011 */  lui       $at, 0x8011
/* E21A38 802B71C8 AC23C920 */  sw        $v1, -0x36e0($at)
/* E21A3C 802B71CC 03E00008 */  jr        $ra
/* E21A40 802B71D0 27BD0018 */   addiu    $sp, $sp, 0x18
