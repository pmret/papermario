.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240158
/* 946028 80240158 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 94602C 8024015C AFB10014 */  sw        $s1, 0x14($sp)
/* 946030 80240160 0080882D */  daddu     $s1, $a0, $zero
/* 946034 80240164 AFBF0018 */  sw        $ra, 0x18($sp)
/* 946038 80240168 AFB00010 */  sw        $s0, 0x10($sp)
/* 94603C 8024016C 8E30000C */  lw        $s0, 0xc($s1)
/* 946040 80240170 8E050000 */  lw        $a1, ($s0)
/* 946044 80240174 0C0B1EAF */  jal       get_variable
/* 946048 80240178 26100004 */   addiu    $s0, $s0, 4
/* 94604C 8024017C 0C00EAD2 */  jal       get_npc_safe
/* 946050 80240180 0040202D */   daddu    $a0, $v0, $zero
/* 946054 80240184 10400005 */  beqz      $v0, .L8024019C
/* 946058 80240188 00000000 */   nop      
/* 94605C 8024018C 8E050000 */  lw        $a1, ($s0)
/* 946060 80240190 844600A8 */  lh        $a2, 0xa8($v0)
/* 946064 80240194 0C0B2026 */  jal       set_variable
/* 946068 80240198 0220202D */   daddu    $a0, $s1, $zero
.L8024019C:
/* 94606C 8024019C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 946070 802401A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 946074 802401A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 946078 802401A8 24020002 */  addiu     $v0, $zero, 2
/* 94607C 802401AC 03E00008 */  jr        $ra
/* 946080 802401B0 27BD0020 */   addiu    $sp, $sp, 0x20
