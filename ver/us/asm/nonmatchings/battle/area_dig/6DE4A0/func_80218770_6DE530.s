.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218770_6DE530
/* 6DE530 80218770 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6DE534 80218774 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 6DE538 80218778 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 6DE53C 8021877C AFBF0014 */  sw        $ra, 0x14($sp)
/* 6DE540 80218780 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DE544 80218784 8C7000DC */  lw        $s0, 0xdc($v1)
/* 6DE548 80218788 24020006 */  addiu     $v0, $zero, 6
/* 6DE54C 8021878C A0620178 */  sb        $v0, 0x178($v1)
/* 6DE550 80218790 A460017A */  sh        $zero, 0x17a($v1)
/* 6DE554 80218794 3C048009 */  lui       $a0, %hi(D_8008FC44)
/* 6DE558 80218798 8C84FC44 */  lw        $a0, %lo(D_8008FC44)($a0)
/* 6DE55C 8021879C 24020098 */  addiu     $v0, $zero, 0x98
/* 6DE560 802187A0 A462017C */  sh        $v0, 0x17c($v1)
/* 6DE564 802187A4 AC640184 */  sw        $a0, 0x184($v1)
/* 6DE568 802187A8 0C098C0B */  jal       player_create_target_list
/* 6DE56C 802187AC 0200202D */   daddu    $a0, $s0, $zero
/* 6DE570 802187B0 8203040D */  lb        $v1, 0x40d($s0)
/* 6DE574 802187B4 A2000425 */  sb        $zero, 0x425($s0)
/* 6DE578 802187B8 00031080 */  sll       $v0, $v1, 2
/* 6DE57C 802187BC 00431021 */  addu      $v0, $v0, $v1
/* 6DE580 802187C0 00021080 */  sll       $v0, $v0, 2
/* 6DE584 802187C4 2442022C */  addiu     $v0, $v0, 0x22c
/* 6DE588 802187C8 02021021 */  addu      $v0, $s0, $v0
/* 6DE58C 802187CC 94430000 */  lhu       $v1, ($v0)
/* 6DE590 802187D0 A6030428 */  sh        $v1, 0x428($s0)
/* 6DE594 802187D4 90420003 */  lbu       $v0, 3($v0)
/* 6DE598 802187D8 A2020426 */  sb        $v0, 0x426($s0)
/* 6DE59C 802187DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6DE5A0 802187E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DE5A4 802187E4 24020002 */  addiu     $v0, $zero, 2
/* 6DE5A8 802187E8 03E00008 */  jr        $ra
/* 6DE5AC 802187EC 27BD0018 */   addiu    $sp, $sp, 0x18
