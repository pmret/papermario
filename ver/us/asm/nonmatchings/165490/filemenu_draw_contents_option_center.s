.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_draw_contents_option_center
/* 1656B4 80244E54 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1656B8 80244E58 0080382D */  daddu     $a3, $a0, $zero
/* 1656BC 80244E5C AFB00018 */  sw        $s0, 0x18($sp)
/* 1656C0 80244E60 00A0802D */  daddu     $s0, $a1, $zero
/* 1656C4 80244E64 AFBF002C */  sw        $ra, 0x2c($sp)
/* 1656C8 80244E68 AFB40028 */  sw        $s4, 0x28($sp)
/* 1656CC 80244E6C AFB30024 */  sw        $s3, 0x24($sp)
/* 1656D0 80244E70 AFB20020 */  sw        $s2, 0x20($sp)
/* 1656D4 80244E74 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1656D8 80244E78 80E30004 */  lb        $v1, 4($a3)
/* 1656DC 80244E7C 28620005 */  slti      $v0, $v1, 5
/* 1656E0 80244E80 1040000F */  beqz      $v0, .L80244EC0
/* 1656E4 80244E84 00C0882D */   daddu    $s1, $a2, $zero
/* 1656E8 80244E88 1860000D */  blez      $v1, .L80244EC0
/* 1656EC 80244E8C 2412000A */   addiu    $s2, $zero, 0xa
/* 1656F0 80244E90 24140012 */  addiu     $s4, $zero, 0x12
/* 1656F4 80244E94 3C0400FF */  lui       $a0, 0xff
/* 1656F8 80244E98 3484FF00 */  ori       $a0, $a0, 0xff00
/* 1656FC 80244E9C 3C030001 */  lui       $v1, 1
/* 165700 80244EA0 8CE20000 */  lw        $v0, ($a3)
/* 165704 80244EA4 34630200 */  ori       $v1, $v1, 0x200
/* 165708 80244EA8 00441024 */  and       $v0, $v0, $a0
/* 16570C 80244EAC 14430012 */  bne       $v0, $v1, .L80244EF8
/* 165710 80244EB0 0000982D */   daddu    $s3, $zero, $zero
/* 165714 80244EB4 24040036 */  addiu     $a0, $zero, 0x36
/* 165718 80244EB8 080913BC */  j         .L80244EF0
/* 16571C 80244EBC 26050008 */   addiu    $a1, $s0, 8
.L80244EC0:
/* 165720 80244EC0 2412000B */  addiu     $s2, $zero, 0xb
/* 165724 80244EC4 2414000E */  addiu     $s4, $zero, 0xe
/* 165728 80244EC8 3C0400FF */  lui       $a0, 0xff
/* 16572C 80244ECC 3484FF00 */  ori       $a0, $a0, 0xff00
/* 165730 80244ED0 3C030001 */  lui       $v1, 1
/* 165734 80244ED4 8CE20000 */  lw        $v0, ($a3)
/* 165738 80244ED8 34630200 */  ori       $v1, $v1, 0x200
/* 16573C 80244EDC 00441024 */  and       $v0, $v0, $a0
/* 165740 80244EE0 14430005 */  bne       $v0, $v1, .L80244EF8
/* 165744 80244EE4 0000982D */   daddu    $s3, $zero, $zero
/* 165748 80244EE8 24040036 */  addiu     $a0, $zero, 0x36
/* 16574C 80244EEC 26050004 */  addiu     $a1, $s0, 4
.L80244EF0:
/* 165750 80244EF0 0C090B80 */  jal       filemenu_set_cursor_goal_pos
/* 165754 80244EF4 26260008 */   addiu    $a2, $s1, 8
.L80244EF8:
/* 165758 80244EF8 0C0926A9 */  jal       filemenu_get_menu_message
/* 16575C 80244EFC 0240202D */   daddu    $a0, $s2, $zero
/* 165760 80244F00 0040202D */  daddu     $a0, $v0, $zero
/* 165764 80244F04 02142821 */  addu      $a1, $s0, $s4
/* 165768 80244F08 02333021 */  addu      $a2, $s1, $s3
/* 16576C 80244F0C 24C60002 */  addiu     $a2, $a2, 2
/* 165770 80244F10 24020001 */  addiu     $v0, $zero, 1
/* 165774 80244F14 240700FF */  addiu     $a3, $zero, 0xff
/* 165778 80244F18 AFA00010 */  sw        $zero, 0x10($sp)
/* 16577C 80244F1C 0C09265F */  jal       filemenu_draw_message
/* 165780 80244F20 AFA20014 */   sw       $v0, 0x14($sp)
/* 165784 80244F24 8FBF002C */  lw        $ra, 0x2c($sp)
/* 165788 80244F28 8FB40028 */  lw        $s4, 0x28($sp)
/* 16578C 80244F2C 8FB30024 */  lw        $s3, 0x24($sp)
/* 165790 80244F30 8FB20020 */  lw        $s2, 0x20($sp)
/* 165794 80244F34 8FB1001C */  lw        $s1, 0x1c($sp)
/* 165798 80244F38 8FB00018 */  lw        $s0, 0x18($sp)
/* 16579C 80244F3C 03E00008 */  jr        $ra
/* 1657A0 80244F40 27BD0030 */   addiu    $sp, $sp, 0x30
