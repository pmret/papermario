.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_state_update_switch_to_player
/* 1713A8 80242AC8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1713AC 80242ACC AFB00010 */  sw        $s0, 0x10($sp)
/* 1713B0 80242AD0 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 1713B4 80242AD4 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 1713B8 80242AD8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1713BC 80242ADC AFB20018 */  sw        $s2, 0x18($sp)
/* 1713C0 80242AE0 AFB10014 */  sw        $s1, 0x14($sp)
/* 1713C4 80242AE4 8E1200D8 */  lw        $s2, 0xd8($s0)
/* 1713C8 80242AE8 3C02800E */  lui       $v0, %hi(gBattleState2)
/* 1713CC 80242AEC 8C42C4DC */  lw        $v0, %lo(gBattleState2)($v0)
/* 1713D0 80242AF0 8E1100DC */  lw        $s1, 0xdc($s0)
/* 1713D4 80242AF4 14400026 */  bnez      $v0, .L80242B90
/* 1713D8 80242AF8 3C03FFF7 */   lui      $v1, 0xfff7
/* 1713DC 80242AFC 8E020000 */  lw        $v0, ($s0)
/* 1713E0 80242B00 3463FFFF */  ori       $v1, $v1, 0xffff
/* 1713E4 80242B04 00431024 */  and       $v0, $v0, $v1
/* 1713E8 80242B08 0C098F18 */  jal       reset_actor_turn_info
/* 1713EC 80242B0C AE020000 */   sw       $v0, ($s0)
/* 1713F0 80242B10 8E020000 */  lw        $v0, ($s0)
/* 1713F4 80242B14 2403007F */  addiu     $v1, $zero, 0x7f
/* 1713F8 80242B18 A600017C */  sh        $zero, 0x17c($s0)
/* 1713FC 80242B1C A2030086 */  sb        $v1, 0x86($s0)
/* 171400 80242B20 A2030087 */  sb        $v1, 0x87($s0)
/* 171404 80242B24 34420008 */  ori       $v0, $v0, 8
/* 171408 80242B28 AE020000 */  sw        $v0, ($s0)
/* 17140C 80242B2C 8E420000 */  lw        $v0, ($s2)
/* 171410 80242B30 3C030800 */  lui       $v1, 0x800
/* 171414 80242B34 00431025 */  or        $v0, $v0, $v1
/* 171418 80242B38 12200005 */  beqz      $s1, .L80242B50
/* 17141C 80242B3C AE420000 */   sw       $v0, ($s2)
/* 171420 80242B40 8E220000 */  lw        $v0, ($s1)
/* 171424 80242B44 3C030C00 */  lui       $v1, 0xc00
/* 171428 80242B48 00431025 */  or        $v0, $v0, $v1
/* 17142C 80242B4C AE220000 */  sw        $v0, ($s1)
.L80242B50:
/* 171430 80242B50 0000282D */  daddu     $a1, $zero, $zero
/* 171434 80242B54 3C070008 */  lui       $a3, 8
/* 171438 80242B58 3C060800 */  lui       $a2, 0x800
/* 17143C 80242B5C 0200202D */  daddu     $a0, $s0, $zero
.L80242B60:
/* 171440 80242B60 8C8300E0 */  lw        $v1, 0xe0($a0)
/* 171444 80242B64 10600005 */  beqz      $v1, .L80242B7C
/* 171448 80242B68 24A50001 */   addiu    $a1, $a1, 1
/* 17144C 80242B6C 8C620000 */  lw        $v0, ($v1)
/* 171450 80242B70 00471025 */  or        $v0, $v0, $a3
/* 171454 80242B74 00461025 */  or        $v0, $v0, $a2
/* 171458 80242B78 AC620000 */  sw        $v0, ($v1)
.L80242B7C:
/* 17145C 80242B7C 28A20018 */  slti      $v0, $a1, 0x18
/* 171460 80242B80 1440FFF7 */  bnez      $v0, .L80242B60
/* 171464 80242B84 24840004 */   addiu    $a0, $a0, 4
/* 171468 80242B88 0C090464 */  jal       btl_set_state
/* 17146C 80242B8C 2404000C */   addiu    $a0, $zero, 0xc
.L80242B90:
/* 171470 80242B90 8FBF001C */  lw        $ra, 0x1c($sp)
/* 171474 80242B94 8FB20018 */  lw        $s2, 0x18($sp)
/* 171478 80242B98 8FB10014 */  lw        $s1, 0x14($sp)
/* 17147C 80242B9C 8FB00010 */  lw        $s0, 0x10($sp)
/* 171480 80242BA0 03E00008 */  jr        $ra
/* 171484 80242BA4 27BD0020 */   addiu    $sp, $sp, 0x20
