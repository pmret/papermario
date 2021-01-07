.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021C004_6A3204
/* 6A3204 8021C004 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A3208 8021C008 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A320C 8021C00C 0080802D */  daddu     $s0, $a0, $zero
/* 6A3210 8021C010 10A0000E */  beqz      $a1, .L8021C04C
/* 6A3214 8021C014 AFBF0014 */   sw       $ra, 0x14($sp)
/* 6A3218 8021C018 0C04760B */  jal       func_8011D82C
/* 6A321C 8021C01C 24040001 */   addiu    $a0, $zero, 1
/* 6A3220 8021C020 0000202D */  daddu     $a0, $zero, $zero
/* 6A3224 8021C024 0080282D */  daddu     $a1, $a0, $zero
/* 6A3228 8021C028 0080302D */  daddu     $a2, $a0, $zero
/* 6A322C 8021C02C 0080382D */  daddu     $a3, $a0, $zero
/* 6A3230 8021C030 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 6A3234 8021C034 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 6A3238 8021C038 24030001 */  addiu     $v1, $zero, 1
/* 6A323C 8021C03C 0C046F97 */  jal       set_background_color_blend
/* 6A3240 8021C040 A0430000 */   sb       $v1, ($v0)
/* 6A3244 8021C044 24020014 */  addiu     $v0, $zero, 0x14
/* 6A3248 8021C048 AE020070 */  sw        $v0, 0x70($s0)
.L8021C04C:
/* 6A324C 8021C04C 0000202D */  daddu     $a0, $zero, $zero
/* 6A3250 8021C050 0080282D */  daddu     $a1, $a0, $zero
/* 6A3254 8021C054 0080302D */  daddu     $a2, $a0, $zero
/* 6A3258 8021C058 8E030070 */  lw        $v1, 0x70($s0)
/* 6A325C 8021C05C 24020014 */  addiu     $v0, $zero, 0x14
/* 6A3260 8021C060 00431023 */  subu      $v0, $v0, $v1
/* 6A3264 8021C064 00023880 */  sll       $a3, $v0, 2
/* 6A3268 8021C068 00E23821 */  addu      $a3, $a3, $v0
/* 6A326C 8021C06C 00073840 */  sll       $a3, $a3, 1
/* 6A3270 8021C070 0C046F97 */  jal       set_background_color_blend
/* 6A3274 8021C074 30E700FE */   andi     $a3, $a3, 0xfe
/* 6A3278 8021C078 8E020070 */  lw        $v0, 0x70($s0)
/* 6A327C 8021C07C 2442FFFF */  addiu     $v0, $v0, -1
/* 6A3280 8021C080 AE020070 */  sw        $v0, 0x70($s0)
/* 6A3284 8021C084 2C420001 */  sltiu     $v0, $v0, 1
/* 6A3288 8021C088 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6A328C 8021C08C 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A3290 8021C090 00021040 */  sll       $v0, $v0, 1
/* 6A3294 8021C094 03E00008 */  jr        $ra
/* 6A3298 8021C098 27BD0018 */   addiu    $sp, $sp, 0x18
