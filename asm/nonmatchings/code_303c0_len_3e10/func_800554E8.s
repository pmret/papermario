.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800554E8
/* 308E8 800554E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 308EC 800554EC AFB10014 */  sw        $s1, 0x14($sp)
/* 308F0 800554F0 0080882D */  daddu     $s1, $a0, $zero
/* 308F4 800554F4 AFB20018 */  sw        $s2, 0x18($sp)
/* 308F8 800554F8 00A0902D */  daddu     $s2, $a1, $zero
/* 308FC 800554FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 30900 80055500 0C01430C */  jal       func_80050C30
/* 30904 80055504 AFB00010 */   sw       $s0, 0x10($sp)
/* 30908 80055508 0040802D */  daddu     $s0, $v0, $zero
/* 3090C 8005550C 16000005 */  bnez      $s0, .L80055524
/* 30910 80055510 0200102D */   daddu    $v0, $s0, $zero
/* 30914 80055514 0220202D */  daddu     $a0, $s1, $zero
/* 30918 80055518 0C0143D9 */  jal       func_80050F64
/* 3091C 8005551C 0240282D */   daddu    $a1, $s2, $zero
/* 30920 80055520 0200102D */  daddu     $v0, $s0, $zero
.L80055524:
/* 30924 80055524 8FBF001C */  lw        $ra, 0x1c($sp)
/* 30928 80055528 8FB20018 */  lw        $s2, 0x18($sp)
/* 3092C 8005552C 8FB10014 */  lw        $s1, 0x14($sp)
/* 30930 80055530 8FB00010 */  lw        $s0, 0x10($sp)
/* 30934 80055534 03E00008 */  jr        $ra
/* 30938 80055538 27BD0020 */   addiu    $sp, $sp, 0x20
