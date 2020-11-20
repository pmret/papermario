.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AB4_D8ED04
/* D8ED04 80241AB4 27BDFF98 */  addiu     $sp, $sp, -0x68
/* D8ED08 80241AB8 AFB40058 */  sw        $s4, 0x58($sp)
/* D8ED0C 80241ABC 0080A02D */  daddu     $s4, $a0, $zero
/* D8ED10 80241AC0 AFBF0060 */  sw        $ra, 0x60($sp)
/* D8ED14 80241AC4 AFB5005C */  sw        $s5, 0x5c($sp)
/* D8ED18 80241AC8 AFB30054 */  sw        $s3, 0x54($sp)
/* D8ED1C 80241ACC AFB20050 */  sw        $s2, 0x50($sp)
/* D8ED20 80241AD0 AFB1004C */  sw        $s1, 0x4c($sp)
/* D8ED24 80241AD4 AFB00048 */  sw        $s0, 0x48($sp)
/* D8ED28 80241AD8 8E910148 */  lw        $s1, 0x148($s4)
/* D8ED2C 80241ADC 86240008 */  lh        $a0, 8($s1)
/* D8ED30 80241AE0 0C00EABB */  jal       get_npc_unsafe
/* D8ED34 80241AE4 00A0802D */   daddu    $s0, $a1, $zero
/* D8ED38 80241AE8 8E83000C */  lw        $v1, 0xc($s4)
/* D8ED3C 80241AEC 0280202D */  daddu     $a0, $s4, $zero
/* D8ED40 80241AF0 8C650000 */  lw        $a1, ($v1)
/* D8ED44 80241AF4 0C0B1EAF */  jal       get_variable
/* D8ED48 80241AF8 0040902D */   daddu    $s2, $v0, $zero
/* D8ED4C 80241AFC AFA00018 */  sw        $zero, 0x18($sp)
/* D8ED50 80241B00 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D8ED54 80241B04 8C630094 */  lw        $v1, 0x94($v1)
/* D8ED58 80241B08 AFA3001C */  sw        $v1, 0x1c($sp)
/* D8ED5C 80241B0C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D8ED60 80241B10 8C630080 */  lw        $v1, 0x80($v1)
/* D8ED64 80241B14 AFA30020 */  sw        $v1, 0x20($sp)
/* D8ED68 80241B18 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D8ED6C 80241B1C 8C630088 */  lw        $v1, 0x88($v1)
/* D8ED70 80241B20 AFA30024 */  sw        $v1, 0x24($sp)
/* D8ED74 80241B24 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D8ED78 80241B28 8C63008C */  lw        $v1, 0x8c($v1)
/* D8ED7C 80241B2C 27B50018 */  addiu     $s5, $sp, 0x18
/* D8ED80 80241B30 AFA30028 */  sw        $v1, 0x28($sp)
/* D8ED84 80241B34 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D8ED88 80241B38 3C014282 */  lui       $at, 0x4282
/* D8ED8C 80241B3C 44810000 */  mtc1      $at, $f0
/* D8ED90 80241B40 8C630090 */  lw        $v1, 0x90($v1)
/* D8ED94 80241B44 0040982D */  daddu     $s3, $v0, $zero
/* D8ED98 80241B48 E7A00030 */  swc1      $f0, 0x30($sp)
/* D8ED9C 80241B4C A7A00034 */  sh        $zero, 0x34($sp)
/* D8EDA0 80241B50 16000005 */  bnez      $s0, .L80241B68
/* D8EDA4 80241B54 AFA3002C */   sw       $v1, 0x2c($sp)
/* D8EDA8 80241B58 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D8EDAC 80241B5C 30420004 */  andi      $v0, $v0, 4
/* D8EDB0 80241B60 10400044 */  beqz      $v0, .L80241C74
/* D8EDB4 80241B64 00000000 */   nop      
.L80241B68:
/* D8EDB8 80241B68 2404F7FF */  addiu     $a0, $zero, -0x801
/* D8EDBC 80241B6C AE800070 */  sw        $zero, 0x70($s4)
/* D8EDC0 80241B70 A640008E */  sh        $zero, 0x8e($s2)
/* D8EDC4 80241B74 8E2200CC */  lw        $v0, 0xcc($s1)
/* D8EDC8 80241B78 8E430000 */  lw        $v1, ($s2)
/* D8EDCC 80241B7C 8C420000 */  lw        $v0, ($v0)
/* D8EDD0 80241B80 00641824 */  and       $v1, $v1, $a0
/* D8EDD4 80241B84 AE430000 */  sw        $v1, ($s2)
/* D8EDD8 80241B88 AE420028 */  sw        $v0, 0x28($s2)
/* D8EDDC 80241B8C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* D8EDE0 80241B90 8C420098 */  lw        $v0, 0x98($v0)
/* D8EDE4 80241B94 54400005 */  bnel      $v0, $zero, .L80241BAC
/* D8EDE8 80241B98 2402FDFF */   addiu    $v0, $zero, -0x201
/* D8EDEC 80241B9C 34620200 */  ori       $v0, $v1, 0x200
/* D8EDF0 80241BA0 2403FFF7 */  addiu     $v1, $zero, -9
/* D8EDF4 80241BA4 080906ED */  j         .L80241BB4
/* D8EDF8 80241BA8 00431024 */   and      $v0, $v0, $v1
.L80241BAC:
/* D8EDFC 80241BAC 00621024 */  and       $v0, $v1, $v0
/* D8EE00 80241BB0 34420008 */  ori       $v0, $v0, 8
.L80241BB4:
/* D8EE04 80241BB4 AE420000 */  sw        $v0, ($s2)
/* D8EE08 80241BB8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D8EE0C 80241BBC 30420004 */  andi      $v0, $v0, 4
/* D8EE10 80241BC0 10400008 */  beqz      $v0, .L80241BE4
/* D8EE14 80241BC4 24020063 */   addiu    $v0, $zero, 0x63
/* D8EE18 80241BC8 AE820070 */  sw        $v0, 0x70($s4)
/* D8EE1C 80241BCC AE800074 */  sw        $zero, 0x74($s4)
/* D8EE20 80241BD0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D8EE24 80241BD4 2403FFFB */  addiu     $v1, $zero, -5
/* D8EE28 80241BD8 00431024 */  and       $v0, $v0, $v1
/* D8EE2C 80241BDC 08090704 */  j         .L80241C10
/* D8EE30 80241BE0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80241BE4:
/* D8EE34 80241BE4 8E220000 */  lw        $v0, ($s1)
/* D8EE38 80241BE8 3C034000 */  lui       $v1, 0x4000
/* D8EE3C 80241BEC 00431024 */  and       $v0, $v0, $v1
/* D8EE40 80241BF0 10400007 */  beqz      $v0, .L80241C10
/* D8EE44 80241BF4 3C03BFFF */   lui      $v1, 0xbfff
/* D8EE48 80241BF8 2402000C */  addiu     $v0, $zero, 0xc
/* D8EE4C 80241BFC AE820070 */  sw        $v0, 0x70($s4)
/* D8EE50 80241C00 8E220000 */  lw        $v0, ($s1)
/* D8EE54 80241C04 3463FFFF */  ori       $v1, $v1, 0xffff
/* D8EE58 80241C08 00431024 */  and       $v0, $v0, $v1
/* D8EE5C 80241C0C AE220000 */  sw        $v0, ($s1)
.L80241C10:
/* D8EE60 80241C10 27A50038 */  addiu     $a1, $sp, 0x38
/* D8EE64 80241C14 27A6003C */  addiu     $a2, $sp, 0x3c
/* D8EE68 80241C18 C6400038 */  lwc1      $f0, 0x38($s2)
/* D8EE6C 80241C1C 864200A8 */  lh        $v0, 0xa8($s2)
/* D8EE70 80241C20 3C0142C8 */  lui       $at, 0x42c8
/* D8EE74 80241C24 44812000 */  mtc1      $at, $f4
/* D8EE78 80241C28 44823000 */  mtc1      $v0, $f6
/* D8EE7C 80241C2C 00000000 */  nop       
/* D8EE80 80241C30 468031A0 */  cvt.s.w   $f6, $f6
/* D8EE84 80241C34 27A20044 */  addiu     $v0, $sp, 0x44
/* D8EE88 80241C38 E7A00038 */  swc1      $f0, 0x38($sp)
/* D8EE8C 80241C3C C640003C */  lwc1      $f0, 0x3c($s2)
/* D8EE90 80241C40 C6420040 */  lwc1      $f2, 0x40($s2)
/* D8EE94 80241C44 46060000 */  add.s     $f0, $f0, $f6
/* D8EE98 80241C48 E7A40044 */  swc1      $f4, 0x44($sp)
/* D8EE9C 80241C4C E7A20040 */  swc1      $f2, 0x40($sp)
/* D8EEA0 80241C50 E7A0003C */  swc1      $f0, 0x3c($sp)
/* D8EEA4 80241C54 AFA20010 */  sw        $v0, 0x10($sp)
/* D8EEA8 80241C58 8E440080 */  lw        $a0, 0x80($s2)
/* D8EEAC 80241C5C 0C0372DF */  jal       func_800DCB7C
/* D8EEB0 80241C60 27A70040 */   addiu    $a3, $sp, 0x40
/* D8EEB4 80241C64 10400003 */  beqz      $v0, .L80241C74
/* D8EEB8 80241C68 00000000 */   nop      
/* D8EEBC 80241C6C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* D8EEC0 80241C70 E640003C */  swc1      $f0, 0x3c($s2)
.L80241C74:
/* D8EEC4 80241C74 8E830070 */  lw        $v1, 0x70($s4)
/* D8EEC8 80241C78 2C620064 */  sltiu     $v0, $v1, 0x64
/* D8EECC 80241C7C 10400042 */  beqz      $v0, .L80241D88
/* D8EED0 80241C80 00031080 */   sll      $v0, $v1, 2
/* D8EED4 80241C84 3C018024 */  lui       $at, 0x8024
/* D8EED8 80241C88 00220821 */  addu      $at, $at, $v0
/* D8EEDC 80241C8C 8C223FF0 */  lw        $v0, 0x3ff0($at)
/* D8EEE0 80241C90 00400008 */  jr        $v0
/* D8EEE4 80241C94 00000000 */   nop      
/* D8EEE8 80241C98 0280202D */  daddu     $a0, $s4, $zero
/* D8EEEC 80241C9C 0260282D */  daddu     $a1, $s3, $zero
/* D8EEF0 80241CA0 0C0903C8 */  jal       func_80240F20_D8E170
/* D8EEF4 80241CA4 02A0302D */   daddu    $a2, $s5, $zero
/* D8EEF8 80241CA8 0280202D */  daddu     $a0, $s4, $zero
/* D8EEFC 80241CAC 0260282D */  daddu     $a1, $s3, $zero
/* D8EF00 80241CB0 0C09041E */  jal       func_80241078_D8E2C8
/* D8EF04 80241CB4 02A0302D */   daddu    $a2, $s5, $zero
/* D8EF08 80241CB8 08090762 */  j         .L80241D88
/* D8EF0C 80241CBC 00000000 */   nop      
/* D8EF10 80241CC0 0280202D */  daddu     $a0, $s4, $zero
/* D8EF14 80241CC4 0260282D */  daddu     $a1, $s3, $zero
/* D8EF18 80241CC8 0C0904C8 */  jal       UnkNpcAIFunc1
/* D8EF1C 80241CCC 02A0302D */   daddu    $a2, $s5, $zero
/* D8EF20 80241CD0 0280202D */  daddu     $a0, $s4, $zero
/* D8EF24 80241CD4 0260282D */  daddu     $a1, $s3, $zero
/* D8EF28 80241CD8 0C0904F8 */  jal       func_802413E0_D8E630
/* D8EF2C 80241CDC 02A0302D */   daddu    $a2, $s5, $zero
/* D8EF30 80241CE0 08090762 */  j         .L80241D88
/* D8EF34 80241CE4 00000000 */   nop      
/* D8EF38 80241CE8 0280202D */  daddu     $a0, $s4, $zero
/* D8EF3C 80241CEC 0260282D */  daddu     $a1, $s3, $zero
/* D8EF40 80241CF0 0C090567 */  jal       func_8024159C_D8E7EC
/* D8EF44 80241CF4 02A0302D */   daddu    $a2, $s5, $zero
/* D8EF48 80241CF8 08090762 */  j         .L80241D88
/* D8EF4C 80241CFC 00000000 */   nop      
/* D8EF50 80241D00 0280202D */  daddu     $a0, $s4, $zero
/* D8EF54 80241D04 0260282D */  daddu     $a1, $s3, $zero
/* D8EF58 80241D08 0C090594 */  jal       func_80241650_D8E8A0
/* D8EF5C 80241D0C 02A0302D */   daddu    $a2, $s5, $zero
/* D8EF60 80241D10 0280202D */  daddu     $a0, $s4, $zero
/* D8EF64 80241D14 0260282D */  daddu     $a1, $s3, $zero
/* D8EF68 80241D18 0C0905B1 */  jal       func_802416C4_D8E914
/* D8EF6C 80241D1C 02A0302D */   daddu    $a2, $s5, $zero
/* D8EF70 80241D20 08090762 */  j         .L80241D88
/* D8EF74 80241D24 00000000 */   nop      
/* D8EF78 80241D28 0280202D */  daddu     $a0, $s4, $zero
/* D8EF7C 80241D2C 0260282D */  daddu     $a1, $s3, $zero
/* D8EF80 80241D30 0C0905CF */  jal       func_8024173C_D8E98C
/* D8EF84 80241D34 02A0302D */   daddu    $a2, $s5, $zero
/* D8EF88 80241D38 0280202D */  daddu     $a0, $s4, $zero
/* D8EF8C 80241D3C 0260282D */  daddu     $a1, $s3, $zero
/* D8EF90 80241D40 0C09061B */  jal       func_8024186C_D8EABC
/* D8EF94 80241D44 02A0302D */   daddu    $a2, $s5, $zero
/* D8EF98 80241D48 08090762 */  j         .L80241D88
/* D8EF9C 80241D4C 00000000 */   nop      
/* D8EFA0 80241D50 0280202D */  daddu     $a0, $s4, $zero
/* D8EFA4 80241D54 0260282D */  daddu     $a1, $s3, $zero
/* D8EFA8 80241D58 0C090663 */  jal       func_8024198C_D8EBDC
/* D8EFAC 80241D5C 02A0302D */   daddu    $a2, $s5, $zero
/* D8EFB0 80241D60 08090762 */  j         .L80241D88
/* D8EFB4 80241D64 00000000 */   nop      
/* D8EFB8 80241D68 0280202D */  daddu     $a0, $s4, $zero
/* D8EFBC 80241D6C 0260282D */  daddu     $a1, $s3, $zero
/* D8EFC0 80241D70 0C09067D */  jal       func_802419F4_D8EC44
/* D8EFC4 80241D74 02A0302D */   daddu    $a2, $s5, $zero
/* D8EFC8 80241D78 08090762 */  j         .L80241D88
/* D8EFCC 80241D7C 00000000 */   nop      
/* D8EFD0 80241D80 0C0129CF */  jal       func_8004A73C
/* D8EFD4 80241D84 0280202D */   daddu    $a0, $s4, $zero
.L80241D88:
/* D8EFD8 80241D88 8FBF0060 */  lw        $ra, 0x60($sp)
/* D8EFDC 80241D8C 8FB5005C */  lw        $s5, 0x5c($sp)
/* D8EFE0 80241D90 8FB40058 */  lw        $s4, 0x58($sp)
/* D8EFE4 80241D94 8FB30054 */  lw        $s3, 0x54($sp)
/* D8EFE8 80241D98 8FB20050 */  lw        $s2, 0x50($sp)
/* D8EFEC 80241D9C 8FB1004C */  lw        $s1, 0x4c($sp)
/* D8EFF0 80241DA0 8FB00048 */  lw        $s0, 0x48($sp)
/* D8EFF4 80241DA4 0000102D */  daddu     $v0, $zero, $zero
/* D8EFF8 80241DA8 03E00008 */  jr        $ra
/* D8EFFC 80241DAC 27BD0068 */   addiu    $sp, $sp, 0x68
