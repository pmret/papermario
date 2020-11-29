.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A90_853C00
/* 853C00 80241A90 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 853C04 80241A94 AFB1001C */  sw        $s1, 0x1c($sp)
/* 853C08 80241A98 AFBF0020 */  sw        $ra, 0x20($sp)
/* 853C0C 80241A9C AFB00018 */  sw        $s0, 0x18($sp)
/* 853C10 80241AA0 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 853C14 80241AA4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 853C18 80241AA8 10A00060 */  beqz      $a1, .L80241C2C
/* 853C1C 80241AAC 0080882D */   daddu    $s1, $a0, $zero
/* 853C20 80241AB0 3C05F4AC */  lui       $a1, 0xf4ac
/* 853C24 80241AB4 0C0B1EAF */  jal       get_variable
/* 853C28 80241AB8 34A5D481 */   ori      $a1, $a1, 0xd481
/* 853C2C 80241ABC 0220202D */  daddu     $a0, $s1, $zero
/* 853C30 80241AC0 3C05F4AC */  lui       $a1, 0xf4ac
/* 853C34 80241AC4 4482B000 */  mtc1      $v0, $f22
/* 853C38 80241AC8 00000000 */  nop       
/* 853C3C 80241ACC 4680B5A0 */  cvt.s.w   $f22, $f22
/* 853C40 80241AD0 0C0B1EAF */  jal       get_variable
/* 853C44 80241AD4 34A5D482 */   ori      $a1, $a1, 0xd482
/* 853C48 80241AD8 0220202D */  daddu     $a0, $s1, $zero
/* 853C4C 80241ADC 3C05F4AC */  lui       $a1, 0xf4ac
/* 853C50 80241AE0 4482A000 */  mtc1      $v0, $f20
/* 853C54 80241AE4 00000000 */  nop       
/* 853C58 80241AE8 4680A520 */  cvt.s.w   $f20, $f20
/* 853C5C 80241AEC 0C0B1EAF */  jal       get_variable
/* 853C60 80241AF0 34A5D483 */   ori      $a1, $a1, 0xd483
/* 853C64 80241AF4 44821000 */  mtc1      $v0, $f2
/* 853C68 80241AF8 00000000 */  nop       
/* 853C6C 80241AFC 468010A0 */  cvt.s.w   $f2, $f2
/* 853C70 80241B00 4405B000 */  mfc1      $a1, $f22
/* 853C74 80241B04 4406A000 */  mfc1      $a2, $f20
/* 853C78 80241B08 44071000 */  mfc1      $a3, $f2
/* 853C7C 80241B0C 0C01C574 */  jal       func_800715D0
/* 853C80 80241B10 0000202D */   daddu    $a0, $zero, $zero
/* 853C84 80241B14 0220202D */  daddu     $a0, $s1, $zero
/* 853C88 80241B18 3C05F4AC */  lui       $a1, 0xf4ac
/* 853C8C 80241B1C 34A5D481 */  ori       $a1, $a1, 0xd481
/* 853C90 80241B20 3C108025 */  lui       $s0, %hi(D_802529F0)
/* 853C94 80241B24 261029F0 */  addiu     $s0, $s0, %lo(D_802529F0)
/* 853C98 80241B28 0C0B1EAF */  jal       get_variable
/* 853C9C 80241B2C AE020000 */   sw       $v0, ($s0)
/* 853CA0 80241B30 0220202D */  daddu     $a0, $s1, $zero
/* 853CA4 80241B34 3C05F4AC */  lui       $a1, 0xf4ac
/* 853CA8 80241B38 4482B000 */  mtc1      $v0, $f22
/* 853CAC 80241B3C 00000000 */  nop       
/* 853CB0 80241B40 4680B5A0 */  cvt.s.w   $f22, $f22
/* 853CB4 80241B44 0C0B1EAF */  jal       get_variable
/* 853CB8 80241B48 34A5D482 */   ori      $a1, $a1, 0xd482
/* 853CBC 80241B4C 0220202D */  daddu     $a0, $s1, $zero
/* 853CC0 80241B50 3C05F4AC */  lui       $a1, 0xf4ac
/* 853CC4 80241B54 4482A000 */  mtc1      $v0, $f20
/* 853CC8 80241B58 00000000 */  nop       
/* 853CCC 80241B5C 4680A520 */  cvt.s.w   $f20, $f20
/* 853CD0 80241B60 0C0B1EAF */  jal       get_variable
/* 853CD4 80241B64 34A5D483 */   ori      $a1, $a1, 0xd483
/* 853CD8 80241B68 44821000 */  mtc1      $v0, $f2
/* 853CDC 80241B6C 00000000 */  nop       
/* 853CE0 80241B70 468010A0 */  cvt.s.w   $f2, $f2
/* 853CE4 80241B74 4405B000 */  mfc1      $a1, $f22
/* 853CE8 80241B78 4406A000 */  mfc1      $a2, $f20
/* 853CEC 80241B7C 44071000 */  mfc1      $a3, $f2
/* 853CF0 80241B80 0C01C604 */  jal       func_80071810
/* 853CF4 80241B84 0000202D */   daddu    $a0, $zero, $zero
/* 853CF8 80241B88 0220202D */  daddu     $a0, $s1, $zero
/* 853CFC 80241B8C 3C05F4AC */  lui       $a1, 0xf4ac
/* 853D00 80241B90 3C018025 */  lui       $at, %hi(D_802529F4)
/* 853D04 80241B94 AC2229F4 */  sw        $v0, %lo(D_802529F4)($at)
/* 853D08 80241B98 0C0B1EAF */  jal       get_variable
/* 853D0C 80241B9C 34A5D481 */   ori      $a1, $a1, 0xd481
/* 853D10 80241BA0 0220202D */  daddu     $a0, $s1, $zero
/* 853D14 80241BA4 3C05F4AC */  lui       $a1, 0xf4ac
/* 853D18 80241BA8 4482B000 */  mtc1      $v0, $f22
/* 853D1C 80241BAC 00000000 */  nop       
/* 853D20 80241BB0 4680B5A0 */  cvt.s.w   $f22, $f22
/* 853D24 80241BB4 0C0B1EAF */  jal       get_variable
/* 853D28 80241BB8 34A5D482 */   ori      $a1, $a1, 0xd482
/* 853D2C 80241BBC 0220202D */  daddu     $a0, $s1, $zero
/* 853D30 80241BC0 3C05F4AC */  lui       $a1, 0xf4ac
/* 853D34 80241BC4 4482A000 */  mtc1      $v0, $f20
/* 853D38 80241BC8 00000000 */  nop       
/* 853D3C 80241BCC 4680A520 */  cvt.s.w   $f20, $f20
/* 853D40 80241BD0 0C0B1EAF */  jal       get_variable
/* 853D44 80241BD4 34A5D483 */   ori      $a1, $a1, 0xd483
/* 853D48 80241BD8 44821000 */  mtc1      $v0, $f2
/* 853D4C 80241BDC 00000000 */  nop       
/* 853D50 80241BE0 468010A0 */  cvt.s.w   $f2, $f2
/* 853D54 80241BE4 4405B000 */  mfc1      $a1, $f22
/* 853D58 80241BE8 4406A000 */  mfc1      $a2, $f20
/* 853D5C 80241BEC 3C013F80 */  lui       $at, 0x3f80
/* 853D60 80241BF0 44810000 */  mtc1      $at, $f0
/* 853D64 80241BF4 44071000 */  mfc1      $a3, $f2
/* 853D68 80241BF8 0000202D */  daddu     $a0, $zero, $zero
/* 853D6C 80241BFC AFA00014 */  sw        $zero, 0x14($sp)
/* 853D70 80241C00 0C01CA24 */  jal       func_80072890
/* 853D74 80241C04 E7A00010 */   swc1     $f0, 0x10($sp)
/* 853D78 80241C08 8E030000 */  lw        $v1, ($s0)
/* 853D7C 80241C0C 8C64000C */  lw        $a0, 0xc($v1)
/* 853D80 80241C10 3C018025 */  lui       $at, %hi(D_802529F8)
/* 853D84 80241C14 AC2229F8 */  sw        $v0, %lo(D_802529F8)($at)
/* 853D88 80241C18 AC800018 */  sw        $zero, 0x18($a0)
/* 853D8C 80241C1C AC800020 */  sw        $zero, 0x20($a0)
/* 853D90 80241C20 AC800024 */  sw        $zero, 0x24($a0)
/* 853D94 80241C24 AC800028 */  sw        $zero, 0x28($a0)
/* 853D98 80241C28 AC80001C */  sw        $zero, 0x1c($a0)
.L80241C2C:
/* 853D9C 80241C2C 3C028025 */  lui       $v0, %hi(D_802529F0)
/* 853DA0 80241C30 8C4229F0 */  lw        $v0, %lo(D_802529F0)($v0)
/* 853DA4 80241C34 8C44000C */  lw        $a0, 0xc($v0)
/* 853DA8 80241C38 8C820020 */  lw        $v0, 0x20($a0)
/* 853DAC 80241C3C 8C830028 */  lw        $v1, 0x28($a0)
/* 853DB0 80241C40 2442000A */  addiu     $v0, $v0, 0xa
/* 853DB4 80241C44 AC820020 */  sw        $v0, 0x20($a0)
/* 853DB8 80241C48 8C820024 */  lw        $v0, 0x24($a0)
/* 853DBC 80241C4C 2463000A */  addiu     $v1, $v1, 0xa
/* 853DC0 80241C50 AC830028 */  sw        $v1, 0x28($a0)
/* 853DC4 80241C54 8C830018 */  lw        $v1, 0x18($a0)
/* 853DC8 80241C58 2442000A */  addiu     $v0, $v0, 0xa
/* 853DCC 80241C5C AC820024 */  sw        $v0, 0x24($a0)
/* 853DD0 80241C60 8C82001C */  lw        $v0, 0x1c($a0)
/* 853DD4 80241C64 2463000A */  addiu     $v1, $v1, 0xa
/* 853DD8 80241C68 AC830018 */  sw        $v1, 0x18($a0)
/* 853DDC 80241C6C 286300FF */  slti      $v1, $v1, 0xff
/* 853DE0 80241C70 2442000A */  addiu     $v0, $v0, 0xa
/* 853DE4 80241C74 AC82001C */  sw        $v0, 0x1c($a0)
/* 853DE8 80241C78 14600004 */  bnez      $v1, .L80241C8C
/* 853DEC 80241C7C 0000102D */   daddu    $v0, $zero, $zero
/* 853DF0 80241C80 240200FF */  addiu     $v0, $zero, 0xff
/* 853DF4 80241C84 AC820018 */  sw        $v0, 0x18($a0)
/* 853DF8 80241C88 24020002 */  addiu     $v0, $zero, 2
.L80241C8C:
/* 853DFC 80241C8C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 853E00 80241C90 8FB1001C */  lw        $s1, 0x1c($sp)
/* 853E04 80241C94 8FB00018 */  lw        $s0, 0x18($sp)
/* 853E08 80241C98 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 853E0C 80241C9C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 853E10 80241CA0 03E00008 */  jr        $ra
/* 853E14 80241CA4 27BD0038 */   addiu    $sp, $sp, 0x38
