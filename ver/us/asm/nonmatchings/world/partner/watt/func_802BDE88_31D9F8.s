.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BDE88_31D9F8
/* 31D9F8 802BDE88 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 31D9FC 802BDE8C AFB10014 */  sw        $s1, 0x14($sp)
/* 31DA00 802BDE90 0080882D */  daddu     $s1, $a0, $zero
/* 31DA04 802BDE94 AFB00010 */  sw        $s0, 0x10($sp)
/* 31DA08 802BDE98 00A0802D */  daddu     $s0, $a1, $zero
/* 31DA0C 802BDE9C 2404FFFC */  addiu     $a0, $zero, -4
/* 31DA10 802BDEA0 AFBF0024 */  sw        $ra, 0x24($sp)
/* 31DA14 802BDEA4 AFB40020 */  sw        $s4, 0x20($sp)
/* 31DA18 802BDEA8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 31DA1C 802BDEAC 0C00EABB */  jal       get_npc_unsafe
/* 31DA20 802BDEB0 AFB20018 */   sw       $s2, 0x18($sp)
/* 31DA24 802BDEB4 3C148011 */  lui       $s4, %hi(gPartnerActionStatus)
/* 31DA28 802BDEB8 2694EBB0 */  addiu     $s4, $s4, %lo(gPartnerActionStatus)
/* 31DA2C 802BDEBC 3C138011 */  lui       $s3, %hi(gPlayerStatus)
/* 31DA30 802BDEC0 2673EFC8 */  addiu     $s3, $s3, %lo(gPlayerStatus)
/* 31DA34 802BDEC4 12000002 */  beqz      $s0, .L802BDED0
/* 31DA38 802BDEC8 0040902D */   daddu    $s2, $v0, $zero
/* 31DA3C 802BDECC AE200070 */  sw        $zero, 0x70($s1)
.L802BDED0:
/* 31DA40 802BDED0 8E230070 */  lw        $v1, 0x70($s1)
/* 31DA44 802BDED4 10600005 */  beqz      $v1, .L802BDEEC
/* 31DA48 802BDED8 24020001 */   addiu    $v0, $zero, 1
/* 31DA4C 802BDEDC 10620037 */  beq       $v1, $v0, .L802BDFBC
/* 31DA50 802BDEE0 0000102D */   daddu    $v0, $zero, $zero
/* 31DA54 802BDEE4 080AF7FD */  j         .L802BDFF4
/* 31DA58 802BDEE8 00000000 */   nop
.L802BDEEC:
/* 31DA5C 802BDEEC 8E2200B4 */  lw        $v0, 0xb4($s1)
/* 31DA60 802BDEF0 14400007 */  bnez      $v0, .L802BDF10
/* 31DA64 802BDEF4 00000000 */   nop
/* 31DA68 802BDEF8 0C03ADF3 */  jal       partner_kill_ability_script
/* 31DA6C 802BDEFC 00000000 */   nop
/* 31DA70 802BDF00 0C0AF460 */  jal       func_802BD180_31CCF0
/* 31DA74 802BDF04 00000000 */   nop
/* 31DA78 802BDF08 080AF7C6 */  j         .L802BDF18
/* 31DA7C 802BDF0C 00000000 */   nop
.L802BDF10:
/* 31DA80 802BDF10 0C0AF440 */  jal       func_802BD100_31CC70
/* 31DA84 802BDF14 0240202D */   daddu    $a0, $s2, $zero
.L802BDF18:
/* 31DA88 802BDF18 C6220088 */  lwc1      $f2, 0x88($s1)
/* 31DA8C 802BDF1C 468010A0 */  cvt.s.w   $f2, $f2
/* 31DA90 802BDF20 44061000 */  mfc1      $a2, $f2
/* 31DA94 802BDF24 C6220090 */  lwc1      $f2, 0x90($s1)
/* 31DA98 802BDF28 468010A0 */  cvt.s.w   $f2, $f2
/* 31DA9C 802BDF2C 8E220094 */  lw        $v0, 0x94($s1)
/* 31DAA0 802BDF30 44071000 */  mfc1      $a3, $f2
/* 31DAA4 802BDF34 AE220074 */  sw        $v0, 0x74($s1)
/* 31DAA8 802BDF38 C66C0028 */  lwc1      $f12, 0x28($s3)
/* 31DAAC 802BDF3C 0C00A720 */  jal       atan2
/* 31DAB0 802BDF40 C66E0030 */   lwc1     $f14, 0x30($s3)
/* 31DAB4 802BDF44 E6600080 */  swc1      $f0, 0x80($s3)
/* 31DAB8 802BDF48 E66000A0 */  swc1      $f0, 0xa0($s3)
/* 31DABC 802BDF4C 8E240074 */  lw        $a0, 0x74($s1)
/* 31DAC0 802BDF50 8E260098 */  lw        $a2, 0x98($s1)
/* 31DAC4 802BDF54 44050000 */  mfc1      $a1, $f0
/* 31DAC8 802BDF58 0C0389DE */  jal       move_player
/* 31DACC 802BDF5C 00000000 */   nop
/* 31DAD0 802BDF60 0C0AF81C */  jal       func_802BE070_31DBE0
/* 31DAD4 802BDF64 00000000 */   nop
/* 31DAD8 802BDF68 8E420000 */  lw        $v0, ($s2)
/* 31DADC 802BDF6C 2403FDFF */  addiu     $v1, $zero, -0x201
/* 31DAE0 802BDF70 00431024 */  and       $v0, $v0, $v1
/* 31DAE4 802BDF74 34420100 */  ori       $v0, $v0, 0x100
/* 31DAE8 802BDF78 AE420000 */  sw        $v0, ($s2)
/* 31DAEC 802BDF7C 8E620004 */  lw        $v0, 4($s3)
/* 31DAF0 802BDF80 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 31DAF4 802BDF84 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 31DAF8 802BDF88 34420003 */  ori       $v0, $v0, 3
/* 31DAFC 802BDF8C AE620004 */  sw        $v0, 4($s3)
/* 31DB00 802BDF90 24020001 */  addiu     $v0, $zero, 1
/* 31DB04 802BDF94 A062007D */  sb        $v0, 0x7d($v1)
/* 31DB08 802BDF98 A2820000 */  sb        $v0, ($s4)
/* 31DB0C 802BDF9C 24020006 */  addiu     $v0, $zero, 6
/* 31DB10 802BDFA0 A2820003 */  sb        $v0, 3($s4)
/* 31DB14 802BDFA4 8E220070 */  lw        $v0, 0x70($s1)
/* 31DB18 802BDFA8 3C01802C */  lui       $at, %hi(D_802BE308)
/* 31DB1C 802BDFAC AC20E308 */  sw        $zero, %lo(D_802BE308)($at)
/* 31DB20 802BDFB0 24420001 */  addiu     $v0, $v0, 1
/* 31DB24 802BDFB4 080AF7FC */  j         .L802BDFF0
/* 31DB28 802BDFB8 AE220070 */   sw       $v0, 0x70($s1)
.L802BDFBC:
/* 31DB2C 802BDFBC 0C0AF81C */  jal       func_802BE070_31DBE0
/* 31DB30 802BDFC0 00000000 */   nop
/* 31DB34 802BDFC4 8E220074 */  lw        $v0, 0x74($s1)
/* 31DB38 802BDFC8 2442FFFF */  addiu     $v0, $v0, -1
/* 31DB3C 802BDFCC 14400008 */  bnez      $v0, .L802BDFF0
/* 31DB40 802BDFD0 AE220074 */   sw       $v0, 0x74($s1)
/* 31DB44 802BDFD4 8E2200B4 */  lw        $v0, 0xb4($s1)
/* 31DB48 802BDFD8 10400006 */  beqz      $v0, .L802BDFF4
/* 31DB4C 802BDFDC 24020002 */   addiu    $v0, $zero, 2
/* 31DB50 802BDFE0 0C03ACC5 */  jal       partner_use_ability
/* 31DB54 802BDFE4 00000000 */   nop
/* 31DB58 802BDFE8 080AF7FD */  j         .L802BDFF4
/* 31DB5C 802BDFEC 24020002 */   addiu    $v0, $zero, 2
.L802BDFF0:
/* 31DB60 802BDFF0 0000102D */  daddu     $v0, $zero, $zero
.L802BDFF4:
/* 31DB64 802BDFF4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 31DB68 802BDFF8 8FB40020 */  lw        $s4, 0x20($sp)
/* 31DB6C 802BDFFC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 31DB70 802BE000 8FB20018 */  lw        $s2, 0x18($sp)
/* 31DB74 802BE004 8FB10014 */  lw        $s1, 0x14($sp)
/* 31DB78 802BE008 8FB00010 */  lw        $s0, 0x10($sp)
/* 31DB7C 802BE00C 03E00008 */  jr        $ra
/* 31DB80 802BE010 27BD0028 */   addiu    $sp, $sp, 0x28
