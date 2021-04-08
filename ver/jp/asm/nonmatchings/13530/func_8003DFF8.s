.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003DFF8
/* 193F8 8003DFF8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 193FC 8003DFFC AFBF0010 */  sw        $ra, 0x10($sp)
/* 19400 8003E000 24050017 */  addiu     $a1, $zero, 0x17
/* 19404 8003E004 3C06800B */  lui       $a2, %hi(D_800B0EF0)
/* 19408 8003E008 24C60EF0 */  addiu     $a2, $a2, %lo(D_800B0EF0)
/* 1940C 8003E00C 24C2005C */  addiu     $v0, $a2, 0x5c
.L8003E010:
/* 19410 8003E010 AC400028 */  sw        $zero, 0x28($v0)
/* 19414 8003E014 24A5FFFF */  addiu     $a1, $a1, -1
/* 19418 8003E018 04A1FFFD */  bgez      $a1, .L8003E010
/* 1941C 8003E01C 2442FFFC */   addiu    $v0, $v0, -4
/* 19420 8003E020 0000282D */  daddu     $a1, $zero, $zero
/* 19424 8003E024 00A0382D */  daddu     $a3, $a1, $zero
/* 19428 8003E028 ACC00000 */  sw        $zero, ($a2)
/* 1942C 8003E02C A0C0001C */  sb        $zero, 0x1c($a2)
/* 19430 8003E030 A0C00004 */  sb        $zero, 4($a2)
/* 19434 8003E034 A0C00005 */  sb        $zero, 5($a2)
/* 19438 8003E038 A0C0000A */  sb        $zero, 0xa($a2)
/* 1943C 8003E03C ACC00024 */  sw        $zero, 0x24($a2)
/* 19440 8003E040 A0C00008 */  sb        $zero, 8($a2)
/* 19444 8003E044 A0C00013 */  sb        $zero, 0x13($a2)
.L8003E048:
/* 19448 8003E048 0000202D */  daddu     $a0, $zero, $zero
/* 1944C 8003E04C 00E0182D */  daddu     $v1, $a3, $zero
.L8003E050:
/* 19450 8003E050 00C31021 */  addu      $v0, $a2, $v1
/* 19454 8003E054 AC4000B0 */  sw        $zero, 0xb0($v0)
/* 19458 8003E058 24840001 */  addiu     $a0, $a0, 1
/* 1945C 8003E05C 2882000C */  slti      $v0, $a0, 0xc
/* 19460 8003E060 1440FFFB */  bnez      $v0, .L8003E050
/* 19464 8003E064 24630004 */   addiu    $v1, $v1, 4
/* 19468 8003E068 24A50001 */  addiu     $a1, $a1, 1
/* 1946C 8003E06C 28A2003C */  slti      $v0, $a1, 0x3c
/* 19470 8003E070 1440FFF5 */  bnez      $v0, .L8003E048
/* 19474 8003E074 24E70030 */   addiu    $a3, $a3, 0x30
/* 19478 8003E078 2403FFFF */  addiu     $v1, $zero, -1
/* 1947C 8003E07C 24050001 */  addiu     $a1, $zero, 1
/* 19480 8003E080 24C20002 */  addiu     $v0, $a2, 2
.L8003E084:
/* 19484 8003E084 A4430BF0 */  sh        $v1, 0xbf0($v0)
/* 19488 8003E088 24A5FFFF */  addiu     $a1, $a1, -1
/* 1948C 8003E08C 04A1FFFD */  bgez      $a1, .L8003E084
/* 19490 8003E090 2442FFFE */   addiu    $v0, $v0, -2
/* 19494 8003E094 0C0115E0 */  jal       func_80045780
/* 19498 8003E098 00000000 */   nop
/* 1949C 8003E09C 3C058004 */  lui       $a1, %hi(func_8003E330)
/* 194A0 8003E0A0 24A5E330 */  addiu     $a1, $a1, %lo(func_8003E330)
/* 194A4 8003E0A4 3C01800A */  lui       $at, %hi(D_8009A5E0)
/* 194A8 8003E0A8 AC20A5E0 */  sw        $zero, %lo(D_8009A5E0)($at)
/* 194AC 8003E0AC 0C04A0DA */  jal       func_80128368
/* 194B0 8003E0B0 0000202D */   daddu    $a0, $zero, $zero
/* 194B4 8003E0B4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 194B8 8003E0B8 03E00008 */  jr        $ra
/* 194BC 8003E0BC 27BD0018 */   addiu    $sp, $sp, 0x18
