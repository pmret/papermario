.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003ECD8
/* 1A0D8 8003ECD8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1A0DC 8003ECDC AFB00010 */  sw        $s0, 0x10($sp)
/* 1A0E0 8003ECE0 00A0802D */  daddu     $s0, $a1, $zero
/* 1A0E4 8003ECE4 2404FFF6 */  addiu     $a0, $zero, -0xa
/* 1A0E8 8003ECE8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1A0EC 8003ECEC 0C00E9EB */  jal       func_8003A7AC
/* 1A0F0 8003ECF0 AFB10014 */   sw       $s1, 0x14($sp)
/* 1A0F4 8003ECF4 12000004 */  beqz      $s0, .L8003ED08
/* 1A0F8 8003ECF8 0040882D */   daddu    $s1, $v0, $zero
/* 1A0FC 8003ECFC 0C053B59 */  jal       func_8014ED64
/* 1A100 8003ED00 2404024B */   addiu    $a0, $zero, 0x24b
/* 1A104 8003ED04 A22000AC */  sb        $zero, 0xac($s1)
.L8003ED08:
/* 1A108 8003ED08 922200AC */  lbu       $v0, 0xac($s1)
/* 1A10C 8003ED0C 24420011 */  addiu     $v0, $v0, 0x11
/* 1A110 8003ED10 A22200AC */  sb        $v0, 0xac($s1)
/* 1A114 8003ED14 304200FF */  andi      $v0, $v0, 0xff
/* 1A118 8003ED18 2C4200FF */  sltiu     $v0, $v0, 0xff
/* 1A11C 8003ED1C 14400004 */  bnez      $v0, .L8003ED30
/* 1A120 8003ED20 0000102D */   daddu    $v0, $zero, $zero
/* 1A124 8003ED24 240200FF */  addiu     $v0, $zero, 0xff
/* 1A128 8003ED28 A22200AC */  sb        $v0, 0xac($s1)
/* 1A12C 8003ED2C 24020001 */  addiu     $v0, $zero, 1
.L8003ED30:
/* 1A130 8003ED30 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1A134 8003ED34 8FB10014 */  lw        $s1, 0x14($sp)
/* 1A138 8003ED38 8FB00010 */  lw        $s0, 0x10($sp)
/* 1A13C 8003ED3C 03E00008 */  jr        $ra
/* 1A140 8003ED40 27BD0020 */   addiu    $sp, $sp, 0x20
