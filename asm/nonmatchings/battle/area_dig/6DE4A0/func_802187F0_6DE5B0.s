.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802187F0_6DE5B0
/* 6DE5B0 802187F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6DE5B4 802187F4 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 6DE5B8 802187F8 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 6DE5BC 802187FC 24020002 */  addiu     $v0, $zero, 2
/* 6DE5C0 80218800 AFBF0014 */  sw        $ra, 0x14($sp)
/* 6DE5C4 80218804 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DE5C8 80218808 A0620178 */  sb        $v0, 0x178($v1)
/* 6DE5CC 8021880C 24020082 */  addiu     $v0, $zero, 0x82
/* 6DE5D0 80218810 A462017A */  sh        $v0, 0x17a($v1)
/* 6DE5D4 80218814 24020082 */  addiu     $v0, $zero, 0x82
/* 6DE5D8 80218818 A460017C */  sh        $zero, 0x17c($v1)
/* 6DE5DC 8021881C AC600188 */  sw        $zero, 0x188($v1)
/* 6DE5E0 80218820 3C018011 */  lui       $at, %hi(gPlayerData+0x1B4)
/* 6DE5E4 80218824 A422F444 */  sh        $v0, %lo(gPlayerData+0x1B4)($at)
/* 6DE5E8 80218828 3C028009 */  lui       $v0, %hi(gItemTable+0x1048)
/* 6DE5EC 8021882C 8C428928 */  lw        $v0, %lo(gItemTable+0x1048)($v0)
/* 6DE5F0 80218830 8C7000D8 */  lw        $s0, 0xd8($v1)
/* 6DE5F4 80218834 34428000 */  ori       $v0, $v0, 0x8000
/* 6DE5F8 80218838 0200202D */  daddu     $a0, $s0, $zero
/* 6DE5FC 8021883C 0C098C0B */  jal       player_create_target_list
/* 6DE600 80218840 AC620184 */   sw       $v0, 0x184($v1)
/* 6DE604 80218844 8203040D */  lb        $v1, 0x40d($s0)
/* 6DE608 80218848 A2000425 */  sb        $zero, 0x425($s0)
/* 6DE60C 8021884C 00031080 */  sll       $v0, $v1, 2
/* 6DE610 80218850 00431021 */  addu      $v0, $v0, $v1
/* 6DE614 80218854 00021080 */  sll       $v0, $v0, 2
/* 6DE618 80218858 2442022C */  addiu     $v0, $v0, 0x22c
/* 6DE61C 8021885C 02021021 */  addu      $v0, $s0, $v0
/* 6DE620 80218860 94430000 */  lhu       $v1, ($v0)
/* 6DE624 80218864 A6030428 */  sh        $v1, 0x428($s0)
/* 6DE628 80218868 90420003 */  lbu       $v0, 3($v0)
/* 6DE62C 8021886C A2020426 */  sb        $v0, 0x426($s0)
/* 6DE630 80218870 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6DE634 80218874 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DE638 80218878 24020002 */  addiu     $v0, $zero, 2
/* 6DE63C 8021887C 03E00008 */  jr        $ra
/* 6DE640 80218880 27BD0018 */   addiu    $sp, $sp, 0x18
/* 6DE644 80218884 00000000 */  nop       
/* 6DE648 80218888 00000000 */  nop       
/* 6DE64C 8021888C 00000000 */  nop       
