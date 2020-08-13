.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel initialize_printer
/* 0BBDA4 801256A4 0000182D */  daddu $v1, $zero, $zero
/* 0BBDA8 801256A8 2406FFFF */  addiu $a2, $zero, -1
/* 0BBDAC 801256AC 0080282D */  daddu $a1, $a0, $zero
/* 0BBDB0 801256B0 24020440 */  addiu $v0, $zero, 0x440
/* 0BBDB4 801256B4 A4820450 */  sh    $v0, 0x450($a0)
/* 0BBDB8 801256B8 240200FB */  addiu $v0, $zero, 0xfb
/* 0BBDBC 801256BC A0820010 */  sb    $v0, 0x10($a0)
/* 0BBDC0 801256C0 24020001 */  addiu $v0, $zero, 1
/* 0BBDC4 801256C4 A082045E */  sb    $v0, 0x45e($a0)
/* 0BBDC8 801256C8 A082045F */  sb    $v0, 0x45f($a0)
/* 0BBDCC 801256CC 24020006 */  addiu $v0, $zero, 6
/* 0BBDD0 801256D0 A0820464 */  sb    $v0, 0x464($a0)
/* 0BBDD4 801256D4 240200FF */  addiu $v0, $zero, 0xff
/* 0BBDD8 801256D8 AC800000 */  sw    $zero, ($a0)
/* 0BBDDC 801256DC AC800008 */  sw    $zero, 8($a0)
/* 0BBDE0 801256E0 A480000E */  sh    $zero, 0xe($a0)
/* 0BBDE4 801256E4 A4800456 */  sh    $zero, 0x456($a0)
/* 0BBDE8 801256E8 A4800458 */  sh    $zero, 0x458($a0)
/* 0BBDEC 801256EC A480045A */  sh    $zero, 0x45a($a0)
/* 0BBDF0 801256F0 A480045C */  sh    $zero, 0x45c($a0)
/* 0BBDF4 801256F4 A080047C */  sb    $zero, 0x47c($a0)
/* 0BBDF8 801256F8 A480047E */  sh    $zero, 0x47e($a0)
/* 0BBDFC 801256FC A4800482 */  sh    $zero, 0x482($a0)
/* 0BBE00 80125700 A4800484 */  sh    $zero, 0x484($a0)
/* 0BBE04 80125704 A0800486 */  sb    $zero, 0x486($a0)
/* 0BBE08 80125708 A0800487 */  sb    $zero, 0x487($a0)
/* 0BBE0C 8012570C A08004CE */  sb    $zero, 0x4ce($a0)
/* 0BBE10 80125710 A08004E9 */  sb    $zero, 0x4e9($a0)
/* 0BBE14 80125714 A08004E8 */  sb    $zero, 0x4e8($a0)
/* 0BBE18 80125718 A08004EE */  sb    $zero, 0x4ee($a0)
/* 0BBE1C 8012571C A08204EA */  sb    $v0, 0x4ea($a0)
/* 0BBE20 80125720 A08004F8 */  sb    $zero, 0x4f8($a0)
/* 0BBE24 80125724 AC8004FC */  sw    $zero, 0x4fc($a0)
/* 0BBE28 80125728 A4800500 */  sh    $zero, 0x500($a0)
/* 0BBE2C 8012572C AC800504 */  sw    $zero, 0x504($a0)
/* 0BBE30 80125730 A4800004 */  sh    $zero, 4($a0)
/* 0BBE34 80125734 A480000C */  sh    $zero, 0xc($a0)
/* 0BBE38 80125738 A0800454 */  sb    $zero, 0x454($a0)
/* 0BBE3C 8012573C A0800455 */  sb    $zero, 0x455($a0)
/* 0BBE40 80125740 A4800452 */  sh    $zero, 0x452($a0)
/* 0BBE44 80125744 AC800460 */  sw    $zero, 0x460($a0)
/* 0BBE48 80125748 AC80046C */  sw    $zero, 0x46c($a0)
/* 0BBE4C 8012574C A0800468 */  sb    $zero, 0x468($a0)
.L80125750:
/* 0BBE50 80125750 00831021 */  addu  $v0, $a0, $v1
/* 0BBE54 80125754 A0400470 */  sb    $zero, 0x470($v0)
/* 0BBE58 80125758 A4A60474 */  sh    $a2, 0x474($a1)
/* 0BBE5C 8012575C 24630001 */  addiu $v1, $v1, 1
/* 0BBE60 80125760 28620004 */  slti  $v0, $v1, 4
/* 0BBE64 80125764 1440FFFA */  bnez  $v0, .L80125750
/* 0BBE68 80125768 24A50002 */   addiu $a1, $a1, 2
/* 0BBE6C 8012576C 3C013F80 */  lui   $at, 0x3f80
/* 0BBE70 80125770 44810000 */  mtc1  $at, $f0
/* 0BBE74 80125774 240200A0 */  addiu $v0, $zero, 0xa0
/* 0BBE78 80125778 A482050A */  sh    $v0, 0x50a($a0)
/* 0BBE7C 8012577C 24020028 */  addiu $v0, $zero, 0x28
/* 0BBE80 80125780 A482050C */  sh    $v0, 0x50c($a0)
/* 0BBE84 80125784 2402FFFF */  addiu $v0, $zero, -1
/* 0BBE88 80125788 A0820518 */  sb    $v0, 0x518($a0)
/* 0BBE8C 8012578C 24020040 */  addiu $v0, $zero, 0x40
/* 0BBE90 80125790 A082051A */  sb    $v0, 0x51a($a0)
/* 0BBE94 80125794 2402004B */  addiu $v0, $zero, 0x4b
/* 0BBE98 80125798 A0820519 */  sb    $v0, 0x519($a0)
/* 0BBE9C 8012579C 240200FF */  addiu $v0, $zero, 0xff
/* 0BBEA0 801257A0 A480047E */  sh    $zero, 0x47e($a0)
/* 0BBEA4 801257A4 A0800508 */  sb    $zero, 0x508($a0)
/* 0BBEA8 801257A8 A0800509 */  sb    $zero, 0x509($a0)
/* 0BBEAC 801257AC A480050E */  sh    $zero, 0x50e($a0)
/* 0BBEB0 801257B0 A4800510 */  sh    $zero, 0x510($a0)
/* 0BBEB4 801257B4 A0800512 */  sb    $zero, 0x512($a0)
/* 0BBEB8 801257B8 A4800516 */  sh    $zero, 0x516($a0)
/* 0BBEBC 801257BC A4800514 */  sh    $zero, 0x514($a0)
/* 0BBEC0 801257C0 A480051C */  sh    $zero, 0x51c($a0)
/* 0BBEC4 801257C4 AC800520 */  sw    $zero, 0x520($a0)
/* 0BBEC8 801257C8 AC800524 */  sw    $zero, 0x524($a0)
/* 0BBECC 801257CC A4800528 */  sh    $zero, 0x528($a0)
/* 0BBED0 801257D0 A080052B */  sb    $zero, 0x52b($a0)
/* 0BBED4 801257D4 A480052C */  sh    $zero, 0x52c($a0)
/* 0BBED8 801257D8 A480052E */  sh    $zero, 0x52e($a0)
/* 0BBEDC 801257DC A0800530 */  sb    $zero, 0x530($a0)
/* 0BBEE0 801257E0 A0820531 */  sb    $v0, 0x531($a0)
/* 0BBEE4 801257E4 A0800533 */  sb    $zero, 0x533($a0)
/* 0BBEE8 801257E8 A4800534 */  sh    $zero, 0x534($a0)
/* 0BBEEC 801257EC AC800544 */  sw    $zero, 0x544($a0)
/* 0BBEF0 801257F0 AC800548 */  sw    $zero, 0x548($a0)
/* 0BBEF4 801257F4 AC80054C */  sw    $zero, 0x54c($a0)
/* 0BBEF8 801257F8 AC800550 */  sw    $zero, 0x550($a0)
/* 0BBEFC 801257FC 03E00008 */  jr    $ra
/* 0BBF00 80125800 E4800540 */   swc1  $f0, 0x540($a0)

