.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800553C8
/* 307C8 800553C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 307CC 800553CC AFB10014 */  sw        $s1, 0x14($sp)
/* 307D0 800553D0 0080882D */  daddu     $s1, $a0, $zero
/* 307D4 800553D4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 307D8 800553D8 0C014238 */  jal       func_800508E0
/* 307DC 800553DC AFB00010 */   sw       $s0, 0x10($sp)
/* 307E0 800553E0 0040802D */  daddu     $s0, $v0, $zero
/* 307E4 800553E4 16000005 */  bnez      $s0, .L800553FC
/* 307E8 800553E8 0200102D */   daddu    $v0, $s0, $zero
/* 307EC 800553EC 0220202D */  daddu     $a0, $s1, $zero
/* 307F0 800553F0 0C014245 */  jal       func_80050914
/* 307F4 800553F4 0000282D */   daddu    $a1, $zero, $zero
/* 307F8 800553F8 0200102D */  daddu     $v0, $s0, $zero
.L800553FC:
/* 307FC 800553FC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 30800 80055400 8FB10014 */  lw        $s1, 0x14($sp)
/* 30804 80055404 8FB00010 */  lw        $s0, 0x10($sp)
/* 30808 80055408 03E00008 */  jr        $ra
/* 3080C 8005540C 27BD0020 */   addiu    $sp, $sp, 0x20
