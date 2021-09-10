.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CDC_A1155C
/* A1155C 80240CDC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A11560 80240CE0 AFB1001C */  sw        $s1, 0x1c($sp)
/* A11564 80240CE4 0080882D */  daddu     $s1, $a0, $zero
/* A11568 80240CE8 AFBF002C */  sw        $ra, 0x2c($sp)
/* A1156C 80240CEC AFB40028 */  sw        $s4, 0x28($sp)
/* A11570 80240CF0 AFB30024 */  sw        $s3, 0x24($sp)
/* A11574 80240CF4 AFB20020 */  sw        $s2, 0x20($sp)
/* A11578 80240CF8 AFB00018 */  sw        $s0, 0x18($sp)
/* A1157C 80240CFC 8E30000C */  lw        $s0, 0xc($s1)
/* A11580 80240D00 8E050000 */  lw        $a1, ($s0)
/* A11584 80240D04 0C0B1EAF */  jal       evt_get_variable
/* A11588 80240D08 26100004 */   addiu    $s0, $s0, 4
/* A1158C 80240D0C 8E050000 */  lw        $a1, ($s0)
/* A11590 80240D10 26100004 */  addiu     $s0, $s0, 4
/* A11594 80240D14 0220202D */  daddu     $a0, $s1, $zero
/* A11598 80240D18 0C0B1EAF */  jal       evt_get_variable
/* A1159C 80240D1C 0040A02D */   daddu    $s4, $v0, $zero
/* A115A0 80240D20 8E050000 */  lw        $a1, ($s0)
/* A115A4 80240D24 26100004 */  addiu     $s0, $s0, 4
/* A115A8 80240D28 0220202D */  daddu     $a0, $s1, $zero
/* A115AC 80240D2C 0C0B1EAF */  jal       evt_get_variable
/* A115B0 80240D30 0040982D */   daddu    $s3, $v0, $zero
/* A115B4 80240D34 8E050000 */  lw        $a1, ($s0)
/* A115B8 80240D38 26100004 */  addiu     $s0, $s0, 4
/* A115BC 80240D3C 0220202D */  daddu     $a0, $s1, $zero
/* A115C0 80240D40 0C0B1EAF */  jal       evt_get_variable
/* A115C4 80240D44 0040902D */   daddu    $s2, $v0, $zero
/* A115C8 80240D48 0220202D */  daddu     $a0, $s1, $zero
/* A115CC 80240D4C 8E050000 */  lw        $a1, ($s0)
/* A115D0 80240D50 0C0B1EAF */  jal       evt_get_variable
/* A115D4 80240D54 0040802D */   daddu    $s0, $v0, $zero
/* A115D8 80240D58 0280202D */  daddu     $a0, $s4, $zero
/* A115DC 80240D5C 44931000 */  mtc1      $s3, $f2
/* A115E0 80240D60 00000000 */  nop
/* A115E4 80240D64 468010A0 */  cvt.s.w   $f2, $f2
/* A115E8 80240D68 44051000 */  mfc1      $a1, $f2
/* A115EC 80240D6C 44921000 */  mtc1      $s2, $f2
/* A115F0 80240D70 00000000 */  nop
/* A115F4 80240D74 468010A0 */  cvt.s.w   $f2, $f2
/* A115F8 80240D78 44061000 */  mfc1      $a2, $f2
/* A115FC 80240D7C 44901000 */  mtc1      $s0, $f2
/* A11600 80240D80 00000000 */  nop
/* A11604 80240D84 468010A0 */  cvt.s.w   $f2, $f2
/* A11608 80240D88 44071000 */  mfc1      $a3, $f2
/* A1160C 80240D8C 44820000 */  mtc1      $v0, $f0
/* A11610 80240D90 00000000 */  nop
/* A11614 80240D94 46800020 */  cvt.s.w   $f0, $f0
/* A11618 80240D98 0C01BFBC */  jal       playFX_11
/* A1161C 80240D9C E7A00010 */   swc1     $f0, 0x10($sp)
/* A11620 80240DA0 8FBF002C */  lw        $ra, 0x2c($sp)
/* A11624 80240DA4 8FB40028 */  lw        $s4, 0x28($sp)
/* A11628 80240DA8 8FB30024 */  lw        $s3, 0x24($sp)
/* A1162C 80240DAC 8FB20020 */  lw        $s2, 0x20($sp)
/* A11630 80240DB0 8FB1001C */  lw        $s1, 0x1c($sp)
/* A11634 80240DB4 8FB00018 */  lw        $s0, 0x18($sp)
/* A11638 80240DB8 24020002 */  addiu     $v0, $zero, 2
/* A1163C 80240DBC 03E00008 */  jr        $ra
/* A11640 80240DC0 27BD0030 */   addiu    $sp, $sp, 0x30
/* A11644 80240DC4 00000000 */  nop
/* A11648 80240DC8 00000000 */  nop
/* A1164C 80240DCC 00000000 */  nop
