.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel partner_reset_data
/* 84924 800EB474 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 84928 800EB478 AFB10014 */  sw        $s1, 0x14($sp)
/* 8492C 800EB47C 3C118011 */  lui       $s1, %hi(D_8010EBB0)
/* 84930 800EB480 2631EBB0 */  addiu     $s1, $s1, %lo(D_8010EBB0)
/* 84934 800EB484 0220202D */  daddu     $a0, $s1, $zero
/* 84938 800EB488 AFB00010 */  sw        $s0, 0x10($sp)
/* 8493C 800EB48C 3C108011 */  lui       $s0, %hi(gPlayerData+0x12)
/* 84940 800EB490 8210F2A2 */  lb        $s0, %lo(gPlayerData+0x12)($s0)
/* 84944 800EB494 AFBF0018 */  sw        $ra, 0x18($sp)
/* 84948 800EB498 0C00A580 */  jal       mem_clear
/* 8494C 800EB49C 24050360 */   addiu    $a1, $zero, 0x360
/* 84950 800EB4A0 3C04800F */  lui       $a0, %hi(_use_partner_ability)
/* 84954 800EB4A4 2484A6CC */  addiu     $a0, $a0, %lo(_use_partner_ability)
/* 84958 800EB4A8 0C048C8F */  jal       bind_dynamic_entity_7
/* 8495C 800EB4AC 0000282D */   daddu    $a1, $zero, $zero
/* 84960 800EB4B0 0C048D8F */  jal       get_dynamic_entity
/* 84964 800EB4B4 0040202D */   daddu    $a0, $v0, $zero
/* 84968 800EB4B8 24040001 */  addiu     $a0, $zero, 1
/* 8496C 800EB4BC 3C068011 */  lui       $a2, %hi(D_8010CFE8)
/* 84970 800EB4C0 24C6CFE8 */  addiu     $a2, $a2, %lo(D_8010CFE8)
/* 84974 800EB4C4 24020009 */  addiu     $v0, $zero, 9
/* 84978 800EB4C8 3C018011 */  lui       $at, %hi(D_8010CFE0)
/* 8497C 800EB4CC AC24CFE0 */  sw        $a0, %lo(D_8010CFE0)($at)
/* 84980 800EB4D0 ACC20000 */  sw        $v0, ($a2)
/* 84984 800EB4D4 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 84988 800EB4D8 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 8498C 800EB4DC 3C058011 */  lui       $a1, %hi(D_8010CFD8)
/* 84990 800EB4E0 24A5CFD8 */  addiu     $a1, $a1, %lo(D_8010CFD8)
/* 84994 800EB4E4 ACB00000 */  sw        $s0, ($a1)
/* 84998 800EB4E8 8062007D */  lb        $v0, 0x7d($v1)
/* 8499C 800EB4EC 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 849A0 800EB4F0 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 849A4 800EB4F4 10400003 */  beqz      $v0, .L800EB504
/* 849A8 800EB4F8 00000000 */   nop
/* 849AC 800EB4FC A2240000 */  sb        $a0, ($s1)
/* 849B0 800EB500 A060007D */  sb        $zero, 0x7d($v1)
.L800EB504:
/* 849B4 800EB504 C6000028 */  lwc1      $f0, 0x28($s0)
/* 849B8 800EB508 C602002C */  lwc1      $f2, 0x2c($s0)
/* 849BC 800EB50C C6040030 */  lwc1      $f4, 0x30($s0)
/* 849C0 800EB510 8CA20000 */  lw        $v0, ($a1)
/* 849C4 800EB514 3C018011 */  lui       $at, %hi(D_8010CFEC)
/* 849C8 800EB518 AC20CFEC */  sw        $zero, %lo(D_8010CFEC)($at)
/* 849CC 800EB51C 3C018010 */  lui       $at, %hi(D_800F833C)
/* 849D0 800EB520 E420833C */  swc1      $f0, %lo(D_800F833C)($at)
/* 849D4 800EB524 3C018010 */  lui       $at, %hi(D_800F8340)
/* 849D8 800EB528 E4228340 */  swc1      $f2, %lo(D_800F8340)($at)
/* 849DC 800EB52C 3C018010 */  lui       $at, %hi(D_800F8344)
/* 849E0 800EB530 14400003 */  bnez      $v0, .L800EB540
/* 849E4 800EB534 E4248344 */   swc1     $f4, %lo(D_800F8344)($at)
/* 849E8 800EB538 0803AD5B */  j         .L800EB56C
/* 849EC 800EB53C ACC40000 */   sw       $a0, ($a2)
.L800EB540:
/* 849F0 800EB540 0C03A974 */  jal       load_partner_npc
/* 849F4 800EB544 00000000 */   nop
/* 849F8 800EB548 3C028011 */  lui       $v0, %hi(D_8010C930)
/* 849FC 800EB54C 8C42C930 */  lw        $v0, %lo(D_8010C930)($v0)
/* 84A00 800EB550 3C013F80 */  lui       $at, 0x3f80
/* 84A04 800EB554 44810000 */  mtc1      $at, $f0
/* 84A08 800EB558 00000000 */  nop
/* 84A0C 800EB55C E4400054 */  swc1      $f0, 0x54($v0)
/* 84A10 800EB560 E4400058 */  swc1      $f0, 0x58($v0)
/* 84A14 800EB564 0C03A9B3 */  jal       _use_partner_ability
/* 84A18 800EB568 E440005C */   swc1     $f0, 0x5c($v0)
.L800EB56C:
/* 84A1C 800EB56C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 84A20 800EB570 8FB10014 */  lw        $s1, 0x14($sp)
/* 84A24 800EB574 8FB00010 */  lw        $s0, 0x10($sp)
/* 84A28 800EB578 03E00008 */  jr        $ra
/* 84A2C 800EB57C 27BD0020 */   addiu    $sp, $sp, 0x20
