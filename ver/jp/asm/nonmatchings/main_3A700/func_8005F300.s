.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F300
/* 3A700 8005F300 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3A704 8005F304 AFB10014 */  sw        $s1, 0x14($sp)
/* 3A708 8005F308 0080882D */  daddu     $s1, $a0, $zero
/* 3A70C 8005F30C AFB00010 */  sw        $s0, 0x10($sp)
/* 3A710 8005F310 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3A714 8005F314 0C018177 */  jal       func_800605DC
/* 3A718 8005F318 00A0802D */   daddu    $s0, $a1, $zero
/* 3A71C 8005F31C 00102040 */  sll       $a0, $s0, 1
/* 3A720 8005F320 00902021 */  addu      $a0, $a0, $s0
/* 3A724 8005F324 00042040 */  sll       $a0, $a0, 1
/* 3A728 8005F328 3C02800B */  lui       $v0, %hi(D_800B1D48)
/* 3A72C 8005F32C 24421D48 */  addiu     $v0, $v0, %lo(D_800B1D48)
/* 3A730 8005F330 00822021 */  addu      $a0, $a0, $v0
/* 3A734 8005F334 0220282D */  daddu     $a1, $s1, $zero
/* 3A738 8005F338 0C019188 */  jal       func_80064620
/* 3A73C 8005F33C 24060006 */   addiu    $a2, $zero, 6
/* 3A740 8005F340 0C018181 */  jal       func_80060604
/* 3A744 8005F344 00000000 */   nop
/* 3A748 8005F348 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3A74C 8005F34C 8FB10014 */  lw        $s1, 0x14($sp)
/* 3A750 8005F350 8FB00010 */  lw        $s0, 0x10($sp)
/* 3A754 8005F354 03E00008 */  jr        $ra
/* 3A758 8005F358 27BD0020 */   addiu    $sp, $sp, 0x20
/* 3A75C 8005F35C 00000000 */  nop
