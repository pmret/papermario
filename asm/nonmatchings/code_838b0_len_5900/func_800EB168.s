.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EB168
/* 84618 800EB168 3C038011 */  lui       $v1, 0x8011
/* 8461C 800EB16C 8C63CFD8 */  lw        $v1, -0x3028($v1)
/* 84620 800EB170 3C058011 */  lui       $a1, 0x8011
/* 84624 800EB174 24A5EFC8 */  addiu     $a1, $a1, -0x1038
/* 84628 800EB178 1064000C */  beq       $v1, $a0, .L800EB1AC
/* 8462C 800EB17C 24020001 */   addiu    $v0, $zero, 1
/* 84630 800EB180 3C018011 */  lui       $at, 0x8011
/* 84634 800EB184 AC22CFE0 */  sw        $v0, -0x3020($at)
/* 84638 800EB188 3C018011 */  lui       $at, 0x8011
/* 8463C 800EB18C AC24CFE4 */  sw        $a0, -0x301c($at)
/* 84640 800EB190 10600008 */  beqz      $v1, .L800EB1B4
/* 84644 800EB194 00000000 */   nop      
/* 84648 800EB198 10800009 */  beqz      $a0, .L800EB1C0
/* 8464C 800EB19C 24020004 */   addiu    $v0, $zero, 4
/* 84650 800EB1A0 24020003 */  addiu     $v0, $zero, 3
/* 84654 800EB1A4 3C018011 */  lui       $at, 0x8011
/* 84658 800EB1A8 AC22CFE8 */  sw        $v0, -0x3018($at)
.L800EB1AC:
/* 8465C 800EB1AC 03E00008 */  jr        $ra
/* 84660 800EB1B0 00000000 */   nop      
.L800EB1B4:
/* 84664 800EB1B4 14800006 */  bnez      $a0, .L800EB1D0
/* 84668 800EB1B8 24020006 */   addiu    $v0, $zero, 6
/* 8466C 800EB1BC 24020004 */  addiu     $v0, $zero, 4
.L800EB1C0:
/* 84670 800EB1C0 3C018011 */  lui       $at, 0x8011
/* 84674 800EB1C4 AC22CFE8 */  sw        $v0, -0x3018($at)
/* 84678 800EB1C8 03E00008 */  jr        $ra
/* 8467C 800EB1CC 00000000 */   nop      
.L800EB1D0:
/* 84680 800EB1D0 C4A00028 */  lwc1      $f0, 0x28($a1)
/* 84684 800EB1D4 C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 84688 800EB1D8 C4A40030 */  lwc1      $f4, 0x30($a1)
/* 8468C 800EB1DC 3C018011 */  lui       $at, 0x8011
/* 84690 800EB1E0 AC22CFE8 */  sw        $v0, -0x3018($at)
/* 84694 800EB1E4 3C018010 */  lui       $at, 0x8010
/* 84698 800EB1E8 E420833C */  swc1      $f0, -0x7cc4($at)
/* 8469C 800EB1EC 3C018010 */  lui       $at, 0x8010
/* 846A0 800EB1F0 E4228340 */  swc1      $f2, -0x7cc0($at)
/* 846A4 800EB1F4 3C018010 */  lui       $at, 0x8010
/* 846A8 800EB1F8 03E00008 */  jr        $ra
/* 846AC 800EB1FC E4248344 */   swc1     $f4, -0x7cbc($at)
