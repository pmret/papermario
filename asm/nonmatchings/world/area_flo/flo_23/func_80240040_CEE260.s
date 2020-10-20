.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_CEE2A0
/* CEE2A0 80240040 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CEE2A4 80240044 AFB10014 */  sw        $s1, 0x14($sp)
/* CEE2A8 80240048 0080882D */  daddu     $s1, $a0, $zero
/* CEE2AC 8024004C AFBF0018 */  sw        $ra, 0x18($sp)
/* CEE2B0 80240050 AFB00010 */  sw        $s0, 0x10($sp)
/* CEE2B4 80240054 8E30000C */  lw        $s0, 0xc($s1)
/* CEE2B8 80240058 8E050000 */  lw        $a1, ($s0)
/* CEE2BC 8024005C 0C0B1EAF */  jal       get_variable
/* CEE2C0 80240060 26100004 */   addiu    $s0, $s0, 4
/* CEE2C4 80240064 0C00EAD2 */  jal       get_npc_safe
/* CEE2C8 80240068 0040202D */   daddu    $a0, $v0, $zero
/* CEE2CC 8024006C 10400005 */  beqz      $v0, .L80240084
/* CEE2D0 80240070 00000000 */   nop      
/* CEE2D4 80240074 8E050000 */  lw        $a1, ($s0)
/* CEE2D8 80240078 844600A8 */  lh        $a2, 0xa8($v0)
/* CEE2DC 8024007C 0C0B2026 */  jal       set_variable
/* CEE2E0 80240080 0220202D */   daddu    $a0, $s1, $zero
.L80240084:
/* CEE2E4 80240084 8FBF0018 */  lw        $ra, 0x18($sp)
/* CEE2E8 80240088 8FB10014 */  lw        $s1, 0x14($sp)
/* CEE2EC 8024008C 8FB00010 */  lw        $s0, 0x10($sp)
/* CEE2F0 80240090 24020002 */  addiu     $v0, $zero, 2
/* CEE2F4 80240094 03E00008 */  jr        $ra
/* CEE2F8 80240098 27BD0020 */   addiu    $sp, $sp, 0x20
