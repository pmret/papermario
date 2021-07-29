.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel render_screen_overlay_frontUI
/* CE8A0 801381A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CE8A4 801381A4 3C048015 */  lui       $a0, %hi(D_80156900)
/* CE8A8 801381A8 24846900 */  addiu     $a0, $a0, %lo(D_80156900)
/* CE8AC 801381AC AFBF0010 */  sw        $ra, 0x10($sp)
/* CE8B0 801381B0 8C830000 */  lw        $v1, ($a0)
/* CE8B4 801381B4 2402FFFF */  addiu     $v0, $zero, -1
/* CE8B8 801381B8 10620016 */  beq       $v1, $v0, .L80138214
/* CE8BC 801381BC 00000000 */   nop
/* CE8C0 801381C0 3C018015 */  lui       $at, %hi(D_80156904)
/* CE8C4 801381C4 C4226904 */  lwc1      $f2, %lo(D_80156904)($at)
/* CE8C8 801381C8 3C01BF80 */  lui       $at, 0xbf80
/* CE8CC 801381CC 44810000 */  mtc1      $at, $f0
/* CE8D0 801381D0 00000000 */  nop
/* CE8D4 801381D4 46001032 */  c.eq.s    $f2, $f0
/* CE8D8 801381D8 00000000 */  nop
/* CE8DC 801381DC 4501000D */  bc1t      .L80138214
/* CE8E0 801381E0 00000000 */   nop
/* CE8E4 801381E4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* CE8E8 801381E8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* CE8EC 801381EC 80430070 */  lb        $v1, 0x70($v0)
/* CE8F0 801381F0 24020002 */  addiu     $v0, $zero, 2
/* CE8F4 801381F4 10620007 */  beq       $v1, $v0, .L80138214
/* CE8F8 801381F8 00000000 */   nop
/* CE8FC 801381FC 90840003 */  lbu       $a0, 3($a0)
/* CE900 80138200 44051000 */  mfc1      $a1, $f2
/* CE904 80138204 3C068016 */  lui       $a2, %hi(D_8015C790)
/* CE908 80138208 24C6C790 */  addiu     $a2, $a2, %lo(D_8015C790)
/* CE90C 8013820C 0C04DAA0 */  jal       _render_transition_stencil
/* CE910 80138210 00000000 */   nop
.L80138214:
/* CE914 80138214 8FBF0010 */  lw        $ra, 0x10($sp)
/* CE918 80138218 03E00008 */  jr        $ra
/* CE91C 8013821C 27BD0018 */   addiu    $sp, $sp, 0x18
