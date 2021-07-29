.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_item_entity_data
/* C76F0 80130FF0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* C76F4 80130FF4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* C76F8 80130FF8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C76FC 80130FFC AFBF0010 */  sw        $ra, 0x10($sp)
/* C7700 80131000 80420070 */  lb        $v0, 0x70($v0)
/* C7704 80131004 14400005 */  bnez      $v0, .L8013101C
/* C7708 80131008 00000000 */   nop
/* C770C 8013100C 3C028015 */  lui       $v0, %hi(D_80155DA0)
/* C7710 80131010 24425DA0 */  addiu     $v0, $v0, %lo(D_80155DA0)
/* C7714 80131014 0804C409 */  j         .L80131024
/* C7718 80131018 00000000 */   nop
.L8013101C:
/* C771C 8013101C 3C028015 */  lui       $v0, %hi(D_801561A0)
/* C7720 80131020 244261A0 */  addiu     $v0, $v0, %lo(D_801561A0)
.L80131024:
/* C7724 80131024 3C018015 */  lui       $at, %hi(D_801565A0)
/* C7728 80131028 AC2265A0 */  sw        $v0, %lo(D_801565A0)($at)
/* C772C 8013102C 3C028015 */  lui       $v0, %hi(D_801565A0)
/* C7730 80131030 8C4265A0 */  lw        $v0, %lo(D_801565A0)($v0)
/* C7734 80131034 240300FF */  addiu     $v1, $zero, 0xff
/* C7738 80131038 244203FC */  addiu     $v0, $v0, 0x3fc
.L8013103C:
/* C773C 8013103C AC400000 */  sw        $zero, ($v0)
/* C7740 80131040 2463FFFF */  addiu     $v1, $v1, -1
/* C7744 80131044 0461FFFD */  bgez      $v1, .L8013103C
/* C7748 80131048 2442FFFC */   addiu    $v0, $v0, -4
/* C774C 8013104C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* C7750 80131050 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* C7754 80131054 3C018015 */  lui       $at, %hi(D_801512F8)
/* C7758 80131058 AC2012F8 */  sw        $zero, %lo(D_801512F8)($at)
/* C775C 8013105C 3C018015 */  lui       $at, %hi(D_80155D8C)
/* C7760 80131060 A4205D8C */  sh        $zero, %lo(D_80155D8C)($at)
/* C7764 80131064 3C018015 */  lui       $at, %hi(D_80155D8E)
/* C7768 80131068 A4205D8E */  sh        $zero, %lo(D_80155D8E)($at)
/* C776C 8013106C 3C018015 */  lui       $at, %hi(D_80155D90)
/* C7770 80131070 A4205D90 */  sh        $zero, %lo(D_80155D90)($at)
/* C7774 80131074 3C018015 */  lui       $at, %hi(D_80155D84)
/* C7778 80131078 AC205D84 */  sw        $zero, %lo(D_80155D84)($at)
/* C777C 8013107C 80420070 */  lb        $v0, 0x70($v0)
/* C7780 80131080 14400003 */  bnez      $v0, .L80131090
/* C7784 80131084 00000000 */   nop
/* C7788 80131088 3C018015 */  lui       $at, %hi(D_80155D88)
/* C778C 8013108C AC205D88 */  sw        $zero, %lo(D_80155D88)($at)
.L80131090:
/* C7790 80131090 3C058013 */  lui       $a1, %hi(draw_item_entities)
/* C7794 80131094 24A52C80 */  addiu     $a1, $a1, %lo(draw_item_entities)
/* C7798 80131098 0C048C56 */  jal       create_generic_entity_world
/* C779C 8013109C 0000202D */   daddu    $a0, $zero, $zero
/* C77A0 801310A0 3C058013 */  lui       $a1, %hi(func_80132D94)
/* C77A4 801310A4 24A52D94 */  addiu     $a1, $a1, %lo(func_80132D94)
/* C77A8 801310A8 0C048C8F */  jal       create_generic_entity_frontUI
/* C77AC 801310AC 0000202D */   daddu    $a0, $zero, $zero
/* C77B0 801310B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* C77B4 801310B4 3C018015 */  lui       $at, %hi(D_801565A4)
/* C77B8 801310B8 A42065A4 */  sh        $zero, %lo(D_801565A4)($at)
/* C77BC 801310BC 3C018015 */  lui       $at, %hi(D_801565A8)
/* C77C0 801310C0 A42065A8 */  sh        $zero, %lo(D_801565A8)($at)
/* C77C4 801310C4 03E00008 */  jr        $ra
/* C77C8 801310C8 27BD0018 */   addiu    $sp, $sp, 0x18
