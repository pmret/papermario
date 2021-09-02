.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_update_hidden_name_input
/* 163E88 80243628 3C028016 */  lui       $v0, %hi(gWindows)
/* 163E8C 8024362C 24429D50 */  addiu     $v0, $v0, %lo(gWindows)
/* 163E90 80243630 00042140 */  sll       $a0, $a0, 5
/* 163E94 80243634 00822021 */  addu      $a0, $a0, $v0
/* 163E98 80243638 9083001C */  lbu       $v1, 0x1c($a0)
/* 163E9C 8024363C 2862000A */  slti      $v0, $v1, 0xa
/* 163EA0 80243640 10400008 */  beqz      $v0, .L80243664
/* 163EA4 80243644 00031040 */   sll      $v0, $v1, 1
/* 163EA8 80243648 3C038025 */  lui       $v1, %hi(D_80249C90)
/* 163EAC 8024364C 00621821 */  addu      $v1, $v1, $v0
/* 163EB0 80243650 84639C90 */  lh        $v1, %lo(D_80249C90)($v1)
/* 163EB4 80243654 8CC20000 */  lw        $v0, ($a2)
/* 163EB8 80243658 00431023 */  subu      $v0, $v0, $v1
/* 163EBC 8024365C 03E00008 */  jr        $ra
/* 163EC0 80243660 ACC20000 */   sw       $v0, ($a2)
.L80243664:
/* 163EC4 80243664 3C028025 */  lui       $v0, %hi(D_80249CA2)
/* 163EC8 80243668 84429CA2 */  lh        $v0, %lo(D_80249CA2)($v0)
/* 163ECC 8024366C 8CC30000 */  lw        $v1, ($a2)
/* 163ED0 80243670 00621823 */  subu      $v1, $v1, $v0
/* 163ED4 80243674 ACC30000 */  sw        $v1, ($a2)
/* 163ED8 80243678 90820000 */  lbu       $v0, ($a0)
/* 163EDC 8024367C 304200F7 */  andi      $v0, $v0, 0xf7
/* 163EE0 80243680 34420004 */  ori       $v0, $v0, 4
/* 163EE4 80243684 03E00008 */  jr        $ra
/* 163EE8 80243688 A0820000 */   sb       $v0, ($a0)
