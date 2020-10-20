.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D50
/* A3A230 80240D50 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A3A234 80240D54 AFB10014 */  sw        $s1, 0x14($sp)
/* A3A238 80240D58 0080882D */  daddu     $s1, $a0, $zero
/* A3A23C 80240D5C AFBF0018 */  sw        $ra, 0x18($sp)
/* A3A240 80240D60 AFB00010 */  sw        $s0, 0x10($sp)
/* A3A244 80240D64 8E30000C */  lw        $s0, 0xc($s1)
/* A3A248 80240D68 8E050000 */  lw        $a1, ($s0)
/* A3A24C 80240D6C 0C0B1EAF */  jal       get_variable
/* A3A250 80240D70 26100004 */   addiu    $s0, $s0, 4
/* A3A254 80240D74 0C00EAD2 */  jal       get_npc_safe
/* A3A258 80240D78 0040202D */   daddu    $a0, $v0, $zero
/* A3A25C 80240D7C 10400005 */  beqz      $v0, .L80240D94
/* A3A260 80240D80 00000000 */   nop      
/* A3A264 80240D84 8E050000 */  lw        $a1, ($s0)
/* A3A268 80240D88 844600A8 */  lh        $a2, 0xa8($v0)
/* A3A26C 80240D8C 0C0B2026 */  jal       set_variable
/* A3A270 80240D90 0220202D */   daddu    $a0, $s1, $zero
.L80240D94:
/* A3A274 80240D94 8FBF0018 */  lw        $ra, 0x18($sp)
/* A3A278 80240D98 8FB10014 */  lw        $s1, 0x14($sp)
/* A3A27C 80240D9C 8FB00010 */  lw        $s0, 0x10($sp)
/* A3A280 80240DA0 24020002 */  addiu     $v0, $zero, 2
/* A3A284 80240DA4 03E00008 */  jr        $ra
/* A3A288 80240DA8 27BD0020 */   addiu    $sp, $sp, 0x20
