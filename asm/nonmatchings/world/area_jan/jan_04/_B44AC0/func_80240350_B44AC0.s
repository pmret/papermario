.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240350_B44AC0
/* B44AC0 80240350 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B44AC4 80240354 AFB00010 */  sw        $s0, 0x10($sp)
/* B44AC8 80240358 3C108024 */  lui       $s0, 0x8024
/* B44ACC 8024035C 26101800 */  addiu     $s0, $s0, 0x1800
/* B44AD0 80240360 AFBF0018 */  sw        $ra, 0x18($sp)
/* B44AD4 80240364 AFB10014 */  sw        $s1, 0x14($sp)
/* B44AD8 80240368 8E020000 */  lw        $v0, ($s0)
/* B44ADC 8024036C 14400010 */  bnez      $v0, .L802403B0
/* B44AE0 80240370 0080882D */   daddu    $s1, $a0, $zero
/* B44AE4 80240374 0C00AB39 */  jal       heap_malloc
/* B44AE8 80240378 24040040 */   addiu    $a0, $zero, 0x40
/* B44AEC 8024037C AE020000 */  sw        $v0, ($s0)
/* B44AF0 80240380 0000182D */  daddu     $v1, $zero, $zero
/* B44AF4 80240384 0040282D */  daddu     $a1, $v0, $zero
/* B44AF8 80240388 0220202D */  daddu     $a0, $s1, $zero
.L8024038C:
/* B44AFC 8024038C 8C820084 */  lw        $v0, 0x84($a0)
/* B44B00 80240390 24840004 */  addiu     $a0, $a0, 4
/* B44B04 80240394 24630001 */  addiu     $v1, $v1, 1
/* B44B08 80240398 ACA20000 */  sw        $v0, ($a1)
/* B44B0C 8024039C 28620010 */  slti      $v0, $v1, 0x10
/* B44B10 802403A0 1440FFFA */  bnez      $v0, .L8024038C
/* B44B14 802403A4 24A50004 */   addiu    $a1, $a1, 4
/* B44B18 802403A8 080900FB */  j         .L802403EC
/* B44B1C 802403AC 00000000 */   nop      
.L802403B0:
/* B44B20 802403B0 0000182D */  daddu     $v1, $zero, $zero
/* B44B24 802403B4 0040282D */  daddu     $a1, $v0, $zero
/* B44B28 802403B8 0220202D */  daddu     $a0, $s1, $zero
.L802403BC:
/* B44B2C 802403BC 8CA20000 */  lw        $v0, ($a1)
/* B44B30 802403C0 24A50004 */  addiu     $a1, $a1, 4
/* B44B34 802403C4 24630001 */  addiu     $v1, $v1, 1
/* B44B38 802403C8 AC820084 */  sw        $v0, 0x84($a0)
/* B44B3C 802403CC 28620010 */  slti      $v0, $v1, 0x10
/* B44B40 802403D0 1440FFFA */  bnez      $v0, .L802403BC
/* B44B44 802403D4 24840004 */   addiu    $a0, $a0, 4
/* B44B48 802403D8 3C108024 */  lui       $s0, 0x8024
/* B44B4C 802403DC 26101800 */  addiu     $s0, $s0, 0x1800
/* B44B50 802403E0 0C00AB4B */  jal       heap_free
/* B44B54 802403E4 8E040000 */   lw       $a0, ($s0)
/* B44B58 802403E8 AE000000 */  sw        $zero, ($s0)
.L802403EC:
/* B44B5C 802403EC 8FBF0018 */  lw        $ra, 0x18($sp)
/* B44B60 802403F0 8FB10014 */  lw        $s1, 0x14($sp)
/* B44B64 802403F4 8FB00010 */  lw        $s0, 0x10($sp)
/* B44B68 802403F8 24020002 */  addiu     $v0, $zero, 2
/* B44B6C 802403FC 03E00008 */  jr        $ra
/* B44B70 80240400 27BD0020 */   addiu    $sp, $sp, 0x20
