.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401FC_AF7B4C
/* AF7B4C 802401FC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* AF7B50 80240200 3C048024 */  lui       $a0, %hi(func_80240068_AF79B8)
/* AF7B54 80240204 24840068 */  addiu     $a0, $a0, %lo(func_80240068_AF79B8)
/* AF7B58 80240208 AFBF0024 */  sw        $ra, 0x24($sp)
/* AF7B5C 8024020C AFB20020 */  sw        $s2, 0x20($sp)
/* AF7B60 80240210 AFB1001C */  sw        $s1, 0x1c($sp)
/* AF7B64 80240214 AFB00018 */  sw        $s0, 0x18($sp)
/* AF7B68 80240218 3C018024 */  lui       $at, %hi(D_80240E88_AF87D8)
/* AF7B6C 8024021C AC200E88 */  sw        $zero, %lo(D_80240E88_AF87D8)($at)
/* AF7B70 80240220 3C018024 */  lui       $at, %hi(D_80240E8C_AF87DC)
/* AF7B74 80240224 AC200E8C */  sw        $zero, %lo(D_80240E8C_AF87DC)($at)
/* AF7B78 80240228 3C018024 */  lui       $at, %hi(D_80240E90_AF87E0)
/* AF7B7C 8024022C AC200E90 */  sw        $zero, %lo(D_80240E90_AF87E0)($at)
/* AF7B80 80240230 0C048C8F */  jal       bind_dynamic_entity_7
/* AF7B84 80240234 0000282D */   daddu    $a1, $zero, $zero
/* AF7B88 80240238 0C048D8F */  jal       get_dynamic_entity
/* AF7B8C 8024023C 0040202D */   daddu    $a0, $v0, $zero
/* AF7B90 80240240 3C048024 */  lui       $a0, %hi(D_80240EF0_AF8840)
/* AF7B94 80240244 24840EF0 */  addiu     $a0, $a0, %lo(D_80240EF0_AF8840)
/* AF7B98 80240248 0C051FCC */  jal       setup_pause_menu_tab
/* AF7B9C 8024024C 24050002 */   addiu    $a1, $zero, 2
/* AF7BA0 80240250 0000802D */  daddu     $s0, $zero, $zero
/* AF7BA4 80240254 24120003 */  addiu     $s2, $zero, 3
/* AF7BA8 80240258 3C118024 */  lui       $s1, %hi(D_80240E10_AF8760)
/* AF7BAC 8024025C 26310E10 */  addiu     $s1, $s1, %lo(D_80240E10_AF8760)
.L80240260:
/* AF7BB0 80240260 3C048024 */  lui       $a0, %hi(D_80240E94_AF87E4)
/* AF7BB4 80240264 24840E94 */  addiu     $a0, $a0, %lo(D_80240E94_AF87E4)
/* AF7BB8 80240268 24050080 */  addiu     $a1, $zero, 0x80
/* AF7BBC 8024026C AFA00010 */  sw        $zero, 0x10($sp)
/* AF7BC0 80240270 AFB20014 */  sw        $s2, 0x14($sp)
/* AF7BC4 80240274 8E260004 */  lw        $a2, 4($s1)
/* AF7BC8 80240278 2631000C */  addiu     $s1, $s1, 0xc
/* AF7BCC 8024027C 0200382D */  daddu     $a3, $s0, $zero
/* AF7BD0 80240280 0C0B10AA */  jal       bind_trigger_1
/* AF7BD4 80240284 26100001 */   addiu    $s0, $s0, 1
/* AF7BD8 80240288 2A02000A */  slti      $v0, $s0, 0xa
/* AF7BDC 8024028C 1440FFF4 */  bnez      $v0, .L80240260
/* AF7BE0 80240290 24020002 */   addiu    $v0, $zero, 2
/* AF7BE4 80240294 8FBF0024 */  lw        $ra, 0x24($sp)
/* AF7BE8 80240298 8FB20020 */  lw        $s2, 0x20($sp)
/* AF7BEC 8024029C 8FB1001C */  lw        $s1, 0x1c($sp)
/* AF7BF0 802402A0 8FB00018 */  lw        $s0, 0x18($sp)
/* AF7BF4 802402A4 03E00008 */  jr        $ra
/* AF7BF8 802402A8 27BD0028 */   addiu    $sp, $sp, 0x28
/* AF7BFC 802402AC 00000000 */  nop
