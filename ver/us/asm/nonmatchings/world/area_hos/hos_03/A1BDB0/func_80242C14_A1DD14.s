.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242C14_A1DD14
/* A1DD14 80242C14 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A1DD18 80242C18 AFB1001C */  sw        $s1, 0x1c($sp)
/* A1DD1C 80242C1C AFBF0020 */  sw        $ra, 0x20($sp)
/* A1DD20 80242C20 AFB00018 */  sw        $s0, 0x18($sp)
/* A1DD24 80242C24 F7B60030 */  sdc1      $f22, 0x30($sp)
/* A1DD28 80242C28 F7B40028 */  sdc1      $f20, 0x28($sp)
/* A1DD2C 80242C2C 10A00060 */  beqz      $a1, .L80242DB0
/* A1DD30 80242C30 0080882D */   daddu    $s1, $a0, $zero
/* A1DD34 80242C34 3C05F4AC */  lui       $a1, 0xf4ac
/* A1DD38 80242C38 0C0B1EAF */  jal       get_variable
/* A1DD3C 80242C3C 34A5D481 */   ori      $a1, $a1, 0xd481
/* A1DD40 80242C40 0220202D */  daddu     $a0, $s1, $zero
/* A1DD44 80242C44 3C05F4AC */  lui       $a1, 0xf4ac
/* A1DD48 80242C48 4482B000 */  mtc1      $v0, $f22
/* A1DD4C 80242C4C 00000000 */  nop
/* A1DD50 80242C50 4680B5A0 */  cvt.s.w   $f22, $f22
/* A1DD54 80242C54 0C0B1EAF */  jal       get_variable
/* A1DD58 80242C58 34A5D482 */   ori      $a1, $a1, 0xd482
/* A1DD5C 80242C5C 0220202D */  daddu     $a0, $s1, $zero
/* A1DD60 80242C60 3C05F4AC */  lui       $a1, 0xf4ac
/* A1DD64 80242C64 4482A000 */  mtc1      $v0, $f20
/* A1DD68 80242C68 00000000 */  nop
/* A1DD6C 80242C6C 4680A520 */  cvt.s.w   $f20, $f20
/* A1DD70 80242C70 0C0B1EAF */  jal       get_variable
/* A1DD74 80242C74 34A5D483 */   ori      $a1, $a1, 0xd483
/* A1DD78 80242C78 44821000 */  mtc1      $v0, $f2
/* A1DD7C 80242C7C 00000000 */  nop
/* A1DD80 80242C80 468010A0 */  cvt.s.w   $f2, $f2
/* A1DD84 80242C84 4405B000 */  mfc1      $a1, $f22
/* A1DD88 80242C88 4406A000 */  mfc1      $a2, $f20
/* A1DD8C 80242C8C 44071000 */  mfc1      $a3, $f2
/* A1DD90 80242C90 0C01C574 */  jal       playFX_4E
/* A1DD94 80242C94 0000202D */   daddu    $a0, $zero, $zero
/* A1DD98 80242C98 0220202D */  daddu     $a0, $s1, $zero
/* A1DD9C 80242C9C 3C05F4AC */  lui       $a1, 0xf4ac
/* A1DDA0 80242CA0 34A5D481 */  ori       $a1, $a1, 0xd481
/* A1DDA4 80242CA4 3C108025 */  lui       $s0, %hi(D_8024BDF0)
/* A1DDA8 80242CA8 2610BDF0 */  addiu     $s0, $s0, %lo(D_8024BDF0)
/* A1DDAC 80242CAC 0C0B1EAF */  jal       get_variable
/* A1DDB0 80242CB0 AE020000 */   sw       $v0, ($s0)
/* A1DDB4 80242CB4 0220202D */  daddu     $a0, $s1, $zero
/* A1DDB8 80242CB8 3C05F4AC */  lui       $a1, 0xf4ac
/* A1DDBC 80242CBC 4482B000 */  mtc1      $v0, $f22
/* A1DDC0 80242CC0 00000000 */  nop
/* A1DDC4 80242CC4 4680B5A0 */  cvt.s.w   $f22, $f22
/* A1DDC8 80242CC8 0C0B1EAF */  jal       get_variable
/* A1DDCC 80242CCC 34A5D482 */   ori      $a1, $a1, 0xd482
/* A1DDD0 80242CD0 0220202D */  daddu     $a0, $s1, $zero
/* A1DDD4 80242CD4 3C05F4AC */  lui       $a1, 0xf4ac
/* A1DDD8 80242CD8 4482A000 */  mtc1      $v0, $f20
/* A1DDDC 80242CDC 00000000 */  nop
/* A1DDE0 80242CE0 4680A520 */  cvt.s.w   $f20, $f20
/* A1DDE4 80242CE4 0C0B1EAF */  jal       get_variable
/* A1DDE8 80242CE8 34A5D483 */   ori      $a1, $a1, 0xd483
/* A1DDEC 80242CEC 44821000 */  mtc1      $v0, $f2
/* A1DDF0 80242CF0 00000000 */  nop
/* A1DDF4 80242CF4 468010A0 */  cvt.s.w   $f2, $f2
/* A1DDF8 80242CF8 4405B000 */  mfc1      $a1, $f22
/* A1DDFC 80242CFC 4406A000 */  mfc1      $a2, $f20
/* A1DE00 80242D00 44071000 */  mfc1      $a3, $f2
/* A1DE04 80242D04 0C01C604 */  jal       playFX_54
/* A1DE08 80242D08 0000202D */   daddu    $a0, $zero, $zero
/* A1DE0C 80242D0C 0220202D */  daddu     $a0, $s1, $zero
/* A1DE10 80242D10 3C05F4AC */  lui       $a1, 0xf4ac
/* A1DE14 80242D14 3C018025 */  lui       $at, %hi(D_8024BDF4)
/* A1DE18 80242D18 AC22BDF4 */  sw        $v0, %lo(D_8024BDF4)($at)
/* A1DE1C 80242D1C 0C0B1EAF */  jal       get_variable
/* A1DE20 80242D20 34A5D481 */   ori      $a1, $a1, 0xd481
/* A1DE24 80242D24 0220202D */  daddu     $a0, $s1, $zero
/* A1DE28 80242D28 3C05F4AC */  lui       $a1, 0xf4ac
/* A1DE2C 80242D2C 4482B000 */  mtc1      $v0, $f22
/* A1DE30 80242D30 00000000 */  nop
/* A1DE34 80242D34 4680B5A0 */  cvt.s.w   $f22, $f22
/* A1DE38 80242D38 0C0B1EAF */  jal       get_variable
/* A1DE3C 80242D3C 34A5D482 */   ori      $a1, $a1, 0xd482
/* A1DE40 80242D40 0220202D */  daddu     $a0, $s1, $zero
/* A1DE44 80242D44 3C05F4AC */  lui       $a1, 0xf4ac
/* A1DE48 80242D48 4482A000 */  mtc1      $v0, $f20
/* A1DE4C 80242D4C 00000000 */  nop
/* A1DE50 80242D50 4680A520 */  cvt.s.w   $f20, $f20
/* A1DE54 80242D54 0C0B1EAF */  jal       get_variable
/* A1DE58 80242D58 34A5D483 */   ori      $a1, $a1, 0xd483
/* A1DE5C 80242D5C 44821000 */  mtc1      $v0, $f2
/* A1DE60 80242D60 00000000 */  nop
/* A1DE64 80242D64 468010A0 */  cvt.s.w   $f2, $f2
/* A1DE68 80242D68 4405B000 */  mfc1      $a1, $f22
/* A1DE6C 80242D6C 4406A000 */  mfc1      $a2, $f20
/* A1DE70 80242D70 3C013F80 */  lui       $at, 0x3f80
/* A1DE74 80242D74 44810000 */  mtc1      $at, $f0
/* A1DE78 80242D78 44071000 */  mfc1      $a3, $f2
/* A1DE7C 80242D7C 0000202D */  daddu     $a0, $zero, $zero
/* A1DE80 80242D80 AFA00014 */  sw        $zero, 0x14($sp)
/* A1DE84 80242D84 0C01CA24 */  jal       playFX_80
/* A1DE88 80242D88 E7A00010 */   swc1     $f0, 0x10($sp)
/* A1DE8C 80242D8C 8E030000 */  lw        $v1, ($s0)
/* A1DE90 80242D90 8C64000C */  lw        $a0, 0xc($v1)
/* A1DE94 80242D94 3C018025 */  lui       $at, %hi(D_8024BDF8)
/* A1DE98 80242D98 AC22BDF8 */  sw        $v0, %lo(D_8024BDF8)($at)
/* A1DE9C 80242D9C AC800018 */  sw        $zero, 0x18($a0)
/* A1DEA0 80242DA0 AC800020 */  sw        $zero, 0x20($a0)
/* A1DEA4 80242DA4 AC800024 */  sw        $zero, 0x24($a0)
/* A1DEA8 80242DA8 AC800028 */  sw        $zero, 0x28($a0)
/* A1DEAC 80242DAC AC80001C */  sw        $zero, 0x1c($a0)
.L80242DB0:
/* A1DEB0 80242DB0 3C028025 */  lui       $v0, %hi(D_8024BDF0)
/* A1DEB4 80242DB4 8C42BDF0 */  lw        $v0, %lo(D_8024BDF0)($v0)
/* A1DEB8 80242DB8 8C44000C */  lw        $a0, 0xc($v0)
/* A1DEBC 80242DBC 8C820020 */  lw        $v0, 0x20($a0)
/* A1DEC0 80242DC0 8C830028 */  lw        $v1, 0x28($a0)
/* A1DEC4 80242DC4 2442000A */  addiu     $v0, $v0, 0xa
/* A1DEC8 80242DC8 AC820020 */  sw        $v0, 0x20($a0)
/* A1DECC 80242DCC 8C820024 */  lw        $v0, 0x24($a0)
/* A1DED0 80242DD0 2463000A */  addiu     $v1, $v1, 0xa
/* A1DED4 80242DD4 AC830028 */  sw        $v1, 0x28($a0)
/* A1DED8 80242DD8 8C830018 */  lw        $v1, 0x18($a0)
/* A1DEDC 80242DDC 2442000A */  addiu     $v0, $v0, 0xa
/* A1DEE0 80242DE0 AC820024 */  sw        $v0, 0x24($a0)
/* A1DEE4 80242DE4 8C82001C */  lw        $v0, 0x1c($a0)
/* A1DEE8 80242DE8 2463000A */  addiu     $v1, $v1, 0xa
/* A1DEEC 80242DEC AC830018 */  sw        $v1, 0x18($a0)
/* A1DEF0 80242DF0 286300FF */  slti      $v1, $v1, 0xff
/* A1DEF4 80242DF4 2442000A */  addiu     $v0, $v0, 0xa
/* A1DEF8 80242DF8 AC82001C */  sw        $v0, 0x1c($a0)
/* A1DEFC 80242DFC 14600004 */  bnez      $v1, .L80242E10
/* A1DF00 80242E00 0000102D */   daddu    $v0, $zero, $zero
/* A1DF04 80242E04 240200FF */  addiu     $v0, $zero, 0xff
/* A1DF08 80242E08 AC820018 */  sw        $v0, 0x18($a0)
/* A1DF0C 80242E0C 24020002 */  addiu     $v0, $zero, 2
.L80242E10:
/* A1DF10 80242E10 8FBF0020 */  lw        $ra, 0x20($sp)
/* A1DF14 80242E14 8FB1001C */  lw        $s1, 0x1c($sp)
/* A1DF18 80242E18 8FB00018 */  lw        $s0, 0x18($sp)
/* A1DF1C 80242E1C D7B60030 */  ldc1      $f22, 0x30($sp)
/* A1DF20 80242E20 D7B40028 */  ldc1      $f20, 0x28($sp)
/* A1DF24 80242E24 03E00008 */  jr        $ra
/* A1DF28 80242E28 27BD0038 */   addiu    $sp, $sp, 0x38
