.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_partners_draw_movelist_title
/* 13F388 8024C048 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 13F38C 8024C04C AFB00018 */  sw        $s0, 0x18($sp)
/* 13F390 8024C050 00A0802D */  daddu     $s0, $a1, $zero
/* 13F394 8024C054 AFB1001C */  sw        $s1, 0x1c($sp)
/* 13F398 8024C058 00C0882D */  daddu     $s1, $a2, $zero
/* 13F39C 8024C05C AFBF0020 */  sw        $ra, 0x20($sp)
/* 13F3A0 8024C060 0C093BA0 */  jal       pause_get_menu_string
/* 13F3A4 8024C064 24040055 */   addiu    $a0, $zero, 0x55
/* 13F3A8 8024C068 0040202D */  daddu     $a0, $v0, $zero
/* 13F3AC 8024C06C 2402FFFF */  addiu     $v0, $zero, -1
/* 13F3B0 8024C070 AFA20010 */  sw        $v0, 0x10($sp)
/* 13F3B4 8024C074 24020001 */  addiu     $v0, $zero, 1
/* 13F3B8 8024C078 2605000C */  addiu     $a1, $s0, 0xc
/* 13F3BC 8024C07C 02223021 */  addu      $a2, $s1, $v0
/* 13F3C0 8024C080 240700FF */  addiu     $a3, $zero, 0xff
/* 13F3C4 8024C084 0C04993B */  jal       draw_string
/* 13F3C8 8024C088 AFA20014 */   sw       $v0, 0x14($sp)
/* 13F3CC 8024C08C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 13F3D0 8024C090 8FB1001C */  lw        $s1, 0x1c($sp)
/* 13F3D4 8024C094 8FB00018 */  lw        $s0, 0x18($sp)
/* 13F3D8 8024C098 03E00008 */  jr        $ra
/* 13F3DC 8024C09C 27BD0028 */   addiu    $sp, $sp, 0x28
