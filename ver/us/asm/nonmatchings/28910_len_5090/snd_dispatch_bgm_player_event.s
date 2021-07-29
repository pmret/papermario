.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_dispatch_bgm_player_event
/* 28BE0 8004D7E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 28BE4 8004D7E4 AFB20018 */  sw        $s2, 0x18($sp)
/* 28BE8 8004D7E8 0080902D */  daddu     $s2, $a0, $zero
/* 28BEC 8004D7EC AFB50024 */  sw        $s5, 0x24($sp)
/* 28BF0 8004D7F0 AFBF0028 */  sw        $ra, 0x28($sp)
/* 28BF4 8004D7F4 AFB40020 */  sw        $s4, 0x20($sp)
/* 28BF8 8004D7F8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 28BFC 8004D7FC AFB10014 */  sw        $s1, 0x14($sp)
/* 28C00 8004D800 AFB00010 */  sw        $s0, 0x10($sp)
/* 28C04 8004D804 8E540000 */  lw        $s4, ($s2)
/* 28C08 8004D808 8E530010 */  lw        $s3, 0x10($s2)
/* 28C0C 8004D80C 12800074 */  beqz      $s4, .L8004D9E0
/* 28C10 8004D810 0000A82D */   daddu    $s5, $zero, $zero
/* 28C14 8004D814 0C0135E5 */  jal       snd_get_player_with_song_name
/* 28C18 8004D818 0280202D */   daddu    $a0, $s4, $zero
/* 28C1C 8004D81C 0040802D */  daddu     $s0, $v0, $zero
/* 28C20 8004D820 52000070 */  beql      $s0, $zero, .L8004D9E4
/* 28C24 8004D824 24150002 */   addiu    $s5, $zero, 2
/* 28C28 8004D828 8E020064 */  lw        $v0, 0x64($s0)
/* 28C2C 8004D82C 8E450004 */  lw        $a1, 4($s2)
/* 28C30 8004D830 10A00008 */  beqz      $a1, .L8004D854
/* 28C34 8004D834 24510010 */   addiu    $s1, $v0, 0x10
/* 28C38 8004D838 28A22711 */  slti      $v0, $a1, 0x2711
/* 28C3C 8004D83C 14400003 */  bnez      $v0, .L8004D84C
/* 28C40 8004D840 28A200FA */   slti     $v0, $a1, 0xfa
/* 28C44 8004D844 08013615 */  j         .L8004D854
/* 28C48 8004D848 24052710 */   addiu    $a1, $zero, 0x2710
.L8004D84C:
/* 28C4C 8004D84C 54400001 */  bnel      $v0, $zero, .L8004D854
/* 28C50 8004D850 240500FA */   addiu    $a1, $zero, 0xfa
.L8004D854:
/* 28C54 8004D854 8E460008 */  lw        $a2, 8($s2)
/* 28C58 8004D858 28C20080 */  slti      $v0, $a2, 0x80
/* 28C5C 8004D85C 50400001 */  beql      $v0, $zero, .L8004D864
/* 28C60 8004D860 2406007F */   addiu    $a2, $zero, 0x7f
.L8004D864:
/* 28C64 8004D864 10C00002 */  beqz      $a2, .L8004D870
/* 28C68 8004D868 00061200 */   sll      $v0, $a2, 8
/* 28C6C 8004D86C 344600FF */  ori       $a2, $v0, 0xff
.L8004D870:
/* 28C70 8004D870 8E47000C */  lw        $a3, 0xc($s2)
/* 28C74 8004D874 28E20080 */  slti      $v0, $a3, 0x80
/* 28C78 8004D878 50400001 */  beql      $v0, $zero, .L8004D880
/* 28C7C 8004D87C 2407007F */   addiu    $a3, $zero, 0x7f
.L8004D880:
/* 28C80 8004D880 10E00003 */  beqz      $a3, .L8004D890
/* 28C84 8004D884 00071200 */   sll      $v0, $a3, 8
/* 28C88 8004D888 08013625 */  j         .L8004D894
/* 28C8C 8004D88C 344700FF */   ori      $a3, $v0, 0xff
.L8004D890:
/* 28C90 8004D890 24077FFF */  addiu     $a3, $zero, 0x7fff
.L8004D894:
/* 28C94 8004D894 0C014E5D */  jal       snd_initialize_bgm_fade
/* 28C98 8004D898 2604002C */   addiu    $a0, $s0, 0x2c
/* 28C9C 8004D89C 0200202D */  daddu     $a0, $s0, $zero
/* 28CA0 8004D8A0 24027FFF */  addiu     $v0, $zero, 0x7fff
/* 28CA4 8004D8A4 A6020044 */  sh        $v0, 0x44($s0)
/* 28CA8 8004D8A8 24020001 */  addiu     $v0, $zero, 1
/* 28CAC 8004D8AC A6020046 */  sh        $v0, 0x46($s0)
/* 28CB0 8004D8B0 92220000 */  lbu       $v0, ($s1)
/* 28CB4 8004D8B4 3C050002 */  lui       $a1, 2
/* 28CB8 8004D8B8 30420007 */  andi      $v0, $v0, 7
/* 28CBC 8004D8BC 3C068008 */  lui       $a2, %hi(D_80078510)
/* 28CC0 8004D8C0 00C23021 */  addu      $a2, $a2, $v0
/* 28CC4 8004D8C4 90C68510 */  lbu       $a2, %lo(D_80078510)($a2)
/* 28CC8 8004D8C8 0C013A20 */  jal       func_8004E880
/* 28CCC 8004D8CC 34A5625A */   ori      $a1, $a1, 0x625a
/* 28CD0 8004D8D0 2E620004 */  sltiu     $v0, $s3, 4
/* 28CD4 8004D8D4 10400005 */  beqz      $v0, .L8004D8EC
/* 28CD8 8004D8D8 00131040 */   sll      $v0, $s3, 1
/* 28CDC 8004D8DC 02221021 */  addu      $v0, $s1, $v0
/* 28CE0 8004D8E0 94420004 */  lhu       $v0, 4($v0)
/* 28CE4 8004D8E4 14400003 */  bnez      $v0, .L8004D8F4
/* 28CE8 8004D8E8 00131040 */   sll      $v0, $s3, 1
.L8004D8EC:
/* 28CEC 8004D8EC 0000982D */  daddu     $s3, $zero, $zero
/* 28CF0 8004D8F0 00131040 */  sll       $v0, $s3, 1
.L8004D8F4:
/* 28CF4 8004D8F4 02221021 */  addu      $v0, $s1, $v0
/* 28CF8 8004D8F8 AE130060 */  sw        $s3, 0x60($s0)
/* 28CFC 8004D8FC 94420004 */  lhu       $v0, 4($v0)
/* 28D00 8004D900 8E030064 */  lw        $v1, 0x64($s0)
/* 28D04 8004D904 00021080 */  sll       $v0, $v0, 2
/* 28D08 8004D908 00431021 */  addu      $v0, $v0, $v1
/* 28D0C 8004D90C AE02006C */  sw        $v0, 0x6c($s0)
/* 28D10 8004D910 AE020068 */  sw        $v0, 0x68($s0)
/* 28D14 8004D914 9622000C */  lhu       $v0, 0xc($s1)
/* 28D18 8004D918 1040001F */  beqz      $v0, .L8004D998
/* 28D1C 8004D91C 00021080 */   sll      $v0, $v0, 2
/* 28D20 8004D920 00431021 */  addu      $v0, $v0, $v1
/* 28D24 8004D924 AE020078 */  sw        $v0, 0x78($s0)
/* 28D28 8004D928 9222000F */  lbu       $v0, 0xf($s1)
/* 28D2C 8004D92C A202021C */  sb        $v0, 0x21c($s0)
/* 28D30 8004D930 304200FF */  andi      $v0, $v0, 0xff
/* 28D34 8004D934 1040000C */  beqz      $v0, .L8004D968
/* 28D38 8004D938 0000182D */   daddu    $v1, $zero, $zero
/* 28D3C 8004D93C 0200282D */  daddu     $a1, $s0, $zero
/* 28D40 8004D940 0060202D */  daddu     $a0, $v1, $zero
.L8004D944:
/* 28D44 8004D944 8E020078 */  lw        $v0, 0x78($s0)
/* 28D48 8004D948 24630001 */  addiu     $v1, $v1, 1
/* 28D4C 8004D94C 00441021 */  addu      $v0, $v0, $a0
/* 28D50 8004D950 ACA20080 */  sw        $v0, 0x80($a1)
/* 28D54 8004D954 24A50004 */  addiu     $a1, $a1, 4
/* 28D58 8004D958 9202021C */  lbu       $v0, 0x21c($s0)
/* 28D5C 8004D95C 0062102B */  sltu      $v0, $v1, $v0
/* 28D60 8004D960 1440FFF8 */  bnez      $v0, .L8004D944
/* 28D64 8004D964 2484000C */   addiu    $a0, $a0, 0xc
.L8004D968:
/* 28D68 8004D968 2C62000C */  sltiu     $v0, $v1, 0xc
/* 28D6C 8004D96C 1040000C */  beqz      $v0, .L8004D9A0
/* 28D70 8004D970 00031080 */   sll      $v0, $v1, 2
/* 28D74 8004D974 00502021 */  addu      $a0, $v0, $s0
.L8004D978:
/* 28D78 8004D978 8E020080 */  lw        $v0, 0x80($s0)
/* 28D7C 8004D97C 24630001 */  addiu     $v1, $v1, 1
/* 28D80 8004D980 AC820080 */  sw        $v0, 0x80($a0)
/* 28D84 8004D984 2C62000C */  sltiu     $v0, $v1, 0xc
/* 28D88 8004D988 1440FFFB */  bnez      $v0, .L8004D978
/* 28D8C 8004D98C 24840004 */   addiu    $a0, $a0, 4
/* 28D90 8004D990 08013668 */  j         .L8004D9A0
/* 28D94 8004D994 00000000 */   nop
.L8004D998:
/* 28D98 8004D998 AE000078 */  sw        $zero, 0x78($s0)
/* 28D9C 8004D99C A200021C */  sb        $zero, 0x21c($s0)
.L8004D9A0:
/* 28DA0 8004D9A0 96220010 */  lhu       $v0, 0x10($s1)
/* 28DA4 8004D9A4 10400007 */  beqz      $v0, .L8004D9C4
/* 28DA8 8004D9A8 00021080 */   sll      $v0, $v0, 2
/* 28DAC 8004D9AC 8E030064 */  lw        $v1, 0x64($s0)
/* 28DB0 8004D9B0 00431021 */  addu      $v0, $v0, $v1
/* 28DB4 8004D9B4 AE02007C */  sw        $v0, 0x7c($s0)
/* 28DB8 8004D9B8 92220013 */  lbu       $v0, 0x13($s1)
/* 28DBC 8004D9BC 08013673 */  j         .L8004D9CC
/* 28DC0 8004D9C0 A202021D */   sb       $v0, 0x21d($s0)
.L8004D9C4:
/* 28DC4 8004D9C4 AE00007C */  sw        $zero, 0x7c($s0)
/* 28DC8 8004D9C8 A200021D */  sb        $zero, 0x21d($s0)
.L8004D9CC:
/* 28DCC 8004D9CC AE14001C */  sw        $s4, 0x1c($s0)
/* 28DD0 8004D9D0 0C013976 */  jal       snd_initialize_bgm_player
/* 28DD4 8004D9D4 0200202D */   daddu    $a0, $s0, $zero
/* 28DD8 8004D9D8 0801367A */  j         .L8004D9E8
/* 28DDC 8004D9DC 02A0102D */   daddu    $v0, $s5, $zero
.L8004D9E0:
/* 28DE0 8004D9E0 24150003 */  addiu     $s5, $zero, 3
.L8004D9E4:
/* 28DE4 8004D9E4 02A0102D */  daddu     $v0, $s5, $zero
.L8004D9E8:
/* 28DE8 8004D9E8 8FBF0028 */  lw        $ra, 0x28($sp)
/* 28DEC 8004D9EC 8FB50024 */  lw        $s5, 0x24($sp)
/* 28DF0 8004D9F0 8FB40020 */  lw        $s4, 0x20($sp)
/* 28DF4 8004D9F4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 28DF8 8004D9F8 8FB20018 */  lw        $s2, 0x18($sp)
/* 28DFC 8004D9FC 8FB10014 */  lw        $s1, 0x14($sp)
/* 28E00 8004DA00 8FB00010 */  lw        $s0, 0x10($sp)
/* 28E04 8004DA04 03E00008 */  jr        $ra
/* 28E08 8004DA08 27BD0030 */   addiu    $sp, $sp, 0x30
