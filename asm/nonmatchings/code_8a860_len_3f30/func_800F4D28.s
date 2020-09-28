.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800F4D28
/* 8E1D8 800F4D28 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 8E1DC 800F4D2C AFB40030 */  sw        $s4, 0x30($sp)
/* 8E1E0 800F4D30 00A0A02D */  daddu     $s4, $a1, $zero
/* 8E1E4 800F4D34 AFB00020 */  sw        $s0, 0x20($sp)
/* 8E1E8 800F4D38 3C108011 */  lui       $s0, 0x8011
/* 8E1EC 800F4D3C 8E10D660 */  lw        $s0, -0x29a0($s0)
/* 8E1F0 800F4D40 3C058011 */  lui       $a1, 0x8011
/* 8E1F4 800F4D44 8CA5D650 */  lw        $a1, -0x29b0($a1)
/* 8E1F8 800F4D48 AFB3002C */  sw        $s3, 0x2c($sp)
/* 8E1FC 800F4D4C 00C0982D */  daddu     $s3, $a2, $zero
/* 8E200 800F4D50 AFB10024 */  sw        $s1, 0x24($sp)
/* 8E204 800F4D54 2691000E */  addiu     $s1, $s4, 0xe
/* 8E208 800F4D58 AFB20028 */  sw        $s2, 0x28($sp)
/* 8E20C 800F4D5C 26720009 */  addiu     $s2, $s3, 9
/* 8E210 800F4D60 AFBF0034 */  sw        $ra, 0x34($sp)
/* 8E214 800F4D64 0C0513AC */  jal       icon_set_opacity
/* 8E218 800F4D68 0200202D */   daddu    $a0, $s0, $zero
/* 8E21C 800F4D6C 3C028011 */  lui       $v0, 0x8011
/* 8E220 800F4D70 8C42D69C */  lw        $v0, -0x2964($v0)
/* 8E224 800F4D74 8C430318 */  lw        $v1, 0x318($v0)
/* 8E228 800F4D78 24020003 */  addiu     $v0, $zero, 3
/* 8E22C 800F4D7C 14620004 */  bne       $v1, $v0, .L800F4D90
/* 8E230 800F4D80 0200202D */   daddu    $a0, $s0, $zero
/* 8E234 800F4D84 0220282D */  daddu     $a1, $s1, $zero
/* 8E238 800F4D88 0803D366 */  j         .L800F4D98
/* 8E23C 800F4D8C 0240302D */   daddu    $a2, $s2, $zero
.L800F4D90:
/* 8E240 800F4D90 0220282D */  daddu     $a1, $s1, $zero
/* 8E244 800F4D94 2666000A */  addiu     $a2, $s3, 0xa
.L800F4D98:
/* 8E248 800F4D98 0C051261 */  jal       set_icon_render_pos
/* 8E24C 800F4D9C 00000000 */   nop      
/* 8E250 800F4DA0 0C0511EA */  jal       draw_icon_0
/* 8E254 800F4DA4 0200202D */   daddu    $a0, $s0, $zero
/* 8E258 800F4DA8 2685001A */  addiu     $a1, $s4, 0x1a
/* 8E25C 800F4DAC 3C108011 */  lui       $s0, 0x8011
/* 8E260 800F4DB0 8E10D664 */  lw        $s0, -0x299c($s0)
/* 8E264 800F4DB4 2666000B */  addiu     $a2, $s3, 0xb
/* 8E268 800F4DB8 0C051261 */  jal       set_icon_render_pos
/* 8E26C 800F4DBC 0200202D */   daddu    $a0, $s0, $zero
/* 8E270 800F4DC0 3C118011 */  lui       $s1, 0x8011
/* 8E274 800F4DC4 2631D650 */  addiu     $s1, $s1, -0x29b0
/* 8E278 800F4DC8 8E250000 */  lw        $a1, ($s1)
/* 8E27C 800F4DCC 0C0513AC */  jal       icon_set_opacity
/* 8E280 800F4DD0 0200202D */   daddu    $a0, $s0, $zero
/* 8E284 800F4DD4 0C0511EA */  jal       draw_icon_0
/* 8E288 800F4DD8 0200202D */   daddu    $a0, $s0, $zero
/* 8E28C 800F4DDC 3C028011 */  lui       $v0, 0x8011
/* 8E290 800F4DE0 8C42D69C */  lw        $v0, -0x2964($v0)
/* 8E294 800F4DE4 8C430318 */  lw        $v1, 0x318($v0)
/* 8E298 800F4DE8 24020003 */  addiu     $v0, $zero, 3
/* 8E29C 800F4DEC 1462000C */  bne       $v1, $v0, .L800F4E20
/* 8E2A0 800F4DF0 2685003A */   addiu    $a1, $s4, 0x3a
/* 8E2A4 800F4DF4 26660004 */  addiu     $a2, $s3, 4
/* 8E2A8 800F4DF8 2402000A */  addiu     $v0, $zero, 0xa
/* 8E2AC 800F4DFC AFA20010 */  sw        $v0, 0x10($sp)
/* 8E2B0 800F4E00 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 8E2B4 800F4E04 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 8E2B8 800F4E08 AFA30018 */  sw        $v1, 0x18($sp)
/* 8E2BC 800F4E0C 9044000F */  lbu       $a0, 0xf($v0)
/* 8E2C0 800F4E10 8E220000 */  lw        $v0, ($s1)
/* 8E2C4 800F4E14 24070001 */  addiu     $a3, $zero, 1
/* 8E2C8 800F4E18 0C049DA7 */  jal       draw_number
/* 8E2CC 800F4E1C AFA20014 */   sw       $v0, 0x14($sp)
.L800F4E20:
/* 8E2D0 800F4E20 8FBF0034 */  lw        $ra, 0x34($sp)
/* 8E2D4 800F4E24 8FB40030 */  lw        $s4, 0x30($sp)
/* 8E2D8 800F4E28 8FB3002C */  lw        $s3, 0x2c($sp)
/* 8E2DC 800F4E2C 8FB20028 */  lw        $s2, 0x28($sp)
/* 8E2E0 800F4E30 8FB10024 */  lw        $s1, 0x24($sp)
/* 8E2E4 800F4E34 8FB00020 */  lw        $s0, 0x20($sp)
/* 8E2E8 800F4E38 03E00008 */  jr        $ra
/* 8E2EC 800F4E3C 27BD0038 */   addiu    $sp, $sp, 0x38
