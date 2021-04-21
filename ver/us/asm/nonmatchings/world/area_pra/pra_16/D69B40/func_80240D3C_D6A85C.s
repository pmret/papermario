.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pra_16_ReflectPartner
/* D6A85C 80240D3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D6A860 80240D40 AFB00010 */  sw        $s0, 0x10($sp)
/* D6A864 80240D44 0080802D */  daddu     $s0, $a0, $zero
/* D6A868 80240D48 AFBF0014 */  sw        $ra, 0x14($sp)
/* D6A86C 80240D4C 8E020088 */  lw        $v0, 0x88($s0)
/* D6A870 80240D50 14400017 */  bnez      $v0, .L80240DB0
/* D6A874 80240D54 24020001 */   addiu    $v0, $zero, 1
/* D6A878 80240D58 8E030084 */  lw        $v1, 0x84($s0)
/* D6A87C 80240D5C 1062001A */  beq       $v1, $v0, .L80240DC8
/* D6A880 80240D60 00000000 */   nop
/* D6A884 80240D64 28620002 */  slti      $v0, $v1, 2
/* D6A888 80240D68 50400005 */  beql      $v0, $zero, .L80240D80
/* D6A88C 80240D6C 24020002 */   addiu    $v0, $zero, 2
/* D6A890 80240D70 10600007 */  beqz      $v1, .L80240D90
/* D6A894 80240D74 00000000 */   nop
/* D6A898 80240D78 08090378 */  j         .L80240DE0
/* D6A89C 80240D7C 00000000 */   nop
.L80240D80:
/* D6A8A0 80240D80 10620007 */  beq       $v1, $v0, .L80240DA0
/* D6A8A4 80240D84 00000000 */   nop
/* D6A8A8 80240D88 08090378 */  j         .L80240DE0
/* D6A8AC 80240D8C 00000000 */   nop
.L80240D90:
/* D6A8B0 80240D90 3C048024 */  lui       $a0, %hi(pra_16_SetPartnerFlagsA0000)
/* D6A8B4 80240D94 24840E84 */  addiu     $a0, $a0, %lo(pra_16_SetPartnerFlagsA0000)
/* D6A8B8 80240D98 08090374 */  j         .L80240DD0
/* D6A8BC 80240D9C 00000000 */   nop
.L80240DA0:
/* D6A8C0 80240DA0 3C048024 */  lui       $a0, %hi(pra_16_SetPartnerFlags20000)
/* D6A8C4 80240DA4 24840EEC */  addiu     $a0, $a0, %lo(pra_16_SetPartnerFlags20000)
/* D6A8C8 80240DA8 08090374 */  j         .L80240DD0
/* D6A8CC 80240DAC 00000000 */   nop
.L80240DB0:
/* D6A8D0 80240DB0 8E020084 */  lw        $v0, 0x84($s0)
/* D6A8D4 80240DB4 0440000A */  bltz      $v0, .L80240DE0
/* D6A8D8 80240DB8 00000000 */   nop
/* D6A8DC 80240DBC 28420002 */  slti      $v0, $v0, 2
/* D6A8E0 80240DC0 10400007 */  beqz      $v0, .L80240DE0
/* D6A8E4 80240DC4 00000000 */   nop
.L80240DC8:
/* D6A8E8 80240DC8 3C048024 */  lui       $a0, %hi(pra_16_SetPartnerFlags80000)
/* D6A8EC 80240DCC 24840EB8 */  addiu     $a0, $a0, %lo(pra_16_SetPartnerFlags80000)
.L80240DD0:
/* D6A8F0 80240DD0 0C048C56 */  jal       create_dynamic_entity_world
/* D6A8F4 80240DD4 0000282D */   daddu    $a1, $zero, $zero
/* D6A8F8 80240DD8 8E03013C */  lw        $v1, 0x13c($s0)
/* D6A8FC 80240DDC AC620004 */  sw        $v0, 4($v1)
.L80240DE0:
/* D6A900 80240DE0 0C00EAD2 */  jal       get_npc_safe
/* D6A904 80240DE4 2404FFFC */   addiu    $a0, $zero, -4
/* D6A908 80240DE8 0040282D */  daddu     $a1, $v0, $zero
/* D6A90C 80240DEC 10A00021 */  beqz      $a1, .L80240E74
/* D6A910 80240DF0 24020002 */   addiu    $v0, $zero, 2
/* D6A914 80240DF4 8E020088 */  lw        $v0, 0x88($s0)
/* D6A918 80240DF8 14400014 */  bnez      $v0, .L80240E4C
/* D6A91C 80240DFC 24020001 */   addiu    $v0, $zero, 1
/* D6A920 80240E00 8E040084 */  lw        $a0, 0x84($s0)
/* D6A924 80240E04 10820016 */  beq       $a0, $v0, .L80240E60
/* D6A928 80240E08 28820002 */   slti     $v0, $a0, 2
/* D6A92C 80240E0C 10400005 */  beqz      $v0, .L80240E24
/* D6A930 80240E10 24020002 */   addiu    $v0, $zero, 2
/* D6A934 80240E14 10800007 */  beqz      $a0, .L80240E34
/* D6A938 80240E18 00000000 */   nop
/* D6A93C 80240E1C 0809039D */  j         .L80240E74
/* D6A940 80240E20 00000000 */   nop
.L80240E24:
/* D6A944 80240E24 10820006 */  beq       $a0, $v0, .L80240E40
/* D6A948 80240E28 24020002 */   addiu    $v0, $zero, 2
/* D6A94C 80240E2C 0809039D */  j         .L80240E74
/* D6A950 80240E30 00000000 */   nop
.L80240E34:
/* D6A954 80240E34 8CA20000 */  lw        $v0, ($a1)
/* D6A958 80240E38 0809039A */  j         .L80240E68
/* D6A95C 80240E3C 3C03000A */   lui      $v1, 0xa
.L80240E40:
/* D6A960 80240E40 8CA20000 */  lw        $v0, ($a1)
/* D6A964 80240E44 0809039A */  j         .L80240E68
/* D6A968 80240E48 3C030002 */   lui      $v1, 2
.L80240E4C:
/* D6A96C 80240E4C 8E020084 */  lw        $v0, 0x84($s0)
/* D6A970 80240E50 04400007 */  bltz      $v0, .L80240E70
/* D6A974 80240E54 28420002 */   slti     $v0, $v0, 2
/* D6A978 80240E58 10400006 */  beqz      $v0, .L80240E74
/* D6A97C 80240E5C 24020002 */   addiu    $v0, $zero, 2
.L80240E60:
/* D6A980 80240E60 8CA20000 */  lw        $v0, ($a1)
/* D6A984 80240E64 3C030008 */  lui       $v1, 8
.L80240E68:
/* D6A988 80240E68 00431025 */  or        $v0, $v0, $v1
/* D6A98C 80240E6C ACA20000 */  sw        $v0, ($a1)
.L80240E70:
/* D6A990 80240E70 24020002 */  addiu     $v0, $zero, 2
.L80240E74:
/* D6A994 80240E74 8FBF0014 */  lw        $ra, 0x14($sp)
/* D6A998 80240E78 8FB00010 */  lw        $s0, 0x10($sp)
/* D6A99C 80240E7C 03E00008 */  jr        $ra
/* D6A9A0 80240E80 27BD0018 */   addiu    $sp, $sp, 0x18
