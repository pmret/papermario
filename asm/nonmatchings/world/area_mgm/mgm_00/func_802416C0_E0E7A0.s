.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416C0_E0FE60
/* E0FE60 802416C0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E0FE64 802416C4 2402002D */  addiu     $v0, $zero, 0x2d
/* E0FE68 802416C8 AFA20010 */  sw        $v0, 0x10($sp)
/* E0FE6C 802416CC 3C028024 */  lui       $v0, 0x8024
/* E0FE70 802416D0 24421540 */  addiu     $v0, $v0, 0x1540
/* E0FE74 802416D4 27A40010 */  addiu     $a0, $sp, 0x10
/* E0FE78 802416D8 AFBF0020 */  sw        $ra, 0x20($sp)
/* E0FE7C 802416DC AFA00018 */  sw        $zero, 0x18($sp)
/* E0FE80 802416E0 AFA2001C */  sw        $v0, 0x1c($sp)
/* E0FE84 802416E4 0C047644 */  jal       queue_render_task
/* E0FE88 802416E8 AFA00014 */   sw       $zero, 0x14($sp)
/* E0FE8C 802416EC 8FBF0020 */  lw        $ra, 0x20($sp)
/* E0FE90 802416F0 03E00008 */  jr        $ra
/* E0FE94 802416F4 27BD0028 */   addiu    $sp, $sp, 0x28
