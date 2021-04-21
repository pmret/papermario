.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pra_39_ReflectPartner
/* D985FC 80240D6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D98600 80240D70 AFB00010 */  sw        $s0, 0x10($sp)
/* D98604 80240D74 0080802D */  daddu     $s0, $a0, $zero
/* D98608 80240D78 AFBF0014 */  sw        $ra, 0x14($sp)
/* D9860C 80240D7C 8E020088 */  lw        $v0, 0x88($s0)
/* D98610 80240D80 14400017 */  bnez      $v0, .L80240DE0
/* D98614 80240D84 24020001 */   addiu    $v0, $zero, 1
/* D98618 80240D88 8E030084 */  lw        $v1, 0x84($s0)
/* D9861C 80240D8C 1062001A */  beq       $v1, $v0, .L80240DF8
/* D98620 80240D90 00000000 */   nop
/* D98624 80240D94 28620002 */  slti      $v0, $v1, 2
/* D98628 80240D98 50400005 */  beql      $v0, $zero, .L80240DB0
/* D9862C 80240D9C 24020002 */   addiu    $v0, $zero, 2
/* D98630 80240DA0 10600007 */  beqz      $v1, .L80240DC0
/* D98634 80240DA4 00000000 */   nop
/* D98638 80240DA8 08090384 */  j         .L80240E10
/* D9863C 80240DAC 00000000 */   nop
.L80240DB0:
/* D98640 80240DB0 10620007 */  beq       $v1, $v0, .L80240DD0
/* D98644 80240DB4 00000000 */   nop
/* D98648 80240DB8 08090384 */  j         .L80240E10
/* D9864C 80240DBC 00000000 */   nop
.L80240DC0:
/* D98650 80240DC0 3C048024 */  lui       $a0, %hi(pra_39_SetPartnerFlagsA0000)
/* D98654 80240DC4 24840EB4 */  addiu     $a0, $a0, %lo(pra_39_SetPartnerFlagsA0000)
/* D98658 80240DC8 08090380 */  j         .L80240E00
/* D9865C 80240DCC 00000000 */   nop
.L80240DD0:
/* D98660 80240DD0 3C048024 */  lui       $a0, %hi(pra_39_SetPartnerFlags20000)
/* D98664 80240DD4 24840F1C */  addiu     $a0, $a0, %lo(pra_39_SetPartnerFlags20000)
/* D98668 80240DD8 08090380 */  j         .L80240E00
/* D9866C 80240DDC 00000000 */   nop
.L80240DE0:
/* D98670 80240DE0 8E020084 */  lw        $v0, 0x84($s0)
/* D98674 80240DE4 0440000A */  bltz      $v0, .L80240E10
/* D98678 80240DE8 00000000 */   nop
/* D9867C 80240DEC 28420002 */  slti      $v0, $v0, 2
/* D98680 80240DF0 10400007 */  beqz      $v0, .L80240E10
/* D98684 80240DF4 00000000 */   nop
.L80240DF8:
/* D98688 80240DF8 3C048024 */  lui       $a0, %hi(pra_39_SetPartnerFlags80000)
/* D9868C 80240DFC 24840EE8 */  addiu     $a0, $a0, %lo(pra_39_SetPartnerFlags80000)
.L80240E00:
/* D98690 80240E00 0C048C56 */  jal       create_dynamic_entity_world
/* D98694 80240E04 0000282D */   daddu    $a1, $zero, $zero
/* D98698 80240E08 8E03013C */  lw        $v1, 0x13c($s0)
/* D9869C 80240E0C AC620004 */  sw        $v0, 4($v1)
.L80240E10:
/* D986A0 80240E10 0C00EAD2 */  jal       get_npc_safe
/* D986A4 80240E14 2404FFFC */   addiu    $a0, $zero, -4
/* D986A8 80240E18 0040282D */  daddu     $a1, $v0, $zero
/* D986AC 80240E1C 10A00021 */  beqz      $a1, .L80240EA4
/* D986B0 80240E20 24020002 */   addiu    $v0, $zero, 2
/* D986B4 80240E24 8E020088 */  lw        $v0, 0x88($s0)
/* D986B8 80240E28 14400014 */  bnez      $v0, .L80240E7C
/* D986BC 80240E2C 24020001 */   addiu    $v0, $zero, 1
/* D986C0 80240E30 8E040084 */  lw        $a0, 0x84($s0)
/* D986C4 80240E34 10820016 */  beq       $a0, $v0, .L80240E90
/* D986C8 80240E38 28820002 */   slti     $v0, $a0, 2
/* D986CC 80240E3C 10400005 */  beqz      $v0, .L80240E54
/* D986D0 80240E40 24020002 */   addiu    $v0, $zero, 2
/* D986D4 80240E44 10800007 */  beqz      $a0, .L80240E64
/* D986D8 80240E48 00000000 */   nop
/* D986DC 80240E4C 080903A9 */  j         .L80240EA4
/* D986E0 80240E50 00000000 */   nop
.L80240E54:
/* D986E4 80240E54 10820006 */  beq       $a0, $v0, .L80240E70
/* D986E8 80240E58 24020002 */   addiu    $v0, $zero, 2
/* D986EC 80240E5C 080903A9 */  j         .L80240EA4
/* D986F0 80240E60 00000000 */   nop
.L80240E64:
/* D986F4 80240E64 8CA20000 */  lw        $v0, ($a1)
/* D986F8 80240E68 080903A6 */  j         .L80240E98
/* D986FC 80240E6C 3C03000A */   lui      $v1, 0xa
.L80240E70:
/* D98700 80240E70 8CA20000 */  lw        $v0, ($a1)
/* D98704 80240E74 080903A6 */  j         .L80240E98
/* D98708 80240E78 3C030002 */   lui      $v1, 2
.L80240E7C:
/* D9870C 80240E7C 8E020084 */  lw        $v0, 0x84($s0)
/* D98710 80240E80 04400007 */  bltz      $v0, .L80240EA0
/* D98714 80240E84 28420002 */   slti     $v0, $v0, 2
/* D98718 80240E88 10400006 */  beqz      $v0, .L80240EA4
/* D9871C 80240E8C 24020002 */   addiu    $v0, $zero, 2
.L80240E90:
/* D98720 80240E90 8CA20000 */  lw        $v0, ($a1)
/* D98724 80240E94 3C030008 */  lui       $v1, 8
.L80240E98:
/* D98728 80240E98 00431025 */  or        $v0, $v0, $v1
/* D9872C 80240E9C ACA20000 */  sw        $v0, ($a1)
.L80240EA0:
/* D98730 80240EA0 24020002 */  addiu     $v0, $zero, 2
.L80240EA4:
/* D98734 80240EA4 8FBF0014 */  lw        $ra, 0x14($sp)
/* D98738 80240EA8 8FB00010 */  lw        $s0, 0x10($sp)
/* D9873C 80240EAC 03E00008 */  jr        $ra
/* D98740 80240EB0 27BD0018 */   addiu    $sp, $sp, 0x18
