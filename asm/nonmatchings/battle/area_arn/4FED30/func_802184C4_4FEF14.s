.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802184C4_4FEF14
/* 4FEF14 802184C4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4FEF18 802184C8 AFB40020 */  sw        $s4, 0x20($sp)
/* 4FEF1C 802184CC 0080A02D */  daddu     $s4, $a0, $zero
/* 4FEF20 802184D0 AFBF0024 */  sw        $ra, 0x24($sp)
/* 4FEF24 802184D4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4FEF28 802184D8 AFB20018 */  sw        $s2, 0x18($sp)
/* 4FEF2C 802184DC AFB10014 */  sw        $s1, 0x14($sp)
/* 4FEF30 802184E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 4FEF34 802184E4 8E92000C */  lw        $s2, 0xc($s4)
/* 4FEF38 802184E8 8E450000 */  lw        $a1, ($s2)
/* 4FEF3C 802184EC 0C0B1EAF */  jal       get_variable
/* 4FEF40 802184F0 26520004 */   addiu    $s2, $s2, 4
/* 4FEF44 802184F4 8E450000 */  lw        $a1, ($s2)
/* 4FEF48 802184F8 26520004 */  addiu     $s2, $s2, 4
/* 4FEF4C 802184FC 0280202D */  daddu     $a0, $s4, $zero
/* 4FEF50 80218500 0C0B1EAF */  jal       get_variable
/* 4FEF54 80218504 0040802D */   daddu    $s0, $v0, $zero
/* 4FEF58 80218508 8E450000 */  lw        $a1, ($s2)
/* 4FEF5C 8021850C 26520004 */  addiu     $s2, $s2, 4
/* 4FEF60 80218510 0280202D */  daddu     $a0, $s4, $zero
/* 4FEF64 80218514 0C0B1EAF */  jal       get_variable
/* 4FEF68 80218518 0040882D */   daddu    $s1, $v0, $zero
/* 4FEF6C 8021851C 0040982D */  daddu     $s3, $v0, $zero
/* 4FEF70 80218520 8E450000 */  lw        $a1, ($s2)
/* 4FEF74 80218524 26520004 */  addiu     $s2, $s2, 4
/* 4FEF78 80218528 0280202D */  daddu     $a0, $s4, $zero
/* 4FEF7C 8021852C 0C0B1EAF */  jal       get_variable
/* 4FEF80 80218530 02709823 */   subu     $s3, $s3, $s0
/* 4FEF84 80218534 0040802D */  daddu     $s0, $v0, $zero
/* 4FEF88 80218538 0280202D */  daddu     $a0, $s4, $zero
/* 4FEF8C 8021853C 8E450000 */  lw        $a1, ($s2)
/* 4FEF90 80218540 0C0B1EAF */  jal       get_variable
/* 4FEF94 80218544 02118023 */   subu     $s0, $s0, $s1
/* 4FEF98 80218548 16600006 */  bnez      $s3, .L80218564
/* 4FEF9C 8021854C 00000000 */   nop      
/* 4FEFA0 80218550 16000004 */  bnez      $s0, .L80218564
/* 4FEFA4 80218554 0280202D */   daddu    $a0, $s4, $zero
/* 4FEFA8 80218558 8E450000 */  lw        $a1, ($s2)
/* 4FEFAC 8021855C 08086163 */  j         .L8021858C
/* 4FEFB0 80218560 0040302D */   daddu    $a2, $v0, $zero
.L80218564:
/* 4FEFB4 80218564 44936000 */  mtc1      $s3, $f12
/* 4FEFB8 80218568 00000000 */  nop       
/* 4FEFBC 8021856C 46806320 */  cvt.s.w   $f12, $f12
/* 4FEFC0 80218570 44907000 */  mtc1      $s0, $f14
/* 4FEFC4 80218574 00000000 */  nop       
/* 4FEFC8 80218578 0C0860CE */  jal       func_80218338_4FED88
/* 4FEFCC 8021857C 468073A0 */   cvt.s.w  $f14, $f14
/* 4FEFD0 80218580 0280202D */  daddu     $a0, $s4, $zero
/* 4FEFD4 80218584 8E450000 */  lw        $a1, ($s2)
/* 4FEFD8 80218588 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L8021858C:
/* 4FEFDC 8021858C 0C0B2026 */  jal       set_variable
/* 4FEFE0 80218590 00000000 */   nop      
/* 4FEFE4 80218594 24020002 */  addiu     $v0, $zero, 2
/* 4FEFE8 80218598 8FBF0024 */  lw        $ra, 0x24($sp)
/* 4FEFEC 8021859C 8FB40020 */  lw        $s4, 0x20($sp)
/* 4FEFF0 802185A0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4FEFF4 802185A4 8FB20018 */  lw        $s2, 0x18($sp)
/* 4FEFF8 802185A8 8FB10014 */  lw        $s1, 0x14($sp)
/* 4FEFFC 802185AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 4FF000 802185B0 03E00008 */  jr        $ra
/* 4FF004 802185B4 27BD0028 */   addiu    $sp, $sp, 0x28
/* 4FF008 802185B8 00000000 */  nop       
/* 4FF00C 802185BC 00000000 */  nop       
