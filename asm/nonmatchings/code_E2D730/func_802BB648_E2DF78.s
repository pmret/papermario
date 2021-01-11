.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB648_E2DF78
/* E2DF78 802BB648 3C028011 */  lui       $v0, %hi(gPlayerStatus+0x4)
/* E2DF7C 802BB64C 8C42EFCC */  lw        $v0, %lo(gPlayerStatus+0x4)($v0)
/* E2DF80 802BB650 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2DF84 802BB654 AFB00010 */  sw        $s0, 0x10($sp)
/* E2DF88 802BB658 0080802D */  daddu     $s0, $a0, $zero
/* E2DF8C 802BB65C AFBF0014 */  sw        $ra, 0x14($sp)
/* E2DF90 802BB660 8E050040 */  lw        $a1, 0x40($s0)
/* E2DF94 802BB664 30420010 */  andi      $v0, $v0, 0x10
/* E2DF98 802BB668 10400019 */  beqz      $v0, .L802BB6D0
/* E2DF9C 802BB66C 00000000 */   nop      
/* E2DFA0 802BB670 92020006 */  lbu       $v0, 6($s0)
/* E2DFA4 802BB674 30420048 */  andi      $v0, $v0, 0x48
/* E2DFA8 802BB678 10400015 */  beqz      $v0, .L802BB6D0
/* E2DFAC 802BB67C 00000000 */   nop      
/* E2DFB0 802BB680 8E030000 */  lw        $v1, ($s0)
/* E2DFB4 802BB684 30621000 */  andi      $v0, $v1, 0x1000
/* E2DFB8 802BB688 10400011 */  beqz      $v0, .L802BB6D0
/* E2DFBC 802BB68C 2402EFFF */   addiu    $v0, $zero, -0x1001
/* E2DFC0 802BB690 00621024 */  and       $v0, $v1, $v0
/* E2DFC4 802BB694 AE020000 */  sw        $v0, ($s0)
/* E2DFC8 802BB698 0C04417A */  jal       get_entity_by_index
/* E2DFCC 802BB69C 94A40004 */   lhu      $a0, 4($a1)
/* E2DFD0 802BB6A0 8C450040 */  lw        $a1, 0x40($v0)
/* E2DFD4 802BB6A4 94A20000 */  lhu       $v0, ($a1)
/* E2DFD8 802BB6A8 14400009 */  bnez      $v0, .L802BB6D0
/* E2DFDC 802BB6AC 0200202D */   daddu    $a0, $s0, $zero
/* E2DFE0 802BB6B0 24020001 */  addiu     $v0, $zero, 1
/* E2DFE4 802BB6B4 0C043F5A */  jal       func_8010FD68
/* E2DFE8 802BB6B8 A4A20000 */   sh       $v0, ($a1)
/* E2DFEC 802BB6BC 86040014 */  lh        $a0, 0x14($s0)
/* E2DFF0 802BB6C0 3C050000 */  lui       $a1, 0
/* E2DFF4 802BB6C4 24A500F4 */  addiu     $a1, $a1, 0xf4
/* E2DFF8 802BB6C8 0C048052 */  jal       play_model_animation
/* E2DFFC 802BB6CC 00000000 */   nop      
.L802BB6D0:
/* E2E000 802BB6D0 8FBF0014 */  lw        $ra, 0x14($sp)
/* E2E004 802BB6D4 8FB00010 */  lw        $s0, 0x10($sp)
/* E2E008 802BB6D8 03E00008 */  jr        $ra
/* E2E00C 802BB6DC 27BD0018 */   addiu    $sp, $sp, 0x18
