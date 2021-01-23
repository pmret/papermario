.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E7CB8
/* 109538 802E7CB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10953C 802E7CBC AFBF0014 */  sw        $ra, 0x14($sp)
/* 109540 802E7CC0 AFB00010 */  sw        $s0, 0x10($sp)
/* 109544 802E7CC4 8C900040 */  lw        $s0, 0x40($a0)
/* 109548 802E7CC8 8E020010 */  lw        $v0, 0x10($s0)
/* 10954C 802E7CCC 10400010 */  beqz      $v0, .L802E7D10
/* 109550 802E7CD0 00000000 */   nop
/* 109554 802E7CD4 82020030 */  lb        $v0, 0x30($s0)
/* 109558 802E7CD8 1040000F */  beqz      $v0, .L802E7D18
/* 10955C 802E7CDC 00000000 */   nop
/* 109560 802E7CE0 0C043F5A */  jal       exec_entity_updatecmd
/* 109564 802E7CE4 00000000 */   nop
/* 109568 802E7CE8 0C04CE7F */  jal       remove_item_entity_by_index
/* 10956C 802E7CEC 8E040014 */   lw       $a0, 0x14($s0)
/* 109570 802E7CF0 3C040001 */  lui       $a0, 1
/* 109574 802E7CF4 0C037FBF */  jal       func_800DFEFC
/* 109578 802E7CF8 34840002 */   ori      $a0, $a0, 2
/* 10957C 802E7CFC 0C038069 */  jal       enable_player_input
/* 109580 802E7D00 00000000 */   nop
/* 109584 802E7D04 2402FFFF */  addiu     $v0, $zero, -1
/* 109588 802E7D08 080B9F46 */  j         .L802E7D18
/* 10958C 802E7D0C AE020010 */   sw       $v0, 0x10($s0)
.L802E7D10:
/* 109590 802E7D10 0C043F5A */  jal       exec_entity_updatecmd
/* 109594 802E7D14 00000000 */   nop
.L802E7D18:
/* 109598 802E7D18 8FBF0014 */  lw        $ra, 0x14($sp)
/* 10959C 802E7D1C 8FB00010 */  lw        $s0, 0x10($sp)
/* 1095A0 802E7D20 03E00008 */  jr        $ra
/* 1095A4 802E7D24 27BD0018 */   addiu    $sp, $sp, 0x18
