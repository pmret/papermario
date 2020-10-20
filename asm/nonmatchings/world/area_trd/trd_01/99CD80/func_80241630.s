.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241630
/* 99DFC0 80241630 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 99DFC4 80241634 0080102D */  daddu     $v0, $a0, $zero
/* 99DFC8 80241638 AFBF0014 */  sw        $ra, 0x14($sp)
/* 99DFCC 8024163C AFB00010 */  sw        $s0, 0x10($sp)
/* 99DFD0 80241640 8C44014C */  lw        $a0, 0x14c($v0)
/* 99DFD4 80241644 0C00EAD2 */  jal       get_npc_safe
/* 99DFD8 80241648 8C500148 */   lw       $s0, 0x148($v0)
/* 99DFDC 8024164C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* 99DFE0 80241650 C4400038 */  lwc1      $f0, 0x38($v0)
/* 99DFE4 80241654 4600008D */  trunc.w.s $f2, $f0
/* 99DFE8 80241658 E4620000 */  swc1      $f2, ($v1)
/* 99DFEC 8024165C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* 99DFF0 80241660 C440003C */  lwc1      $f0, 0x3c($v0)
/* 99DFF4 80241664 4600008D */  trunc.w.s $f2, $f0
/* 99DFF8 80241668 E4620004 */  swc1      $f2, 4($v1)
/* 99DFFC 8024166C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* 99E000 80241670 C4400040 */  lwc1      $f0, 0x40($v0)
/* 99E004 80241674 4600008D */  trunc.w.s $f2, $f0
/* 99E008 80241678 E4620008 */  swc1      $f2, 8($v1)
/* 99E00C 8024167C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* 99E010 80241680 C4400038 */  lwc1      $f0, 0x38($v0)
/* 99E014 80241684 4600008D */  trunc.w.s $f2, $f0
/* 99E018 80241688 E462001C */  swc1      $f2, 0x1c($v1)
/* 99E01C 8024168C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* 99E020 80241690 C440003C */  lwc1      $f0, 0x3c($v0)
/* 99E024 80241694 4600008D */  trunc.w.s $f2, $f0
/* 99E028 80241698 E4620020 */  swc1      $f2, 0x20($v1)
/* 99E02C 8024169C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* 99E030 802416A0 C4400040 */  lwc1      $f0, 0x40($v0)
/* 99E034 802416A4 4600008D */  trunc.w.s $f2, $f0
/* 99E038 802416A8 E4620024 */  swc1      $f2, 0x24($v1)
/* 99E03C 802416AC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 99E040 802416B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 99E044 802416B4 24020002 */  addiu     $v0, $zero, 2
/* 99E048 802416B8 03E00008 */  jr        $ra
/* 99E04C 802416BC 27BD0018 */   addiu    $sp, $sp, 0x18
