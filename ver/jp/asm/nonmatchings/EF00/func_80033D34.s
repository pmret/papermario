.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80033D34
/* F134 80033D34 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F138 80033D38 AFB00010 */  sw        $s0, 0x10($sp)
/* F13C 80033D3C 3C108007 */  lui       $s0, %hi(D_8007417C)
/* F140 80033D40 2610417C */  addiu     $s0, $s0, %lo(D_8007417C)
/* F144 80033D44 AFBF0014 */  sw        $ra, 0x14($sp)
/* F148 80033D48 8E030000 */  lw        $v1, ($s0)
/* F14C 80033D4C 806200AE */  lb        $v0, 0xae($v1)
/* F150 80033D50 1040000E */  beqz      $v0, .L80033D8C
/* F154 80033D54 8C640010 */   lw       $a0, 0x10($v1)
/* F158 80033D58 0C00CD30 */  jal       func_800334C0
/* F15C 80033D5C 2404000A */   addiu    $a0, $zero, 0xa
/* F160 80033D60 104000AB */  beqz      $v0, .L80034010
/* F164 80033D64 00000000 */   nop
/* F168 80033D68 3C013F80 */  lui       $at, 0x3f80
/* F16C 80033D6C 44816000 */  mtc1      $at, $f12
/* F170 80033D70 0C00AFAB */  jal       func_8002BEAC
/* F174 80033D74 00000000 */   nop
/* F178 80033D78 44806000 */  mtc1      $zero, $f12
/* F17C 80033D7C 0C00AFB9 */  jal       func_8002BEE4
/* F180 80033D80 00000000 */   nop
/* F184 80033D84 0800D002 */  j         .L80034008
/* F188 80033D88 24040002 */   addiu    $a0, $zero, 2
.L80033D8C:
/* F18C 80033D8C 906200AC */  lbu       $v0, 0xac($v1)
/* F190 80033D90 2442FFFF */  addiu     $v0, $v0, -1
/* F194 80033D94 2C42000A */  sltiu     $v0, $v0, 0xa
/* F198 80033D98 10400008 */  beqz      $v0, .L80033DBC
/* F19C 80033D9C 3082B000 */   andi     $v0, $a0, 0xb000
/* F1A0 80033DA0 10400006 */  beqz      $v0, .L80033DBC
/* F1A4 80033DA4 00000000 */   nop
/* F1A8 80033DA8 0C00CD1C */  jal       func_80033470
/* F1AC 80033DAC 240400D0 */   addiu    $a0, $zero, 0xd0
/* F1B0 80033DB0 8E030000 */  lw        $v1, ($s0)
/* F1B4 80033DB4 24020001 */  addiu     $v0, $zero, 1
/* F1B8 80033DB8 A06200AE */  sb        $v0, 0xae($v1)
.L80033DBC:
/* F1BC 80033DBC 3C028007 */  lui       $v0, %hi(D_8007417C)
/* F1C0 80033DC0 8C42417C */  lw        $v0, %lo(D_8007417C)($v0)
/* F1C4 80033DC4 804300AC */  lb        $v1, 0xac($v0)
/* F1C8 80033DC8 2C62000C */  sltiu     $v0, $v1, 0xc
/* F1CC 80033DCC 10400090 */  beqz      $v0, .L80034010
/* F1D0 80033DD0 00031080 */   sll      $v0, $v1, 2
/* F1D4 80033DD4 3C01800A */  lui       $at, %hi(D_80098270)
/* F1D8 80033DD8 00220821 */  addu      $at, $at, $v0
/* F1DC 80033DDC 8C228270 */  lw        $v0, %lo(D_80098270)($at)
/* F1E0 80033DE0 00400008 */  jr        $v0
/* F1E4 80033DE4 00000000 */   nop
/* F1E8 80033DE8 3C108007 */  lui       $s0, %hi(D_8007417C)
/* F1EC 80033DEC 2610417C */  addiu     $s0, $s0, %lo(D_8007417C)
/* F1F0 80033DF0 8E020000 */  lw        $v0, ($s0)
/* F1F4 80033DF4 804200AD */  lb        $v0, 0xad($v0)
/* F1F8 80033DF8 14400046 */  bnez      $v0, .L80033F14
/* F1FC 80033DFC 00000000 */   nop
/* F200 80033E00 0C00CD1C */  jal       func_80033470
/* F204 80033E04 240400D0 */   addiu    $a0, $zero, 0xd0
/* F208 80033E08 8E030000 */  lw        $v1, ($s0)
/* F20C 80033E0C 906200AC */  lbu       $v0, 0xac($v1)
/* F210 80033E10 24420001 */  addiu     $v0, $v0, 1
/* F214 80033E14 0800CFC5 */  j         .L80033F14
/* F218 80033E18 A06200AC */   sb       $v0, 0xac($v1)
/* F21C 80033E1C 0C00CD30 */  jal       func_800334C0
/* F220 80033E20 2404000A */   addiu    $a0, $zero, 0xa
/* F224 80033E24 1040007A */  beqz      $v0, .L80034010
/* F228 80033E28 00000000 */   nop
/* F22C 80033E2C 3C048007 */  lui       $a0, %hi(D_8007417C)
/* F230 80033E30 2484417C */  addiu     $a0, $a0, %lo(D_8007417C)
/* F234 80033E34 8C830000 */  lw        $v1, ($a0)
/* F238 80033E38 906200AC */  lbu       $v0, 0xac($v1)
/* F23C 80033E3C 24420001 */  addiu     $v0, $v0, 1
/* F240 80033E40 A06200AC */  sb        $v0, 0xac($v1)
/* F244 80033E44 8C830000 */  lw        $v1, ($a0)
/* F248 80033E48 906200AC */  lbu       $v0, 0xac($v1)
/* F24C 80033E4C 24420002 */  addiu     $v0, $v0, 2
/* F250 80033E50 0800D004 */  j         .L80034010
/* F254 80033E54 A06200AC */   sb       $v0, 0xac($v1)
/* F258 80033E58 3C108007 */  lui       $s0, %hi(D_8007417C)
/* F25C 80033E5C 2610417C */  addiu     $s0, $s0, %lo(D_8007417C)
/* F260 80033E60 8E030000 */  lw        $v1, ($s0)
/* F264 80033E64 806200AD */  lb        $v0, 0xad($v1)
/* F268 80033E68 1440002B */  bnez      $v0, .L80033F18
/* F26C 80033E6C 0000202D */   daddu    $a0, $zero, $zero
/* F270 80033E70 906200AC */  lbu       $v0, 0xac($v1)
/* F274 80033E74 24420001 */  addiu     $v0, $v0, 1
/* F278 80033E78 0C00CD1C */  jal       func_80033470
/* F27C 80033E7C A06200AC */   sb       $v0, 0xac($v1)
/* F280 80033E80 0800CFC5 */  j         .L80033F14
/* F284 80033E84 00000000 */   nop
/* F288 80033E88 0C00CD30 */  jal       func_800334C0
/* F28C 80033E8C 2404000A */   addiu    $a0, $zero, 0xa
/* F290 80033E90 1040005F */  beqz      $v0, .L80034010
/* F294 80033E94 00000000 */   nop
/* F298 80033E98 3C038007 */  lui       $v1, %hi(D_8007417C)
/* F29C 80033E9C 8C63417C */  lw        $v1, %lo(D_8007417C)($v1)
/* F2A0 80033EA0 0800CFF1 */  j         .L80033FC4
/* F2A4 80033EA4 00000000 */   nop
/* F2A8 80033EA8 0C00CD22 */  jal       func_80033488
/* F2AC 80033EAC 2404000A */   addiu    $a0, $zero, 0xa
/* F2B0 80033EB0 10400057 */  beqz      $v0, .L80034010
/* F2B4 80033EB4 00000000 */   nop
/* F2B8 80033EB8 3C048007 */  lui       $a0, %hi(D_8007417C)
/* F2BC 80033EBC 2484417C */  addiu     $a0, $a0, %lo(D_8007417C)
/* F2C0 80033EC0 8C830000 */  lw        $v1, ($a0)
/* F2C4 80033EC4 906200AC */  lbu       $v0, 0xac($v1)
/* F2C8 80033EC8 24420001 */  addiu     $v0, $v0, 1
/* F2CC 80033ECC A06200AC */  sb        $v0, 0xac($v1)
/* F2D0 80033ED0 8C830000 */  lw        $v1, ($a0)
/* F2D4 80033ED4 2402001E */  addiu     $v0, $zero, 0x1e
/* F2D8 80033ED8 0800D004 */  j         .L80034010
/* F2DC 80033EDC A06200AD */   sb       $v0, 0xad($v1)
/* F2E0 80033EE0 3C108007 */  lui       $s0, %hi(D_8007417C)
/* F2E4 80033EE4 2610417C */  addiu     $s0, $s0, %lo(D_8007417C)
/* F2E8 80033EE8 8E030000 */  lw        $v1, ($s0)
/* F2EC 80033EEC 806200AD */  lb        $v0, 0xad($v1)
/* F2F0 80033EF0 14400009 */  bnez      $v0, .L80033F18
/* F2F4 80033EF4 240400D0 */   addiu    $a0, $zero, 0xd0
/* F2F8 80033EF8 906200AC */  lbu       $v0, 0xac($v1)
/* F2FC 80033EFC 24420001 */  addiu     $v0, $v0, 1
/* F300 80033F00 0C00CD1C */  jal       func_80033470
/* F304 80033F04 A06200AC */   sb       $v0, 0xac($v1)
/* F308 80033F08 8E030000 */  lw        $v1, ($s0)
/* F30C 80033F0C 2402001E */  addiu     $v0, $zero, 0x1e
/* F310 80033F10 A06200AD */  sb        $v0, 0xad($v1)
.L80033F14:
/* F314 80033F14 8E030000 */  lw        $v1, ($s0)
.L80033F18:
/* F318 80033F18 906200AD */  lbu       $v0, 0xad($v1)
/* F31C 80033F1C 2442FFFF */  addiu     $v0, $v0, -1
/* F320 80033F20 0800D004 */  j         .L80034010
/* F324 80033F24 A06200AD */   sb       $v0, 0xad($v1)
/* F328 80033F28 3C048007 */  lui       $a0, %hi(D_8007417C)
/* F32C 80033F2C 8C84417C */  lw        $a0, %lo(D_8007417C)($a0)
/* F330 80033F30 808200AD */  lb        $v0, 0xad($a0)
/* F334 80033F34 908300AD */  lbu       $v1, 0xad($a0)
/* F338 80033F38 14400010 */  bnez      $v0, .L80033F7C
/* F33C 80033F3C 2462FFFF */   addiu    $v0, $v1, -1
/* F340 80033F40 908200AC */  lbu       $v0, 0xac($a0)
/* F344 80033F44 3C013F80 */  lui       $at, 0x3f80
/* F348 80033F48 44816000 */  mtc1      $at, $f12
/* F34C 80033F4C 24420001 */  addiu     $v0, $v0, 1
/* F350 80033F50 0C00AFA7 */  jal       func_8002BE9C
/* F354 80033F54 A08200AC */   sb       $v0, 0xac($a0)
/* F358 80033F58 0C00AFB1 */  jal       func_8002BEC4
/* F35C 80033F5C 0000202D */   daddu    $a0, $zero, $zero
/* F360 80033F60 3C013E99 */  lui       $at, 0x3e99
/* F364 80033F64 3421999A */  ori       $at, $at, 0x999a
/* F368 80033F68 44816000 */  mtc1      $at, $f12
/* F36C 80033F6C 0C00AFB5 */  jal       func_8002BED4
/* F370 80033F70 00000000 */   nop
/* F374 80033F74 0800D004 */  j         .L80034010
/* F378 80033F78 00000000 */   nop
.L80033F7C:
/* F37C 80033F7C 0800D004 */  j         .L80034010
/* F380 80033F80 A08200AD */   sb       $v0, 0xad($a0)
/* F384 80033F84 0C00CD30 */  jal       func_800334C0
/* F388 80033F88 2404000A */   addiu    $a0, $zero, 0xa
/* F38C 80033F8C 10400020 */  beqz      $v0, .L80034010
/* F390 80033F90 2402000F */   addiu    $v0, $zero, 0xf
/* F394 80033F94 3C048007 */  lui       $a0, %hi(D_8007417C)
/* F398 80033F98 2484417C */  addiu     $a0, $a0, %lo(D_8007417C)
/* F39C 80033F9C 8C830000 */  lw        $v1, ($a0)
/* F3A0 80033FA0 A06200AD */  sb        $v0, 0xad($v1)
/* F3A4 80033FA4 0800CFF1 */  j         .L80033FC4
/* F3A8 80033FA8 8C830000 */   lw       $v1, ($a0)
/* F3AC 80033FAC 3C038007 */  lui       $v1, %hi(D_8007417C)
/* F3B0 80033FB0 8C63417C */  lw        $v1, %lo(D_8007417C)($v1)
/* F3B4 80033FB4 806200AD */  lb        $v0, 0xad($v1)
/* F3B8 80033FB8 906400AD */  lbu       $a0, 0xad($v1)
/* F3BC 80033FBC 14400005 */  bnez      $v0, .L80033FD4
/* F3C0 80033FC0 2482FFFF */   addiu    $v0, $a0, -1
.L80033FC4:
/* F3C4 80033FC4 906200AC */  lbu       $v0, 0xac($v1)
/* F3C8 80033FC8 24420001 */  addiu     $v0, $v0, 1
/* F3CC 80033FCC 0800D004 */  j         .L80034010
/* F3D0 80033FD0 A06200AC */   sb       $v0, 0xac($v1)
.L80033FD4:
/* F3D4 80033FD4 0800D004 */  j         .L80034010
/* F3D8 80033FD8 A06200AD */   sb       $v0, 0xad($v1)
/* F3DC 80033FDC 3C10800A */  lui       $s0, %hi(D_8009E720)
/* F3E0 80033FE0 2610E720 */  addiu     $s0, $s0, %lo(D_8009E720)
/* F3E4 80033FE4 0C00AB3B */  jal       func_8002ACEC
/* F3E8 80033FE8 8E040000 */   lw       $a0, ($s0)
/* F3EC 80033FEC 240400FF */  addiu     $a0, $zero, 0xff
/* F3F0 80033FF0 0C00CD18 */  jal       func_80033460
/* F3F4 80033FF4 AE000000 */   sw       $zero, ($s0)
/* F3F8 80033FF8 3C028007 */  lui       $v0, %hi(D_8007417C)
/* F3FC 80033FFC 8C42417C */  lw        $v0, %lo(D_8007417C)($v0)
/* F400 80034000 24040010 */  addiu     $a0, $zero, 0x10
/* F404 80034004 A04000A8 */  sb        $zero, 0xa8($v0)
.L80034008:
/* F408 80034008 0C00CC60 */  jal       func_80033180
/* F40C 8003400C 00000000 */   nop
.L80034010:
/* F410 80034010 0C00E57C */  jal       func_800395F0
/* F414 80034014 00000000 */   nop
/* F418 80034018 0C00B424 */  jal       func_8002D090
/* F41C 8003401C 00000000 */   nop
/* F420 80034020 0C00CD41 */  jal       func_80033504
/* F424 80034024 00000000 */   nop
/* F428 80034028 8FBF0014 */  lw        $ra, 0x14($sp)
/* F42C 8003402C 8FB00010 */  lw        $s0, 0x10($sp)
/* F430 80034030 03E00008 */  jr        $ra
/* F434 80034034 27BD0018 */   addiu    $sp, $sp, 0x18
