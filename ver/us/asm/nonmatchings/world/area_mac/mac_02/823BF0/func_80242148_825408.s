.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mac_02_Quizmo_UnkC
/* 825408 80242148 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 82540C 8024214C 10A0000B */  beqz      $a1, .L8024217C
/* 825410 80242150 AFBF0010 */   sw       $ra, 0x10($sp)
/* 825414 80242154 3C038025 */  lui       $v1, %hi(mac_02_Quizmo_AudienceEffect)
/* 825418 80242158 8C63E564 */  lw        $v1, %lo(mac_02_Quizmo_AudienceEffect)($v1)
/* 82541C 8024215C 8C620000 */  lw        $v0, ($v1)
/* 825420 80242160 3C048025 */  lui       $a0, %hi(mac_02_Quizmo_VannaTEffect)
/* 825424 80242164 8C84E568 */  lw        $a0, %lo(mac_02_Quizmo_VannaTEffect)($a0)
/* 825428 80242168 34420010 */  ori       $v0, $v0, 0x10
/* 82542C 8024216C AC620000 */  sw        $v0, ($v1)
/* 825430 80242170 8C820000 */  lw        $v0, ($a0)
/* 825434 80242174 34420010 */  ori       $v0, $v0, 0x10
/* 825438 80242178 AC820000 */  sw        $v0, ($a0)
.L8024217C:
/* 82543C 8024217C 3C048025 */  lui       $a0, %hi(mac_02_Quizmo_StageEffect)
/* 825440 80242180 8C84E560 */  lw        $a0, %lo(mac_02_Quizmo_StageEffect)($a0)
/* 825444 80242184 8C85000C */  lw        $a1, 0xc($a0)
/* 825448 80242188 8CA20018 */  lw        $v0, 0x18($a1)
/* 82544C 8024218C 8CA30020 */  lw        $v1, 0x20($a1)
/* 825450 80242190 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 825454 80242194 ACA20018 */  sw        $v0, 0x18($a1)
/* 825458 80242198 8CA20024 */  lw        $v0, 0x24($a1)
/* 82545C 8024219C 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 825460 802421A0 ACA30020 */  sw        $v1, 0x20($a1)
/* 825464 802421A4 8CA30028 */  lw        $v1, 0x28($a1)
/* 825468 802421A8 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 82546C 802421AC ACA20024 */  sw        $v0, 0x24($a1)
/* 825470 802421B0 8CA2001C */  lw        $v0, 0x1c($a1)
/* 825474 802421B4 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 825478 802421B8 ACA30028 */  sw        $v1, 0x28($a1)
/* 82547C 802421BC 8CA30018 */  lw        $v1, 0x18($a1)
/* 825480 802421C0 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 825484 802421C4 18600003 */  blez      $v1, .L802421D4
/* 825488 802421C8 ACA2001C */   sw       $v0, 0x1c($a1)
/* 82548C 802421CC 0809087C */  j         .L802421F0
/* 825490 802421D0 0000102D */   daddu    $v0, $zero, $zero
.L802421D4:
/* 825494 802421D4 0C016914 */  jal       remove_effect
/* 825498 802421D8 ACA00018 */   sw       $zero, 0x18($a1)
/* 82549C 802421DC 3C048025 */  lui       $a0, %hi(mac_02_Quizmo_Worker)
/* 8254A0 802421E0 8C84E540 */  lw        $a0, %lo(mac_02_Quizmo_Worker)($a0)
/* 8254A4 802421E4 0C048D70 */  jal       free_generic_entity
/* 8254A8 802421E8 00000000 */   nop
/* 8254AC 802421EC 24020002 */  addiu     $v0, $zero, 2
.L802421F0:
/* 8254B0 802421F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8254B4 802421F4 03E00008 */  jr        $ra
/* 8254B8 802421F8 27BD0018 */   addiu    $sp, $sp, 0x18
