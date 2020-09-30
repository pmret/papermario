.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011F4D4
/* B5BD4 8011F4D4 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* B5BD8 8011F4D8 AFB00050 */  sw        $s0, 0x50($sp)
/* B5BDC 8011F4DC 0080802D */  daddu     $s0, $a0, $zero
/* B5BE0 8011F4E0 AFBF0054 */  sw        $ra, 0x54($sp)
/* B5BE4 8011F4E4 8E0200D8 */  lw        $v0, 0xd8($s0)
/* B5BE8 8011F4E8 10400013 */  beqz      $v0, .L8011F538
/* B5BEC 8011F4EC 3C020001 */   lui      $v0, 1
/* B5BF0 8011F4F0 3C04800A */  lui       $a0, 0x800a
/* B5BF4 8011F4F4 2484A66C */  addiu     $a0, $a0, -0x5994
/* B5BF8 8011F4F8 8C830000 */  lw        $v1, ($a0)
/* B5BFC 8011F4FC 3C028015 */  lui       $v0, 0x8015
/* B5C00 8011F500 8C423A60 */  lw        $v0, 0x3a60($v0)
/* B5C04 8011F504 0060282D */  daddu     $a1, $v1, $zero
/* B5C08 8011F508 24630008 */  addiu     $v1, $v1, 8
/* B5C0C 8011F50C 00021080 */  sll       $v0, $v0, 2
/* B5C10 8011F510 3042FFFF */  andi      $v0, $v0, 0xffff
/* B5C14 8011F514 AC830000 */  sw        $v1, ($a0)
/* B5C18 8011F518 3C03DB06 */  lui       $v1, 0xdb06
/* B5C1C 8011F51C 00431025 */  or        $v0, $v0, $v1
/* B5C20 8011F520 ACA20000 */  sw        $v0, ($a1)
/* B5C24 8011F524 8E0200D8 */  lw        $v0, 0xd8($s0)
/* B5C28 8011F528 3C038000 */  lui       $v1, 0x8000
/* B5C2C 8011F52C 00431021 */  addu      $v0, $v0, $v1
/* B5C30 8011F530 ACA20004 */  sw        $v0, 4($a1)
/* B5C34 8011F534 3C020001 */  lui       $v0, 1
.L8011F538:
/* B5C38 8011F538 34421630 */  ori       $v0, $v0, 0x1630
/* B5C3C 8011F53C 26050098 */  addiu     $a1, $s0, 0x98
/* B5C40 8011F540 260600D8 */  addiu     $a2, $s0, 0xd8
/* B5C44 8011F544 3C038007 */  lui       $v1, 0x8007
/* B5C48 8011F548 946341F0 */  lhu       $v1, 0x41f0($v1)
/* B5C4C 8011F54C 3C04800A */  lui       $a0, 0x800a
/* B5C50 8011F550 8C84A674 */  lw        $a0, -0x598c($a0)
/* B5C54 8011F554 00031980 */  sll       $v1, $v1, 6
/* B5C58 8011F558 00832021 */  addu      $a0, $a0, $v1
/* B5C5C 8011F55C 00822021 */  addu      $a0, $a0, $v0
.L8011F560:
/* B5C60 8011F560 8CAA0000 */  lw        $t2, ($a1)
/* B5C64 8011F564 8CAB0004 */  lw        $t3, 4($a1)
/* B5C68 8011F568 8CAC0008 */  lw        $t4, 8($a1)
/* B5C6C 8011F56C 8CAD000C */  lw        $t5, 0xc($a1)
/* B5C70 8011F570 AC8A0000 */  sw        $t2, ($a0)
/* B5C74 8011F574 AC8B0004 */  sw        $t3, 4($a0)
/* B5C78 8011F578 AC8C0008 */  sw        $t4, 8($a0)
/* B5C7C 8011F57C AC8D000C */  sw        $t5, 0xc($a0)
/* B5C80 8011F580 24A50010 */  addiu     $a1, $a1, 0x10
/* B5C84 8011F584 14A6FFF6 */  bne       $a1, $a2, .L8011F560
/* B5C88 8011F588 24840010 */   addiu    $a0, $a0, 0x10
/* B5C8C 8011F58C 3C07DA38 */  lui       $a3, 0xda38
/* B5C90 8011F590 34E70002 */  ori       $a3, $a3, 2
/* B5C94 8011F594 3C080001 */  lui       $t0, 1
/* B5C98 8011F598 3C05800A */  lui       $a1, 0x800a
/* B5C9C 8011F59C 24A5A66C */  addiu     $a1, $a1, -0x5994
/* B5CA0 8011F5A0 35081630 */  ori       $t0, $t0, 0x1630
/* B5CA4 8011F5A4 3C048007 */  lui       $a0, 0x8007
/* B5CA8 8011F5A8 248441F0 */  addiu     $a0, $a0, 0x41f0
/* B5CAC 8011F5AC 8CA20000 */  lw        $v0, ($a1)
/* B5CB0 8011F5B0 94830000 */  lhu       $v1, ($a0)
/* B5CB4 8011F5B4 0040302D */  daddu     $a2, $v0, $zero
/* B5CB8 8011F5B8 24420008 */  addiu     $v0, $v0, 8
/* B5CBC 8011F5BC ACA20000 */  sw        $v0, ($a1)
/* B5CC0 8011F5C0 24620001 */  addiu     $v0, $v1, 1
/* B5CC4 8011F5C4 3063FFFF */  andi      $v1, $v1, 0xffff
/* B5CC8 8011F5C8 00031980 */  sll       $v1, $v1, 6
/* B5CCC 8011F5CC 00681821 */  addu      $v1, $v1, $t0
/* B5CD0 8011F5D0 ACC70000 */  sw        $a3, ($a2)
/* B5CD4 8011F5D4 A4820000 */  sh        $v0, ($a0)
/* B5CD8 8011F5D8 3C02800A */  lui       $v0, 0x800a
/* B5CDC 8011F5DC 8C42A674 */  lw        $v0, -0x598c($v0)
/* B5CE0 8011F5E0 3C048015 */  lui       $a0, 0x8015
/* B5CE4 8011F5E4 8C843A44 */  lw        $a0, 0x3a44($a0)
/* B5CE8 8011F5E8 00431021 */  addu      $v0, $v0, $v1
/* B5CEC 8011F5EC 0004202B */  sltu      $a0, $zero, $a0
/* B5CF0 8011F5F0 10800006 */  beqz      $a0, .L8011F60C
/* B5CF4 8011F5F4 ACC20004 */   sw       $v0, 4($a2)
/* B5CF8 8011F5F8 24020001 */  addiu     $v0, $zero, 1
/* B5CFC 8011F5FC 10820063 */  beq       $a0, $v0, .L8011F78C
/* B5D00 8011F600 27A40010 */   addiu    $a0, $sp, 0x10
/* B5D04 8011F604 08047E80 */  j         .L8011FA00
/* B5D08 8011F608 00000000 */   nop      
.L8011F60C:
/* B5D0C 8011F60C 92020004 */  lbu       $v0, 4($s0)
/* B5D10 8011F610 2442FFFF */  addiu     $v0, $v0, -1
/* B5D14 8011F614 00021600 */  sll       $v0, $v0, 0x18
/* B5D18 8011F618 00021E03 */  sra       $v1, $v0, 0x18
/* B5D1C 8011F61C 2C620026 */  sltiu     $v0, $v1, 0x26
/* B5D20 8011F620 104000F6 */  beqz      $v0, .L8011F9FC
/* B5D24 8011F624 00031080 */   sll      $v0, $v1, 2
/* B5D28 8011F628 3C018015 */  lui       $at, 0x8015
/* B5D2C 8011F62C 00220821 */  addu      $at, $at, $v0
/* B5D30 8011F630 8C22FEE0 */  lw        $v0, -0x120($at)
/* B5D34 8011F634 00400008 */  jr        $v0
/* B5D38 8011F638 00000000 */   nop      
/* B5D3C 8011F63C 3C03800A */  lui       $v1, 0x800a
/* B5D40 8011F640 2463A66C */  addiu     $v1, $v1, -0x5994
/* B5D44 8011F644 8C620000 */  lw        $v0, ($v1)
/* B5D48 8011F648 0040202D */  daddu     $a0, $v0, $zero
/* B5D4C 8011F64C 24420008 */  addiu     $v0, $v0, 8
/* B5D50 8011F650 AC620000 */  sw        $v0, ($v1)
/* B5D54 8011F654 3C02DE00 */  lui       $v0, 0xde00
/* B5D58 8011F658 AC820000 */  sw        $v0, ($a0)
/* B5D5C 8011F65C 3C028015 */  lui       $v0, 0x8015
/* B5D60 8011F660 2442B7F8 */  addiu     $v0, $v0, -0x4808
/* B5D64 8011F664 08047E7F */  j         .L8011F9FC
/* B5D68 8011F668 AC820004 */   sw       $v0, 4($a0)
/* B5D6C 8011F66C 3C03800A */  lui       $v1, 0x800a
/* B5D70 8011F670 2463A66C */  addiu     $v1, $v1, -0x5994
/* B5D74 8011F674 8C620000 */  lw        $v0, ($v1)
/* B5D78 8011F678 0040202D */  daddu     $a0, $v0, $zero
/* B5D7C 8011F67C 24420008 */  addiu     $v0, $v0, 8
/* B5D80 8011F680 AC620000 */  sw        $v0, ($v1)
/* B5D84 8011F684 3C02DE00 */  lui       $v0, 0xde00
/* B5D88 8011F688 AC820000 */  sw        $v0, ($a0)
/* B5D8C 8011F68C 3C028015 */  lui       $v0, 0x8015
/* B5D90 8011F690 2442B820 */  addiu     $v0, $v0, -0x47e0
/* B5D94 8011F694 08047E7F */  j         .L8011F9FC
/* B5D98 8011F698 AC820004 */   sw       $v0, 4($a0)
/* B5D9C 8011F69C 3C03800A */  lui       $v1, 0x800a
/* B5DA0 8011F6A0 2463A66C */  addiu     $v1, $v1, -0x5994
/* B5DA4 8011F6A4 8C620000 */  lw        $v0, ($v1)
/* B5DA8 8011F6A8 0040202D */  daddu     $a0, $v0, $zero
/* B5DAC 8011F6AC 24420008 */  addiu     $v0, $v0, 8
/* B5DB0 8011F6B0 AC620000 */  sw        $v0, ($v1)
/* B5DB4 8011F6B4 3C02DE00 */  lui       $v0, 0xde00
/* B5DB8 8011F6B8 AC820000 */  sw        $v0, ($a0)
/* B5DBC 8011F6BC 3C028015 */  lui       $v0, 0x8015
/* B5DC0 8011F6C0 2442B848 */  addiu     $v0, $v0, -0x47b8
/* B5DC4 8011F6C4 08047E7F */  j         .L8011F9FC
/* B5DC8 8011F6C8 AC820004 */   sw       $v0, 4($a0)
/* B5DCC 8011F6CC 3C03800A */  lui       $v1, 0x800a
/* B5DD0 8011F6D0 2463A66C */  addiu     $v1, $v1, -0x5994
/* B5DD4 8011F6D4 8C620000 */  lw        $v0, ($v1)
/* B5DD8 8011F6D8 0040202D */  daddu     $a0, $v0, $zero
/* B5DDC 8011F6DC 24420008 */  addiu     $v0, $v0, 8
/* B5DE0 8011F6E0 AC620000 */  sw        $v0, ($v1)
/* B5DE4 8011F6E4 3C02DE00 */  lui       $v0, 0xde00
/* B5DE8 8011F6E8 AC820000 */  sw        $v0, ($a0)
/* B5DEC 8011F6EC 3C028015 */  lui       $v0, 0x8015
/* B5DF0 8011F6F0 2442B870 */  addiu     $v0, $v0, -0x4790
/* B5DF4 8011F6F4 08047E7F */  j         .L8011F9FC
/* B5DF8 8011F6F8 AC820004 */   sw       $v0, 4($a0)
/* B5DFC 8011F6FC 3C03800A */  lui       $v1, 0x800a
/* B5E00 8011F700 2463A66C */  addiu     $v1, $v1, -0x5994
/* B5E04 8011F704 8C620000 */  lw        $v0, ($v1)
/* B5E08 8011F708 0040202D */  daddu     $a0, $v0, $zero
/* B5E0C 8011F70C 24420008 */  addiu     $v0, $v0, 8
/* B5E10 8011F710 AC620000 */  sw        $v0, ($v1)
/* B5E14 8011F714 3C02DE00 */  lui       $v0, 0xde00
/* B5E18 8011F718 AC820000 */  sw        $v0, ($a0)
/* B5E1C 8011F71C 3C028015 */  lui       $v0, 0x8015
/* B5E20 8011F720 2442B898 */  addiu     $v0, $v0, -0x4768
/* B5E24 8011F724 08047E7F */  j         .L8011F9FC
/* B5E28 8011F728 AC820004 */   sw       $v0, 4($a0)
/* B5E2C 8011F72C 3C03800A */  lui       $v1, 0x800a
/* B5E30 8011F730 2463A66C */  addiu     $v1, $v1, -0x5994
/* B5E34 8011F734 8C620000 */  lw        $v0, ($v1)
/* B5E38 8011F738 0040202D */  daddu     $a0, $v0, $zero
/* B5E3C 8011F73C 24420008 */  addiu     $v0, $v0, 8
/* B5E40 8011F740 AC620000 */  sw        $v0, ($v1)
/* B5E44 8011F744 3C02DE00 */  lui       $v0, 0xde00
/* B5E48 8011F748 AC820000 */  sw        $v0, ($a0)
/* B5E4C 8011F74C 3C028015 */  lui       $v0, 0x8015
/* B5E50 8011F750 2442B8C0 */  addiu     $v0, $v0, -0x4740
/* B5E54 8011F754 08047E7F */  j         .L8011F9FC
/* B5E58 8011F758 AC820004 */   sw       $v0, 4($a0)
/* B5E5C 8011F75C 3C03800A */  lui       $v1, 0x800a
/* B5E60 8011F760 2463A66C */  addiu     $v1, $v1, -0x5994
/* B5E64 8011F764 8C620000 */  lw        $v0, ($v1)
/* B5E68 8011F768 0040202D */  daddu     $a0, $v0, $zero
/* B5E6C 8011F76C 24420008 */  addiu     $v0, $v0, 8
/* B5E70 8011F770 AC620000 */  sw        $v0, ($v1)
/* B5E74 8011F774 3C02DE00 */  lui       $v0, 0xde00
/* B5E78 8011F778 AC820000 */  sw        $v0, ($a0)
/* B5E7C 8011F77C 3C028015 */  lui       $v0, 0x8015
/* B5E80 8011F780 2442B8E8 */  addiu     $v0, $v0, -0x4718
/* B5E84 8011F784 08047E7F */  j         .L8011F9FC
/* B5E88 8011F788 AC820004 */   sw       $v0, 4($a0)
.L8011F78C:
/* B5E8C 8011F78C 92020004 */  lbu       $v0, 4($s0)
/* B5E90 8011F790 2442FFFF */  addiu     $v0, $v0, -1
/* B5E94 8011F794 00021600 */  sll       $v0, $v0, 0x18
/* B5E98 8011F798 00021E03 */  sra       $v1, $v0, 0x18
/* B5E9C 8011F79C 2C620026 */  sltiu     $v0, $v1, 0x26
/* B5EA0 8011F7A0 10400059 */  beqz      $v0, .L8011F908
/* B5EA4 8011F7A4 00031080 */   sll      $v0, $v1, 2
/* B5EA8 8011F7A8 3C018015 */  lui       $at, 0x8015
/* B5EAC 8011F7AC 00220821 */  addu      $at, $at, $v0
/* B5EB0 8011F7B0 8C22FF78 */  lw        $v0, -0x88($at)
/* B5EB4 8011F7B4 00400008 */  jr        $v0
/* B5EB8 8011F7B8 00000000 */   nop      
/* B5EBC 8011F7BC 3C03800A */  lui       $v1, 0x800a
/* B5EC0 8011F7C0 2463A66C */  addiu     $v1, $v1, -0x5994
/* B5EC4 8011F7C4 8C620000 */  lw        $v0, ($v1)
/* B5EC8 8011F7C8 0040202D */  daddu     $a0, $v0, $zero
/* B5ECC 8011F7CC 24420008 */  addiu     $v0, $v0, 8
/* B5ED0 8011F7D0 AC620000 */  sw        $v0, ($v1)
/* B5ED4 8011F7D4 3C02DE00 */  lui       $v0, 0xde00
/* B5ED8 8011F7D8 AC820000 */  sw        $v0, ($a0)
/* B5EDC 8011F7DC 3C028015 */  lui       $v0, 0x8015
/* B5EE0 8011F7E0 2442BE78 */  addiu     $v0, $v0, -0x4188
/* B5EE4 8011F7E4 08047E42 */  j         .L8011F908
/* B5EE8 8011F7E8 AC820004 */   sw       $v0, 4($a0)
/* B5EEC 8011F7EC 3C03800A */  lui       $v1, 0x800a
/* B5EF0 8011F7F0 2463A66C */  addiu     $v1, $v1, -0x5994
/* B5EF4 8011F7F4 8C620000 */  lw        $v0, ($v1)
/* B5EF8 8011F7F8 0040202D */  daddu     $a0, $v0, $zero
/* B5EFC 8011F7FC 24420008 */  addiu     $v0, $v0, 8
/* B5F00 8011F800 AC620000 */  sw        $v0, ($v1)
/* B5F04 8011F804 3C02DE00 */  lui       $v0, 0xde00
/* B5F08 8011F808 AC820000 */  sw        $v0, ($a0)
/* B5F0C 8011F80C 3C028015 */  lui       $v0, 0x8015
/* B5F10 8011F810 2442BEA0 */  addiu     $v0, $v0, -0x4160
/* B5F14 8011F814 08047E42 */  j         .L8011F908
/* B5F18 8011F818 AC820004 */   sw       $v0, 4($a0)
/* B5F1C 8011F81C 3C03800A */  lui       $v1, 0x800a
/* B5F20 8011F820 2463A66C */  addiu     $v1, $v1, -0x5994
/* B5F24 8011F824 8C620000 */  lw        $v0, ($v1)
/* B5F28 8011F828 0040202D */  daddu     $a0, $v0, $zero
/* B5F2C 8011F82C 24420008 */  addiu     $v0, $v0, 8
/* B5F30 8011F830 AC620000 */  sw        $v0, ($v1)
/* B5F34 8011F834 3C02DE00 */  lui       $v0, 0xde00
/* B5F38 8011F838 AC820000 */  sw        $v0, ($a0)
/* B5F3C 8011F83C 3C028015 */  lui       $v0, 0x8015
/* B5F40 8011F840 2442BEC8 */  addiu     $v0, $v0, -0x4138
/* B5F44 8011F844 08047E42 */  j         .L8011F908
/* B5F48 8011F848 AC820004 */   sw       $v0, 4($a0)
/* B5F4C 8011F84C 3C03800A */  lui       $v1, 0x800a
/* B5F50 8011F850 2463A66C */  addiu     $v1, $v1, -0x5994
/* B5F54 8011F854 8C620000 */  lw        $v0, ($v1)
/* B5F58 8011F858 0040202D */  daddu     $a0, $v0, $zero
/* B5F5C 8011F85C 24420008 */  addiu     $v0, $v0, 8
/* B5F60 8011F860 AC620000 */  sw        $v0, ($v1)
/* B5F64 8011F864 3C02DE00 */  lui       $v0, 0xde00
/* B5F68 8011F868 AC820000 */  sw        $v0, ($a0)
/* B5F6C 8011F86C 3C028015 */  lui       $v0, 0x8015
/* B5F70 8011F870 2442BEF0 */  addiu     $v0, $v0, -0x4110
/* B5F74 8011F874 08047E42 */  j         .L8011F908
/* B5F78 8011F878 AC820004 */   sw       $v0, 4($a0)
/* B5F7C 8011F87C 3C03800A */  lui       $v1, 0x800a
/* B5F80 8011F880 2463A66C */  addiu     $v1, $v1, -0x5994
/* B5F84 8011F884 8C620000 */  lw        $v0, ($v1)
/* B5F88 8011F888 0040202D */  daddu     $a0, $v0, $zero
/* B5F8C 8011F88C 24420008 */  addiu     $v0, $v0, 8
/* B5F90 8011F890 AC620000 */  sw        $v0, ($v1)
/* B5F94 8011F894 3C02DE00 */  lui       $v0, 0xde00
/* B5F98 8011F898 AC820000 */  sw        $v0, ($a0)
/* B5F9C 8011F89C 3C028015 */  lui       $v0, 0x8015
/* B5FA0 8011F8A0 2442BF18 */  addiu     $v0, $v0, -0x40e8
/* B5FA4 8011F8A4 08047E42 */  j         .L8011F908
/* B5FA8 8011F8A8 AC820004 */   sw       $v0, 4($a0)
/* B5FAC 8011F8AC 3C03800A */  lui       $v1, 0x800a
/* B5FB0 8011F8B0 2463A66C */  addiu     $v1, $v1, -0x5994
/* B5FB4 8011F8B4 8C620000 */  lw        $v0, ($v1)
/* B5FB8 8011F8B8 0040202D */  daddu     $a0, $v0, $zero
/* B5FBC 8011F8BC 24420008 */  addiu     $v0, $v0, 8
/* B5FC0 8011F8C0 AC620000 */  sw        $v0, ($v1)
/* B5FC4 8011F8C4 3C02DE00 */  lui       $v0, 0xde00
/* B5FC8 8011F8C8 AC820000 */  sw        $v0, ($a0)
/* B5FCC 8011F8CC 3C028015 */  lui       $v0, 0x8015
/* B5FD0 8011F8D0 2442BF40 */  addiu     $v0, $v0, -0x40c0
/* B5FD4 8011F8D4 08047E42 */  j         .L8011F908
/* B5FD8 8011F8D8 AC820004 */   sw       $v0, 4($a0)
/* B5FDC 8011F8DC 3C03800A */  lui       $v1, 0x800a
/* B5FE0 8011F8E0 2463A66C */  addiu     $v1, $v1, -0x5994
/* B5FE4 8011F8E4 8C620000 */  lw        $v0, ($v1)
/* B5FE8 8011F8E8 0040202D */  daddu     $a0, $v0, $zero
/* B5FEC 8011F8EC 24420008 */  addiu     $v0, $v0, 8
/* B5FF0 8011F8F0 AC620000 */  sw        $v0, ($v1)
/* B5FF4 8011F8F4 3C02DE00 */  lui       $v0, 0xde00
/* B5FF8 8011F8F8 AC820000 */  sw        $v0, ($a0)
/* B5FFC 8011F8FC 3C028015 */  lui       $v0, 0x8015
/* B6000 8011F900 2442BF68 */  addiu     $v0, $v0, -0x4098
/* B6004 8011F904 AC820004 */  sw        $v0, 4($a0)
.L8011F908:
/* B6008 8011F908 3C070001 */  lui       $a3, 1
/* B600C 8011F90C 3C028015 */  lui       $v0, 0x8015
/* B6010 8011F910 8C423A5C */  lw        $v0, 0x3a5c($v0)
/* B6014 8011F914 3C038015 */  lui       $v1, 0x8015
/* B6018 8011F918 8C633A58 */  lw        $v1, 0x3a58($v1)
/* B601C 8011F91C 34E7F400 */  ori       $a3, $a3, 0xf400
/* B6020 8011F920 00431023 */  subu      $v0, $v0, $v1
/* B6024 8011F924 14400002 */  bnez      $v0, .L8011F930
/* B6028 8011F928 00E2001A */   div      $zero, $a3, $v0
/* B602C 8011F92C 0007000D */  break     7
.L8011F930:
/* B6030 8011F930 2401FFFF */   addiu    $at, $zero, -1
/* B6034 8011F934 14410004 */  bne       $v0, $at, .L8011F948
/* B6038 8011F938 3C018000 */   lui      $at, 0x8000
/* B603C 8011F93C 14E10002 */  bne       $a3, $at, .L8011F948
/* B6040 8011F940 00000000 */   nop      
/* B6044 8011F944 0006000D */  break     6
.L8011F948:
/* B6048 8011F948 00003812 */   mflo     $a3
/* B604C 8011F94C 240501F4 */  addiu     $a1, $zero, 0x1f4
/* B6050 8011F950 00A32823 */  subu      $a1, $a1, $v1
/* B6054 8011F954 00052A00 */  sll       $a1, $a1, 8
/* B6058 8011F958 14400002 */  bnez      $v0, .L8011F964
/* B605C 8011F95C 00A2001A */   div      $zero, $a1, $v0
/* B6060 8011F960 0007000D */  break     7
.L8011F964:
/* B6064 8011F964 2401FFFF */   addiu    $at, $zero, -1
/* B6068 8011F968 14410004 */  bne       $v0, $at, .L8011F97C
/* B606C 8011F96C 3C018000 */   lui      $at, 0x8000
/* B6070 8011F970 14A10002 */  bne       $a1, $at, .L8011F97C
/* B6074 8011F974 00000000 */   nop      
/* B6078 8011F978 0006000D */  break     6
.L8011F97C:
/* B607C 8011F97C 00002812 */   mflo     $a1
/* B6080 8011F980 3C08800A */  lui       $t0, 0x800a
/* B6084 8011F984 2508A66C */  addiu     $t0, $t0, -0x5994
/* B6088 8011F988 8D060000 */  lw        $a2, ($t0)
/* B608C 8011F98C 00C0482D */  daddu     $t1, $a2, $zero
/* B6090 8011F990 24C60008 */  addiu     $a2, $a2, 8
/* B6094 8011F994 3C02F800 */  lui       $v0, 0xf800
/* B6098 8011F998 AD060000 */  sw        $a2, ($t0)
/* B609C 8011F99C AD220000 */  sw        $v0, ($t1)
/* B60A0 8011F9A0 3C028015 */  lui       $v0, 0x8015
/* B60A4 8011F9A4 90423A4B */  lbu       $v0, 0x3a4b($v0)
/* B60A8 8011F9A8 3C038015 */  lui       $v1, 0x8015
/* B60AC 8011F9AC 90633A4F */  lbu       $v1, 0x3a4f($v1)
/* B60B0 8011F9B0 3C048015 */  lui       $a0, 0x8015
/* B60B4 8011F9B4 90843A53 */  lbu       $a0, 0x3a53($a0)
/* B60B8 8011F9B8 00021600 */  sll       $v0, $v0, 0x18
/* B60BC 8011F9BC 00031C00 */  sll       $v1, $v1, 0x10
/* B60C0 8011F9C0 00431025 */  or        $v0, $v0, $v1
/* B60C4 8011F9C4 00042200 */  sll       $a0, $a0, 8
/* B60C8 8011F9C8 3C038015 */  lui       $v1, 0x8015
/* B60CC 8011F9CC 90633A57 */  lbu       $v1, 0x3a57($v1)
/* B60D0 8011F9D0 00441025 */  or        $v0, $v0, $a0
/* B60D4 8011F9D4 00431025 */  or        $v0, $v0, $v1
/* B60D8 8011F9D8 AD220004 */  sw        $v0, 4($t1)
/* B60DC 8011F9DC 24C20008 */  addiu     $v0, $a2, 8
/* B60E0 8011F9E0 AD020000 */  sw        $v0, ($t0)
/* B60E4 8011F9E4 3C02DB08 */  lui       $v0, 0xdb08
/* B60E8 8011F9E8 ACC20000 */  sw        $v0, ($a2)
/* B60EC 8011F9EC 00073C00 */  sll       $a3, $a3, 0x10
/* B60F0 8011F9F0 30A5FFFF */  andi      $a1, $a1, 0xffff
/* B60F4 8011F9F4 00E53825 */  or        $a3, $a3, $a1
/* B60F8 8011F9F8 ACC70004 */  sw        $a3, 4($a2)
.L8011F9FC:
/* B60FC 8011F9FC 27A40010 */  addiu     $a0, $sp, 0x10
.L8011FA00:
/* B6100 8011FA00 0C019D60 */  jal       guMtxL2F
/* B6104 8011FA04 26050098 */   addiu    $a1, $s0, 0x98
/* B6108 8011FA08 0200202D */  daddu     $a0, $s0, $zero
/* B610C 8011FA0C 8C850010 */  lw        $a1, 0x10($a0)
/* B6110 8011FA10 0C047E95 */  jal       func_8011FA54
/* B6114 8011FA14 27A60010 */   addiu    $a2, $sp, 0x10
/* B6118 8011FA18 3C05D838 */  lui       $a1, 0xd838
/* B611C 8011FA1C 3C03800A */  lui       $v1, 0x800a
/* B6120 8011FA20 2463A66C */  addiu     $v1, $v1, -0x5994
/* B6124 8011FA24 8C620000 */  lw        $v0, ($v1)
/* B6128 8011FA28 34A50002 */  ori       $a1, $a1, 2
/* B612C 8011FA2C 0040202D */  daddu     $a0, $v0, $zero
/* B6130 8011FA30 24420008 */  addiu     $v0, $v0, 8
/* B6134 8011FA34 AC620000 */  sw        $v0, ($v1)
/* B6138 8011FA38 24020040 */  addiu     $v0, $zero, 0x40
/* B613C 8011FA3C AC850000 */  sw        $a1, ($a0)
/* B6140 8011FA40 AC820004 */  sw        $v0, 4($a0)
/* B6144 8011FA44 8FBF0054 */  lw        $ra, 0x54($sp)
/* B6148 8011FA48 8FB00050 */  lw        $s0, 0x50($sp)
/* B614C 8011FA4C 03E00008 */  jr        $ra
/* B6150 8011FA50 27BD0058 */   addiu    $sp, $sp, 0x58
