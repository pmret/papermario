.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240468_E161E8
/* E161E8 80240468 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E161EC 8024046C AFB00010 */  sw        $s0, 0x10($sp)
/* E161F0 80240470 00A0802D */  daddu     $s0, $a1, $zero
/* E161F4 80240474 0000202D */  daddu     $a0, $zero, $zero
/* E161F8 80240478 AFBF001C */  sw        $ra, 0x1c($sp)
/* E161FC 8024047C AFB20018 */  sw        $s2, 0x18($sp)
/* E16200 80240480 0C00FB3A */  jal       get_enemy
/* E16204 80240484 AFB10014 */   sw       $s1, 0x14($sp)
/* E16208 80240488 8C52006C */  lw        $s2, 0x6c($v0)
/* E1620C 8024048C 12000026 */  beqz      $s0, .L80240528
/* E16210 80240490 00000000 */   nop      
/* E16214 80240494 3C058024 */  lui       $a1, %hi(func_80240430_E15D48)
/* E16218 80240498 24A50430 */  addiu     $a1, $a1, %lo(func_80240430_E15D48)
/* E1621C 8024049C 0C048C56 */  jal       bind_dynamic_entity_3
/* E16220 802404A0 0000202D */   daddu    $a0, $zero, $zero
/* E16224 802404A4 3C118011 */  lui       $s1, %hi(D_80108B28)
/* E16228 802404A8 26318B28 */  addiu     $s1, $s1, %lo(D_80108B28)
/* E1622C 802404AC 0220202D */  daddu     $a0, $s1, $zero
/* E16230 802404B0 0C050529 */  jal       create_icon
/* E16234 802404B4 AE420000 */   sw       $v0, ($s2)
/* E16238 802404B8 0040802D */  daddu     $s0, $v0, $zero
/* E1623C 802404BC 0200202D */  daddu     $a0, $s0, $zero
/* E16240 802404C0 0000282D */  daddu     $a1, $zero, $zero
/* E16244 802404C4 0C051277 */  jal       func_801449DC
/* E16248 802404C8 AE50000C */   sw       $s0, 0xc($s2)
/* E1624C 802404CC 0200202D */  daddu     $a0, $s0, $zero
/* E16250 802404D0 0C051280 */  jal       set_icon_flags
/* E16254 802404D4 24050080 */   addiu    $a1, $zero, 0x80
/* E16258 802404D8 0200202D */  daddu     $a0, $s0, $zero
/* E1625C 802404DC 240500FF */  addiu     $a1, $zero, 0xff
/* E16260 802404E0 00A0302D */  daddu     $a2, $a1, $zero
/* E16264 802404E4 0C0513BF */  jal       icon_set_tint
/* E16268 802404E8 00A0382D */   daddu    $a3, $a1, $zero
/* E1626C 802404EC 0200202D */  daddu     $a0, $s0, $zero
/* E16270 802404F0 0C0511FF */  jal       set_menu_icon_script
/* E16274 802404F4 0220282D */   daddu    $a1, $s1, $zero
/* E16278 802404F8 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* E1627C 802404FC 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* E16280 80240500 0C050529 */  jal       create_icon
/* E16284 80240504 00000000 */   nop      
/* E16288 80240508 0040802D */  daddu     $s0, $v0, $zero
/* E1628C 8024050C 0200202D */  daddu     $a0, $s0, $zero
/* E16290 80240510 0000282D */  daddu     $a1, $zero, $zero
/* E16294 80240514 0C051277 */  jal       func_801449DC
/* E16298 80240518 AE500010 */   sw       $s0, 0x10($s2)
/* E1629C 8024051C 0200202D */  daddu     $a0, $s0, $zero
/* E162A0 80240520 0C051280 */  jal       set_icon_flags
/* E162A4 80240524 24050080 */   addiu    $a1, $zero, 0x80
.L80240528:
/* E162A8 80240528 8FBF001C */  lw        $ra, 0x1c($sp)
/* E162AC 8024052C 8FB20018 */  lw        $s2, 0x18($sp)
/* E162B0 80240530 8FB10014 */  lw        $s1, 0x14($sp)
/* E162B4 80240534 8FB00010 */  lw        $s0, 0x10($sp)
/* E162B8 80240538 0000102D */  daddu     $v0, $zero, $zero
/* E162BC 8024053C 03E00008 */  jr        $ra
/* E162C0 80240540 27BD0020 */   addiu    $sp, $sp, 0x20
