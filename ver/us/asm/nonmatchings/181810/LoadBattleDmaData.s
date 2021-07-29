.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel LoadBattleDmaData
/* 181F04 80253624 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 181F08 80253628 AFBF0010 */  sw        $ra, 0x10($sp)
/* 181F0C 8025362C 8C82000C */  lw        $v0, 0xc($a0)
/* 181F10 80253630 0C0B1EAF */  jal       get_variable
/* 181F14 80253634 8C450000 */   lw       $a1, ($v0)
/* 181F18 80253638 00021840 */  sll       $v1, $v0, 1
/* 181F1C 8025363C 3C04800E */  lui       $a0, %hi(gCurrentBattleSection)
/* 181F20 80253640 9084C4EA */  lbu       $a0, %lo(gCurrentBattleSection)($a0)
/* 181F24 80253644 00621821 */  addu      $v1, $v1, $v0
/* 181F28 80253648 00042140 */  sll       $a0, $a0, 5
/* 181F2C 8025364C 3C028009 */  lui       $v0, %hi(gBattleAreas+0x1C)
/* 181F30 80253650 00441021 */  addu      $v0, $v0, $a0
/* 181F34 80253654 8C425A4C */  lw        $v0, %lo(gBattleAreas+0x1C)($v0)
/* 181F38 80253658 00031880 */  sll       $v1, $v1, 2
/* 181F3C 8025365C 00431021 */  addu      $v0, $v0, $v1
/* 181F40 80253660 5040000E */  beql      $v0, $zero, .L8025369C
/* 181F44 80253664 24020002 */   addiu    $v0, $zero, 2
/* 181F48 80253668 3C068028 */  lui       $a2, %hi(gBattleDmaDest)
/* 181F4C 8025366C 8CC64000 */  lw        $a2, %lo(gBattleDmaDest)($a2)
/* 181F50 80253670 14C00005 */  bnez      $a2, .L80253688
/* 181F54 80253674 00000000 */   nop
/* 181F58 80253678 8C440000 */  lw        $a0, ($v0)
/* 181F5C 8025367C 8C450004 */  lw        $a1, 4($v0)
/* 181F60 80253680 08094DA4 */  j         .L80253690
/* 181F64 80253684 8C460008 */   lw       $a2, 8($v0)
.L80253688:
/* 181F68 80253688 8C440000 */  lw        $a0, ($v0)
/* 181F6C 8025368C 8C450004 */  lw        $a1, 4($v0)
.L80253690:
/* 181F70 80253690 0C00A5CF */  jal       dma_copy
/* 181F74 80253694 00000000 */   nop
/* 181F78 80253698 24020002 */  addiu     $v0, $zero, 2
.L8025369C:
/* 181F7C 8025369C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 181F80 802536A0 03E00008 */  jr        $ra
/* 181F84 802536A4 27BD0018 */   addiu    $sp, $sp, 0x18
