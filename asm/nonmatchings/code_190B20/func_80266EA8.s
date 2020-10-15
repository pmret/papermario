.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80266EA8
/* 195788 80266EA8 8C820094 */  lw        $v0, 0x94($a0)
/* 19578C 80266EAC 1040000C */  beqz      $v0, .L80266EE0
/* 195790 80266EB0 00000000 */   nop      
/* 195794 80266EB4 8C820000 */  lw        $v0, ($a0)
/* 195798 80266EB8 30420002 */  andi      $v0, $v0, 2
/* 19579C 80266EBC 14400008 */  bnez      $v0, .L80266EE0
/* 1957A0 80266EC0 00000000 */   nop      
/* 1957A4 80266EC4 8C8400C0 */  lw        $a0, 0xc0($a0)
/* 1957A8 80266EC8 80820750 */  lb        $v0, 0x750($a0)
/* 1957AC 80266ECC 10450004 */  beq       $v0, $a1, .L80266EE0
/* 1957B0 80266ED0 24020001 */   addiu    $v0, $zero, 1
/* 1957B4 80266ED4 A0850750 */  sb        $a1, 0x750($a0)
/* 1957B8 80266ED8 A0800752 */  sb        $zero, 0x752($a0)
/* 1957BC 80266EDC A0820751 */  sb        $v0, 0x751($a0)
.L80266EE0:
/* 1957C0 80266EE0 03E00008 */  jr        $ra
/* 1957C4 80266EE4 00000000 */   nop      
