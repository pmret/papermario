.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003C098
/* 17498 8003C098 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1749C 8003C09C AFB00010 */  sw        $s0, 0x10($sp)
/* 174A0 8003C0A0 0080802D */  daddu     $s0, $a0, $zero
/* 174A4 8003C0A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 174A8 8003C0A8 00A0882D */  daddu     $s1, $a1, $zero
/* 174AC 8003C0AC AFB20018 */  sw        $s2, 0x18($sp)
/* 174B0 8003C0B0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 174B4 8003C0B4 0C00F07F */  jal       func_8003C1FC
/* 174B8 8003C0B8 00C0902D */   daddu    $s2, $a2, $zero
/* 174BC 8003C0BC 02118021 */  addu      $s0, $s0, $s1
/* 174C0 8003C0C0 24020001 */  addiu     $v0, $zero, 1
/* 174C4 8003C0C4 A212032C */  sb        $s2, 0x32c($s0)
/* 174C8 8003C0C8 A202032E */  sb        $v0, 0x32e($s0)
/* 174CC 8003C0CC A2000330 */  sb        $zero, 0x330($s0)
/* 174D0 8003C0D0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 174D4 8003C0D4 8FB20018 */  lw        $s2, 0x18($sp)
/* 174D8 8003C0D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 174DC 8003C0DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 174E0 8003C0E0 03E00008 */  jr        $ra
/* 174E4 8003C0E4 27BD0020 */   addiu    $sp, $sp, 0x20
