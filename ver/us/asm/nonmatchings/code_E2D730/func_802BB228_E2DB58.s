.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB228_E2DB58
/* E2DB58 802BB228 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2DB5C 802BB22C AFBF0014 */  sw        $ra, 0x14($sp)
/* E2DB60 802BB230 AFB00010 */  sw        $s0, 0x10($sp)
/* E2DB64 802BB234 0C0AEC00 */  jal       func_802BB000_E2D930
/* E2DB68 802BB238 8C900040 */   lw       $s0, 0x40($a0)
/* E2DB6C 802BB23C C6000014 */  lwc1      $f0, 0x14($s0)
/* E2DB70 802BB240 3C014000 */  lui       $at, 0x4000
/* E2DB74 802BB244 44811800 */  mtc1      $at, $f3
/* E2DB78 802BB248 44801000 */  mtc1      $zero, $f2
/* E2DB7C 802BB24C 46000021 */  cvt.d.s   $f0, $f0
/* E2DB80 802BB250 46220000 */  add.d     $f0, $f0, $f2
/* E2DB84 802BB254 3C014220 */  lui       $at, 0x4220
/* E2DB88 802BB258 44811000 */  mtc1      $at, $f2
/* E2DB8C 802BB25C 46200020 */  cvt.s.d   $f0, $f0
/* E2DB90 802BB260 4600103C */  c.lt.s    $f2, $f0
/* E2DB94 802BB264 00000000 */  nop
/* E2DB98 802BB268 45000002 */  bc1f      .L802BB274
/* E2DB9C 802BB26C E6000014 */   swc1     $f0, 0x14($s0)
/* E2DBA0 802BB270 E6020014 */  swc1      $f2, 0x14($s0)
.L802BB274:
/* E2DBA4 802BB274 C6000008 */  lwc1      $f0, 8($s0)
/* E2DBA8 802BB278 C60C0014 */  lwc1      $f12, 0x14($s0)
/* E2DBAC 802BB27C 0C00A6C9 */  jal       clamp_angle
/* E2DBB0 802BB280 460C0300 */   add.s    $f12, $f0, $f12
/* E2DBB4 802BB284 E6000008 */  swc1      $f0, 8($s0)
/* E2DBB8 802BB288 8FBF0014 */  lw        $ra, 0x14($sp)
/* E2DBBC 802BB28C 8FB00010 */  lw        $s0, 0x10($sp)
/* E2DBC0 802BB290 03E00008 */  jr        $ra
/* E2DBC4 802BB294 27BD0018 */   addiu    $sp, $sp, 0x18
