.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802DA240
.word L802D40D4_F8A84, L802D40E0_F8A90, L802D4148_F8AF8, L802D40EC_F8A9C, L802D40F8_F8AA8, L802D4104_F8AB4

.section .text

glabel func_802D4050
/* F8A00 802D4050 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F8A04 802D4054 AFB20018 */  sw        $s2, 0x18($sp)
/* F8A08 802D4058 0080902D */  daddu     $s2, $a0, $zero
/* F8A0C 802D405C AFBF001C */  sw        $ra, 0x1c($sp)
/* F8A10 802D4060 AFB10014 */  sw        $s1, 0x14($sp)
/* F8A14 802D4064 AFB00010 */  sw        $s0, 0x10($sp)
/* F8A18 802D4068 8E51000C */  lw        $s1, 0xc($s2)
/* F8A1C 802D406C 8E250000 */  lw        $a1, ($s1)
/* F8A20 802D4070 0C0B1EAF */  jal       get_variable
/* F8A24 802D4074 26310004 */   addiu    $s1, $s1, 4
/* F8A28 802D4078 0240202D */  daddu     $a0, $s2, $zero
/* F8A2C 802D407C 8E250000 */  lw        $a1, ($s1)
/* F8A30 802D4080 0C0B1EAF */  jal       get_variable
/* F8A34 802D4084 0040802D */   daddu    $s0, $v0, $zero
/* F8A38 802D4088 3C03802E */  lui       $v1, %hi(D_802DB7C0)
/* F8A3C 802D408C 8C63B7C0 */  lw        $v1, %lo(D_802DB7C0)($v1)
/* F8A40 802D4090 00108080 */  sll       $s0, $s0, 2
/* F8A44 802D4094 02038021 */  addu      $s0, $s0, $v1
/* F8A48 802D4098 8E030000 */  lw        $v1, ($s0)
/* F8A4C 802D409C 26310004 */  addiu     $s1, $s1, 4
/* F8A50 802D40A0 8C640000 */  lw        $a0, ($v1)
/* F8A54 802D40A4 0C048B77 */  jal       get_entity_model
/* F8A58 802D40A8 0040802D */   daddu    $s0, $v0, $zero
/* F8A5C 802D40AC 0040182D */  daddu     $v1, $v0, $zero
/* F8A60 802D40B0 26100001 */  addiu     $s0, $s0, 1
/* F8A64 802D40B4 2E020006 */  sltiu     $v0, $s0, 6
/* F8A68 802D40B8 10400023 */  beqz      $v0, L802D4148_F8AF8
/* F8A6C 802D40BC 00101080 */   sll      $v0, $s0, 2
/* F8A70 802D40C0 3C01802E */  lui       $at, %hi(jtbl_802DA240)
/* F8A74 802D40C4 00220821 */  addu      $at, $at, $v0
/* F8A78 802D40C8 8C22A240 */  lw        $v0, %lo(jtbl_802DA240)($at)
/* F8A7C 802D40CC 00400008 */  jr        $v0
/* F8A80 802D40D0 00000000 */   nop
glabel L802D40D4_F8A84
/* F8A84 802D40D4 24020001 */  addiu     $v0, $zero, 1
/* F8A88 802D40D8 080B5052 */  j         L802D4148_F8AF8
/* F8A8C 802D40DC A0620004 */   sb       $v0, 4($v1)
glabel L802D40E0_F8A90
/* F8A90 802D40E0 24020001 */  addiu     $v0, $zero, 1
/* F8A94 802D40E4 080B5047 */  j         .L802D411C
/* F8A98 802D40E8 A0620004 */   sb       $v0, 4($v1)
glabel L802D40EC_F8A9C
/* F8A9C 802D40EC 2402000D */  addiu     $v0, $zero, 0xd
/* F8AA0 802D40F0 080B5047 */  j         .L802D411C
/* F8AA4 802D40F4 A0620004 */   sb       $v0, 4($v1)
glabel L802D40F8_F8AA8
/* F8AA8 802D40F8 24020016 */  addiu     $v0, $zero, 0x16
/* F8AAC 802D40FC 080B504F */  j         .L802D413C
/* F8AB0 802D4100 A0620004 */   sb       $v0, 4($v1)
glabel L802D4104_F8AB4
/* F8AB4 802D4104 24020016 */  addiu     $v0, $zero, 0x16
/* F8AB8 802D4108 A0620004 */  sb        $v0, 4($v1)
/* F8ABC 802D410C 8E250000 */  lw        $a1, ($s1)
/* F8AC0 802D4110 26310004 */  addiu     $s1, $s1, 4
/* F8AC4 802D4114 0C0B1EAF */  jal       get_variable
/* F8AC8 802D4118 0240202D */   daddu    $a0, $s2, $zero
.L802D411C:
/* F8ACC 802D411C 8E250000 */  lw        $a1, ($s1)
/* F8AD0 802D4120 26310004 */  addiu     $s1, $s1, 4
/* F8AD4 802D4124 0C0B1EAF */  jal       get_variable
/* F8AD8 802D4128 0240202D */   daddu    $a0, $s2, $zero
/* F8ADC 802D412C 8E250000 */  lw        $a1, ($s1)
/* F8AE0 802D4130 26310004 */  addiu     $s1, $s1, 4
/* F8AE4 802D4134 0C0B1EAF */  jal       get_variable
/* F8AE8 802D4138 0240202D */   daddu    $a0, $s2, $zero
.L802D413C:
/* F8AEC 802D413C 8E250000 */  lw        $a1, ($s1)
/* F8AF0 802D4140 0C0B1EAF */  jal       get_variable
/* F8AF4 802D4144 0240202D */   daddu    $a0, $s2, $zero
glabel L802D4148_F8AF8
/* F8AF8 802D4148 8FBF001C */  lw        $ra, 0x1c($sp)
/* F8AFC 802D414C 8FB20018 */  lw        $s2, 0x18($sp)
/* F8B00 802D4150 8FB10014 */  lw        $s1, 0x14($sp)
/* F8B04 802D4154 8FB00010 */  lw        $s0, 0x10($sp)
/* F8B08 802D4158 24020002 */  addiu     $v0, $zero, 2
/* F8B0C 802D415C 03E00008 */  jr        $ra
/* F8B10 802D4160 27BD0020 */   addiu    $sp, $sp, 0x20
