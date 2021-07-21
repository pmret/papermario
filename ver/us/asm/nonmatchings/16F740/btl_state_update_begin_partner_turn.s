.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_state_update_begin_partner_turn
/* 171490 80242BB0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 171494 80242BB4 AFB20018 */  sw        $s2, 0x18($sp)
/* 171498 80242BB8 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 17149C 80242BBC 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 1714A0 80242BC0 AFB10014 */  sw        $s1, 0x14($sp)
/* 1714A4 80242BC4 3C11800E */  lui       $s1, %hi(gBattleState2)
/* 1714A8 80242BC8 2631C4DC */  addiu     $s1, $s1, %lo(gBattleState2)
/* 1714AC 80242BCC AFBF0020 */  sw        $ra, 0x20($sp)
/* 1714B0 80242BD0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1714B4 80242BD4 AFB00010 */  sw        $s0, 0x10($sp)
/* 1714B8 80242BD8 8E220000 */  lw        $v0, ($s1)
/* 1714BC 80242BDC 14400016 */  bnez      $v0, .L80242C38
/* 1714C0 80242BE0 8E5000DC */   lw       $s0, 0xdc($s2)
/* 1714C4 80242BE4 16000006 */  bnez      $s0, .L80242C00
/* 1714C8 80242BE8 24030006 */   addiu    $v1, $zero, 6
/* 1714CC 80242BEC 24020001 */  addiu     $v0, $zero, 1
/* 1714D0 80242BF0 3C01802A */  lui       $at, %hi(D_8029F254)
/* 1714D4 80242BF4 AC22F254 */  sw        $v0, %lo(D_8029F254)($at)
/* 1714D8 80242BF8 08090B0D */  j         .L80242C34
/* 1714DC 80242BFC 2402000A */   addiu    $v0, $zero, 0xa
.L80242C00:
/* 1714E0 80242C00 8E420004 */  lw        $v0, 4($s2)
/* 1714E4 80242C04 30420006 */  andi      $v0, $v0, 6
/* 1714E8 80242C08 104300B1 */  beq       $v0, $v1, .L80242ED0
/* 1714EC 80242C0C 3C030020 */   lui      $v1, 0x20
/* 1714F0 80242C10 8E020000 */  lw        $v0, ($s0)
/* 1714F4 80242C14 00431024 */  and       $v0, $v0, $v1
/* 1714F8 80242C18 144000AE */  bnez      $v0, .L80242ED4
/* 1714FC 80242C1C 24040009 */   addiu    $a0, $zero, 9
/* 171500 80242C20 0C093903 */  jal       func_8024E40C
/* 171504 80242C24 24040002 */   addiu    $a0, $zero, 2
/* 171508 80242C28 0C093936 */  jal       btl_cam_move
/* 17150C 80242C2C 24040005 */   addiu    $a0, $zero, 5
/* 171510 80242C30 24020064 */  addiu     $v0, $zero, 0x64
.L80242C34:
/* 171514 80242C34 AE220000 */  sw        $v0, ($s1)
.L80242C38:
/* 171518 80242C38 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 17151C 80242C3C 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 171520 80242C40 24020064 */  addiu     $v0, $zero, 0x64
/* 171524 80242C44 14620048 */  bne       $v1, $v0, .L80242D68
/* 171528 80242C48 24020001 */   addiu    $v0, $zero, 1
/* 17152C 80242C4C 0C093961 */  jal       func_8024E584
/* 171530 80242C50 00000000 */   nop
/* 171534 80242C54 10400041 */  beqz      $v0, .L80242D5C
/* 171538 80242C58 00000000 */   nop
/* 17153C 80242C5C 3C13802A */  lui       $s3, %hi(D_8029F258)
/* 171540 80242C60 2673F258 */  addiu     $s3, $s3, %lo(D_8029F258)
/* 171544 80242C64 0C098F18 */  jal       reset_actor_turn_info
/* 171548 80242C68 AE600000 */   sw       $zero, ($s3)
/* 17154C 80242C6C 2402007F */  addiu     $v0, $zero, 0x7f
/* 171550 80242C70 3C05802A */  lui       $a1, %hi(D_8029F254)
/* 171554 80242C74 24A5F254 */  addiu     $a1, $a1, %lo(D_8029F254)
/* 171558 80242C78 8E5000DC */  lw        $s0, 0xdc($s2)
/* 17155C 80242C7C 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 171560 80242C80 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 171564 80242C84 A2420086 */  sb        $v0, 0x86($s2)
/* 171568 80242C88 A2420087 */  sb        $v0, 0x87($s2)
/* 17156C 80242C8C ACA00000 */  sw        $zero, ($a1)
/* 171570 80242C90 8E220000 */  lw        $v0, ($s1)
/* 171574 80242C94 3C030008 */  lui       $v1, 8
/* 171578 80242C98 00431025 */  or        $v0, $v0, $v1
/* 17157C 80242C9C AE220000 */  sw        $v0, ($s1)
/* 171580 80242CA0 8E220004 */  lw        $v0, 4($s1)
/* 171584 80242CA4 3C030010 */  lui       $v1, 0x10
/* 171588 80242CA8 00431025 */  or        $v0, $v0, $v1
/* 17158C 80242CAC 3C030800 */  lui       $v1, 0x800
/* 171590 80242CB0 AE220004 */  sw        $v0, 4($s1)
/* 171594 80242CB4 8E020000 */  lw        $v0, ($s0)
/* 171598 80242CB8 82040216 */  lb        $a0, 0x216($s0)
/* 17159C 80242CBC 00431025 */  or        $v0, $v0, $v1
/* 1715A0 80242CC0 10800017 */  beqz      $a0, .L80242D20
/* 1715A4 80242CC4 AE020000 */   sw       $v0, ($s0)
/* 1715A8 80242CC8 92020217 */  lbu       $v0, 0x217($s0)
/* 1715AC 80242CCC 2442FFFF */  addiu     $v0, $v0, -1
/* 1715B0 80242CD0 A2020217 */  sb        $v0, 0x217($s0)
/* 1715B4 80242CD4 24020001 */  addiu     $v0, $zero, 1
/* 1715B8 80242CD8 ACA20000 */  sw        $v0, ($a1)
/* 1715BC 80242CDC 24020014 */  addiu     $v0, $zero, 0x14
/* 1715C0 80242CE0 AE620000 */  sw        $v0, ($s3)
/* 1715C4 80242CE4 82030217 */  lb        $v1, 0x217($s0)
/* 1715C8 80242CE8 18600005 */  blez      $v1, .L80242D00
/* 1715CC 80242CEC 24040034 */   addiu    $a0, $zero, 0x34
/* 1715D0 80242CF0 8E020440 */  lw        $v0, 0x440($s0)
/* 1715D4 80242CF4 8C42000C */  lw        $v0, 0xc($v0)
/* 1715D8 80242CF8 08090B48 */  j         .L80242D20
/* 1715DC 80242CFC AC43003C */   sw       $v1, 0x3c($v0)
.L80242D00:
/* 1715E0 80242D00 0C09F7A0 */  jal       dispatch_event_partner
/* 1715E4 80242D04 A2000216 */   sb       $zero, 0x216($s0)
/* 1715E8 80242D08 8E020440 */  lw        $v0, 0x440($s0)
/* 1715EC 80242D0C 8C42000C */  lw        $v0, 0xc($v0)
/* 1715F0 80242D10 AC40003C */  sw        $zero, 0x3c($v0)
/* 1715F4 80242D14 8E220004 */  lw        $v0, 4($s1)
/* 1715F8 80242D18 34420008 */  ori       $v0, $v0, 8
/* 1715FC 80242D1C AE220004 */  sw        $v0, 4($s1)
.L80242D20:
/* 171600 80242D20 0000282D */  daddu     $a1, $zero, $zero
/* 171604 80242D24 3C060C00 */  lui       $a2, 0xc00
/* 171608 80242D28 0240202D */  daddu     $a0, $s2, $zero
.L80242D2C:
/* 17160C 80242D2C 8C8300E0 */  lw        $v1, 0xe0($a0)
/* 171610 80242D30 10600004 */  beqz      $v1, .L80242D44
/* 171614 80242D34 24A50001 */   addiu    $a1, $a1, 1
/* 171618 80242D38 8C620000 */  lw        $v0, ($v1)
/* 17161C 80242D3C 00461025 */  or        $v0, $v0, $a2
/* 171620 80242D40 AC620000 */  sw        $v0, ($v1)
.L80242D44:
/* 171624 80242D44 28A20018 */  slti      $v0, $a1, 0x18
/* 171628 80242D48 1440FFF8 */  bnez      $v0, .L80242D2C
/* 17162C 80242D4C 24840004 */   addiu    $a0, $a0, 4
/* 171630 80242D50 24020001 */  addiu     $v0, $zero, 1
/* 171634 80242D54 3C01800E */  lui       $at, %hi(gBattleState2)
/* 171638 80242D58 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
.L80242D5C:
/* 17163C 80242D5C 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 171640 80242D60 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 171644 80242D64 24020001 */  addiu     $v0, $zero, 1
.L80242D68:
/* 171648 80242D68 1462001B */  bne       $v1, $v0, .L80242DD8
/* 17164C 80242D6C 00000000 */   nop
/* 171650 80242D70 1200000A */  beqz      $s0, .L80242D9C
/* 171654 80242D74 00000000 */   nop
/* 171658 80242D78 8E0201D8 */  lw        $v0, 0x1d8($s0)
/* 17165C 80242D7C 50400007 */  beql      $v0, $zero, .L80242D9C
/* 171660 80242D80 AE0001D8 */   sw       $zero, 0x1d8($s0)
/* 171664 80242D84 8E0401E8 */  lw        $a0, 0x1e8($s0)
/* 171668 80242D88 0C0B1059 */  jal       does_script_exist
/* 17166C 80242D8C 00000000 */   nop
/* 171670 80242D90 14400011 */  bnez      $v0, .L80242DD8
/* 171674 80242D94 00000000 */   nop
/* 171678 80242D98 AE0001D8 */  sw        $zero, 0x1d8($s0)
.L80242D9C:
/* 17167C 80242D9C 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 171680 80242DA0 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 171684 80242DA4 8C430004 */  lw        $v1, 4($v0)
/* 171688 80242DA8 2404FFF7 */  addiu     $a0, $zero, -9
/* 17168C 80242DAC 00641824 */  and       $v1, $v1, $a0
/* 171690 80242DB0 0C098D19 */  jal       btl_check_player_defeated
/* 171694 80242DB4 AC430004 */   sw       $v1, 4($v0)
/* 171698 80242DB8 14400048 */  bnez      $v0, .L80242EDC
/* 17169C 80242DBC 00000000 */   nop
/* 1716A0 80242DC0 0C098D0D */  jal       btl_check_enemies_defeated
/* 1716A4 80242DC4 00000000 */   nop
/* 1716A8 80242DC8 14400044 */  bnez      $v0, .L80242EDC
/* 1716AC 80242DCC 24020008 */   addiu    $v0, $zero, 8
/* 1716B0 80242DD0 3C01800E */  lui       $at, %hi(gBattleState2)
/* 1716B4 80242DD4 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
.L80242DD8:
/* 1716B8 80242DD8 3C11800E */  lui       $s1, %hi(gBattleState2)
/* 1716BC 80242DDC 2631C4DC */  addiu     $s1, $s1, %lo(gBattleState2)
/* 1716C0 80242DE0 8E230000 */  lw        $v1, ($s1)
/* 1716C4 80242DE4 24020008 */  addiu     $v0, $zero, 8
/* 1716C8 80242DE8 14620014 */  bne       $v1, $v0, .L80242E3C
/* 1716CC 80242DEC 24020009 */   addiu    $v0, $zero, 9
/* 1716D0 80242DF0 8E0201CC */  lw        $v0, 0x1cc($s0)
/* 1716D4 80242DF4 1040000B */  beqz      $v0, .L80242E24
/* 1716D8 80242DF8 2402000C */   addiu    $v0, $zero, 0xc
/* 1716DC 80242DFC 2405000A */  addiu     $a1, $zero, 0xa
/* 1716E0 80242E00 A24201A7 */  sb        $v0, 0x1a7($s2)
/* 1716E4 80242E04 8E0401CC */  lw        $a0, 0x1cc($s0)
/* 1716E8 80242E08 0C0B0CF8 */  jal       start_script
/* 1716EC 80242E0C 0000302D */   daddu    $a2, $zero, $zero
/* 1716F0 80242E10 AE0201DC */  sw        $v0, 0x1dc($s0)
/* 1716F4 80242E14 8C430144 */  lw        $v1, 0x144($v0)
/* 1716F8 80242E18 AE0301EC */  sw        $v1, 0x1ec($s0)
/* 1716FC 80242E1C 24030100 */  addiu     $v1, $zero, 0x100
/* 171700 80242E20 AC430148 */  sw        $v1, 0x148($v0)
.L80242E24:
/* 171704 80242E24 24020009 */  addiu     $v0, $zero, 9
/* 171708 80242E28 AE220000 */  sw        $v0, ($s1)
/* 17170C 80242E2C 3C11800E */  lui       $s1, %hi(gBattleState2)
/* 171710 80242E30 2631C4DC */  addiu     $s1, $s1, %lo(gBattleState2)
/* 171714 80242E34 8E230000 */  lw        $v1, ($s1)
/* 171718 80242E38 24020009 */  addiu     $v0, $zero, 9
.L80242E3C:
/* 17171C 80242E3C 1462000A */  bne       $v1, $v0, .L80242E68
/* 171720 80242E40 00000000 */   nop
/* 171724 80242E44 8E0201CC */  lw        $v0, 0x1cc($s0)
/* 171728 80242E48 10400006 */  beqz      $v0, .L80242E64
/* 17172C 80242E4C 2402000A */   addiu    $v0, $zero, 0xa
/* 171730 80242E50 8E0401EC */  lw        $a0, 0x1ec($s0)
/* 171734 80242E54 0C0B1059 */  jal       does_script_exist
/* 171738 80242E58 00000000 */   nop
/* 17173C 80242E5C 14400002 */  bnez      $v0, .L80242E68
/* 171740 80242E60 2402000A */   addiu    $v0, $zero, 0xa
.L80242E64:
/* 171744 80242E64 AE220000 */  sw        $v0, ($s1)
.L80242E68:
/* 171748 80242E68 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 17174C 80242E6C 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 171750 80242E70 2402000A */  addiu     $v0, $zero, 0xa
/* 171754 80242E74 14620019 */  bne       $v1, $v0, .L80242EDC
/* 171758 80242E78 00000000 */   nop
/* 17175C 80242E7C 3C03802A */  lui       $v1, %hi(D_8029F258)
/* 171760 80242E80 2463F258 */  addiu     $v1, $v1, %lo(D_8029F258)
/* 171764 80242E84 8C620000 */  lw        $v0, ($v1)
/* 171768 80242E88 10400003 */  beqz      $v0, .L80242E98
/* 17176C 80242E8C 2442FFFF */   addiu    $v0, $v0, -1
/* 171770 80242E90 08090BB7 */  j         .L80242EDC
/* 171774 80242E94 AC620000 */   sw       $v0, ($v1)
.L80242E98:
/* 171778 80242E98 3C02FFEF */  lui       $v0, 0xffef
/* 17177C 80242E9C 3442FFFF */  ori       $v0, $v0, 0xffff
/* 171780 80242EA0 3C05800E */  lui       $a1, %hi(gBattleStatus)
/* 171784 80242EA4 24A5C070 */  addiu     $a1, $a1, %lo(gBattleStatus)
/* 171788 80242EA8 8CA30004 */  lw        $v1, 4($a1)
/* 17178C 80242EAC 3C04802A */  lui       $a0, %hi(D_8029F254)
/* 171790 80242EB0 8C84F254 */  lw        $a0, %lo(D_8029F254)($a0)
/* 171794 80242EB4 00621024 */  and       $v0, $v1, $v0
/* 171798 80242EB8 14800003 */  bnez      $a0, .L80242EC8
/* 17179C 80242EBC ACA20004 */   sw       $v0, 4($a1)
/* 1717A0 80242EC0 08090BB5 */  j         .L80242ED4
/* 1717A4 80242EC4 2404000B */   addiu    $a0, $zero, 0xb
.L80242EC8:
/* 1717A8 80242EC8 34420004 */  ori       $v0, $v0, 4
/* 1717AC 80242ECC ACA20004 */  sw        $v0, 4($a1)
.L80242ED0:
/* 1717B0 80242ED0 24040009 */  addiu     $a0, $zero, 9
.L80242ED4:
/* 1717B4 80242ED4 0C090464 */  jal       btl_set_state
/* 1717B8 80242ED8 00000000 */   nop
.L80242EDC:
/* 1717BC 80242EDC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1717C0 80242EE0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1717C4 80242EE4 8FB20018 */  lw        $s2, 0x18($sp)
/* 1717C8 80242EE8 8FB10014 */  lw        $s1, 0x14($sp)
/* 1717CC 80242EEC 8FB00010 */  lw        $s0, 0x10($sp)
/* 1717D0 80242EF0 03E00008 */  jr        $ra
/* 1717D4 80242EF4 27BD0028 */   addiu    $sp, $sp, 0x28
