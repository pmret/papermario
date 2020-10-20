.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414F4
/* 8440C4 802414F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8440C8 802414F8 AFB10014 */  sw        $s1, 0x14($sp)
/* 8440CC 802414FC 0080882D */  daddu     $s1, $a0, $zero
/* 8440D0 80241500 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8440D4 80241504 AFB00010 */  sw        $s0, 0x10($sp)
/* 8440D8 80241508 8E30000C */  lw        $s0, 0xc($s1)
/* 8440DC 8024150C 8E050000 */  lw        $a1, ($s0)
/* 8440E0 80241510 0C0B1EAF */  jal       get_variable
/* 8440E4 80241514 26100004 */   addiu    $s0, $s0, 4
/* 8440E8 80241518 0C00EAD2 */  jal       get_npc_safe
/* 8440EC 8024151C 0040202D */   daddu    $a0, $v0, $zero
/* 8440F0 80241520 10400005 */  beqz      $v0, .L80241538
/* 8440F4 80241524 00000000 */   nop      
/* 8440F8 80241528 8E050000 */  lw        $a1, ($s0)
/* 8440FC 8024152C 844600A8 */  lh        $a2, 0xa8($v0)
/* 844100 80241530 0C0B2026 */  jal       set_variable
/* 844104 80241534 0220202D */   daddu    $a0, $s1, $zero
.L80241538:
/* 844108 80241538 8FBF0018 */  lw        $ra, 0x18($sp)
/* 84410C 8024153C 8FB10014 */  lw        $s1, 0x14($sp)
/* 844110 80241540 8FB00010 */  lw        $s0, 0x10($sp)
/* 844114 80241544 24020002 */  addiu     $v0, $zero, 2
/* 844118 80241548 03E00008 */  jr        $ra
/* 84411C 8024154C 27BD0020 */   addiu    $sp, $sp, 0x20
