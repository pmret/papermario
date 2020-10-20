.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B00_8B0B70
/* 8B0B70 80240B00 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 8B0B74 80240B04 AFB1001C */  sw        $s1, 0x1c($sp)
/* 8B0B78 80240B08 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8B0B7C 80240B0C AFB00018 */  sw        $s0, 0x18($sp)
/* 8B0B80 80240B10 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 8B0B84 80240B14 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 8B0B88 80240B18 10A00060 */  beqz      $a1, .L80240C9C
/* 8B0B8C 80240B1C 0080882D */   daddu    $s1, $a0, $zero
/* 8B0B90 80240B20 3C05F4AC */  lui       $a1, 0xf4ac
/* 8B0B94 80240B24 0C0B1EAF */  jal       get_variable
/* 8B0B98 80240B28 34A5D481 */   ori      $a1, $a1, 0xd481
/* 8B0B9C 80240B2C 0220202D */  daddu     $a0, $s1, $zero
/* 8B0BA0 80240B30 3C05F4AC */  lui       $a1, 0xf4ac
/* 8B0BA4 80240B34 4482B000 */  mtc1      $v0, $f22
/* 8B0BA8 80240B38 00000000 */  nop       
/* 8B0BAC 80240B3C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 8B0BB0 80240B40 0C0B1EAF */  jal       get_variable
/* 8B0BB4 80240B44 34A5D482 */   ori      $a1, $a1, 0xd482
/* 8B0BB8 80240B48 0220202D */  daddu     $a0, $s1, $zero
/* 8B0BBC 80240B4C 3C05F4AC */  lui       $a1, 0xf4ac
/* 8B0BC0 80240B50 4482A000 */  mtc1      $v0, $f20
/* 8B0BC4 80240B54 00000000 */  nop       
/* 8B0BC8 80240B58 4680A520 */  cvt.s.w   $f20, $f20
/* 8B0BCC 80240B5C 0C0B1EAF */  jal       get_variable
/* 8B0BD0 80240B60 34A5D483 */   ori      $a1, $a1, 0xd483
/* 8B0BD4 80240B64 44821000 */  mtc1      $v0, $f2
/* 8B0BD8 80240B68 00000000 */  nop       
/* 8B0BDC 80240B6C 468010A0 */  cvt.s.w   $f2, $f2
/* 8B0BE0 80240B70 4405B000 */  mfc1      $a1, $f22
/* 8B0BE4 80240B74 4406A000 */  mfc1      $a2, $f20
/* 8B0BE8 80240B78 44071000 */  mfc1      $a3, $f2
/* 8B0BEC 80240B7C 0C01C574 */  jal       func_800715D0
/* 8B0BF0 80240B80 0000202D */   daddu    $a0, $zero, $zero
/* 8B0BF4 80240B84 0220202D */  daddu     $a0, $s1, $zero
/* 8B0BF8 80240B88 3C05F4AC */  lui       $a1, 0xf4ac
/* 8B0BFC 80240B8C 34A5D481 */  ori       $a1, $a1, 0xd481
/* 8B0C00 80240B90 3C108025 */  lui       $s0, 0x8025
/* 8B0C04 80240B94 26107F48 */  addiu     $s0, $s0, 0x7f48
/* 8B0C08 80240B98 0C0B1EAF */  jal       get_variable
/* 8B0C0C 80240B9C AE020000 */   sw       $v0, ($s0)
/* 8B0C10 80240BA0 0220202D */  daddu     $a0, $s1, $zero
/* 8B0C14 80240BA4 3C05F4AC */  lui       $a1, 0xf4ac
/* 8B0C18 80240BA8 4482B000 */  mtc1      $v0, $f22
/* 8B0C1C 80240BAC 00000000 */  nop       
/* 8B0C20 80240BB0 4680B5A0 */  cvt.s.w   $f22, $f22
/* 8B0C24 80240BB4 0C0B1EAF */  jal       get_variable
/* 8B0C28 80240BB8 34A5D482 */   ori      $a1, $a1, 0xd482
/* 8B0C2C 80240BBC 0220202D */  daddu     $a0, $s1, $zero
/* 8B0C30 80240BC0 3C05F4AC */  lui       $a1, 0xf4ac
/* 8B0C34 80240BC4 4482A000 */  mtc1      $v0, $f20
/* 8B0C38 80240BC8 00000000 */  nop       
/* 8B0C3C 80240BCC 4680A520 */  cvt.s.w   $f20, $f20
/* 8B0C40 80240BD0 0C0B1EAF */  jal       get_variable
/* 8B0C44 80240BD4 34A5D483 */   ori      $a1, $a1, 0xd483
/* 8B0C48 80240BD8 44821000 */  mtc1      $v0, $f2
/* 8B0C4C 80240BDC 00000000 */  nop       
/* 8B0C50 80240BE0 468010A0 */  cvt.s.w   $f2, $f2
/* 8B0C54 80240BE4 4405B000 */  mfc1      $a1, $f22
/* 8B0C58 80240BE8 4406A000 */  mfc1      $a2, $f20
/* 8B0C5C 80240BEC 44071000 */  mfc1      $a3, $f2
/* 8B0C60 80240BF0 0C01C604 */  jal       func_80071810
/* 8B0C64 80240BF4 0000202D */   daddu    $a0, $zero, $zero
/* 8B0C68 80240BF8 0220202D */  daddu     $a0, $s1, $zero
/* 8B0C6C 80240BFC 3C05F4AC */  lui       $a1, 0xf4ac
/* 8B0C70 80240C00 3C018025 */  lui       $at, 0x8025
/* 8B0C74 80240C04 AC227F4C */  sw        $v0, 0x7f4c($at)
/* 8B0C78 80240C08 0C0B1EAF */  jal       get_variable
/* 8B0C7C 80240C0C 34A5D481 */   ori      $a1, $a1, 0xd481
/* 8B0C80 80240C10 0220202D */  daddu     $a0, $s1, $zero
/* 8B0C84 80240C14 3C05F4AC */  lui       $a1, 0xf4ac
/* 8B0C88 80240C18 4482B000 */  mtc1      $v0, $f22
/* 8B0C8C 80240C1C 00000000 */  nop       
/* 8B0C90 80240C20 4680B5A0 */  cvt.s.w   $f22, $f22
/* 8B0C94 80240C24 0C0B1EAF */  jal       get_variable
/* 8B0C98 80240C28 34A5D482 */   ori      $a1, $a1, 0xd482
/* 8B0C9C 80240C2C 0220202D */  daddu     $a0, $s1, $zero
/* 8B0CA0 80240C30 3C05F4AC */  lui       $a1, 0xf4ac
/* 8B0CA4 80240C34 4482A000 */  mtc1      $v0, $f20
/* 8B0CA8 80240C38 00000000 */  nop       
/* 8B0CAC 80240C3C 4680A520 */  cvt.s.w   $f20, $f20
/* 8B0CB0 80240C40 0C0B1EAF */  jal       get_variable
/* 8B0CB4 80240C44 34A5D483 */   ori      $a1, $a1, 0xd483
/* 8B0CB8 80240C48 44821000 */  mtc1      $v0, $f2
/* 8B0CBC 80240C4C 00000000 */  nop       
/* 8B0CC0 80240C50 468010A0 */  cvt.s.w   $f2, $f2
/* 8B0CC4 80240C54 4405B000 */  mfc1      $a1, $f22
/* 8B0CC8 80240C58 4406A000 */  mfc1      $a2, $f20
/* 8B0CCC 80240C5C 3C013F80 */  lui       $at, 0x3f80
/* 8B0CD0 80240C60 44810000 */  mtc1      $at, $f0
/* 8B0CD4 80240C64 44071000 */  mfc1      $a3, $f2
/* 8B0CD8 80240C68 0000202D */  daddu     $a0, $zero, $zero
/* 8B0CDC 80240C6C AFA00014 */  sw        $zero, 0x14($sp)
/* 8B0CE0 80240C70 0C01CA24 */  jal       func_80072890
/* 8B0CE4 80240C74 E7A00010 */   swc1     $f0, 0x10($sp)
/* 8B0CE8 80240C78 8E030000 */  lw        $v1, ($s0)
/* 8B0CEC 80240C7C 8C64000C */  lw        $a0, 0xc($v1)
/* 8B0CF0 80240C80 3C018025 */  lui       $at, 0x8025
/* 8B0CF4 80240C84 AC227F50 */  sw        $v0, 0x7f50($at)
/* 8B0CF8 80240C88 AC800018 */  sw        $zero, 0x18($a0)
/* 8B0CFC 80240C8C AC800020 */  sw        $zero, 0x20($a0)
/* 8B0D00 80240C90 AC800024 */  sw        $zero, 0x24($a0)
/* 8B0D04 80240C94 AC800028 */  sw        $zero, 0x28($a0)
/* 8B0D08 80240C98 AC80001C */  sw        $zero, 0x1c($a0)
.L80240C9C:
/* 8B0D0C 80240C9C 3C028025 */  lui       $v0, 0x8025
/* 8B0D10 80240CA0 8C427F48 */  lw        $v0, 0x7f48($v0)
/* 8B0D14 80240CA4 8C44000C */  lw        $a0, 0xc($v0)
/* 8B0D18 80240CA8 8C820020 */  lw        $v0, 0x20($a0)
/* 8B0D1C 80240CAC 8C830028 */  lw        $v1, 0x28($a0)
/* 8B0D20 80240CB0 2442000A */  addiu     $v0, $v0, 0xa
/* 8B0D24 80240CB4 AC820020 */  sw        $v0, 0x20($a0)
/* 8B0D28 80240CB8 8C820024 */  lw        $v0, 0x24($a0)
/* 8B0D2C 80240CBC 2463000A */  addiu     $v1, $v1, 0xa
/* 8B0D30 80240CC0 AC830028 */  sw        $v1, 0x28($a0)
/* 8B0D34 80240CC4 8C830018 */  lw        $v1, 0x18($a0)
/* 8B0D38 80240CC8 2442000A */  addiu     $v0, $v0, 0xa
/* 8B0D3C 80240CCC AC820024 */  sw        $v0, 0x24($a0)
/* 8B0D40 80240CD0 8C82001C */  lw        $v0, 0x1c($a0)
/* 8B0D44 80240CD4 2463000A */  addiu     $v1, $v1, 0xa
/* 8B0D48 80240CD8 AC830018 */  sw        $v1, 0x18($a0)
/* 8B0D4C 80240CDC 286300FF */  slti      $v1, $v1, 0xff
/* 8B0D50 80240CE0 2442000A */  addiu     $v0, $v0, 0xa
/* 8B0D54 80240CE4 AC82001C */  sw        $v0, 0x1c($a0)
/* 8B0D58 80240CE8 14600004 */  bnez      $v1, .L80240CFC
/* 8B0D5C 80240CEC 0000102D */   daddu    $v0, $zero, $zero
/* 8B0D60 80240CF0 240200FF */  addiu     $v0, $zero, 0xff
/* 8B0D64 80240CF4 AC820018 */  sw        $v0, 0x18($a0)
/* 8B0D68 80240CF8 24020002 */  addiu     $v0, $zero, 2
.L80240CFC:
/* 8B0D6C 80240CFC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8B0D70 80240D00 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8B0D74 80240D04 8FB00018 */  lw        $s0, 0x18($sp)
/* 8B0D78 80240D08 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 8B0D7C 80240D0C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 8B0D80 80240D10 03E00008 */  jr        $ra
/* 8B0D84 80240D14 27BD0038 */   addiu    $sp, $sp, 0x38
