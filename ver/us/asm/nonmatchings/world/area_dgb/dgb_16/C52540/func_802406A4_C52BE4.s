.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406A4_C52BE4
/* C52BE4 802406A4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C52BE8 802406A8 AFB40048 */  sw        $s4, 0x48($sp)
/* C52BEC 802406AC 0080A02D */  daddu     $s4, $a0, $zero
/* C52BF0 802406B0 AFBF004C */  sw        $ra, 0x4c($sp)
/* C52BF4 802406B4 AFB30044 */  sw        $s3, 0x44($sp)
/* C52BF8 802406B8 AFB20040 */  sw        $s2, 0x40($sp)
/* C52BFC 802406BC AFB1003C */  sw        $s1, 0x3c($sp)
/* C52C00 802406C0 AFB00038 */  sw        $s0, 0x38($sp)
/* C52C04 802406C4 8E930148 */  lw        $s3, 0x148($s4)
/* C52C08 802406C8 00C0802D */  daddu     $s0, $a2, $zero
/* C52C0C 802406CC 86640008 */  lh        $a0, 8($s3)
/* C52C10 802406D0 0C00EABB */  jal       get_npc_unsafe
/* C52C14 802406D4 0000902D */   daddu    $s2, $zero, $zero
/* C52C18 802406D8 0C039D59 */  jal       get_player_data
/* C52C1C 802406DC 0040882D */   daddu    $s1, $v0, $zero
/* C52C20 802406E0 0200202D */  daddu     $a0, $s0, $zero
/* C52C24 802406E4 0260282D */  daddu     $a1, $s3, $zero
/* C52C28 802406E8 0000382D */  daddu     $a3, $zero, $zero
/* C52C2C 802406EC 3C0642A0 */  lui       $a2, 0x42a0
/* C52C30 802406F0 0040802D */  daddu     $s0, $v0, $zero
/* C52C34 802406F4 0C01242D */  jal       func_800490B4
/* C52C38 802406F8 AFA00010 */   sw       $zero, 0x10($sp)
/* C52C3C 802406FC 10400022 */  beqz      $v0, .L80240788
/* C52C40 80240700 00000000 */   nop
/* C52C44 80240704 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C52C48 80240708 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C52C4C 8024070C 804300B4 */  lb        $v1, 0xb4($v0)
/* C52C50 80240710 24020002 */  addiu     $v0, $zero, 2
/* C52C54 80240714 10620013 */  beq       $v1, $v0, .L80240764
/* C52C58 80240718 2402001A */   addiu    $v0, $zero, 0x1a
/* C52C5C 8024071C 10620011 */  beq       $v1, $v0, .L80240764
/* C52C60 80240720 24020003 */   addiu    $v0, $zero, 3
/* C52C64 80240724 1062000F */  beq       $v1, $v0, .L80240764
/* C52C68 80240728 2402000E */   addiu    $v0, $zero, 0xe
/* C52C6C 8024072C 1062000D */  beq       $v1, $v0, .L80240764
/* C52C70 80240730 24020010 */   addiu    $v0, $zero, 0x10
/* C52C74 80240734 1062000B */  beq       $v1, $v0, .L80240764
/* C52C78 80240738 2402000B */   addiu    $v0, $zero, 0xb
/* C52C7C 8024073C 10620009 */  beq       $v1, $v0, .L80240764
/* C52C80 80240740 2402000A */   addiu    $v0, $zero, 0xa
/* C52C84 80240744 10620007 */  beq       $v1, $v0, .L80240764
/* C52C88 80240748 24020012 */   addiu    $v0, $zero, 0x12
/* C52C8C 8024074C 10620005 */  beq       $v1, $v0, .L80240764
/* C52C90 80240750 24020013 */   addiu    $v0, $zero, 0x13
/* C52C94 80240754 10620003 */  beq       $v1, $v0, .L80240764
/* C52C98 80240758 24020025 */   addiu    $v0, $zero, 0x25
/* C52C9C 8024075C 14620002 */  bne       $v1, $v0, .L80240768
/* C52CA0 80240760 00000000 */   nop
.L80240764:
/* C52CA4 80240764 24120001 */  addiu     $s2, $zero, 1
.L80240768:
/* C52CA8 80240768 82030012 */  lb        $v1, 0x12($s0)
/* C52CAC 8024076C 24020002 */  addiu     $v0, $zero, 2
/* C52CB0 80240770 14620007 */  bne       $v1, $v0, .L80240790
/* C52CB4 80240774 24020001 */   addiu    $v0, $zero, 1
/* C52CB8 80240778 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* C52CBC 8024077C 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* C52CC0 80240780 50430002 */  beql      $v0, $v1, .L8024078C
/* C52CC4 80240784 24120001 */   addiu    $s2, $zero, 1
.L80240788:
/* C52CC8 80240788 82030012 */  lb        $v1, 0x12($s0)
.L8024078C:
/* C52CCC 8024078C 24020001 */  addiu     $v0, $zero, 1
.L80240790:
/* C52CD0 80240790 14620006 */  bne       $v1, $v0, .L802407AC
/* C52CD4 80240794 24020003 */   addiu    $v0, $zero, 3
/* C52CD8 80240798 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* C52CDC 8024079C 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* C52CE0 802407A0 14400008 */  bnez      $v0, .L802407C4
/* C52CE4 802407A4 27A40028 */   addiu    $a0, $sp, 0x28
/* C52CE8 802407A8 24020003 */  addiu     $v0, $zero, 3
.L802407AC:
/* C52CEC 802407AC 1462001B */  bne       $v1, $v0, .L8024081C
/* C52CF0 802407B0 24020002 */   addiu    $v0, $zero, 2
/* C52CF4 802407B4 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* C52CF8 802407B8 8063EBB0 */  lb        $v1, %lo(D_8010EBB0)($v1)
/* C52CFC 802407BC 14620017 */  bne       $v1, $v0, .L8024081C
/* C52D00 802407C0 27A40028 */   addiu    $a0, $sp, 0x28
.L802407C4:
/* C52D04 802407C4 27A5002C */  addiu     $a1, $sp, 0x2c
/* C52D08 802407C8 8E27000C */  lw        $a3, 0xc($s1)
/* C52D0C 802407CC C6200038 */  lwc1      $f0, 0x38($s1)
/* C52D10 802407D0 C6220040 */  lwc1      $f2, 0x40($s1)
/* C52D14 802407D4 0000302D */  daddu     $a2, $zero, $zero
/* C52D18 802407D8 E7A00028 */  swc1      $f0, 0x28($sp)
/* C52D1C 802407DC 0C00A7E7 */  jal       add_vec2D_polar
/* C52D20 802407E0 E7A2002C */   swc1     $f2, 0x2c($sp)
/* C52D24 802407E4 3C028011 */  lui       $v0, %hi(D_8010C930)
/* C52D28 802407E8 8C42C930 */  lw        $v0, %lo(D_8010C930)($v0)
/* C52D2C 802407EC C7AC0028 */  lwc1      $f12, 0x28($sp)
/* C52D30 802407F0 C7AE002C */  lwc1      $f14, 0x2c($sp)
/* C52D34 802407F4 8C460038 */  lw        $a2, 0x38($v0)
/* C52D38 802407F8 0C00A7B5 */  jal       dist2D
/* C52D3C 802407FC 8C470040 */   lw       $a3, 0x40($v0)
/* C52D40 80240800 3C0142A0 */  lui       $at, 0x42a0
/* C52D44 80240804 44811000 */  mtc1      $at, $f2
/* C52D48 80240808 00000000 */  nop
/* C52D4C 8024080C 4602003E */  c.le.s    $f0, $f2
/* C52D50 80240810 00000000 */  nop
/* C52D54 80240814 45030001 */  bc1tl     .L8024081C
/* C52D58 80240818 24120001 */   addiu    $s2, $zero, 1
.L8024081C:
/* C52D5C 8024081C 12400026 */  beqz      $s2, .L802408B8
/* C52D60 80240820 0220202D */   daddu    $a0, $s1, $zero
/* C52D64 80240824 3C05B000 */  lui       $a1, 0xb000
/* C52D68 80240828 34A5000E */  ori       $a1, $a1, 0xe
/* C52D6C 8024082C 0C012530 */  jal       func_800494C0
/* C52D70 80240830 0000302D */   daddu    $a2, $zero, $zero
/* C52D74 80240834 0000202D */  daddu     $a0, $zero, $zero
/* C52D78 80240838 0220282D */  daddu     $a1, $s1, $zero
/* C52D7C 8024083C 0000302D */  daddu     $a2, $zero, $zero
/* C52D80 80240840 862200A8 */  lh        $v0, 0xa8($s1)
/* C52D84 80240844 8E6300CC */  lw        $v1, 0xcc($s3)
/* C52D88 80240848 3C013F80 */  lui       $at, 0x3f80
/* C52D8C 8024084C 44810000 */  mtc1      $at, $f0
/* C52D90 80240850 3C014000 */  lui       $at, 0x4000
/* C52D94 80240854 44811000 */  mtc1      $at, $f2
/* C52D98 80240858 3C01C1A0 */  lui       $at, 0xc1a0
/* C52D9C 8024085C 44812000 */  mtc1      $at, $f4
/* C52DA0 80240860 44823000 */  mtc1      $v0, $f6
/* C52DA4 80240864 00000000 */  nop
/* C52DA8 80240868 468031A0 */  cvt.s.w   $f6, $f6
/* C52DAC 8024086C 44073000 */  mfc1      $a3, $f6
/* C52DB0 80240870 8C63002C */  lw        $v1, 0x2c($v1)
/* C52DB4 80240874 2402000A */  addiu     $v0, $zero, 0xa
/* C52DB8 80240878 A622008E */  sh        $v0, 0x8e($s1)
/* C52DBC 8024087C 2402000F */  addiu     $v0, $zero, 0xf
/* C52DC0 80240880 AE230028 */  sw        $v1, 0x28($s1)
/* C52DC4 80240884 AFA2001C */  sw        $v0, 0x1c($sp)
/* C52DC8 80240888 27A20030 */  addiu     $v0, $sp, 0x30
/* C52DCC 8024088C E7A00010 */  swc1      $f0, 0x10($sp)
/* C52DD0 80240890 E7A20014 */  swc1      $f2, 0x14($sp)
/* C52DD4 80240894 E7A40018 */  swc1      $f4, 0x18($sp)
/* C52DD8 80240898 0C01BFA4 */  jal       fx_emote
/* C52DDC 8024089C AFA20020 */   sw       $v0, 0x20($sp)
/* C52DE0 802408A0 0220202D */  daddu     $a0, $s1, $zero
/* C52DE4 802408A4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C52DE8 802408A8 0C012530 */  jal       func_800494C0
/* C52DEC 802408AC 3C060020 */   lui      $a2, 0x20
/* C52DF0 802408B0 24020002 */  addiu     $v0, $zero, 2
/* C52DF4 802408B4 AE820070 */  sw        $v0, 0x70($s4)
.L802408B8:
/* C52DF8 802408B8 9622008E */  lhu       $v0, 0x8e($s1)
/* C52DFC 802408BC 24420001 */  addiu     $v0, $v0, 1
/* C52E00 802408C0 A622008E */  sh        $v0, 0x8e($s1)
/* C52E04 802408C4 00021400 */  sll       $v0, $v0, 0x10
/* C52E08 802408C8 00021C03 */  sra       $v1, $v0, 0x10
/* C52E0C 802408CC 2402001B */  addiu     $v0, $zero, 0x1b
/* C52E10 802408D0 14620005 */  bne       $v1, $v0, .L802408E8
/* C52E14 802408D4 24020039 */   addiu    $v0, $zero, 0x39
/* C52E18 802408D8 0220202D */  daddu     $a0, $s1, $zero
/* C52E1C 802408DC 3C05B000 */  lui       $a1, 0xb000
/* C52E20 802408E0 0809023F */  j         .L802408FC
/* C52E24 802408E4 34A5000C */   ori      $a1, $a1, 0xc
.L802408E8:
/* C52E28 802408E8 14620008 */  bne       $v1, $v0, .L8024090C
/* C52E2C 802408EC 2402003B */   addiu    $v0, $zero, 0x3b
/* C52E30 802408F0 0220202D */  daddu     $a0, $s1, $zero
/* C52E34 802408F4 3C05B000 */  lui       $a1, 0xb000
/* C52E38 802408F8 34A5000D */  ori       $a1, $a1, 0xd
.L802408FC:
/* C52E3C 802408FC 0C012530 */  jal       func_800494C0
/* C52E40 80240900 0000302D */   daddu    $a2, $zero, $zero
/* C52E44 80240904 0809024F */  j         .L8024093C
/* C52E48 80240908 00000000 */   nop
.L8024090C:
/* C52E4C 8024090C 14620005 */  bne       $v1, $v0, .L80240924
/* C52E50 80240910 2402003C */   addiu    $v0, $zero, 0x3c
/* C52E54 80240914 8E6200CC */  lw        $v0, 0xcc($s3)
/* C52E58 80240918 8C420030 */  lw        $v0, 0x30($v0)
/* C52E5C 8024091C 0809024F */  j         .L8024093C
/* C52E60 80240920 AE220028 */   sw       $v0, 0x28($s1)
.L80240924:
/* C52E64 80240924 14620005 */  bne       $v1, $v0, .L8024093C
/* C52E68 80240928 00000000 */   nop
/* C52E6C 8024092C 8E6200CC */  lw        $v0, 0xcc($s3)
/* C52E70 80240930 8C420028 */  lw        $v0, 0x28($v0)
/* C52E74 80240934 A620008E */  sh        $zero, 0x8e($s1)
/* C52E78 80240938 AE220028 */  sw        $v0, 0x28($s1)
.L8024093C:
/* C52E7C 8024093C 8FBF004C */  lw        $ra, 0x4c($sp)
/* C52E80 80240940 8FB40048 */  lw        $s4, 0x48($sp)
/* C52E84 80240944 8FB30044 */  lw        $s3, 0x44($sp)
/* C52E88 80240948 8FB20040 */  lw        $s2, 0x40($sp)
/* C52E8C 8024094C 8FB1003C */  lw        $s1, 0x3c($sp)
/* C52E90 80240950 8FB00038 */  lw        $s0, 0x38($sp)
/* C52E94 80240954 03E00008 */  jr        $ra
/* C52E98 80240958 27BD0050 */   addiu    $sp, $sp, 0x50
