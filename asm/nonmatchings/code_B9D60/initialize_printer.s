.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel initialize_printer
/* BBDA4 801256A4 0000182D */  daddu     $v1, $zero, $zero
/* BBDA8 801256A8 2406FFFF */  addiu     $a2, $zero, -1
/* BBDAC 801256AC 0080282D */  daddu     $a1, $a0, $zero
/* BBDB0 801256B0 24020440 */  addiu     $v0, $zero, 0x440
/* BBDB4 801256B4 A4820450 */  sh        $v0, 0x450($a0)
/* BBDB8 801256B8 240200FB */  addiu     $v0, $zero, 0xfb
/* BBDBC 801256BC A0820010 */  sb        $v0, 0x10($a0)
/* BBDC0 801256C0 24020001 */  addiu     $v0, $zero, 1
/* BBDC4 801256C4 A082045E */  sb        $v0, 0x45e($a0)
/* BBDC8 801256C8 A082045F */  sb        $v0, 0x45f($a0)
/* BBDCC 801256CC 24020006 */  addiu     $v0, $zero, 6
/* BBDD0 801256D0 A0820464 */  sb        $v0, 0x464($a0)
/* BBDD4 801256D4 240200FF */  addiu     $v0, $zero, 0xff
/* BBDD8 801256D8 AC800000 */  sw        $zero, ($a0)
/* BBDDC 801256DC AC800008 */  sw        $zero, 8($a0)
/* BBDE0 801256E0 A480000E */  sh        $zero, 0xe($a0)
/* BBDE4 801256E4 A4800456 */  sh        $zero, 0x456($a0)
/* BBDE8 801256E8 A4800458 */  sh        $zero, 0x458($a0)
/* BBDEC 801256EC A480045A */  sh        $zero, 0x45a($a0)
/* BBDF0 801256F0 A480045C */  sh        $zero, 0x45c($a0)
/* BBDF4 801256F4 A080047C */  sb        $zero, 0x47c($a0)
/* BBDF8 801256F8 A480047E */  sh        $zero, 0x47e($a0)
/* BBDFC 801256FC A4800482 */  sh        $zero, 0x482($a0)
/* BBE00 80125700 A4800484 */  sh        $zero, 0x484($a0)
/* BBE04 80125704 A0800486 */  sb        $zero, 0x486($a0)
/* BBE08 80125708 A0800487 */  sb        $zero, 0x487($a0)
/* BBE0C 8012570C A08004CE */  sb        $zero, 0x4ce($a0)
/* BBE10 80125710 A08004E9 */  sb        $zero, 0x4e9($a0)
/* BBE14 80125714 A08004E8 */  sb        $zero, 0x4e8($a0)
/* BBE18 80125718 A08004EE */  sb        $zero, 0x4ee($a0)
/* BBE1C 8012571C A08204EA */  sb        $v0, 0x4ea($a0)
/* BBE20 80125720 A08004F8 */  sb        $zero, 0x4f8($a0)
/* BBE24 80125724 AC8004FC */  sw        $zero, 0x4fc($a0)
/* BBE28 80125728 A4800500 */  sh        $zero, 0x500($a0)
/* BBE2C 8012572C AC800504 */  sw        $zero, 0x504($a0)
/* BBE30 80125730 A4800004 */  sh        $zero, 4($a0)
/* BBE34 80125734 A480000C */  sh        $zero, 0xc($a0)
/* BBE38 80125738 A0800454 */  sb        $zero, 0x454($a0)
/* BBE3C 8012573C A0800455 */  sb        $zero, 0x455($a0)
/* BBE40 80125740 A4800452 */  sh        $zero, 0x452($a0)
/* BBE44 80125744 AC800460 */  sw        $zero, 0x460($a0)
/* BBE48 80125748 AC80046C */  sw        $zero, 0x46c($a0)
/* BBE4C 8012574C A0800468 */  sb        $zero, 0x468($a0)
.L80125750:
/* BBE50 80125750 00831021 */  addu      $v0, $a0, $v1
/* BBE54 80125754 A0400470 */  sb        $zero, 0x470($v0)
/* BBE58 80125758 A4A60474 */  sh        $a2, 0x474($a1)
/* BBE5C 8012575C 24630001 */  addiu     $v1, $v1, 1
/* BBE60 80125760 28620004 */  slti      $v0, $v1, 4
/* BBE64 80125764 1440FFFA */  bnez      $v0, .L80125750
/* BBE68 80125768 24A50002 */   addiu    $a1, $a1, 2
/* BBE6C 8012576C 3C013F80 */  lui       $at, 0x3f80
/* BBE70 80125770 44810000 */  mtc1      $at, $f0
/* BBE74 80125774 240200A0 */  addiu     $v0, $zero, 0xa0
/* BBE78 80125778 A482050A */  sh        $v0, 0x50a($a0)
/* BBE7C 8012577C 24020028 */  addiu     $v0, $zero, 0x28
/* BBE80 80125780 A482050C */  sh        $v0, 0x50c($a0)
/* BBE84 80125784 2402FFFF */  addiu     $v0, $zero, -1
/* BBE88 80125788 A0820518 */  sb        $v0, 0x518($a0)
/* BBE8C 8012578C 24020040 */  addiu     $v0, $zero, 0x40
/* BBE90 80125790 A082051A */  sb        $v0, 0x51a($a0)
/* BBE94 80125794 2402004B */  addiu     $v0, $zero, 0x4b
/* BBE98 80125798 A0820519 */  sb        $v0, 0x519($a0)
/* BBE9C 8012579C 240200FF */  addiu     $v0, $zero, 0xff
/* BBEA0 801257A0 A480047E */  sh        $zero, 0x47e($a0)
/* BBEA4 801257A4 A0800508 */  sb        $zero, 0x508($a0)
/* BBEA8 801257A8 A0800509 */  sb        $zero, 0x509($a0)
/* BBEAC 801257AC A480050E */  sh        $zero, 0x50e($a0)
/* BBEB0 801257B0 A4800510 */  sh        $zero, 0x510($a0)
/* BBEB4 801257B4 A0800512 */  sb        $zero, 0x512($a0)
/* BBEB8 801257B8 A4800516 */  sh        $zero, 0x516($a0)
/* BBEBC 801257BC A4800514 */  sh        $zero, 0x514($a0)
/* BBEC0 801257C0 A480051C */  sh        $zero, 0x51c($a0)
/* BBEC4 801257C4 AC800520 */  sw        $zero, 0x520($a0)
/* BBEC8 801257C8 AC800524 */  sw        $zero, 0x524($a0)
/* BBECC 801257CC A4800528 */  sh        $zero, 0x528($a0)
/* BBED0 801257D0 A080052B */  sb        $zero, 0x52b($a0)
/* BBED4 801257D4 A480052C */  sh        $zero, 0x52c($a0)
/* BBED8 801257D8 A480052E */  sh        $zero, 0x52e($a0)
/* BBEDC 801257DC A0800530 */  sb        $zero, 0x530($a0)
/* BBEE0 801257E0 A0820531 */  sb        $v0, 0x531($a0)
/* BBEE4 801257E4 A0800533 */  sb        $zero, 0x533($a0)
/* BBEE8 801257E8 A4800534 */  sh        $zero, 0x534($a0)
/* BBEEC 801257EC AC800544 */  sw        $zero, 0x544($a0)
/* BBEF0 801257F0 AC800548 */  sw        $zero, 0x548($a0)
/* BBEF4 801257F4 AC80054C */  sw        $zero, 0x54c($a0)
/* BBEF8 801257F8 AC800550 */  sw        $zero, 0x550($a0)
/* BBEFC 801257FC 03E00008 */  jr        $ra
/* BBF00 80125800 E4800540 */   swc1     $f0, 0x540($a0)
