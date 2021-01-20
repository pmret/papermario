.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC148_E2C878
/* E2C878 802BC148 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2C87C 802BC14C AFB00010 */  sw        $s0, 0x10($sp)
/* E2C880 802BC150 0080802D */  daddu     $s0, $a0, $zero
/* E2C884 802BC154 AFBF0014 */  sw        $ra, 0x14($sp)
/* E2C888 802BC158 92020006 */  lbu       $v0, 6($s0)
/* E2C88C 802BC15C 30420001 */  andi      $v0, $v0, 1
/* E2C890 802BC160 1040000D */  beqz      $v0, .L802BC198
/* E2C894 802BC164 00000000 */   nop
/* E2C898 802BC168 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* E2C89C 802BC16C 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* E2C8A0 802BC170 804300B4 */  lb        $v1, 0xb4($v0)
/* E2C8A4 802BC174 2402000E */  addiu     $v0, $zero, 0xe
/* E2C8A8 802BC178 10620003 */  beq       $v1, $v0, .L802BC188
/* E2C8AC 802BC17C 24020010 */   addiu    $v0, $zero, 0x10
/* E2C8B0 802BC180 14620005 */  bne       $v1, $v0, .L802BC198
/* E2C8B4 802BC184 00000000 */   nop
.L802BC188:
/* E2C8B8 802BC188 0C04419E */  jal       func_80110678
/* E2C8BC 802BC18C 0200202D */   daddu    $a0, $s0, $zero
/* E2C8C0 802BC190 0C043F5A */  jal       exec_entity_updatecmd
/* E2C8C4 802BC194 0200202D */   daddu    $a0, $s0, $zero
.L802BC198:
/* E2C8C8 802BC198 8FBF0014 */  lw        $ra, 0x14($sp)
/* E2C8CC 802BC19C 8FB00010 */  lw        $s0, 0x10($sp)
/* E2C8D0 802BC1A0 03E00008 */  jr        $ra
/* E2C8D4 802BC1A4 27BD0018 */   addiu    $sp, $sp, 0x18
