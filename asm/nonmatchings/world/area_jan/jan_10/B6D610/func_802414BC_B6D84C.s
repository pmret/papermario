.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414BC_B6D84C
/* B6D84C 802414BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B6D850 802414C0 AFB00010 */  sw        $s0, 0x10($sp)
/* B6D854 802414C4 0080802D */  daddu     $s0, $a0, $zero
/* B6D858 802414C8 AFBF0014 */  sw        $ra, 0x14($sp)
/* B6D85C 802414CC 0C00FB5A */  jal       get_enemy_safe
/* B6D860 802414D0 24040001 */   addiu    $a0, $zero, 1
/* B6D864 802414D4 14400003 */  bnez      $v0, .L802414E4
/* B6D868 802414D8 24020001 */   addiu    $v0, $zero, 1
/* B6D86C 802414DC 0809053A */  j         .L802414E8
/* B6D870 802414E0 AE000084 */   sw       $zero, 0x84($s0)
.L802414E4:
/* B6D874 802414E4 AE020084 */  sw        $v0, 0x84($s0)
.L802414E8:
/* B6D878 802414E8 8FBF0014 */  lw        $ra, 0x14($sp)
/* B6D87C 802414EC 8FB00010 */  lw        $s0, 0x10($sp)
/* B6D880 802414F0 24020002 */  addiu     $v0, $zero, 2
/* B6D884 802414F4 03E00008 */  jr        $ra
/* B6D888 802414F8 27BD0018 */   addiu    $sp, $sp, 0x18
/* B6D88C 802414FC 00000000 */  nop
