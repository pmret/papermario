.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002B3EC
/* 67EC 8002B3EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 67F0 8002B3F0 AFB20018 */  sw        $s2, 0x18($sp)
/* 67F4 8002B3F4 0080902D */  daddu     $s2, $a0, $zero
/* 67F8 8002B3F8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 67FC 8002B3FC AFB10014 */  sw        $s1, 0x14($sp)
/* 6800 8002B400 0C00AC45 */  jal       func_8002B114
/* 6804 8002B404 AFB00010 */   sw       $s0, 0x10($sp)
/* 6808 8002B408 0000802D */  daddu     $s0, $zero, $zero
/* 680C 8002B40C 3C11800A */  lui       $s1, %hi(D_8009BA30)
/* 6810 8002B410 2631BA30 */  addiu     $s1, $s1, %lo(D_8009BA30)
.L8002B414:
/* 6814 8002B414 8E220000 */  lw        $v0, ($s1)
/* 6818 8002B418 54520004 */  bnel      $v0, $s2, .L8002B42C
/* 681C 8002B41C 26100001 */   addiu    $s0, $s0, 1
/* 6820 8002B420 0C00AE77 */  jal       func_8002B9DC
/* 6824 8002B424 0200202D */   daddu    $a0, $s0, $zero
/* 6828 8002B428 26100001 */  addiu     $s0, $s0, 1
.L8002B42C:
/* 682C 8002B42C 2A020006 */  slti      $v0, $s0, 6
/* 6830 8002B430 1440FFF8 */  bnez      $v0, .L8002B414
/* 6834 8002B434 26310008 */   addiu    $s1, $s1, 8
/* 6838 8002B438 8FBF001C */  lw        $ra, 0x1c($sp)
/* 683C 8002B43C 8FB20018 */  lw        $s2, 0x18($sp)
/* 6840 8002B440 8FB10014 */  lw        $s1, 0x14($sp)
/* 6844 8002B444 8FB00010 */  lw        $s0, 0x10($sp)
/* 6848 8002B448 03E00008 */  jr        $ra
/* 684C 8002B44C 27BD0020 */   addiu    $sp, $sp, 0x20
