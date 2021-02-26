.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80044F1C
/* 2031C 80044F1C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 20320 80044F20 AFB00010 */  sw        $s0, 0x10($sp)
/* 20324 80044F24 0080802D */  daddu     $s0, $a0, $zero
/* 20328 80044F28 AFBF001C */  sw        $ra, 0x1c($sp)
/* 2032C 80044F2C AFB20018 */  sw        $s2, 0x18($sp)
/* 20330 80044F30 AFB10014 */  sw        $s1, 0x14($sp)
/* 20334 80044F34 8E11000C */  lw        $s1, 0xc($s0)
/* 20338 80044F38 8E120148 */  lw        $s2, 0x148($s0)
/* 2033C 80044F3C 8E250000 */  lw        $a1, ($s1)
/* 20340 80044F40 0C0B1EAF */  jal       func_802C7ABC
/* 20344 80044F44 26310004 */   addiu    $s1, $s1, 4
/* 20348 80044F48 0200202D */  daddu     $a0, $s0, $zero
/* 2034C 80044F4C 8E250000 */  lw        $a1, ($s1)
/* 20350 80044F50 0C0B1EAF */  jal       func_802C7ABC
/* 20354 80044F54 0040802D */   daddu    $s0, $v0, $zero
/* 20358 80044F58 00108080 */  sll       $s0, $s0, 2
/* 2035C 80044F5C 02509021 */  addu      $s2, $s2, $s0
/* 20360 80044F60 AE42006C */  sw        $v0, 0x6c($s2)
/* 20364 80044F64 8FBF001C */  lw        $ra, 0x1c($sp)
/* 20368 80044F68 8FB20018 */  lw        $s2, 0x18($sp)
/* 2036C 80044F6C 8FB10014 */  lw        $s1, 0x14($sp)
/* 20370 80044F70 8FB00010 */  lw        $s0, 0x10($sp)
/* 20374 80044F74 24020002 */  addiu     $v0, $zero, 2
/* 20378 80044F78 03E00008 */  jr        $ra
/* 2037C 80044F7C 27BD0020 */   addiu    $sp, $sp, 0x20
