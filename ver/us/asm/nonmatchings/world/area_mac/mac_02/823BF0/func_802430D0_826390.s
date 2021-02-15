.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802430D0_826390
/* 826390 802430D0 2404005A */  addiu     $a0, $zero, 0x5a
/* 826394 802430D4 3C038025 */  lui       $v1, %hi(D_8024EA10)
/* 826398 802430D8 2463EA10 */  addiu     $v1, $v1, %lo(D_8024EA10)
/* 82639C 802430DC 240200DA */  addiu     $v0, $zero, 0xda
.L802430E0:
/* 8263A0 802430E0 AC620000 */  sw        $v0, ($v1)
/* 8263A4 802430E4 2463FFFC */  addiu     $v1, $v1, -4
/* 8263A8 802430E8 2484FFFF */  addiu     $a0, $a0, -1
/* 8263AC 802430EC 0481FFFC */  bgez      $a0, .L802430E0
/* 8263B0 802430F0 2442FFFF */   addiu    $v0, $v0, -1
/* 8263B4 802430F4 3C018025 */  lui       $at, %hi(D_8024EA14)
/* 8263B8 802430F8 AC20EA14 */  sw        $zero, %lo(D_8024EA14)($at)
/* 8263BC 802430FC 03E00008 */  jr        $ra
/* 8263C0 80243100 24020002 */   addiu    $v0, $zero, 2
