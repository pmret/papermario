.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9120
/* 421B10 802A9120 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 421B14 802A9124 AFB20018 */  sw        $s2, 0x18($sp)
/* 421B18 802A9128 0080902D */  daddu     $s2, $a0, $zero
/* 421B1C 802A912C AFB10014 */  sw        $s1, 0x14($sp)
/* 421B20 802A9130 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 421B24 802A9134 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 421B28 802A9138 AFB40020 */  sw        $s4, 0x20($sp)
/* 421B2C 802A913C 0220A02D */  daddu     $s4, $s1, $zero
/* 421B30 802A9140 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 421B34 802A9144 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 421B38 802A9148 AFB3001C */  sw        $s3, 0x1c($sp)
/* 421B3C 802A914C AFBF0024 */  sw        $ra, 0x24($sp)
/* 421B40 802A9150 AFB00010 */  sw        $s0, 0x10($sp)
/* 421B44 802A9154 80620083 */  lb        $v0, 0x83($v1)
/* 421B48 802A9158 8E50000C */  lw        $s0, 0xc($s2)
/* 421B4C 802A915C 14400003 */  bnez      $v0, .L802A916C
/* 421B50 802A9160 0060982D */   daddu    $s3, $v1, $zero
/* 421B54 802A9164 080AA484 */  j         .L802A9210
/* 421B58 802A9168 A0600081 */   sb       $zero, 0x81($v1)
.L802A916C:
/* 421B5C 802A916C 0C09A216 */  jal       func_80268858
/* 421B60 802A9170 00000000 */   nop      
/* 421B64 802A9174 8E050000 */  lw        $a1, ($s0)
/* 421B68 802A9178 26100004 */  addiu     $s0, $s0, 4
/* 421B6C 802A917C 0C0B1EAF */  jal       get_variable
/* 421B70 802A9180 0240202D */   daddu    $a0, $s2, $zero
/* 421B74 802A9184 A622004E */  sh        $v0, 0x4e($s1)
/* 421B78 802A9188 8E050000 */  lw        $a1, ($s0)
/* 421B7C 802A918C 0C0B1EAF */  jal       get_variable
/* 421B80 802A9190 0240202D */   daddu    $a0, $s2, $zero
/* 421B84 802A9194 00022400 */  sll       $a0, $v0, 0x10
/* 421B88 802A9198 00042403 */  sra       $a0, $a0, 0x10
/* 421B8C 802A919C 0C09A089 */  jal       func_80268224
/* 421B90 802A91A0 A6220050 */   sh       $v0, 0x50($s1)
/* 421B94 802A91A4 3C03FFFF */  lui       $v1, 0xffff
/* 421B98 802A91A8 34637FFF */  ori       $v1, $v1, 0x7fff
/* 421B9C 802A91AC 24050032 */  addiu     $a1, $zero, 0x32
/* 421BA0 802A91B0 A6220050 */  sh        $v0, 0x50($s1)
/* 421BA4 802A91B4 A2200060 */  sb        $zero, 0x60($s1)
/* 421BA8 802A91B8 A2600081 */  sb        $zero, 0x81($s3)
/* 421BAC 802A91BC 8E300004 */  lw        $s0, 4($s1)
/* 421BB0 802A91C0 00A0102D */  daddu     $v0, $a1, $zero
/* 421BB4 802A91C4 A6220056 */  sh        $v0, 0x56($s1)
/* 421BB8 802A91C8 8E620000 */  lw        $v0, ($s3)
/* 421BBC 802A91CC 86260058 */  lh        $a2, 0x58($s1)
/* 421BC0 802A91D0 0200202D */  daddu     $a0, $s0, $zero
/* 421BC4 802A91D4 00431024 */  and       $v0, $v0, $v1
/* 421BC8 802A91D8 2403DFFF */  addiu     $v1, $zero, -0x2001
/* 421BCC 802A91DC 00431024 */  and       $v0, $v0, $v1
/* 421BD0 802A91E0 0C051261 */  jal       set_icon_render_pos
/* 421BD4 802A91E4 AE620000 */   sw       $v0, ($s3)
/* 421BD8 802A91E8 82220061 */  lb        $v0, 0x61($s1)
/* 421BDC 802A91EC 10400003 */  beqz      $v0, .L802A91FC
/* 421BE0 802A91F0 0200202D */   daddu    $a0, $s0, $zero
/* 421BE4 802A91F4 0C05128B */  jal       clear_icon_flags
/* 421BE8 802A91F8 24050002 */   addiu    $a1, $zero, 2
.L802A91FC:
/* 421BEC 802A91FC 2402000A */  addiu     $v0, $zero, 0xa
/* 421BF0 802A9200 0C09A446 */  jal       func_80269118
/* 421BF4 802A9204 A682004C */   sh       $v0, 0x4c($s4)
/* 421BF8 802A9208 0C093EB1 */  jal       set_popup_duration
/* 421BFC 802A920C 2404000A */   addiu    $a0, $zero, 0xa
.L802A9210:
/* 421C00 802A9210 24020002 */  addiu     $v0, $zero, 2
/* 421C04 802A9214 8FBF0024 */  lw        $ra, 0x24($sp)
/* 421C08 802A9218 8FB40020 */  lw        $s4, 0x20($sp)
/* 421C0C 802A921C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 421C10 802A9220 8FB20018 */  lw        $s2, 0x18($sp)
/* 421C14 802A9224 8FB10014 */  lw        $s1, 0x14($sp)
/* 421C18 802A9228 8FB00010 */  lw        $s0, 0x10($sp)
/* 421C1C 802A922C 03E00008 */  jr        $ra
/* 421C20 802A9230 27BD0028 */   addiu    $sp, $sp, 0x28
