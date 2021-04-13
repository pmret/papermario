.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800473A0
/* 227A0 800473A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 227A4 800473A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 227A8 800473A8 0080802D */  daddu     $s0, $a0, $zero
/* 227AC 800473AC 00101040 */  sll       $v0, $s0, 1
/* 227B0 800473B0 00501021 */  addu      $v0, $v0, $s0
/* 227B4 800473B4 00021080 */  sll       $v0, $v0, 2
/* 227B8 800473B8 00501023 */  subu      $v0, $v0, $s0
/* 227BC 800473BC AFB10014 */  sw        $s1, 0x14($sp)
/* 227C0 800473C0 3C11800A */  lui       $s1, %hi(D_8009ED54)
/* 227C4 800473C4 8E31ED54 */  lw        $s1, %lo(D_8009ED54)($s1)
/* 227C8 800473C8 00021100 */  sll       $v0, $v0, 4
/* 227CC 800473CC AFBF0018 */  sw        $ra, 0x18($sp)
/* 227D0 800473D0 0C011D51 */  jal       func_80047544
/* 227D4 800473D4 02228821 */   addu     $s1, $s1, $v0
/* 227D8 800473D8 0C011D93 */  jal       func_8004764C
/* 227DC 800473DC 0200202D */   daddu    $a0, $s0, $zero
/* 227E0 800473E0 0C011DD5 */  jal       func_80047754
/* 227E4 800473E4 0200202D */   daddu    $a0, $s0, $zero
/* 227E8 800473E8 0C011E0C */  jal       func_80047830
/* 227EC 800473EC 0200202D */   daddu    $a0, $s0, $zero
/* 227F0 800473F0 0C011E54 */  jal       func_80047950
/* 227F4 800473F4 0200202D */   daddu    $a0, $s0, $zero
/* 227F8 800473F8 0C011E9B */  jal       func_80047A6C
/* 227FC 800473FC 0200202D */   daddu    $a0, $s0, $zero
/* 22800 80047400 0C011EE2 */  jal       func_80047B88
/* 22804 80047404 0200202D */   daddu    $a0, $s0, $zero
/* 22808 80047408 0C011F25 */  jal       func_80047C94
/* 2280C 8004740C 0200202D */   daddu    $a0, $s0, $zero
/* 22810 80047410 0C011F68 */  jal       func_80047DA0
/* 22814 80047414 0200202D */   daddu    $a0, $s0, $zero
/* 22818 80047418 0C011FAB */  jal       func_80047EAC
/* 2281C 8004741C 0200202D */   daddu    $a0, $s0, $zero
/* 22820 80047420 AE200000 */  sw        $zero, ($s1)
/* 22824 80047424 8FBF0018 */  lw        $ra, 0x18($sp)
/* 22828 80047428 8FB10014 */  lw        $s1, 0x14($sp)
/* 2282C 8004742C 8FB00010 */  lw        $s0, 0x10($sp)
/* 22830 80047430 03E00008 */  jr        $ra
/* 22834 80047434 27BD0020 */   addiu    $sp, $sp, 0x20
