.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243DB0_9DADD0
/* 9DADD0 80243DB0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9DADD4 80243DB4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9DADD8 80243DB8 3C108025 */  lui       $s0, 0x8025
/* 9DADDC 80243DBC 26102720 */  addiu     $s0, $s0, 0x2720
/* 9DADE0 80243DC0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9DADE4 80243DC4 AFB10014 */  sw        $s1, 0x14($sp)
/* 9DADE8 80243DC8 8E020000 */  lw        $v0, ($s0)
/* 9DADEC 80243DCC 14400010 */  bnez      $v0, .L80243E10
/* 9DADF0 80243DD0 0080882D */   daddu    $s1, $a0, $zero
/* 9DADF4 80243DD4 0C00AB39 */  jal       heap_malloc
/* 9DADF8 80243DD8 24040040 */   addiu    $a0, $zero, 0x40
/* 9DADFC 80243DDC AE020000 */  sw        $v0, ($s0)
/* 9DAE00 80243DE0 0000182D */  daddu     $v1, $zero, $zero
/* 9DAE04 80243DE4 0040282D */  daddu     $a1, $v0, $zero
/* 9DAE08 80243DE8 0220202D */  daddu     $a0, $s1, $zero
.L80243DEC:
/* 9DAE0C 80243DEC 8C820084 */  lw        $v0, 0x84($a0)
/* 9DAE10 80243DF0 24840004 */  addiu     $a0, $a0, 4
/* 9DAE14 80243DF4 24630001 */  addiu     $v1, $v1, 1
/* 9DAE18 80243DF8 ACA20000 */  sw        $v0, ($a1)
/* 9DAE1C 80243DFC 28620010 */  slti      $v0, $v1, 0x10
/* 9DAE20 80243E00 1440FFFA */  bnez      $v0, .L80243DEC
/* 9DAE24 80243E04 24A50004 */   addiu    $a1, $a1, 4
/* 9DAE28 80243E08 08090F93 */  j         .L80243E4C
/* 9DAE2C 80243E0C 00000000 */   nop      
.L80243E10:
/* 9DAE30 80243E10 0000182D */  daddu     $v1, $zero, $zero
/* 9DAE34 80243E14 0040282D */  daddu     $a1, $v0, $zero
/* 9DAE38 80243E18 0220202D */  daddu     $a0, $s1, $zero
.L80243E1C:
/* 9DAE3C 80243E1C 8CA20000 */  lw        $v0, ($a1)
/* 9DAE40 80243E20 24A50004 */  addiu     $a1, $a1, 4
/* 9DAE44 80243E24 24630001 */  addiu     $v1, $v1, 1
/* 9DAE48 80243E28 AC820084 */  sw        $v0, 0x84($a0)
/* 9DAE4C 80243E2C 28620010 */  slti      $v0, $v1, 0x10
/* 9DAE50 80243E30 1440FFFA */  bnez      $v0, .L80243E1C
/* 9DAE54 80243E34 24840004 */   addiu    $a0, $a0, 4
/* 9DAE58 80243E38 3C108025 */  lui       $s0, 0x8025
/* 9DAE5C 80243E3C 26102720 */  addiu     $s0, $s0, 0x2720
/* 9DAE60 80243E40 0C00AB4B */  jal       heap_free
/* 9DAE64 80243E44 8E040000 */   lw       $a0, ($s0)
/* 9DAE68 80243E48 AE000000 */  sw        $zero, ($s0)
.L80243E4C:
/* 9DAE6C 80243E4C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9DAE70 80243E50 8FB10014 */  lw        $s1, 0x14($sp)
/* 9DAE74 80243E54 8FB00010 */  lw        $s0, 0x10($sp)
/* 9DAE78 80243E58 24020002 */  addiu     $v0, $zero, 2
/* 9DAE7C 80243E5C 03E00008 */  jr        $ra
/* 9DAE80 80243E60 27BD0020 */   addiu    $sp, $sp, 0x20
