.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel contReadData
/* 3BB38 80060738 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3BB3C 8006073C AFBF0014 */  sw        $ra, 0x14($sp)
/* 3BB40 80060740 AFB00010 */  sw        $s0, 0x10($sp)
/* 3BB44 80060744 8C90000C */  lw        $s0, 0xc($a0)
/* 3BB48 80060748 3C04800E */  lui       $a0, 0x800e
/* 3BB4C 8006074C 2484AC78 */  addiu     $a0, $a0, -0x5388
/* 3BB50 80060750 0C018668 */  jal       osContStartReadData
/* 3BB54 80060754 00000000 */   nop      
/* 3BB58 80060758 14400012 */  bnez      $v0, .L800607A4
/* 3BB5C 8006075C 0000282D */   daddu    $a1, $zero, $zero
/* 3BB60 80060760 3C04800E */  lui       $a0, 0x800e
/* 3BB64 80060764 2484AC78 */  addiu     $a0, $a0, -0x5388
/* 3BB68 80060768 0C0195BC */  jal       osRecvMesg
/* 3BB6C 8006076C 24060001 */   addiu    $a2, $zero, 1
/* 3BB70 80060770 3C04800E */  lui       $a0, 0x800e
/* 3BB74 80060774 2484C040 */  addiu     $a0, $a0, -0x3fc0
/* 3BB78 80060778 0000282D */  daddu     $a1, $zero, $zero
/* 3BB7C 8006077C 0C019608 */  jal       osSendMesg
/* 3BB80 80060780 24060001 */   addiu    $a2, $zero, 1
/* 3BB84 80060784 0C01868A */  jal       osContGetReadData
/* 3BB88 80060788 0200202D */   daddu    $a0, $s0, $zero
/* 3BB8C 8006078C 3C04800E */  lui       $a0, 0x800e
/* 3BB90 80060790 2484C040 */  addiu     $a0, $a0, -0x3fc0
/* 3BB94 80060794 0000282D */  daddu     $a1, $zero, $zero
/* 3BB98 80060798 0C0195BC */  jal       osRecvMesg
/* 3BB9C 8006079C 24060001 */   addiu    $a2, $zero, 1
/* 3BBA0 800607A0 0000102D */  daddu     $v0, $zero, $zero
.L800607A4:
/* 3BBA4 800607A4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3BBA8 800607A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 3BBAC 800607AC 03E00008 */  jr        $ra
/* 3BBB0 800607B0 27BD0018 */   addiu    $sp, $sp, 0x18
