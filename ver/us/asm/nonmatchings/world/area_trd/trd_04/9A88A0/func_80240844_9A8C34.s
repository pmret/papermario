.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80245EE8_9AE2D8
.word L80240C50_9A9040, L80240C5C_9A904C, L80240C5C_9A904C, L80240C5C_9A904C, L80240C5C_9A904C, L80240C5C_9A904C, L80240C5C_9A904C, L80240C5C_9A904C, L80240C50_9A9040, L80240C5C_9A904C, L80240C50_9A9040, L80240C5C_9A904C, L80240C50_9A9040, L80240C5C_9A904C, L80240C50_9A9040, L80240C5C_9A904C, L80240C5C_9A904C, L80240C5C_9A904C, L80240C50_9A9040, L80240C5C_9A904C, L80240C50_9A9040, 0

.section .text

glabel func_80240844_9A8C34
/* 9A8C34 80240844 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 9A8C38 80240848 AFB3005C */  sw        $s3, 0x5c($sp)
/* 9A8C3C 8024084C 0080982D */  daddu     $s3, $a0, $zero
/* 9A8C40 80240850 AFBF0068 */  sw        $ra, 0x68($sp)
/* 9A8C44 80240854 AFB50064 */  sw        $s5, 0x64($sp)
/* 9A8C48 80240858 AFB40060 */  sw        $s4, 0x60($sp)
/* 9A8C4C 8024085C AFB20058 */  sw        $s2, 0x58($sp)
/* 9A8C50 80240860 AFB10054 */  sw        $s1, 0x54($sp)
/* 9A8C54 80240864 AFB00050 */  sw        $s0, 0x50($sp)
/* 9A8C58 80240868 8E710148 */  lw        $s1, 0x148($s3)
/* 9A8C5C 8024086C 86240008 */  lh        $a0, 8($s1)
/* 9A8C60 80240870 0C00EABB */  jal       get_npc_unsafe
/* 9A8C64 80240874 00A0802D */   daddu    $s0, $a1, $zero
/* 9A8C68 80240878 8E63000C */  lw        $v1, 0xc($s3)
/* 9A8C6C 8024087C 0260202D */  daddu     $a0, $s3, $zero
/* 9A8C70 80240880 8C650000 */  lw        $a1, ($v1)
/* 9A8C74 80240884 0C0B1EAF */  jal       get_variable
/* 9A8C78 80240888 0040902D */   daddu    $s2, $v0, $zero
/* 9A8C7C 8024088C AFA00028 */  sw        $zero, 0x28($sp)
/* 9A8C80 80240890 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A8C84 80240894 8C630030 */  lw        $v1, 0x30($v1)
/* 9A8C88 80240898 AFA3002C */  sw        $v1, 0x2c($sp)
/* 9A8C8C 8024089C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A8C90 802408A0 8C63001C */  lw        $v1, 0x1c($v1)
/* 9A8C94 802408A4 AFA30030 */  sw        $v1, 0x30($sp)
/* 9A8C98 802408A8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A8C9C 802408AC 8C630024 */  lw        $v1, 0x24($v1)
/* 9A8CA0 802408B0 AFA30034 */  sw        $v1, 0x34($sp)
/* 9A8CA4 802408B4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A8CA8 802408B8 8C630028 */  lw        $v1, 0x28($v1)
/* 9A8CAC 802408BC 27B50028 */  addiu     $s5, $sp, 0x28
/* 9A8CB0 802408C0 AFA30038 */  sw        $v1, 0x38($sp)
/* 9A8CB4 802408C4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A8CB8 802408C8 3C0142C8 */  lui       $at, 0x42c8
/* 9A8CBC 802408CC 44810000 */  mtc1      $at, $f0
/* 9A8CC0 802408D0 8C63002C */  lw        $v1, 0x2c($v1)
/* 9A8CC4 802408D4 0040A02D */  daddu     $s4, $v0, $zero
/* 9A8CC8 802408D8 E7A00040 */  swc1      $f0, 0x40($sp)
/* 9A8CCC 802408DC A7A00044 */  sh        $zero, 0x44($sp)
/* 9A8CD0 802408E0 12000009 */  beqz      $s0, .L80240908
/* 9A8CD4 802408E4 AFA3003C */   sw       $v1, 0x3c($sp)
/* 9A8CD8 802408E8 864300A8 */  lh        $v1, 0xa8($s2)
/* 9A8CDC 802408EC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9A8CE0 802408F0 AE20008C */  sw        $zero, 0x8c($s1)
/* 9A8CE4 802408F4 A22000B5 */  sb        $zero, 0xb5($s1)
/* 9A8CE8 802408F8 34420008 */  ori       $v0, $v0, 8
/* 9A8CEC 802408FC AE230084 */  sw        $v1, 0x84($s1)
/* 9A8CF0 80240900 08090246 */  j         .L80240918
/* 9A8CF4 80240904 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240908:
/* 9A8CF8 80240908 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9A8CFC 8024090C 30420004 */  andi      $v0, $v0, 4
/* 9A8D00 80240910 10400047 */  beqz      $v0, .L80240A30
/* 9A8D04 80240914 00000000 */   nop
.L80240918:
/* 9A8D08 80240918 AE600070 */  sw        $zero, 0x70($s3)
/* 9A8D0C 8024091C A640008E */  sh        $zero, 0x8e($s2)
/* 9A8D10 80240920 8E2300CC */  lw        $v1, 0xcc($s1)
/* 9A8D14 80240924 2404F7FF */  addiu     $a0, $zero, -0x801
/* 9A8D18 80240928 A2200007 */  sb        $zero, 7($s1)
/* 9A8D1C 8024092C 8E420000 */  lw        $v0, ($s2)
/* 9A8D20 80240930 8C630000 */  lw        $v1, ($v1)
/* 9A8D24 80240934 00441024 */  and       $v0, $v0, $a0
/* 9A8D28 80240938 AE420000 */  sw        $v0, ($s2)
/* 9A8D2C 8024093C AE430028 */  sw        $v1, 0x28($s2)
/* 9A8D30 80240940 96220086 */  lhu       $v0, 0x86($s1)
/* 9A8D34 80240944 A64200A8 */  sh        $v0, 0xa8($s2)
/* 9A8D38 80240948 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9A8D3C 8024094C AE200090 */  sw        $zero, 0x90($s1)
/* 9A8D40 80240950 8C420034 */  lw        $v0, 0x34($v0)
/* 9A8D44 80240954 14400006 */  bnez      $v0, .L80240970
/* 9A8D48 80240958 2403FDFF */   addiu    $v1, $zero, -0x201
/* 9A8D4C 8024095C 8E420000 */  lw        $v0, ($s2)
/* 9A8D50 80240960 2403FFF7 */  addiu     $v1, $zero, -9
/* 9A8D54 80240964 34420200 */  ori       $v0, $v0, 0x200
/* 9A8D58 80240968 0809025F */  j         .L8024097C
/* 9A8D5C 8024096C 00431024 */   and      $v0, $v0, $v1
.L80240970:
/* 9A8D60 80240970 8E420000 */  lw        $v0, ($s2)
/* 9A8D64 80240974 00431024 */  and       $v0, $v0, $v1
/* 9A8D68 80240978 34420008 */  ori       $v0, $v0, 8
.L8024097C:
/* 9A8D6C 8024097C AE420000 */  sw        $v0, ($s2)
/* 9A8D70 80240980 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9A8D74 80240984 30420004 */  andi      $v0, $v0, 4
/* 9A8D78 80240988 1040001E */  beqz      $v0, .L80240A04
/* 9A8D7C 8024098C 24040002 */   addiu    $a0, $zero, 2
/* 9A8D80 80240990 0240282D */  daddu     $a1, $s2, $zero
/* 9A8D84 80240994 0000302D */  daddu     $a2, $zero, $zero
/* 9A8D88 80240998 24020063 */  addiu     $v0, $zero, 0x63
/* 9A8D8C 8024099C AE620070 */  sw        $v0, 0x70($s3)
/* 9A8D90 802409A0 AE600074 */  sw        $zero, 0x74($s3)
/* 9A8D94 802409A4 864300A8 */  lh        $v1, 0xa8($s2)
/* 9A8D98 802409A8 3C013F80 */  lui       $at, 0x3f80
/* 9A8D9C 802409AC 44810000 */  mtc1      $at, $f0
/* 9A8DA0 802409B0 3C014000 */  lui       $at, 0x4000
/* 9A8DA4 802409B4 44811000 */  mtc1      $at, $f2
/* 9A8DA8 802409B8 3C01C1A0 */  lui       $at, 0xc1a0
/* 9A8DAC 802409BC 44812000 */  mtc1      $at, $f4
/* 9A8DB0 802409C0 24020028 */  addiu     $v0, $zero, 0x28
/* 9A8DB4 802409C4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 9A8DB8 802409C8 44833000 */  mtc1      $v1, $f6
/* 9A8DBC 802409CC 00000000 */  nop
/* 9A8DC0 802409D0 468031A0 */  cvt.s.w   $f6, $f6
/* 9A8DC4 802409D4 44073000 */  mfc1      $a3, $f6
/* 9A8DC8 802409D8 27A20048 */  addiu     $v0, $sp, 0x48
/* 9A8DCC 802409DC AFA20020 */  sw        $v0, 0x20($sp)
/* 9A8DD0 802409E0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9A8DD4 802409E4 E7A20014 */  swc1      $f2, 0x14($sp)
/* 9A8DD8 802409E8 0C01BFA4 */  jal       fx_emote
/* 9A8DDC 802409EC E7A40018 */   swc1     $f4, 0x18($sp)
/* 9A8DE0 802409F0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9A8DE4 802409F4 2403FFFB */  addiu     $v1, $zero, -5
/* 9A8DE8 802409F8 00431024 */  and       $v0, $v0, $v1
/* 9A8DEC 802409FC 0809028C */  j         .L80240A30
/* 9A8DF0 80240A00 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240A04:
/* 9A8DF4 80240A04 8E220000 */  lw        $v0, ($s1)
/* 9A8DF8 80240A08 3C034000 */  lui       $v1, 0x4000
/* 9A8DFC 80240A0C 00431024 */  and       $v0, $v0, $v1
/* 9A8E00 80240A10 10400007 */  beqz      $v0, .L80240A30
/* 9A8E04 80240A14 3C03BFFF */   lui      $v1, 0xbfff
/* 9A8E08 80240A18 2402000C */  addiu     $v0, $zero, 0xc
/* 9A8E0C 80240A1C AE620070 */  sw        $v0, 0x70($s3)
/* 9A8E10 80240A20 8E220000 */  lw        $v0, ($s1)
/* 9A8E14 80240A24 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9A8E18 80240A28 00431024 */  and       $v0, $v0, $v1
/* 9A8E1C 80240A2C AE220000 */  sw        $v0, ($s1)
.L80240A30:
/* 9A8E20 80240A30 8E220090 */  lw        $v0, 0x90($s1)
/* 9A8E24 80240A34 1840000C */  blez      $v0, .L80240A68
/* 9A8E28 80240A38 2442FFFF */   addiu    $v0, $v0, -1
/* 9A8E2C 80240A3C 14400087 */  bnez      $v0, L80240C5C_9A904C
/* 9A8E30 80240A40 AE220090 */   sw       $v0, 0x90($s1)
/* 9A8E34 80240A44 3C03FFAA */  lui       $v1, 0xffaa
/* 9A8E38 80240A48 8E420028 */  lw        $v0, 0x28($s2)
/* 9A8E3C 80240A4C 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* 9A8E40 80240A50 00431021 */  addu      $v0, $v0, $v1
/* 9A8E44 80240A54 2C420002 */  sltiu     $v0, $v0, 2
/* 9A8E48 80240A58 10400003 */  beqz      $v0, .L80240A68
/* 9A8E4C 80240A5C 3C020055 */   lui      $v0, 0x55
/* 9A8E50 80240A60 3442000C */  ori       $v0, $v0, 0xc
/* 9A8E54 80240A64 AE420028 */  sw        $v0, 0x28($s2)
.L80240A68:
/* 9A8E58 80240A68 8E630070 */  lw        $v1, 0x70($s3)
/* 9A8E5C 80240A6C 2402000C */  addiu     $v0, $zero, 0xc
/* 9A8E60 80240A70 10620048 */  beq       $v1, $v0, .L80240B94
/* 9A8E64 80240A74 2862000D */   slti     $v0, $v1, 0xd
/* 9A8E68 80240A78 1040000F */  beqz      $v0, .L80240AB8
/* 9A8E6C 80240A7C 24100001 */   addiu    $s0, $zero, 1
/* 9A8E70 80240A80 1070001E */  beq       $v1, $s0, .L80240AFC
/* 9A8E74 80240A84 28620002 */   slti     $v0, $v1, 2
/* 9A8E78 80240A88 10400005 */  beqz      $v0, .L80240AA0
/* 9A8E7C 80240A8C 24020002 */   addiu    $v0, $zero, 2
/* 9A8E80 80240A90 10600015 */  beqz      $v1, .L80240AE8
/* 9A8E84 80240A94 0260202D */   daddu    $a0, $s3, $zero
/* 9A8E88 80240A98 080902FC */  j         .L80240BF0
/* 9A8E8C 80240A9C 00000000 */   nop
.L80240AA0:
/* 9A8E90 80240AA0 1062001C */  beq       $v1, $v0, .L80240B14
/* 9A8E94 80240AA4 24020003 */   addiu    $v0, $zero, 3
/* 9A8E98 80240AA8 10620035 */  beq       $v1, $v0, .L80240B80
/* 9A8E9C 80240AAC 0260202D */   daddu    $a0, $s3, $zero
/* 9A8EA0 80240AB0 080902FC */  j         .L80240BF0
/* 9A8EA4 80240AB4 00000000 */   nop
.L80240AB8:
/* 9A8EA8 80240AB8 2402000E */  addiu     $v0, $zero, 0xe
/* 9A8EAC 80240ABC 1062003F */  beq       $v1, $v0, .L80240BBC
/* 9A8EB0 80240AC0 0062102A */   slt      $v0, $v1, $v0
/* 9A8EB4 80240AC4 14400038 */  bnez      $v0, .L80240BA8
/* 9A8EB8 80240AC8 0260202D */   daddu    $a0, $s3, $zero
/* 9A8EBC 80240ACC 2402000F */  addiu     $v0, $zero, 0xf
/* 9A8EC0 80240AD0 10620040 */  beq       $v1, $v0, .L80240BD4
/* 9A8EC4 80240AD4 24020063 */   addiu    $v0, $zero, 0x63
/* 9A8EC8 80240AD8 10620043 */  beq       $v1, $v0, .L80240BE8
/* 9A8ECC 80240ADC 00000000 */   nop
/* 9A8ED0 80240AE0 080902FC */  j         .L80240BF0
/* 9A8ED4 80240AE4 00000000 */   nop
.L80240AE8:
/* 9A8ED8 80240AE8 0280282D */  daddu     $a1, $s4, $zero
/* 9A8EDC 80240AEC 0C012568 */  jal       func_800495A0
/* 9A8EE0 80240AF0 02A0302D */   daddu    $a2, $s5, $zero
/* 9A8EE4 80240AF4 96220086 */  lhu       $v0, 0x86($s1)
/* 9A8EE8 80240AF8 A64200A8 */  sh        $v0, 0xa8($s2)
.L80240AFC:
/* 9A8EEC 80240AFC 0260202D */  daddu     $a0, $s3, $zero
/* 9A8EF0 80240B00 0280282D */  daddu     $a1, $s4, $zero
/* 9A8EF4 80240B04 0C0125AE */  jal       func_800496B8
/* 9A8EF8 80240B08 02A0302D */   daddu    $a2, $s5, $zero
/* 9A8EFC 80240B0C 080902FC */  j         .L80240BF0
/* 9A8F00 80240B10 00000000 */   nop
.L80240B14:
/* 9A8F04 80240B14 0260202D */  daddu     $a0, $s3, $zero
/* 9A8F08 80240B18 0280282D */  daddu     $a1, $s4, $zero
/* 9A8F0C 80240B1C 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* 9A8F10 80240B20 02A0302D */   daddu    $a2, $s5, $zero
/* 9A8F14 80240B24 8E230088 */  lw        $v1, 0x88($s1)
/* 9A8F18 80240B28 24020006 */  addiu     $v0, $zero, 6
/* 9A8F1C 80240B2C 14620014 */  bne       $v1, $v0, .L80240B80
/* 9A8F20 80240B30 0260202D */   daddu    $a0, $s3, $zero
/* 9A8F24 80240B34 0C00A67F */  jal       rand_int
/* 9A8F28 80240B38 24040064 */   addiu    $a0, $zero, 0x64
/* 9A8F2C 80240B3C 28420021 */  slti      $v0, $v0, 0x21
/* 9A8F30 80240B40 5040000F */  beql      $v0, $zero, .L80240B80
/* 9A8F34 80240B44 0260202D */   daddu    $a0, $s3, $zero
/* 9A8F38 80240B48 8E22008C */  lw        $v0, 0x8c($s1)
/* 9A8F3C 80240B4C 10400005 */  beqz      $v0, .L80240B64
/* 9A8F40 80240B50 3C020055 */   lui      $v0, 0x55
/* 9A8F44 80240B54 3442002F */  ori       $v0, $v0, 0x2f
/* 9A8F48 80240B58 AE20008C */  sw        $zero, 0x8c($s1)
/* 9A8F4C 80240B5C 080902DC */  j         .L80240B70
/* 9A8F50 80240B60 A22000B5 */   sb       $zero, 0xb5($s1)
.L80240B64:
/* 9A8F54 80240B64 3442002E */  ori       $v0, $v0, 0x2e
/* 9A8F58 80240B68 AE30008C */  sw        $s0, 0x8c($s1)
/* 9A8F5C 80240B6C A23000B5 */  sb        $s0, 0xb5($s1)
.L80240B70:
/* 9A8F60 80240B70 AE420028 */  sw        $v0, 0x28($s2)
/* 9A8F64 80240B74 24020007 */  addiu     $v0, $zero, 7
/* 9A8F68 80240B78 08090317 */  j         L80240C5C_9A904C
/* 9A8F6C 80240B7C AE220090 */   sw       $v0, 0x90($s1)
.L80240B80:
/* 9A8F70 80240B80 0280282D */  daddu     $a1, $s4, $zero
/* 9A8F74 80240B84 0C012701 */  jal       func_80049C04
/* 9A8F78 80240B88 02A0302D */   daddu    $a2, $s5, $zero
/* 9A8F7C 80240B8C 080902FC */  j         .L80240BF0
/* 9A8F80 80240B90 00000000 */   nop
.L80240B94:
/* 9A8F84 80240B94 0260202D */  daddu     $a0, $s3, $zero
/* 9A8F88 80240B98 0280282D */  daddu     $a1, $s4, $zero
/* 9A8F8C 80240B9C 0C09012C */  jal       trd_04_set_script_owner_npc_anim
/* 9A8F90 80240BA0 02A0302D */   daddu    $a2, $s5, $zero
/* 9A8F94 80240BA4 0260202D */  daddu     $a0, $s3, $zero
.L80240BA8:
/* 9A8F98 80240BA8 0280282D */  daddu     $a1, $s4, $zero
/* 9A8F9C 80240BAC 0C09014B */  jal       func_8024052C_9A891C
/* 9A8FA0 80240BB0 02A0302D */   daddu    $a2, $s5, $zero
/* 9A8FA4 80240BB4 080902FC */  j         .L80240BF0
/* 9A8FA8 80240BB8 00000000 */   nop
.L80240BBC:
/* 9A8FAC 80240BBC 0260202D */  daddu     $a0, $s3, $zero
/* 9A8FB0 80240BC0 0280282D */  daddu     $a1, $s4, $zero
/* 9A8FB4 80240BC4 0C090198 */  jal       trd_04_UnkNpcAIFunc12
/* 9A8FB8 80240BC8 02A0302D */   daddu    $a2, $s5, $zero
/* 9A8FBC 80240BCC 080902FC */  j         .L80240BF0
/* 9A8FC0 80240BD0 00000000 */   nop
.L80240BD4:
/* 9A8FC4 80240BD4 0280282D */  daddu     $a1, $s4, $zero
/* 9A8FC8 80240BD8 0C0901F1 */  jal       trd_04_set_script_owner_npc_col_height
/* 9A8FCC 80240BDC 02A0302D */   daddu    $a2, $s5, $zero
/* 9A8FD0 80240BE0 080902FC */  j         .L80240BF0
/* 9A8FD4 80240BE4 00000000 */   nop
.L80240BE8:
/* 9A8FD8 80240BE8 0C0129CF */  jal       func_8004A73C
/* 9A8FDC 80240BEC 0260202D */   daddu    $a0, $s3, $zero
.L80240BF0:
/* 9A8FE0 80240BF0 8E230088 */  lw        $v1, 0x88($s1)
/* 9A8FE4 80240BF4 24020006 */  addiu     $v0, $zero, 6
/* 9A8FE8 80240BF8 14620019 */  bne       $v1, $v0, .L80240C60
/* 9A8FEC 80240BFC 0000102D */   daddu    $v0, $zero, $zero
/* 9A8FF0 80240C00 8E22008C */  lw        $v0, 0x8c($s1)
/* 9A8FF4 80240C04 10400003 */  beqz      $v0, .L80240C14
/* 9A8FF8 80240C08 24020001 */   addiu    $v0, $zero, 1
/* 9A8FFC 80240C0C 08090306 */  j         .L80240C18
/* 9A9000 80240C10 A22200B5 */   sb       $v0, 0xb5($s1)
.L80240C14:
/* 9A9004 80240C14 A22000B5 */  sb        $zero, 0xb5($s1)
.L80240C18:
/* 9A9008 80240C18 8E22008C */  lw        $v0, 0x8c($s1)
/* 9A900C 80240C1C 1040000F */  beqz      $v0, L80240C5C_9A904C
/* 9A9010 80240C20 3C03FFAA */   lui      $v1, 0xffaa
/* 9A9014 80240C24 8E420028 */  lw        $v0, 0x28($s2)
/* 9A9018 80240C28 3463FFFC */  ori       $v1, $v1, 0xfffc
/* 9A901C 80240C2C 00431821 */  addu      $v1, $v0, $v1
/* 9A9020 80240C30 2C620015 */  sltiu     $v0, $v1, 0x15
/* 9A9024 80240C34 10400009 */  beqz      $v0, L80240C5C_9A904C
/* 9A9028 80240C38 00031080 */   sll      $v0, $v1, 2
/* 9A902C 80240C3C 3C018024 */  lui       $at, %hi(jtbl_80245EE8_9AE2D8)
/* 9A9030 80240C40 00220821 */  addu      $at, $at, $v0
/* 9A9034 80240C44 8C225EE8 */  lw        $v0, %lo(jtbl_80245EE8_9AE2D8)($at)
/* 9A9038 80240C48 00400008 */  jr        $v0
/* 9A903C 80240C4C 00000000 */   nop
glabel L80240C50_9A9040
/* 9A9040 80240C50 8E420028 */  lw        $v0, 0x28($s2)
/* 9A9044 80240C54 24420001 */  addiu     $v0, $v0, 1
/* 9A9048 80240C58 AE420028 */  sw        $v0, 0x28($s2)
glabel L80240C5C_9A904C
/* 9A904C 80240C5C 0000102D */  daddu     $v0, $zero, $zero
.L80240C60:
/* 9A9050 80240C60 8FBF0068 */  lw        $ra, 0x68($sp)
/* 9A9054 80240C64 8FB50064 */  lw        $s5, 0x64($sp)
/* 9A9058 80240C68 8FB40060 */  lw        $s4, 0x60($sp)
/* 9A905C 80240C6C 8FB3005C */  lw        $s3, 0x5c($sp)
/* 9A9060 80240C70 8FB20058 */  lw        $s2, 0x58($sp)
/* 9A9064 80240C74 8FB10054 */  lw        $s1, 0x54($sp)
/* 9A9068 80240C78 8FB00050 */  lw        $s0, 0x50($sp)
/* 9A906C 80240C7C 03E00008 */  jr        $ra
/* 9A9070 80240C80 27BD0070 */   addiu    $sp, $sp, 0x70
