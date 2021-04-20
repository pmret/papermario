.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D6C_D9635C
/* D9635C 80240D6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D96360 80240D70 AFB00010 */  sw        $s0, 0x10($sp)
/* D96364 80240D74 0080802D */  daddu     $s0, $a0, $zero
/* D96368 80240D78 AFBF0014 */  sw        $ra, 0x14($sp)
/* D9636C 80240D7C 8E020088 */  lw        $v0, 0x88($s0)
/* D96370 80240D80 14400017 */  bnez      $v0, .L80240DE0
/* D96374 80240D84 24020001 */   addiu    $v0, $zero, 1
/* D96378 80240D88 8E030084 */  lw        $v1, 0x84($s0)
/* D9637C 80240D8C 1062001A */  beq       $v1, $v0, .L80240DF8
/* D96380 80240D90 00000000 */   nop
/* D96384 80240D94 28620002 */  slti      $v0, $v1, 2
/* D96388 80240D98 50400005 */  beql      $v0, $zero, .L80240DB0
/* D9638C 80240D9C 24020002 */   addiu    $v0, $zero, 2
/* D96390 80240DA0 10600007 */  beqz      $v1, .L80240DC0
/* D96394 80240DA4 00000000 */   nop
/* D96398 80240DA8 08090384 */  j         .L80240E10
/* D9639C 80240DAC 00000000 */   nop
.L80240DB0:
/* D963A0 80240DB0 10620007 */  beq       $v1, $v0, .L80240DD0
/* D963A4 80240DB4 00000000 */   nop
/* D963A8 80240DB8 08090384 */  j         .L80240E10
/* D963AC 80240DBC 00000000 */   nop
.L80240DC0:
/* D963B0 80240DC0 3C048024 */  lui       $a0, %hi(pra_38_SetPartnerFlagsA0000)
/* D963B4 80240DC4 24840EB4 */  addiu     $a0, $a0, %lo(pra_38_SetPartnerFlagsA0000)
/* D963B8 80240DC8 08090380 */  j         .L80240E00
/* D963BC 80240DCC 00000000 */   nop
.L80240DD0:
/* D963C0 80240DD0 3C048024 */  lui       $a0, %hi(pra_38_SetPartnerFlags20000)
/* D963C4 80240DD4 24840F1C */  addiu     $a0, $a0, %lo(pra_38_SetPartnerFlags20000)
/* D963C8 80240DD8 08090380 */  j         .L80240E00
/* D963CC 80240DDC 00000000 */   nop
.L80240DE0:
/* D963D0 80240DE0 8E020084 */  lw        $v0, 0x84($s0)
/* D963D4 80240DE4 0440000A */  bltz      $v0, .L80240E10
/* D963D8 80240DE8 00000000 */   nop
/* D963DC 80240DEC 28420002 */  slti      $v0, $v0, 2
/* D963E0 80240DF0 10400007 */  beqz      $v0, .L80240E10
/* D963E4 80240DF4 00000000 */   nop
.L80240DF8:
/* D963E8 80240DF8 3C048024 */  lui       $a0, %hi(pra_38_SetPartnerFlags80000)
/* D963EC 80240DFC 24840EE8 */  addiu     $a0, $a0, %lo(pra_38_SetPartnerFlags80000)
.L80240E00:
/* D963F0 80240E00 0C048C56 */  jal       create_dynamic_entity_world
/* D963F4 80240E04 0000282D */   daddu    $a1, $zero, $zero
/* D963F8 80240E08 8E03013C */  lw        $v1, 0x13c($s0)
/* D963FC 80240E0C AC620004 */  sw        $v0, 4($v1)
.L80240E10:
/* D96400 80240E10 0C00EAD2 */  jal       get_npc_safe
/* D96404 80240E14 2404FFFC */   addiu    $a0, $zero, -4
/* D96408 80240E18 0040282D */  daddu     $a1, $v0, $zero
/* D9640C 80240E1C 10A00021 */  beqz      $a1, .L80240EA4
/* D96410 80240E20 24020002 */   addiu    $v0, $zero, 2
/* D96414 80240E24 8E020088 */  lw        $v0, 0x88($s0)
/* D96418 80240E28 14400014 */  bnez      $v0, .L80240E7C
/* D9641C 80240E2C 24020001 */   addiu    $v0, $zero, 1
/* D96420 80240E30 8E040084 */  lw        $a0, 0x84($s0)
/* D96424 80240E34 10820016 */  beq       $a0, $v0, .L80240E90
/* D96428 80240E38 28820002 */   slti     $v0, $a0, 2
/* D9642C 80240E3C 10400005 */  beqz      $v0, .L80240E54
/* D96430 80240E40 24020002 */   addiu    $v0, $zero, 2
/* D96434 80240E44 10800007 */  beqz      $a0, .L80240E64
/* D96438 80240E48 00000000 */   nop
/* D9643C 80240E4C 080903A9 */  j         .L80240EA4
/* D96440 80240E50 00000000 */   nop
.L80240E54:
/* D96444 80240E54 10820006 */  beq       $a0, $v0, .L80240E70
/* D96448 80240E58 24020002 */   addiu    $v0, $zero, 2
/* D9644C 80240E5C 080903A9 */  j         .L80240EA4
/* D96450 80240E60 00000000 */   nop
.L80240E64:
/* D96454 80240E64 8CA20000 */  lw        $v0, ($a1)
/* D96458 80240E68 080903A6 */  j         .L80240E98
/* D9645C 80240E6C 3C03000A */   lui      $v1, 0xa
.L80240E70:
/* D96460 80240E70 8CA20000 */  lw        $v0, ($a1)
/* D96464 80240E74 080903A6 */  j         .L80240E98
/* D96468 80240E78 3C030002 */   lui      $v1, 2
.L80240E7C:
/* D9646C 80240E7C 8E020084 */  lw        $v0, 0x84($s0)
/* D96470 80240E80 04400007 */  bltz      $v0, .L80240EA0
/* D96474 80240E84 28420002 */   slti     $v0, $v0, 2
/* D96478 80240E88 10400006 */  beqz      $v0, .L80240EA4
/* D9647C 80240E8C 24020002 */   addiu    $v0, $zero, 2
.L80240E90:
/* D96480 80240E90 8CA20000 */  lw        $v0, ($a1)
/* D96484 80240E94 3C030008 */  lui       $v1, 8
.L80240E98:
/* D96488 80240E98 00431025 */  or        $v0, $v0, $v1
/* D9648C 80240E9C ACA20000 */  sw        $v0, ($a1)
.L80240EA0:
/* D96490 80240EA0 24020002 */  addiu     $v0, $zero, 2
.L80240EA4:
/* D96494 80240EA4 8FBF0014 */  lw        $ra, 0x14($sp)
/* D96498 80240EA8 8FB00010 */  lw        $s0, 0x10($sp)
/* D9649C 80240EAC 03E00008 */  jr        $ra
/* D964A0 80240EB0 27BD0018 */   addiu    $sp, $sp, 0x18
