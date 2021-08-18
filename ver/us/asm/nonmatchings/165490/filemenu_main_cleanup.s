.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_main_cleanup
/* 16751C 80246CBC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 167520 80246CC0 AFB10014 */  sw        $s1, 0x14($sp)
/* 167524 80246CC4 0000882D */  daddu     $s1, $zero, $zero
/* 167528 80246CC8 AFB00010 */  sw        $s0, 0x10($sp)
/* 16752C 80246CCC 3C108025 */  lui       $s0, %hi(D_8024C0B0)
/* 167530 80246CD0 2610C0B0 */  addiu     $s0, $s0, %lo(D_8024C0B0)
/* 167534 80246CD4 AFBF0018 */  sw        $ra, 0x18($sp)
.L80246CD8:
/* 167538 80246CD8 8E040000 */  lw        $a0, ($s0)
/* 16753C 80246CDC 26100004 */  addiu     $s0, $s0, 4
/* 167540 80246CE0 0C05123D */  jal       hud_element_free
/* 167544 80246CE4 26310001 */   addiu    $s1, $s1, 1
/* 167548 80246CE8 2A220014 */  slti      $v0, $s1, 0x14
/* 16754C 80246CEC 1440FFFA */  bnez      $v0, .L80246CD8
/* 167550 80246CF0 00000000 */   nop
/* 167554 80246CF4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 167558 80246CF8 8FB10014 */  lw        $s1, 0x14($sp)
/* 16755C 80246CFC 8FB00010 */  lw        $s0, 0x10($sp)
/* 167560 80246D00 03E00008 */  jr        $ra
/* 167564 80246D04 27BD0020 */   addiu    $sp, $sp, 0x20
/* 167568 80246D08 00000000 */  nop
/* 16756C 80246D0C 00000000 */  nop
