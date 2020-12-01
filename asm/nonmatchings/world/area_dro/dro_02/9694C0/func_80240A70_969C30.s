.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A70_969C30
/* 969C30 80240A70 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 969C34 80240A74 AFB1001C */  sw        $s1, 0x1c($sp)
/* 969C38 80240A78 AFBF0020 */  sw        $ra, 0x20($sp)
/* 969C3C 80240A7C AFB00018 */  sw        $s0, 0x18($sp)
/* 969C40 80240A80 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 969C44 80240A84 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 969C48 80240A88 10A00060 */  beqz      $a1, .L80240C0C
/* 969C4C 80240A8C 0080882D */   daddu    $s1, $a0, $zero
/* 969C50 80240A90 3C05F4AC */  lui       $a1, 0xf4ac
/* 969C54 80240A94 0C0B1EAF */  jal       get_variable
/* 969C58 80240A98 34A5D481 */   ori      $a1, $a1, 0xd481
/* 969C5C 80240A9C 0220202D */  daddu     $a0, $s1, $zero
/* 969C60 80240AA0 3C05F4AC */  lui       $a1, 0xf4ac
/* 969C64 80240AA4 4482B000 */  mtc1      $v0, $f22
/* 969C68 80240AA8 00000000 */  nop       
/* 969C6C 80240AAC 4680B5A0 */  cvt.s.w   $f22, $f22
/* 969C70 80240AB0 0C0B1EAF */  jal       get_variable
/* 969C74 80240AB4 34A5D482 */   ori      $a1, $a1, 0xd482
/* 969C78 80240AB8 0220202D */  daddu     $a0, $s1, $zero
/* 969C7C 80240ABC 3C05F4AC */  lui       $a1, 0xf4ac
/* 969C80 80240AC0 4482A000 */  mtc1      $v0, $f20
/* 969C84 80240AC4 00000000 */  nop       
/* 969C88 80240AC8 4680A520 */  cvt.s.w   $f20, $f20
/* 969C8C 80240ACC 0C0B1EAF */  jal       get_variable
/* 969C90 80240AD0 34A5D483 */   ori      $a1, $a1, 0xd483
/* 969C94 80240AD4 44821000 */  mtc1      $v0, $f2
/* 969C98 80240AD8 00000000 */  nop       
/* 969C9C 80240ADC 468010A0 */  cvt.s.w   $f2, $f2
/* 969CA0 80240AE0 4405B000 */  mfc1      $a1, $f22
/* 969CA4 80240AE4 4406A000 */  mfc1      $a2, $f20
/* 969CA8 80240AE8 44071000 */  mfc1      $a3, $f2
/* 969CAC 80240AEC 0C01C574 */  jal       func_800715D0
/* 969CB0 80240AF0 0000202D */   daddu    $a0, $zero, $zero
/* 969CB4 80240AF4 0220202D */  daddu     $a0, $s1, $zero
/* 969CB8 80240AF8 3C05F4AC */  lui       $a1, 0xf4ac
/* 969CBC 80240AFC 34A5D481 */  ori       $a1, $a1, 0xd481
/* 969CC0 80240B00 3C108025 */  lui       $s0, %hi(D_8024EFC0)
/* 969CC4 80240B04 2610EFC0 */  addiu     $s0, $s0, %lo(D_8024EFC0)
/* 969CC8 80240B08 0C0B1EAF */  jal       get_variable
/* 969CCC 80240B0C AE020000 */   sw       $v0, ($s0)
/* 969CD0 80240B10 0220202D */  daddu     $a0, $s1, $zero
/* 969CD4 80240B14 3C05F4AC */  lui       $a1, 0xf4ac
/* 969CD8 80240B18 4482B000 */  mtc1      $v0, $f22
/* 969CDC 80240B1C 00000000 */  nop       
/* 969CE0 80240B20 4680B5A0 */  cvt.s.w   $f22, $f22
/* 969CE4 80240B24 0C0B1EAF */  jal       get_variable
/* 969CE8 80240B28 34A5D482 */   ori      $a1, $a1, 0xd482
/* 969CEC 80240B2C 0220202D */  daddu     $a0, $s1, $zero
/* 969CF0 80240B30 3C05F4AC */  lui       $a1, 0xf4ac
/* 969CF4 80240B34 4482A000 */  mtc1      $v0, $f20
/* 969CF8 80240B38 00000000 */  nop       
/* 969CFC 80240B3C 4680A520 */  cvt.s.w   $f20, $f20
/* 969D00 80240B40 0C0B1EAF */  jal       get_variable
/* 969D04 80240B44 34A5D483 */   ori      $a1, $a1, 0xd483
/* 969D08 80240B48 44821000 */  mtc1      $v0, $f2
/* 969D0C 80240B4C 00000000 */  nop       
/* 969D10 80240B50 468010A0 */  cvt.s.w   $f2, $f2
/* 969D14 80240B54 4405B000 */  mfc1      $a1, $f22
/* 969D18 80240B58 4406A000 */  mfc1      $a2, $f20
/* 969D1C 80240B5C 44071000 */  mfc1      $a3, $f2
/* 969D20 80240B60 0C01C604 */  jal       func_80071810
/* 969D24 80240B64 0000202D */   daddu    $a0, $zero, $zero
/* 969D28 80240B68 0220202D */  daddu     $a0, $s1, $zero
/* 969D2C 80240B6C 3C05F4AC */  lui       $a1, 0xf4ac
/* 969D30 80240B70 3C018025 */  lui       $at, %hi(D_8024EFC4)
/* 969D34 80240B74 AC22EFC4 */  sw        $v0, %lo(D_8024EFC4)($at)
/* 969D38 80240B78 0C0B1EAF */  jal       get_variable
/* 969D3C 80240B7C 34A5D481 */   ori      $a1, $a1, 0xd481
/* 969D40 80240B80 0220202D */  daddu     $a0, $s1, $zero
/* 969D44 80240B84 3C05F4AC */  lui       $a1, 0xf4ac
/* 969D48 80240B88 4482B000 */  mtc1      $v0, $f22
/* 969D4C 80240B8C 00000000 */  nop       
/* 969D50 80240B90 4680B5A0 */  cvt.s.w   $f22, $f22
/* 969D54 80240B94 0C0B1EAF */  jal       get_variable
/* 969D58 80240B98 34A5D482 */   ori      $a1, $a1, 0xd482
/* 969D5C 80240B9C 0220202D */  daddu     $a0, $s1, $zero
/* 969D60 80240BA0 3C05F4AC */  lui       $a1, 0xf4ac
/* 969D64 80240BA4 4482A000 */  mtc1      $v0, $f20
/* 969D68 80240BA8 00000000 */  nop       
/* 969D6C 80240BAC 4680A520 */  cvt.s.w   $f20, $f20
/* 969D70 80240BB0 0C0B1EAF */  jal       get_variable
/* 969D74 80240BB4 34A5D483 */   ori      $a1, $a1, 0xd483
/* 969D78 80240BB8 44821000 */  mtc1      $v0, $f2
/* 969D7C 80240BBC 00000000 */  nop       
/* 969D80 80240BC0 468010A0 */  cvt.s.w   $f2, $f2
/* 969D84 80240BC4 4405B000 */  mfc1      $a1, $f22
/* 969D88 80240BC8 4406A000 */  mfc1      $a2, $f20
/* 969D8C 80240BCC 3C013F80 */  lui       $at, 0x3f80
/* 969D90 80240BD0 44810000 */  mtc1      $at, $f0
/* 969D94 80240BD4 44071000 */  mfc1      $a3, $f2
/* 969D98 80240BD8 0000202D */  daddu     $a0, $zero, $zero
/* 969D9C 80240BDC AFA00014 */  sw        $zero, 0x14($sp)
/* 969DA0 80240BE0 0C01CA24 */  jal       func_80072890
/* 969DA4 80240BE4 E7A00010 */   swc1     $f0, 0x10($sp)
/* 969DA8 80240BE8 8E030000 */  lw        $v1, ($s0)
/* 969DAC 80240BEC 8C64000C */  lw        $a0, 0xc($v1)
/* 969DB0 80240BF0 3C018025 */  lui       $at, %hi(D_8024EFC8)
/* 969DB4 80240BF4 AC22EFC8 */  sw        $v0, %lo(D_8024EFC8)($at)
/* 969DB8 80240BF8 AC800018 */  sw        $zero, 0x18($a0)
/* 969DBC 80240BFC AC800020 */  sw        $zero, 0x20($a0)
/* 969DC0 80240C00 AC800024 */  sw        $zero, 0x24($a0)
/* 969DC4 80240C04 AC800028 */  sw        $zero, 0x28($a0)
/* 969DC8 80240C08 AC80001C */  sw        $zero, 0x1c($a0)
.L80240C0C:
/* 969DCC 80240C0C 3C028025 */  lui       $v0, %hi(D_8024EFC0)
/* 969DD0 80240C10 8C42EFC0 */  lw        $v0, %lo(D_8024EFC0)($v0)
/* 969DD4 80240C14 8C44000C */  lw        $a0, 0xc($v0)
/* 969DD8 80240C18 8C820020 */  lw        $v0, 0x20($a0)
/* 969DDC 80240C1C 8C830028 */  lw        $v1, 0x28($a0)
/* 969DE0 80240C20 2442000A */  addiu     $v0, $v0, 0xa
/* 969DE4 80240C24 AC820020 */  sw        $v0, 0x20($a0)
/* 969DE8 80240C28 8C820024 */  lw        $v0, 0x24($a0)
/* 969DEC 80240C2C 2463000A */  addiu     $v1, $v1, 0xa
/* 969DF0 80240C30 AC830028 */  sw        $v1, 0x28($a0)
/* 969DF4 80240C34 8C830018 */  lw        $v1, 0x18($a0)
/* 969DF8 80240C38 2442000A */  addiu     $v0, $v0, 0xa
/* 969DFC 80240C3C AC820024 */  sw        $v0, 0x24($a0)
/* 969E00 80240C40 8C82001C */  lw        $v0, 0x1c($a0)
/* 969E04 80240C44 2463000A */  addiu     $v1, $v1, 0xa
/* 969E08 80240C48 AC830018 */  sw        $v1, 0x18($a0)
/* 969E0C 80240C4C 286300FF */  slti      $v1, $v1, 0xff
/* 969E10 80240C50 2442000A */  addiu     $v0, $v0, 0xa
/* 969E14 80240C54 AC82001C */  sw        $v0, 0x1c($a0)
/* 969E18 80240C58 14600004 */  bnez      $v1, .L80240C6C
/* 969E1C 80240C5C 0000102D */   daddu    $v0, $zero, $zero
/* 969E20 80240C60 240200FF */  addiu     $v0, $zero, 0xff
/* 969E24 80240C64 AC820018 */  sw        $v0, 0x18($a0)
/* 969E28 80240C68 24020002 */  addiu     $v0, $zero, 2
.L80240C6C:
/* 969E2C 80240C6C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 969E30 80240C70 8FB1001C */  lw        $s1, 0x1c($sp)
/* 969E34 80240C74 8FB00018 */  lw        $s0, 0x18($sp)
/* 969E38 80240C78 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 969E3C 80240C7C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 969E40 80240C80 03E00008 */  jr        $ra
/* 969E44 80240C84 27BD0038 */   addiu    $sp, $sp, 0x38
