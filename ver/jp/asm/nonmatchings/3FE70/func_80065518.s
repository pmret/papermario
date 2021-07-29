.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80065518
/* 40918 80065518 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4091C 8006551C AFB10014 */  sw        $s1, 0x14($sp)
/* 40920 80065520 00808821 */  addu      $s1, $a0, $zero
/* 40924 80065524 AFB00010 */  sw        $s0, 0x10($sp)
/* 40928 80065528 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4092C 8006552C 0C019291 */  jal       func_80064A44
/* 40930 80065530 00C08021 */   addu     $s0, $a2, $zero
/* 40934 80065534 02301021 */  addu      $v0, $s1, $s0
/* 40938 80065538 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4093C 8006553C 8FB10014 */  lw        $s1, 0x14($sp)
/* 40940 80065540 8FB00010 */  lw        $s0, 0x10($sp)
/* 40944 80065544 03E00008 */  jr        $ra
/* 40948 80065548 27BD0020 */   addiu    $sp, $sp, 0x20
/* 4094C 8006554C 00000000 */  nop
