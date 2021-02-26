.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002B00C
/* 640C 8002B00C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6410 8002B010 AFB00010 */  sw        $s0, 0x10($sp)
/* 6414 8002B014 3C10800E */  lui       $s0, %hi(D_800D95C8)
/* 6418 8002B018 261095C8 */  addiu     $s0, $s0, %lo(D_800D95C8)
/* 641C 8002B01C 3C058007 */  lui       $a1, %hi(D_800745B0)
/* 6420 8002B020 24A545B0 */  addiu     $a1, $a1, %lo(D_800745B0)
/* 6424 8002B024 AFBF0014 */  sw        $ra, 0x14($sp)
/* 6428 8002B028 0C01BB48 */  jal       func_8006ED20
/* 642C 8002B02C 0200202D */   daddu    $a0, $s0, $zero
/* 6430 8002B030 2402FFFF */  addiu     $v0, $zero, -1
/* 6434 8002B034 AE000030 */  sw        $zero, 0x30($s0)
/* 6438 8002B038 0C00ABC0 */  jal       func_8002AF00
/* 643C 8002B03C AE020034 */   sw       $v0, 0x34($s0)
/* 6440 8002B040 24040006 */  addiu     $a0, $zero, 6
/* 6444 8002B044 AE020030 */  sw        $v0, 0x30($s0)
/* 6448 8002B048 00021027 */  nor       $v0, $zero, $v0
/* 644C 8002B04C 0C00AE77 */  jal       func_8002B9DC
/* 6450 8002B050 AE020034 */   sw       $v0, 0x34($s0)
/* 6454 8002B054 24040006 */  addiu     $a0, $zero, 6
/* 6458 8002B058 0200282D */  daddu     $a1, $s0, $zero
/* 645C 8002B05C 0C00AE42 */  jal       func_8002B908
/* 6460 8002B060 24060080 */   addiu    $a2, $zero, 0x80
/* 6464 8002B064 0C00AE77 */  jal       func_8002B9DC
/* 6468 8002B068 24040007 */   addiu    $a0, $zero, 7
/* 646C 8002B06C 24040007 */  addiu     $a0, $zero, 7
/* 6470 8002B070 0200282D */  daddu     $a1, $s0, $zero
/* 6474 8002B074 0C00AE42 */  jal       func_8002B908
/* 6478 8002B078 24060080 */   addiu    $a2, $zero, 0x80
/* 647C 8002B07C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6480 8002B080 8FB00010 */  lw        $s0, 0x10($sp)
/* 6484 8002B084 24020001 */  addiu     $v0, $zero, 1
/* 6488 8002B088 03E00008 */  jr        $ra
/* 648C 8002B08C 27BD0018 */   addiu    $sp, $sp, 0x18
