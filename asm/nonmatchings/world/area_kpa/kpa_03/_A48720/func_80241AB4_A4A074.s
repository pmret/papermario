.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AB4_A4A074
/* A4A074 80241AB4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A4A078 80241AB8 AFB50044 */  sw        $s5, 0x44($sp)
/* A4A07C 80241ABC 0080A82D */  daddu     $s5, $a0, $zero
/* A4A080 80241AC0 AFBF0048 */  sw        $ra, 0x48($sp)
/* A4A084 80241AC4 AFB40040 */  sw        $s4, 0x40($sp)
/* A4A088 80241AC8 AFB3003C */  sw        $s3, 0x3c($sp)
/* A4A08C 80241ACC AFB20038 */  sw        $s2, 0x38($sp)
/* A4A090 80241AD0 AFB10034 */  sw        $s1, 0x34($sp)
/* A4A094 80241AD4 AFB00030 */  sw        $s0, 0x30($sp)
/* A4A098 80241AD8 8EB10148 */  lw        $s1, 0x148($s5)
/* A4A09C 80241ADC 86240008 */  lh        $a0, 8($s1)
/* A4A0A0 80241AE0 0C00EABB */  jal       get_npc_unsafe
/* A4A0A4 80241AE4 00A0802D */   daddu    $s0, $a1, $zero
/* A4A0A8 80241AE8 8EA3000C */  lw        $v1, 0xc($s5)
/* A4A0AC 80241AEC 02A0202D */  daddu     $a0, $s5, $zero
/* A4A0B0 80241AF0 8C650000 */  lw        $a1, ($v1)
/* A4A0B4 80241AF4 0C0B1EAF */  jal       get_variable
/* A4A0B8 80241AF8 0040902D */   daddu    $s2, $v0, $zero
/* A4A0BC 80241AFC AFA00010 */  sw        $zero, 0x10($sp)
/* A4A0C0 80241B00 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A4A0C4 80241B04 8C630030 */  lw        $v1, 0x30($v1)
/* A4A0C8 80241B08 AFA30014 */  sw        $v1, 0x14($sp)
/* A4A0CC 80241B0C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A4A0D0 80241B10 8C63001C */  lw        $v1, 0x1c($v1)
/* A4A0D4 80241B14 AFA30018 */  sw        $v1, 0x18($sp)
/* A4A0D8 80241B18 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A4A0DC 80241B1C 8C630024 */  lw        $v1, 0x24($v1)
/* A4A0E0 80241B20 AFA3001C */  sw        $v1, 0x1c($sp)
/* A4A0E4 80241B24 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A4A0E8 80241B28 8C630028 */  lw        $v1, 0x28($v1)
/* A4A0EC 80241B2C 27B40010 */  addiu     $s4, $sp, 0x10
/* A4A0F0 80241B30 AFA30020 */  sw        $v1, 0x20($sp)
/* A4A0F4 80241B34 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A4A0F8 80241B38 3C0142C8 */  lui       $at, 0x42c8
/* A4A0FC 80241B3C 44810000 */  mtc1      $at, $f0
/* A4A100 80241B40 8C63002C */  lw        $v1, 0x2c($v1)
/* A4A104 80241B44 0040982D */  daddu     $s3, $v0, $zero
/* A4A108 80241B48 E7A00028 */  swc1      $f0, 0x28($sp)
/* A4A10C 80241B4C A7A0002C */  sh        $zero, 0x2c($sp)
/* A4A110 80241B50 16000005 */  bnez      $s0, .L80241B68
/* A4A114 80241B54 AFA30024 */   sw       $v1, 0x24($sp)
/* A4A118 80241B58 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A4A11C 80241B5C 30420004 */  andi      $v0, $v0, 4
/* A4A120 80241B60 1040001E */  beqz      $v0, .L80241BDC
/* A4A124 80241B64 00000000 */   nop      
.L80241B68:
/* A4A128 80241B68 8E430000 */  lw        $v1, ($s2)
/* A4A12C 80241B6C 2402F7FF */  addiu     $v0, $zero, -0x801
/* A4A130 80241B70 00621824 */  and       $v1, $v1, $v0
/* A4A134 80241B74 8E2200CC */  lw        $v0, 0xcc($s1)
/* A4A138 80241B78 3C040020 */  lui       $a0, 0x20
/* A4A13C 80241B7C 8C420000 */  lw        $v0, ($v0)
/* A4A140 80241B80 00641825 */  or        $v1, $v1, $a0
/* A4A144 80241B84 AE430000 */  sw        $v1, ($s2)
/* A4A148 80241B88 AE420028 */  sw        $v0, 0x28($s2)
/* A4A14C 80241B8C 8E220000 */  lw        $v0, ($s1)
/* A4A150 80241B90 00441025 */  or        $v0, $v0, $a0
/* A4A154 80241B94 AE220000 */  sw        $v0, ($s1)
/* A4A158 80241B98 A640008E */  sh        $zero, 0x8e($s2)
/* A4A15C 80241B9C 8E2300B0 */  lw        $v1, 0xb0($s1)
/* A4A160 80241BA0 30620004 */  andi      $v0, $v1, 4
/* A4A164 80241BA4 1040000C */  beqz      $v0, .L80241BD8
/* A4A168 80241BA8 2402FFFB */   addiu    $v0, $zero, -5
/* A4A16C 80241BAC 3C013F80 */  lui       $at, 0x3f80
/* A4A170 80241BB0 44810000 */  mtc1      $at, $f0
/* A4A174 80241BB4 00621024 */  and       $v0, $v1, $v0
/* A4A178 80241BB8 AE2200B0 */  sw        $v0, 0xb0($s1)
/* A4A17C 80241BBC 240200FF */  addiu     $v0, $zero, 0xff
/* A4A180 80241BC0 A24200AC */  sb        $v0, 0xac($s2)
/* A4A184 80241BC4 24020014 */  addiu     $v0, $zero, 0x14
/* A4A188 80241BC8 A642008E */  sh        $v0, 0x8e($s2)
/* A4A18C 80241BCC E6400054 */  swc1      $f0, 0x54($s2)
/* A4A190 80241BD0 E6400058 */  swc1      $f0, 0x58($s2)
/* A4A194 80241BD4 E640005C */  swc1      $f0, 0x5c($s2)
.L80241BD8:
/* A4A198 80241BD8 AEA00070 */  sw        $zero, 0x70($s5)
.L80241BDC:
/* A4A19C 80241BDC 8EA30070 */  lw        $v1, 0x70($s5)
/* A4A1A0 80241BE0 2C620019 */  sltiu     $v0, $v1, 0x19
/* A4A1A4 80241BE4 10400044 */  beqz      $v0, .L80241CF8
/* A4A1A8 80241BE8 00031080 */   sll      $v0, $v1, 2
/* A4A1AC 80241BEC 3C018024 */  lui       $at, 0x8024
/* A4A1B0 80241BF0 00220821 */  addu      $at, $at, $v0
/* A4A1B4 80241BF4 8C223930 */  lw        $v0, 0x3930($at)
/* A4A1B8 80241BF8 00400008 */  jr        $v0
/* A4A1BC 80241BFC 00000000 */   nop      
/* A4A1C0 80241C00 02A0202D */  daddu     $a0, $s5, $zero
/* A4A1C4 80241C04 0260282D */  daddu     $a1, $s3, $zero
/* A4A1C8 80241C08 0C09044A */  jal       func_80241128
/* A4A1CC 80241C0C 0280302D */   daddu    $a2, $s4, $zero
/* A4A1D0 80241C10 8EA30070 */  lw        $v1, 0x70($s5)
/* A4A1D4 80241C14 24020001 */  addiu     $v0, $zero, 1
/* A4A1D8 80241C18 14620037 */  bne       $v1, $v0, .L80241CF8
/* A4A1DC 80241C1C 00000000 */   nop      
/* A4A1E0 80241C20 02A0202D */  daddu     $a0, $s5, $zero
/* A4A1E4 80241C24 0260282D */  daddu     $a1, $s3, $zero
/* A4A1E8 80241C28 0C090467 */  jal       func_8024119C
/* A4A1EC 80241C2C 0280302D */   daddu    $a2, $s4, $zero
/* A4A1F0 80241C30 0809073E */  j         .L80241CF8
/* A4A1F4 80241C34 00000000 */   nop      
/* A4A1F8 80241C38 02A0202D */  daddu     $a0, $s5, $zero
/* A4A1FC 80241C3C 0260282D */  daddu     $a1, $s3, $zero
/* A4A200 80241C40 0C0904B2 */  jal       func_802412C8
/* A4A204 80241C44 0280302D */   daddu    $a2, $s4, $zero
/* A4A208 80241C48 02A0202D */  daddu     $a0, $s5, $zero
/* A4A20C 80241C4C 0260282D */  daddu     $a1, $s3, $zero
/* A4A210 80241C50 0C0904DA */  jal       func_80241368
/* A4A214 80241C54 0280302D */   daddu    $a2, $s4, $zero
/* A4A218 80241C58 0809073E */  j         .L80241CF8
/* A4A21C 80241C5C 00000000 */   nop      
/* A4A220 80241C60 02A0202D */  daddu     $a0, $s5, $zero
/* A4A224 80241C64 0260282D */  daddu     $a1, $s3, $zero
/* A4A228 80241C68 0C0904F3 */  jal       func_802413CC
/* A4A22C 80241C6C 0280302D */   daddu    $a2, $s4, $zero
/* A4A230 80241C70 02A0202D */  daddu     $a0, $s5, $zero
/* A4A234 80241C74 0260282D */  daddu     $a1, $s3, $zero
/* A4A238 80241C78 0C090543 */  jal       func_8024150C
/* A4A23C 80241C7C 0280302D */   daddu    $a2, $s4, $zero
/* A4A240 80241C80 0809073E */  j         .L80241CF8
/* A4A244 80241C84 00000000 */   nop      
/* A4A248 80241C88 02A0202D */  daddu     $a0, $s5, $zero
/* A4A24C 80241C8C 0260282D */  daddu     $a1, $s3, $zero
/* A4A250 80241C90 0C0905AC */  jal       func_802416B0
/* A4A254 80241C94 0280302D */   daddu    $a2, $s4, $zero
/* A4A258 80241C98 0809073E */  j         .L80241CF8
/* A4A25C 80241C9C 00000000 */   nop      
/* A4A260 80241CA0 02A0202D */  daddu     $a0, $s5, $zero
/* A4A264 80241CA4 0260282D */  daddu     $a1, $s3, $zero
/* A4A268 80241CA8 0C0905BB */  jal       func_802416EC
/* A4A26C 80241CAC 0280302D */   daddu    $a2, $s4, $zero
/* A4A270 80241CB0 0809073E */  j         .L80241CF8
/* A4A274 80241CB4 00000000 */   nop      
/* A4A278 80241CB8 02A0202D */  daddu     $a0, $s5, $zero
/* A4A27C 80241CBC 0260282D */  daddu     $a1, $s3, $zero
/* A4A280 80241CC0 0C09062B */  jal       func_802418AC
/* A4A284 80241CC4 0280302D */   daddu    $a2, $s4, $zero
/* A4A288 80241CC8 0809073E */  j         .L80241CF8
/* A4A28C 80241CCC 00000000 */   nop      
/* A4A290 80241CD0 02A0202D */  daddu     $a0, $s5, $zero
/* A4A294 80241CD4 0260282D */  daddu     $a1, $s3, $zero
/* A4A298 80241CD8 0C090646 */  jal       func_80241918
/* A4A29C 80241CDC 0280302D */   daddu    $a2, $s4, $zero
/* A4A2A0 80241CE0 0809073E */  j         .L80241CF8
/* A4A2A4 80241CE4 00000000 */   nop      
/* A4A2A8 80241CE8 02A0202D */  daddu     $a0, $s5, $zero
/* A4A2AC 80241CEC 0260282D */  daddu     $a1, $s3, $zero
/* A4A2B0 80241CF0 0C090693 */  jal       func_80241A4C
/* A4A2B4 80241CF4 0280302D */   daddu    $a2, $s4, $zero
.L80241CF8:
/* A4A2B8 80241CF8 8FBF0048 */  lw        $ra, 0x48($sp)
/* A4A2BC 80241CFC 8FB50044 */  lw        $s5, 0x44($sp)
/* A4A2C0 80241D00 8FB40040 */  lw        $s4, 0x40($sp)
/* A4A2C4 80241D04 8FB3003C */  lw        $s3, 0x3c($sp)
/* A4A2C8 80241D08 8FB20038 */  lw        $s2, 0x38($sp)
/* A4A2CC 80241D0C 8FB10034 */  lw        $s1, 0x34($sp)
/* A4A2D0 80241D10 8FB00030 */  lw        $s0, 0x30($sp)
/* A4A2D4 80241D14 0000102D */  daddu     $v0, $zero, $zero
/* A4A2D8 80241D18 03E00008 */  jr        $ra
/* A4A2DC 80241D1C 27BD0050 */   addiu    $sp, $sp, 0x50
