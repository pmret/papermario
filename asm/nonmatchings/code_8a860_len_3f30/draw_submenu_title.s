.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel draw_submenu_title
/* 08DAF8 800F4648 3C028011 */  lui   $v0, 0x8011
/* 08DAFC 800F464C 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08DB00 800F4650 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 08DB04 800F4654 AFBF0034 */  sw    $ra, 0x34($sp)
/* 08DB08 800F4658 AFB40030 */  sw    $s4, 0x30($sp)
/* 08DB0C 800F465C AFB3002C */  sw    $s3, 0x2c($sp)
/* 08DB10 800F4660 AFB20028 */  sw    $s2, 0x28($sp)
/* 08DB14 800F4664 AFB10024 */  sw    $s1, 0x24($sp)
/* 08DB18 800F4668 AFB00020 */  sw    $s0, 0x20($sp)
/* 08DB1C 800F466C 8C430318 */  lw    $v1, 0x318($v0)
/* 08DB20 800F4670 2C62000E */  sltiu $v0, $v1, 0xe
/* 08DB24 800F4674 10400097 */  beqz  $v0, .L800F48D4
/* 08DB28 800F4678 00A0A02D */   daddu $s4, $a1, $zero
/* 08DB2C 800F467C 00031080 */  sll   $v0, $v1, 2
/* 08DB30 800F4680 3C018011 */  lui   $at, 0x8011
/* 08DB34 800F4684 00220821 */  addu  $at, $at, $v0
/* 08DB38 800F4688 8C22C8A8 */  lw    $v0, -0x3758($at)
/* 08DB3C 800F468C 00400008 */  jr    $v0
/* 08DB40 800F4690 00000000 */   nop   
/* 08DB44 800F4694 3C138011 */  lui   $s3, 0x8011
/* 08DB48 800F4698 2673D69C */  addiu $s3, $s3, -0x2964
/* 08DB4C 800F469C 8E620000 */  lw    $v0, ($s3)
/* 08DB50 800F46A0 8C43031C */  lw    $v1, 0x31c($v0)
/* 08DB54 800F46A4 24080001 */  addiu $t0, $zero, 1
/* 08DB58 800F46A8 10680014 */  beq   $v1, $t0, .L800F46FC
/* 08DB5C 800F46AC 28620002 */   slti  $v0, $v1, 2
/* 08DB60 800F46B0 50400005 */  beql  $v0, $zero, .L800F46C8
/* 08DB64 800F46B4 24020002 */   addiu $v0, $zero, 2
/* 08DB68 800F46B8 10600007 */  beqz  $v1, .L800F46D8
/* 08DB6C 800F46BC 3C04001D */   lui   $a0, 0x1d
/* 08DB70 800F46C0 0803D235 */  j     .L800F48D4
/* 08DB74 800F46C4 00000000 */   nop   

.L800F46C8:
/* 08DB78 800F46C8 10620025 */  beq   $v1, $v0, .L800F4760
/* 08DB7C 800F46CC 3C04001D */   lui   $a0, 0x1d
/* 08DB80 800F46D0 0803D235 */  j     .L800F48D4
/* 08DB84 800F46D4 00000000 */   nop   

.L800F46D8:
/* 08DB88 800F46D8 3484003F */  ori   $a0, $a0, 0x3f
/* 08DB8C 800F46DC 2685001A */  addiu $a1, $s4, 0x1a
/* 08DB90 800F46E0 24C60002 */  addiu $a2, $a2, 2
/* 08DB94 800F46E4 3C078011 */  lui   $a3, 0x8011
/* 08DB98 800F46E8 8CE7D650 */  lw    $a3, -0x29b0($a3)
/* 08DB9C 800F46EC 24020032 */  addiu $v0, $zero, 0x32
/* 08DBA0 800F46F0 AFA20010 */  sw    $v0, 0x10($sp)
/* 08DBA4 800F46F4 0803D233 */  j     .L800F48CC
/* 08DBA8 800F46F8 AFA80014 */   sw    $t0, 0x14($sp)

.L800F46FC:
/* 08DBAC 800F46FC 3C04001D */  lui   $a0, 0x1d
/* 08DBB0 800F4700 34840041 */  ori   $a0, $a0, 0x41
/* 08DBB4 800F4704 26850004 */  addiu $a1, $s4, 4
/* 08DBB8 800F4708 24D20002 */  addiu $s2, $a2, 2
/* 08DBBC 800F470C 0240302D */  daddu $a2, $s2, $zero
/* 08DBC0 800F4710 3C108011 */  lui   $s0, 0x8011
/* 08DBC4 800F4714 2610D650 */  addiu $s0, $s0, -0x29b0
/* 08DBC8 800F4718 8E070000 */  lw    $a3, ($s0)
/* 08DBCC 800F471C 24110032 */  addiu $s1, $zero, 0x32
/* 08DBD0 800F4720 AFB10010 */  sw    $s1, 0x10($sp)
/* 08DBD4 800F4724 0C04993B */  jal   draw_string
/* 08DBD8 800F4728 AFA80014 */   sw    $t0, 0x14($sp)
/* 08DBDC 800F472C 2685005E */  addiu $a1, $s4, 0x5e
/* 08DBE0 800F4730 0240302D */  daddu $a2, $s2, $zero
/* 08DBE4 800F4734 AFB10010 */  sw    $s1, 0x10($sp)
/* 08DBE8 800F4738 8E630000 */  lw    $v1, ($s3)
/* 08DBEC 800F473C 8E020000 */  lw    $v0, ($s0)
/* 08DBF0 800F4740 24130003 */  addiu $s3, $zero, 3
/* 08DBF4 800F4744 AFB30018 */  sw    $s3, 0x18($sp)
/* 08DBF8 800F4748 AFA20014 */  sw    $v0, 0x14($sp)
/* 08DBFC 800F474C 8C640320 */  lw    $a0, 0x320($v1)
/* 08DC00 800F4750 0C049DA7 */  jal   draw_number
/* 08DC04 800F4754 24070001 */   addiu $a3, $zero, 1
/* 08DC08 800F4758 0803D1EF */  j     .L800F47BC
/* 08DC0C 800F475C 24040002 */   addiu $a0, $zero, 2

.L800F4760:
/* 08DC10 800F4760 34840042 */  ori   $a0, $a0, 0x42
/* 08DC14 800F4764 26850006 */  addiu $a1, $s4, 6
/* 08DC18 800F4768 24D20002 */  addiu $s2, $a2, 2
/* 08DC1C 800F476C 0240302D */  daddu $a2, $s2, $zero
/* 08DC20 800F4770 3C108011 */  lui   $s0, 0x8011
/* 08DC24 800F4774 2610D650 */  addiu $s0, $s0, -0x29b0
/* 08DC28 800F4778 8E070000 */  lw    $a3, ($s0)
/* 08DC2C 800F477C 24110032 */  addiu $s1, $zero, 0x32
/* 08DC30 800F4780 AFB10010 */  sw    $s1, 0x10($sp)
/* 08DC34 800F4784 0C04993B */  jal   draw_string
/* 08DC38 800F4788 AFA80014 */   sw    $t0, 0x14($sp)
/* 08DC3C 800F478C 2685005E */  addiu $a1, $s4, 0x5e
/* 08DC40 800F4790 0240302D */  daddu $a2, $s2, $zero
/* 08DC44 800F4794 AFB10010 */  sw    $s1, 0x10($sp)
/* 08DC48 800F4798 8E630000 */  lw    $v1, ($s3)
/* 08DC4C 800F479C 8E020000 */  lw    $v0, ($s0)
/* 08DC50 800F47A0 24130003 */  addiu $s3, $zero, 3
/* 08DC54 800F47A4 AFB30018 */  sw    $s3, 0x18($sp)
/* 08DC58 800F47A8 AFA20014 */  sw    $v0, 0x14($sp)
/* 08DC5C 800F47AC 8C640320 */  lw    $a0, 0x320($v1)
/* 08DC60 800F47B0 0C049DA7 */  jal   draw_number
/* 08DC64 800F47B4 24070001 */   addiu $a3, $zero, 1
/* 08DC68 800F47B8 0260202D */  daddu $a0, $s3, $zero
.L800F47BC:
/* 08DC6C 800F47BC 26850072 */  addiu $a1, $s4, 0x72
/* 08DC70 800F47C0 0240302D */  daddu $a2, $s2, $zero
/* 08DC74 800F47C4 8E020000 */  lw    $v0, ($s0)
/* 08DC78 800F47C8 24070001 */  addiu $a3, $zero, 1
/* 08DC7C 800F47CC AFB10010 */  sw    $s1, 0x10($sp)
/* 08DC80 800F47D0 AFB30018 */  sw    $s3, 0x18($sp)
/* 08DC84 800F47D4 0C049DA7 */  jal   draw_number
/* 08DC88 800F47D8 AFA20014 */   sw    $v0, 0x14($sp)
/* 08DC8C 800F47DC 0803D235 */  j     .L800F48D4
/* 08DC90 800F47E0 00000000 */   nop   

/* 08DC94 800F47E4 3C04001F */  lui   $a0, 0x1f
/* 08DC98 800F47E8 34840032 */  ori   $a0, $a0, 0x32
/* 08DC9C 800F47EC 2685001B */  addiu $a1, $s4, 0x1b
/* 08DCA0 800F47F0 24C60002 */  addiu $a2, $a2, 2
/* 08DCA4 800F47F4 3C078011 */  lui   $a3, 0x8011
/* 08DCA8 800F47F8 8CE7D650 */  lw    $a3, -0x29b0($a3)
/* 08DCAC 800F47FC 0803D230 */  j     .L800F48C0
/* 08DCB0 800F4800 24020032 */   addiu $v0, $zero, 0x32

/* 08DCB4 800F4804 3C04001F */  lui   $a0, 0x1f
/* 08DCB8 800F4808 34840033 */  ori   $a0, $a0, 0x33
/* 08DCBC 800F480C 26850017 */  addiu $a1, $s4, 0x17
/* 08DCC0 800F4810 24C60002 */  addiu $a2, $a2, 2
/* 08DCC4 800F4814 3C078011 */  lui   $a3, 0x8011
/* 08DCC8 800F4818 8CE7D650 */  lw    $a3, -0x29b0($a3)
/* 08DCCC 800F481C 0803D230 */  j     .L800F48C0
/* 08DCD0 800F4820 24020032 */   addiu $v0, $zero, 0x32

/* 08DCD4 800F4824 3C04001D */  lui   $a0, 0x1d
/* 08DCD8 800F4828 348400D7 */  ori   $a0, $a0, 0xd7
/* 08DCDC 800F482C 26850004 */  addiu $a1, $s4, 4
/* 08DCE0 800F4830 24C60002 */  addiu $a2, $a2, 2
/* 08DCE4 800F4834 3C078011 */  lui   $a3, 0x8011
/* 08DCE8 800F4838 8CE7D650 */  lw    $a3, -0x29b0($a3)
/* 08DCEC 800F483C 0803D230 */  j     .L800F48C0
/* 08DCF0 800F4840 24020032 */   addiu $v0, $zero, 0x32

/* 08DCF4 800F4844 3C04001D */  lui   $a0, 0x1d
/* 08DCF8 800F4848 348400CE */  ori   $a0, $a0, 0xce
/* 08DCFC 800F484C 26850008 */  addiu $a1, $s4, 8
/* 08DD00 800F4850 24C60002 */  addiu $a2, $a2, 2
/* 08DD04 800F4854 3C078011 */  lui   $a3, 0x8011
/* 08DD08 800F4858 8CE7D650 */  lw    $a3, -0x29b0($a3)
/* 08DD0C 800F485C 0803D230 */  j     .L800F48C0
/* 08DD10 800F4860 24020032 */   addiu $v0, $zero, 0x32

/* 08DD14 800F4864 3C04001D */  lui   $a0, 0x1d
/* 08DD18 800F4868 348400D0 */  ori   $a0, $a0, 0xd0
/* 08DD1C 800F486C 26850006 */  addiu $a1, $s4, 6
/* 08DD20 800F4870 24C60002 */  addiu $a2, $a2, 2
/* 08DD24 800F4874 3C078011 */  lui   $a3, 0x8011
/* 08DD28 800F4878 8CE7D650 */  lw    $a3, -0x29b0($a3)
/* 08DD2C 800F487C 0803D230 */  j     .L800F48C0
/* 08DD30 800F4880 24020032 */   addiu $v0, $zero, 0x32

/* 08DD34 800F4884 3C04001D */  lui   $a0, 0x1d
/* 08DD38 800F4888 3484003F */  ori   $a0, $a0, 0x3f
/* 08DD3C 800F488C 2685001B */  addiu $a1, $s4, 0x1b
/* 08DD40 800F4890 24C60002 */  addiu $a2, $a2, 2
/* 08DD44 800F4894 3C078011 */  lui   $a3, 0x8011
/* 08DD48 800F4898 8CE7D650 */  lw    $a3, -0x29b0($a3)
/* 08DD4C 800F489C 0803D230 */  j     .L800F48C0
/* 08DD50 800F48A0 24020032 */   addiu $v0, $zero, 0x32

/* 08DD54 800F48A4 3C04001D */  lui   $a0, 0x1d
/* 08DD58 800F48A8 3484003D */  ori   $a0, $a0, 0x3d
/* 08DD5C 800F48AC 26850008 */  addiu $a1, $s4, 8
/* 08DD60 800F48B0 24C60002 */  addiu $a2, $a2, 2
/* 08DD64 800F48B4 3C078011 */  lui   $a3, 0x8011
/* 08DD68 800F48B8 8CE7D650 */  lw    $a3, -0x29b0($a3)
/* 08DD6C 800F48BC 24020034 */  addiu $v0, $zero, 0x34
.L800F48C0:
/* 08DD70 800F48C0 AFA20010 */  sw    $v0, 0x10($sp)
/* 08DD74 800F48C4 24020001 */  addiu $v0, $zero, 1
/* 08DD78 800F48C8 AFA20014 */  sw    $v0, 0x14($sp)
.L800F48CC:
/* 08DD7C 800F48CC 0C04993B */  jal   draw_string
/* 08DD80 800F48D0 00000000 */   nop   
.L800F48D4:
/* 08DD84 800F48D4 8FBF0034 */  lw    $ra, 0x34($sp)
/* 08DD88 800F48D8 8FB40030 */  lw    $s4, 0x30($sp)
/* 08DD8C 800F48DC 8FB3002C */  lw    $s3, 0x2c($sp)
/* 08DD90 800F48E0 8FB20028 */  lw    $s2, 0x28($sp)
/* 08DD94 800F48E4 8FB10024 */  lw    $s1, 0x24($sp)
/* 08DD98 800F48E8 8FB00020 */  lw    $s0, 0x20($sp)
/* 08DD9C 800F48EC 03E00008 */  jr    $ra
/* 08DDA0 800F48F0 27BD0038 */   addiu $sp, $sp, 0x38

/* 08DDA4 800F48F4 3C028011 */  lui   $v0, 0x8011
/* 08DDA8 800F48F8 8042D690 */  lb    $v0, -0x2970($v0)
/* 08DDAC 800F48FC 3C038011 */  lui   $v1, 0x8011
/* 08DDB0 800F4900 8C63D69C */  lw    $v1, -0x2964($v1)
/* 08DDB4 800F4904 3C078011 */  lui   $a3, 0x8011
/* 08DDB8 800F4908 8CE7D650 */  lw    $a3, -0x29b0($a3)
/* 08DDBC 800F490C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 08DDC0 800F4910 AFA20010 */  sw    $v0, 0x10($sp)
/* 08DDC4 800F4914 3C028011 */  lui   $v0, 0x8011
/* 08DDC8 800F4918 8C42D648 */  lw    $v0, -0x29b8($v0)
/* 08DDCC 800F491C AFBF0018 */  sw    $ra, 0x18($sp)
/* 08DDD0 800F4920 AFA00014 */  sw    $zero, 0x14($sp)
/* 08DDD4 800F4924 00021080 */  sll   $v0, $v0, 2
/* 08DDD8 800F4928 00621821 */  addu  $v1, $v1, $v0
/* 08DDDC 800F492C 8C640294 */  lw    $a0, 0x294($v1)
/* 08DDE0 800F4930 0C04993B */  jal   draw_string
/* 08DDE4 800F4934 24A50008 */   addiu $a1, $a1, 8
/* 08DDE8 800F4938 8FBF0018 */  lw    $ra, 0x18($sp)
/* 08DDEC 800F493C 03E00008 */  jr    $ra
/* 08DDF0 800F4940 27BD0020 */   addiu $sp, $sp, 0x20

/* 08DDF4 800F4944 3C028011 */  lui   $v0, 0x8011
/* 08DDF8 800F4948 8042D68E */  lb    $v0, -0x2972($v0)
/* 08DDFC 800F494C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 08DE00 800F4950 AFB00018 */  sw    $s0, 0x18($sp)
/* 08DE04 800F4954 00A0802D */  daddu $s0, $a1, $zero
/* 08DE08 800F4958 AFB1001C */  sw    $s1, 0x1c($sp)
/* 08DE0C 800F495C 24D10007 */  addiu $s1, $a2, 7
/* 08DE10 800F4960 104000A9 */  beqz  $v0, .L800F4C08
/* 08DE14 800F4964 AFBF0020 */   sw    $ra, 0x20($sp)
/* 08DE18 800F4968 3C028011 */  lui   $v0, 0x8011
/* 08DE1C 800F496C 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08DE20 800F4970 8C430318 */  lw    $v1, 0x318($v0)
/* 08DE24 800F4974 2C62000E */  sltiu $v0, $v1, 0xe
/* 08DE28 800F4978 104000A3 */  beqz  $v0, .L800F4C08
/* 08DE2C 800F497C 00031080 */   sll   $v0, $v1, 2
/* 08DE30 800F4980 3C018011 */  lui   $at, 0x8011
/* 08DE34 800F4984 00220821 */  addu  $at, $at, $v0
/* 08DE38 800F4988 8C22C8E0 */  lw    $v0, -0x3720($at)
/* 08DE3C 800F498C 00400008 */  jr    $v0
/* 08DE40 800F4990 00000000 */   nop   
/* 08DE44 800F4994 3C04001D */  lui   $a0, 0x1d
/* 08DE48 800F4998 34840061 */  ori   $a0, $a0, 0x61
/* 08DE4C 800F499C 0C04991D */  jal   get_string_width
/* 08DE50 800F49A0 0000282D */   daddu $a1, $zero, $zero
/* 08DE54 800F49A4 3C04001D */  lui   $a0, 0x1d
/* 08DE58 800F49A8 0803D2F7 */  j     .L800F4BDC
/* 08DE5C 800F49AC 34840061 */   ori   $a0, $a0, 0x61

/* 08DE60 800F49B0 3C04001D */  lui   $a0, 0x1d
/* 08DE64 800F49B4 34840063 */  ori   $a0, $a0, 0x63
/* 08DE68 800F49B8 0C04991D */  jal   get_string_width
/* 08DE6C 800F49BC 0000282D */   daddu $a1, $zero, $zero
/* 08DE70 800F49C0 3C04001D */  lui   $a0, 0x1d
/* 08DE74 800F49C4 34840063 */  ori   $a0, $a0, 0x63
/* 08DE78 800F49C8 26050048 */  addiu $a1, $s0, 0x48
/* 08DE7C 800F49CC 00021FC2 */  srl   $v1, $v0, 0x1f
/* 08DE80 800F49D0 00621821 */  addu  $v1, $v1, $v0
/* 08DE84 800F49D4 00031843 */  sra   $v1, $v1, 1
/* 08DE88 800F49D8 00A32823 */  subu  $a1, $a1, $v1
/* 08DE8C 800F49DC 0803D2FD */  j     .L800F4BF4
/* 08DE90 800F49E0 2626FFFC */   addiu $a2, $s1, -4

/* 08DE94 800F49E4 3C04001D */  lui   $a0, 0x1d
/* 08DE98 800F49E8 34840064 */  ori   $a0, $a0, 0x64
/* 08DE9C 800F49EC 0C04991D */  jal   get_string_width
/* 08DEA0 800F49F0 0000282D */   daddu $a1, $zero, $zero
/* 08DEA4 800F49F4 3C04001D */  lui   $a0, 0x1d
/* 08DEA8 800F49F8 34840064 */  ori   $a0, $a0, 0x64
/* 08DEAC 800F49FC 26050048 */  addiu $a1, $s0, 0x48
/* 08DEB0 800F4A00 00021FC2 */  srl   $v1, $v0, 0x1f
/* 08DEB4 800F4A04 00621821 */  addu  $v1, $v1, $v0
/* 08DEB8 800F4A08 00031843 */  sra   $v1, $v1, 1
/* 08DEBC 800F4A0C 00A32823 */  subu  $a1, $a1, $v1
/* 08DEC0 800F4A10 0803D2FD */  j     .L800F4BF4
/* 08DEC4 800F4A14 2626FFFC */   addiu $a2, $s1, -4

/* 08DEC8 800F4A18 3C04001D */  lui   $a0, 0x1d
/* 08DECC 800F4A1C 34840070 */  ori   $a0, $a0, 0x70
/* 08DED0 800F4A20 0C04991D */  jal   get_string_width
/* 08DED4 800F4A24 0000282D */   daddu $a1, $zero, $zero
/* 08DED8 800F4A28 3C04001D */  lui   $a0, 0x1d
/* 08DEDC 800F4A2C 34840070 */  ori   $a0, $a0, 0x70
/* 08DEE0 800F4A30 26050040 */  addiu $a1, $s0, 0x40
/* 08DEE4 800F4A34 00021FC2 */  srl   $v1, $v0, 0x1f
/* 08DEE8 800F4A38 00621821 */  addu  $v1, $v1, $v0
/* 08DEEC 800F4A3C 00031843 */  sra   $v1, $v1, 1
/* 08DEF0 800F4A40 00A32823 */  subu  $a1, $a1, $v1
/* 08DEF4 800F4A44 0803D2FD */  j     .L800F4BF4
/* 08DEF8 800F4A48 2626FFFC */   addiu $a2, $s1, -4

/* 08DEFC 800F4A4C 3C04001D */  lui   $a0, 0x1d
/* 08DF00 800F4A50 3484006A */  ori   $a0, $a0, 0x6a
/* 08DF04 800F4A54 0C04991D */  jal   get_string_width
/* 08DF08 800F4A58 0000282D */   daddu $a1, $zero, $zero
/* 08DF0C 800F4A5C 3C04001D */  lui   $a0, 0x1d
/* 08DF10 800F4A60 3484006A */  ori   $a0, $a0, 0x6a
/* 08DF14 800F4A64 26050044 */  addiu $a1, $s0, 0x44
/* 08DF18 800F4A68 00021FC2 */  srl   $v1, $v0, 0x1f
/* 08DF1C 800F4A6C 00621821 */  addu  $v1, $v1, $v0
/* 08DF20 800F4A70 00031843 */  sra   $v1, $v1, 1
/* 08DF24 800F4A74 00A32823 */  subu  $a1, $a1, $v1
/* 08DF28 800F4A78 0803D2FD */  j     .L800F4BF4
/* 08DF2C 800F4A7C 2626FFFC */   addiu $a2, $s1, -4

/* 08DF30 800F4A80 3C04001D */  lui   $a0, 0x1d
/* 08DF34 800F4A84 34840065 */  ori   $a0, $a0, 0x65
/* 08DF38 800F4A88 0C04991D */  jal   get_string_width
/* 08DF3C 800F4A8C 0000282D */   daddu $a1, $zero, $zero
/* 08DF40 800F4A90 3C04001D */  lui   $a0, 0x1d
/* 08DF44 800F4A94 34840065 */  ori   $a0, $a0, 0x65
/* 08DF48 800F4A98 0803D2F8 */  j     .L800F4BE0
/* 08DF4C 800F4A9C 2605003C */   addiu $a1, $s0, 0x3c

/* 08DF50 800F4AA0 3C04001D */  lui   $a0, 0x1d
/* 08DF54 800F4AA4 34840066 */  ori   $a0, $a0, 0x66
/* 08DF58 800F4AA8 0C04991D */  jal   get_string_width
/* 08DF5C 800F4AAC 0000282D */   daddu $a1, $zero, $zero
/* 08DF60 800F4AB0 3C04001D */  lui   $a0, 0x1d
/* 08DF64 800F4AB4 0803D2F7 */  j     .L800F4BDC
/* 08DF68 800F4AB8 34840066 */   ori   $a0, $a0, 0x66

/* 08DF6C 800F4ABC 3C04001D */  lui   $a0, 0x1d
/* 08DF70 800F4AC0 34840067 */  ori   $a0, $a0, 0x67
/* 08DF74 800F4AC4 0C04991D */  jal   get_string_width
/* 08DF78 800F4AC8 0000282D */   daddu $a1, $zero, $zero
/* 08DF7C 800F4ACC 3C04001D */  lui   $a0, 0x1d
/* 08DF80 800F4AD0 0803D2F7 */  j     .L800F4BDC
/* 08DF84 800F4AD4 34840067 */   ori   $a0, $a0, 0x67

/* 08DF88 800F4AD8 3C04001D */  lui   $a0, 0x1d
/* 08DF8C 800F4ADC 3484006F */  ori   $a0, $a0, 0x6f
/* 08DF90 800F4AE0 0C04991D */  jal   get_string_width
/* 08DF94 800F4AE4 0000282D */   daddu $a1, $zero, $zero
/* 08DF98 800F4AE8 3C04001D */  lui   $a0, 0x1d
/* 08DF9C 800F4AEC 3484006F */  ori   $a0, $a0, 0x6f
/* 08DFA0 800F4AF0 26050048 */  addiu $a1, $s0, 0x48
/* 08DFA4 800F4AF4 00021FC2 */  srl   $v1, $v0, 0x1f
/* 08DFA8 800F4AF8 00621821 */  addu  $v1, $v1, $v0
/* 08DFAC 800F4AFC 00031843 */  sra   $v1, $v1, 1
/* 08DFB0 800F4B00 00A32823 */  subu  $a1, $a1, $v1
/* 08DFB4 800F4B04 0803D2FD */  j     .L800F4BF4
/* 08DFB8 800F4B08 2626FFFC */   addiu $a2, $s1, -4

/* 08DFBC 800F4B0C 3C04001D */  lui   $a0, 0x1d
/* 08DFC0 800F4B10 3484006D */  ori   $a0, $a0, 0x6d
/* 08DFC4 800F4B14 0C04991D */  jal   get_string_width
/* 08DFC8 800F4B18 0000282D */   daddu $a1, $zero, $zero
/* 08DFCC 800F4B1C 3C04001D */  lui   $a0, 0x1d
/* 08DFD0 800F4B20 3484006D */  ori   $a0, $a0, 0x6d
/* 08DFD4 800F4B24 26050038 */  addiu $a1, $s0, 0x38
/* 08DFD8 800F4B28 00021FC2 */  srl   $v1, $v0, 0x1f
/* 08DFDC 800F4B2C 00621821 */  addu  $v1, $v1, $v0
/* 08DFE0 800F4B30 00031843 */  sra   $v1, $v1, 1
/* 08DFE4 800F4B34 00A32823 */  subu  $a1, $a1, $v1
/* 08DFE8 800F4B38 0803D2FD */  j     .L800F4BF4
/* 08DFEC 800F4B3C 2626FFFC */   addiu $a2, $s1, -4

/* 08DFF0 800F4B40 3C04001D */  lui   $a0, 0x1d
/* 08DFF4 800F4B44 348400D6 */  ori   $a0, $a0, 0xd6
/* 08DFF8 800F4B48 0C04991D */  jal   get_string_width
/* 08DFFC 800F4B4C 0000282D */   daddu $a1, $zero, $zero
/* 08E000 800F4B50 3C04001D */  lui   $a0, 0x1d
/* 08E004 800F4B54 0803D2F7 */  j     .L800F4BDC
/* 08E008 800F4B58 348400D6 */   ori   $a0, $a0, 0xd6

/* 08E00C 800F4B5C 3C04001D */  lui   $a0, 0x1d
/* 08E010 800F4B60 3484006C */  ori   $a0, $a0, 0x6c
/* 08E014 800F4B64 0C04991D */  jal   get_string_width
/* 08E018 800F4B68 0000282D */   daddu $a1, $zero, $zero
/* 08E01C 800F4B6C 3C04001D */  lui   $a0, 0x1d
/* 08E020 800F4B70 3484006C */  ori   $a0, $a0, 0x6c
/* 08E024 800F4B74 26050040 */  addiu $a1, $s0, 0x40
/* 08E028 800F4B78 00021FC2 */  srl   $v1, $v0, 0x1f
/* 08E02C 800F4B7C 00621821 */  addu  $v1, $v1, $v0
/* 08E030 800F4B80 00031843 */  sra   $v1, $v1, 1
/* 08E034 800F4B84 00A32823 */  subu  $a1, $a1, $v1
/* 08E038 800F4B88 0803D2FD */  j     .L800F4BF4
/* 08E03C 800F4B8C 2626FFFC */   addiu $a2, $s1, -4

/* 08E040 800F4B90 3C04001D */  lui   $a0, 0x1d
/* 08E044 800F4B94 3484006D */  ori   $a0, $a0, 0x6d
/* 08E048 800F4B98 0C04991D */  jal   get_string_width
/* 08E04C 800F4B9C 0000282D */   daddu $a1, $zero, $zero
/* 08E050 800F4BA0 3C04001D */  lui   $a0, 0x1d
/* 08E054 800F4BA4 3484006D */  ori   $a0, $a0, 0x6d
/* 08E058 800F4BA8 26050040 */  addiu $a1, $s0, 0x40
/* 08E05C 800F4BAC 00021FC2 */  srl   $v1, $v0, 0x1f
/* 08E060 800F4BB0 00621821 */  addu  $v1, $v1, $v0
/* 08E064 800F4BB4 00031843 */  sra   $v1, $v1, 1
/* 08E068 800F4BB8 00A32823 */  subu  $a1, $a1, $v1
/* 08E06C 800F4BBC 0803D2FD */  j     .L800F4BF4
/* 08E070 800F4BC0 2626FFFC */   addiu $a2, $s1, -4

/* 08E074 800F4BC4 3C04001D */  lui   $a0, 0x1d
/* 08E078 800F4BC8 34840062 */  ori   $a0, $a0, 0x62
/* 08E07C 800F4BCC 0C04991D */  jal   get_string_width
/* 08E080 800F4BD0 0000282D */   daddu $a1, $zero, $zero
/* 08E084 800F4BD4 3C04001D */  lui   $a0, 0x1d
/* 08E088 800F4BD8 34840062 */  ori   $a0, $a0, 0x62
.L800F4BDC:
/* 08E08C 800F4BDC 26050048 */  addiu $a1, $s0, 0x48
.L800F4BE0:
/* 08E090 800F4BE0 00021FC2 */  srl   $v1, $v0, 0x1f
/* 08E094 800F4BE4 00621821 */  addu  $v1, $v1, $v0
/* 08E098 800F4BE8 00031843 */  sra   $v1, $v1, 1
/* 08E09C 800F4BEC 00A32823 */  subu  $a1, $a1, $v1
/* 08E0A0 800F4BF0 0220302D */  daddu $a2, $s1, $zero
.L800F4BF4:
/* 08E0A4 800F4BF4 240700FF */  addiu $a3, $zero, 0xff
/* 08E0A8 800F4BF8 2402000F */  addiu $v0, $zero, 0xf
/* 08E0AC 800F4BFC AFA20010 */  sw    $v0, 0x10($sp)
/* 08E0B0 800F4C00 0C04993B */  jal   draw_string
/* 08E0B4 800F4C04 AFA00014 */   sw    $zero, 0x14($sp)
.L800F4C08:
/* 08E0B8 800F4C08 8FBF0020 */  lw    $ra, 0x20($sp)
/* 08E0BC 800F4C0C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 08E0C0 800F4C10 8FB00018 */  lw    $s0, 0x18($sp)
/* 08E0C4 800F4C14 03E00008 */  jr    $ra
/* 08E0C8 800F4C18 27BD0028 */   addiu $sp, $sp, 0x28

/* 08E0CC 800F4C1C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 08E0D0 800F4C20 3C04001D */  lui   $a0, 0x1d
/* 08E0D4 800F4C24 34840069 */  ori   $a0, $a0, 0x69
/* 08E0D8 800F4C28 24A5000B */  addiu $a1, $a1, 0xb
/* 08E0DC 800F4C2C 24C60008 */  addiu $a2, $a2, 8
/* 08E0E0 800F4C30 3C038011 */  lui   $v1, 0x8011
/* 08E0E4 800F4C34 8063D699 */  lb    $v1, -0x2967($v1)
/* 08E0E8 800F4C38 24020001 */  addiu $v0, $zero, 1
/* 08E0EC 800F4C3C 14620003 */  bne   $v1, $v0, .L800F4C4C
/* 08E0F0 800F4C40 AFBF0018 */   sw    $ra, 0x18($sp)
/* 08E0F4 800F4C44 3C04001D */  lui   $a0, 0x1d
/* 08E0F8 800F4C48 34840068 */  ori   $a0, $a0, 0x68
.L800F4C4C:
/* 08E0FC 800F4C4C 2402000F */  addiu $v0, $zero, 0xf
/* 08E100 800F4C50 240700FF */  addiu $a3, $zero, 0xff
/* 08E104 800F4C54 AFA20010 */  sw    $v0, 0x10($sp)
/* 08E108 800F4C58 0C04993B */  jal   draw_string
/* 08E10C 800F4C5C AFA00014 */   sw    $zero, 0x14($sp)
/* 08E110 800F4C60 8FBF0018 */  lw    $ra, 0x18($sp)
/* 08E114 800F4C64 03E00008 */  jr    $ra
/* 08E118 800F4C68 27BD0020 */   addiu $sp, $sp, 0x20

/* 08E11C 800F4C6C 3C028011 */  lui   $v0, 0x8011
/* 08E120 800F4C70 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08E124 800F4C74 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08E128 800F4C78 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08E12C 800F4C7C AFB00010 */  sw    $s0, 0x10($sp)
/* 08E130 800F4C80 8C430318 */  lw    $v1, 0x318($v0)
/* 08E134 800F4C84 24020003 */  addiu $v0, $zero, 3
/* 08E138 800F4C88 10620005 */  beq   $v1, $v0, .L800F4CA0
/* 08E13C 800F4C8C 24020005 */   addiu $v0, $zero, 5
/* 08E140 800F4C90 10620008 */  beq   $v1, $v0, .L800F4CB4
/* 08E144 800F4C94 24A50011 */   addiu $a1, $a1, 0x11
/* 08E148 800F4C98 0803D338 */  j     .L800F4CE0
/* 08E14C 800F4C9C 00000000 */   nop   

.L800F4CA0:
/* 08E150 800F4CA0 24A50010 */  addiu $a1, $a1, 0x10
/* 08E154 800F4CA4 3C108011 */  lui   $s0, 0x8011
/* 08E158 800F4CA8 8E10D660 */  lw    $s0, -0x29a0($s0)
/* 08E15C 800F4CAC 0803D330 */  j     .L800F4CC0
/* 08E160 800F4CB0 24C60010 */   addiu $a2, $a2, 0x10

.L800F4CB4:
/* 08E164 800F4CB4 3C108011 */  lui   $s0, 0x8011
/* 08E168 800F4CB8 8E10D660 */  lw    $s0, -0x29a0($s0)
/* 08E16C 800F4CBC 24C60011 */  addiu $a2, $a2, 0x11
.L800F4CC0:
/* 08E170 800F4CC0 0C051261 */  jal   set_icon_render_pos
/* 08E174 800F4CC4 0200202D */   daddu $a0, $s0, $zero
/* 08E178 800F4CC8 3C058011 */  lui   $a1, 0x8011
/* 08E17C 800F4CCC 8CA5D650 */  lw    $a1, -0x29b0($a1)
/* 08E180 800F4CD0 0C0513AC */  jal   func_80144EB0
/* 08E184 800F4CD4 0200202D */   daddu $a0, $s0, $zero
/* 08E188 800F4CD8 0C0511EA */  jal   draw_icon_0
/* 08E18C 800F4CDC 0200202D */   daddu $a0, $s0, $zero
.L800F4CE0:
/* 08E190 800F4CE0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08E194 800F4CE4 8FB00010 */  lw    $s0, 0x10($sp)
/* 08E198 800F4CE8 03E00008 */  jr    $ra
/* 08E19C 800F4CEC 27BD0018 */   addiu $sp, $sp, 0x18

/* 08E1A0 800F4CF0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 08E1A4 800F4CF4 3C04001D */  lui   $a0, 0x1d
/* 08E1A8 800F4CF8 3484006B */  ori   $a0, $a0, 0x6b
/* 08E1AC 800F4CFC 2402000F */  addiu $v0, $zero, 0xf
/* 08E1B0 800F4D00 24A50010 */  addiu $a1, $a1, 0x10
/* 08E1B4 800F4D04 24C60002 */  addiu $a2, $a2, 2
/* 08E1B8 800F4D08 240700FF */  addiu $a3, $zero, 0xff
/* 08E1BC 800F4D0C AFBF0018 */  sw    $ra, 0x18($sp)
/* 08E1C0 800F4D10 AFA20010 */  sw    $v0, 0x10($sp)
/* 08E1C4 800F4D14 0C04993B */  jal   draw_string
/* 08E1C8 800F4D18 AFA00014 */   sw    $zero, 0x14($sp)
/* 08E1CC 800F4D1C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 08E1D0 800F4D20 03E00008 */  jr    $ra
/* 08E1D4 800F4D24 27BD0020 */   addiu $sp, $sp, 0x20

/* 08E1D8 800F4D28 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 08E1DC 800F4D2C AFB40030 */  sw    $s4, 0x30($sp)
/* 08E1E0 800F4D30 00A0A02D */  daddu $s4, $a1, $zero
/* 08E1E4 800F4D34 AFB00020 */  sw    $s0, 0x20($sp)
/* 08E1E8 800F4D38 3C108011 */  lui   $s0, 0x8011
/* 08E1EC 800F4D3C 8E10D660 */  lw    $s0, -0x29a0($s0)
/* 08E1F0 800F4D40 3C058011 */  lui   $a1, 0x8011
/* 08E1F4 800F4D44 8CA5D650 */  lw    $a1, -0x29b0($a1)
/* 08E1F8 800F4D48 AFB3002C */  sw    $s3, 0x2c($sp)
/* 08E1FC 800F4D4C 00C0982D */  daddu $s3, $a2, $zero
/* 08E200 800F4D50 AFB10024 */  sw    $s1, 0x24($sp)
/* 08E204 800F4D54 2691000E */  addiu $s1, $s4, 0xe
/* 08E208 800F4D58 AFB20028 */  sw    $s2, 0x28($sp)
/* 08E20C 800F4D5C 26720009 */  addiu $s2, $s3, 9
/* 08E210 800F4D60 AFBF0034 */  sw    $ra, 0x34($sp)
/* 08E214 800F4D64 0C0513AC */  jal   func_80144EB0
/* 08E218 800F4D68 0200202D */   daddu $a0, $s0, $zero
/* 08E21C 800F4D6C 3C028011 */  lui   $v0, 0x8011
/* 08E220 800F4D70 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08E224 800F4D74 8C430318 */  lw    $v1, 0x318($v0)
/* 08E228 800F4D78 24020003 */  addiu $v0, $zero, 3
/* 08E22C 800F4D7C 14620004 */  bne   $v1, $v0, .L800F4D90
/* 08E230 800F4D80 0200202D */   daddu $a0, $s0, $zero
/* 08E234 800F4D84 0220282D */  daddu $a1, $s1, $zero
/* 08E238 800F4D88 0803D366 */  j     .L800F4D98
/* 08E23C 800F4D8C 0240302D */   daddu $a2, $s2, $zero

.L800F4D90:
/* 08E240 800F4D90 0220282D */  daddu $a1, $s1, $zero
/* 08E244 800F4D94 2666000A */  addiu $a2, $s3, 0xa
.L800F4D98:
/* 08E248 800F4D98 0C051261 */  jal   set_icon_render_pos
/* 08E24C 800F4D9C 00000000 */   nop   
/* 08E250 800F4DA0 0C0511EA */  jal   draw_icon_0
/* 08E254 800F4DA4 0200202D */   daddu $a0, $s0, $zero
/* 08E258 800F4DA8 2685001A */  addiu $a1, $s4, 0x1a
/* 08E25C 800F4DAC 3C108011 */  lui   $s0, 0x8011
/* 08E260 800F4DB0 8E10D664 */  lw    $s0, -0x299c($s0)
/* 08E264 800F4DB4 2666000B */  addiu $a2, $s3, 0xb
/* 08E268 800F4DB8 0C051261 */  jal   set_icon_render_pos
/* 08E26C 800F4DBC 0200202D */   daddu $a0, $s0, $zero
/* 08E270 800F4DC0 3C118011 */  lui   $s1, 0x8011
/* 08E274 800F4DC4 2631D650 */  addiu $s1, $s1, -0x29b0
/* 08E278 800F4DC8 8E250000 */  lw    $a1, ($s1)
/* 08E27C 800F4DCC 0C0513AC */  jal   func_80144EB0
/* 08E280 800F4DD0 0200202D */   daddu $a0, $s0, $zero
/* 08E284 800F4DD4 0C0511EA */  jal   draw_icon_0
/* 08E288 800F4DD8 0200202D */   daddu $a0, $s0, $zero
/* 08E28C 800F4DDC 3C028011 */  lui   $v0, 0x8011
/* 08E290 800F4DE0 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08E294 800F4DE4 8C430318 */  lw    $v1, 0x318($v0)
/* 08E298 800F4DE8 24020003 */  addiu $v0, $zero, 3
/* 08E29C 800F4DEC 1462000C */  bne   $v1, $v0, .L800F4E20
/* 08E2A0 800F4DF0 2685003A */   addiu $a1, $s4, 0x3a
/* 08E2A4 800F4DF4 26660004 */  addiu $a2, $s3, 4
/* 08E2A8 800F4DF8 2402000A */  addiu $v0, $zero, 0xa
/* 08E2AC 800F4DFC AFA20010 */  sw    $v0, 0x10($sp)
/* 08E2B0 800F4E00 3C028011 */  lui   $v0, 0x8011
/* 08E2B4 800F4E04 2442F290 */  addiu $v0, $v0, -0xd70
/* 08E2B8 800F4E08 AFA30018 */  sw    $v1, 0x18($sp)
/* 08E2BC 800F4E0C 9044000F */  lbu   $a0, 0xf($v0)
/* 08E2C0 800F4E10 8E220000 */  lw    $v0, ($s1)
/* 08E2C4 800F4E14 24070001 */  addiu $a3, $zero, 1
/* 08E2C8 800F4E18 0C049DA7 */  jal   draw_number
/* 08E2CC 800F4E1C AFA20014 */   sw    $v0, 0x14($sp)
.L800F4E20:
/* 08E2D0 800F4E20 8FBF0034 */  lw    $ra, 0x34($sp)
/* 08E2D4 800F4E24 8FB40030 */  lw    $s4, 0x30($sp)
/* 08E2D8 800F4E28 8FB3002C */  lw    $s3, 0x2c($sp)
/* 08E2DC 800F4E2C 8FB20028 */  lw    $s2, 0x28($sp)
/* 08E2E0 800F4E30 8FB10024 */  lw    $s1, 0x24($sp)
/* 08E2E4 800F4E34 8FB00020 */  lw    $s0, 0x20($sp)
/* 08E2E8 800F4E38 03E00008 */  jr    $ra
/* 08E2EC 800F4E3C 27BD0038 */   addiu $sp, $sp, 0x38

