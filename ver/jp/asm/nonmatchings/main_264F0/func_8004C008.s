.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004C008
/* 27408 8004C008 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 2740C 8004C00C AFB40020 */  sw        $s4, 0x20($sp)
/* 27410 8004C010 0080A02D */  daddu     $s4, $a0, $zero
/* 27414 8004C014 AFB20018 */  sw        $s2, 0x18($sp)
/* 27418 8004C018 00A0902D */  daddu     $s2, $a1, $zero
/* 2741C 8004C01C AFB10014 */  sw        $s1, 0x14($sp)
/* 27420 8004C020 0000882D */  daddu     $s1, $zero, $zero
/* 27424 8004C024 AFBF0024 */  sw        $ra, 0x24($sp)
/* 27428 8004C028 AFB3001C */  sw        $s3, 0x1c($sp)
/* 2742C 8004C02C AFB00010 */  sw        $s0, 0x10($sp)
/* 27430 8004C030 96420000 */  lhu       $v0, ($s2)
/* 27434 8004C034 2410016C */  addiu     $s0, $zero, 0x16c
/* 27438 8004C038 305323FF */  andi      $s3, $v0, 0x23ff
.L8004C03C:
/* 2743C 8004C03C 02902021 */  addu      $a0, $s4, $s0
/* 27440 8004C040 94820096 */  lhu       $v0, 0x96($a0)
/* 27444 8004C044 54530004 */  bnel      $v0, $s3, .L8004C058
/* 27448 8004C048 26310001 */   addiu    $s1, $s1, 1
/* 2744C 8004C04C 0C013021 */  jal       func_8004C084
/* 27450 8004C050 0240282D */   daddu    $a1, $s2, $zero
/* 27454 8004C054 26310001 */  addiu     $s1, $s1, 1
.L8004C058:
/* 27458 8004C058 2A220008 */  slti      $v0, $s1, 8
/* 2745C 8004C05C 1440FFF7 */  bnez      $v0, .L8004C03C
/* 27460 8004C060 261000AC */   addiu    $s0, $s0, 0xac
/* 27464 8004C064 8FBF0024 */  lw        $ra, 0x24($sp)
/* 27468 8004C068 8FB40020 */  lw        $s4, 0x20($sp)
/* 2746C 8004C06C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 27470 8004C070 8FB20018 */  lw        $s2, 0x18($sp)
/* 27474 8004C074 8FB10014 */  lw        $s1, 0x14($sp)
/* 27478 8004C078 8FB00010 */  lw        $s0, 0x10($sp)
/* 2747C 8004C07C 03E00008 */  jr        $ra
/* 27480 8004C080 27BD0028 */   addiu    $sp, $sp, 0x28
