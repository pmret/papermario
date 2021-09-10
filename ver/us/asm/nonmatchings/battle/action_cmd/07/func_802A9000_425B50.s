.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_425B50
/* 425B50 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 425B54 802A9004 AFB20018 */  sw        $s2, 0x18($sp)
/* 425B58 802A9008 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 425B5C 802A900C 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 425B60 802A9010 AFBF001C */  sw        $ra, 0x1c($sp)
/* 425B64 802A9014 AFB10014 */  sw        $s1, 0x14($sp)
/* 425B68 802A9018 AFB00010 */  sw        $s0, 0x10($sp)
/* 425B6C 802A901C 8C83000C */  lw        $v1, 0xc($a0)
/* 425B70 802A9020 24020005 */  addiu     $v0, $zero, 5
/* 425B74 802A9024 A2420082 */  sb        $v0, 0x82($s2)
/* 425B78 802A9028 3C028029 */  lui       $v0, %hi(D_80294280)
/* 425B7C 802A902C 24424280 */  addiu     $v0, $v0, %lo(D_80294280)
/* 425B80 802A9030 3C10802A */  lui       $s0, %hi(gActionCommandStatus)
/* 425B84 802A9034 2610FBE0 */  addiu     $s0, $s0, %lo(gActionCommandStatus)
/* 425B88 802A9038 AE420434 */  sw        $v0, 0x434($s2)
/* 425B8C 802A903C 24020007 */  addiu     $v0, $zero, 7
/* 425B90 802A9040 A200005E */  sb        $zero, 0x5e($s0)
/* 425B94 802A9044 A602004A */  sh        $v0, 0x4a($s0)
/* 425B98 802A9048 A600004C */  sh        $zero, 0x4c($s0)
/* 425B9C 802A904C A2000060 */  sb        $zero, 0x60($s0)
/* 425BA0 802A9050 0C0B1EAF */  jal       evt_get_variable
/* 425BA4 802A9054 8C650000 */   lw       $a1, ($v1)
/* 425BA8 802A9058 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 425BAC 802A905C 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 425BB0 802A9060 A6020044 */  sh        $v0, 0x44($s0)
/* 425BB4 802A9064 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 425BB8 802A9068 A6020056 */  sh        $v0, 0x56($s0)
/* 425BBC 802A906C 24020050 */  addiu     $v0, $zero, 0x50
/* 425BC0 802A9070 A6000048 */  sh        $zero, 0x48($s0)
/* 425BC4 802A9074 3C01802B */  lui       $at, %hi(D_802A9620)
/* 425BC8 802A9078 AC209620 */  sw        $zero, %lo(D_802A9620)($at)
/* 425BCC 802A907C 0C050529 */  jal       create_hud_element
/* 425BD0 802A9080 A6020058 */   sh       $v0, 0x58($s0)
/* 425BD4 802A9084 0040882D */  daddu     $s1, $v0, $zero
/* 425BD8 802A9088 0220202D */  daddu     $a0, $s1, $zero
/* 425BDC 802A908C 24050082 */  addiu     $a1, $zero, 0x82
/* 425BE0 802A9090 0C051280 */  jal       set_hud_element_flags
/* 425BE4 802A9094 AE110004 */   sw       $s1, 4($s0)
/* 425BE8 802A9098 86050056 */  lh        $a1, 0x56($s0)
/* 425BEC 802A909C 86060058 */  lh        $a2, 0x58($s0)
/* 425BF0 802A90A0 0C051261 */  jal       set_hud_element_render_pos
/* 425BF4 802A90A4 0220202D */   daddu    $a0, $s1, $zero
/* 425BF8 802A90A8 0220202D */  daddu     $a0, $s1, $zero
/* 425BFC 802A90AC 0C051277 */  jal       set_hud_element_render_depth
/* 425C00 802A90B0 0000282D */   daddu    $a1, $zero, $zero
/* 425C04 802A90B4 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 425C08 802A90B8 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 425C0C 802A90BC 0C050529 */  jal       create_hud_element
/* 425C10 802A90C0 00000000 */   nop
/* 425C14 802A90C4 0040882D */  daddu     $s1, $v0, $zero
/* 425C18 802A90C8 86050056 */  lh        $a1, 0x56($s0)
/* 425C1C 802A90CC 86060058 */  lh        $a2, 0x58($s0)
/* 425C20 802A90D0 0220202D */  daddu     $a0, $s1, $zero
/* 425C24 802A90D4 AE110008 */  sw        $s1, 8($s0)
/* 425C28 802A90D8 0C051261 */  jal       set_hud_element_render_pos
/* 425C2C 802A90DC 24C6001C */   addiu    $a2, $a2, 0x1c
/* 425C30 802A90E0 0220202D */  daddu     $a0, $s1, $zero
/* 425C34 802A90E4 0C051277 */  jal       set_hud_element_render_depth
/* 425C38 802A90E8 0000282D */   daddu    $a1, $zero, $zero
/* 425C3C 802A90EC 0220202D */  daddu     $a0, $s1, $zero
/* 425C40 802A90F0 0C051280 */  jal       set_hud_element_flags
/* 425C44 802A90F4 24050082 */   addiu    $a1, $zero, 0x82
/* 425C48 802A90F8 3C048011 */  lui       $a0, %hi(D_80109244)
/* 425C4C 802A90FC 24849244 */  addiu     $a0, $a0, %lo(D_80109244)
/* 425C50 802A9100 0C050529 */  jal       create_hud_element
/* 425C54 802A9104 00000000 */   nop
/* 425C58 802A9108 0040882D */  daddu     $s1, $v0, $zero
/* 425C5C 802A910C 86050056 */  lh        $a1, 0x56($s0)
/* 425C60 802A9110 86060058 */  lh        $a2, 0x58($s0)
/* 425C64 802A9114 0220202D */  daddu     $a0, $s1, $zero
/* 425C68 802A9118 AE11000C */  sw        $s1, 0xc($s0)
/* 425C6C 802A911C 0C051261 */  jal       set_hud_element_render_pos
/* 425C70 802A9120 24C6001C */   addiu    $a2, $a2, 0x1c
/* 425C74 802A9124 0220202D */  daddu     $a0, $s1, $zero
/* 425C78 802A9128 0C051277 */  jal       set_hud_element_render_depth
/* 425C7C 802A912C 0000282D */   daddu    $a1, $zero, $zero
/* 425C80 802A9130 0220202D */  daddu     $a0, $s1, $zero
/* 425C84 802A9134 0C051280 */  jal       set_hud_element_flags
/* 425C88 802A9138 24050082 */   addiu    $a1, $zero, 0x82
/* 425C8C 802A913C 3C04FFFF */  lui       $a0, 0xffff
/* 425C90 802A9140 8E430000 */  lw        $v1, ($s2)
/* 425C94 802A9144 34847FFF */  ori       $a0, $a0, 0x7fff
/* 425C98 802A9148 00641824 */  and       $v1, $v1, $a0
/* 425C9C 802A914C AE430000 */  sw        $v1, ($s2)
/* 425CA0 802A9150 8FBF001C */  lw        $ra, 0x1c($sp)
/* 425CA4 802A9154 8FB20018 */  lw        $s2, 0x18($sp)
/* 425CA8 802A9158 8FB10014 */  lw        $s1, 0x14($sp)
/* 425CAC 802A915C 8FB00010 */  lw        $s0, 0x10($sp)
/* 425CB0 802A9160 24020002 */  addiu     $v0, $zero, 2
/* 425CB4 802A9164 03E00008 */  jr        $ra
/* 425CB8 802A9168 27BD0020 */   addiu    $sp, $sp, 0x20
