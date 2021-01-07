.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D3C_D6F6EC
/* D6F6EC 80240D3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D6F6F0 80240D40 AFB00010 */  sw        $s0, 0x10($sp)
/* D6F6F4 80240D44 0080802D */  daddu     $s0, $a0, $zero
/* D6F6F8 80240D48 AFBF0014 */  sw        $ra, 0x14($sp)
/* D6F6FC 80240D4C 8E020088 */  lw        $v0, 0x88($s0)
/* D6F700 80240D50 14400017 */  bnez      $v0, .L80240DB0
/* D6F704 80240D54 24020001 */   addiu    $v0, $zero, 1
/* D6F708 80240D58 8E030084 */  lw        $v1, 0x84($s0)
/* D6F70C 80240D5C 1062001A */  beq       $v1, $v0, .L80240DC8
/* D6F710 80240D60 00000000 */   nop      
/* D6F714 80240D64 28620002 */  slti      $v0, $v1, 2
/* D6F718 80240D68 50400005 */  beql      $v0, $zero, .L80240D80
/* D6F71C 80240D6C 24020002 */   addiu    $v0, $zero, 2
/* D6F720 80240D70 10600007 */  beqz      $v1, .L80240D90
/* D6F724 80240D74 00000000 */   nop      
/* D6F728 80240D78 08090378 */  j         .L80240DE0
/* D6F72C 80240D7C 00000000 */   nop      
.L80240D80:
/* D6F730 80240D80 10620007 */  beq       $v1, $v0, .L80240DA0
/* D6F734 80240D84 00000000 */   nop      
/* D6F738 80240D88 08090378 */  j         .L80240DE0
/* D6F73C 80240D8C 00000000 */   nop      
.L80240D90:
/* D6F740 80240D90 3C048024 */  lui       $a0, %hi(D_80240E84)
/* D6F744 80240D94 24840E84 */  addiu     $a0, $a0, %lo(D_80240E84)
/* D6F748 80240D98 08090374 */  j         .L80240DD0
/* D6F74C 80240D9C 00000000 */   nop      
.L80240DA0:
/* D6F750 80240DA0 3C048024 */  lui       $a0, %hi(D_80240EEC)
/* D6F754 80240DA4 24840EEC */  addiu     $a0, $a0, %lo(D_80240EEC)
/* D6F758 80240DA8 08090374 */  j         .L80240DD0
/* D6F75C 80240DAC 00000000 */   nop      
.L80240DB0:
/* D6F760 80240DB0 8E020084 */  lw        $v0, 0x84($s0)
/* D6F764 80240DB4 0440000A */  bltz      $v0, .L80240DE0
/* D6F768 80240DB8 00000000 */   nop      
/* D6F76C 80240DBC 28420002 */  slti      $v0, $v0, 2
/* D6F770 80240DC0 10400007 */  beqz      $v0, .L80240DE0
/* D6F774 80240DC4 00000000 */   nop      
.L80240DC8:
/* D6F778 80240DC8 3C048024 */  lui       $a0, %hi(D_80240EB8)
/* D6F77C 80240DCC 24840EB8 */  addiu     $a0, $a0, %lo(D_80240EB8)
.L80240DD0:
/* D6F780 80240DD0 0C048C56 */  jal       bind_dynamic_entity_3
/* D6F784 80240DD4 0000282D */   daddu    $a1, $zero, $zero
/* D6F788 80240DD8 8E03013C */  lw        $v1, 0x13c($s0)
/* D6F78C 80240DDC AC620004 */  sw        $v0, 4($v1)
.L80240DE0:
/* D6F790 80240DE0 0C00EAD2 */  jal       get_npc_safe
/* D6F794 80240DE4 2404FFFC */   addiu    $a0, $zero, -4
/* D6F798 80240DE8 0040282D */  daddu     $a1, $v0, $zero
/* D6F79C 80240DEC 10A00021 */  beqz      $a1, .L80240E74
/* D6F7A0 80240DF0 24020002 */   addiu    $v0, $zero, 2
/* D6F7A4 80240DF4 8E020088 */  lw        $v0, 0x88($s0)
/* D6F7A8 80240DF8 14400014 */  bnez      $v0, .L80240E4C
/* D6F7AC 80240DFC 24020001 */   addiu    $v0, $zero, 1
/* D6F7B0 80240E00 8E040084 */  lw        $a0, 0x84($s0)
/* D6F7B4 80240E04 10820016 */  beq       $a0, $v0, .L80240E60
/* D6F7B8 80240E08 28820002 */   slti     $v0, $a0, 2
/* D6F7BC 80240E0C 10400005 */  beqz      $v0, .L80240E24
/* D6F7C0 80240E10 24020002 */   addiu    $v0, $zero, 2
/* D6F7C4 80240E14 10800007 */  beqz      $a0, .L80240E34
/* D6F7C8 80240E18 00000000 */   nop      
/* D6F7CC 80240E1C 0809039D */  j         .L80240E74
/* D6F7D0 80240E20 00000000 */   nop      
.L80240E24:
/* D6F7D4 80240E24 10820006 */  beq       $a0, $v0, .L80240E40
/* D6F7D8 80240E28 24020002 */   addiu    $v0, $zero, 2
/* D6F7DC 80240E2C 0809039D */  j         .L80240E74
/* D6F7E0 80240E30 00000000 */   nop      
.L80240E34:
/* D6F7E4 80240E34 8CA20000 */  lw        $v0, ($a1)
/* D6F7E8 80240E38 0809039A */  j         .L80240E68
/* D6F7EC 80240E3C 3C03000A */   lui      $v1, 0xa
.L80240E40:
/* D6F7F0 80240E40 8CA20000 */  lw        $v0, ($a1)
/* D6F7F4 80240E44 0809039A */  j         .L80240E68
/* D6F7F8 80240E48 3C030002 */   lui      $v1, 2
.L80240E4C:
/* D6F7FC 80240E4C 8E020084 */  lw        $v0, 0x84($s0)
/* D6F800 80240E50 04400007 */  bltz      $v0, .L80240E70
/* D6F804 80240E54 28420002 */   slti     $v0, $v0, 2
/* D6F808 80240E58 10400006 */  beqz      $v0, .L80240E74
/* D6F80C 80240E5C 24020002 */   addiu    $v0, $zero, 2
.L80240E60:
/* D6F810 80240E60 8CA20000 */  lw        $v0, ($a1)
/* D6F814 80240E64 3C030008 */  lui       $v1, 8
.L80240E68:
/* D6F818 80240E68 00431025 */  or        $v0, $v0, $v1
/* D6F81C 80240E6C ACA20000 */  sw        $v0, ($a1)
.L80240E70:
/* D6F820 80240E70 24020002 */  addiu     $v0, $zero, 2
.L80240E74:
/* D6F824 80240E74 8FBF0014 */  lw        $ra, 0x14($sp)
/* D6F828 80240E78 8FB00010 */  lw        $s0, 0x10($sp)
/* D6F82C 80240E7C 03E00008 */  jr        $ra
/* D6F830 80240E80 27BD0018 */   addiu    $sp, $sp, 0x18
