.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pra_10_ReflectPartner
/* D5FFEC 80240D3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D5FFF0 80240D40 AFB00010 */  sw        $s0, 0x10($sp)
/* D5FFF4 80240D44 0080802D */  daddu     $s0, $a0, $zero
/* D5FFF8 80240D48 AFBF0014 */  sw        $ra, 0x14($sp)
/* D5FFFC 80240D4C 8E020088 */  lw        $v0, 0x88($s0)
/* D60000 80240D50 14400017 */  bnez      $v0, .L80240DB0
/* D60004 80240D54 24020001 */   addiu    $v0, $zero, 1
/* D60008 80240D58 8E030084 */  lw        $v1, 0x84($s0)
/* D6000C 80240D5C 1062001A */  beq       $v1, $v0, .L80240DC8
/* D60010 80240D60 00000000 */   nop
/* D60014 80240D64 28620002 */  slti      $v0, $v1, 2
/* D60018 80240D68 50400005 */  beql      $v0, $zero, .L80240D80
/* D6001C 80240D6C 24020002 */   addiu    $v0, $zero, 2
/* D60020 80240D70 10600007 */  beqz      $v1, .L80240D90
/* D60024 80240D74 00000000 */   nop
/* D60028 80240D78 08090378 */  j         .L80240DE0
/* D6002C 80240D7C 00000000 */   nop
.L80240D80:
/* D60030 80240D80 10620007 */  beq       $v1, $v0, .L80240DA0
/* D60034 80240D84 00000000 */   nop
/* D60038 80240D88 08090378 */  j         .L80240DE0
/* D6003C 80240D8C 00000000 */   nop
.L80240D90:
/* D60040 80240D90 3C048024 */  lui       $a0, %hi(pra_10_SetPartnerFlagsA0000)
/* D60044 80240D94 24840E84 */  addiu     $a0, $a0, %lo(pra_10_SetPartnerFlagsA0000)
/* D60048 80240D98 08090374 */  j         .L80240DD0
/* D6004C 80240D9C 00000000 */   nop
.L80240DA0:
/* D60050 80240DA0 3C048024 */  lui       $a0, %hi(pra_10_SetPartnerFlags20000)
/* D60054 80240DA4 24840EEC */  addiu     $a0, $a0, %lo(pra_10_SetPartnerFlags20000)
/* D60058 80240DA8 08090374 */  j         .L80240DD0
/* D6005C 80240DAC 00000000 */   nop
.L80240DB0:
/* D60060 80240DB0 8E020084 */  lw        $v0, 0x84($s0)
/* D60064 80240DB4 0440000A */  bltz      $v0, .L80240DE0
/* D60068 80240DB8 00000000 */   nop
/* D6006C 80240DBC 28420002 */  slti      $v0, $v0, 2
/* D60070 80240DC0 10400007 */  beqz      $v0, .L80240DE0
/* D60074 80240DC4 00000000 */   nop
.L80240DC8:
/* D60078 80240DC8 3C048024 */  lui       $a0, %hi(pra_10_SetPartnerFlags80000)
/* D6007C 80240DCC 24840EB8 */  addiu     $a0, $a0, %lo(pra_10_SetPartnerFlags80000)
.L80240DD0:
/* D60080 80240DD0 0C048C56 */  jal       create_dynamic_entity_world
/* D60084 80240DD4 0000282D */   daddu    $a1, $zero, $zero
/* D60088 80240DD8 8E03013C */  lw        $v1, 0x13c($s0)
/* D6008C 80240DDC AC620004 */  sw        $v0, 4($v1)
.L80240DE0:
/* D60090 80240DE0 0C00EAD2 */  jal       get_npc_safe
/* D60094 80240DE4 2404FFFC */   addiu    $a0, $zero, -4
/* D60098 80240DE8 0040282D */  daddu     $a1, $v0, $zero
/* D6009C 80240DEC 10A00021 */  beqz      $a1, .L80240E74
/* D600A0 80240DF0 24020002 */   addiu    $v0, $zero, 2
/* D600A4 80240DF4 8E020088 */  lw        $v0, 0x88($s0)
/* D600A8 80240DF8 14400014 */  bnez      $v0, .L80240E4C
/* D600AC 80240DFC 24020001 */   addiu    $v0, $zero, 1
/* D600B0 80240E00 8E040084 */  lw        $a0, 0x84($s0)
/* D600B4 80240E04 10820016 */  beq       $a0, $v0, .L80240E60
/* D600B8 80240E08 28820002 */   slti     $v0, $a0, 2
/* D600BC 80240E0C 10400005 */  beqz      $v0, .L80240E24
/* D600C0 80240E10 24020002 */   addiu    $v0, $zero, 2
/* D600C4 80240E14 10800007 */  beqz      $a0, .L80240E34
/* D600C8 80240E18 00000000 */   nop
/* D600CC 80240E1C 0809039D */  j         .L80240E74
/* D600D0 80240E20 00000000 */   nop
.L80240E24:
/* D600D4 80240E24 10820006 */  beq       $a0, $v0, .L80240E40
/* D600D8 80240E28 24020002 */   addiu    $v0, $zero, 2
/* D600DC 80240E2C 0809039D */  j         .L80240E74
/* D600E0 80240E30 00000000 */   nop
.L80240E34:
/* D600E4 80240E34 8CA20000 */  lw        $v0, ($a1)
/* D600E8 80240E38 0809039A */  j         .L80240E68
/* D600EC 80240E3C 3C03000A */   lui      $v1, 0xa
.L80240E40:
/* D600F0 80240E40 8CA20000 */  lw        $v0, ($a1)
/* D600F4 80240E44 0809039A */  j         .L80240E68
/* D600F8 80240E48 3C030002 */   lui      $v1, 2
.L80240E4C:
/* D600FC 80240E4C 8E020084 */  lw        $v0, 0x84($s0)
/* D60100 80240E50 04400007 */  bltz      $v0, .L80240E70
/* D60104 80240E54 28420002 */   slti     $v0, $v0, 2
/* D60108 80240E58 10400006 */  beqz      $v0, .L80240E74
/* D6010C 80240E5C 24020002 */   addiu    $v0, $zero, 2
.L80240E60:
/* D60110 80240E60 8CA20000 */  lw        $v0, ($a1)
/* D60114 80240E64 3C030008 */  lui       $v1, 8
.L80240E68:
/* D60118 80240E68 00431025 */  or        $v0, $v0, $v1
/* D6011C 80240E6C ACA20000 */  sw        $v0, ($a1)
.L80240E70:
/* D60120 80240E70 24020002 */  addiu     $v0, $zero, 2
.L80240E74:
/* D60124 80240E74 8FBF0014 */  lw        $ra, 0x14($sp)
/* D60128 80240E78 8FB00010 */  lw        $s0, 0x10($sp)
/* D6012C 80240E7C 03E00008 */  jr        $ra
/* D60130 80240E80 27BD0018 */   addiu    $sp, $sp, 0x18
