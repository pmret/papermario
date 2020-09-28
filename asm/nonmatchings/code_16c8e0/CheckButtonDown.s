.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel CheckButtonDown
/* 19C9E8 8026E108 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19C9EC 8026E10C AFBF0010 */  sw        $ra, 0x10($sp)
/* 19C9F0 8026E110 8C82000C */  lw        $v0, 0xc($a0)
/* 19C9F4 8026E114 3C06800E */  lui       $a2, 0x800e
/* 19C9F8 8026E118 8CC6C280 */  lw        $a2, -0x3d80($a2)
/* 19C9FC 8026E11C 8C430000 */  lw        $v1, ($v0)
/* 19CA00 8026E120 8C450004 */  lw        $a1, 4($v0)
/* 19CA04 8026E124 00C33024 */  and       $a2, $a2, $v1
/* 19CA08 8026E128 0C0B2026 */  jal       set_variable
/* 19CA0C 8026E12C 0006302B */   sltu     $a2, $zero, $a2
/* 19CA10 8026E130 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19CA14 8026E134 24020002 */  addiu     $v0, $zero, 2
/* 19CA18 8026E138 03E00008 */  jr        $ra
/* 19CA1C 8026E13C 27BD0018 */   addiu    $sp, $sp, 0x18
