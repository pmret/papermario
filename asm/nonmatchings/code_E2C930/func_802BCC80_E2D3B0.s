.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BCC80_E2D3B0
/* E2D3B0 802BCC80 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2D3B4 802BCC84 AFB00010 */  sw        $s0, 0x10($sp)
/* E2D3B8 802BCC88 0080802D */  daddu     $s0, $a0, $zero
/* E2D3BC 802BCC8C AFBF0014 */  sw        $ra, 0x14($sp)
/* E2D3C0 802BCC90 92020006 */  lbu       $v0, 6($s0)
/* E2D3C4 802BCC94 30420080 */  andi      $v0, $v0, 0x80
/* E2D3C8 802BCC98 1040000C */  beqz      $v0, .L802BCCCC
/* E2D3CC 802BCC9C 00000000 */   nop
/* E2D3D0 802BCCA0 0C04419E */  jal       func_80110678
/* E2D3D4 802BCCA4 00000000 */   nop
/* E2D3D8 802BCCA8 0C043F5A */  jal       func_8010FD68
/* E2D3DC 802BCCAC 0200202D */   daddu    $a0, $s0, $zero
/* E2D3E0 802BCCB0 C600004C */  lwc1      $f0, 0x4c($s0)
/* E2D3E4 802BCCB4 3C0141C8 */  lui       $at, 0x41c8
/* E2D3E8 802BCCB8 44817000 */  mtc1      $at, $f14
/* E2D3EC 802BCCBC C60C0048 */  lwc1      $f12, 0x48($s0)
/* E2D3F0 802BCCC0 8E060050 */  lw        $a2, 0x50($s0)
/* E2D3F4 802BCCC4 0C01BE3C */  jal       func_8006F8F0
/* E2D3F8 802BCCC8 460E0380 */   add.s    $f14, $f0, $f14
.L802BCCCC:
/* E2D3FC 802BCCCC 8FBF0014 */  lw        $ra, 0x14($sp)
/* E2D400 802BCCD0 8FB00010 */  lw        $s0, 0x10($sp)
/* E2D404 802BCCD4 03E00008 */  jr        $ra
/* E2D408 802BCCD8 27BD0018 */   addiu    $sp, $sp, 0x18
/* E2D40C 802BCCDC 00000000 */  nop
