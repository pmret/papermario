.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_update_hidden_options_left
/* 163EEC 8024368C 3C028016 */  lui       $v0, %hi(gWindows)
/* 163EF0 80243690 24429D50 */  addiu     $v0, $v0, %lo(gWindows)
/* 163EF4 80243694 00042140 */  sll       $a0, $a0, 5
/* 163EF8 80243698 00822021 */  addu      $a0, $a0, $v0
/* 163EFC 8024369C 9083001C */  lbu       $v1, 0x1c($a0)
/* 163F00 802436A0 2862000A */  slti      $v0, $v1, 0xa
/* 163F04 802436A4 10400008 */  beqz      $v0, .L802436C8
/* 163F08 802436A8 00031040 */   sll      $v0, $v1, 1
/* 163F0C 802436AC 3C038025 */  lui       $v1, %hi(D_80249CA4)
/* 163F10 802436B0 00621821 */  addu      $v1, $v1, $v0
/* 163F14 802436B4 84639CA4 */  lh        $v1, %lo(D_80249CA4)($v1)
/* 163F18 802436B8 8CC20000 */  lw        $v0, ($a2)
/* 163F1C 802436BC 00431021 */  addu      $v0, $v0, $v1
/* 163F20 802436C0 03E00008 */  jr        $ra
/* 163F24 802436C4 ACC20000 */   sw       $v0, ($a2)
.L802436C8:
/* 163F28 802436C8 3C028025 */  lui       $v0, %hi(D_80249CB6)
/* 163F2C 802436CC 84429CB6 */  lh        $v0, %lo(D_80249CB6)($v0)
/* 163F30 802436D0 8CC30000 */  lw        $v1, ($a2)
/* 163F34 802436D4 00621821 */  addu      $v1, $v1, $v0
/* 163F38 802436D8 ACC30000 */  sw        $v1, ($a2)
/* 163F3C 802436DC 90820000 */  lbu       $v0, ($a0)
/* 163F40 802436E0 304200F7 */  andi      $v0, $v0, 0xf7
/* 163F44 802436E4 34420004 */  ori       $v0, $v0, 4
/* 163F48 802436E8 03E00008 */  jr        $ra
/* 163F4C 802436EC A0820000 */   sb       $v0, ($a0)
