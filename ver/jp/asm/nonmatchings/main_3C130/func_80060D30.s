.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060D30
/* 3C130 80060D30 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3C134 80060D34 AFB00010 */  sw        $s0, 0x10($sp)
/* 3C138 80060D38 00808021 */  addu      $s0, $a0, $zero
/* 3C13C 80060D3C AFB10014 */  sw        $s1, 0x14($sp)
/* 3C140 80060D40 00A08821 */  addu      $s1, $a1, $zero
/* 3C144 80060D44 AFB20018 */  sw        $s2, 0x18($sp)
/* 3C148 80060D48 AFBF001C */  sw        $ra, 0x1c($sp)
/* 3C14C 80060D4C 0C01851D */  jal       func_80061474
/* 3C150 80060D50 00C09021 */   addu     $s2, $a2, $zero
/* 3C154 80060D54 02002021 */  addu      $a0, $s0, $zero
/* 3C158 80060D58 02202821 */  addu      $a1, $s1, $zero
/* 3C15C 80060D5C 0C01ADB0 */  jal       func_8006B6C0
/* 3C160 80060D60 02403021 */   addu     $a2, $s2, $zero
/* 3C164 80060D64 0C018538 */  jal       func_800614E0
/* 3C168 80060D68 00408021 */   addu     $s0, $v0, $zero
/* 3C16C 80060D6C 02001021 */  addu      $v0, $s0, $zero
/* 3C170 80060D70 8FBF001C */  lw        $ra, 0x1c($sp)
/* 3C174 80060D74 8FB20018 */  lw        $s2, 0x18($sp)
/* 3C178 80060D78 8FB10014 */  lw        $s1, 0x14($sp)
/* 3C17C 80060D7C 8FB00010 */  lw        $s0, 0x10($sp)
/* 3C180 80060D80 03E00008 */  jr        $ra
/* 3C184 80060D84 27BD0020 */   addiu    $sp, $sp, 0x20
/* 3C188 80060D88 00000000 */  nop
/* 3C18C 80060D8C 00000000 */  nop
