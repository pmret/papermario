.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026E208
/* 19CAE8 8026E208 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19CAEC 8026E20C AFBF0014 */  sw        $ra, 0x14($sp)
/* 19CAF0 8026E210 AFB00010 */  sw        $s0, 0x10($sp)
/* 19CAF4 8026E214 8C82000C */  lw        $v0, 0xc($a0)
/* 19CAF8 8026E218 0C0B1EAF */  jal       get_variable
/* 19CAFC 8026E21C 8C450000 */   lw       $a1, ($v0)
/* 19CB00 8026E220 3C10800E */  lui       $s0, 0x800e
/* 19CB04 8026E224 2610C070 */  addiu     $s0, $s0, -0x3f90
/* 19CB08 8026E228 0040182D */  daddu     $v1, $v0, $zero
/* 19CB0C 8026E22C 10600005 */  beqz      $v1, .L8026E244
/* 19CB10 8026E230 24020001 */   addiu    $v0, $zero, 1
/* 19CB14 8026E234 10620004 */  beq       $v1, $v0, .L8026E248
/* 19CB18 8026E238 2402FFFF */   addiu    $v0, $zero, -1
/* 19CB1C 8026E23C 0809B893 */  j         .L8026E24C
/* 19CB20 8026E240 00000000 */   nop      
.L8026E244:
/* 19CB24 8026E244 24020001 */  addiu     $v0, $zero, 1
.L8026E248:
/* 19CB28 8026E248 A2020094 */  sb        $v0, 0x94($s0)
.L8026E24C:
/* 19CB2C 8026E24C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 19CB30 8026E250 8FB00010 */  lw        $s0, 0x10($sp)
/* 19CB34 8026E254 24020002 */  addiu     $v0, $zero, 2
/* 19CB38 8026E258 03E00008 */  jr        $ra
/* 19CB3C 8026E25C 27BD0018 */   addiu    $sp, $sp, 0x18
