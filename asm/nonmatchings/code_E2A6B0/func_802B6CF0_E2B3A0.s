.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6CF0_E2B3A0
/* E2B3A0 802B6CF0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2B3A4 802B6CF4 3C02802B */  lui       $v0, %hi(D_802B6E80)
/* E2B3A8 802B6CF8 24426E80 */  addiu     $v0, $v0, %lo(D_802B6E80)
/* E2B3AC 802B6CFC AFBF0014 */  sw        $ra, 0x14($sp)
/* E2B3B0 802B6D00 AFB00010 */  sw        $s0, 0x10($sp)
/* E2B3B4 802B6D04 C4420020 */  lwc1      $f2, 0x20($v0)
/* E2B3B8 802B6D08 C440001C */  lwc1      $f0, 0x1c($v0)
/* E2B3BC 802B6D0C 46001080 */  add.s     $f2, $f2, $f0
/* E2B3C0 802B6D10 3C014248 */  lui       $at, 0x4248
/* E2B3C4 802B6D14 44810000 */  mtc1      $at, $f0
/* E2B3C8 802B6D18 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E2B3CC 802B6D1C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E2B3D0 802B6D20 4602003C */  c.lt.s    $f0, $f2
/* E2B3D4 802B6D24 00000000 */  nop       
/* E2B3D8 802B6D28 45010008 */  bc1t      .L802B6D4C
/* E2B3DC 802B6D2C E4420020 */   swc1     $f2, 0x20($v0)
/* E2B3E0 802B6D30 3C01C248 */  lui       $at, 0xc248
/* E2B3E4 802B6D34 44810000 */  mtc1      $at, $f0
/* E2B3E8 802B6D38 00000000 */  nop       
/* E2B3EC 802B6D3C 4600103C */  c.lt.s    $f2, $f0
/* E2B3F0 802B6D40 00000000 */  nop       
/* E2B3F4 802B6D44 45000002 */  bc1f      .L802B6D50
/* E2B3F8 802B6D48 00000000 */   nop      
.L802B6D4C:
/* E2B3FC 802B6D4C E4400020 */  swc1      $f0, 0x20($v0)
.L802B6D50:
/* E2B400 802B6D50 C60000A8 */  lwc1      $f0, 0xa8($s0)
/* E2B404 802B6D54 C44C0020 */  lwc1      $f12, 0x20($v0)
/* E2B408 802B6D58 0C00A6C9 */  jal       clamp_angle
/* E2B40C 802B6D5C 460C0300 */   add.s    $f12, $f0, $f12
/* E2B410 802B6D60 E60000A8 */  swc1      $f0, 0xa8($s0)
/* E2B414 802B6D64 8FBF0014 */  lw        $ra, 0x14($sp)
/* E2B418 802B6D68 8FB00010 */  lw        $s0, 0x10($sp)
/* E2B41C 802B6D6C 03E00008 */  jr        $ra
