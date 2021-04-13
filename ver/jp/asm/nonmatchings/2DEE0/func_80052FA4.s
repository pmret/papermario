.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80052FA4
/* 2E3A4 80052FA4 3C013F00 */  lui       $at, 0x3f00
/* 2E3A8 80052FA8 44810000 */  mtc1      $at, $f0
/* 2E3AC 80052FAC 3C028008 */  lui       $v0, %hi(D_800781A0)
/* 2E3B0 80052FB0 244281A0 */  addiu     $v0, $v0, %lo(D_800781A0)
/* 2E3B4 80052FB4 AC820000 */  sw        $v0, ($a0)
/* 2E3B8 80052FB8 240200BE */  addiu     $v0, $zero, 0xbe
/* 2E3BC 80052FBC AC820004 */  sw        $v0, 4($a0)
/* 2E3C0 80052FC0 3C028008 */  lui       $v0, %hi(D_80078160)
/* 2E3C4 80052FC4 24428160 */  addiu     $v0, $v0, %lo(D_80078160)
/* 2E3C8 80052FC8 AC820018 */  sw        $v0, 0x18($a0)
/* 2E3CC 80052FCC 24020040 */  addiu     $v0, $zero, 0x40
/* 2E3D0 80052FD0 A482001C */  sh        $v0, 0x1c($a0)
/* 2E3D4 80052FD4 240212C0 */  addiu     $v0, $zero, 0x12c0
/* 2E3D8 80052FD8 A482001E */  sh        $v0, 0x1e($a0)
/* 2E3DC 80052FDC 3C028008 */  lui       $v0, %hi(D_80078514)
/* 2E3E0 80052FE0 24428514 */  addiu     $v0, $v0, %lo(D_80078514)
/* 2E3E4 80052FE4 AC800008 */  sw        $zero, 8($a0)
/* 2E3E8 80052FE8 AC80000C */  sw        $zero, 0xc($a0)
/* 2E3EC 80052FEC AC800010 */  sw        $zero, 0x10($a0)
/* 2E3F0 80052FF0 AC800014 */  sw        $zero, 0x14($a0)
/* 2E3F4 80052FF4 A0800024 */  sb        $zero, 0x24($a0)
/* 2E3F8 80052FF8 A0800025 */  sb        $zero, 0x25($a0)
/* 2E3FC 80052FFC AC82002C */  sw        $v0, 0x2c($a0)
/* 2E400 80053000 A0800026 */  sb        $zero, 0x26($a0)
/* 2E404 80053004 A0800027 */  sb        $zero, 0x27($a0)
/* 2E408 80053008 A0800028 */  sb        $zero, 0x28($a0)
/* 2E40C 8005300C A0800029 */  sb        $zero, 0x29($a0)
/* 2E410 80053010 A080002A */  sb        $zero, 0x2a($a0)
/* 2E414 80053014 A080002B */  sb        $zero, 0x2b($a0)
/* 2E418 80053018 03E00008 */  jr        $ra
/* 2E41C 8005301C E4800020 */   swc1     $f0, 0x20($a0)
