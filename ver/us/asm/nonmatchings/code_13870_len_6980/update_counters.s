.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_counters
/* 19924 8003E524 3C03800A */  lui       $v1, %hi(gGameState)
/* 19928 8003E528 8C63A600 */  lw        $v1, %lo(gGameState)($v1)
/* 1992C 8003E52C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19930 8003E530 2C620006 */  sltiu     $v0, $v1, 6
/* 19934 8003E534 10400019 */  beqz      $v0, L8003E59C_1999C
/* 19938 8003E538 AFBF0010 */   sw       $ra, 0x10($sp)
/* 1993C 8003E53C 00031080 */  sll       $v0, $v1, 2
/* 19940 8003E540 3C01800A */  lui       $at, %hi(jtbl_800985C0)
/* 19944 8003E544 00220821 */  addu      $at, $at, $v0
/* 19948 8003E548 8C2285C0 */  lw        $v0, %lo(jtbl_800985C0)($at)
/* 1994C 8003E54C 00400008 */  jr        $v0
/* 19950 8003E550 00000000 */   nop
glabel L8003E554_19954
/* 19954 8003E554 0C010DAC */  jal       create_encounters
/* 19958 8003E558 00000000 */   nop
/* 1995C 8003E55C 0800F967 */  j         L8003E59C_1999C
/* 19960 8003E560 00000000 */   nop
glabel L8003E564_19964
/* 19964 8003E564 0C00FDF3 */  jal       update_encounters_neutral
/* 19968 8003E568 00000000 */   nop
/* 1996C 8003E56C 0800F967 */  j         L8003E59C_1999C
/* 19970 8003E570 00000000 */   nop
glabel L8003E574_19974
/* 19974 8003E574 0C0104D9 */  jal       update_encounters_pre_battle
/* 19978 8003E578 00000000 */   nop
/* 1997C 8003E57C 0800F967 */  j         L8003E59C_1999C
/* 19980 8003E580 00000000 */   nop
glabel L8003E584_19984
/* 19984 8003E584 0C010C27 */  jal       update_encounters_conversation
/* 19988 8003E588 00000000 */   nop
/* 1998C 8003E58C 0800F967 */  j         L8003E59C_1999C
/* 19990 8003E590 00000000 */   nop
glabel L8003E594_19994
/* 19994 8003E594 0C0107C4 */  jal       update_encounters_post_battle
/* 19998 8003E598 00000000 */   nop
glabel L8003E59C_1999C
/* 1999C 8003E59C 0C0116DA */  jal       update_merlee_messages
/* 199A0 8003E5A0 00000000 */   nop
/* 199A4 8003E5A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 199A8 8003E5A8 03E00008 */  jr        $ra
/* 199AC 8003E5AC 27BD0018 */   addiu    $sp, $sp, 0x18
