.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel IncrementPlayerHP
/* 190608 80261D28 3C048011 */  lui       $a0, 0x8011
/* 19060C 80261D2C 2484F290 */  addiu     $a0, $a0, -0xd70
/* 190610 80261D30 90820002 */  lbu       $v0, 2($a0)
/* 190614 80261D34 80830003 */  lb        $v1, 3($a0)
/* 190618 80261D38 24420001 */  addiu     $v0, $v0, 1
/* 19061C 80261D3C A0820002 */  sb        $v0, 2($a0)
/* 190620 80261D40 00021600 */  sll       $v0, $v0, 0x18
/* 190624 80261D44 00021603 */  sra       $v0, $v0, 0x18
/* 190628 80261D48 0062182A */  slt       $v1, $v1, $v0
/* 19062C 80261D4C 90820003 */  lbu       $v0, 3($a0)
/* 190630 80261D50 54600001 */  bnel      $v1, $zero, .L80261D58
/* 190634 80261D54 A0820002 */   sb       $v0, 2($a0)
.L80261D58:
/* 190638 80261D58 03E00008 */  jr        $ra
/* 19063C 80261D5C 24020002 */   addiu    $v0, $zero, 2
