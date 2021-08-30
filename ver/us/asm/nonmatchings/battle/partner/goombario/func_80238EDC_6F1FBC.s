.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238EDC_6F1FBC
/* 6F1FBC 80238EDC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 6F1FC0 80238EE0 AFB30024 */  sw        $s3, 0x24($sp)
/* 6F1FC4 80238EE4 0080982D */  daddu     $s3, $a0, $zero
/* 6F1FC8 80238EE8 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 6F1FCC 80238EEC 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 6F1FD0 80238EF0 AFBF0028 */  sw        $ra, 0x28($sp)
/* 6F1FD4 80238EF4 AFB20020 */  sw        $s2, 0x20($sp)
/* 6F1FD8 80238EF8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 6F1FDC 80238EFC AFB00018 */  sw        $s0, 0x18($sp)
/* 6F1FE0 80238F00 8E71000C */  lw        $s1, 0xc($s3)
/* 6F1FE4 80238F04 8C6400DC */  lw        $a0, 0xdc($v1)
/* 6F1FE8 80238F08 3C058024 */  lui       $a1, %hi(D_8023CDA4)
/* 6F1FEC 80238F0C 24A5CDA4 */  addiu     $a1, $a1, %lo(D_8023CDA4)
/* 6F1FF0 80238F10 ACA00000 */  sw        $zero, ($a1)
/* 6F1FF4 80238F14 80820220 */  lb        $v0, 0x220($a0)
/* 6F1FF8 80238F18 18400002 */  blez      $v0, .L80238F24
/* 6F1FFC 80238F1C 24020001 */   addiu    $v0, $zero, 1
/* 6F2000 80238F20 ACA20000 */  sw        $v0, ($a1)
.L80238F24:
/* 6F2004 80238F24 8463017C */  lh        $v1, 0x17c($v1)
/* 6F2008 80238F28 24020087 */  addiu     $v0, $zero, 0x87
/* 6F200C 80238F2C 1062000B */  beq       $v1, $v0, .L80238F5C
/* 6F2010 80238F30 0000902D */   daddu    $s2, $zero, $zero
/* 6F2014 80238F34 28620088 */  slti      $v0, $v1, 0x88
/* 6F2018 80238F38 10400005 */  beqz      $v0, .L80238F50
/* 6F201C 80238F3C 24020086 */   addiu    $v0, $zero, 0x86
/* 6F2020 80238F40 10620006 */  beq       $v1, $v0, .L80238F5C
/* 6F2024 80238F44 00000000 */   nop
/* 6F2028 80238F48 0808E3E1 */  j         .L80238F84
/* 6F202C 80238F4C 00000000 */   nop
.L80238F50:
/* 6F2030 80238F50 24020088 */  addiu     $v0, $zero, 0x88
/* 6F2034 80238F54 1462000B */  bne       $v1, $v0, .L80238F84
/* 6F2038 80238F58 00000000 */   nop
.L80238F5C:
/* 6F203C 80238F5C 90820220 */  lbu       $v0, 0x220($a0)
/* 6F2040 80238F60 24420002 */  addiu     $v0, $v0, 2
/* 6F2044 80238F64 A0820220 */  sb        $v0, 0x220($a0)
/* 6F2048 80238F68 00021600 */  sll       $v0, $v0, 0x18
/* 6F204C 80238F6C 00021603 */  sra       $v0, $v0, 0x18
/* 6F2050 80238F70 28420063 */  slti      $v0, $v0, 0x63
/* 6F2054 80238F74 14400003 */  bnez      $v0, .L80238F84
/* 6F2058 80238F78 24120001 */   addiu    $s2, $zero, 1
/* 6F205C 80238F7C 24020063 */  addiu     $v0, $zero, 0x63
/* 6F2060 80238F80 A0820220 */  sb        $v0, 0x220($a0)
.L80238F84:
/* 6F2064 80238F84 8E250000 */  lw        $a1, ($s1)
/* 6F2068 80238F88 26310004 */  addiu     $s1, $s1, 4
/* 6F206C 80238F8C 0C0B1EAF */  jal       evt_get_variable
/* 6F2070 80238F90 0260202D */   daddu    $a0, $s3, $zero
/* 6F2074 80238F94 8E250000 */  lw        $a1, ($s1)
/* 6F2078 80238F98 26310004 */  addiu     $s1, $s1, 4
/* 6F207C 80238F9C 0260202D */  daddu     $a0, $s3, $zero
/* 6F2080 80238FA0 0C0B1EAF */  jal       evt_get_variable
/* 6F2084 80238FA4 0040802D */   daddu    $s0, $v0, $zero
/* 6F2088 80238FA8 0260202D */  daddu     $a0, $s3, $zero
/* 6F208C 80238FAC 8E250000 */  lw        $a1, ($s1)
/* 6F2090 80238FB0 0C0B1EAF */  jal       evt_get_variable
/* 6F2094 80238FB4 0040882D */   daddu    $s1, $v0, $zero
/* 6F2098 80238FB8 0240202D */  daddu     $a0, $s2, $zero
/* 6F209C 80238FBC 44901000 */  mtc1      $s0, $f2
/* 6F20A0 80238FC0 00000000 */  nop
/* 6F20A4 80238FC4 468010A0 */  cvt.s.w   $f2, $f2
/* 6F20A8 80238FC8 44051000 */  mfc1      $a1, $f2
/* 6F20AC 80238FCC 44911000 */  mtc1      $s1, $f2
/* 6F20B0 80238FD0 00000000 */  nop
/* 6F20B4 80238FD4 468010A0 */  cvt.s.w   $f2, $f2
/* 6F20B8 80238FD8 44061000 */  mfc1      $a2, $f2
/* 6F20BC 80238FDC 44821000 */  mtc1      $v0, $f2
/* 6F20C0 80238FE0 00000000 */  nop
/* 6F20C4 80238FE4 468010A0 */  cvt.s.w   $f2, $f2
/* 6F20C8 80238FE8 3C013F80 */  lui       $at, 0x3f80
/* 6F20CC 80238FEC 44810000 */  mtc1      $at, $f0
/* 6F20D0 80238FF0 44071000 */  mfc1      $a3, $f2
/* 6F20D4 80238FF4 2403003C */  addiu     $v1, $zero, 0x3c
/* 6F20D8 80238FF8 AFA30014 */  sw        $v1, 0x14($sp)
/* 6F20DC 80238FFC 0C01C634 */  jal       playFX_56
/* 6F20E0 80239000 E7A00010 */   swc1     $f0, 0x10($sp)
/* 6F20E4 80239004 3C05800E */  lui       $a1, %hi(gBattleStatus)
/* 6F20E8 80239008 24A5C070 */  addiu     $a1, $a1, %lo(gBattleStatus)
/* 6F20EC 8023900C 8CA30000 */  lw        $v1, ($a1)
/* 6F20F0 80239010 3C044000 */  lui       $a0, 0x4000
/* 6F20F4 80239014 00641825 */  or        $v1, $v1, $a0
/* 6F20F8 80239018 ACA30000 */  sw        $v1, ($a1)
/* 6F20FC 8023901C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 6F2100 80239020 8FB30024 */  lw        $s3, 0x24($sp)
/* 6F2104 80239024 8FB20020 */  lw        $s2, 0x20($sp)
/* 6F2108 80239028 8FB1001C */  lw        $s1, 0x1c($sp)
/* 6F210C 8023902C 8FB00018 */  lw        $s0, 0x18($sp)
/* 6F2110 80239030 24020002 */  addiu     $v0, $zero, 2
/* 6F2114 80239034 03E00008 */  jr        $ra
/* 6F2118 80239038 27BD0030 */   addiu    $sp, $sp, 0x30
