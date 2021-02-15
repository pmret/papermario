.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241628_7EC338
/* 7EC338 80241628 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EC33C 8024162C 3C058025 */  lui       $a1, %hi(D_80255B88)
/* 7EC340 80241630 8CA55B88 */  lw        $a1, %lo(D_80255B88)($a1)
/* 7EC344 80241634 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EC348 80241638 0C0B1EAF */  jal       get_variable
/* 7EC34C 8024163C 0000202D */   daddu    $a0, $zero, $zero
/* 7EC350 80241640 0040182D */  daddu     $v1, $v0, $zero
/* 7EC354 80241644 24020001 */  addiu     $v0, $zero, 1
/* 7EC358 80241648 14620006 */  bne       $v1, $v0, .L80241664
/* 7EC35C 8024164C 24020002 */   addiu    $v0, $zero, 2
/* 7EC360 80241650 44800000 */  mtc1      $zero, $f0
/* 7EC364 80241654 00000000 */  nop
/* 7EC368 80241658 44050000 */  mfc1      $a1, $f0
/* 7EC36C 8024165C 0809059F */  j         .L8024167C
/* 7EC370 80241660 0000202D */   daddu    $a0, $zero, $zero
.L80241664:
/* 7EC374 80241664 14620008 */  bne       $v1, $v0, .L80241688
/* 7EC378 80241668 24040001 */   addiu    $a0, $zero, 1
/* 7EC37C 8024166C 44800000 */  mtc1      $zero, $f0
/* 7EC380 80241670 00000000 */  nop
/* 7EC384 80241674 44050000 */  mfc1      $a1, $f0
/* 7EC388 80241678 00000000 */  nop
.L8024167C:
/* 7EC38C 8024167C 00A0302D */  daddu     $a2, $a1, $zero
/* 7EC390 80241680 0C01C5A4 */  jal       func_80071690
/* 7EC394 80241684 00A0382D */   daddu    $a3, $a1, $zero
.L80241688:
/* 7EC398 80241688 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EC39C 8024168C 03E00008 */  jr        $ra
/* 7EC3A0 80241690 27BD0018 */   addiu    $sp, $sp, 0x18
