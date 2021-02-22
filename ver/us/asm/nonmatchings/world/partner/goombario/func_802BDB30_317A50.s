.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BDB30_317A50
/* 317A50 802BDB30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 317A54 802BDB34 0000202D */  daddu     $a0, $zero, $zero
/* 317A58 802BDB38 AFBF0014 */  sw        $ra, 0x14($sp)
/* 317A5C 802BDB3C 0C009C22 */  jal       func_80027088
/* 317A60 802BDB40 AFB00010 */   sw       $s0, 0x10($sp)
/* 317A64 802BDB44 3C03802C */  lui       $v1, %hi(func_802BDF64_3248B4)
/* 317A68 802BDB48 2463DF64 */  addiu     $v1, $v1, %lo(func_802BDF64_3248B4)
/* 317A6C 802BDB4C 8C620000 */  lw        $v0, ($v1)
/* 317A70 802BDB50 3C108011 */  lui       $s0, %hi(D_8010EBB0)
/* 317A74 802BDB54 2610EBB0 */  addiu     $s0, $s0, %lo(D_8010EBB0)
/* 317A78 802BDB58 50400004 */  beql      $v0, $zero, .L802BDB6C
/* 317A7C 802BDB5C A2000000 */   sb       $zero, ($s0)
/* 317A80 802BDB60 0C038069 */  jal       enable_player_input
/* 317A84 802BDB64 AC600000 */   sw       $zero, ($v1)
/* 317A88 802BDB68 A2000000 */  sb        $zero, ($s0)
.L802BDB6C:
/* 317A8C 802BDB6C A2000003 */  sb        $zero, 3($s0)
/* 317A90 802BDB70 8FBF0014 */  lw        $ra, 0x14($sp)
/* 317A94 802BDB74 8FB00010 */  lw        $s0, 0x10($sp)
/* 317A98 802BDB78 24020002 */  addiu     $v0, $zero, 2
/* 317A9C 802BDB7C 03E00008 */  jr        $ra
/* 317AA0 802BDB80 27BD0018 */   addiu    $sp, $sp, 0x18
