.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242318_854488
/* 854488 80242318 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 85448C 8024231C 3C058025 */  lui       $a1, %hi(D_802529E8)
/* 854490 80242320 8CA529E8 */  lw        $a1, %lo(D_802529E8)($a1)
/* 854494 80242324 AFBF0010 */  sw        $ra, 0x10($sp)
/* 854498 80242328 0C0B1EAF */  jal       evt_get_variable
/* 85449C 8024232C 0000202D */   daddu    $a0, $zero, $zero
/* 8544A0 80242330 0040182D */  daddu     $v1, $v0, $zero
/* 8544A4 80242334 24020001 */  addiu     $v0, $zero, 1
/* 8544A8 80242338 14620006 */  bne       $v1, $v0, .L80242354
/* 8544AC 8024233C 24020002 */   addiu    $v0, $zero, 2
/* 8544B0 80242340 44800000 */  mtc1      $zero, $f0
/* 8544B4 80242344 00000000 */  nop
/* 8544B8 80242348 44050000 */  mfc1      $a1, $f0
/* 8544BC 8024234C 080908DB */  j         .L8024236C
/* 8544C0 80242350 0000202D */   daddu    $a0, $zero, $zero
.L80242354:
/* 8544C4 80242354 14620008 */  bne       $v1, $v0, .L80242378
/* 8544C8 80242358 24040001 */   addiu    $a0, $zero, 1
/* 8544CC 8024235C 44800000 */  mtc1      $zero, $f0
/* 8544D0 80242360 00000000 */  nop
/* 8544D4 80242364 44050000 */  mfc1      $a1, $f0
/* 8544D8 80242368 00000000 */  nop
.L8024236C:
/* 8544DC 8024236C 00A0302D */  daddu     $a2, $a1, $zero
/* 8544E0 80242370 0C01C5A4 */  jal       playFX_50
/* 8544E4 80242374 00A0382D */   daddu    $a3, $a1, $zero
.L80242378:
/* 8544E8 80242378 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8544EC 8024237C 03E00008 */  jr        $ra
/* 8544F0 80242380 27BD0018 */   addiu    $sp, $sp, 0x18
