.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021C974_6A3B74
/* 6A3B74 8021C974 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6A3B78 8021C978 AFB10014 */  sw        $s1, 0x14($sp)
/* 6A3B7C 8021C97C 0080882D */  daddu     $s1, $a0, $zero
/* 6A3B80 8021C980 AFB20018 */  sw        $s2, 0x18($sp)
/* 6A3B84 8021C984 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 6A3B88 8021C988 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 6A3B8C 8021C98C AFBF001C */  sw        $ra, 0x1c($sp)
/* 6A3B90 8021C990 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A3B94 8021C994 8E30000C */  lw        $s0, 0xc($s1)
/* 6A3B98 8021C998 82460097 */  lb        $a2, 0x97($s2)
/* 6A3B9C 8021C99C 8E050000 */  lw        $a1, ($s0)
/* 6A3BA0 8021C9A0 0C0B2026 */  jal       set_variable
/* 6A3BA4 8021C9A4 26100004 */   addiu    $s0, $s0, 4
/* 6A3BA8 8021C9A8 8E050000 */  lw        $a1, ($s0)
/* 6A3BAC 8021C9AC 82460096 */  lb        $a2, 0x96($s2)
/* 6A3BB0 8021C9B0 0C0B2026 */  jal       set_variable
/* 6A3BB4 8021C9B4 0220202D */   daddu    $a0, $s1, $zero
/* 6A3BB8 8021C9B8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6A3BBC 8021C9BC 8FB20018 */  lw        $s2, 0x18($sp)
/* 6A3BC0 8021C9C0 8FB10014 */  lw        $s1, 0x14($sp)
/* 6A3BC4 8021C9C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A3BC8 8021C9C8 24020002 */  addiu     $v0, $zero, 2
/* 6A3BCC 8021C9CC 03E00008 */  jr        $ra
/* 6A3BD0 8021C9D0 27BD0020 */   addiu    $sp, $sp, 0x20
