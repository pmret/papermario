.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055464
/* 30864 80055464 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30868 80055468 AFB00010 */  sw        $s0, 0x10($sp)
/* 3086C 8005546C 0080802D */  daddu     $s0, $a0, $zero
/* 30870 80055470 AFB10014 */  sw        $s1, 0x14($sp)
/* 30874 80055474 AFBF0018 */  sw        $ra, 0x18($sp)
/* 30878 80055478 0C01430C */  jal       func_80050C30
/* 3087C 8005547C 00A0882D */   daddu    $s1, $a1, $zero
/* 30880 80055480 14400003 */  bnez      $v0, .L80055490
/* 30884 80055484 0200202D */   daddu    $a0, $s0, $zero
/* 30888 80055488 0C014328 */  jal       func_80050CA0
/* 3088C 8005548C 0220282D */   daddu    $a1, $s1, $zero
.L80055490:
/* 30890 80055490 8FBF0018 */  lw        $ra, 0x18($sp)
/* 30894 80055494 8FB10014 */  lw        $s1, 0x14($sp)
/* 30898 80055498 8FB00010 */  lw        $s0, 0x10($sp)
/* 3089C 8005549C 03E00008 */  jr        $ra
/* 308A0 800554A0 27BD0020 */   addiu    $sp, $sp, 0x20
