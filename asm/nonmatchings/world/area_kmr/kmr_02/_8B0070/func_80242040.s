.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242040
/* 8B20B0 80242040 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B20B4 80242044 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B20B8 80242048 0080882D */  daddu     $s1, $a0, $zero
/* 8B20BC 8024204C AFBF0018 */  sw        $ra, 0x18($sp)
/* 8B20C0 80242050 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B20C4 80242054 8E30000C */  lw        $s0, 0xc($s1)
/* 8B20C8 80242058 8E050000 */  lw        $a1, ($s0)
/* 8B20CC 8024205C 0C0B1EAF */  jal       get_variable
/* 8B20D0 80242060 26100004 */   addiu    $s0, $s0, 4
/* 8B20D4 80242064 0C00EAD2 */  jal       get_npc_safe
/* 8B20D8 80242068 0040202D */   daddu    $a0, $v0, $zero
/* 8B20DC 8024206C 10400005 */  beqz      $v0, .L80242084
/* 8B20E0 80242070 00000000 */   nop      
/* 8B20E4 80242074 8E050000 */  lw        $a1, ($s0)
/* 8B20E8 80242078 844600A8 */  lh        $a2, 0xa8($v0)
/* 8B20EC 8024207C 0C0B2026 */  jal       set_variable
/* 8B20F0 80242080 0220202D */   daddu    $a0, $s1, $zero
.L80242084:
/* 8B20F4 80242084 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8B20F8 80242088 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B20FC 8024208C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B2100 80242090 24020002 */  addiu     $v0, $zero, 2
/* 8B2104 80242094 03E00008 */  jr        $ra
/* 8B2108 80242098 27BD0020 */   addiu    $sp, $sp, 0x20
