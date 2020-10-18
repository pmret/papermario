.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BDB84
/* 317AA4 802BDB84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 317AA8 802BDB88 AFBF0014 */  sw        $ra, 0x14($sp)
/* 317AAC 802BDB8C AFB00010 */  sw        $s0, 0x10($sp)
/* 317AB0 802BDB90 10A00003 */  beqz      $a1, .L802BDBA0
/* 317AB4 802BDB94 8C90014C */   lw       $s0, 0x14c($a0)
/* 317AB8 802BDB98 0C03BA65 */  jal       func_800EE994
/* 317ABC 802BDB9C 0200202D */   daddu    $a0, $s0, $zero
.L802BDBA0:
/* 317AC0 802BDBA0 0C03BA6E */  jal       func_800EE9B8
/* 317AC4 802BDBA4 0200202D */   daddu    $a0, $s0, $zero
/* 317AC8 802BDBA8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 317ACC 802BDBAC 8FB00010 */  lw        $s0, 0x10($sp)
/* 317AD0 802BDBB0 0002102B */  sltu      $v0, $zero, $v0
/* 317AD4 802BDBB4 03E00008 */  jr        $ra
/* 317AD8 802BDBB8 27BD0018 */   addiu    $sp, $sp, 0x18
