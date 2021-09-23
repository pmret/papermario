.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DE4_EE07A4
/* EE07A4 80241DE4 27BDFF98 */  addiu     $sp, $sp, -0x68
/* EE07A8 80241DE8 AFB40050 */  sw        $s4, 0x50($sp)
/* EE07AC 80241DEC 0080A02D */  daddu     $s4, $a0, $zero
/* EE07B0 80241DF0 AFBF005C */  sw        $ra, 0x5c($sp)
/* EE07B4 80241DF4 AFB60058 */  sw        $s6, 0x58($sp)
/* EE07B8 80241DF8 AFB50054 */  sw        $s5, 0x54($sp)
/* EE07BC 80241DFC AFB3004C */  sw        $s3, 0x4c($sp)
/* EE07C0 80241E00 AFB20048 */  sw        $s2, 0x48($sp)
/* EE07C4 80241E04 AFB10044 */  sw        $s1, 0x44($sp)
/* EE07C8 80241E08 AFB00040 */  sw        $s0, 0x40($sp)
/* EE07CC 80241E0C F7B40060 */  sdc1      $f20, 0x60($sp)
/* EE07D0 80241E10 8E930148 */  lw        $s3, 0x148($s4)
/* EE07D4 80241E14 86640008 */  lh        $a0, 8($s3)
/* EE07D8 80241E18 8E90000C */  lw        $s0, 0xc($s4)
/* EE07DC 80241E1C 0C00F92F */  jal       dead_get_npc_unsafe
/* EE07E0 80241E20 00A0882D */   daddu    $s1, $a1, $zero
/* EE07E4 80241E24 0280202D */  daddu     $a0, $s4, $zero
/* EE07E8 80241E28 8E050000 */  lw        $a1, ($s0)
/* EE07EC 80241E2C 0C0B53A3 */  jal       dead_evt_get_variable
/* EE07F0 80241E30 0040902D */   daddu    $s2, $v0, $zero
/* EE07F4 80241E34 AFA00020 */  sw        $zero, 0x20($sp)
/* EE07F8 80241E38 8E6300D0 */  lw        $v1, 0xd0($s3)
/* EE07FC 80241E3C 8C630030 */  lw        $v1, 0x30($v1)
/* EE0800 80241E40 AFA30024 */  sw        $v1, 0x24($sp)
/* EE0804 80241E44 8E6300D0 */  lw        $v1, 0xd0($s3)
/* EE0808 80241E48 8C63001C */  lw        $v1, 0x1c($v1)
/* EE080C 80241E4C AFA30028 */  sw        $v1, 0x28($sp)
/* EE0810 80241E50 8E6300D0 */  lw        $v1, 0xd0($s3)
/* EE0814 80241E54 8C630024 */  lw        $v1, 0x24($v1)
/* EE0818 80241E58 AFA3002C */  sw        $v1, 0x2c($sp)
/* EE081C 80241E5C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* EE0820 80241E60 8C630028 */  lw        $v1, 0x28($v1)
/* EE0824 80241E64 AFA30030 */  sw        $v1, 0x30($sp)
/* EE0828 80241E68 8E6300D0 */  lw        $v1, 0xd0($s3)
/* EE082C 80241E6C 3C0142F0 */  lui       $at, 0x42f0
/* EE0830 80241E70 44810000 */  mtc1      $at, $f0
/* EE0834 80241E74 8C63002C */  lw        $v1, 0x2c($v1)
/* EE0838 80241E78 E7A00038 */  swc1      $f0, 0x38($sp)
/* EE083C 80241E7C A7A0003C */  sh        $zero, 0x3c($sp)
/* EE0840 80241E80 AFA30034 */  sw        $v1, 0x34($sp)
/* EE0844 80241E84 C6400038 */  lwc1      $f0, 0x38($s2)
/* EE0848 80241E88 E6600108 */  swc1      $f0, 0x108($s3)
/* EE084C 80241E8C C640003C */  lwc1      $f0, 0x3c($s2)
/* EE0850 80241E90 27B50020 */  addiu     $s5, $sp, 0x20
/* EE0854 80241E94 E660010C */  swc1      $f0, 0x10c($s3)
/* EE0858 80241E98 3C0138D1 */  lui       $at, 0x38d1
/* EE085C 80241E9C 3421B717 */  ori       $at, $at, 0xb717
/* EE0860 80241EA0 44810000 */  mtc1      $at, $f0
/* EE0864 80241EA4 C6420040 */  lwc1      $f2, 0x40($s2)
/* EE0868 80241EA8 0040B02D */  daddu     $s6, $v0, $zero
/* EE086C 80241EAC E6600114 */  swc1      $f0, 0x114($s3)
/* EE0870 80241EB0 E6600118 */  swc1      $f0, 0x118($s3)
/* EE0874 80241EB4 12200007 */  beqz      $s1, .L80241ED4
/* EE0878 80241EB8 E6620110 */   swc1     $f2, 0x110($s3)
/* EE087C 80241EBC 0240202D */  daddu     $a0, $s2, $zero
/* EE0880 80241EC0 0260282D */  daddu     $a1, $s3, $zero
/* EE0884 80241EC4 0280302D */  daddu     $a2, $s4, $zero
/* EE0888 80241EC8 0C0904EB */  jal       EDEA00_UnkFunc5
/* EE088C 80241ECC 02C0382D */   daddu    $a3, $s6, $zero
/* EE0890 80241ED0 AE800070 */  sw        $zero, 0x70($s4)
.L80241ED4:
/* EE0894 80241ED4 2402FFFD */  addiu     $v0, $zero, -3
/* EE0898 80241ED8 A24200AB */  sb        $v0, 0xab($s2)
/* EE089C 80241EDC 8E6300B0 */  lw        $v1, 0xb0($s3)
/* EE08A0 80241EE0 30620004 */  andi      $v0, $v1, 4
/* EE08A4 80241EE4 10400007 */  beqz      $v0, .L80241F04
/* EE08A8 80241EE8 00000000 */   nop
/* EE08AC 80241EEC 826200B4 */  lb        $v0, 0xb4($s3)
/* EE08B0 80241EF0 144000F4 */  bnez      $v0, .L802422C4
/* EE08B4 80241EF4 0000102D */   daddu    $v0, $zero, $zero
/* EE08B8 80241EF8 2402FFFB */  addiu     $v0, $zero, -5
/* EE08BC 80241EFC 00621024 */  and       $v0, $v1, $v0
/* EE08C0 80241F00 AE6200B0 */  sw        $v0, 0xb0($s3)
.L80241F04:
/* EE08C4 80241F04 8E830070 */  lw        $v1, 0x70($s4)
/* EE08C8 80241F08 24020001 */  addiu     $v0, $zero, 1
/* EE08CC 80241F0C 10620011 */  beq       $v1, $v0, .L80241F54
/* EE08D0 80241F10 28620002 */   slti     $v0, $v1, 2
/* EE08D4 80241F14 10400005 */  beqz      $v0, .L80241F2C
/* EE08D8 80241F18 24020002 */   addiu    $v0, $zero, 2
/* EE08DC 80241F1C 10600009 */  beqz      $v1, .L80241F44
/* EE08E0 80241F20 2402000C */   addiu    $v0, $zero, 0xc
/* EE08E4 80241F24 080907E5 */  j         .L80241F94
/* EE08E8 80241F28 00000000 */   nop
.L80241F2C:
/* EE08EC 80241F2C 1062000F */  beq       $v1, $v0, .L80241F6C
/* EE08F0 80241F30 24020003 */   addiu    $v0, $zero, 3
/* EE08F4 80241F34 10620012 */  beq       $v1, $v0, .L80241F80
/* EE08F8 80241F38 0280202D */   daddu    $a0, $s4, $zero
/* EE08FC 80241F3C 080907E3 */  j         .L80241F8C
/* EE0900 80241F40 00000000 */   nop
.L80241F44:
/* EE0904 80241F44 0280202D */  daddu     $a0, $s4, $zero
/* EE0908 80241F48 02C0282D */  daddu     $a1, $s6, $zero
/* EE090C 80241F4C 0C090071 */  jal       EDEA00_UnkNpcAIFunc23
/* EE0910 80241F50 02A0302D */   daddu    $a2, $s5, $zero
.L80241F54:
/* EE0914 80241F54 0280202D */  daddu     $a0, $s4, $zero
/* EE0918 80241F58 02C0282D */  daddu     $a1, $s6, $zero
/* EE091C 80241F5C 0C0905CC */  jal       func_80241730_EE00F0
/* EE0920 80241F60 02A0302D */   daddu    $a2, $s5, $zero
/* EE0924 80241F64 080907E3 */  j         .L80241F8C
/* EE0928 80241F68 00000000 */   nop
.L80241F6C:
/* EE092C 80241F6C 0280202D */  daddu     $a0, $s4, $zero
/* EE0930 80241F70 02C0282D */  daddu     $a1, $s6, $zero
/* EE0934 80241F74 0C090267 */  jal       EDEA00_DeadUnkNpcAIFunc1
/* EE0938 80241F78 02A0302D */   daddu    $a2, $s5, $zero
/* EE093C 80241F7C 0280202D */  daddu     $a0, $s4, $zero
.L80241F80:
/* EE0940 80241F80 02C0282D */  daddu     $a1, $s6, $zero
/* EE0944 80241F84 0C0906E5 */  jal       func_80241B94_EE0554
/* EE0948 80241F88 02A0302D */   daddu    $a2, $s5, $zero
.L80241F8C:
/* EE094C 80241F8C 8E830070 */  lw        $v1, 0x70($s4)
/* EE0950 80241F90 2402000C */  addiu     $v0, $zero, 0xc
.L80241F94:
/* EE0954 80241F94 1462001A */  bne       $v1, $v0, .L80242000
/* EE0958 80241F98 00000000 */   nop
/* EE095C 80241F9C C64C0038 */  lwc1      $f12, 0x38($s2)
/* EE0960 80241FA0 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EE0964 80241FA4 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EE0968 80241FA8 C64E0040 */  lwc1      $f14, 0x40($s2)
/* EE096C 80241FAC 8C460028 */  lw        $a2, 0x28($v0)
/* EE0970 80241FB0 0C00ABDC */  jal       fio_validate_header_checksums
/* EE0974 80241FB4 8C470030 */   lw       $a3, 0x30($v0)
/* EE0978 80241FB8 0C0905BA */  jal       func_802416E8_EE00A8
/* EE097C 80241FBC E640000C */   swc1     $f0, 0xc($s2)
/* EE0980 80241FC0 0440000F */  bltz      $v0, .L80242000
/* EE0984 80241FC4 AE62007C */   sw       $v0, 0x7c($s3)
/* EE0988 80241FC8 0C010ABD */  jal       dead_get_enemy
/* EE098C 80241FCC 0040202D */   daddu    $a0, $v0, $zero
/* EE0990 80241FD0 3C030049 */  lui       $v1, 0x49
/* EE0994 80241FD4 0040202D */  daddu     $a0, $v0, $zero
/* EE0998 80241FD8 24020001 */  addiu     $v0, $zero, 1
/* EE099C 80241FDC AC820094 */  sw        $v0, 0x94($a0)
/* EE09A0 80241FE0 86620008 */  lh        $v0, 8($s3)
/* EE09A4 80241FE4 34630014 */  ori       $v1, $v1, 0x14
/* EE09A8 80241FE8 AC820098 */  sw        $v0, 0x98($a0)
/* EE09AC 80241FEC 2402000F */  addiu     $v0, $zero, 0xf
/* EE09B0 80241FF0 A642008E */  sh        $v0, 0x8e($s2)
/* EE09B4 80241FF4 2402001E */  addiu     $v0, $zero, 0x1e
/* EE09B8 80241FF8 AE430028 */  sw        $v1, 0x28($s2)
/* EE09BC 80241FFC AE820070 */  sw        $v0, 0x70($s4)
.L80242000:
/* EE09C0 80242000 8E830070 */  lw        $v1, 0x70($s4)
/* EE09C4 80242004 2402000D */  addiu     $v0, $zero, 0xd
/* EE09C8 80242008 10620010 */  beq       $v1, $v0, .L8024204C
/* EE09CC 8024200C 2862000E */   slti     $v0, $v1, 0xe
/* EE09D0 80242010 10400005 */  beqz      $v0, .L80242028
/* EE09D4 80242014 2402000C */   addiu    $v0, $zero, 0xc
/* EE09D8 80242018 10620008 */  beq       $v1, $v0, .L8024203C
/* EE09DC 8024201C 2410001F */   addiu    $s0, $zero, 0x1f
/* EE09E0 80242020 0809081E */  j         .L80242078
/* EE09E4 80242024 00000000 */   nop
.L80242028:
/* EE09E8 80242028 2402000E */  addiu     $v0, $zero, 0xe
/* EE09EC 8024202C 1062000D */  beq       $v1, $v0, .L80242064
/* EE09F0 80242030 0280202D */   daddu    $a0, $s4, $zero
/* EE09F4 80242034 0809081C */  j         .L80242070
/* EE09F8 80242038 00000000 */   nop
.L8024203C:
/* EE09FC 8024203C 0280202D */  daddu     $a0, $s4, $zero
/* EE0A00 80242040 02C0282D */  daddu     $a1, $s6, $zero
/* EE0A04 80242044 0C0903A1 */  jal       EDEA00_DeadUnkNpcAIFunc14
/* EE0A08 80242048 02A0302D */   daddu    $a2, $s5, $zero
.L8024204C:
/* EE0A0C 8024204C 0280202D */  daddu     $a0, $s4, $zero
/* EE0A10 80242050 02C0282D */  daddu     $a1, $s6, $zero
/* EE0A14 80242054 0C0903EE */  jal       EDEA00_UnkNpcAIFunc3
/* EE0A18 80242058 02A0302D */   daddu    $a2, $s5, $zero
/* EE0A1C 8024205C 0809081C */  j         .L80242070
/* EE0A20 80242060 00000000 */   nop
.L80242064:
/* EE0A24 80242064 02C0282D */  daddu     $a1, $s6, $zero
/* EE0A28 80242068 0C090407 */  jal       EDEA00_UnkFunc6
/* EE0A2C 8024206C 02A0302D */   daddu    $a2, $s5, $zero
.L80242070:
/* EE0A30 80242070 8E830070 */  lw        $v1, 0x70($s4)
/* EE0A34 80242074 2410001F */  addiu     $s0, $zero, 0x1f
.L80242078:
/* EE0A38 80242078 1070001B */  beq       $v1, $s0, .L802420E8
/* EE0A3C 8024207C 28620020 */   slti     $v0, $v1, 0x20
/* EE0A40 80242080 10400005 */  beqz      $v0, .L80242098
/* EE0A44 80242084 2402001E */   addiu    $v0, $zero, 0x1e
/* EE0A48 80242088 1062000A */  beq       $v1, $v0, .L802420B4
/* EE0A4C 8024208C 00000000 */   nop
/* EE0A50 80242090 08090859 */  j         .L80242164
/* EE0A54 80242094 00000000 */   nop
.L80242098:
/* EE0A58 80242098 24020020 */  addiu     $v0, $zero, 0x20
/* EE0A5C 8024209C 10620022 */  beq       $v1, $v0, .L80242128
/* EE0A60 802420A0 24020021 */   addiu    $v0, $zero, 0x21
/* EE0A64 802420A4 10620029 */  beq       $v1, $v0, .L8024214C
/* EE0A68 802420A8 00000000 */   nop
/* EE0A6C 802420AC 08090859 */  j         .L80242164
/* EE0A70 802420B0 00000000 */   nop
.L802420B4:
/* EE0A74 802420B4 9642008E */  lhu       $v0, 0x8e($s2)
/* EE0A78 802420B8 2442FFFF */  addiu     $v0, $v0, -1
/* EE0A7C 802420BC A642008E */  sh        $v0, 0x8e($s2)
/* EE0A80 802420C0 00021400 */  sll       $v0, $v0, 0x10
/* EE0A84 802420C4 1C400027 */  bgtz      $v0, .L80242164
/* EE0A88 802420C8 00000000 */   nop
/* EE0A8C 802420CC 0C010ABD */  jal       dead_get_enemy
/* EE0A90 802420D0 8E64007C */   lw       $a0, 0x7c($s3)
/* EE0A94 802420D4 24030002 */  addiu     $v1, $zero, 2
/* EE0A98 802420D8 AC430094 */  sw        $v1, 0x94($v0)
/* EE0A9C 802420DC 24020005 */  addiu     $v0, $zero, 5
/* EE0AA0 802420E0 A642008E */  sh        $v0, 0x8e($s2)
/* EE0AA4 802420E4 AE900070 */  sw        $s0, 0x70($s4)
.L802420E8:
/* EE0AA8 802420E8 9642008E */  lhu       $v0, 0x8e($s2)
/* EE0AAC 802420EC 2442FFFF */  addiu     $v0, $v0, -1
/* EE0AB0 802420F0 A642008E */  sh        $v0, 0x8e($s2)
/* EE0AB4 802420F4 00021400 */  sll       $v0, $v0, 0x10
/* EE0AB8 802420F8 1C40001A */  bgtz      $v0, .L80242164
/* EE0ABC 802420FC 3C020049 */   lui      $v0, 0x49
/* EE0AC0 80242100 34420015 */  ori       $v0, $v0, 0x15
/* EE0AC4 80242104 AE420028 */  sw        $v0, 0x28($s2)
/* EE0AC8 80242108 0C010ABD */  jal       dead_get_enemy
/* EE0ACC 8024210C 8E64007C */   lw       $a0, 0x7c($s3)
/* EE0AD0 80242110 24030003 */  addiu     $v1, $zero, 3
/* EE0AD4 80242114 AC430094 */  sw        $v1, 0x94($v0)
/* EE0AD8 80242118 2402000A */  addiu     $v0, $zero, 0xa
/* EE0ADC 8024211C A642008E */  sh        $v0, 0x8e($s2)
/* EE0AE0 80242120 24020020 */  addiu     $v0, $zero, 0x20
/* EE0AE4 80242124 AE820070 */  sw        $v0, 0x70($s4)
.L80242128:
/* EE0AE8 80242128 9642008E */  lhu       $v0, 0x8e($s2)
/* EE0AEC 8024212C 2442FFFF */  addiu     $v0, $v0, -1
/* EE0AF0 80242130 A642008E */  sh        $v0, 0x8e($s2)
/* EE0AF4 80242134 00021400 */  sll       $v0, $v0, 0x10
/* EE0AF8 80242138 1C40000A */  bgtz      $v0, .L80242164
/* EE0AFC 8024213C 24020003 */   addiu    $v0, $zero, 3
/* EE0B00 80242140 A642008E */  sh        $v0, 0x8e($s2)
/* EE0B04 80242144 24020021 */  addiu     $v0, $zero, 0x21
/* EE0B08 80242148 AE820070 */  sw        $v0, 0x70($s4)
.L8024214C:
/* EE0B0C 8024214C 9642008E */  lhu       $v0, 0x8e($s2)
/* EE0B10 80242150 2442FFFF */  addiu     $v0, $v0, -1
/* EE0B14 80242154 A642008E */  sh        $v0, 0x8e($s2)
/* EE0B18 80242158 00021400 */  sll       $v0, $v0, 0x10
/* EE0B1C 8024215C 58400001 */  blezl     $v0, .L80242164
/* EE0B20 80242160 AE800070 */   sw       $zero, 0x70($s4)
.L80242164:
/* EE0B24 80242164 8E820070 */  lw        $v0, 0x70($s4)
/* EE0B28 80242168 2442FFE2 */  addiu     $v0, $v0, -0x1e
/* EE0B2C 8024216C 2C420002 */  sltiu     $v0, $v0, 2
/* EE0B30 80242170 10400054 */  beqz      $v0, .L802422C4
/* EE0B34 80242174 0000102D */   daddu    $v0, $zero, $zero
/* EE0B38 80242178 3C108010 */  lui       $s0, %hi(dead_gPlayerStatusPtr)
/* EE0B3C 8024217C 2610FC90 */  addiu     $s0, $s0, %lo(dead_gPlayerStatusPtr)
/* EE0B40 80242180 C64C0038 */  lwc1      $f12, 0x38($s2)
/* EE0B44 80242184 8E020000 */  lw        $v0, ($s0)
/* EE0B48 80242188 C64E0040 */  lwc1      $f14, 0x40($s2)
/* EE0B4C 8024218C 8C460028 */  lw        $a2, 0x28($v0)
/* EE0B50 80242190 0C00ABDC */  jal       fio_validate_header_checksums
/* EE0B54 80242194 8C470030 */   lw       $a3, 0x30($v0)
/* EE0B58 80242198 8E460038 */  lw        $a2, 0x38($s2)
/* EE0B5C 8024219C 8E470040 */  lw        $a3, 0x40($s2)
/* EE0B60 802421A0 8E020000 */  lw        $v0, ($s0)
/* EE0B64 802421A4 E640000C */  swc1      $f0, 0xc($s2)
/* EE0B68 802421A8 C44C0028 */  lwc1      $f12, 0x28($v0)
/* EE0B6C 802421AC 0C00AC71 */  jal       dead_dist2D
/* EE0B70 802421B0 C44E0030 */   lwc1     $f14, 0x30($v0)
/* EE0B74 802421B4 C6A20008 */  lwc1      $f2, 8($s5)
/* EE0B78 802421B8 468010A0 */  cvt.s.w   $f2, $f2
/* EE0B7C 802421BC 44051000 */  mfc1      $a1, $f2
/* EE0B80 802421C0 C6A2000C */  lwc1      $f2, 0xc($s5)
/* EE0B84 802421C4 468010A0 */  cvt.s.w   $f2, $f2
/* EE0B88 802421C8 44061000 */  mfc1      $a2, $f2
/* EE0B8C 802421CC C6420040 */  lwc1      $f2, 0x40($s2)
/* EE0B90 802421D0 E7A20010 */  swc1      $f2, 0x10($sp)
/* EE0B94 802421D4 C6A20010 */  lwc1      $f2, 0x10($s5)
/* EE0B98 802421D8 468010A0 */  cvt.s.w   $f2, $f2
/* EE0B9C 802421DC E7A20014 */  swc1      $f2, 0x14($sp)
/* EE0BA0 802421E0 C6A20014 */  lwc1      $f2, 0x14($s5)
/* EE0BA4 802421E4 468010A0 */  cvt.s.w   $f2, $f2
/* EE0BA8 802421E8 E7A20018 */  swc1      $f2, 0x18($sp)
/* EE0BAC 802421EC 8EA40004 */  lw        $a0, 4($s5)
/* EE0BB0 802421F0 8E470038 */  lw        $a3, 0x38($s2)
/* EE0BB4 802421F4 0C013431 */  jal       dead_is_point_within_region
/* EE0BB8 802421F8 46000506 */   mov.s    $f20, $f0
/* EE0BBC 802421FC 14400031 */  bnez      $v0, .L802422C4
/* EE0BC0 80242200 0000102D */   daddu    $v0, $zero, $zero
/* EE0BC4 80242204 3C01403E */  lui       $at, 0x403e
/* EE0BC8 80242208 44810800 */  mtc1      $at, $f1
/* EE0BCC 8024220C 44800000 */  mtc1      $zero, $f0
/* EE0BD0 80242210 4600A0A1 */  cvt.d.s   $f2, $f20
/* EE0BD4 80242214 4622003C */  c.lt.d    $f0, $f2
/* EE0BD8 80242218 00000000 */  nop
/* EE0BDC 8024221C 45000029 */  bc1f      .L802422C4
/* EE0BE0 80242220 00000000 */   nop
/* EE0BE4 80242224 8642008C */  lh        $v0, 0x8c($s2)
/* EE0BE8 80242228 54400026 */  bnel      $v0, $zero, .L802422C4
/* EE0BEC 8024222C 0000102D */   daddu    $v0, $zero, $zero
/* EE0BF0 80242230 3C014034 */  lui       $at, 0x4034
/* EE0BF4 80242234 44810800 */  mtc1      $at, $f1
/* EE0BF8 80242238 44800000 */  mtc1      $zero, $f0
/* EE0BFC 8024223C 00000000 */  nop
/* EE0C00 80242240 46201001 */  sub.d     $f0, $f2, $f0
/* EE0C04 80242244 44801000 */  mtc1      $zero, $f2
/* EE0C08 80242248 44801800 */  mtc1      $zero, $f3
/* EE0C0C 8024224C 46200120 */  cvt.s.d   $f4, $f0
/* EE0C10 80242250 46002021 */  cvt.d.s   $f0, $f4
/* EE0C14 80242254 4622003C */  c.lt.d    $f0, $f2
/* EE0C18 80242258 00000000 */  nop
/* EE0C1C 8024225C 45000002 */  bc1f      .L80242268
/* EE0C20 80242260 00000000 */   nop
/* EE0C24 80242264 44802000 */  mtc1      $zero, $f4
.L80242268:
/* EE0C28 80242268 3C014069 */  lui       $at, 0x4069
/* EE0C2C 8024226C 44811800 */  mtc1      $at, $f3
/* EE0C30 80242270 44801000 */  mtc1      $zero, $f2
/* EE0C34 80242274 46002021 */  cvt.d.s   $f0, $f4
/* EE0C38 80242278 4620103C */  c.lt.d    $f2, $f0
/* EE0C3C 8024227C 00000000 */  nop
/* EE0C40 80242280 45000003 */  bc1f      .L80242290
/* EE0C44 80242284 240200C8 */   addiu    $v0, $zero, 0xc8
/* EE0C48 80242288 3C014348 */  lui       $at, 0x4348
/* EE0C4C 8024228C 44812000 */  mtc1      $at, $f4
.L80242290:
/* EE0C50 80242290 AFA20010 */  sw        $v0, 0x10($sp)
/* EE0C54 80242294 8EC50000 */  lw        $a1, ($s6)
/* EE0C58 80242298 8EC60018 */  lw        $a2, 0x18($s6)
/* EE0C5C 8024229C 4600218D */  trunc.w.s $f6, $f4
/* EE0C60 802422A0 44073000 */  mfc1      $a3, $f6
/* EE0C64 802422A4 0C00ADA9 */  jal       func_8002B6A4
/* EE0C68 802422A8 0000202D */   daddu    $a0, $zero, $zero
/* EE0C6C 802422AC 44050000 */  mfc1      $a1, $f0
/* EE0C70 802422B0 8E46000C */  lw        $a2, 0xc($s2)
/* EE0C74 802422B4 0240202D */  daddu     $a0, $s2, $zero
/* EE0C78 802422B8 0C00F909 */  jal       dead_npc_move_heading
/* EE0C7C 802422BC AC850018 */   sw       $a1, 0x18($a0)
/* EE0C80 802422C0 0000102D */  daddu     $v0, $zero, $zero
.L802422C4:
/* EE0C84 802422C4 8FBF005C */  lw        $ra, 0x5c($sp)
/* EE0C88 802422C8 8FB60058 */  lw        $s6, 0x58($sp)
/* EE0C8C 802422CC 8FB50054 */  lw        $s5, 0x54($sp)
/* EE0C90 802422D0 8FB40050 */  lw        $s4, 0x50($sp)
/* EE0C94 802422D4 8FB3004C */  lw        $s3, 0x4c($sp)
/* EE0C98 802422D8 8FB20048 */  lw        $s2, 0x48($sp)
/* EE0C9C 802422DC 8FB10044 */  lw        $s1, 0x44($sp)
/* EE0CA0 802422E0 8FB00040 */  lw        $s0, 0x40($sp)
/* EE0CA4 802422E4 D7B40060 */  ldc1      $f20, 0x60($sp)
/* EE0CA8 802422E8 03E00008 */  jr        $ra
/* EE0CAC 802422EC 27BD0068 */   addiu    $sp, $sp, 0x68
