.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238B3C_70462C
/* 70462C 80238B3C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 704630 80238B40 AFB1001C */  sw        $s1, 0x1c($sp)
/* 704634 80238B44 0080882D */  daddu     $s1, $a0, $zero
/* 704638 80238B48 AFBF0024 */  sw        $ra, 0x24($sp)
/* 70463C 80238B4C AFB20020 */  sw        $s2, 0x20($sp)
/* 704640 80238B50 AFB00018 */  sw        $s0, 0x18($sp)
/* 704644 80238B54 8E30000C */  lw        $s0, 0xc($s1)
/* 704648 80238B58 8E050000 */  lw        $a1, ($s0)
/* 70464C 80238B5C 0C0B1EAF */  jal       get_variable
/* 704650 80238B60 26100004 */   addiu    $s0, $s0, 4
/* 704654 80238B64 8E050000 */  lw        $a1, ($s0)
/* 704658 80238B68 26100004 */  addiu     $s0, $s0, 4
/* 70465C 80238B6C 0220202D */  daddu     $a0, $s1, $zero
/* 704660 80238B70 0C0B1EAF */  jal       get_variable
/* 704664 80238B74 0040902D */   daddu    $s2, $v0, $zero
/* 704668 80238B78 0220202D */  daddu     $a0, $s1, $zero
/* 70466C 80238B7C 8E050000 */  lw        $a1, ($s0)
/* 704670 80238B80 0C0B1EAF */  jal       get_variable
/* 704674 80238B84 0040802D */   daddu    $s0, $v0, $zero
/* 704678 80238B88 0000202D */  daddu     $a0, $zero, $zero
/* 70467C 80238B8C 44921000 */  mtc1      $s2, $f2
/* 704680 80238B90 00000000 */  nop
/* 704684 80238B94 468010A0 */  cvt.s.w   $f2, $f2
/* 704688 80238B98 44051000 */  mfc1      $a1, $f2
/* 70468C 80238B9C 44901000 */  mtc1      $s0, $f2
/* 704690 80238BA0 00000000 */  nop
/* 704694 80238BA4 468010A0 */  cvt.s.w   $f2, $f2
/* 704698 80238BA8 44061000 */  mfc1      $a2, $f2
/* 70469C 80238BAC 44821000 */  mtc1      $v0, $f2
/* 7046A0 80238BB0 00000000 */  nop
/* 7046A4 80238BB4 468010A0 */  cvt.s.w   $f2, $f2
/* 7046A8 80238BB8 3C013F80 */  lui       $at, 0x3f80
/* 7046AC 80238BBC 44810000 */  mtc1      $at, $f0
/* 7046B0 80238BC0 44071000 */  mfc1      $a3, $f2
/* 7046B4 80238BC4 2403003C */  addiu     $v1, $zero, 0x3c
/* 7046B8 80238BC8 AFA30014 */  sw        $v1, 0x14($sp)
/* 7046BC 80238BCC 0C01C664 */  jal       playFX_58
/* 7046C0 80238BD0 E7A00010 */   swc1     $f0, 0x10($sp)
/* 7046C4 80238BD4 0040182D */  daddu     $v1, $v0, $zero
/* 7046C8 80238BD8 8C64000C */  lw        $a0, 0xc($v1)
/* 7046CC 80238BDC 24020002 */  addiu     $v0, $zero, 2
/* 7046D0 80238BE0 3C018024 */  lui       $at, %hi(D_8023C1B4)
/* 7046D4 80238BE4 AC23C1B4 */  sw        $v1, %lo(D_8023C1B4)($at)
/* 7046D8 80238BE8 0040182D */  daddu     $v1, $v0, $zero
/* 7046DC 80238BEC AC830030 */  sw        $v1, 0x30($a0)
/* 7046E0 80238BF0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 7046E4 80238BF4 8FB20020 */  lw        $s2, 0x20($sp)
/* 7046E8 80238BF8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7046EC 80238BFC 8FB00018 */  lw        $s0, 0x18($sp)
/* 7046F0 80238C00 03E00008 */  jr        $ra
/* 7046F4 80238C04 27BD0028 */   addiu    $sp, $sp, 0x28
