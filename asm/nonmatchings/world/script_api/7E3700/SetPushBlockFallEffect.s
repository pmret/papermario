.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPushBlockFallEffect
/* 7E462C 802837AC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E4630 802837B0 AFB10014 */  sw        $s1, 0x14($sp)
/* 7E4634 802837B4 0080882D */  daddu     $s1, $a0, $zero
/* 7E4638 802837B8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7E463C 802837BC AFB00010 */  sw        $s0, 0x10($sp)
/* 7E4640 802837C0 8E30000C */  lw        $s0, 0xc($s1)
/* 7E4644 802837C4 8E050000 */  lw        $a1, ($s0)
/* 7E4648 802837C8 0C0B1EAF */  jal       get_variable
/* 7E464C 802837CC 26100004 */   addiu    $s0, $s0, 4
/* 7E4650 802837D0 0220202D */  daddu     $a0, $s1, $zero
/* 7E4654 802837D4 8E050000 */  lw        $a1, ($s0)
/* 7E4658 802837D8 0C0B1EAF */  jal       get_variable
/* 7E465C 802837DC 0040802D */   daddu    $s0, $v0, $zero
/* 7E4660 802837E0 00108080 */  sll       $s0, $s0, 2
/* 7E4664 802837E4 3C03802E */  lui       $v1, %hi(D_802DBC88)
/* 7E4668 802837E8 00701821 */  addu      $v1, $v1, $s0
/* 7E466C 802837EC 8C63BC88 */  lw        $v1, %lo(D_802DBC88)($v1)
/* 7E4670 802837F0 AC620014 */  sw        $v0, 0x14($v1)
/* 7E4674 802837F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7E4678 802837F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E467C 802837FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E4680 80283800 24020002 */  addiu     $v0, $zero, 2
/* 7E4684 80283804 03E00008 */  jr        $ra
/* 7E4688 80283808 27BD0020 */   addiu    $sp, $sp, 0x20
/* 7E468C 8028380C 00000000 */  nop
