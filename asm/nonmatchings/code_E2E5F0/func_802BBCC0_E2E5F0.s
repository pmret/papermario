.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BBCC0_E2E5F0
/* E2E5F0 802BBCC0 3C028011 */  lui       $v0, %hi(gPlayerStatus+0x4)
/* E2E5F4 802BBCC4 8C42EFCC */  lw        $v0, %lo(gPlayerStatus+0x4)($v0)
/* E2E5F8 802BBCC8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2E5FC 802BBCCC AFB00010 */  sw        $s0, 0x10($sp)
/* E2E600 802BBCD0 0080802D */  daddu     $s0, $a0, $zero
/* E2E604 802BBCD4 30420010 */  andi      $v0, $v0, 0x10
/* E2E608 802BBCD8 1040000C */  beqz      $v0, .L802BBD0C
/* E2E60C 802BBCDC AFBF0014 */   sw       $ra, 0x14($sp)
/* E2E610 802BBCE0 92020006 */  lbu       $v0, 6($s0)
/* E2E614 802BBCE4 30420048 */  andi      $v0, $v0, 0x48
/* E2E618 802BBCE8 10400008 */  beqz      $v0, .L802BBD0C
/* E2E61C 802BBCEC 00000000 */   nop
/* E2E620 802BBCF0 0C043F5A */  jal       exec_entity_updatecmd
/* E2E624 802BBCF4 00000000 */   nop
/* E2E628 802BBCF8 86040014 */  lh        $a0, 0x14($s0)
/* E2E62C 802BBCFC 3C050000 */  lui       $a1, 0
/* E2E630 802BBD00 24A500F4 */  addiu     $a1, $a1, 0xf4
/* E2E634 802BBD04 0C048052 */  jal       play_model_animation
/* E2E638 802BBD08 00000000 */   nop
.L802BBD0C:
/* E2E63C 802BBD0C 8FBF0014 */  lw        $ra, 0x14($sp)
/* E2E640 802BBD10 8FB00010 */  lw        $s0, 0x10($sp)
/* E2E644 802BBD14 03E00008 */  jr        $ra
/* E2E648 802BBD18 27BD0018 */   addiu    $sp, $sp, 0x18
