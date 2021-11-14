.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_8010C8A8
.word L800F4694_8DB44, L800F48A4_8DD54, L800F4694_8DB44, L800F47E4_8DC94, L800F48A4_8DD54, L800F4694_8DB44, L800F4694_8DB44, L800F4694_8DB44, L800F4804_8DCB4, L800F4824_8DCD4, L800F4844_8DCF4, L800F4864_8DD14, L800F4884_8DD34, L800F48A4_8DD54

.section .text

glabel popup_menu_draw_title_contents
/* 8DAF8 800F4648 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8DAFC 800F464C 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8DB00 800F4650 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 8DB04 800F4654 AFBF0034 */  sw        $ra, 0x34($sp)
/* 8DB08 800F4658 AFB40030 */  sw        $s4, 0x30($sp)
/* 8DB0C 800F465C AFB3002C */  sw        $s3, 0x2c($sp)
/* 8DB10 800F4660 AFB20028 */  sw        $s2, 0x28($sp)
/* 8DB14 800F4664 AFB10024 */  sw        $s1, 0x24($sp)
/* 8DB18 800F4668 AFB00020 */  sw        $s0, 0x20($sp)
/* 8DB1C 800F466C 8C430318 */  lw        $v1, 0x318($v0)
/* 8DB20 800F4670 2C62000E */  sltiu     $v0, $v1, 0xe
/* 8DB24 800F4674 10400097 */  beqz      $v0, .L800F48D4
/* 8DB28 800F4678 00A0A02D */   daddu    $s4, $a1, $zero
/* 8DB2C 800F467C 00031080 */  sll       $v0, $v1, 2
/* 8DB30 800F4680 3C018011 */  lui       $at, %hi(jtbl_8010C8A8)
/* 8DB34 800F4684 00220821 */  addu      $at, $at, $v0
/* 8DB38 800F4688 8C22C8A8 */  lw        $v0, %lo(jtbl_8010C8A8)($at)
/* 8DB3C 800F468C 00400008 */  jr        $v0
/* 8DB40 800F4690 00000000 */   nop
dlabel L800F4694_8DB44
/* 8DB44 800F4694 3C138011 */  lui       $s3, %hi(D_8010D69C)
/* 8DB48 800F4698 2673D69C */  addiu     $s3, $s3, %lo(D_8010D69C)
/* 8DB4C 800F469C 8E620000 */  lw        $v0, ($s3)
/* 8DB50 800F46A0 8C43031C */  lw        $v1, 0x31c($v0)
/* 8DB54 800F46A4 24080001 */  addiu     $t0, $zero, 1
/* 8DB58 800F46A8 10680014 */  beq       $v1, $t0, .L800F46FC
/* 8DB5C 800F46AC 28620002 */   slti     $v0, $v1, 2
/* 8DB60 800F46B0 50400005 */  beql      $v0, $zero, .L800F46C8
/* 8DB64 800F46B4 24020002 */   addiu    $v0, $zero, 2
/* 8DB68 800F46B8 10600007 */  beqz      $v1, .L800F46D8
/* 8DB6C 800F46BC 3C04001D */   lui      $a0, 0x1d
/* 8DB70 800F46C0 0803D235 */  j         .L800F48D4
/* 8DB74 800F46C4 00000000 */   nop
.L800F46C8:
/* 8DB78 800F46C8 10620025 */  beq       $v1, $v0, .L800F4760
/* 8DB7C 800F46CC 3C04001D */   lui      $a0, 0x1d
/* 8DB80 800F46D0 0803D235 */  j         .L800F48D4
/* 8DB84 800F46D4 00000000 */   nop
.L800F46D8:
/* 8DB88 800F46D8 3484003F */  ori       $a0, $a0, 0x3f
/* 8DB8C 800F46DC 2685001A */  addiu     $a1, $s4, 0x1a
/* 8DB90 800F46E0 24C60002 */  addiu     $a2, $a2, 2
/* 8DB94 800F46E4 3C078011 */  lui       $a3, %hi(D_8010D650)
/* 8DB98 800F46E8 8CE7D650 */  lw        $a3, %lo(D_8010D650)($a3)
/* 8DB9C 800F46EC 24020032 */  addiu     $v0, $zero, 0x32
/* 8DBA0 800F46F0 AFA20010 */  sw        $v0, 0x10($sp)
/* 8DBA4 800F46F4 0803D233 */  j         .L800F48CC
/* 8DBA8 800F46F8 AFA80014 */   sw       $t0, 0x14($sp)
.L800F46FC:
/* 8DBAC 800F46FC 3C04001D */  lui       $a0, 0x1d
/* 8DBB0 800F4700 34840041 */  ori       $a0, $a0, 0x41
/* 8DBB4 800F4704 26850004 */  addiu     $a1, $s4, 4
/* 8DBB8 800F4708 24D20002 */  addiu     $s2, $a2, 2
/* 8DBBC 800F470C 0240302D */  daddu     $a2, $s2, $zero
/* 8DBC0 800F4710 3C108011 */  lui       $s0, %hi(D_8010D650)
/* 8DBC4 800F4714 2610D650 */  addiu     $s0, $s0, %lo(D_8010D650)
/* 8DBC8 800F4718 8E070000 */  lw        $a3, ($s0)
/* 8DBCC 800F471C 24110032 */  addiu     $s1, $zero, 0x32
/* 8DBD0 800F4720 AFB10010 */  sw        $s1, 0x10($sp)
/* 8DBD4 800F4724 0C04993B */  jal       draw_msg
/* 8DBD8 800F4728 AFA80014 */   sw       $t0, 0x14($sp)
/* 8DBDC 800F472C 2685005E */  addiu     $a1, $s4, 0x5e
/* 8DBE0 800F4730 0240302D */  daddu     $a2, $s2, $zero
/* 8DBE4 800F4734 AFB10010 */  sw        $s1, 0x10($sp)
/* 8DBE8 800F4738 8E630000 */  lw        $v1, ($s3)
/* 8DBEC 800F473C 8E020000 */  lw        $v0, ($s0)
/* 8DBF0 800F4740 24130003 */  addiu     $s3, $zero, 3
/* 8DBF4 800F4744 AFB30018 */  sw        $s3, 0x18($sp)
/* 8DBF8 800F4748 AFA20014 */  sw        $v0, 0x14($sp)
/* 8DBFC 800F474C 8C640320 */  lw        $a0, 0x320($v1)
/* 8DC00 800F4750 0C049DA7 */  jal       draw_number
/* 8DC04 800F4754 24070001 */   addiu    $a3, $zero, 1
/* 8DC08 800F4758 0803D1EF */  j         .L800F47BC
/* 8DC0C 800F475C 24040002 */   addiu    $a0, $zero, 2
.L800F4760:
/* 8DC10 800F4760 34840042 */  ori       $a0, $a0, 0x42
/* 8DC14 800F4764 26850006 */  addiu     $a1, $s4, 6
/* 8DC18 800F4768 24D20002 */  addiu     $s2, $a2, 2
/* 8DC1C 800F476C 0240302D */  daddu     $a2, $s2, $zero
/* 8DC20 800F4770 3C108011 */  lui       $s0, %hi(D_8010D650)
/* 8DC24 800F4774 2610D650 */  addiu     $s0, $s0, %lo(D_8010D650)
/* 8DC28 800F4778 8E070000 */  lw        $a3, ($s0)
/* 8DC2C 800F477C 24110032 */  addiu     $s1, $zero, 0x32
/* 8DC30 800F4780 AFB10010 */  sw        $s1, 0x10($sp)
/* 8DC34 800F4784 0C04993B */  jal       draw_msg
/* 8DC38 800F4788 AFA80014 */   sw       $t0, 0x14($sp)
/* 8DC3C 800F478C 2685005E */  addiu     $a1, $s4, 0x5e
/* 8DC40 800F4790 0240302D */  daddu     $a2, $s2, $zero
/* 8DC44 800F4794 AFB10010 */  sw        $s1, 0x10($sp)
/* 8DC48 800F4798 8E630000 */  lw        $v1, ($s3)
/* 8DC4C 800F479C 8E020000 */  lw        $v0, ($s0)
/* 8DC50 800F47A0 24130003 */  addiu     $s3, $zero, 3
/* 8DC54 800F47A4 AFB30018 */  sw        $s3, 0x18($sp)
/* 8DC58 800F47A8 AFA20014 */  sw        $v0, 0x14($sp)
/* 8DC5C 800F47AC 8C640320 */  lw        $a0, 0x320($v1)
/* 8DC60 800F47B0 0C049DA7 */  jal       draw_number
/* 8DC64 800F47B4 24070001 */   addiu    $a3, $zero, 1
/* 8DC68 800F47B8 0260202D */  daddu     $a0, $s3, $zero
.L800F47BC:
/* 8DC6C 800F47BC 26850072 */  addiu     $a1, $s4, 0x72
/* 8DC70 800F47C0 0240302D */  daddu     $a2, $s2, $zero
/* 8DC74 800F47C4 8E020000 */  lw        $v0, ($s0)
/* 8DC78 800F47C8 24070001 */  addiu     $a3, $zero, 1
/* 8DC7C 800F47CC AFB10010 */  sw        $s1, 0x10($sp)
/* 8DC80 800F47D0 AFB30018 */  sw        $s3, 0x18($sp)
/* 8DC84 800F47D4 0C049DA7 */  jal       draw_number
/* 8DC88 800F47D8 AFA20014 */   sw       $v0, 0x14($sp)
/* 8DC8C 800F47DC 0803D235 */  j         .L800F48D4
/* 8DC90 800F47E0 00000000 */   nop
dlabel L800F47E4_8DC94
/* 8DC94 800F47E4 3C04001F */  lui       $a0, 0x1f
/* 8DC98 800F47E8 34840032 */  ori       $a0, $a0, 0x32
/* 8DC9C 800F47EC 2685001B */  addiu     $a1, $s4, 0x1b
/* 8DCA0 800F47F0 24C60002 */  addiu     $a2, $a2, 2
/* 8DCA4 800F47F4 3C078011 */  lui       $a3, %hi(D_8010D650)
/* 8DCA8 800F47F8 8CE7D650 */  lw        $a3, %lo(D_8010D650)($a3)
/* 8DCAC 800F47FC 0803D230 */  j         .L800F48C0
/* 8DCB0 800F4800 24020032 */   addiu    $v0, $zero, 0x32
dlabel L800F4804_8DCB4
/* 8DCB4 800F4804 3C04001F */  lui       $a0, 0x1f
/* 8DCB8 800F4808 34840033 */  ori       $a0, $a0, 0x33
/* 8DCBC 800F480C 26850017 */  addiu     $a1, $s4, 0x17
/* 8DCC0 800F4810 24C60002 */  addiu     $a2, $a2, 2
/* 8DCC4 800F4814 3C078011 */  lui       $a3, %hi(D_8010D650)
/* 8DCC8 800F4818 8CE7D650 */  lw        $a3, %lo(D_8010D650)($a3)
/* 8DCCC 800F481C 0803D230 */  j         .L800F48C0
/* 8DCD0 800F4820 24020032 */   addiu    $v0, $zero, 0x32
dlabel L800F4824_8DCD4
/* 8DCD4 800F4824 3C04001D */  lui       $a0, 0x1d
/* 8DCD8 800F4828 348400D7 */  ori       $a0, $a0, 0xd7
/* 8DCDC 800F482C 26850004 */  addiu     $a1, $s4, 4
/* 8DCE0 800F4830 24C60002 */  addiu     $a2, $a2, 2
/* 8DCE4 800F4834 3C078011 */  lui       $a3, %hi(D_8010D650)
/* 8DCE8 800F4838 8CE7D650 */  lw        $a3, %lo(D_8010D650)($a3)
/* 8DCEC 800F483C 0803D230 */  j         .L800F48C0
/* 8DCF0 800F4840 24020032 */   addiu    $v0, $zero, 0x32
dlabel L800F4844_8DCF4
/* 8DCF4 800F4844 3C04001D */  lui       $a0, 0x1d
/* 8DCF8 800F4848 348400CE */  ori       $a0, $a0, 0xce
/* 8DCFC 800F484C 26850008 */  addiu     $a1, $s4, 8
/* 8DD00 800F4850 24C60002 */  addiu     $a2, $a2, 2
/* 8DD04 800F4854 3C078011 */  lui       $a3, %hi(D_8010D650)
/* 8DD08 800F4858 8CE7D650 */  lw        $a3, %lo(D_8010D650)($a3)
/* 8DD0C 800F485C 0803D230 */  j         .L800F48C0
/* 8DD10 800F4860 24020032 */   addiu    $v0, $zero, 0x32
dlabel L800F4864_8DD14
/* 8DD14 800F4864 3C04001D */  lui       $a0, 0x1d
/* 8DD18 800F4868 348400D0 */  ori       $a0, $a0, 0xd0
/* 8DD1C 800F486C 26850006 */  addiu     $a1, $s4, 6
/* 8DD20 800F4870 24C60002 */  addiu     $a2, $a2, 2
/* 8DD24 800F4874 3C078011 */  lui       $a3, %hi(D_8010D650)
/* 8DD28 800F4878 8CE7D650 */  lw        $a3, %lo(D_8010D650)($a3)
/* 8DD2C 800F487C 0803D230 */  j         .L800F48C0
/* 8DD30 800F4880 24020032 */   addiu    $v0, $zero, 0x32
dlabel L800F4884_8DD34
/* 8DD34 800F4884 3C04001D */  lui       $a0, 0x1d
/* 8DD38 800F4888 3484003F */  ori       $a0, $a0, 0x3f
/* 8DD3C 800F488C 2685001B */  addiu     $a1, $s4, 0x1b
/* 8DD40 800F4890 24C60002 */  addiu     $a2, $a2, 2
/* 8DD44 800F4894 3C078011 */  lui       $a3, %hi(D_8010D650)
/* 8DD48 800F4898 8CE7D650 */  lw        $a3, %lo(D_8010D650)($a3)
/* 8DD4C 800F489C 0803D230 */  j         .L800F48C0
/* 8DD50 800F48A0 24020032 */   addiu    $v0, $zero, 0x32
dlabel L800F48A4_8DD54
/* 8DD54 800F48A4 3C04001D */  lui       $a0, 0x1d
/* 8DD58 800F48A8 3484003D */  ori       $a0, $a0, 0x3d
/* 8DD5C 800F48AC 26850008 */  addiu     $a1, $s4, 8
/* 8DD60 800F48B0 24C60002 */  addiu     $a2, $a2, 2
/* 8DD64 800F48B4 3C078011 */  lui       $a3, %hi(D_8010D650)
/* 8DD68 800F48B8 8CE7D650 */  lw        $a3, %lo(D_8010D650)($a3)
/* 8DD6C 800F48BC 24020034 */  addiu     $v0, $zero, 0x34
.L800F48C0:
/* 8DD70 800F48C0 AFA20010 */  sw        $v0, 0x10($sp)
/* 8DD74 800F48C4 24020001 */  addiu     $v0, $zero, 1
/* 8DD78 800F48C8 AFA20014 */  sw        $v0, 0x14($sp)
.L800F48CC:
/* 8DD7C 800F48CC 0C04993B */  jal       draw_msg
/* 8DD80 800F48D0 00000000 */   nop
.L800F48D4:
/* 8DD84 800F48D4 8FBF0034 */  lw        $ra, 0x34($sp)
/* 8DD88 800F48D8 8FB40030 */  lw        $s4, 0x30($sp)
/* 8DD8C 800F48DC 8FB3002C */  lw        $s3, 0x2c($sp)
/* 8DD90 800F48E0 8FB20028 */  lw        $s2, 0x28($sp)
/* 8DD94 800F48E4 8FB10024 */  lw        $s1, 0x24($sp)
/* 8DD98 800F48E8 8FB00020 */  lw        $s0, 0x20($sp)
/* 8DD9C 800F48EC 03E00008 */  jr        $ra
/* 8DDA0 800F48F0 27BD0038 */   addiu    $sp, $sp, 0x38
