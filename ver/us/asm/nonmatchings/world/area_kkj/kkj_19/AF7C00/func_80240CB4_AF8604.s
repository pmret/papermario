.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CB4_AF8604
/* AF8604 80240CB4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF8608 80240CB8 10A00003 */  beqz      $a1, .L80240CC8
/* AF860C 80240CBC AFBF0010 */   sw       $ra, 0x10($sp)
/* AF8610 80240CC0 240200FF */  addiu     $v0, $zero, 0xff
/* AF8614 80240CC4 AC820074 */  sw        $v0, 0x74($a0)
.L80240CC8:
/* AF8618 80240CC8 8C820074 */  lw        $v0, 0x74($a0)
/* AF861C 80240CCC 2442FFF0 */  addiu     $v0, $v0, -0x10
/* AF8620 80240CD0 18400009 */  blez      $v0, .L80240CF8
/* AF8624 80240CD4 AC820074 */   sw       $v0, 0x74($a0)
/* AF8628 80240CD8 44820000 */  mtc1      $v0, $f0
/* AF862C 80240CDC 00000000 */  nop
/* AF8630 80240CE0 46800020 */  cvt.s.w   $f0, $f0
/* AF8634 80240CE4 44050000 */  mfc1      $a1, $f0
/* AF8638 80240CE8 0C04DF62 */  jal       set_screen_overlay_params_front
/* AF863C 80240CEC 0000202D */   daddu    $a0, $zero, $zero
/* AF8640 80240CF0 08090340 */  j         .L80240D00
/* AF8644 80240CF4 0000102D */   daddu    $v0, $zero, $zero
.L80240CF8:
/* AF8648 80240CF8 AC800074 */  sw        $zero, 0x74($a0)
/* AF864C 80240CFC 24020002 */  addiu     $v0, $zero, 2
.L80240D00:
/* AF8650 80240D00 8FBF0010 */  lw        $ra, 0x10($sp)
/* AF8654 80240D04 03E00008 */  jr        $ra
/* AF8658 80240D08 27BD0018 */   addiu    $sp, $sp, 0x18
/* AF865C 80240D0C 00000000 */  nop
