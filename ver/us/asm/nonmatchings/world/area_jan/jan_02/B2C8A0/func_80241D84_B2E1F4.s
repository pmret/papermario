.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D84_B2E1F4
/* B2E1F4 80241D84 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* B2E1F8 80241D88 AFB1001C */  sw        $s1, 0x1c($sp)
/* B2E1FC 80241D8C AFBF0020 */  sw        $ra, 0x20($sp)
/* B2E200 80241D90 AFB00018 */  sw        $s0, 0x18($sp)
/* B2E204 80241D94 F7B60030 */  sdc1      $f22, 0x30($sp)
/* B2E208 80241D98 F7B40028 */  sdc1      $f20, 0x28($sp)
/* B2E20C 80241D9C 10A00060 */  beqz      $a1, .L80241F20
/* B2E210 80241DA0 0080882D */   daddu    $s1, $a0, $zero
/* B2E214 80241DA4 3C05F4AC */  lui       $a1, 0xf4ac
/* B2E218 80241DA8 0C0B1EAF */  jal       get_variable
/* B2E21C 80241DAC 34A5D481 */   ori      $a1, $a1, 0xd481
/* B2E220 80241DB0 0220202D */  daddu     $a0, $s1, $zero
/* B2E224 80241DB4 3C05F4AC */  lui       $a1, 0xf4ac
/* B2E228 80241DB8 4482B000 */  mtc1      $v0, $f22
/* B2E22C 80241DBC 00000000 */  nop
/* B2E230 80241DC0 4680B5A0 */  cvt.s.w   $f22, $f22
/* B2E234 80241DC4 0C0B1EAF */  jal       get_variable
/* B2E238 80241DC8 34A5D482 */   ori      $a1, $a1, 0xd482
/* B2E23C 80241DCC 0220202D */  daddu     $a0, $s1, $zero
/* B2E240 80241DD0 3C05F4AC */  lui       $a1, 0xf4ac
/* B2E244 80241DD4 4482A000 */  mtc1      $v0, $f20
/* B2E248 80241DD8 00000000 */  nop
/* B2E24C 80241DDC 4680A520 */  cvt.s.w   $f20, $f20
/* B2E250 80241DE0 0C0B1EAF */  jal       get_variable
/* B2E254 80241DE4 34A5D483 */   ori      $a1, $a1, 0xd483
/* B2E258 80241DE8 44821000 */  mtc1      $v0, $f2
/* B2E25C 80241DEC 00000000 */  nop
/* B2E260 80241DF0 468010A0 */  cvt.s.w   $f2, $f2
/* B2E264 80241DF4 4405B000 */  mfc1      $a1, $f22
/* B2E268 80241DF8 4406A000 */  mfc1      $a2, $f20
/* B2E26C 80241DFC 44071000 */  mfc1      $a3, $f2
/* B2E270 80241E00 0C01C574 */  jal       playFX_4E
/* B2E274 80241E04 0000202D */   daddu    $a0, $zero, $zero
/* B2E278 80241E08 0220202D */  daddu     $a0, $s1, $zero
/* B2E27C 80241E0C 3C05F4AC */  lui       $a1, 0xf4ac
/* B2E280 80241E10 34A5D481 */  ori       $a1, $a1, 0xd481
/* B2E284 80241E14 3C108025 */  lui       $s0, %hi(D_80248940)
/* B2E288 80241E18 26108940 */  addiu     $s0, $s0, %lo(D_80248940)
/* B2E28C 80241E1C 0C0B1EAF */  jal       get_variable
/* B2E290 80241E20 AE020000 */   sw       $v0, ($s0)
/* B2E294 80241E24 0220202D */  daddu     $a0, $s1, $zero
/* B2E298 80241E28 3C05F4AC */  lui       $a1, 0xf4ac
/* B2E29C 80241E2C 4482B000 */  mtc1      $v0, $f22
/* B2E2A0 80241E30 00000000 */  nop
/* B2E2A4 80241E34 4680B5A0 */  cvt.s.w   $f22, $f22
/* B2E2A8 80241E38 0C0B1EAF */  jal       get_variable
/* B2E2AC 80241E3C 34A5D482 */   ori      $a1, $a1, 0xd482
/* B2E2B0 80241E40 0220202D */  daddu     $a0, $s1, $zero
/* B2E2B4 80241E44 3C05F4AC */  lui       $a1, 0xf4ac
/* B2E2B8 80241E48 4482A000 */  mtc1      $v0, $f20
/* B2E2BC 80241E4C 00000000 */  nop
/* B2E2C0 80241E50 4680A520 */  cvt.s.w   $f20, $f20
/* B2E2C4 80241E54 0C0B1EAF */  jal       get_variable
/* B2E2C8 80241E58 34A5D483 */   ori      $a1, $a1, 0xd483
/* B2E2CC 80241E5C 44821000 */  mtc1      $v0, $f2
/* B2E2D0 80241E60 00000000 */  nop
/* B2E2D4 80241E64 468010A0 */  cvt.s.w   $f2, $f2
/* B2E2D8 80241E68 4405B000 */  mfc1      $a1, $f22
/* B2E2DC 80241E6C 4406A000 */  mfc1      $a2, $f20
/* B2E2E0 80241E70 44071000 */  mfc1      $a3, $f2
/* B2E2E4 80241E74 0C01C604 */  jal       playFX_54
/* B2E2E8 80241E78 0000202D */   daddu    $a0, $zero, $zero
/* B2E2EC 80241E7C 0220202D */  daddu     $a0, $s1, $zero
/* B2E2F0 80241E80 3C05F4AC */  lui       $a1, 0xf4ac
/* B2E2F4 80241E84 3C018025 */  lui       $at, %hi(D_80248944)
/* B2E2F8 80241E88 AC228944 */  sw        $v0, %lo(D_80248944)($at)
/* B2E2FC 80241E8C 0C0B1EAF */  jal       get_variable
/* B2E300 80241E90 34A5D481 */   ori      $a1, $a1, 0xd481
/* B2E304 80241E94 0220202D */  daddu     $a0, $s1, $zero
/* B2E308 80241E98 3C05F4AC */  lui       $a1, 0xf4ac
/* B2E30C 80241E9C 4482B000 */  mtc1      $v0, $f22
/* B2E310 80241EA0 00000000 */  nop
/* B2E314 80241EA4 4680B5A0 */  cvt.s.w   $f22, $f22
/* B2E318 80241EA8 0C0B1EAF */  jal       get_variable
/* B2E31C 80241EAC 34A5D482 */   ori      $a1, $a1, 0xd482
/* B2E320 80241EB0 0220202D */  daddu     $a0, $s1, $zero
/* B2E324 80241EB4 3C05F4AC */  lui       $a1, 0xf4ac
/* B2E328 80241EB8 4482A000 */  mtc1      $v0, $f20
/* B2E32C 80241EBC 00000000 */  nop
/* B2E330 80241EC0 4680A520 */  cvt.s.w   $f20, $f20
/* B2E334 80241EC4 0C0B1EAF */  jal       get_variable
/* B2E338 80241EC8 34A5D483 */   ori      $a1, $a1, 0xd483
/* B2E33C 80241ECC 44821000 */  mtc1      $v0, $f2
/* B2E340 80241ED0 00000000 */  nop
/* B2E344 80241ED4 468010A0 */  cvt.s.w   $f2, $f2
/* B2E348 80241ED8 4405B000 */  mfc1      $a1, $f22
/* B2E34C 80241EDC 4406A000 */  mfc1      $a2, $f20
/* B2E350 80241EE0 3C013F80 */  lui       $at, 0x3f80
/* B2E354 80241EE4 44810000 */  mtc1      $at, $f0
/* B2E358 80241EE8 44071000 */  mfc1      $a3, $f2
/* B2E35C 80241EEC 0000202D */  daddu     $a0, $zero, $zero
/* B2E360 80241EF0 AFA00014 */  sw        $zero, 0x14($sp)
/* B2E364 80241EF4 0C01CA24 */  jal       playFX_80
/* B2E368 80241EF8 E7A00010 */   swc1     $f0, 0x10($sp)
/* B2E36C 80241EFC 8E030000 */  lw        $v1, ($s0)
/* B2E370 80241F00 8C64000C */  lw        $a0, 0xc($v1)
/* B2E374 80241F04 3C018025 */  lui       $at, %hi(D_80248948)
/* B2E378 80241F08 AC228948 */  sw        $v0, %lo(D_80248948)($at)
/* B2E37C 80241F0C AC800018 */  sw        $zero, 0x18($a0)
/* B2E380 80241F10 AC800020 */  sw        $zero, 0x20($a0)
/* B2E384 80241F14 AC800024 */  sw        $zero, 0x24($a0)
/* B2E388 80241F18 AC800028 */  sw        $zero, 0x28($a0)
/* B2E38C 80241F1C AC80001C */  sw        $zero, 0x1c($a0)
.L80241F20:
/* B2E390 80241F20 3C028025 */  lui       $v0, %hi(D_80248940)
/* B2E394 80241F24 8C428940 */  lw        $v0, %lo(D_80248940)($v0)
/* B2E398 80241F28 8C44000C */  lw        $a0, 0xc($v0)
/* B2E39C 80241F2C 8C820020 */  lw        $v0, 0x20($a0)
/* B2E3A0 80241F30 8C830028 */  lw        $v1, 0x28($a0)
/* B2E3A4 80241F34 2442000A */  addiu     $v0, $v0, 0xa
/* B2E3A8 80241F38 AC820020 */  sw        $v0, 0x20($a0)
/* B2E3AC 80241F3C 8C820024 */  lw        $v0, 0x24($a0)
/* B2E3B0 80241F40 2463000A */  addiu     $v1, $v1, 0xa
/* B2E3B4 80241F44 AC830028 */  sw        $v1, 0x28($a0)
/* B2E3B8 80241F48 8C830018 */  lw        $v1, 0x18($a0)
/* B2E3BC 80241F4C 2442000A */  addiu     $v0, $v0, 0xa
/* B2E3C0 80241F50 AC820024 */  sw        $v0, 0x24($a0)
/* B2E3C4 80241F54 8C82001C */  lw        $v0, 0x1c($a0)
/* B2E3C8 80241F58 2463000A */  addiu     $v1, $v1, 0xa
/* B2E3CC 80241F5C AC830018 */  sw        $v1, 0x18($a0)
/* B2E3D0 80241F60 286300FF */  slti      $v1, $v1, 0xff
/* B2E3D4 80241F64 2442000A */  addiu     $v0, $v0, 0xa
/* B2E3D8 80241F68 AC82001C */  sw        $v0, 0x1c($a0)
/* B2E3DC 80241F6C 14600004 */  bnez      $v1, .L80241F80
/* B2E3E0 80241F70 0000102D */   daddu    $v0, $zero, $zero
/* B2E3E4 80241F74 240200FF */  addiu     $v0, $zero, 0xff
/* B2E3E8 80241F78 AC820018 */  sw        $v0, 0x18($a0)
/* B2E3EC 80241F7C 24020002 */  addiu     $v0, $zero, 2
.L80241F80:
/* B2E3F0 80241F80 8FBF0020 */  lw        $ra, 0x20($sp)
/* B2E3F4 80241F84 8FB1001C */  lw        $s1, 0x1c($sp)
/* B2E3F8 80241F88 8FB00018 */  lw        $s0, 0x18($sp)
/* B2E3FC 80241F8C D7B60030 */  ldc1      $f22, 0x30($sp)
/* B2E400 80241F90 D7B40028 */  ldc1      $f20, 0x28($sp)
/* B2E404 80241F94 03E00008 */  jr        $ra
/* B2E408 80241F98 27BD0038 */   addiu    $sp, $sp, 0x38
