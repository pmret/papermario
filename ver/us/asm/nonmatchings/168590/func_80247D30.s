.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80247D30
/* 168590 80247D30 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 168594 80247D34 AFB40030 */  sw        $s4, 0x30($sp)
/* 168598 80247D38 00A0A02D */  daddu     $s4, $a1, $zero
/* 16859C 80247D3C AFB50034 */  sw        $s5, 0x34($sp)
/* 1685A0 80247D40 AFBF0038 */  sw        $ra, 0x38($sp)
/* 1685A4 80247D44 AFB3002C */  sw        $s3, 0x2c($sp)
/* 1685A8 80247D48 AFB20028 */  sw        $s2, 0x28($sp)
/* 1685AC 80247D4C AFB10024 */  sw        $s1, 0x24($sp)
/* 1685B0 80247D50 AFB00020 */  sw        $s0, 0x20($sp)
/* 1685B4 80247D54 80910004 */  lb        $s1, 4($a0)
/* 1685B8 80247D58 24020001 */  addiu     $v0, $zero, 1
/* 1685BC 80247D5C 1222006B */  beq       $s1, $v0, .L80247F0C
/* 1685C0 80247D60 00C0A82D */   daddu    $s5, $a2, $zero
/* 1685C4 80247D64 2A220002 */  slti      $v0, $s1, 2
/* 1685C8 80247D68 10400005 */  beqz      $v0, .L80247D80
/* 1685CC 80247D6C 24020002 */   addiu    $v0, $zero, 2
/* 1685D0 80247D70 12200009 */  beqz      $s1, .L80247D98
/* 1685D4 80247D74 00000000 */   nop
/* 1685D8 80247D78 08091FE9 */  j         .L80247FA4
/* 1685DC 80247D7C 00000000 */   nop
.L80247D80:
/* 1685E0 80247D80 1222001E */  beq       $s1, $v0, .L80247DFC
/* 1685E4 80247D84 24020003 */   addiu    $v0, $zero, 3
/* 1685E8 80247D88 12220066 */  beq       $s1, $v0, .L80247F24
/* 1685EC 80247D8C 00000000 */   nop
/* 1685F0 80247D90 08091FE9 */  j         .L80247FA4
/* 1685F4 80247D94 00000000 */   nop
.L80247D98:
/* 1685F8 80247D98 0C0926A9 */  jal       func_80249AA4
/* 1685FC 80247D9C 2404001A */   addiu    $a0, $zero, 0x1a
/* 168600 80247DA0 0040202D */  daddu     $a0, $v0, $zero
/* 168604 80247DA4 2685000A */  addiu     $a1, $s4, 0xa
/* 168608 80247DA8 26B00004 */  addiu     $s0, $s5, 4
/* 16860C 80247DAC 0200302D */  daddu     $a2, $s0, $zero
/* 168610 80247DB0 240700FF */  addiu     $a3, $zero, 0xff
/* 168614 80247DB4 AFA00010 */  sw        $zero, 0x10($sp)
/* 168618 80247DB8 0C09265F */  jal       func_8024997C
/* 16861C 80247DBC AFA00014 */   sw       $zero, 0x14($sp)
/* 168620 80247DC0 26850030 */  addiu     $a1, $s4, 0x30
/* 168624 80247DC4 26A60006 */  addiu     $a2, $s5, 6
/* 168628 80247DC8 3C028025 */  lui       $v0, %hi(D_80249B84)
/* 16862C 80247DCC 8C429B84 */  lw        $v0, %lo(D_80249B84)($v0)
/* 168630 80247DD0 0000382D */  daddu     $a3, $zero, $zero
/* 168634 80247DD4 90440003 */  lbu       $a0, 3($v0)
/* 168638 80247DD8 240200FF */  addiu     $v0, $zero, 0xff
/* 16863C 80247DDC AFA20014 */  sw        $v0, 0x14($sp)
/* 168640 80247DE0 24020003 */  addiu     $v0, $zero, 3
/* 168644 80247DE4 AFA00010 */  sw        $zero, 0x10($sp)
/* 168648 80247DE8 AFA20018 */  sw        $v0, 0x18($sp)
/* 16864C 80247DEC 0C049DA7 */  jal       draw_number
/* 168650 80247DF0 24840001 */   addiu    $a0, $a0, 1
/* 168654 80247DF4 08091FE0 */  j         .L80247F80
/* 168658 80247DF8 2404001B */   addiu    $a0, $zero, 0x1b
.L80247DFC:
/* 16865C 80247DFC 0C0926A9 */  jal       func_80249AA4
/* 168660 80247E00 2404001D */   addiu    $a0, $zero, 0x1d
/* 168664 80247E04 0040202D */  daddu     $a0, $v0, $zero
/* 168668 80247E08 2692000A */  addiu     $s2, $s4, 0xa
/* 16866C 80247E0C 0240282D */  daddu     $a1, $s2, $zero
/* 168670 80247E10 26B00004 */  addiu     $s0, $s5, 4
/* 168674 80247E14 0200302D */  daddu     $a2, $s0, $zero
/* 168678 80247E18 240700FF */  addiu     $a3, $zero, 0xff
/* 16867C 80247E1C AFA00010 */  sw        $zero, 0x10($sp)
/* 168680 80247E20 0C09265F */  jal       func_8024997C
/* 168684 80247E24 AFA00014 */   sw       $zero, 0x14($sp)
/* 168688 80247E28 0C0926A9 */  jal       func_80249AA4
/* 16868C 80247E2C 2404001A */   addiu    $a0, $zero, 0x1a
/* 168690 80247E30 0040202D */  daddu     $a0, $v0, $zero
/* 168694 80247E34 26850054 */  addiu     $a1, $s4, 0x54
/* 168698 80247E38 0200302D */  daddu     $a2, $s0, $zero
/* 16869C 80247E3C 240700FF */  addiu     $a3, $zero, 0xff
/* 1686A0 80247E40 AFA00010 */  sw        $zero, 0x10($sp)
/* 1686A4 80247E44 0C09265F */  jal       func_8024997C
/* 1686A8 80247E48 AFA00014 */   sw       $zero, 0x14($sp)
/* 1686AC 80247E4C 2685007A */  addiu     $a1, $s4, 0x7a
/* 1686B0 80247E50 26A60006 */  addiu     $a2, $s5, 6
/* 1686B4 80247E54 0000382D */  daddu     $a3, $zero, $zero
/* 1686B8 80247E58 241300FF */  addiu     $s3, $zero, 0xff
/* 1686BC 80247E5C 3C048025 */  lui       $a0, %hi(D_8024C094)
/* 1686C0 80247E60 8C84C094 */  lw        $a0, %lo(D_8024C094)($a0)
/* 1686C4 80247E64 24110003 */  addiu     $s1, $zero, 3
/* 1686C8 80247E68 AFA00010 */  sw        $zero, 0x10($sp)
/* 1686CC 80247E6C AFB30014 */  sw        $s3, 0x14($sp)
/* 1686D0 80247E70 AFB10018 */  sw        $s1, 0x18($sp)
/* 1686D4 80247E74 0C049DA7 */  jal       draw_number
/* 1686D8 80247E78 24840001 */   addiu    $a0, $a0, 1
/* 1686DC 80247E7C 0C0926A9 */  jal       func_80249AA4
/* 1686E0 80247E80 2404001E */   addiu    $a0, $zero, 0x1e
/* 1686E4 80247E84 0040202D */  daddu     $a0, $v0, $zero
/* 1686E8 80247E88 0240282D */  daddu     $a1, $s2, $zero
/* 1686EC 80247E8C 26B00012 */  addiu     $s0, $s5, 0x12
/* 1686F0 80247E90 0200302D */  daddu     $a2, $s0, $zero
/* 1686F4 80247E94 0260382D */  daddu     $a3, $s3, $zero
/* 1686F8 80247E98 AFA00010 */  sw        $zero, 0x10($sp)
/* 1686FC 80247E9C 0C09265F */  jal       func_8024997C
/* 168700 80247EA0 AFA00014 */   sw       $zero, 0x14($sp)
/* 168704 80247EA4 0C0926A9 */  jal       func_80249AA4
/* 168708 80247EA8 2404001A */   addiu    $a0, $zero, 0x1a
/* 16870C 80247EAC 0040202D */  daddu     $a0, $v0, $zero
/* 168710 80247EB0 2685001E */  addiu     $a1, $s4, 0x1e
/* 168714 80247EB4 0200302D */  daddu     $a2, $s0, $zero
/* 168718 80247EB8 0260382D */  daddu     $a3, $s3, $zero
/* 16871C 80247EBC AFA00010 */  sw        $zero, 0x10($sp)
/* 168720 80247EC0 0C09265F */  jal       func_8024997C
/* 168724 80247EC4 AFA00014 */   sw       $zero, 0x14($sp)
/* 168728 80247EC8 26850044 */  addiu     $a1, $s4, 0x44
/* 16872C 80247ECC 26A60014 */  addiu     $a2, $s5, 0x14
/* 168730 80247ED0 3C048025 */  lui       $a0, %hi(D_8024C080)
/* 168734 80247ED4 8C84C080 */  lw        $a0, %lo(D_8024C080)($a0)
/* 168738 80247ED8 0000382D */  daddu     $a3, $zero, $zero
/* 16873C 80247EDC AFA00010 */  sw        $zero, 0x10($sp)
/* 168740 80247EE0 AFB30014 */  sw        $s3, 0x14($sp)
/* 168744 80247EE4 AFB10018 */  sw        $s1, 0x18($sp)
/* 168748 80247EE8 0C049DA7 */  jal       draw_number
/* 16874C 80247EEC 24840001 */   addiu    $a0, $a0, 1
/* 168750 80247EF0 0C0926A9 */  jal       func_80249AA4
/* 168754 80247EF4 24040022 */   addiu    $a0, $zero, 0x22
/* 168758 80247EF8 0040202D */  daddu     $a0, $v0, $zero
/* 16875C 80247EFC 26850041 */  addiu     $a1, $s4, 0x41
/* 168760 80247F00 0200302D */  daddu     $a2, $s0, $zero
/* 168764 80247F04 08091FE6 */  j         .L80247F98
/* 168768 80247F08 0260382D */   daddu    $a3, $s3, $zero
.L80247F0C:
/* 16876C 80247F0C 0C0926A9 */  jal       func_80249AA4
/* 168770 80247F10 2404001C */   addiu    $a0, $zero, 0x1c
/* 168774 80247F14 0040202D */  daddu     $a0, $v0, $zero
/* 168778 80247F18 2685000A */  addiu     $a1, $s4, 0xa
/* 16877C 80247F1C 08091FE5 */  j         .L80247F94
/* 168780 80247F20 26A60004 */   addiu    $a2, $s5, 4
.L80247F24:
/* 168784 80247F24 0C0926A9 */  jal       func_80249AA4
/* 168788 80247F28 2404001A */   addiu    $a0, $zero, 0x1a
/* 16878C 80247F2C 0040202D */  daddu     $a0, $v0, $zero
/* 168790 80247F30 2685000A */  addiu     $a1, $s4, 0xa
/* 168794 80247F34 26B00004 */  addiu     $s0, $s5, 4
/* 168798 80247F38 0200302D */  daddu     $a2, $s0, $zero
/* 16879C 80247F3C 240700FF */  addiu     $a3, $zero, 0xff
/* 1687A0 80247F40 AFA00010 */  sw        $zero, 0x10($sp)
/* 1687A4 80247F44 0C09265F */  jal       func_8024997C
/* 1687A8 80247F48 AFA00014 */   sw       $zero, 0x14($sp)
/* 1687AC 80247F4C 26850030 */  addiu     $a1, $s4, 0x30
/* 1687B0 80247F50 26A60006 */  addiu     $a2, $s5, 6
/* 1687B4 80247F54 3C028025 */  lui       $v0, %hi(D_80249B84)
/* 1687B8 80247F58 8C429B84 */  lw        $v0, %lo(D_80249B84)($v0)
/* 1687BC 80247F5C 0000382D */  daddu     $a3, $zero, $zero
/* 1687C0 80247F60 90440003 */  lbu       $a0, 3($v0)
/* 1687C4 80247F64 240200FF */  addiu     $v0, $zero, 0xff
/* 1687C8 80247F68 AFA00010 */  sw        $zero, 0x10($sp)
/* 1687CC 80247F6C AFA20014 */  sw        $v0, 0x14($sp)
/* 1687D0 80247F70 AFB10018 */  sw        $s1, 0x18($sp)
/* 1687D4 80247F74 0C049DA7 */  jal       draw_number
/* 1687D8 80247F78 24840001 */   addiu    $a0, $a0, 1
/* 1687DC 80247F7C 2404001F */  addiu     $a0, $zero, 0x1f
.L80247F80:
/* 1687E0 80247F80 0C0926A9 */  jal       func_80249AA4
/* 1687E4 80247F84 00000000 */   nop
/* 1687E8 80247F88 0040202D */  daddu     $a0, $v0, $zero
/* 1687EC 80247F8C 26850031 */  addiu     $a1, $s4, 0x31
/* 1687F0 80247F90 0200302D */  daddu     $a2, $s0, $zero
.L80247F94:
/* 1687F4 80247F94 240700FF */  addiu     $a3, $zero, 0xff
.L80247F98:
/* 1687F8 80247F98 AFA00010 */  sw        $zero, 0x10($sp)
/* 1687FC 80247F9C 0C09265F */  jal       func_8024997C
/* 168800 80247FA0 AFA00014 */   sw       $zero, 0x14($sp)
.L80247FA4:
/* 168804 80247FA4 0C090B7B */  jal       func_80242DEC
/* 168808 80247FA8 0000202D */   daddu    $a0, $zero, $zero
/* 16880C 80247FAC 8FBF0038 */  lw        $ra, 0x38($sp)
/* 168810 80247FB0 8FB50034 */  lw        $s5, 0x34($sp)
/* 168814 80247FB4 8FB40030 */  lw        $s4, 0x30($sp)
/* 168818 80247FB8 8FB3002C */  lw        $s3, 0x2c($sp)
/* 16881C 80247FBC 8FB20028 */  lw        $s2, 0x28($sp)
/* 168820 80247FC0 8FB10024 */  lw        $s1, 0x24($sp)
/* 168824 80247FC4 8FB00020 */  lw        $s0, 0x20($sp)
/* 168828 80247FC8 03E00008 */  jr        $ra
/* 16882C 80247FCC 27BD0040 */   addiu    $sp, $sp, 0x40
