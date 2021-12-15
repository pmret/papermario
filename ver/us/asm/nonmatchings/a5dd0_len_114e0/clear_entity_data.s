.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_entity_data
/* A73B8 80110CB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A73BC 80110CBC 3C058007 */  lui       $a1, %hi(gGameStatusPtr)
/* A73C0 80110CC0 24A5419C */  addiu     $a1, $a1, %lo(gGameStatusPtr)
/* A73C4 80110CC4 AFBF0014 */  sw        $ra, 0x14($sp)
/* A73C8 80110CC8 AFB00010 */  sw        $s0, 0x10($sp)
/* A73CC 80110CCC 8CA20000 */  lw        $v0, ($a1)
/* A73D0 80110CD0 24030001 */  addiu     $v1, $zero, 1
/* A73D4 80110CD4 3C018015 */  lui       $at, %hi(D_801516FC)
/* A73D8 80110CD8 AC2316FC */  sw        $v1, %lo(D_801516FC)($at)
/* A73DC 80110CDC 3C018015 */  lui       $at, %hi(D_801512C0)
/* A73E0 80110CE0 AC2012C0 */  sw        $zero, %lo(D_801512C0)($at)
/* A73E4 80110CE4 3C018015 */  lui       $at, %hi(D_80151324)
/* A73E8 80110CE8 AC201324 */  sw        $zero, %lo(D_80151324)($at)
/* A73EC 80110CEC 3C018015 */  lui       $at, %hi(D_80151330)
/* A73F0 80110CF0 AC201330 */  sw        $zero, %lo(D_80151330)($at)
/* A73F4 80110CF4 3C018015 */  lui       $at, %hi(D_80151304)
/* A73F8 80110CF8 AC201304 */  sw        $zero, %lo(D_80151304)($at)
/* A73FC 80110CFC 80420070 */  lb        $v0, 0x70($v0)
/* A7400 80110D00 14400003 */  bnez      $v0, .L80110D10
/* A7404 80110D04 00000000 */   nop
/* A7408 80110D08 3C018015 */  lui       $at, %hi(D_80151310)
/* A740C 80110D0C AC201310 */  sw        $zero, %lo(D_80151310)($at)
.L80110D10:
/* A7410 80110D10 3C028016 */  lui       $v0, %hi(D_8015A578)
/* A7414 80110D14 2442A578 */  addiu     $v0, $v0, %lo(D_8015A578)
/* A7418 80110D18 3C018015 */  lui       $at, %hi(D_8015132C)
/* A741C 80110D1C AC20132C */  sw        $zero, %lo(D_8015132C)($at)
/* A7420 80110D20 A0400001 */  sb        $zero, 1($v0)
/* A7424 80110D24 14800003 */  bnez      $a0, .L80110D34
/* A7428 80110D28 A0400002 */   sb       $zero, 2($v0)
/* A742C 80110D2C 3C018015 */  lui       $at, %hi(D_80151344)
/* A7430 80110D30 AC201344 */  sw        $zero, %lo(D_80151344)($at)
.L80110D34:
/* A7434 80110D34 8CA20000 */  lw        $v0, ($a1)
/* A7438 80110D38 240300FF */  addiu     $v1, $zero, 0xff
/* A743C 80110D3C 3C018015 */  lui       $at, %hi(D_8014AFB0)
/* A7440 80110D40 AC23AFB0 */  sw        $v1, %lo(D_8014AFB0)($at)
/* A7444 80110D44 80420070 */  lb        $v0, 0x70($v0)
/* A7448 80110D48 1440000C */  bnez      $v0, .L80110D7C
/* A744C 80110D4C 24040003 */   addiu    $a0, $zero, 3
/* A7450 80110D50 3C018015 */  lui       $at, %hi(wStaticEntityDataSize)
/* A7454 80110D54 AC20165C */  sw        $zero, %lo(wStaticEntityDataSize)($at)
/* A7458 80110D58 2404001D */  addiu     $a0, $zero, 0x1d
/* A745C 80110D5C 3C028015 */  lui       $v0, %hi(D_801516DC)
/* A7460 80110D60 244216DC */  addiu     $v0, $v0, %lo(D_801516DC)
.L80110D64:
/* A7464 80110D64 AC400000 */  sw        $zero, ($v0)
/* A7468 80110D68 2484FFFF */  addiu     $a0, $a0, -1
/* A746C 80110D6C 0481FFFD */  bgez      $a0, .L80110D64
/* A7470 80110D70 2442FFFC */   addiu    $v0, $v0, -4
/* A7474 80110D74 08044367 */  j         .L80110D9C
/* A7478 80110D78 00000000 */   nop
.L80110D7C:
/* A747C 80110D7C 3C018015 */  lui       $at, %hi(bStaticEntityDataSize)
/* A7480 80110D80 AC201660 */  sw        $zero, %lo(bStaticEntityDataSize)($at)
/* A7484 80110D84 3C028015 */  lui       $v0, %hi(bStaticEntityData + 0xC)
/* A7488 80110D88 244216F4 */  addiu     $v0, $v0, %lo(bStaticEntityData + 0xC)
.L80110D8C:
/* A748C 80110D8C AC400000 */  sw        $zero, ($v0)
/* A7490 80110D90 2484FFFF */  addiu     $a0, $a0, -1
/* A7494 80110D94 0481FFFD */  bgez      $a0, .L80110D8C
/* A7498 80110D98 2442FFFC */   addiu    $v0, $v0, -4
.L80110D9C:
/* A749C 80110D9C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* A74A0 80110DA0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* A74A4 80110DA4 80420070 */  lb        $v0, 0x70($v0)
/* A74A8 80110DA8 14400009 */  bnez      $v0, .L80110DD0
/* A74AC 80110DAC 3C028025 */   lui      $v0, 0x8025
/* A74B0 80110DB0 3C038026 */  lui       $v1, 0x8026
/* A74B4 80110DB4 34637FF0 */  ori       $v1, $v1, 0x7ff0
/* A74B8 80110DB8 3C018015 */  lui       $at, %hi(D_80151300)
/* A74BC 80110DBC AC221300 */  sw        $v0, %lo(D_80151300)($at)
/* A74C0 80110DC0 3C018015 */  lui       $at, %hi(gEntityHeapBase)
/* A74C4 80110DC4 AC2312C4 */  sw        $v1, %lo(gEntityHeapBase)($at)
/* A74C8 80110DC8 0804437B */  j         .L80110DEC
/* A74CC 80110DCC 00000000 */   nop
.L80110DD0:
/* A74D0 80110DD0 3C02801A */  lui       $v0, %hi(D_801A7000)
/* A74D4 80110DD4 24427000 */  addiu     $v0, $v0, %lo(D_801A7000)
/* A74D8 80110DD8 3C018015 */  lui       $at, %hi(D_80151300)
/* A74DC 80110DDC AC221300 */  sw        $v0, %lo(D_80151300)($at)
/* A74E0 80110DE0 24423000 */  addiu     $v0, $v0, 0x3000
/* A74E4 80110DE4 3C018015 */  lui       $at, %hi(gEntityHeapBase)
/* A74E8 80110DE8 AC2212C4 */  sw        $v0, %lo(gEntityHeapBase)($at)
.L80110DEC:
/* A74EC 80110DEC 0C044188 */  jal       get_entity_list
/* A74F0 80110DF0 00000000 */   nop
/* A74F4 80110DF4 3C108015 */  lui       $s0, %hi(gCurrentEntityListPtr)
/* A74F8 80110DF8 26101470 */  addiu     $s0, $s0, %lo(gCurrentEntityListPtr)
/* A74FC 80110DFC 0C044193 */  jal       get_shadow_list
/* A7500 80110E00 AE020000 */   sw       $v0, ($s0)
/* A7504 80110E04 8E030000 */  lw        $v1, ($s0)
/* A7508 80110E08 2404001D */  addiu     $a0, $zero, 0x1d
/* A750C 80110E0C 3C018015 */  lui       $at, %hi(gCurrentShadowListPtr)
/* A7510 80110E10 AC221658 */  sw        $v0, %lo(gCurrentShadowListPtr)($at)
/* A7514 80110E14 24630074 */  addiu     $v1, $v1, 0x74
.L80110E18:
/* A7518 80110E18 AC600000 */  sw        $zero, ($v1)
/* A751C 80110E1C 2484FFFF */  addiu     $a0, $a0, -1
/* A7520 80110E20 0481FFFD */  bgez      $a0, .L80110E18
/* A7524 80110E24 2463FFFC */   addiu    $v1, $v1, -4
/* A7528 80110E28 3C028015 */  lui       $v0, %hi(gCurrentShadowListPtr)
/* A752C 80110E2C 8C421658 */  lw        $v0, %lo(gCurrentShadowListPtr)($v0)
/* A7530 80110E30 2404003B */  addiu     $a0, $zero, 0x3b
/* A7534 80110E34 244200EC */  addiu     $v0, $v0, 0xec
.L80110E38:
/* A7538 80110E38 AC400000 */  sw        $zero, ($v0)
/* A753C 80110E3C 2484FFFF */  addiu     $a0, $a0, -1
/* A7540 80110E40 0481FFFD */  bgez      $a0, .L80110E38
/* A7544 80110E44 2442FFFC */   addiu    $v0, $v0, -4
/* A7548 80110E48 8FBF0014 */  lw        $ra, 0x14($sp)
/* A754C 80110E4C 8FB00010 */  lw        $s0, 0x10($sp)
/* A7550 80110E50 03E00008 */  jr        $ra
/* A7554 80110E54 27BD0018 */   addiu    $sp, $sp, 0x18
