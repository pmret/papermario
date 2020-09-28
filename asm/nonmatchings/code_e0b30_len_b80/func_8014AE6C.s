.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8014AE6C
/* E156C 8014AE6C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* E1570 8014AE70 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* E1574 8014AE74 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E1578 8014AE78 AFBF0018 */  sw        $ra, 0x18($sp)
/* E157C 8014AE7C 80420071 */  lb        $v0, 0x71($v0)
/* E1580 8014AE80 3C068016 */  lui       $a2, 0x8016
/* E1584 8014AE84 24C69AF0 */  addiu     $a2, $a2, -0x6510
/* E1588 8014AE88 14400018 */  bnez      $v0, .L8014AEEC
/* E158C 8014AE8C 3C020002 */   lui      $v0, 2
/* E1590 8014AE90 3C04800A */  lui       $a0, %hi(D_8009A650)
/* E1594 8014AE94 2484A650 */  addiu     $a0, $a0, %lo(D_8009A650)
/* E1598 8014AE98 8C830000 */  lw        $v1, ($a0)
/* E159C 8014AE9C 00621024 */  and       $v0, $v1, $v0
/* E15A0 8014AEA0 10400005 */  beqz      $v0, .L8014AEB8
/* E15A4 8014AEA4 3C02FFFD */   lui      $v0, 0xfffd
/* E15A8 8014AEA8 3442FFFF */  ori       $v0, $v0, 0xffff
/* E15AC 8014AEAC 00621024 */  and       $v0, $v1, $v0
/* E15B0 8014AEB0 08052BBB */  j         .L8014AEEC
/* E15B4 8014AEB4 AC820000 */   sw       $v0, ($a0)
.L8014AEB8:
/* E15B8 8014AEB8 0000202D */  daddu     $a0, $zero, $zero
/* E15BC 8014AEBC 8CC50024 */  lw        $a1, 0x24($a2)
/* E15C0 8014AEC0 94C20000 */  lhu       $v0, ($a2)
/* E15C4 8014AEC4 24030008 */  addiu     $v1, $zero, 8
/* E15C8 8014AEC8 AFA30010 */  sw        $v1, 0x10($sp)
/* E15CC 8014AECC 00431025 */  or        $v0, $v0, $v1
/* E15D0 8014AED0 A4C20000 */  sh        $v0, ($a2)
/* E15D4 8014AED4 8CC60028 */  lw        $a2, 0x28($a2)
/* E15D8 8014AED8 0C0529F8 */  jal       _set_music_track
/* E15DC 8014AEDC 0080382D */   daddu    $a3, $a0, $zero
/* E15E0 8014AEE0 0000202D */  daddu     $a0, $zero, $zero
/* E15E4 8014AEE4 0C015564 */  jal       func_80055590
/* E15E8 8014AEE8 240500FA */   addiu    $a1, $zero, 0xfa
.L8014AEEC:
/* E15EC 8014AEEC 8FBF0018 */  lw        $ra, 0x18($sp)
/* E15F0 8014AEF0 03E00008 */  jr        $ra
/* E15F4 8014AEF4 27BD0020 */   addiu    $sp, $sp, 0x20
