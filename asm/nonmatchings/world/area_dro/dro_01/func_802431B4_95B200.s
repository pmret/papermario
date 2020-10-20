.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802431B4_95E3B4
/* 95E3B4 802431B4 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 95E3B8 802431B8 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 95E3BC 802431BC 8C6202BC */  lw        $v0, 0x2bc($v1)
/* 95E3C0 802431C0 8C630328 */  lw        $v1, 0x328($v1)
/* 95E3C4 802431C4 00431023 */  subu      $v0, $v0, $v1
/* 95E3C8 802431C8 3C0391A2 */  lui       $v1, 0x91a2
/* 95E3CC 802431CC 3463B3C5 */  ori       $v1, $v1, 0xb3c5
/* 95E3D0 802431D0 00430019 */  multu     $v0, $v1
/* 95E3D4 802431D4 00002810 */  mfhi      $a1
/* 95E3D8 802431D8 000512C2 */  srl       $v0, $a1, 0xb
/* 95E3DC 802431DC 2842001E */  slti      $v0, $v0, 0x1e
/* 95E3E0 802431E0 10400003 */  beqz      $v0, .L802431F0
/* 95E3E4 802431E4 24020001 */   addiu    $v0, $zero, 1
/* 95E3E8 802431E8 08090C7D */  j         .L802431F4
/* 95E3EC 802431EC AC820084 */   sw       $v0, 0x84($a0)
.L802431F0:
/* 95E3F0 802431F0 AC800084 */  sw        $zero, 0x84($a0)
.L802431F4:
/* 95E3F4 802431F4 03E00008 */  jr        $ra
/* 95E3F8 802431F8 24020002 */   addiu    $v0, $zero, 2
