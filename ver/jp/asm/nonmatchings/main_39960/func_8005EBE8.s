.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005EBE8
/* 39FE8 8005EBE8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 39FEC 8005EBEC AFB10014 */  sw        $s1, 0x14($sp)
/* 39FF0 8005EBF0 0080882D */  daddu     $s1, $a0, $zero
/* 39FF4 8005EBF4 AFB00010 */  sw        $s0, 0x10($sp)
/* 39FF8 8005EBF8 00A0802D */  daddu     $s0, $a1, $zero
/* 39FFC 8005EBFC AFBF0018 */  sw        $ra, 0x18($sp)
/* 3A000 8005EC00 0C018244 */  jal       func_80060910
/* 3A004 8005EC04 24040001 */   addiu    $a0, $zero, 1
/* 3A008 8005EC08 0040202D */  daddu     $a0, $v0, $zero
/* 3A00C 8005EC0C 0C018244 */  jal       func_80060910
/* 3A010 8005EC10 A6300008 */   sh       $s0, 8($s1)
/* 3A014 8005EC14 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3A018 8005EC18 8FB10014 */  lw        $s1, 0x14($sp)
/* 3A01C 8005EC1C 8FB00010 */  lw        $s0, 0x10($sp)
/* 3A020 8005EC20 03E00008 */  jr        $ra
/* 3A024 8005EC24 27BD0020 */   addiu    $sp, $sp, 0x20
