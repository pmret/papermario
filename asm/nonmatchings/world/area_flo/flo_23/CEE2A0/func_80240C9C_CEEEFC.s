.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C9C_CEEEFC
/* CEEEFC 80240C9C 2404005A */  addiu     $a0, $zero, 0x5a
/* CEEF00 80240CA0 3C038024 */  lui       $v1, %hi(D_802429B8)
/* CEEF04 80240CA4 246329B8 */  addiu     $v1, $v1, %lo(D_802429B8)
/* CEEF08 80240CA8 240200DA */  addiu     $v0, $zero, 0xda
.L80240CAC:
/* CEEF0C 80240CAC AC620000 */  sw        $v0, ($v1)
/* CEEF10 80240CB0 2463FFFC */  addiu     $v1, $v1, -4
/* CEEF14 80240CB4 2484FFFF */  addiu     $a0, $a0, -1
/* CEEF18 80240CB8 0481FFFC */  bgez      $a0, .L80240CAC
/* CEEF1C 80240CBC 2442FFFF */   addiu    $v0, $v0, -1
/* CEEF20 80240CC0 3C018024 */  lui       $at, %hi(D_802429BC)
/* CEEF24 80240CC4 AC2029BC */  sw        $zero, %lo(D_802429BC)($at)
/* CEEF28 80240CC8 03E00008 */  jr        $ra
/* CEEF2C 80240CCC 24020002 */   addiu    $v0, $zero, 2
