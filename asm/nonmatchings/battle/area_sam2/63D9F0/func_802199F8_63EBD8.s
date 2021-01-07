.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802199F8_63EBD8
/* 63EBD8 802199F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 63EBDC 802199FC 0000202D */  daddu     $a0, $zero, $zero
/* 63EBE0 80219A00 AFBF0010 */  sw        $ra, 0x10($sp)
/* 63EBE4 80219A04 0C01C49C */  jal       func_80071270
/* 63EBE8 80219A08 24050010 */   addiu    $a1, $zero, 0x10
/* 63EBEC 80219A0C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 63EBF0 80219A10 24020002 */  addiu     $v0, $zero, 2
/* 63EBF4 80219A14 03E00008 */  jr        $ra
/* 63EBF8 80219A18 27BD0018 */   addiu    $sp, $sp, 0x18
