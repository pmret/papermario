.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021B314_6A2514
/* 6A2514 8021B314 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6A2518 8021B318 AFB20018 */  sw        $s2, 0x18($sp)
/* 6A251C 8021B31C 0080902D */  daddu     $s2, $a0, $zero
/* 6A2520 8021B320 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6A2524 8021B324 AFB10014 */  sw        $s1, 0x14($sp)
/* 6A2528 8021B328 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A252C 8021B32C 8E50000C */  lw        $s0, 0xc($s2)
/* 6A2530 8021B330 8E050000 */  lw        $a1, ($s0)
/* 6A2534 8021B334 0C0B1EAF */  jal       get_variable
/* 6A2538 8021B338 26100004 */   addiu    $s0, $s0, 4
/* 6A253C 8021B33C 0C04C3D6 */  jal       get_item_entity
/* 6A2540 8021B340 0040202D */   daddu    $a0, $v0, $zero
/* 6A2544 8021B344 8E050000 */  lw        $a1, ($s0)
/* 6A2548 8021B348 26100004 */  addiu     $s0, $s0, 4
/* 6A254C 8021B34C 0040882D */  daddu     $s1, $v0, $zero
/* 6A2550 8021B350 C6200008 */  lwc1      $f0, 8($s1)
/* 6A2554 8021B354 4600008D */  trunc.w.s $f2, $f0
/* 6A2558 8021B358 44061000 */  mfc1      $a2, $f2
/* 6A255C 8021B35C 0C0B2026 */  jal       set_variable
/* 6A2560 8021B360 0240202D */   daddu    $a0, $s2, $zero
/* 6A2564 8021B364 8E050000 */  lw        $a1, ($s0)
/* 6A2568 8021B368 26100004 */  addiu     $s0, $s0, 4
/* 6A256C 8021B36C C620000C */  lwc1      $f0, 0xc($s1)
/* 6A2570 8021B370 4600008D */  trunc.w.s $f2, $f0
/* 6A2574 8021B374 44061000 */  mfc1      $a2, $f2
/* 6A2578 8021B378 0C0B2026 */  jal       set_variable
/* 6A257C 8021B37C 0240202D */   daddu    $a0, $s2, $zero
/* 6A2580 8021B380 C6200010 */  lwc1      $f0, 0x10($s1)
/* 6A2584 8021B384 8E050000 */  lw        $a1, ($s0)
/* 6A2588 8021B388 4600008D */  trunc.w.s $f2, $f0
/* 6A258C 8021B38C 44061000 */  mfc1      $a2, $f2
/* 6A2590 8021B390 0C0B2026 */  jal       set_variable
/* 6A2594 8021B394 0240202D */   daddu    $a0, $s2, $zero
/* 6A2598 8021B398 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6A259C 8021B39C 8FB20018 */  lw        $s2, 0x18($sp)
/* 6A25A0 8021B3A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 6A25A4 8021B3A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A25A8 8021B3A8 24020002 */  addiu     $v0, $zero, 2
/* 6A25AC 8021B3AC 03E00008 */  jr        $ra
/* 6A25B0 8021B3B0 27BD0020 */   addiu    $sp, $sp, 0x20
