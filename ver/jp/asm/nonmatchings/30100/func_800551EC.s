.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800551EC
/* 305EC 800551EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 305F0 800551F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 305F4 800551F4 0080882D */  daddu     $s1, $a0, $zero
/* 305F8 800551F8 AFB20018 */  sw        $s2, 0x18($sp)
/* 305FC 800551FC 00A0902D */  daddu     $s2, $a1, $zero
/* 30600 80055200 AFBF001C */  sw        $ra, 0x1c($sp)
/* 30604 80055204 0C014238 */  jal       func_800508E0
/* 30608 80055208 AFB00010 */   sw       $s0, 0x10($sp)
/* 3060C 8005520C 0040802D */  daddu     $s0, $v0, $zero
/* 30610 80055210 16000005 */  bnez      $s0, .L80055228
/* 30614 80055214 0200102D */   daddu    $v0, $s0, $zero
/* 30618 80055218 0220202D */  daddu     $a0, $s1, $zero
/* 3061C 8005521C 0C0142B2 */  jal       func_80050AC8
/* 30620 80055220 0240282D */   daddu    $a1, $s2, $zero
/* 30624 80055224 0200102D */  daddu     $v0, $s0, $zero
.L80055228:
/* 30628 80055228 8FBF001C */  lw        $ra, 0x1c($sp)
/* 3062C 8005522C 8FB20018 */  lw        $s2, 0x18($sp)
/* 30630 80055230 8FB10014 */  lw        $s1, 0x14($sp)
/* 30634 80055234 8FB00010 */  lw        $s0, 0x10($sp)
/* 30638 80055238 03E00008 */  jr        $ra
/* 3063C 8005523C 27BD0020 */   addiu    $sp, $sp, 0x20
