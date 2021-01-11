.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802AE000_316C00
/* 316C00 802AE000 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 316C04 802AE004 AFB40028 */  sw        $s4, 0x28($sp)
/* 316C08 802AE008 3C144BF1 */  lui       $s4, 0x4bf1
/* 316C0C 802AE00C 36945BF6 */  ori       $s4, $s4, 0x5bf6
/* 316C10 802AE010 AFB30024 */  sw        $s3, 0x24($sp)
/* 316C14 802AE014 3C137013 */  lui       $s3, 0x7013
/* 316C18 802AE018 2673BC11 */  addiu     $s3, $s3, -0x43ef
/* 316C1C 802AE01C AFB00018 */  sw        $s0, 0x18($sp)
/* 316C20 802AE020 0000802D */  daddu     $s0, $zero, $zero
/* 316C24 802AE024 3C05B000 */  lui       $a1, 0xb000
/* 316C28 802AE028 34A50574 */  ori       $a1, $a1, 0x574
/* 316C2C 802AE02C 3C04800A */  lui       $a0, %hi(carthandle)
/* 316C30 802AE030 8C84A638 */  lw        $a0, %lo(carthandle)($a0)
/* 316C34 802AE034 27A60010 */  addiu     $a2, $sp, 0x10
/* 316C38 802AE038 AFB20020 */  sw        $s2, 0x20($sp)
/* 316C3C 802AE03C 0200902D */  daddu     $s2, $s0, $zero
/* 316C40 802AE040 AFB5002C */  sw        $s5, 0x2c($sp)
/* 316C44 802AE044 3C158006 */  lui       $s5, %hi(osEPiReadIo)
/* 316C48 802AE048 26B50DC0 */  addiu     $s5, $s5, %lo(osEPiReadIo)
/* 316C4C 802AE04C AFBF003C */  sw        $ra, 0x3c($sp)
/* 316C50 802AE050 AFBE0038 */  sw        $fp, 0x38($sp)
/* 316C54 802AE054 AFB70034 */  sw        $s7, 0x34($sp)
/* 316C58 802AE058 AFB60030 */  sw        $s6, 0x30($sp)
/* 316C5C 802AE05C 02A0F809 */  jalr      $s5
/* 316C60 802AE060 AFB1001C */   sw       $s1, 0x1c($sp)
/* 316C64 802AE064 3C110031 */  lui       $s1, 0x31
/* 316C68 802AE068 26316A70 */  addiu     $s1, $s1, 0x6a70
/* 316C6C 802AE06C 8FA20010 */  lw        $v0, 0x10($sp)
/* 316C70 802AE070 3C030031 */  lui       $v1, 0x31
/* 316C74 802AE074 24636C00 */  addiu     $v1, $v1, 0x6c00
/* 316C78 802AE078 0282A023 */  subu      $s4, $s4, $v0
/* 316C7C 802AE07C 0223102B */  sltu      $v0, $s1, $v1
/* 316C80 802AE080 1040002B */  beqz      $v0, .L802AE130
/* 316C84 802AE084 241E0023 */   addiu    $fp, $zero, 0x23
/* 316C88 802AE088 24170003 */  addiu     $s7, $zero, 3
/* 316C8C 802AE08C 0060B02D */  daddu     $s6, $v1, $zero
.L802AE090:
/* 316C90 802AE090 0220282D */  daddu     $a1, $s1, $zero
/* 316C94 802AE094 3C04800A */  lui       $a0, %hi(carthandle)
/* 316C98 802AE098 8C84A638 */  lw        $a0, %lo(carthandle)($a0)
/* 316C9C 802AE09C 02A0F809 */  jalr      $s5
/* 316CA0 802AE0A0 27A60010 */   addiu    $a2, $sp, 0x10
/* 316CA4 802AE0A4 8FA30010 */  lw        $v1, 0x10($sp)
/* 316CA8 802AE0A8 2407000F */  addiu     $a3, $zero, 0xf
/* 316CAC 802AE0AC 3065FFFF */  andi      $a1, $v1, 0xffff
/* 316CB0 802AE0B0 00032402 */  srl       $a0, $v1, 0x10
/* 316CB4 802AE0B4 00A41021 */  addu      $v0, $a1, $a0
/* 316CB8 802AE0B8 02028021 */  addu      $s0, $s0, $v0
/* 316CBC 802AE0BC 00121682 */  srl       $v0, $s2, 0x1a
/* 316CC0 802AE0C0 1447000F */  bne       $v0, $a3, .L802AE100
/* 316CC4 802AE0C4 00031682 */   srl      $v0, $v1, 0x1a
/* 316CC8 802AE0C8 24070009 */  addiu     $a3, $zero, 9
/* 316CCC 802AE0CC 50470003 */  beql      $v0, $a3, .L802AE0DC
/* 316CD0 802AE0D0 00031542 */   srl      $v0, $v1, 0x15
/* 316CD4 802AE0D4 145E000A */  bne       $v0, $fp, .L802AE100
/* 316CD8 802AE0D8 00031542 */   srl      $v0, $v1, 0x15
.L802AE0DC:
/* 316CDC 802AE0DC 3043001F */  andi      $v1, $v0, 0x1f
/* 316CE0 802AE0E0 00121402 */  srl       $v0, $s2, 0x10
/* 316CE4 802AE0E4 3042001F */  andi      $v0, $v0, 0x1f
/* 316CE8 802AE0E8 14620005 */  bne       $v1, $v0, .L802AE100
/* 316CEC 802AE0EC 3082001F */   andi     $v0, $a0, 0x1f
/* 316CF0 802AE0F0 14620003 */  bne       $v1, $v0, .L802AE100
/* 316CF4 802AE0F4 3242FFFF */   andi     $v0, $s2, 0xffff
/* 316CF8 802AE0F8 02058023 */  subu      $s0, $s0, $a1
/* 316CFC 802AE0FC 02028023 */  subu      $s0, $s0, $v0
.L802AE100:
/* 316D00 802AE100 8FA40010 */  lw        $a0, 0x10($sp)
/* 316D04 802AE104 00041682 */  srl       $v0, $a0, 0x1a
/* 316D08 802AE108 14570006 */  bne       $v0, $s7, .L802AE124
/* 316D0C 802AE10C 26310004 */   addiu    $s1, $s1, 4
/* 316D10 802AE110 3083FFFF */  andi      $v1, $a0, 0xffff
/* 316D14 802AE114 00041402 */  srl       $v0, $a0, 0x10
/* 316D18 802AE118 3042FC00 */  andi      $v0, $v0, 0xfc00
/* 316D1C 802AE11C 00621821 */  addu      $v1, $v1, $v0
/* 316D20 802AE120 02038023 */  subu      $s0, $s0, $v1
.L802AE124:
/* 316D24 802AE124 0236102B */  sltu      $v0, $s1, $s6
/* 316D28 802AE128 1440FFD9 */  bnez      $v0, .L802AE090
/* 316D2C 802AE12C 0080902D */   daddu    $s2, $a0, $zero
.L802AE130:
/* 316D30 802AE130 3C02FFDB */  lui       $v0, 0xffdb
/* 316D34 802AE134 34426641 */  ori       $v0, $v0, 0x6641
/* 316D38 802AE138 02021021 */  addu      $v0, $s0, $v0
/* 316D3C 802AE13C 02821023 */  subu      $v0, $s4, $v0
/* 316D40 802AE140 02629821 */  addu      $s3, $s3, $v0
/* 316D44 802AE144 00131F02 */  srl       $v1, $s3, 0x1c
/* 316D48 802AE148 24020008 */  addiu     $v0, $zero, 8
/* 316D4C 802AE14C 14620003 */  bne       $v1, $v0, .L802AE15C
/* 316D50 802AE150 00000000 */   nop
/* 316D54 802AE154 0260F809 */  jalr      $s3
/* 316D58 802AE158 00000000 */   nop
.L802AE15C:
/* 316D5C 802AE15C 8FBF003C */  lw        $ra, 0x3c($sp)
/* 316D60 802AE160 8FBE0038 */  lw        $fp, 0x38($sp)
/* 316D64 802AE164 8FB70034 */  lw        $s7, 0x34($sp)
/* 316D68 802AE168 8FB60030 */  lw        $s6, 0x30($sp)
/* 316D6C 802AE16C 8FB5002C */  lw        $s5, 0x2c($sp)
/* 316D70 802AE170 8FB40028 */  lw        $s4, 0x28($sp)
/* 316D74 802AE174 8FB30024 */  lw        $s3, 0x24($sp)
/* 316D78 802AE178 8FB20020 */  lw        $s2, 0x20($sp)
/* 316D7C 802AE17C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 316D80 802AE180 8FB00018 */  lw        $s0, 0x18($sp)
/* 316D84 802AE184 03E00008 */  jr        $ra
/* 316D88 802AE188 27BD0040 */   addiu    $sp, $sp, 0x40
/* 316D8C 802AE18C 00000000 */  nop
