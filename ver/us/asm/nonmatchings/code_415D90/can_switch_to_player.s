.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel can_switch_to_player
/* 41A5A8 802A5818 3C06800E */  lui       $a2, %hi(gBattleStatus)
/* 41A5AC 802A581C 24C6C070 */  addiu     $a2, $a2, %lo(gBattleStatus)
/* 41A5B0 802A5820 8CC20004 */  lw        $v0, 4($a2)
/* 41A5B4 802A5824 8CC500D8 */  lw        $a1, 0xd8($a2)
/* 41A5B8 802A5828 30420002 */  andi      $v0, $v0, 2
/* 41A5BC 802A582C 14400026 */  bnez      $v0, .L802A58C8
/* 41A5C0 802A5830 0000102D */   daddu    $v0, $zero, $zero
/* 41A5C4 802A5834 80A20216 */  lb        $v0, 0x216($a1)
/* 41A5C8 802A5838 80A30210 */  lb        $v1, 0x210($a1)
/* 41A5CC 802A583C 3842000D */  xori      $v0, $v0, 0xd
/* 41A5D0 802A5840 2C440001 */  sltiu     $a0, $v0, 1
/* 41A5D4 802A5844 24020009 */  addiu     $v0, $zero, 9
/* 41A5D8 802A5848 50620001 */  beql      $v1, $v0, .L802A5850
/* 41A5DC 802A584C 0000202D */   daddu    $a0, $zero, $zero
.L802A5850:
/* 41A5E0 802A5850 2402000A */  addiu     $v0, $zero, 0xa
/* 41A5E4 802A5854 50620001 */  beql      $v1, $v0, .L802A585C
/* 41A5E8 802A5858 0000202D */   daddu    $a0, $zero, $zero
.L802A585C:
/* 41A5EC 802A585C 24020006 */  addiu     $v0, $zero, 6
/* 41A5F0 802A5860 50620001 */  beql      $v1, $v0, .L802A5868
/* 41A5F4 802A5864 24040001 */   addiu    $a0, $zero, 1
.L802A5868:
/* 41A5F8 802A5868 24020003 */  addiu     $v0, $zero, 3
/* 41A5FC 802A586C 50620001 */  beql      $v1, $v0, .L802A5874
/* 41A600 802A5870 24040001 */   addiu    $a0, $zero, 1
.L802A5874:
/* 41A604 802A5874 24020004 */  addiu     $v0, $zero, 4
/* 41A608 802A5878 50620001 */  beql      $v1, $v0, .L802A5880
/* 41A60C 802A587C 24040001 */   addiu    $a0, $zero, 1
.L802A5880:
/* 41A610 802A5880 24020005 */  addiu     $v0, $zero, 5
/* 41A614 802A5884 50620001 */  beql      $v1, $v0, .L802A588C
/* 41A618 802A5888 24040001 */   addiu    $a0, $zero, 1
.L802A588C:
/* 41A61C 802A588C 24020007 */  addiu     $v0, $zero, 7
/* 41A620 802A5890 50620001 */  beql      $v1, $v0, .L802A5898
/* 41A624 802A5894 24040001 */   addiu    $a0, $zero, 1
.L802A5898:
/* 41A628 802A5898 24020008 */  addiu     $v0, $zero, 8
/* 41A62C 802A589C 50620001 */  beql      $v1, $v0, .L802A58A4
/* 41A630 802A58A0 24040001 */   addiu    $a0, $zero, 1
.L802A58A4:
/* 41A634 802A58A4 80A30214 */  lb        $v1, 0x214($a1)
/* 41A638 802A58A8 2402000C */  addiu     $v0, $zero, 0xc
/* 41A63C 802A58AC 50620001 */  beql      $v1, $v0, .L802A58B4
/* 41A640 802A58B0 24040001 */   addiu    $a0, $zero, 1
.L802A58B4:
/* 41A644 802A58B4 80C2009A */  lb        $v0, 0x9a($a2)
/* 41A648 802A58B8 54400001 */  bnel      $v0, $zero, .L802A58C0
/* 41A64C 802A58BC 24040001 */   addiu    $a0, $zero, 1
.L802A58C0:
/* 41A650 802A58C0 03E00008 */  jr        $ra
/* 41A654 802A58C4 38820001 */   xori     $v0, $a0, 1
.L802A58C8:
/* 41A658 802A58C8 03E00008 */  jr        $ra
/* 41A65C 802A58CC 00000000 */   nop
