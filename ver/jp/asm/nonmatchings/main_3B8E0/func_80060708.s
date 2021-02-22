.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060708
/* 3BB08 80060708 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3BB0C 8006070C AFBF0014 */  sw        $ra, 0x14($sp)
/* 3BB10 80060710 AFB00010 */  sw        $s0, 0x10($sp)
/* 3BB14 80060714 8C90000C */  lw        $s0, 0xc($a0)
/* 3BB18 80060718 3C04800E */  lui       $a0, %hi(D_800DAC58)
/* 3BB1C 8006071C 2484AC58 */  addiu     $a0, $a0, %lo(D_800DAC58)
/* 3BB20 80060720 0C01865C */  jal       func_80061970
/* 3BB24 80060724 00000000 */   nop
/* 3BB28 80060728 14400012 */  bnez      $v0, .L80060774
/* 3BB2C 8006072C 0000282D */   daddu    $a1, $zero, $zero
/* 3BB30 80060730 3C04800E */  lui       $a0, %hi(D_800DAC58)
/* 3BB34 80060734 2484AC58 */  addiu     $a0, $a0, %lo(D_800DAC58)
/* 3BB38 80060738 0C0195B0 */  jal       func_800656C0
/* 3BB3C 8006073C 24060001 */   addiu    $a2, $zero, 1
/* 3BB40 80060740 3C04800E */  lui       $a0, %hi(D_800DC020)
/* 3BB44 80060744 2484C020 */  addiu     $a0, $a0, %lo(D_800DC020)
/* 3BB48 80060748 0000282D */  daddu     $a1, $zero, $zero
/* 3BB4C 8006074C 0C0195FC */  jal       func_800657F0
/* 3BB50 80060750 24060001 */   addiu    $a2, $zero, 1
/* 3BB54 80060754 0C01867E */  jal       func_800619F8
/* 3BB58 80060758 0200202D */   daddu    $a0, $s0, $zero
/* 3BB5C 8006075C 3C04800E */  lui       $a0, %hi(D_800DC020)
/* 3BB60 80060760 2484C020 */  addiu     $a0, $a0, %lo(D_800DC020)
/* 3BB64 80060764 0000282D */  daddu     $a1, $zero, $zero
/* 3BB68 80060768 0C0195B0 */  jal       func_800656C0
/* 3BB6C 8006076C 24060001 */   addiu    $a2, $zero, 1
/* 3BB70 80060770 0000102D */  daddu     $v0, $zero, $zero
.L80060774:
/* 3BB74 80060774 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3BB78 80060778 8FB00010 */  lw        $s0, 0x10($sp)
/* 3BB7C 8006077C 03E00008 */  jr        $ra
/* 3BB80 80060780 27BD0018 */   addiu    $sp, $sp, 0x18
