.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BE0
/* 95CDE0 80241BE0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 95CDE4 80241BE4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 95CDE8 80241BE8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 95CDEC 80241BEC AFB00018 */  sw        $s0, 0x18($sp)
/* 95CDF0 80241BF0 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 95CDF4 80241BF4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 95CDF8 80241BF8 10A00060 */  beqz      $a1, .L80241D7C
/* 95CDFC 80241BFC 0080882D */   daddu    $s1, $a0, $zero
/* 95CE00 80241C00 3C05F4AC */  lui       $a1, 0xf4ac
/* 95CE04 80241C04 0C0B1EAF */  jal       get_variable
/* 95CE08 80241C08 34A5D481 */   ori      $a1, $a1, 0xd481
/* 95CE0C 80241C0C 0220202D */  daddu     $a0, $s1, $zero
/* 95CE10 80241C10 3C05F4AC */  lui       $a1, 0xf4ac
/* 95CE14 80241C14 4482B000 */  mtc1      $v0, $f22
/* 95CE18 80241C18 00000000 */  nop       
/* 95CE1C 80241C1C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 95CE20 80241C20 0C0B1EAF */  jal       get_variable
/* 95CE24 80241C24 34A5D482 */   ori      $a1, $a1, 0xd482
/* 95CE28 80241C28 0220202D */  daddu     $a0, $s1, $zero
/* 95CE2C 80241C2C 3C05F4AC */  lui       $a1, 0xf4ac
/* 95CE30 80241C30 4482A000 */  mtc1      $v0, $f20
/* 95CE34 80241C34 00000000 */  nop       
/* 95CE38 80241C38 4680A520 */  cvt.s.w   $f20, $f20
/* 95CE3C 80241C3C 0C0B1EAF */  jal       get_variable
/* 95CE40 80241C40 34A5D483 */   ori      $a1, $a1, 0xd483
/* 95CE44 80241C44 44821000 */  mtc1      $v0, $f2
/* 95CE48 80241C48 00000000 */  nop       
/* 95CE4C 80241C4C 468010A0 */  cvt.s.w   $f2, $f2
/* 95CE50 80241C50 4405B000 */  mfc1      $a1, $f22
/* 95CE54 80241C54 4406A000 */  mfc1      $a2, $f20
/* 95CE58 80241C58 44071000 */  mfc1      $a3, $f2
/* 95CE5C 80241C5C 0C01C574 */  jal       func_800715D0
/* 95CE60 80241C60 0000202D */   daddu    $a0, $zero, $zero
/* 95CE64 80241C64 0220202D */  daddu     $a0, $s1, $zero
/* 95CE68 80241C68 3C05F4AC */  lui       $a1, 0xf4ac
/* 95CE6C 80241C6C 34A5D481 */  ori       $a1, $a1, 0xd481
/* 95CE70 80241C70 3C108025 */  lui       $s0, 0x8025
/* 95CE74 80241C74 2610DFE0 */  addiu     $s0, $s0, -0x2020
/* 95CE78 80241C78 0C0B1EAF */  jal       get_variable
/* 95CE7C 80241C7C AE020000 */   sw       $v0, ($s0)
/* 95CE80 80241C80 0220202D */  daddu     $a0, $s1, $zero
/* 95CE84 80241C84 3C05F4AC */  lui       $a1, 0xf4ac
/* 95CE88 80241C88 4482B000 */  mtc1      $v0, $f22
/* 95CE8C 80241C8C 00000000 */  nop       
/* 95CE90 80241C90 4680B5A0 */  cvt.s.w   $f22, $f22
/* 95CE94 80241C94 0C0B1EAF */  jal       get_variable
/* 95CE98 80241C98 34A5D482 */   ori      $a1, $a1, 0xd482
/* 95CE9C 80241C9C 0220202D */  daddu     $a0, $s1, $zero
/* 95CEA0 80241CA0 3C05F4AC */  lui       $a1, 0xf4ac
/* 95CEA4 80241CA4 4482A000 */  mtc1      $v0, $f20
/* 95CEA8 80241CA8 00000000 */  nop       
/* 95CEAC 80241CAC 4680A520 */  cvt.s.w   $f20, $f20
/* 95CEB0 80241CB0 0C0B1EAF */  jal       get_variable
/* 95CEB4 80241CB4 34A5D483 */   ori      $a1, $a1, 0xd483
/* 95CEB8 80241CB8 44821000 */  mtc1      $v0, $f2
/* 95CEBC 80241CBC 00000000 */  nop       
/* 95CEC0 80241CC0 468010A0 */  cvt.s.w   $f2, $f2
/* 95CEC4 80241CC4 4405B000 */  mfc1      $a1, $f22
/* 95CEC8 80241CC8 4406A000 */  mfc1      $a2, $f20
/* 95CECC 80241CCC 44071000 */  mfc1      $a3, $f2
/* 95CED0 80241CD0 0C01C604 */  jal       func_80071810
/* 95CED4 80241CD4 0000202D */   daddu    $a0, $zero, $zero
/* 95CED8 80241CD8 0220202D */  daddu     $a0, $s1, $zero
/* 95CEDC 80241CDC 3C05F4AC */  lui       $a1, 0xf4ac
/* 95CEE0 80241CE0 3C018025 */  lui       $at, 0x8025
/* 95CEE4 80241CE4 AC22DFE4 */  sw        $v0, -0x201c($at)
/* 95CEE8 80241CE8 0C0B1EAF */  jal       get_variable
/* 95CEEC 80241CEC 34A5D481 */   ori      $a1, $a1, 0xd481
/* 95CEF0 80241CF0 0220202D */  daddu     $a0, $s1, $zero
/* 95CEF4 80241CF4 3C05F4AC */  lui       $a1, 0xf4ac
/* 95CEF8 80241CF8 4482B000 */  mtc1      $v0, $f22
/* 95CEFC 80241CFC 00000000 */  nop       
/* 95CF00 80241D00 4680B5A0 */  cvt.s.w   $f22, $f22
/* 95CF04 80241D04 0C0B1EAF */  jal       get_variable
/* 95CF08 80241D08 34A5D482 */   ori      $a1, $a1, 0xd482
/* 95CF0C 80241D0C 0220202D */  daddu     $a0, $s1, $zero
/* 95CF10 80241D10 3C05F4AC */  lui       $a1, 0xf4ac
/* 95CF14 80241D14 4482A000 */  mtc1      $v0, $f20
/* 95CF18 80241D18 00000000 */  nop       
/* 95CF1C 80241D1C 4680A520 */  cvt.s.w   $f20, $f20
/* 95CF20 80241D20 0C0B1EAF */  jal       get_variable
/* 95CF24 80241D24 34A5D483 */   ori      $a1, $a1, 0xd483
/* 95CF28 80241D28 44821000 */  mtc1      $v0, $f2
/* 95CF2C 80241D2C 00000000 */  nop       
/* 95CF30 80241D30 468010A0 */  cvt.s.w   $f2, $f2
/* 95CF34 80241D34 4405B000 */  mfc1      $a1, $f22
/* 95CF38 80241D38 4406A000 */  mfc1      $a2, $f20
/* 95CF3C 80241D3C 3C013F80 */  lui       $at, 0x3f80
/* 95CF40 80241D40 44810000 */  mtc1      $at, $f0
/* 95CF44 80241D44 44071000 */  mfc1      $a3, $f2
/* 95CF48 80241D48 0000202D */  daddu     $a0, $zero, $zero
/* 95CF4C 80241D4C AFA00014 */  sw        $zero, 0x14($sp)
/* 95CF50 80241D50 0C01CA24 */  jal       func_80072890
/* 95CF54 80241D54 E7A00010 */   swc1     $f0, 0x10($sp)
/* 95CF58 80241D58 8E030000 */  lw        $v1, ($s0)
/* 95CF5C 80241D5C 8C64000C */  lw        $a0, 0xc($v1)
/* 95CF60 80241D60 3C018025 */  lui       $at, 0x8025
/* 95CF64 80241D64 AC22DFE8 */  sw        $v0, -0x2018($at)
/* 95CF68 80241D68 AC800018 */  sw        $zero, 0x18($a0)
/* 95CF6C 80241D6C AC800020 */  sw        $zero, 0x20($a0)
/* 95CF70 80241D70 AC800024 */  sw        $zero, 0x24($a0)
/* 95CF74 80241D74 AC800028 */  sw        $zero, 0x28($a0)
/* 95CF78 80241D78 AC80001C */  sw        $zero, 0x1c($a0)
.L80241D7C:
/* 95CF7C 80241D7C 3C028025 */  lui       $v0, 0x8025
/* 95CF80 80241D80 8C42DFE0 */  lw        $v0, -0x2020($v0)
/* 95CF84 80241D84 8C44000C */  lw        $a0, 0xc($v0)
/* 95CF88 80241D88 8C820020 */  lw        $v0, 0x20($a0)
/* 95CF8C 80241D8C 8C830028 */  lw        $v1, 0x28($a0)
/* 95CF90 80241D90 2442000A */  addiu     $v0, $v0, 0xa
/* 95CF94 80241D94 AC820020 */  sw        $v0, 0x20($a0)
/* 95CF98 80241D98 8C820024 */  lw        $v0, 0x24($a0)
/* 95CF9C 80241D9C 2463000A */  addiu     $v1, $v1, 0xa
/* 95CFA0 80241DA0 AC830028 */  sw        $v1, 0x28($a0)
/* 95CFA4 80241DA4 8C830018 */  lw        $v1, 0x18($a0)
/* 95CFA8 80241DA8 2442000A */  addiu     $v0, $v0, 0xa
/* 95CFAC 80241DAC AC820024 */  sw        $v0, 0x24($a0)
/* 95CFB0 80241DB0 8C82001C */  lw        $v0, 0x1c($a0)
/* 95CFB4 80241DB4 2463000A */  addiu     $v1, $v1, 0xa
/* 95CFB8 80241DB8 AC830018 */  sw        $v1, 0x18($a0)
/* 95CFBC 80241DBC 286300FF */  slti      $v1, $v1, 0xff
/* 95CFC0 80241DC0 2442000A */  addiu     $v0, $v0, 0xa
/* 95CFC4 80241DC4 AC82001C */  sw        $v0, 0x1c($a0)
/* 95CFC8 80241DC8 14600004 */  bnez      $v1, .L80241DDC
/* 95CFCC 80241DCC 0000102D */   daddu    $v0, $zero, $zero
/* 95CFD0 80241DD0 240200FF */  addiu     $v0, $zero, 0xff
/* 95CFD4 80241DD4 AC820018 */  sw        $v0, 0x18($a0)
/* 95CFD8 80241DD8 24020002 */  addiu     $v0, $zero, 2
.L80241DDC:
/* 95CFDC 80241DDC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 95CFE0 80241DE0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 95CFE4 80241DE4 8FB00018 */  lw        $s0, 0x18($sp)
/* 95CFE8 80241DE8 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 95CFEC 80241DEC D7B40028 */  ldc1      $f20, 0x28($sp)
/* 95CFF0 80241DF0 03E00008 */  jr        $ra
/* 95CFF4 80241DF4 27BD0038 */   addiu    $sp, $sp, 0x38
