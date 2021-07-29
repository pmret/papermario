.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC050_E2E980
/* E2E980 802BC050 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2E984 802BC054 AFB00010 */  sw        $s0, 0x10($sp)
/* E2E988 802BC058 0080802D */  daddu     $s0, $a0, $zero
/* E2E98C 802BC05C AFBF0014 */  sw        $ra, 0x14($sp)
/* E2E990 802BC060 92020006 */  lbu       $v0, 6($s0)
/* E2E994 802BC064 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* E2E998 802BC068 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* E2E99C 802BC06C 30420001 */  andi      $v0, $v0, 1
/* E2E9A0 802BC070 1040000D */  beqz      $v0, .L802BC0A8
/* E2E9A4 802BC074 00000000 */   nop
/* E2E9A8 802BC078 8C620004 */  lw        $v0, 4($v1)
/* E2E9AC 802BC07C 34420004 */  ori       $v0, $v0, 4
/* E2E9B0 802BC080 0C03BCC0 */  jal       func_800EF300
/* E2E9B4 802BC084 AC620004 */   sw       $v0, 4($v1)
/* E2E9B8 802BC088 8E020040 */  lw        $v0, 0x40($s0)
/* E2E9BC 802BC08C 0C04417A */  jal       get_entity_by_index
/* E2E9C0 802BC090 8C440000 */   lw       $a0, ($v0)
/* E2E9C4 802BC094 0200202D */  daddu     $a0, $s0, $zero
/* E2E9C8 802BC098 0C043F5A */  jal       exec_entity_commandlist
/* E2E9CC 802BC09C 0040802D */   daddu    $s0, $v0, $zero
/* E2E9D0 802BC0A0 0C043F5A */  jal       exec_entity_commandlist
/* E2E9D4 802BC0A4 0200202D */   daddu    $a0, $s0, $zero
.L802BC0A8:
/* E2E9D8 802BC0A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* E2E9DC 802BC0AC 8FB00010 */  lw        $s0, 0x10($sp)
/* E2E9E0 802BC0B0 03E00008 */  jr        $ra
/* E2E9E4 802BC0B4 27BD0018 */   addiu    $sp, $sp, 0x18
