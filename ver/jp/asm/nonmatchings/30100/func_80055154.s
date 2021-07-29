.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055154
/* 30554 80055154 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30558 80055158 AFB10014 */  sw        $s1, 0x14($sp)
/* 3055C 8005515C 0080882D */  daddu     $s1, $a0, $zero
/* 30560 80055160 AFBF0018 */  sw        $ra, 0x18($sp)
/* 30564 80055164 0C014238 */  jal       func_800508E0
/* 30568 80055168 AFB00010 */   sw       $s0, 0x10($sp)
/* 3056C 8005516C 0040802D */  daddu     $s0, $v0, $zero
/* 30570 80055170 16000004 */  bnez      $s0, .L80055184
/* 30574 80055174 0200102D */   daddu    $v0, $s0, $zero
/* 30578 80055178 0C0142E8 */  jal       func_80050BA0
/* 3057C 8005517C 0220202D */   daddu    $a0, $s1, $zero
/* 30580 80055180 0200102D */  daddu     $v0, $s0, $zero
.L80055184:
/* 30584 80055184 8FBF0018 */  lw        $ra, 0x18($sp)
/* 30588 80055188 8FB10014 */  lw        $s1, 0x14($sp)
/* 3058C 8005518C 8FB00010 */  lw        $s0, 0x10($sp)
/* 30590 80055190 03E00008 */  jr        $ra
/* 30594 80055194 27BD0020 */   addiu    $sp, $sp, 0x20
