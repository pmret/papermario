.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_battle_state
/* 16CD18 8023E438 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 16CD1C 8023E43C AFB00028 */  sw        $s0, 0x28($sp)
/* 16CD20 8023E440 3C10800E */  lui       $s0, 0x800e
/* 16CD24 8023E444 2610C070 */  addiu     $s0, $s0, -0x3f90
/* 16CD28 8023E448 2402FFFF */  addiu     $v0, $zero, -1
/* 16CD2C 8023E44C AFBF0034 */  sw        $ra, 0x34($sp)
/* 16CD30 8023E450 AFB20030 */  sw        $s2, 0x30($sp)
/* 16CD34 8023E454 AFB1002C */  sw        $s1, 0x2c($sp)
/* 16CD38 8023E458 8E040224 */  lw        $a0, 0x224($s0)
/* 16CD3C 8023E45C 8E1200DC */  lw        $s2, 0xdc($s0)
/* 16CD40 8023E460 10820028 */  beq       $a0, $v0, .L8023E504
/* 16CD44 8023E464 3C030008 */   lui      $v1, 8
/* 16CD48 8023E468 8E020000 */  lw        $v0, ($s0)
/* 16CD4C 8023E46C 00431024 */  and       $v0, $v0, $v1
/* 16CD50 8023E470 10400014 */  beqz      $v0, .L8023E4C4
/* 16CD54 8023E474 00000000 */   nop      
/* 16CD58 8023E478 3C038007 */  lui       $v1, 0x8007
/* 16CD5C 8023E47C 8C63419C */  lw        $v1, 0x419c($v1)
/* 16CD60 8023E480 80620081 */  lb        $v0, 0x81($v1)
/* 16CD64 8023E484 1040000F */  beqz      $v0, .L8023E4C4
/* 16CD68 8023E488 00000000 */   nop      
/* 16CD6C 8023E48C 8C620004 */  lw        $v0, 4($v1)
/* 16CD70 8023E490 00441024 */  and       $v0, $v0, $a0
/* 16CD74 8023E494 AE020210 */  sw        $v0, 0x210($s0)
/* 16CD78 8023E498 8C620014 */  lw        $v0, 0x14($v1)
/* 16CD7C 8023E49C 00441024 */  and       $v0, $v0, $a0
/* 16CD80 8023E4A0 AE020214 */  sw        $v0, 0x214($s0)
/* 16CD84 8023E4A4 8C620024 */  lw        $v0, 0x24($v1)
/* 16CD88 8023E4A8 00441024 */  and       $v0, $v0, $a0
/* 16CD8C 8023E4AC AE020218 */  sw        $v0, 0x218($s0)
/* 16CD90 8023E4B0 80620041 */  lb        $v0, 0x41($v1)
/* 16CD94 8023E4B4 AE02021C */  sw        $v0, 0x21c($s0)
/* 16CD98 8023E4B8 80620045 */  lb        $v0, 0x45($v1)
/* 16CD9C 8023E4BC 0808F941 */  j         .L8023E504
/* 16CDA0 8023E4C0 AE020220 */   sw       $v0, 0x220($s0)
.L8023E4C4:
/* 16CDA4 8023E4C4 3C048007 */  lui       $a0, 0x8007
/* 16CDA8 8023E4C8 8C84419C */  lw        $a0, 0x419c($a0)
/* 16CDAC 8023E4CC 8E030224 */  lw        $v1, 0x224($s0)
/* 16CDB0 8023E4D0 8C820000 */  lw        $v0, ($a0)
/* 16CDB4 8023E4D4 00431024 */  and       $v0, $v0, $v1
/* 16CDB8 8023E4D8 AE020210 */  sw        $v0, 0x210($s0)
/* 16CDBC 8023E4DC 8C820010 */  lw        $v0, 0x10($a0)
/* 16CDC0 8023E4E0 00431024 */  and       $v0, $v0, $v1
/* 16CDC4 8023E4E4 AE020214 */  sw        $v0, 0x214($s0)
/* 16CDC8 8023E4E8 8C820020 */  lw        $v0, 0x20($a0)
/* 16CDCC 8023E4EC 00431024 */  and       $v0, $v0, $v1
/* 16CDD0 8023E4F0 AE020218 */  sw        $v0, 0x218($s0)
/* 16CDD4 8023E4F4 80820040 */  lb        $v0, 0x40($a0)
/* 16CDD8 8023E4F8 AE02021C */  sw        $v0, 0x21c($s0)
/* 16CDDC 8023E4FC 80820044 */  lb        $v0, 0x44($a0)
/* 16CDE0 8023E500 AE020220 */  sw        $v0, 0x220($s0)
.L8023E504:
/* 16CDE4 8023E504 27A40010 */  addiu     $a0, $sp, 0x10
/* 16CDE8 8023E508 0C08F800 */  jal       get_dpad_input_radial
/* 16CDEC 8023E50C 27A50014 */   addiu    $a1, $sp, 0x14
/* 16CDF0 8023E510 C7A00010 */  lwc1      $f0, 0x10($sp)
/* 16CDF4 8023E514 82020431 */  lb        $v0, 0x431($s0)
/* 16CDF8 8023E518 8E030214 */  lw        $v1, 0x214($s0)
/* 16CDFC 8023E51C 4600010D */  trunc.w.s $f4, $f0
/* 16CE00 8023E520 E6040228 */  swc1      $f4, 0x228($s0)
/* 16CE04 8023E524 00021080 */  sll       $v0, $v0, 2
/* 16CE08 8023E528 C7A00014 */  lwc1      $f0, 0x14($sp)
/* 16CE0C 8023E52C 02021021 */  addu      $v0, $s0, $v0
/* 16CE10 8023E530 4600010D */  trunc.w.s $f4, $f0
/* 16CE14 8023E534 E604022C */  swc1      $f4, 0x22c($s0)
/* 16CE18 8023E538 AC430330 */  sw        $v1, 0x330($v0)
/* 16CE1C 8023E53C 82020431 */  lb        $v0, 0x431($s0)
/* 16CE20 8023E540 8E030210 */  lw        $v1, 0x210($s0)
/* 16CE24 8023E544 00021080 */  sll       $v0, $v0, 2
/* 16CE28 8023E548 02021021 */  addu      $v0, $s0, $v0
/* 16CE2C 8023E54C AC430230 */  sw        $v1, 0x230($v0)
/* 16CE30 8023E550 92020431 */  lbu       $v0, 0x431($s0)
/* 16CE34 8023E554 24420001 */  addiu     $v0, $v0, 1
/* 16CE38 8023E558 A2020431 */  sb        $v0, 0x431($s0)
/* 16CE3C 8023E55C 00021600 */  sll       $v0, $v0, 0x18
/* 16CE40 8023E560 00021603 */  sra       $v0, $v0, 0x18
/* 16CE44 8023E564 28420040 */  slti      $v0, $v0, 0x40
/* 16CE48 8023E568 50400001 */  beql      $v0, $zero, .L8023E570
/* 16CE4C 8023E56C A2000431 */   sb       $zero, 0x431($s0)
.L8023E570:
/* 16CE50 8023E570 8E0200B4 */  lw        $v0, 0xb4($s0)
/* 16CE54 8023E574 10400003 */  beqz      $v0, .L8023E584
/* 16CE58 8023E578 00000000 */   nop      
/* 16CE5C 8023E57C 0040F809 */  jalr      $v0
/* 16CE60 8023E580 00000000 */   nop      
.L8023E584:
/* 16CE64 8023E584 82030095 */  lb        $v1, 0x95($s0)
/* 16CE68 8023E588 10600005 */  beqz      $v1, .L8023E5A0
/* 16CE6C 8023E58C 24110001 */   addiu    $s1, $zero, 1
/* 16CE70 8023E590 3C02800E */  lui       $v0, 0x800e
/* 16CE74 8023E594 8C42C068 */  lw        $v0, -0x3f98($v0)
/* 16CE78 8023E598 10620092 */  beq       $v1, $v0, .L8023E7E4
/* 16CE7C 8023E59C 00000000 */   nop      
.L8023E5A0:
/* 16CE80 8023E5A0 3C02800E */  lui       $v0, 0x800e
/* 16CE84 8023E5A4 8C42C068 */  lw        $v0, -0x3f98($v0)
/* 16CE88 8023E5A8 24430001 */  addiu     $v1, $v0, 1
/* 16CE8C 8023E5AC 2C620025 */  sltiu     $v0, $v1, 0x25
/* 16CE90 8023E5B0 1040008C */  beqz      $v0, .L8023E7E4
/* 16CE94 8023E5B4 00031080 */   sll      $v0, $v1, 2
/* 16CE98 8023E5B8 3C01802A */  lui       $at, 0x802a
/* 16CE9C 8023E5BC 00220821 */  addu      $at, $at, $v0
/* 16CEA0 8023E5C0 8C22C960 */  lw        $v0, -0x36a0($at)
/* 16CEA4 8023E5C4 00400008 */  jr        $v0
/* 16CEA8 8023E5C8 00000000 */   nop      
/* 16CEAC 8023E5CC 0C090486 */  jal       begin_battle
/* 16CEB0 8023E5D0 0000882D */   daddu    $s1, $zero, $zero
/* 16CEB4 8023E5D4 0808F9F9 */  j         .L8023E7E4
/* 16CEB8 8023E5D8 00000000 */   nop      
/* 16CEBC 8023E5DC 0C090809 */  jal       update_heroes_start_turn
/* 16CEC0 8023E5E0 00000000 */   nop      
/* 16CEC4 8023E5E4 0808F9F9 */  j         .L8023E7E4
/* 16CEC8 8023E5E8 00000000 */   nop      
/* 16CECC 8023E5EC 0C090AEC */  jal       update_end_player_turn
/* 16CED0 8023E5F0 00000000 */   nop      
/* 16CED4 8023E5F4 0808F9F9 */  j         .L8023E7E4
/* 16CED8 8023E5F8 00000000 */   nop      
/* 16CEDC 8023E5FC 0C090BF8 */  jal       func_80242FE0
/* 16CEE0 8023E600 00000000 */   nop      
/* 16CEE4 8023E604 0808F9F9 */  j         .L8023E7E4
/* 16CEE8 8023E608 00000000 */   nop      
/* 16CEEC 8023E60C 0C0906C5 */  jal       func_80241B14
/* 16CEF0 8023E610 00000000 */   nop      
/* 16CEF4 8023E614 0808F9F9 */  j         .L8023E7E4
/* 16CEF8 8023E618 00000000 */   nop      
/* 16CEFC 8023E61C 0C090E76 */  jal       func_802439D8
/* 16CF00 8023E620 00000000 */   nop      
/* 16CF04 8023E624 0808F9F9 */  j         .L8023E7E4
/* 16CF08 8023E628 00000000 */   nop      
/* 16CF0C 8023E62C 0C090AB2 */  jal       switch_to_player
/* 16CF10 8023E630 00000000 */   nop      
/* 16CF14 8023E634 0808F9F9 */  j         .L8023E7E4
/* 16CF18 8023E638 00000000 */   nop      
/* 16CF1C 8023E63C 0C090BC0 */  jal       switch_to_partner
/* 16CF20 8023E640 00000000 */   nop      
/* 16CF24 8023E644 0808F9F9 */  j         .L8023E7E4
/* 16CF28 8023E648 00000000 */   nop      
/* 16CF2C 8023E64C 0C090E46 */  jal       switch_order
/* 16CF30 8023E650 00000000 */   nop      
/* 16CF34 8023E654 0808F9F9 */  j         .L8023E7E4
/* 16CF38 8023E658 00000000 */   nop      
/* 16CF3C 8023E65C 0C0A9662 */  jal       update_player_menu
/* 16CF40 8023E660 00000000 */   nop      
/* 16CF44 8023E664 0808F9F9 */  j         .L8023E7E4
/* 16CF48 8023E668 00000000 */   nop      
/* 16CF4C 8023E66C 0C0AA072 */  jal       update_partner_menu
/* 16CF50 8023E670 00000000 */   nop      
/* 16CF54 8023E674 0808F9F9 */  j         .L8023E7E4
/* 16CF58 8023E678 00000000 */   nop      
/* 16CF5C 8023E67C 0C0AA82E */  jal       func_802AA0B8
/* 16CF60 8023E680 00000000 */   nop      
/* 16CF64 8023E684 0808F9F9 */  j         .L8023E7E4
/* 16CF68 8023E688 00000000 */   nop      
/* 16CF6C 8023E68C 0C0AA6D1 */  jal       func_802A9B44
/* 16CF70 8023E690 00000000 */   nop      
/* 16CF74 8023E694 0808F9F9 */  j         .L8023E7E4
/* 16CF78 8023E698 00000000 */   nop      
/* 16CF7C 8023E69C 0C0AA9A2 */  jal       update_targeting_enemies
/* 16CF80 8023E6A0 00000000 */   nop      
/* 16CF84 8023E6A4 0808F9F9 */  j         .L8023E7E4
/* 16CF88 8023E6A8 00000000 */   nop      
/* 16CF8C 8023E6AC 0C0916B4 */  jal       update_player_action
/* 16CF90 8023E6B0 00000000 */   nop      
/* 16CF94 8023E6B4 0808F9F9 */  j         .L8023E7E4
/* 16CF98 8023E6B8 00000000 */   nop      
/* 16CF9C 8023E6BC 0C091EC1 */  jal       func_80247B04
/* 16CFA0 8023E6C0 00000000 */   nop      
/* 16CFA4 8023E6C4 0808F9F9 */  j         .L8023E7E4
/* 16CFA8 8023E6C8 00000000 */   nop      
/* 16CFAC 8023E6CC 0C091914 */  jal       update_player_change_turn
/* 16CFB0 8023E6D0 00000000 */   nop      
/* 16CFB4 8023E6D4 0808F9F9 */  j         .L8023E7E4
/* 16CFB8 8023E6D8 00000000 */   nop      
/* 16CFBC 8023E6DC 0C091C87 */  jal       func_8024721C
/* 16CFC0 8023E6E0 00000000 */   nop      
/* 16CFC4 8023E6E4 0808F9F9 */  j         .L8023E7E4
/* 16CFC8 8023E6E8 00000000 */   nop      
/* 16CFCC 8023E6EC 0C091D5C */  jal       update_enemy_action
/* 16CFD0 8023E6F0 00000000 */   nop      
/* 16CFD4 8023E6F4 0808F9F9 */  j         .L8023E7E4
/* 16CFD8 8023E6F8 00000000 */   nop      
/* 16CFDC 8023E6FC 0C092064 */  jal       func_80248190
/* 16CFE0 8023E700 00000000 */   nop      
/* 16CFE4 8023E704 0808F9F9 */  j         .L8023E7E4
/* 16CFE8 8023E708 00000000 */   nop      
/* 16CFEC 8023E70C 0C091CAB */  jal       update_enemy_change_turn
/* 16CFF0 8023E710 00000000 */   nop      
/* 16CFF4 8023E714 0808F9F9 */  j         .L8023E7E4
/* 16CFF8 8023E718 00000000 */   nop      
/* 16CFFC 8023E71C 0C091ACD */  jal       update_partner_action
/* 16D000 8023E720 00000000 */   nop      
/* 16D004 8023E724 0808F9F9 */  j         .L8023E7E4
/* 16D008 8023E728 00000000 */   nop      
/* 16D00C 8023E72C 0C091002 */  jal       func_80244008
/* 16D010 8023E730 00000000 */   nop      
/* 16D014 8023E734 0808F9F9 */  j         .L8023E7E4
/* 16D018 8023E738 00000000 */   nop      
/* 16D01C 8023E73C 0C091294 */  jal       end_battle
/* 16D020 8023E740 00000000 */   nop      
/* 16D024 8023E744 0808F9F9 */  j         .L8023E7E4
/* 16D028 8023E748 00000000 */   nop      
/* 16D02C 8023E74C 0C0915BE */  jal       update_swap_partner
/* 16D030 8023E750 00000000 */   nop      
/* 16D034 8023E754 0808F9F9 */  j         .L8023E7E4
/* 16D038 8023E758 00000000 */   nop      
/* 16D03C 8023E75C 0C0913C0 */  jal       update_run_away
/* 16D040 8023E760 00000000 */   nop      
/* 16D044 8023E764 0808F9F9 */  j         .L8023E7E4
/* 16D048 8023E768 00000000 */   nop      
/* 16D04C 8023E76C 0C09138E */  jal       func_80244E38
/* 16D050 8023E770 00000000 */   nop      
/* 16D054 8023E774 0808F9F9 */  j         .L8023E7E4
/* 16D058 8023E778 00000000 */   nop      
/* 16D05C 8023E77C 0C091510 */  jal       func_80245440
/* 16D060 8023E780 00000000 */   nop      
/* 16D064 8023E784 0808F9F9 */  j         .L8023E7E4
/* 16D068 8023E788 00000000 */   nop      
/* 16D06C 8023E78C 0C090FF7 */  jal       func_80243FDC
/* 16D070 8023E790 00000000 */   nop      
/* 16D074 8023E794 0808F9F9 */  j         .L8023E7E4
/* 16D078 8023E798 00000000 */   nop      
/* 16D07C 8023E79C 0C0911C4 */  jal       func_80244710
/* 16D080 8023E7A0 00000000 */   nop      
/* 16D084 8023E7A4 0808F9F9 */  j         .L8023E7E4
/* 16D088 8023E7A8 00000000 */   nop      
/* 16D08C 8023E7AC 0C092198 */  jal       func_80248660
/* 16D090 8023E7B0 00000000 */   nop      
/* 16D094 8023E7B4 0808F9F9 */  j         .L8023E7E4
/* 16D098 8023E7B8 00000000 */   nop      
/* 16D09C 8023E7BC 0C0AACCC */  jal       func_802AB330
/* 16D0A0 8023E7C0 00000000 */   nop      
/* 16D0A4 8023E7C4 0808F9F9 */  j         .L8023E7E4
/* 16D0A8 8023E7C8 00000000 */   nop      
/* 16D0AC 8023E7CC 0C097864 */  jal       func_8025E190
/* 16D0B0 8023E7D0 00000000 */   nop      
/* 16D0B4 8023E7D4 0808F9F9 */  j         .L8023E7E4
/* 16D0B8 8023E7D8 00000000 */   nop      
/* 16D0BC 8023E7DC 0C0922C2 */  jal       func_80248B08
/* 16D0C0 8023E7E0 0000882D */   daddu    $s1, $zero, $zero
.L8023E7E4:
/* 16D0C4 8023E7E4 96020090 */  lhu       $v0, 0x90($s0)
/* 16D0C8 8023E7E8 24030028 */  addiu     $v1, $zero, 0x28
/* 16D0CC 8023E7EC 24420001 */  addiu     $v0, $v0, 1
/* 16D0D0 8023E7F0 A6020090 */  sh        $v0, 0x90($s0)
/* 16D0D4 8023E7F4 00021400 */  sll       $v0, $v0, 0x10
/* 16D0D8 8023E7F8 00021403 */  sra       $v0, $v0, 0x10
/* 16D0DC 8023E7FC 14430003 */  bne       $v0, $v1, .L8023E80C
/* 16D0E0 8023E800 00000000 */   nop      
/* 16D0E4 8023E804 0C093DF2 */  jal       func_8024F7C8
/* 16D0E8 8023E808 00000000 */   nop      
.L8023E80C:
/* 16D0EC 8023E80C 0C0999A1 */  jal       func_80266684
/* 16D0F0 8023E810 00000000 */   nop      
/* 16D0F4 8023E814 0C099A5E */  jal       func_80266978
/* 16D0F8 8023E818 00000000 */   nop      
/* 16D0FC 8023E81C 0C099AC5 */  jal       func_80266B14
/* 16D100 8023E820 00000000 */   nop      
/* 16D104 8023E824 0C093B92 */  jal       func_8024EE48
/* 16D108 8023E828 00000000 */   nop      
/* 16D10C 8023E82C 0C08F901 */  jal       update_actor_shadows
/* 16D110 8023E830 00000000 */   nop      
/* 16D114 8023E834 82030432 */  lb        $v1, 0x432($s0)
/* 16D118 8023E838 2402FFFE */  addiu     $v0, $zero, -2
/* 16D11C 8023E83C 10620089 */  beq       $v1, $v0, .L8023EA64
/* 16D120 8023E840 27A50018 */   addiu    $a1, $sp, 0x18
/* 16D124 8023E844 24040001 */  addiu     $a0, $zero, 1
/* 16D128 8023E848 0C04DF70 */  jal       func_80137DC0
/* 16D12C 8023E84C 27A6001C */   addiu    $a2, $sp, 0x1c
/* 16D130 8023E850 82020432 */  lb        $v0, 0x432($s0)
/* 16D134 8023E854 1840002C */  blez      $v0, .L8023E908
/* 16D138 8023E858 24040001 */   addiu    $a0, $zero, 1
/* 16D13C 8023E85C 0000282D */  daddu     $a1, $zero, $zero
/* 16D140 8023E860 00A0302D */  daddu     $a2, $a1, $zero
/* 16D144 8023E864 0C04DF84 */  jal       func_80137E10
/* 16D148 8023E868 00A0382D */   daddu    $a3, $a1, $zero
/* 16D14C 8023E86C 16400003 */  bnez      $s2, .L8023E87C
/* 16D150 8023E870 00000000 */   nop      
/* 16D154 8023E874 0808FA56 */  j         .L8023E958
/* 16D158 8023E878 3C054357 */   lui      $a1, 0x4357
.L8023E87C:
/* 16D15C 8023E87C 3C028011 */  lui       $v0, 0x8011
/* 16D160 8023E880 2442F290 */  addiu     $v0, $v0, -0xd70
/* 16D164 8023E884 80430012 */  lb        $v1, 0x12($v0)
/* 16D168 8023E888 24020006 */  addiu     $v0, $zero, 6
/* 16D16C 8023E88C 1462000F */  bne       $v1, $v0, .L8023E8CC
/* 16D170 8023E890 00000000 */   nop      
/* 16D174 8023E894 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 16D178 8023E898 3C014120 */  lui       $at, 0x4120
/* 16D17C 8023E89C 44811000 */  mtc1      $at, $f2
/* 16D180 8023E8A0 00000000 */  nop       
/* 16D184 8023E8A4 46020001 */  sub.s     $f0, $f0, $f2
/* 16D188 8023E8A8 44801000 */  mtc1      $zero, $f2
/* 16D18C 8023E8AC 00000000 */  nop       
/* 16D190 8023E8B0 4602003C */  c.lt.s    $f0, $f2
/* 16D194 8023E8B4 00000000 */  nop       
/* 16D198 8023E8B8 45000002 */  bc1f      .L8023E8C4
/* 16D19C 8023E8BC E7A0001C */   swc1     $f0, 0x1c($sp)
/* 16D1A0 8023E8C0 E7A2001C */  swc1      $f2, 0x1c($sp)
.L8023E8C4:
/* 16D1A4 8023E8C4 0808FA56 */  j         .L8023E958
/* 16D1A8 8023E8C8 8FA5001C */   lw       $a1, 0x1c($sp)
.L8023E8CC:
/* 16D1AC 8023E8CC C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 16D1B0 8023E8D0 3C014120 */  lui       $at, 0x4120
/* 16D1B4 8023E8D4 44811000 */  mtc1      $at, $f2
/* 16D1B8 8023E8D8 00000000 */  nop       
/* 16D1BC 8023E8DC 46020000 */  add.s     $f0, $f0, $f2
/* 16D1C0 8023E8E0 3C014357 */  lui       $at, 0x4357
/* 16D1C4 8023E8E4 44811000 */  mtc1      $at, $f2
/* 16D1C8 8023E8E8 00000000 */  nop       
/* 16D1CC 8023E8EC 4600103C */  c.lt.s    $f2, $f0
/* 16D1D0 8023E8F0 00000000 */  nop       
/* 16D1D4 8023E8F4 45000002 */  bc1f      .L8023E900
/* 16D1D8 8023E8F8 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 16D1DC 8023E8FC E7A2001C */  swc1      $f2, 0x1c($sp)
.L8023E900:
/* 16D1E0 8023E900 0808FA56 */  j         .L8023E958
/* 16D1E4 8023E904 8FA5001C */   lw       $a1, 0x1c($sp)
.L8023E908:
/* 16D1E8 8023E908 04410015 */  bgez      $v0, .L8023E960
/* 16D1EC 8023E90C 00000000 */   nop      
/* 16D1F0 8023E910 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* 16D1F4 8023E914 3C014120 */  lui       $at, 0x4120
/* 16D1F8 8023E918 44810000 */  mtc1      $at, $f0
/* 16D1FC 8023E91C 00000000 */  nop       
/* 16D200 8023E920 46001081 */  sub.s     $f2, $f2, $f0
/* 16D204 8023E924 44800000 */  mtc1      $zero, $f0
/* 16D208 8023E928 00000000 */  nop       
/* 16D20C 8023E92C 4600103C */  c.lt.s    $f2, $f0
/* 16D210 8023E930 00000000 */  nop       
/* 16D214 8023E934 45000007 */  bc1f      .L8023E954
/* 16D218 8023E938 E7A2001C */   swc1     $f2, 0x1c($sp)
/* 16D21C 8023E93C 3C05BF80 */  lui       $a1, 0xbf80
/* 16D220 8023E940 240400FF */  addiu     $a0, $zero, 0xff
/* 16D224 8023E944 0C04DF69 */  jal       func_80137DA4
/* 16D228 8023E948 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 16D22C 8023E94C 0808FA58 */  j         .L8023E960
/* 16D230 8023E950 A2000432 */   sb       $zero, 0x432($s0)
.L8023E954:
/* 16D234 8023E954 44051000 */  mfc1      $a1, $f2
.L8023E958:
/* 16D238 8023E958 0C04DF69 */  jal       func_80137DA4
/* 16D23C 8023E95C 0000202D */   daddu    $a0, $zero, $zero
.L8023E960:
/* 16D240 8023E960 16200005 */  bnez      $s1, .L8023E978
/* 16D244 8023E964 2402FFFF */   addiu    $v0, $zero, -1
/* 16D248 8023E968 3C038028 */  lui       $v1, 0x8028
/* 16D24C 8023E96C 846309F6 */  lh        $v1, 0x9f6($v1)
/* 16D250 8023E970 1062003C */  beq       $v1, $v0, .L8023EA64
/* 16D254 8023E974 00000000 */   nop      
.L8023E978:
/* 16D258 8023E978 3C108028 */  lui       $s0, 0x8028
/* 16D25C 8023E97C 261009F6 */  addiu     $s0, $s0, 0x9f6
/* 16D260 8023E980 2402FFFF */  addiu     $v0, $zero, -1
/* 16D264 8023E984 86040000 */  lh        $a0, ($s0)
/* 16D268 8023E988 96030000 */  lhu       $v1, ($s0)
/* 16D26C 8023E98C 14820014 */  bne       $a0, $v0, .L8023E9E0
/* 16D270 8023E990 240500FF */   addiu    $a1, $zero, 0xff
/* 16D274 8023E994 3C028007 */  lui       $v0, 0x8007
/* 16D278 8023E998 8C42419C */  lw        $v0, 0x419c($v0)
/* 16D27C 8023E99C 80430071 */  lb        $v1, 0x71($v0)
/* 16D280 8023E9A0 24020002 */  addiu     $v0, $zero, 2
/* 16D284 8023E9A4 1462002F */  bne       $v1, $v0, .L8023EA64
/* 16D288 8023E9A8 27A50020 */   addiu    $a1, $sp, 0x20
/* 16D28C 8023E9AC 0000202D */  daddu     $a0, $zero, $zero
/* 16D290 8023E9B0 0C04DF70 */  jal       func_80137DC0
/* 16D294 8023E9B4 27A60024 */   addiu    $a2, $sp, 0x24
/* 16D298 8023E9B8 93A30020 */  lbu       $v1, 0x20($sp)
/* 16D29C 8023E9BC 240200FF */  addiu     $v0, $zero, 0xff
/* 16D2A0 8023E9C0 14620028 */  bne       $v1, $v0, .L8023EA64
/* 16D2A4 8023E9C4 00000000 */   nop      
/* 16D2A8 8023E9C8 A6000000 */  sh        $zero, ($s0)
/* 16D2AC 8023E9CC 0000202D */  daddu     $a0, $zero, $zero
/* 16D2B0 8023E9D0 0C04DF62 */  jal       func_80137D88
/* 16D2B4 8023E9D4 0000282D */   daddu    $a1, $zero, $zero
/* 16D2B8 8023E9D8 0808FA99 */  j         .L8023EA64
/* 16D2BC 8023E9DC 00000000 */   nop      
.L8023E9E0:
/* 16D2C0 8023E9E0 1485000A */  bne       $a0, $a1, .L8023EA0C
/* 16D2C4 8023E9E4 2462000A */   addiu    $v0, $v1, 0xa
/* 16D2C8 8023E9E8 3C03800E */  lui       $v1, 0x800e
/* 16D2CC 8023E9EC 8C63C068 */  lw        $v1, -0x3f98($v1)
/* 16D2D0 8023E9F0 24020023 */  addiu     $v0, $zero, 0x23
/* 16D2D4 8023E9F4 1062001B */  beq       $v1, $v0, .L8023EA64
/* 16D2D8 8023E9F8 00000000 */   nop      
/* 16D2DC 8023E9FC 0C090464 */  jal       func_80241190
/* 16D2E0 8023EA00 0040202D */   daddu    $a0, $v0, $zero
/* 16D2E4 8023EA04 0808FA99 */  j         .L8023EA64
/* 16D2E8 8023EA08 00000000 */   nop      
.L8023EA0C:
/* 16D2EC 8023EA0C A6020000 */  sh        $v0, ($s0)
/* 16D2F0 8023EA10 00021400 */  sll       $v0, $v0, 0x10
/* 16D2F4 8023EA14 00021403 */  sra       $v0, $v0, 0x10
/* 16D2F8 8023EA18 28420100 */  slti      $v0, $v0, 0x100
/* 16D2FC 8023EA1C 50400001 */  beql      $v0, $zero, .L8023EA24
/* 16D300 8023EA20 A6050000 */   sh       $a1, ($s0)
.L8023EA24:
/* 16D304 8023EA24 86020000 */  lh        $v0, ($s0)
/* 16D308 8023EA28 44822000 */  mtc1      $v0, $f4
/* 16D30C 8023EA2C 00000000 */  nop       
/* 16D310 8023EA30 46802120 */  cvt.s.w   $f4, $f4
/* 16D314 8023EA34 44052000 */  mfc1      $a1, $f4
/* 16D318 8023EA38 0C04DF62 */  jal       func_80137D88
/* 16D31C 8023EA3C 0000202D */   daddu    $a0, $zero, $zero
/* 16D320 8023EA40 0000202D */  daddu     $a0, $zero, $zero
/* 16D324 8023EA44 240500D0 */  addiu     $a1, $zero, 0xd0
/* 16D328 8023EA48 00A0302D */  daddu     $a2, $a1, $zero
/* 16D32C 8023EA4C 0C04DF84 */  jal       func_80137E10
/* 16D330 8023EA50 00A0382D */   daddu    $a3, $a1, $zero
/* 16D334 8023EA54 0C00CDF4 */  jal       intro_logos_set_fade_alpha
/* 16D338 8023EA58 240400FF */   addiu    $a0, $zero, 0xff
/* 16D33C 8023EA5C 0C00CDF8 */  jal       intro_logos_set_fade_color
/* 16D340 8023EA60 240400E0 */   addiu    $a0, $zero, 0xe0
.L8023EA64:
/* 16D344 8023EA64 8FBF0034 */  lw        $ra, 0x34($sp)
/* 16D348 8023EA68 8FB20030 */  lw        $s2, 0x30($sp)
/* 16D34C 8023EA6C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 16D350 8023EA70 8FB00028 */  lw        $s0, 0x28($sp)
/* 16D354 8023EA74 03E00008 */  jr        $ra
/* 16D358 8023EA78 27BD0038 */   addiu    $sp, $sp, 0x38
