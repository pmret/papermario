.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_42C6F0
/* 42C6F0 802A9000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42C6F4 802A9004 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 42C6F8 802A9008 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 42C6FC 802A900C 24020005 */  addiu     $v0, $zero, 5
/* 42C700 802A9010 AFBF0020 */  sw        $ra, 0x20($sp)
/* 42C704 802A9014 AFB3001C */  sw        $s3, 0x1c($sp)
/* 42C708 802A9018 AFB20018 */  sw        $s2, 0x18($sp)
/* 42C70C 802A901C AFB10014 */  sw        $s1, 0x14($sp)
/* 42C710 802A9020 AFB00010 */  sw        $s0, 0x10($sp)
/* 42C714 802A9024 A0620082 */  sb        $v0, 0x82($v1)
/* 42C718 802A9028 3C028029 */  lui       $v0, %hi(D_802944A0)
/* 42C71C 802A902C 244244A0 */  addiu     $v0, $v0, %lo(D_802944A0)
/* 42C720 802A9030 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42C724 802A9034 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42C728 802A9038 AC620434 */  sw        $v0, 0x434($v1)
/* 42C72C 802A903C 80620083 */  lb        $v0, 0x83($v1)
/* 42C730 802A9040 14400003 */  bnez      $v0, .L802A9050
/* 42C734 802A9044 0060802D */   daddu    $s0, $v1, $zero
/* 42C738 802A9048 080AA446 */  j         .L802A9118
/* 42C73C 802A904C A0600081 */   sb       $zero, 0x81($v1)
.L802A9050:
/* 42C740 802A9050 0C09A216 */  jal       func_80268858
/* 42C744 802A9054 24130001 */   addiu    $s3, $zero, 1
/* 42C748 802A9058 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 42C74C 802A905C 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 42C750 802A9060 24020017 */  addiu     $v0, $zero, 0x17
/* 42C754 802A9064 A622004A */  sh        $v0, 0x4a($s1)
/* 42C758 802A9068 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 42C75C 802A906C A620004C */  sh        $zero, 0x4c($s1)
/* 42C760 802A9070 A2200060 */  sb        $zero, 0x60($s1)
/* 42C764 802A9074 A6200044 */  sh        $zero, 0x44($s1)
/* 42C768 802A9078 A6200048 */  sh        $zero, 0x48($s1)
/* 42C76C 802A907C A2000084 */  sb        $zero, 0x84($s0)
/* 42C770 802A9080 A6220056 */  sh        $v0, 0x56($s1)
/* 42C774 802A9084 24020050 */  addiu     $v0, $zero, 0x50
/* 42C778 802A9088 0C050529 */  jal       create_hud_element
/* 42C77C 802A908C A6220058 */   sh       $v0, 0x58($s1)
/* 42C780 802A9090 0040802D */  daddu     $s0, $v0, $zero
/* 42C784 802A9094 0200202D */  daddu     $a0, $s0, $zero
/* 42C788 802A9098 86250056 */  lh        $a1, 0x56($s1)
/* 42C78C 802A909C 86260058 */  lh        $a2, 0x58($s1)
/* 42C790 802A90A0 26320004 */  addiu     $s2, $s1, 4
/* 42C794 802A90A4 AE300004 */  sw        $s0, 4($s1)
/* 42C798 802A90A8 0C051261 */  jal       set_hud_element_render_pos
/* 42C79C 802A90AC 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42C7A0 802A90B0 0200202D */  daddu     $a0, $s0, $zero
/* 42C7A4 802A90B4 0C051277 */  jal       set_hud_element_render_depth
/* 42C7A8 802A90B8 0000282D */   daddu    $a1, $zero, $zero
/* 42C7AC 802A90BC 0200202D */  daddu     $a0, $s0, $zero
/* 42C7B0 802A90C0 0C051280 */  jal       set_hud_element_flags
/* 42C7B4 802A90C4 24050082 */   addiu    $a1, $zero, 0x82
.L802A90C8:
/* 42C7B8 802A90C8 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 42C7BC 802A90CC 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 42C7C0 802A90D0 0C050529 */  jal       create_hud_element
/* 42C7C4 802A90D4 26730001 */   addiu    $s3, $s3, 1
/* 42C7C8 802A90D8 0040802D */  daddu     $s0, $v0, $zero
/* 42C7CC 802A90DC 0200202D */  daddu     $a0, $s0, $zero
/* 42C7D0 802A90E0 AE500004 */  sw        $s0, 4($s2)
/* 42C7D4 802A90E4 86250056 */  lh        $a1, 0x56($s1)
/* 42C7D8 802A90E8 86260058 */  lh        $a2, 0x58($s1)
/* 42C7DC 802A90EC 0C051261 */  jal       set_hud_element_render_pos
/* 42C7E0 802A90F0 26520004 */   addiu    $s2, $s2, 4
/* 42C7E4 802A90F4 0200202D */  daddu     $a0, $s0, $zero
/* 42C7E8 802A90F8 0C051277 */  jal       set_hud_element_render_depth
/* 42C7EC 802A90FC 0000282D */   daddu    $a1, $zero, $zero
/* 42C7F0 802A9100 0200202D */  daddu     $a0, $s0, $zero
/* 42C7F4 802A9104 0C051280 */  jal       set_hud_element_flags
/* 42C7F8 802A9108 24050082 */   addiu    $a1, $zero, 0x82
/* 42C7FC 802A910C 2A62000F */  slti      $v0, $s3, 0xf
/* 42C800 802A9110 1440FFED */  bnez      $v0, .L802A90C8
/* 42C804 802A9114 00000000 */   nop
.L802A9118:
/* 42C808 802A9118 24020002 */  addiu     $v0, $zero, 2
/* 42C80C 802A911C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 42C810 802A9120 8FB3001C */  lw        $s3, 0x1c($sp)
/* 42C814 802A9124 8FB20018 */  lw        $s2, 0x18($sp)
/* 42C818 802A9128 8FB10014 */  lw        $s1, 0x14($sp)
/* 42C81C 802A912C 8FB00010 */  lw        $s0, 0x10($sp)
/* 42C820 802A9130 03E00008 */  jr        $ra
/* 42C824 802A9134 27BD0028 */   addiu    $sp, $sp, 0x28
