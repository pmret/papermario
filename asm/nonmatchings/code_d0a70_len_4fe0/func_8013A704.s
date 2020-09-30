.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013A704
/* D0E04 8013A704 3C028015 */  lui       $v0, 0x8015
/* D0E08 8013A708 8C426954 */  lw        $v0, 0x6954($v0)
/* D0E0C 8013A70C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D0E10 8013A710 AFB60028 */  sw        $s6, 0x28($sp)
/* D0E14 8013A714 0080B02D */  daddu     $s6, $a0, $zero
/* D0E18 8013A718 AFB20018 */  sw        $s2, 0x18($sp)
/* D0E1C 8013A71C 0000902D */  daddu     $s2, $zero, $zero
/* D0E20 8013A720 AFB00010 */  sw        $s0, 0x10($sp)
/* D0E24 8013A724 24100001 */  addiu     $s0, $zero, 1
/* D0E28 8013A728 AFBF002C */  sw        $ra, 0x2c($sp)
/* D0E2C 8013A72C AFB50024 */  sw        $s5, 0x24($sp)
/* D0E30 8013A730 AFB40020 */  sw        $s4, 0x20($sp)
/* D0E34 8013A734 AFB3001C */  sw        $s3, 0x1c($sp)
/* D0E38 8013A738 AFB10014 */  sw        $s1, 0x14($sp)
/* D0E3C 8013A73C 2443007C */  addiu     $v1, $v0, 0x7c
.L8013A740:
/* D0E40 8013A740 8C620014 */  lw        $v0, 0x14($v1)
/* D0E44 8013A744 30420001 */  andi      $v0, $v0, 1
/* D0E48 8013A748 50400001 */  beql      $v0, $zero, .L8013A750
/* D0E4C 8013A74C 26520001 */   addiu    $s2, $s2, 1
.L8013A750:
/* D0E50 8013A750 26100001 */  addiu     $s0, $s0, 1
/* D0E54 8013A754 2A02005A */  slti      $v0, $s0, 0x5a
/* D0E58 8013A758 1440FFF9 */  bnez      $v0, .L8013A740
/* D0E5C 8013A75C 2463007C */   addiu    $v1, $v1, 0x7c
/* D0E60 8013A760 0256102A */  slt       $v0, $s2, $s6
/* D0E64 8013A764 10400006 */  beqz      $v0, .L8013A780
/* D0E68 8013A768 2402FFFF */   addiu    $v0, $zero, -1
/* D0E6C 8013A76C 0804EA0B */  j         .L8013A82C
/* D0E70 8013A770 00000000 */   nop      
.L8013A774:
/* D0E74 8013A774 2402FFFF */  addiu     $v0, $zero, -1
/* D0E78 8013A778 0804EA0A */  j         .L8013A828
/* D0E7C 8013A77C A4620010 */   sh       $v0, 0x10($v1)
.L8013A780:
/* D0E80 8013A780 0000A82D */  daddu     $s5, $zero, $zero
/* D0E84 8013A784 02A0982D */  daddu     $s3, $s5, $zero
/* D0E88 8013A788 02A0902D */  daddu     $s2, $s5, $zero
/* D0E8C 8013A78C 2404FFFF */  addiu     $a0, $zero, -1
/* D0E90 8013A790 24100001 */  addiu     $s0, $zero, 1
/* D0E94 8013A794 3C148015 */  lui       $s4, 0x8015
/* D0E98 8013A798 26946954 */  addiu     $s4, $s4, 0x6954
/* D0E9C 8013A79C 2411007C */  addiu     $s1, $zero, 0x7c
.L8013A7A0:
/* D0EA0 8013A7A0 3C038015 */  lui       $v1, 0x8015
/* D0EA4 8013A7A4 8C636954 */  lw        $v1, 0x6954($v1)
/* D0EA8 8013A7A8 02231021 */  addu      $v0, $s1, $v1
/* D0EAC 8013A7AC 8C420014 */  lw        $v0, 0x14($v0)
/* D0EB0 8013A7B0 30420001 */  andi      $v0, $v0, 1
/* D0EB4 8013A7B4 54400019 */  bnel      $v0, $zero, .L8013A81C
/* D0EB8 8013A7B8 26100001 */   addiu    $s0, $s0, 1
/* D0EBC 8013A7BC 16600004 */  bnez      $s3, .L8013A7D0
/* D0EC0 8013A7C0 00041140 */   sll      $v0, $a0, 5
/* D0EC4 8013A7C4 0200A82D */  daddu     $s5, $s0, $zero
/* D0EC8 8013A7C8 0804E9F8 */  j         .L8013A7E0
/* D0ECC 8013A7CC 24130001 */   addiu    $s3, $zero, 1
.L8013A7D0:
/* D0ED0 8013A7D0 00441023 */  subu      $v0, $v0, $a0
/* D0ED4 8013A7D4 00021080 */  sll       $v0, $v0, 2
/* D0ED8 8013A7D8 00431021 */  addu      $v0, $v0, $v1
/* D0EDC 8013A7DC A4500010 */  sh        $s0, 0x10($v0)
.L8013A7E0:
/* D0EE0 8013A7E0 8E820000 */  lw        $v0, ($s4)
/* D0EE4 8013A7E4 02221021 */  addu      $v0, $s1, $v0
/* D0EE8 8013A7E8 A0500000 */  sb        $s0, ($v0)
/* D0EEC 8013A7EC 8E840000 */  lw        $a0, ($s4)
/* D0EF0 8013A7F0 0C04EA7A */  jal       func_8013A9E8
/* D0EF4 8013A7F4 00912021 */   addu     $a0, $a0, $s1
/* D0EF8 8013A7F8 8E820000 */  lw        $v0, ($s4)
/* D0EFC 8013A7FC 26520001 */  addiu     $s2, $s2, 1
/* D0F00 8013A800 02221821 */  addu      $v1, $s1, $v0
/* D0F04 8013A804 8C620014 */  lw        $v0, 0x14($v1)
/* D0F08 8013A808 0200202D */  daddu     $a0, $s0, $zero
/* D0F0C 8013A80C 34420001 */  ori       $v0, $v0, 1
/* D0F10 8013A810 1256FFD8 */  beq       $s2, $s6, .L8013A774
/* D0F14 8013A814 AC620014 */   sw       $v0, 0x14($v1)
/* D0F18 8013A818 26100001 */  addiu     $s0, $s0, 1
.L8013A81C:
/* D0F1C 8013A81C 2A02005A */  slti      $v0, $s0, 0x5a
/* D0F20 8013A820 1440FFDF */  bnez      $v0, .L8013A7A0
/* D0F24 8013A824 2631007C */   addiu    $s1, $s1, 0x7c
.L8013A828:
/* D0F28 8013A828 02A0102D */  daddu     $v0, $s5, $zero
.L8013A82C:
/* D0F2C 8013A82C 8FBF002C */  lw        $ra, 0x2c($sp)
/* D0F30 8013A830 8FB60028 */  lw        $s6, 0x28($sp)
/* D0F34 8013A834 8FB50024 */  lw        $s5, 0x24($sp)
/* D0F38 8013A838 8FB40020 */  lw        $s4, 0x20($sp)
/* D0F3C 8013A83C 8FB3001C */  lw        $s3, 0x1c($sp)
/* D0F40 8013A840 8FB20018 */  lw        $s2, 0x18($sp)
/* D0F44 8013A844 8FB10014 */  lw        $s1, 0x14($sp)
/* D0F48 8013A848 8FB00010 */  lw        $s0, 0x10($sp)
/* D0F4C 8013A84C 03E00008 */  jr        $ra
/* D0F50 8013A850 27BD0030 */   addiu    $sp, $sp, 0x30
