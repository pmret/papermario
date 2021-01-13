.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D6C_D7A75C
/* D7A75C 80240D6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7A760 80240D70 AFB00010 */  sw        $s0, 0x10($sp)
/* D7A764 80240D74 0080802D */  daddu     $s0, $a0, $zero
/* D7A768 80240D78 AFBF0014 */  sw        $ra, 0x14($sp)
/* D7A76C 80240D7C 8E020088 */  lw        $v0, 0x88($s0)
/* D7A770 80240D80 14400017 */  bnez      $v0, .L80240DE0
/* D7A774 80240D84 24020001 */   addiu    $v0, $zero, 1
/* D7A778 80240D88 8E030084 */  lw        $v1, 0x84($s0)
/* D7A77C 80240D8C 1062001A */  beq       $v1, $v0, .L80240DF8
/* D7A780 80240D90 00000000 */   nop
/* D7A784 80240D94 28620002 */  slti      $v0, $v1, 2
/* D7A788 80240D98 50400005 */  beql      $v0, $zero, .L80240DB0
/* D7A78C 80240D9C 24020002 */   addiu    $v0, $zero, 2
/* D7A790 80240DA0 10600007 */  beqz      $v1, .L80240DC0
/* D7A794 80240DA4 00000000 */   nop
/* D7A798 80240DA8 08090384 */  j         .L80240E10
/* D7A79C 80240DAC 00000000 */   nop
.L80240DB0:
/* D7A7A0 80240DB0 10620007 */  beq       $v1, $v0, .L80240DD0
/* D7A7A4 80240DB4 00000000 */   nop
/* D7A7A8 80240DB8 08090384 */  j         .L80240E10
/* D7A7AC 80240DBC 00000000 */   nop
.L80240DC0:
/* D7A7B0 80240DC0 3C048024 */  lui       $a0, %hi(pra_27_SetPartnerFlagsA0000)
/* D7A7B4 80240DC4 24840EB4 */  addiu     $a0, $a0, %lo(pra_27_SetPartnerFlagsA0000)
/* D7A7B8 80240DC8 08090380 */  j         .L80240E00
/* D7A7BC 80240DCC 00000000 */   nop
.L80240DD0:
/* D7A7C0 80240DD0 3C048024 */  lui       $a0, %hi(pra_27_SetPartnerFlags20000)
/* D7A7C4 80240DD4 24840F1C */  addiu     $a0, $a0, %lo(pra_27_SetPartnerFlags20000)
/* D7A7C8 80240DD8 08090380 */  j         .L80240E00
/* D7A7CC 80240DDC 00000000 */   nop
.L80240DE0:
/* D7A7D0 80240DE0 8E020084 */  lw        $v0, 0x84($s0)
/* D7A7D4 80240DE4 0440000A */  bltz      $v0, .L80240E10
/* D7A7D8 80240DE8 00000000 */   nop
/* D7A7DC 80240DEC 28420002 */  slti      $v0, $v0, 2
/* D7A7E0 80240DF0 10400007 */  beqz      $v0, .L80240E10
/* D7A7E4 80240DF4 00000000 */   nop
.L80240DF8:
/* D7A7E8 80240DF8 3C048024 */  lui       $a0, %hi(pra_27_SetPartnerFlags80000)
/* D7A7EC 80240DFC 24840EE8 */  addiu     $a0, $a0, %lo(pra_27_SetPartnerFlags80000)
.L80240E00:
/* D7A7F0 80240E00 0C048C56 */  jal       bind_dynamic_entity_3
/* D7A7F4 80240E04 0000282D */   daddu    $a1, $zero, $zero
/* D7A7F8 80240E08 8E03013C */  lw        $v1, 0x13c($s0)
/* D7A7FC 80240E0C AC620004 */  sw        $v0, 4($v1)
.L80240E10:
/* D7A800 80240E10 0C00EAD2 */  jal       get_npc_safe
/* D7A804 80240E14 2404FFFC */   addiu    $a0, $zero, -4
/* D7A808 80240E18 0040282D */  daddu     $a1, $v0, $zero
/* D7A80C 80240E1C 10A00021 */  beqz      $a1, .L80240EA4
/* D7A810 80240E20 24020002 */   addiu    $v0, $zero, 2
/* D7A814 80240E24 8E020088 */  lw        $v0, 0x88($s0)
/* D7A818 80240E28 14400014 */  bnez      $v0, .L80240E7C
/* D7A81C 80240E2C 24020001 */   addiu    $v0, $zero, 1
/* D7A820 80240E30 8E040084 */  lw        $a0, 0x84($s0)
/* D7A824 80240E34 10820016 */  beq       $a0, $v0, .L80240E90
/* D7A828 80240E38 28820002 */   slti     $v0, $a0, 2
/* D7A82C 80240E3C 10400005 */  beqz      $v0, .L80240E54
/* D7A830 80240E40 24020002 */   addiu    $v0, $zero, 2
/* D7A834 80240E44 10800007 */  beqz      $a0, .L80240E64
/* D7A838 80240E48 00000000 */   nop
/* D7A83C 80240E4C 080903A9 */  j         .L80240EA4
/* D7A840 80240E50 00000000 */   nop
.L80240E54:
/* D7A844 80240E54 10820006 */  beq       $a0, $v0, .L80240E70
/* D7A848 80240E58 24020002 */   addiu    $v0, $zero, 2
/* D7A84C 80240E5C 080903A9 */  j         .L80240EA4
/* D7A850 80240E60 00000000 */   nop
.L80240E64:
/* D7A854 80240E64 8CA20000 */  lw        $v0, ($a1)
/* D7A858 80240E68 080903A6 */  j         .L80240E98
/* D7A85C 80240E6C 3C03000A */   lui      $v1, 0xa
.L80240E70:
/* D7A860 80240E70 8CA20000 */  lw        $v0, ($a1)
/* D7A864 80240E74 080903A6 */  j         .L80240E98
/* D7A868 80240E78 3C030002 */   lui      $v1, 2
.L80240E7C:
/* D7A86C 80240E7C 8E020084 */  lw        $v0, 0x84($s0)
/* D7A870 80240E80 04400007 */  bltz      $v0, .L80240EA0
/* D7A874 80240E84 28420002 */   slti     $v0, $v0, 2
/* D7A878 80240E88 10400006 */  beqz      $v0, .L80240EA4
/* D7A87C 80240E8C 24020002 */   addiu    $v0, $zero, 2
.L80240E90:
/* D7A880 80240E90 8CA20000 */  lw        $v0, ($a1)
/* D7A884 80240E94 3C030008 */  lui       $v1, 8
.L80240E98:
/* D7A888 80240E98 00431025 */  or        $v0, $v0, $v1
/* D7A88C 80240E9C ACA20000 */  sw        $v0, ($a1)
.L80240EA0:
/* D7A890 80240EA0 24020002 */  addiu     $v0, $zero, 2
.L80240EA4:
/* D7A894 80240EA4 8FBF0014 */  lw        $ra, 0x14($sp)
/* D7A898 80240EA8 8FB00010 */  lw        $s0, 0x10($sp)
/* D7A89C 80240EAC 03E00008 */  jr        $ra
/* D7A8A0 80240EB0 27BD0018 */   addiu    $sp, $sp, 0x18
