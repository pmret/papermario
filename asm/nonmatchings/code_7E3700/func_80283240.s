.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80283240
/* 7E40C0 80283240 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7E40C4 80283244 AFB3001C */  sw        $s3, 0x1c($sp)
/* 7E40C8 80283248 0080982D */  daddu     $s3, $a0, $zero
/* 7E40CC 8028324C AFB10014 */  sw        $s1, 0x14($sp)
/* 7E40D0 80283250 0000882D */  daddu     $s1, $zero, $zero
/* 7E40D4 80283254 AFBF0024 */  sw        $ra, 0x24($sp)
/* 7E40D8 80283258 AFB40020 */  sw        $s4, 0x20($sp)
/* 7E40DC 8028325C AFB20018 */  sw        $s2, 0x18($sp)
/* 7E40E0 80283260 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E40E4 80283264 8E62000C */  lw        $v0, 0xc($s3)
/* 7E40E8 80283268 8C450004 */  lw        $a1, 4($v0)
/* 7E40EC 8028326C 8C540000 */  lw        $s4, ($v0)
/* 7E40F0 80283270 0C0B1EAF */  jal       get_variable
/* 7E40F4 80283274 0220802D */   daddu    $s0, $s1, $zero
/* 7E40F8 80283278 0040902D */  daddu     $s2, $v0, $zero
.L8028327C:
/* 7E40FC 8028327C 0C0B11E4 */  jal       get_script_by_index
/* 7E4100 80283280 0200202D */   daddu    $a0, $s0, $zero
/* 7E4104 80283284 10400006 */  beqz      $v0, .L802832A0
/* 7E4108 80283288 26100001 */   addiu    $s0, $s0, 1
/* 7E410C 8028328C 8C42015C */  lw        $v0, 0x15c($v0)
/* 7E4110 80283290 14520004 */  bne       $v0, $s2, .L802832A4
/* 7E4114 80283294 2A020080 */   slti     $v0, $s0, 0x80
/* 7E4118 80283298 080A0CAB */  j         .L802832AC
/* 7E411C 8028329C 24110001 */   addiu    $s1, $zero, 1
.L802832A0:
/* 7E4120 802832A0 2A020080 */  slti      $v0, $s0, 0x80
.L802832A4:
/* 7E4124 802832A4 1440FFF5 */  bnez      $v0, .L8028327C
/* 7E4128 802832A8 00000000 */   nop      
.L802832AC:
/* 7E412C 802832AC 0260202D */  daddu     $a0, $s3, $zero
/* 7E4130 802832B0 0280282D */  daddu     $a1, $s4, $zero
/* 7E4134 802832B4 0C0B2026 */  jal       set_variable
/* 7E4138 802832B8 0220302D */   daddu    $a2, $s1, $zero
/* 7E413C 802832BC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 7E4140 802832C0 8FB40020 */  lw        $s4, 0x20($sp)
/* 7E4144 802832C4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7E4148 802832C8 8FB20018 */  lw        $s2, 0x18($sp)
/* 7E414C 802832CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E4150 802832D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E4154 802832D4 24020002 */  addiu     $v0, $zero, 2
/* 7E4158 802832D8 03E00008 */  jr        $ra
/* 7E415C 802832DC 27BD0028 */   addiu    $sp, $sp, 0x28
