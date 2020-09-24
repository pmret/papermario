.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel disable_player_input
/* 79628 800E0178 3C038011 */  lui       $v1, 0x8011
/* 7962C 800E017C 2463EFC8 */  addiu     $v1, $v1, -0x1038
/* 79630 800E0180 8C640000 */  lw        $a0, ($v1)
/* 79634 800E0184 90620015 */  lbu       $v0, 0x15($v1)
/* 79638 800E0188 34842000 */  ori       $a0, $a0, 0x2000
/* 7963C 800E018C 24420001 */  addiu     $v0, $v0, 1
/* 79640 800E0190 A0620015 */  sb        $v0, 0x15($v1)
/* 79644 800E0194 00021600 */  sll       $v0, $v0, 0x18
/* 79648 800E0198 00021603 */  sra       $v0, $v0, 0x18
/* 7964C 800E019C 03E00008 */  jr        $ra
/* 79650 800E01A0 AC640000 */   sw       $a0, ($v1)
