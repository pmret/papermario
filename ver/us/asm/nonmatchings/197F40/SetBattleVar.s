.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetBattleVar
/* 19DF18 8026F638 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19DF1C 8026F63C AFB10014 */  sw        $s1, 0x14($sp)
/* 19DF20 8026F640 0080882D */  daddu     $s1, $a0, $zero
/* 19DF24 8026F644 AFBF0018 */  sw        $ra, 0x18($sp)
/* 19DF28 8026F648 AFB00010 */  sw        $s0, 0x10($sp)
/* 19DF2C 8026F64C 8E30000C */  lw        $s0, 0xc($s1)
/* 19DF30 8026F650 8E050000 */  lw        $a1, ($s0)
/* 19DF34 8026F654 0C0B1EAF */  jal       evt_get_variable
/* 19DF38 8026F658 26100004 */   addiu    $s0, $s0, 4
/* 19DF3C 8026F65C 0220202D */  daddu     $a0, $s1, $zero
/* 19DF40 8026F660 8E050000 */  lw        $a1, ($s0)
/* 19DF44 8026F664 0C0B1EAF */  jal       evt_get_variable
/* 19DF48 8026F668 0040802D */   daddu    $s0, $v0, $zero
/* 19DF4C 8026F66C 00108080 */  sll       $s0, $s0, 2
/* 19DF50 8026F670 3C01800E */  lui       $at, %hi(gBattleStatus+0x8)
/* 19DF54 8026F674 00300821 */  addu      $at, $at, $s0
/* 19DF58 8026F678 AC22C078 */  sw        $v0, %lo(gBattleStatus+0x8)($at)
/* 19DF5C 8026F67C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 19DF60 8026F680 8FB10014 */  lw        $s1, 0x14($sp)
/* 19DF64 8026F684 8FB00010 */  lw        $s0, 0x10($sp)
/* 19DF68 8026F688 24020002 */  addiu     $v0, $zero, 2
/* 19DF6C 8026F68C 03E00008 */  jr        $ra
/* 19DF70 8026F690 27BD0020 */   addiu    $sp, $sp, 0x20
