.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005531C
/* 3071C 8005531C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 30720 80055320 AFB10014 */  sw        $s1, 0x14($sp)
/* 30724 80055324 0080882D */  daddu     $s1, $a0, $zero
/* 30728 80055328 AFB20018 */  sw        $s2, 0x18($sp)
/* 3072C 8005532C 00A0902D */  daddu     $s2, $a1, $zero
/* 30730 80055330 AFB3001C */  sw        $s3, 0x1c($sp)
/* 30734 80055334 00C0982D */  daddu     $s3, $a2, $zero
/* 30738 80055338 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3073C 8005533C 0C014238 */  jal       func_800508E0
/* 30740 80055340 AFB00010 */   sw       $s0, 0x10($sp)
/* 30744 80055344 0040802D */  daddu     $s0, $v0, $zero
/* 30748 80055348 16000006 */  bnez      $s0, .L80055364
/* 3074C 8005534C 0200102D */   daddu    $v0, $s0, $zero
/* 30750 80055350 0220202D */  daddu     $a0, $s1, $zero
/* 30754 80055354 0240282D */  daddu     $a1, $s2, $zero
/* 30758 80055358 0C014320 */  jal       func_80050C80
/* 3075C 8005535C 0260302D */   daddu    $a2, $s3, $zero
/* 30760 80055360 0200102D */  daddu     $v0, $s0, $zero
.L80055364:
/* 30764 80055364 8FBF0020 */  lw        $ra, 0x20($sp)
/* 30768 80055368 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3076C 8005536C 8FB20018 */  lw        $s2, 0x18($sp)
/* 30770 80055370 8FB10014 */  lw        $s1, 0x14($sp)
/* 30774 80055374 8FB00010 */  lw        $s0, 0x10($sp)
/* 30778 80055378 03E00008 */  jr        $ra
/* 3077C 8005537C 27BD0028 */   addiu    $sp, $sp, 0x28
