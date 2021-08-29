.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BB8_844788
/* 844788 80241BB8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 84478C 80241BBC AFB10014 */  sw        $s1, 0x14($sp)
/* 844790 80241BC0 0080882D */  daddu     $s1, $a0, $zero
/* 844794 80241BC4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 844798 80241BC8 AFB00010 */  sw        $s0, 0x10($sp)
/* 84479C 80241BCC F7B40020 */  sdc1      $f20, 0x20($sp)
/* 8447A0 80241BD0 8E30000C */  lw        $s0, 0xc($s1)
/* 8447A4 80241BD4 8E050000 */  lw        $a1, ($s0)
/* 8447A8 80241BD8 0C0B1EAF */  jal       get_variable
/* 8447AC 80241BDC 26100004 */   addiu    $s0, $s0, 4
/* 8447B0 80241BE0 0220202D */  daddu     $a0, $s1, $zero
/* 8447B4 80241BE4 8E050000 */  lw        $a1, ($s0)
/* 8447B8 80241BE8 0C0B210B */  jal       evt_get_float_variable
/* 8447BC 80241BEC 0040802D */   daddu    $s0, $v0, $zero
/* 8447C0 80241BF0 0220202D */  daddu     $a0, $s1, $zero
/* 8447C4 80241BF4 0200282D */  daddu     $a1, $s0, $zero
/* 8447C8 80241BF8 0C0B36B0 */  jal       resolve_npc
/* 8447CC 80241BFC 46000506 */   mov.s    $f20, $f0
/* 8447D0 80241C00 E454007C */  swc1      $f20, 0x7c($v0)
/* 8447D4 80241C04 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8447D8 80241C08 8FB10014 */  lw        $s1, 0x14($sp)
/* 8447DC 80241C0C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8447E0 80241C10 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 8447E4 80241C14 24020002 */  addiu     $v0, $zero, 2
/* 8447E8 80241C18 03E00008 */  jr        $ra
/* 8447EC 80241C1C 27BD0028 */   addiu    $sp, $sp, 0x28
