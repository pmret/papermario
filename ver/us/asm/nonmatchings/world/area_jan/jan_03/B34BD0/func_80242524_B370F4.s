.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_03_Quizmo_UnkC
/* B370F4 80242524 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B370F8 80242528 10A0000B */  beqz      $a1, .L80242558
/* B370FC 8024252C AFBF0010 */   sw       $ra, 0x10($sp)
/* B37100 80242530 3C038025 */  lui       $v1, %hi(jan_03_Quizmo_AudienceEffect)
/* B37104 80242534 8C63FEFC */  lw        $v1, %lo(jan_03_Quizmo_AudienceEffect)($v1)
/* B37108 80242538 8C620000 */  lw        $v0, ($v1)
/* B3710C 8024253C 3C048025 */  lui       $a0, %hi(jan_03_Quizmo_VannaTEffect)
/* B37110 80242540 8C84FF00 */  lw        $a0, %lo(jan_03_Quizmo_VannaTEffect)($a0)
/* B37114 80242544 34420010 */  ori       $v0, $v0, 0x10
/* B37118 80242548 AC620000 */  sw        $v0, ($v1)
/* B3711C 8024254C 8C820000 */  lw        $v0, ($a0)
/* B37120 80242550 34420010 */  ori       $v0, $v0, 0x10
/* B37124 80242554 AC820000 */  sw        $v0, ($a0)
.L80242558:
/* B37128 80242558 3C048025 */  lui       $a0, %hi(jan_03_Quizmo_StageEffect)
/* B3712C 8024255C 8C84FEF8 */  lw        $a0, %lo(jan_03_Quizmo_StageEffect)($a0)
/* B37130 80242560 8C85000C */  lw        $a1, 0xc($a0)
/* B37134 80242564 8CA20018 */  lw        $v0, 0x18($a1)
/* B37138 80242568 8CA30020 */  lw        $v1, 0x20($a1)
/* B3713C 8024256C 2442FFF6 */  addiu     $v0, $v0, -0xa
/* B37140 80242570 ACA20018 */  sw        $v0, 0x18($a1)
/* B37144 80242574 8CA20024 */  lw        $v0, 0x24($a1)
/* B37148 80242578 2463FFF6 */  addiu     $v1, $v1, -0xa
/* B3714C 8024257C ACA30020 */  sw        $v1, 0x20($a1)
/* B37150 80242580 8CA30028 */  lw        $v1, 0x28($a1)
/* B37154 80242584 2442FFF6 */  addiu     $v0, $v0, -0xa
/* B37158 80242588 ACA20024 */  sw        $v0, 0x24($a1)
/* B3715C 8024258C 8CA2001C */  lw        $v0, 0x1c($a1)
/* B37160 80242590 2463FFF6 */  addiu     $v1, $v1, -0xa
/* B37164 80242594 ACA30028 */  sw        $v1, 0x28($a1)
/* B37168 80242598 8CA30018 */  lw        $v1, 0x18($a1)
/* B3716C 8024259C 2442FFF6 */  addiu     $v0, $v0, -0xa
/* B37170 802425A0 18600003 */  blez      $v1, .L802425B0
/* B37174 802425A4 ACA2001C */   sw       $v0, 0x1c($a1)
/* B37178 802425A8 08090973 */  j         .L802425CC
/* B3717C 802425AC 0000102D */   daddu    $v0, $zero, $zero
.L802425B0:
/* B37180 802425B0 0C016914 */  jal       remove_effect
/* B37184 802425B4 ACA00018 */   sw       $zero, 0x18($a1)
/* B37188 802425B8 3C048025 */  lui       $a0, %hi(jan_03_Quizmo_Worker)
/* B3718C 802425BC 8C84FED8 */  lw        $a0, %lo(jan_03_Quizmo_Worker)($a0)
/* B37190 802425C0 0C048D70 */  jal       free_generic_entity
/* B37194 802425C4 00000000 */   nop
/* B37198 802425C8 24020002 */  addiu     $v0, $zero, 2
.L802425CC:
/* B3719C 802425CC 8FBF0010 */  lw        $ra, 0x10($sp)
/* B371A0 802425D0 03E00008 */  jr        $ra
/* B371A4 802425D4 27BD0018 */   addiu    $sp, $sp, 0x18
