.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80281C20
/* 7E2AA0 80281C20 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E2AA4 80281C24 AFB10014 */  sw        $s1, 0x14($sp)
/* 7E2AA8 80281C28 0080882D */  daddu     $s1, $a0, $zero
/* 7E2AAC 80281C2C AFBF0018 */  sw        $ra, 0x18($sp)
/* 7E2AB0 80281C30 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E2AB4 80281C34 8E30000C */  lw        $s0, 0xc($s1)
/* 7E2AB8 80281C38 8E050000 */  lw        $a1, ($s0)
/* 7E2ABC 80281C3C 0C0B1EAF */  jal       get_variable
/* 7E2AC0 80281C40 26100004 */   addiu    $s0, $s0, 4
/* 7E2AC4 80281C44 0220202D */  daddu     $a0, $s1, $zero
/* 7E2AC8 80281C48 8E050000 */  lw        $a1, ($s0)
/* 7E2ACC 80281C4C 0C0B1EAF */  jal       get_variable
/* 7E2AD0 80281C50 0040802D */   daddu    $s0, $v0, $zero
/* 7E2AD4 80281C54 0200202D */  daddu     $a0, $s0, $zero
/* 7E2AD8 80281C58 0C03BD05 */  jal       func_800EF414
/* 7E2ADC 80281C5C 0040282D */   daddu    $a1, $v0, $zero
/* 7E2AE0 80281C60 44806000 */  mtc1      $zero, $f12
/* 7E2AE4 80281C64 0C03BCE5 */  jal       func_800EF394
/* 7E2AE8 80281C68 00000000 */   nop      
/* 7E2AEC 80281C6C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7E2AF0 80281C70 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E2AF4 80281C74 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E2AF8 80281C78 24020002 */  addiu     $v0, $zero, 2
/* 7E2AFC 80281C7C 03E00008 */  jr        $ra
/* 7E2B00 80281C80 27BD0020 */   addiu    $sp, $sp, 0x20
