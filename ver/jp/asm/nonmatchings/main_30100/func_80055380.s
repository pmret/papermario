.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055380
/* 30780 80055380 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30784 80055384 AFB10014 */  sw        $s1, 0x14($sp)
/* 30788 80055388 0080882D */  daddu     $s1, $a0, $zero
/* 3078C 8005538C AFBF0018 */  sw        $ra, 0x18($sp)
/* 30790 80055390 0C014238 */  jal       func_800508E0
/* 30794 80055394 AFB00010 */   sw       $s0, 0x10($sp)
/* 30798 80055398 0040802D */  daddu     $s0, $v0, $zero
/* 3079C 8005539C 16000005 */  bnez      $s0, .L800553B4
/* 307A0 800553A0 0200102D */   daddu    $v0, $s0, $zero
/* 307A4 800553A4 0220202D */  daddu     $a0, $s1, $zero
/* 307A8 800553A8 0C014245 */  jal       func_80050914
/* 307AC 800553AC 24050001 */   addiu    $a1, $zero, 1
/* 307B0 800553B0 0200102D */  daddu     $v0, $s0, $zero
.L800553B4:
/* 307B4 800553B4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 307B8 800553B8 8FB10014 */  lw        $s1, 0x14($sp)
/* 307BC 800553BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 307C0 800553C0 03E00008 */  jr        $ra
/* 307C4 800553C4 27BD0020 */   addiu    $sp, $sp, 0x20
