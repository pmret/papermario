.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_update_show_options_right
/* 163CC8 80243468 3C028016 */  lui       $v0, %hi(gUIPanels)
/* 163CCC 8024346C 24429D50 */  addiu     $v0, $v0, %lo(gUIPanels)
/* 163CD0 80243470 00042140 */  sll       $a0, $a0, 5
/* 163CD4 80243474 00822021 */  addu      $a0, $a0, $v0
/* 163CD8 80243478 9083001C */  lbu       $v1, 0x1c($a0)
/* 163CDC 8024347C 14600005 */  bnez      $v1, .L80243494
/* 163CE0 80243480 28620010 */   slti     $v0, $v1, 0x10
/* 163CE4 80243484 90820000 */  lbu       $v0, ($a0)
/* 163CE8 80243488 304200FB */  andi      $v0, $v0, 0xfb
/* 163CEC 8024348C A0820000 */  sb        $v0, ($a0)
/* 163CF0 80243490 28620010 */  slti      $v0, $v1, 0x10
.L80243494:
/* 163CF4 80243494 10400008 */  beqz      $v0, .L802434B8
/* 163CF8 80243498 00031040 */   sll      $v0, $v1, 1
/* 163CFC 8024349C 3C038025 */  lui       $v1, %hi(D_80249C1C)
/* 163D00 802434A0 00621821 */  addu      $v1, $v1, $v0
/* 163D04 802434A4 84639C1C */  lh        $v1, %lo(D_80249C1C)($v1)
/* 163D08 802434A8 8CC20000 */  lw        $v0, ($a2)
/* 163D0C 802434AC 00431021 */  addu      $v0, $v0, $v1
/* 163D10 802434B0 03E00008 */  jr        $ra
/* 163D14 802434B4 ACC20000 */   sw       $v0, ($a2)
.L802434B8:
/* 163D18 802434B8 3C028025 */  lui       $v0, %hi(D_80249C3A)
/* 163D1C 802434BC 84429C3A */  lh        $v0, %lo(D_80249C3A)($v0)
/* 163D20 802434C0 8CC30000 */  lw        $v1, ($a2)
/* 163D24 802434C4 00621821 */  addu      $v1, $v1, $v0
/* 163D28 802434C8 ACC30000 */  sw        $v1, ($a2)
/* 163D2C 802434CC 90820000 */  lbu       $v0, ($a0)
/* 163D30 802434D0 304200F7 */  andi      $v0, $v0, 0xf7
/* 163D34 802434D4 03E00008 */  jr        $ra
/* 163D38 802434D8 A0820000 */   sb       $v0, ($a0)
