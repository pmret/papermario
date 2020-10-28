.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80283174
/* 7E3FF4 80283174 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* 7E3FF8 80283178 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* 7E3FFC 8028317C 8C8200B0 */  lw        $v0, 0xb0($a0)
/* 7E4000 80283180 3C038016 */  lui       $v1, %hi(gCollisionStatus)
/* 7E4004 80283184 8463A550 */  lh        $v1, %lo(gCollisionStatus)($v1)
/* 7E4008 80283188 24424000 */  addiu     $v0, $v0, 0x4000
/* 7E400C 8028318C 5462000F */  bnel      $v1, $v0, .L802831CC
/* 7E4010 80283190 AC8000B8 */   sw       $zero, 0xb8($a0)
/* 7E4014 80283194 80A300B4 */  lb        $v1, 0xb4($a1)
/* 7E4018 80283198 24020014 */  addiu     $v0, $zero, 0x14
/* 7E401C 8028319C 10620005 */  beq       $v1, $v0, .L802831B4
/* 7E4020 802831A0 24020001 */   addiu    $v0, $zero, 1
/* 7E4024 802831A4 10620003 */  beq       $v1, $v0, .L802831B4
/* 7E4028 802831A8 24020002 */   addiu    $v0, $zero, 2
/* 7E402C 802831AC 54620009 */  bnel      $v1, $v0, .L802831D4
/* 7E4030 802831B0 AC8000B8 */   sw       $zero, 0xb8($a0)
.L802831B4:
/* 7E4034 802831B4 8CA20004 */  lw        $v0, 4($a1)
/* 7E4038 802831B8 30420001 */  andi      $v0, $v0, 1
/* 7E403C 802831BC 54400003 */  bnel      $v0, $zero, .L802831CC
/* 7E4040 802831C0 AC8000B8 */   sw       $zero, 0xb8($a0)
/* 7E4044 802831C4 24020001 */  addiu     $v0, $zero, 1
/* 7E4048 802831C8 AC8200B8 */  sw        $v0, 0xb8($a0)
.L802831CC:
/* 7E404C 802831CC 03E00008 */  jr        $ra
/* 7E4050 802831D0 24020002 */   addiu    $v0, $zero, 2
.L802831D4:
/* 7E4054 802831D4 03E00008 */  jr        $ra
/* 7E4058 802831D8 00000000 */   nop      
