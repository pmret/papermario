.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_items_is_visible
/* 13CC70 80249930 3C038027 */  lui       $v1, %hi(gItemMenuCurrentScrollPos)
/* 13CC74 80249934 8C6305D4 */  lw        $v1, %lo(gItemMenuCurrentScrollPos)($v1)
/* 13CC78 80249938 2462FFE0 */  addiu     $v0, $v1, -0x20
/* 13CC7C 8024993C 0082102A */  slt       $v0, $a0, $v0
/* 13CC80 80249940 14400003 */  bnez      $v0, .L80249950
/* 13CC84 80249944 24620080 */   addiu    $v0, $v1, 0x80
/* 13CC88 80249948 03E00008 */  jr        $ra
/* 13CC8C 8024994C 0082102A */   slt      $v0, $a0, $v0
.L80249950:
/* 13CC90 80249950 03E00008 */  jr        $ra
/* 13CC94 80249954 0000102D */   daddu    $v0, $zero, $zero
