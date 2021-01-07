.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011B950
/* B2050 8011B950 3084FFFF */  andi      $a0, $a0, 0xffff
/* B2054 8011B954 3C0A800A */  lui       $t2, %hi(D_8009A5F4)
/* B2058 8011B958 8D4AA5F4 */  lw        $t2, %lo(D_8009A5F4)($t2)
/* B205C 8011B95C 00041080 */  sll       $v0, $a0, 2
/* B2060 8011B960 004A4021 */  addu      $t0, $v0, $t2
/* B2064 8011B964 91030000 */  lbu       $v1, ($t0)
/* B2068 8011B968 286200FF */  slti      $v0, $v1, 0xff
/* B206C 8011B96C 10400004 */  beqz      $v0, .L8011B980
/* B2070 8011B970 2409FFFF */   addiu    $t1, $zero, -1
/* B2074 8011B974 0060482D */  daddu     $t1, $v1, $zero
/* B2078 8011B978 08046E74 */  j         .L8011B9D0
/* B207C 8011B97C 0120582D */   daddu    $t3, $t1, $zero
.L8011B980:
/* B2080 8011B980 2484FFFF */  addiu     $a0, $a0, -1
/* B2084 8011B984 910C0001 */  lbu       $t4, 1($t0)
/* B2088 8011B988 04800011 */  bltz      $a0, .L8011B9D0
/* B208C 8011B98C 00041080 */   sll      $v0, $a0, 2
/* B2090 8011B990 240DFFFF */  addiu     $t5, $zero, -1
/* B2094 8011B994 004A4021 */  addu      $t0, $v0, $t2
.L8011B998:
/* B2098 8011B998 91020001 */  lbu       $v0, 1($t0)
/* B209C 8011B99C 0182102A */  slt       $v0, $t4, $v0
/* B20A0 8011B9A0 1040000C */  beqz      $v0, .L8011B9D4
/* B20A4 8011B9A4 0000502D */   daddu    $t2, $zero, $zero
/* B20A8 8011B9A8 91030000 */  lbu       $v1, ($t0)
/* B20AC 8011B9AC 286200FF */  slti      $v0, $v1, 0xff
/* B20B0 8011B9B0 50400005 */  beql      $v0, $zero, .L8011B9C8
/* B20B4 8011B9B4 2484FFFF */   addiu    $a0, $a0, -1
/* B20B8 8011B9B8 512D0001 */  beql      $t1, $t5, .L8011B9C0
/* B20BC 8011B9BC 0060482D */   daddu    $t1, $v1, $zero
.L8011B9C0:
/* B20C0 8011B9C0 0060582D */  daddu     $t3, $v1, $zero
/* B20C4 8011B9C4 2484FFFF */  addiu     $a0, $a0, -1
.L8011B9C8:
/* B20C8 8011B9C8 0481FFF3 */  bgez      $a0, .L8011B998
/* B20CC 8011B9CC 2508FFFC */   addiu    $t0, $t0, -4
.L8011B9D0:
/* B20D0 8011B9D0 0000502D */  daddu     $t2, $zero, $zero
.L8011B9D4:
/* B20D4 8011B9D4 04A10003 */  bgez      $a1, .L8011B9E4
/* B20D8 8011B9D8 0140402D */   daddu    $t0, $t2, $zero
/* B20DC 8011B9DC 2408000F */  addiu     $t0, $zero, 0xf
/* B20E0 8011B9E0 0140282D */  daddu     $a1, $t2, $zero
.L8011B9E4:
/* B20E4 8011B9E4 04C10004 */  bgez      $a2, .L8011B9F8
/* B20E8 8011B9E8 00061100 */   sll      $v0, $a2, 4
/* B20EC 8011B9EC 240A00F0 */  addiu     $t2, $zero, 0xf0
/* B20F0 8011B9F0 0000302D */  daddu     $a2, $zero, $zero
/* B20F4 8011B9F4 00061100 */  sll       $v0, $a2, 4
.L8011B9F8:
/* B20F8 8011B9F8 14E00015 */  bnez      $a3, .L8011BA50
/* B20FC 8011B9FC 00A22821 */   addu     $a1, $a1, $v0
/* B2100 8011BA00 0160202D */  daddu     $a0, $t3, $zero
/* B2104 8011BA04 0124102A */  slt       $v0, $t1, $a0
/* B2108 8011BA08 1440000F */  bnez      $v0, .L8011BA48
/* B210C 8011BA0C 010A3021 */   addu     $a2, $t0, $t2
/* B2110 8011BA10 3C078015 */  lui       $a3, %hi(gCurrentModelListPtr)
/* B2114 8011BA14 24E712CC */  addiu     $a3, $a3, %lo(gCurrentModelListPtr)
.L8011BA18:
/* B2118 8011BA18 8CE30000 */  lw        $v1, ($a3)
/* B211C 8011BA1C 00041080 */  sll       $v0, $a0, 2
/* B2120 8011BA20 00431021 */  addu      $v0, $v0, $v1
/* B2124 8011BA24 8C430000 */  lw        $v1, ($v0)
/* B2128 8011BA28 906200A5 */  lbu       $v0, 0xa5($v1)
/* B212C 8011BA2C 24840001 */  addiu     $a0, $a0, 1
/* B2130 8011BA30 00461024 */  and       $v0, $v0, $a2
/* B2134 8011BA34 00451021 */  addu      $v0, $v0, $a1
/* B2138 8011BA38 A06200A5 */  sb        $v0, 0xa5($v1)
/* B213C 8011BA3C 0124102A */  slt       $v0, $t1, $a0
/* B2140 8011BA40 1040FFF5 */  beqz      $v0, .L8011BA18
/* B2144 8011BA44 00000000 */   nop      
.L8011BA48:
/* B2148 8011BA48 03E00008 */  jr        $ra
/* B214C 8011BA4C 00000000 */   nop      
.L8011BA50:
/* B2150 8011BA50 19600010 */  blez      $t3, .L8011BA94
/* B2154 8011BA54 0000202D */   daddu    $a0, $zero, $zero
/* B2158 8011BA58 3C078015 */  lui       $a3, %hi(gCurrentModelListPtr)
/* B215C 8011BA5C 24E712CC */  addiu     $a3, $a3, %lo(gCurrentModelListPtr)
/* B2160 8011BA60 010A3021 */  addu      $a2, $t0, $t2
.L8011BA64:
/* B2164 8011BA64 8CE30000 */  lw        $v1, ($a3)
/* B2168 8011BA68 00041080 */  sll       $v0, $a0, 2
/* B216C 8011BA6C 00431021 */  addu      $v0, $v0, $v1
/* B2170 8011BA70 8C430000 */  lw        $v1, ($v0)
/* B2174 8011BA74 906200A5 */  lbu       $v0, 0xa5($v1)
/* B2178 8011BA78 24840001 */  addiu     $a0, $a0, 1
/* B217C 8011BA7C 00461024 */  and       $v0, $v0, $a2
/* B2180 8011BA80 00451021 */  addu      $v0, $v0, $a1
/* B2184 8011BA84 A06200A5 */  sb        $v0, 0xa5($v1)
/* B2188 8011BA88 008B102A */  slt       $v0, $a0, $t3
/* B218C 8011BA8C 1440FFF5 */  bnez      $v0, .L8011BA64
/* B2190 8011BA90 00000000 */   nop      
.L8011BA94:
/* B2194 8011BA94 25240001 */  addiu     $a0, $t1, 1
/* B2198 8011BA98 28820100 */  slti      $v0, $a0, 0x100
/* B219C 8011BA9C 1040FFEA */  beqz      $v0, .L8011BA48
/* B21A0 8011BAA0 010A3021 */   addu     $a2, $t0, $t2
/* B21A4 8011BAA4 3C078015 */  lui       $a3, %hi(gCurrentModelListPtr)
/* B21A8 8011BAA8 24E712CC */  addiu     $a3, $a3, %lo(gCurrentModelListPtr)
.L8011BAAC:
/* B21AC 8011BAAC 8CE30000 */  lw        $v1, ($a3)
/* B21B0 8011BAB0 00041080 */  sll       $v0, $a0, 2
/* B21B4 8011BAB4 00431021 */  addu      $v0, $v0, $v1
/* B21B8 8011BAB8 8C430000 */  lw        $v1, ($v0)
/* B21BC 8011BABC 10600005 */  beqz      $v1, .L8011BAD4
/* B21C0 8011BAC0 24840001 */   addiu    $a0, $a0, 1
/* B21C4 8011BAC4 906200A5 */  lbu       $v0, 0xa5($v1)
/* B21C8 8011BAC8 00461024 */  and       $v0, $v0, $a2
/* B21CC 8011BACC 00451021 */  addu      $v0, $v0, $a1
/* B21D0 8011BAD0 A06200A5 */  sb        $v0, 0xa5($v1)
.L8011BAD4:
/* B21D4 8011BAD4 28820100 */  slti      $v0, $a0, 0x100
/* B21D8 8011BAD8 1440FFF4 */  bnez      $v0, .L8011BAAC
/* B21DC 8011BADC 00000000 */   nop      
/* B21E0 8011BAE0 03E00008 */  jr        $ra
/* B21E4 8011BAE4 00000000 */   nop      
