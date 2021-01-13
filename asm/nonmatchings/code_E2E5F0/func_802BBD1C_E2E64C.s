.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BBD1C_E2E64C
/* E2E64C 802BBD1C 3C028011 */  lui       $v0, %hi(gPlayerStatus+0x4)
/* E2E650 802BBD20 8C42EFCC */  lw        $v0, %lo(gPlayerStatus+0x4)($v0)
/* E2E654 802BBD24 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2E658 802BBD28 AFB00010 */  sw        $s0, 0x10($sp)
/* E2E65C 802BBD2C 0080802D */  daddu     $s0, $a0, $zero
/* E2E660 802BBD30 30420010 */  andi      $v0, $v0, 0x10
/* E2E664 802BBD34 1040000C */  beqz      $v0, .L802BBD68
/* E2E668 802BBD38 AFBF0014 */   sw       $ra, 0x14($sp)
/* E2E66C 802BBD3C 92020006 */  lbu       $v0, 6($s0)
/* E2E670 802BBD40 30420048 */  andi      $v0, $v0, 0x48
/* E2E674 802BBD44 10400008 */  beqz      $v0, .L802BBD68
/* E2E678 802BBD48 00000000 */   nop
/* E2E67C 802BBD4C 0C043F5A */  jal       func_8010FD68
/* E2E680 802BBD50 00000000 */   nop
/* E2E684 802BBD54 86040014 */  lh        $a0, 0x14($s0)
/* E2E688 802BBD58 3C050000 */  lui       $a1, 0
/* E2E68C 802BBD5C 24A50064 */  addiu     $a1, $a1, 0x64
/* E2E690 802BBD60 0C048052 */  jal       play_model_animation
/* E2E694 802BBD64 00000000 */   nop
.L802BBD68:
/* E2E698 802BBD68 8FBF0014 */  lw        $ra, 0x14($sp)
/* E2E69C 802BBD6C 8FB00010 */  lw        $s0, 0x10($sp)
/* E2E6A0 802BBD70 03E00008 */  jr        $ra
/* E2E6A4 802BBD74 27BD0018 */   addiu    $sp, $sp, 0x18
