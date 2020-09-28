.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E581C
/* 10709C 802E581C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1070A0 802E5820 AFB00010 */  sw        $s0, 0x10($sp)
/* 1070A4 802E5824 0080802D */  daddu     $s0, $a0, $zero
/* 1070A8 802E5828 AFBF0014 */  sw        $ra, 0x14($sp)
/* 1070AC 802E582C 8E020040 */  lw        $v0, 0x40($s0)
/* 1070B0 802E5830 0C04417A */  jal       get_entity_by_index
/* 1070B4 802E5834 90440000 */   lbu      $a0, ($v0)
/* 1070B8 802E5838 C4400048 */  lwc1      $f0, 0x48($v0)
/* 1070BC 802E583C 3C014160 */  lui       $at, 0x4160
/* 1070C0 802E5840 44811000 */  mtc1      $at, $f2
/* 1070C4 802E5844 E6000048 */  swc1      $f0, 0x48($s0)
/* 1070C8 802E5848 C440004C */  lwc1      $f0, 0x4c($v0)
/* 1070CC 802E584C 46020000 */  add.s     $f0, $f0, $f2
/* 1070D0 802E5850 E600004C */  swc1      $f0, 0x4c($s0)
/* 1070D4 802E5854 C4400050 */  lwc1      $f0, 0x50($v0)
/* 1070D8 802E5858 E6000050 */  swc1      $f0, 0x50($s0)
/* 1070DC 802E585C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1070E0 802E5860 8FB00010 */  lw        $s0, 0x10($sp)
/* 1070E4 802E5864 03E00008 */  jr        $ra
/* 1070E8 802E5868 27BD0018 */   addiu    $sp, $sp, 0x18
