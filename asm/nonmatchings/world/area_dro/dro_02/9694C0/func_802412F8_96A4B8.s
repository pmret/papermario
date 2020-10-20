.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412F8_96A4B8
/* 96A4B8 802412F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96A4BC 802412FC 3C058025 */  lui       $a1, 0x8025
/* 96A4C0 80241300 8CA5EFB8 */  lw        $a1, -0x1048($a1)
/* 96A4C4 80241304 AFBF0010 */  sw        $ra, 0x10($sp)
/* 96A4C8 80241308 0C0B1EAF */  jal       get_variable
/* 96A4CC 8024130C 0000202D */   daddu    $a0, $zero, $zero
/* 96A4D0 80241310 0040182D */  daddu     $v1, $v0, $zero
/* 96A4D4 80241314 24020001 */  addiu     $v0, $zero, 1
/* 96A4D8 80241318 14620006 */  bne       $v1, $v0, .L80241334
/* 96A4DC 8024131C 24020002 */   addiu    $v0, $zero, 2
/* 96A4E0 80241320 44800000 */  mtc1      $zero, $f0
/* 96A4E4 80241324 00000000 */  nop       
/* 96A4E8 80241328 44050000 */  mfc1      $a1, $f0
/* 96A4EC 8024132C 080904D3 */  j         .L8024134C
/* 96A4F0 80241330 0000202D */   daddu    $a0, $zero, $zero
.L80241334:
/* 96A4F4 80241334 14620008 */  bne       $v1, $v0, .L80241358
/* 96A4F8 80241338 24040001 */   addiu    $a0, $zero, 1
/* 96A4FC 8024133C 44800000 */  mtc1      $zero, $f0
/* 96A500 80241340 00000000 */  nop       
/* 96A504 80241344 44050000 */  mfc1      $a1, $f0
/* 96A508 80241348 00000000 */  nop       
.L8024134C:
/* 96A50C 8024134C 00A0302D */  daddu     $a2, $a1, $zero
/* 96A510 80241350 0C01C5A4 */  jal       func_80071690
/* 96A514 80241354 00A0382D */   daddu    $a3, $a1, $zero
.L80241358:
/* 96A518 80241358 8FBF0010 */  lw        $ra, 0x10($sp)
/* 96A51C 8024135C 03E00008 */  jr        $ra
/* 96A520 80241360 27BD0018 */   addiu    $sp, $sp, 0x18
