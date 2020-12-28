.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218170_4CF320
/* 4CF320 80218170 3C06800E */  lui       $a2, %hi(gBattleStatus)
/* 4CF324 80218174 24C6C070 */  addiu     $a2, $a2, %lo(gBattleStatus)
/* 4CF328 80218178 10A00002 */  beqz      $a1, .L80218184
/* 4CF32C 8021817C 2402000A */   addiu    $v0, $zero, 0xa
/* 4CF330 80218180 AC820070 */  sw        $v0, 0x70($a0)
.L80218184:
/* 4CF334 80218184 8CC20004 */  lw        $v0, 4($a2)
/* 4CF338 80218188 2403FFFD */  addiu     $v1, $zero, -3
/* 4CF33C 8021818C 00431024 */  and       $v0, $v0, $v1
/* 4CF340 80218190 ACC20004 */  sw        $v0, 4($a2)
/* 4CF344 80218194 8C820070 */  lw        $v0, 0x70($a0)
/* 4CF348 80218198 14400003 */  bnez      $v0, .L802181A8
/* 4CF34C 8021819C 2442FFFF */   addiu    $v0, $v0, -1
/* 4CF350 802181A0 03E00008 */  jr        $ra
/* 4CF354 802181A4 24020002 */   addiu    $v0, $zero, 2
.L802181A8:
/* 4CF358 802181A8 AC820070 */  sw        $v0, 0x70($a0)
/* 4CF35C 802181AC 03E00008 */  jr        $ra
/* 4CF360 802181B0 0000102D */   daddu    $v0, $zero, $zero
