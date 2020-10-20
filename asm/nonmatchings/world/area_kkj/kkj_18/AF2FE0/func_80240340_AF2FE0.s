.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240340_AF2FE0
/* AF2FE0 80240340 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AF2FE4 80240344 AFB10014 */  sw        $s1, 0x14($sp)
/* AF2FE8 80240348 0080882D */  daddu     $s1, $a0, $zero
/* AF2FEC 8024034C AFBF0018 */  sw        $ra, 0x18($sp)
/* AF2FF0 80240350 AFB00010 */  sw        $s0, 0x10($sp)
/* AF2FF4 80240354 8E30000C */  lw        $s0, 0xc($s1)
/* AF2FF8 80240358 8E050000 */  lw        $a1, ($s0)
/* AF2FFC 8024035C 0C0B1EAF */  jal       get_variable
/* AF3000 80240360 26100004 */   addiu    $s0, $s0, 4
/* AF3004 80240364 0C00EAD2 */  jal       get_npc_safe
/* AF3008 80240368 0040202D */   daddu    $a0, $v0, $zero
/* AF300C 8024036C 10400005 */  beqz      $v0, .L80240384
/* AF3010 80240370 00000000 */   nop      
/* AF3014 80240374 8E050000 */  lw        $a1, ($s0)
/* AF3018 80240378 844600A8 */  lh        $a2, 0xa8($v0)
/* AF301C 8024037C 0C0B2026 */  jal       set_variable
/* AF3020 80240380 0220202D */   daddu    $a0, $s1, $zero
.L80240384:
/* AF3024 80240384 8FBF0018 */  lw        $ra, 0x18($sp)
/* AF3028 80240388 8FB10014 */  lw        $s1, 0x14($sp)
/* AF302C 8024038C 8FB00010 */  lw        $s0, 0x10($sp)
/* AF3030 80240390 24020002 */  addiu     $v0, $zero, 2
/* AF3034 80240394 03E00008 */  jr        $ra
/* AF3038 80240398 27BD0020 */   addiu    $sp, $sp, 0x20
