.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AD0_A39FB0
/* A39FB0 80240AD0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A39FB4 80240AD4 AFB3001C */  sw        $s3, 0x1c($sp)
/* A39FB8 80240AD8 0080982D */  daddu     $s3, $a0, $zero
/* A39FBC 80240ADC AFB60028 */  sw        $s6, 0x28($sp)
/* A39FC0 80240AE0 3C168011 */  lui       $s6, %hi(gPlayerData)
/* A39FC4 80240AE4 26D6F290 */  addiu     $s6, $s6, %lo(gPlayerData)
/* A39FC8 80240AE8 AFBF0034 */  sw        $ra, 0x34($sp)
/* A39FCC 80240AEC AFBE0030 */  sw        $fp, 0x30($sp)
/* A39FD0 80240AF0 AFB7002C */  sw        $s7, 0x2c($sp)
/* A39FD4 80240AF4 AFB50024 */  sw        $s5, 0x24($sp)
/* A39FD8 80240AF8 AFB40020 */  sw        $s4, 0x20($sp)
/* A39FDC 80240AFC AFB20018 */  sw        $s2, 0x18($sp)
/* A39FE0 80240B00 AFB10014 */  sw        $s1, 0x14($sp)
/* A39FE4 80240B04 10A0003E */  beqz      $a1, .L80240C00
/* A39FE8 80240B08 AFB00010 */   sw       $s0, 0x10($sp)
/* A39FEC 80240B0C 0C00AB39 */  jal       heap_malloc
/* A39FF0 80240B10 24040330 */   addiu    $a0, $zero, 0x330
/* A39FF4 80240B14 AE620078 */  sw        $v0, 0x78($s3)
/* A39FF8 80240B18 0040A82D */  daddu     $s5, $v0, $zero
/* A39FFC 80240B1C 0000A02D */  daddu     $s4, $zero, $zero
/* A3A000 80240B20 0280902D */  daddu     $s2, $s4, $zero
/* A3A004 80240B24 3C17F840 */  lui       $s7, 0xf840
/* A3A008 80240B28 36F7626B */  ori       $s7, $s7, 0x626b
/* A3A00C 80240B2C 3C1E8009 */  lui       $fp, %hi(D_8008A680)
/* A3A010 80240B30 27DEA680 */  addiu     $fp, $fp, %lo(D_8008A680)
/* A3A014 80240B34 3C118024 */  lui       $s1, %hi(D_802435EC_A3CACC)
/* A3A018 80240B38 263135EC */  addiu     $s1, $s1, %lo(D_802435EC_A3CACC)
/* A3A01C 80240B3C 02A0802D */  daddu     $s0, $s5, $zero
.L80240B40:
/* A3A020 80240B40 0000202D */  daddu     $a0, $zero, $zero
/* A3A024 80240B44 0C0B1EAF */  jal       get_variable
/* A3A028 80240B48 02572821 */   addu     $a1, $s2, $s7
/* A3A02C 80240B4C 54400022 */  bnel      $v0, $zero, .L80240BD8
/* A3A030 80240B50 26520001 */   addiu    $s2, $s2, 1
/* A3A034 80240B54 8E220000 */  lw        $v0, ($s1)
/* A3A038 80240B58 3C068008 */  lui       $a2, %hi(gItemTable)
/* A3A03C 80240B5C 24C678E0 */  addiu     $a2, $a2, %lo(gItemTable)
/* A3A040 80240B60 00021140 */  sll       $v0, $v0, 5
/* A3A044 80240B64 00461021 */  addu      $v0, $v0, $a2
/* A3A048 80240B68 84430004 */  lh        $v1, 4($v0)
/* A3A04C 80240B6C AE120108 */  sw        $s2, 0x108($s0)
/* A3A050 80240B70 8C420000 */  lw        $v0, ($v0)
/* A3A054 80240B74 000318C0 */  sll       $v1, $v1, 3
/* A3A058 80240B78 007E2021 */  addu      $a0, $v1, $fp
/* A3A05C 80240B7C AE020084 */  sw        $v0, 0x84($s0)
/* A3A060 80240B80 8C820000 */  lw        $v0, ($a0)
/* A3A064 80240B84 AE020000 */  sw        $v0, ($s0)
/* A3A068 80240B88 92C2000F */  lbu       $v0, 0xf($s6)
/* A3A06C 80240B8C 8E230004 */  lw        $v1, 4($s1)
/* A3A070 80240B90 0043102A */  slt       $v0, $v0, $v1
/* A3A074 80240B94 38420001 */  xori      $v0, $v0, 1
/* A3A078 80240B98 AE02018C */  sw        $v0, 0x18c($s0)
/* A3A07C 80240B9C 92C2000F */  lbu       $v0, 0xf($s6)
/* A3A080 80240BA0 8E230004 */  lw        $v1, 4($s1)
/* A3A084 80240BA4 0043102A */  slt       $v0, $v0, $v1
/* A3A088 80240BA8 10400004 */  beqz      $v0, .L80240BBC
/* A3A08C 80240BAC 00000000 */   nop
/* A3A090 80240BB0 8C820004 */  lw        $v0, 4($a0)
/* A3A094 80240BB4 AE00018C */  sw        $zero, 0x18c($s0)
/* A3A098 80240BB8 AE020000 */  sw        $v0, ($s0)
.L80240BBC:
/* A3A09C 80240BBC 8E220008 */  lw        $v0, 8($s1)
/* A3A0A0 80240BC0 AE020294 */  sw        $v0, 0x294($s0)
/* A3A0A4 80240BC4 8E220004 */  lw        $v0, 4($s1)
/* A3A0A8 80240BC8 26940001 */  addiu     $s4, $s4, 1
/* A3A0AC 80240BCC AE020210 */  sw        $v0, 0x210($s0)
/* A3A0B0 80240BD0 26100004 */  addiu     $s0, $s0, 4
/* A3A0B4 80240BD4 26520001 */  addiu     $s2, $s2, 1
.L80240BD8:
/* A3A0B8 80240BD8 2A42000F */  slti      $v0, $s2, 0xf
/* A3A0BC 80240BDC 1440FFD8 */  bnez      $v0, .L80240B40
/* A3A0C0 80240BE0 2631000C */   addiu    $s1, $s1, 0xc
/* A3A0C4 80240BE4 02A0202D */  daddu     $a0, $s5, $zero
/* A3A0C8 80240BE8 24020003 */  addiu     $v0, $zero, 3
/* A3A0CC 80240BEC AC820318 */  sw        $v0, 0x318($a0)
/* A3A0D0 80240BF0 AC940324 */  sw        $s4, 0x324($a0)
/* A3A0D4 80240BF4 0C03D390 */  jal       create_popup_menu
/* A3A0D8 80240BF8 AC800328 */   sw       $zero, 0x328($a0)
/* A3A0DC 80240BFC AE600070 */  sw        $zero, 0x70($s3)
.L80240C00:
/* A3A0E0 80240C00 8E620070 */  lw        $v0, 0x70($s3)
/* A3A0E4 80240C04 8E750078 */  lw        $s5, 0x78($s3)
/* A3A0E8 80240C08 14400008 */  bnez      $v0, .L80240C2C
/* A3A0EC 80240C0C 24420001 */   addiu    $v0, $v0, 1
/* A3A0F0 80240C10 86A2032C */  lh        $v0, 0x32c($s5)
/* A3A0F4 80240C14 10400009 */  beqz      $v0, .L80240C3C
/* A3A0F8 80240C18 AE620074 */   sw       $v0, 0x74($s3)
/* A3A0FC 80240C1C 0C03C4EC */  jal       hide_popup_menu
/* A3A100 80240C20 00000000 */   nop
/* A3A104 80240C24 8E620070 */  lw        $v0, 0x70($s3)
/* A3A108 80240C28 24420001 */  addiu     $v0, $v0, 1
.L80240C2C:
/* A3A10C 80240C2C AE620070 */  sw        $v0, 0x70($s3)
/* A3A110 80240C30 28420014 */  slti      $v0, $v0, 0x14
/* A3A114 80240C34 10400003 */  beqz      $v0, .L80240C44
/* A3A118 80240C38 00000000 */   nop
.L80240C3C:
/* A3A11C 80240C3C 0809033D */  j         .L80240CF4
/* A3A120 80240C40 0000102D */   daddu    $v0, $zero, $zero
.L80240C44:
/* A3A124 80240C44 0C03C54E */  jal       destroy_popup_menu
/* A3A128 80240C48 00000000 */   nop
/* A3A12C 80240C4C 8E630074 */  lw        $v1, 0x74($s3)
/* A3A130 80240C50 240200FF */  addiu     $v0, $zero, 0xff
/* A3A134 80240C54 10620022 */  beq       $v1, $v0, .L80240CE0
/* A3A138 80240C58 2462FFFF */   addiu    $v0, $v1, -1
/* A3A13C 80240C5C 00021080 */  sll       $v0, $v0, 2
/* A3A140 80240C60 02A21021 */  addu      $v0, $s5, $v0
/* A3A144 80240C64 8C520108 */  lw        $s2, 0x108($v0)
/* A3A148 80240C68 3C028024 */  lui       $v0, %hi(D_802435EC_A3CACC)
/* A3A14C 80240C6C 244235EC */  addiu     $v0, $v0, %lo(D_802435EC_A3CACC)
/* A3A150 80240C70 00121840 */  sll       $v1, $s2, 1
/* A3A154 80240C74 00721821 */  addu      $v1, $v1, $s2
/* A3A158 80240C78 00031880 */  sll       $v1, $v1, 2
/* A3A15C 80240C7C 00621821 */  addu      $v1, $v1, $v0
/* A3A160 80240C80 8C620000 */  lw        $v0, ($v1)
/* A3A164 80240C84 AE620084 */  sw        $v0, 0x84($s3)
/* A3A168 80240C88 8C620004 */  lw        $v0, 4($v1)
/* A3A16C 80240C8C AE72008C */  sw        $s2, 0x8c($s3)
/* A3A170 80240C90 AE620088 */  sw        $v0, 0x88($s3)
/* A3A174 80240C94 8C620000 */  lw        $v0, ($v1)
/* A3A178 80240C98 00021140 */  sll       $v0, $v0, 5
/* A3A17C 80240C9C 3C018008 */  lui       $at, %hi(gItemTable)
/* A3A180 80240CA0 00220821 */  addu      $at, $at, $v0
/* A3A184 80240CA4 8C2278E0 */  lw        $v0, %lo(gItemTable)($at)
/* A3A188 80240CA8 AE620094 */  sw        $v0, 0x94($s3)
/* A3A18C 80240CAC 8C620000 */  lw        $v0, ($v1)
/* A3A190 80240CB0 00021140 */  sll       $v0, $v0, 5
/* A3A194 80240CB4 3C038008 */  lui       $v1, %hi(gItemTable+0x1A)
/* A3A198 80240CB8 00621821 */  addu      $v1, $v1, $v0
/* A3A19C 80240CBC 906378FA */  lbu       $v1, %lo(gItemTable+0x1A)($v1)
/* A3A1A0 80240CC0 00031080 */  sll       $v0, $v1, 2
/* A3A1A4 80240CC4 00431021 */  addu      $v0, $v0, $v1
/* A3A1A8 80240CC8 00021080 */  sll       $v0, $v0, 2
/* A3A1AC 80240CCC 3C018009 */  lui       $at, %hi(D_8008F072)
/* A3A1B0 80240CD0 00220821 */  addu      $at, $at, $v0
/* A3A1B4 80240CD4 8022F072 */  lb        $v0, %lo(D_8008F072)($at)
/* A3A1B8 80240CD8 0809033A */  j         .L80240CE8
/* A3A1BC 80240CDC AE620098 */   sw       $v0, 0x98($s3)
.L80240CE0:
/* A3A1C0 80240CE0 2402FFFF */  addiu     $v0, $zero, -1
/* A3A1C4 80240CE4 AE620084 */  sw        $v0, 0x84($s3)
.L80240CE8:
/* A3A1C8 80240CE8 0C00AB4B */  jal       heap_free
/* A3A1CC 80240CEC 8E640078 */   lw       $a0, 0x78($s3)
/* A3A1D0 80240CF0 24020002 */  addiu     $v0, $zero, 2
.L80240CF4:
/* A3A1D4 80240CF4 8FBF0034 */  lw        $ra, 0x34($sp)
/* A3A1D8 80240CF8 8FBE0030 */  lw        $fp, 0x30($sp)
/* A3A1DC 80240CFC 8FB7002C */  lw        $s7, 0x2c($sp)
/* A3A1E0 80240D00 8FB60028 */  lw        $s6, 0x28($sp)
/* A3A1E4 80240D04 8FB50024 */  lw        $s5, 0x24($sp)
/* A3A1E8 80240D08 8FB40020 */  lw        $s4, 0x20($sp)
/* A3A1EC 80240D0C 8FB3001C */  lw        $s3, 0x1c($sp)
/* A3A1F0 80240D10 8FB20018 */  lw        $s2, 0x18($sp)
/* A3A1F4 80240D14 8FB10014 */  lw        $s1, 0x14($sp)
/* A3A1F8 80240D18 8FB00010 */  lw        $s0, 0x10($sp)
/* A3A1FC 80240D1C 03E00008 */  jr        $ra
/* A3A200 80240D20 27BD0038 */   addiu    $sp, $sp, 0x38
/* A3A204 80240D24 00000000 */  nop
/* A3A208 80240D28 00000000 */  nop
/* A3A20C 80240D2C 00000000 */  nop
