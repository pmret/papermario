.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80058C38
/* 34038 80058C38 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3403C 80058C3C AFB10014 */  sw        $s1, 0x14($sp)
/* 34040 80058C40 0080882D */  daddu     $s1, $a0, $zero
/* 34044 80058C44 AFB00010 */  sw        $s0, 0x10($sp)
/* 34048 80058C48 00A0802D */  daddu     $s0, $a1, $zero
/* 3404C 80058C4C 0200202D */  daddu     $a0, $s0, $zero
/* 34050 80058C50 24051420 */  addiu     $a1, $zero, 0x1420
/* 34054 80058C54 AFBF0018 */  sw        $ra, 0x18($sp)
/* 34058 80058C58 0C015F10 */  jal       func_80057C40
/* 3405C 80058C5C 24060002 */   addiu    $a2, $zero, 2
/* 34060 80058C60 0200202D */  daddu     $a0, $s0, $zero
/* 34064 80058C64 24050001 */  addiu     $a1, $zero, 1
/* 34068 80058C68 24060030 */  addiu     $a2, $zero, 0x30
/* 3406C 80058C6C 0C015F10 */  jal       func_80057C40
/* 34070 80058C70 AE220000 */   sw       $v0, ($s1)
/* 34074 80058C74 0200202D */  daddu     $a0, $s0, $zero
/* 34078 80058C78 24050001 */  addiu     $a1, $zero, 1
/* 3407C 80058C7C 24060008 */  addiu     $a2, $zero, 8
/* 34080 80058C80 0C015F10 */  jal       func_80057C40
/* 34084 80058C84 AE220010 */   sw       $v0, 0x10($s1)
/* 34088 80058C88 0220202D */  daddu     $a0, $s1, $zero
/* 3408C 80058C8C 0000282D */  daddu     $a1, $zero, $zero
/* 34090 80058C90 00A0302D */  daddu     $a2, $a1, $zero
/* 34094 80058C94 8C830010 */  lw        $v1, 0x10($a0)
/* 34098 80058C98 24075000 */  addiu     $a3, $zero, 0x5000
/* 3409C 80058C9C 0C01632E */  jal       func_80058CB8
/* 340A0 80058CA0 AC620028 */   sw       $v0, 0x28($v1)
/* 340A4 80058CA4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 340A8 80058CA8 8FB10014 */  lw        $s1, 0x14($sp)
/* 340AC 80058CAC 8FB00010 */  lw        $s0, 0x10($sp)
/* 340B0 80058CB0 03E00008 */  jr        $ra
/* 340B4 80058CB4 27BD0020 */   addiu    $sp, $sp, 0x20
