.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pra_36_ReflectPartner
/* D9246C 80240D6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D92470 80240D70 AFB00010 */  sw        $s0, 0x10($sp)
/* D92474 80240D74 0080802D */  daddu     $s0, $a0, $zero
/* D92478 80240D78 AFBF0014 */  sw        $ra, 0x14($sp)
/* D9247C 80240D7C 8E020088 */  lw        $v0, 0x88($s0)
/* D92480 80240D80 14400017 */  bnez      $v0, .L80240DE0
/* D92484 80240D84 24020001 */   addiu    $v0, $zero, 1
/* D92488 80240D88 8E030084 */  lw        $v1, 0x84($s0)
/* D9248C 80240D8C 1062001A */  beq       $v1, $v0, .L80240DF8
/* D92490 80240D90 00000000 */   nop
/* D92494 80240D94 28620002 */  slti      $v0, $v1, 2
/* D92498 80240D98 50400005 */  beql      $v0, $zero, .L80240DB0
/* D9249C 80240D9C 24020002 */   addiu    $v0, $zero, 2
/* D924A0 80240DA0 10600007 */  beqz      $v1, .L80240DC0
/* D924A4 80240DA4 00000000 */   nop
/* D924A8 80240DA8 08090384 */  j         .L80240E10
/* D924AC 80240DAC 00000000 */   nop
.L80240DB0:
/* D924B0 80240DB0 10620007 */  beq       $v1, $v0, .L80240DD0
/* D924B4 80240DB4 00000000 */   nop
/* D924B8 80240DB8 08090384 */  j         .L80240E10
/* D924BC 80240DBC 00000000 */   nop
.L80240DC0:
/* D924C0 80240DC0 3C048024 */  lui       $a0, %hi(pra_36_SetPartnerFlagsA0000)
/* D924C4 80240DC4 24840EB4 */  addiu     $a0, $a0, %lo(pra_36_SetPartnerFlagsA0000)
/* D924C8 80240DC8 08090380 */  j         .L80240E00
/* D924CC 80240DCC 00000000 */   nop
.L80240DD0:
/* D924D0 80240DD0 3C048024 */  lui       $a0, %hi(pra_36_SetPartnerFlags20000)
/* D924D4 80240DD4 24840F1C */  addiu     $a0, $a0, %lo(pra_36_SetPartnerFlags20000)
/* D924D8 80240DD8 08090380 */  j         .L80240E00
/* D924DC 80240DDC 00000000 */   nop
.L80240DE0:
/* D924E0 80240DE0 8E020084 */  lw        $v0, 0x84($s0)
/* D924E4 80240DE4 0440000A */  bltz      $v0, .L80240E10
/* D924E8 80240DE8 00000000 */   nop
/* D924EC 80240DEC 28420002 */  slti      $v0, $v0, 2
/* D924F0 80240DF0 10400007 */  beqz      $v0, .L80240E10
/* D924F4 80240DF4 00000000 */   nop
.L80240DF8:
/* D924F8 80240DF8 3C048024 */  lui       $a0, %hi(pra_36_SetPartnerFlags80000)
/* D924FC 80240DFC 24840EE8 */  addiu     $a0, $a0, %lo(pra_36_SetPartnerFlags80000)
.L80240E00:
/* D92500 80240E00 0C048C56 */  jal       create_dynamic_entity_world
/* D92504 80240E04 0000282D */   daddu    $a1, $zero, $zero
/* D92508 80240E08 8E03013C */  lw        $v1, 0x13c($s0)
/* D9250C 80240E0C AC620004 */  sw        $v0, 4($v1)
.L80240E10:
/* D92510 80240E10 0C00EAD2 */  jal       get_npc_safe
/* D92514 80240E14 2404FFFC */   addiu    $a0, $zero, -4
/* D92518 80240E18 0040282D */  daddu     $a1, $v0, $zero
/* D9251C 80240E1C 10A00021 */  beqz      $a1, .L80240EA4
/* D92520 80240E20 24020002 */   addiu    $v0, $zero, 2
/* D92524 80240E24 8E020088 */  lw        $v0, 0x88($s0)
/* D92528 80240E28 14400014 */  bnez      $v0, .L80240E7C
/* D9252C 80240E2C 24020001 */   addiu    $v0, $zero, 1
/* D92530 80240E30 8E040084 */  lw        $a0, 0x84($s0)
/* D92534 80240E34 10820016 */  beq       $a0, $v0, .L80240E90
/* D92538 80240E38 28820002 */   slti     $v0, $a0, 2
/* D9253C 80240E3C 10400005 */  beqz      $v0, .L80240E54
/* D92540 80240E40 24020002 */   addiu    $v0, $zero, 2
/* D92544 80240E44 10800007 */  beqz      $a0, .L80240E64
/* D92548 80240E48 00000000 */   nop
/* D9254C 80240E4C 080903A9 */  j         .L80240EA4
/* D92550 80240E50 00000000 */   nop
.L80240E54:
/* D92554 80240E54 10820006 */  beq       $a0, $v0, .L80240E70
/* D92558 80240E58 24020002 */   addiu    $v0, $zero, 2
/* D9255C 80240E5C 080903A9 */  j         .L80240EA4
/* D92560 80240E60 00000000 */   nop
.L80240E64:
/* D92564 80240E64 8CA20000 */  lw        $v0, ($a1)
/* D92568 80240E68 080903A6 */  j         .L80240E98
/* D9256C 80240E6C 3C03000A */   lui      $v1, 0xa
.L80240E70:
/* D92570 80240E70 8CA20000 */  lw        $v0, ($a1)
/* D92574 80240E74 080903A6 */  j         .L80240E98
/* D92578 80240E78 3C030002 */   lui      $v1, 2
.L80240E7C:
/* D9257C 80240E7C 8E020084 */  lw        $v0, 0x84($s0)
/* D92580 80240E80 04400007 */  bltz      $v0, .L80240EA0
/* D92584 80240E84 28420002 */   slti     $v0, $v0, 2
/* D92588 80240E88 10400006 */  beqz      $v0, .L80240EA4
/* D9258C 80240E8C 24020002 */   addiu    $v0, $zero, 2
.L80240E90:
/* D92590 80240E90 8CA20000 */  lw        $v0, ($a1)
/* D92594 80240E94 3C030008 */  lui       $v1, 8
.L80240E98:
/* D92598 80240E98 00431025 */  or        $v0, $v0, $v1
/* D9259C 80240E9C ACA20000 */  sw        $v0, ($a1)
.L80240EA0:
/* D925A0 80240EA0 24020002 */  addiu     $v0, $zero, 2
.L80240EA4:
/* D925A4 80240EA4 8FBF0014 */  lw        $ra, 0x14($sp)
/* D925A8 80240EA8 8FB00010 */  lw        $s0, 0x10($sp)
/* D925AC 80240EAC 03E00008 */  jr        $ra
/* D925B0 80240EB0 27BD0018 */   addiu    $sp, $sp, 0x18
