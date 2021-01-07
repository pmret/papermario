.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021860C_5ECA9C
/* 5ECA9C 8021860C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5ECAA0 80218610 AFB40020 */  sw        $s4, 0x20($sp)
/* 5ECAA4 80218614 0080A02D */  daddu     $s4, $a0, $zero
/* 5ECAA8 80218618 AFBF0024 */  sw        $ra, 0x24($sp)
/* 5ECAAC 8021861C AFB3001C */  sw        $s3, 0x1c($sp)
/* 5ECAB0 80218620 AFB20018 */  sw        $s2, 0x18($sp)
/* 5ECAB4 80218624 AFB10014 */  sw        $s1, 0x14($sp)
/* 5ECAB8 80218628 AFB00010 */  sw        $s0, 0x10($sp)
/* 5ECABC 8021862C 8E92000C */  lw        $s2, 0xc($s4)
/* 5ECAC0 80218630 8E450000 */  lw        $a1, ($s2)
/* 5ECAC4 80218634 0C0B1EAF */  jal       get_variable
/* 5ECAC8 80218638 26520004 */   addiu    $s2, $s2, 4
/* 5ECACC 8021863C 8E450000 */  lw        $a1, ($s2)
/* 5ECAD0 80218640 26520004 */  addiu     $s2, $s2, 4
/* 5ECAD4 80218644 0280202D */  daddu     $a0, $s4, $zero
/* 5ECAD8 80218648 0C0B1EAF */  jal       get_variable
/* 5ECADC 8021864C 0040802D */   daddu    $s0, $v0, $zero
/* 5ECAE0 80218650 8E450000 */  lw        $a1, ($s2)
/* 5ECAE4 80218654 26520004 */  addiu     $s2, $s2, 4
/* 5ECAE8 80218658 0280202D */  daddu     $a0, $s4, $zero
/* 5ECAEC 8021865C 0C0B1EAF */  jal       get_variable
/* 5ECAF0 80218660 0040882D */   daddu    $s1, $v0, $zero
/* 5ECAF4 80218664 0040982D */  daddu     $s3, $v0, $zero
/* 5ECAF8 80218668 8E450000 */  lw        $a1, ($s2)
/* 5ECAFC 8021866C 26520004 */  addiu     $s2, $s2, 4
/* 5ECB00 80218670 0280202D */  daddu     $a0, $s4, $zero
/* 5ECB04 80218674 0C0B1EAF */  jal       get_variable
/* 5ECB08 80218678 02709823 */   subu     $s3, $s3, $s0
/* 5ECB0C 8021867C 0040802D */  daddu     $s0, $v0, $zero
/* 5ECB10 80218680 0280202D */  daddu     $a0, $s4, $zero
/* 5ECB14 80218684 8E450000 */  lw        $a1, ($s2)
/* 5ECB18 80218688 0C0B1EAF */  jal       get_variable
/* 5ECB1C 8021868C 02118023 */   subu     $s0, $s0, $s1
/* 5ECB20 80218690 16600006 */  bnez      $s3, .L802186AC
/* 5ECB24 80218694 00000000 */   nop      
/* 5ECB28 80218698 16000004 */  bnez      $s0, .L802186AC
/* 5ECB2C 8021869C 0280202D */   daddu    $a0, $s4, $zero
/* 5ECB30 802186A0 8E450000 */  lw        $a1, ($s2)
/* 5ECB34 802186A4 080861B5 */  j         .L802186D4
/* 5ECB38 802186A8 0040302D */   daddu    $a2, $v0, $zero
.L802186AC:
/* 5ECB3C 802186AC 44936000 */  mtc1      $s3, $f12
/* 5ECB40 802186B0 00000000 */  nop       
/* 5ECB44 802186B4 46806320 */  cvt.s.w   $f12, $f12
/* 5ECB48 802186B8 44907000 */  mtc1      $s0, $f14
/* 5ECB4C 802186BC 00000000 */  nop       
/* 5ECB50 802186C0 0C086120 */  jal       func_80218480_5EC910
/* 5ECB54 802186C4 468073A0 */   cvt.s.w  $f14, $f14
/* 5ECB58 802186C8 0280202D */  daddu     $a0, $s4, $zero
/* 5ECB5C 802186CC 8E450000 */  lw        $a1, ($s2)
/* 5ECB60 802186D0 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L802186D4:
/* 5ECB64 802186D4 0C0B2026 */  jal       set_variable
/* 5ECB68 802186D8 00000000 */   nop      
/* 5ECB6C 802186DC 24020002 */  addiu     $v0, $zero, 2
/* 5ECB70 802186E0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 5ECB74 802186E4 8FB40020 */  lw        $s4, 0x20($sp)
/* 5ECB78 802186E8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5ECB7C 802186EC 8FB20018 */  lw        $s2, 0x18($sp)
/* 5ECB80 802186F0 8FB10014 */  lw        $s1, 0x14($sp)
/* 5ECB84 802186F4 8FB00010 */  lw        $s0, 0x10($sp)
/* 5ECB88 802186F8 03E00008 */  jr        $ra
/* 5ECB8C 802186FC 27BD0028 */   addiu    $sp, $sp, 0x28
