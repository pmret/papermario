.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_update_hidden_options_right
/* 163F50 802436F0 3C028016 */  lui       $v0, %hi(gUIPanels)
/* 163F54 802436F4 24429D50 */  addiu     $v0, $v0, %lo(gUIPanels)
/* 163F58 802436F8 00042140 */  sll       $a0, $a0, 5
/* 163F5C 802436FC 00822021 */  addu      $a0, $a0, $v0
/* 163F60 80243700 9083001C */  lbu       $v1, 0x1c($a0)
/* 163F64 80243704 2862000A */  slti      $v0, $v1, 0xa
/* 163F68 80243708 10400008 */  beqz      $v0, .L8024372C
/* 163F6C 8024370C 00031040 */   sll      $v0, $v1, 1
/* 163F70 80243710 3C038025 */  lui       $v1, %hi(D_80249CB8)
/* 163F74 80243714 00621821 */  addu      $v1, $v1, $v0
/* 163F78 80243718 84639CB8 */  lh        $v1, %lo(D_80249CB8)($v1)
/* 163F7C 8024371C 8CC20000 */  lw        $v0, ($a2)
/* 163F80 80243720 00431023 */  subu      $v0, $v0, $v1
/* 163F84 80243724 03E00008 */  jr        $ra
/* 163F88 80243728 ACC20000 */   sw       $v0, ($a2)
.L8024372C:
/* 163F8C 8024372C 3C028025 */  lui       $v0, %hi(D_80249CCA)
/* 163F90 80243730 84429CCA */  lh        $v0, %lo(D_80249CCA)($v0)
/* 163F94 80243734 8CC30000 */  lw        $v1, ($a2)
/* 163F98 80243738 00621823 */  subu      $v1, $v1, $v0
/* 163F9C 8024373C ACC30000 */  sw        $v1, ($a2)
/* 163FA0 80243740 90820000 */  lbu       $v0, ($a0)
/* 163FA4 80243744 304200F7 */  andi      $v0, $v0, 0xf7
/* 163FA8 80243748 34420004 */  ori       $v0, $v0, 4
/* 163FAC 8024374C 03E00008 */  jr        $ra
/* 163FB0 80243750 A0820000 */   sb       $v0, ($a0)
