.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E01124CC
/* 3FA31C E01124CC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3FA320 E01124D0 3C06DB06 */  lui       $a2, 0xdb06
/* 3FA324 E01124D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 3FA328 E01124D8 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* 3FA32C E01124DC 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* 3FA330 E01124E0 34C60024 */  ori       $a2, $a2, 0x24
/* 3FA334 E01124E4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 3FA338 E01124E8 3C13E700 */  lui       $s3, 0xe700
/* 3FA33C E01124EC AFBF0020 */  sw        $ra, 0x20($sp)
/* 3FA340 E01124F0 AFB20018 */  sw        $s2, 0x18($sp)
/* 3FA344 E01124F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 3FA348 E01124F8 8E030000 */  lw        $v1, ($s0)
/* 3FA34C E01124FC 8C91000C */  lw        $s1, 0xc($a0)
/* 3FA350 E0112500 0060102D */  daddu     $v0, $v1, $zero
/* 3FA354 E0112504 24630008 */  addiu     $v1, $v1, 8
/* 3FA358 E0112508 AE030000 */  sw        $v1, ($s0)
/* 3FA35C E011250C 8E250000 */  lw        $a1, ($s1)
/* 3FA360 E0112510 3C12DE00 */  lui       $s2, 0xde00
/* 3FA364 E0112514 AC530000 */  sw        $s3, ($v0)
/* 3FA368 E0112518 AC400004 */  sw        $zero, 4($v0)
/* 3FA36C E011251C 24620008 */  addiu     $v0, $v1, 8
/* 3FA370 E0112520 AE020000 */  sw        $v0, ($s0)
/* 3FA374 E0112524 24620010 */  addiu     $v0, $v1, 0x10
/* 3FA378 E0112528 AC660000 */  sw        $a2, ($v1)
/* 3FA37C E011252C AE020000 */  sw        $v0, ($s0)
/* 3FA380 E0112530 8C840010 */  lw        $a0, 0x10($a0)
/* 3FA384 E0112534 24620018 */  addiu     $v0, $v1, 0x18
/* 3FA388 E0112538 AE020000 */  sw        $v0, ($s0)
/* 3FA38C E011253C 8C84001C */  lw        $a0, 0x1c($a0)
/* 3FA390 E0112540 3C020900 */  lui       $v0, 0x900
/* 3FA394 E0112544 244242E0 */  addiu     $v0, $v0, 0x42e0
/* 3FA398 E0112548 AC62000C */  sw        $v0, 0xc($v1)
/* 3FA39C E011254C 3C02FB00 */  lui       $v0, 0xfb00
/* 3FA3A0 E0112550 AC620010 */  sw        $v0, 0x10($v1)
/* 3FA3A4 E0112554 240200FF */  addiu     $v0, $zero, 0xff
/* 3FA3A8 E0112558 AC620014 */  sw        $v0, 0x14($v1)
/* 3FA3AC E011255C 3C028000 */  lui       $v0, 0x8000
/* 3FA3B0 E0112560 28A50002 */  slti      $a1, $a1, 2
/* 3FA3B4 E0112564 AC720008 */  sw        $s2, 8($v1)
/* 3FA3B8 E0112568 00822021 */  addu      $a0, $a0, $v0
/* 3FA3BC E011256C 10A00022 */  beqz      $a1, .LE01125F8
/* 3FA3C0 E0112570 AC640004 */   sw       $a0, 4($v1)
/* 3FA3C4 E0112574 0000202D */  daddu     $a0, $zero, $zero
/* 3FA3C8 E0112578 0C0448CC */  jal       func_E0112330
/* 3FA3CC E011257C 0220282D */   daddu    $a1, $s1, $zero
/* 3FA3D0 E0112580 8E030000 */  lw        $v1, ($s0)
/* 3FA3D4 E0112584 3C06D838 */  lui       $a2, 0xd838
/* 3FA3D8 E0112588 0060282D */  daddu     $a1, $v1, $zero
/* 3FA3DC E011258C 24630008 */  addiu     $v1, $v1, 8
/* 3FA3E0 E0112590 AE030000 */  sw        $v1, ($s0)
/* 3FA3E4 E0112594 ACB20000 */  sw        $s2, ($a1)
/* 3FA3E8 E0112598 3C04E011 */  lui       $a0, %hi(D_E0112638)
/* 3FA3EC E011259C 8C842638 */  lw        $a0, %lo(D_E0112638)($a0)
/* 3FA3F0 E01125A0 24620008 */  addiu     $v0, $v1, 8
/* 3FA3F4 E01125A4 AE020000 */  sw        $v0, ($s0)
/* 3FA3F8 E01125A8 ACA40004 */  sw        $a0, 4($a1)
/* 3FA3FC E01125AC AC720000 */  sw        $s2, ($v1)
/* 3FA400 E01125B0 92220034 */  lbu       $v0, 0x34($s1)
/* 3FA404 E01125B4 34C60002 */  ori       $a2, $a2, 2
/* 3FA408 E01125B8 00021080 */  sll       $v0, $v0, 2
/* 3FA40C E01125BC 3C04E011 */  lui       $a0, %hi(D_E0112640)
/* 3FA410 E01125C0 00822021 */  addu      $a0, $a0, $v0
/* 3FA414 E01125C4 8C842640 */  lw        $a0, %lo(D_E0112640)($a0)
/* 3FA418 E01125C8 24620010 */  addiu     $v0, $v1, 0x10
/* 3FA41C E01125CC AE020000 */  sw        $v0, ($s0)
/* 3FA420 E01125D0 AC720008 */  sw        $s2, 8($v1)
/* 3FA424 E01125D4 AC640004 */  sw        $a0, 4($v1)
/* 3FA428 E01125D8 3C04E011 */  lui       $a0, %hi(D_E0112630)
/* 3FA42C E01125DC 8C842630 */  lw        $a0, %lo(D_E0112630)($a0)
/* 3FA430 E01125E0 24620018 */  addiu     $v0, $v1, 0x18
/* 3FA434 E01125E4 AE020000 */  sw        $v0, ($s0)
/* 3FA438 E01125E8 24020040 */  addiu     $v0, $zero, 0x40
/* 3FA43C E01125EC AC660010 */  sw        $a2, 0x10($v1)
/* 3FA440 E01125F0 AC620014 */  sw        $v0, 0x14($v1)
/* 3FA444 E01125F4 AC64000C */  sw        $a0, 0xc($v1)
.LE01125F8:
/* 3FA448 E01125F8 8E020000 */  lw        $v0, ($s0)
/* 3FA44C E01125FC 0040182D */  daddu     $v1, $v0, $zero
/* 3FA450 E0112600 24420008 */  addiu     $v0, $v0, 8
/* 3FA454 E0112604 AE020000 */  sw        $v0, ($s0)
/* 3FA458 E0112608 AC730000 */  sw        $s3, ($v1)
/* 3FA45C E011260C AC600004 */  sw        $zero, 4($v1)
/* 3FA460 E0112610 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3FA464 E0112614 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3FA468 E0112618 8FB20018 */  lw        $s2, 0x18($sp)
/* 3FA46C E011261C 8FB10014 */  lw        $s1, 0x14($sp)
/* 3FA470 E0112620 8FB00010 */  lw        $s0, 0x10($sp)
/* 3FA474 E0112624 03E00008 */  jr        $ra
/* 3FA478 E0112628 27BD0028 */   addiu    $sp, $sp, 0x28
/* 3FA47C E011262C 00000000 */  nop
