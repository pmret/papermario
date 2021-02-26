.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80065D40
/* 41140 80065D40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41144 80065D44 24020001 */  addiu     $v0, $zero, 1
/* 41148 80065D48 AFB00010 */  sw        $s0, 0x10($sp)
/* 4114C 80065D4C 3C10800E */  lui       $s0, %hi(D_800DAC88)
/* 41150 80065D50 2610AC88 */  addiu     $s0, $s0, %lo(D_800DAC88)
/* 41154 80065D54 02002021 */  addu      $a0, $s0, $zero
/* 41158 80065D58 3C05800B */  lui       $a1, %hi(D_800AF8E0)
/* 4115C 80065D5C 24A5F8E0 */  addiu     $a1, $a1, %lo(D_800AF8E0)
/* 41160 80065D60 AFBF0014 */  sw        $ra, 0x14($sp)
/* 41164 80065D64 3C018009 */  lui       $at, %hi(D_80094620)
/* 41168 80065D68 AC224620 */  sw        $v0, %lo(D_80094620)($at)
/* 4116C 80065D6C 0C019554 */  jal       func_80065550
/* 41170 80065D70 24060001 */   addiu    $a2, $zero, 1
/* 41174 80065D74 02002021 */  addu      $a0, $s0, $zero
/* 41178 80065D78 00002821 */  addu      $a1, $zero, $zero
/* 4117C 80065D7C 0C0195FC */  jal       func_800657F0
/* 41180 80065D80 00003021 */   addu     $a2, $zero, $zero
/* 41184 80065D84 8FBF0014 */  lw        $ra, 0x14($sp)
/* 41188 80065D88 8FB00010 */  lw        $s0, 0x10($sp)
/* 4118C 80065D8C 03E00008 */  jr        $ra
/* 41190 80065D90 27BD0018 */   addiu    $sp, $sp, 0x18
