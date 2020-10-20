.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243AA8
/* 804328 80243AA8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 80432C 80243AAC AFB10014 */  sw        $s1, 0x14($sp)
/* 804330 80243AB0 0080882D */  daddu     $s1, $a0, $zero
/* 804334 80243AB4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 804338 80243AB8 AFB00010 */  sw        $s0, 0x10($sp)
/* 80433C 80243ABC 8E30000C */  lw        $s0, 0xc($s1)
/* 804340 80243AC0 8E050000 */  lw        $a1, ($s0)
/* 804344 80243AC4 0C0B1EAF */  jal       get_variable
/* 804348 80243AC8 26100004 */   addiu    $s0, $s0, 4
/* 80434C 80243ACC 0C00EAD2 */  jal       get_npc_safe
/* 804350 80243AD0 0040202D */   daddu    $a0, $v0, $zero
/* 804354 80243AD4 10400005 */  beqz      $v0, .L80243AEC
/* 804358 80243AD8 00000000 */   nop      
/* 80435C 80243ADC 8E050000 */  lw        $a1, ($s0)
/* 804360 80243AE0 844600A8 */  lh        $a2, 0xa8($v0)
/* 804364 80243AE4 0C0B2026 */  jal       set_variable
/* 804368 80243AE8 0220202D */   daddu    $a0, $s1, $zero
.L80243AEC:
/* 80436C 80243AEC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 804370 80243AF0 8FB10014 */  lw        $s1, 0x14($sp)
/* 804374 80243AF4 8FB00010 */  lw        $s0, 0x10($sp)
/* 804378 80243AF8 24020002 */  addiu     $v0, $zero, 2
/* 80437C 80243AFC 03E00008 */  jr        $ra
/* 804380 80243B00 27BD0020 */   addiu    $sp, $sp, 0x20
