.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E205C
/* 7B50C 800E205C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7B510 800E2060 2402FFFF */  addiu     $v0, $zero, -1
/* 7B514 800E2064 3C058011 */  lui       $a1, %hi(D_8010C92C)
/* 7B518 800E2068 24A5C92C */  addiu     $a1, $a1, %lo(D_8010C92C)
/* 7B51C 800E206C AFB00010 */  sw        $s0, 0x10($sp)
/* 7B520 800E2070 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 7B524 800E2074 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 7B528 800E2078 3C018011 */  lui       $at, %hi(D_8010C96C)
/* 7B52C 800E207C AC22C96C */  sw        $v0, %lo(D_8010C96C)($at)
/* 7B530 800E2080 24020001 */  addiu     $v0, $zero, 1
/* 7B534 800E2084 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7B538 800E2088 3C018011 */  lui       $at, %hi(D_8010C954)
/* 7B53C 800E208C AC20C954 */  sw        $zero, %lo(D_8010C954)($at)
/* 7B540 800E2090 3C018011 */  lui       $at, %hi(D_8010C920)
/* 7B544 800E2094 AC20C920 */  sw        $zero, %lo(D_8010C920)($at)
/* 7B548 800E2098 3C018011 */  lui       $at, %hi(D_8010C940)
/* 7B54C 800E209C AC20C940 */  sw        $zero, %lo(D_8010C940)($at)
/* 7B550 800E20A0 3C018011 */  lui       $at, %hi(D_8010C958)
/* 7B554 800E20A4 AC20C958 */  sw        $zero, %lo(D_8010C958)($at)
/* 7B558 800E20A8 ACA00000 */  sw        $zero, ($a1)
/* 7B55C 800E20AC 3C018011 */  lui       $at, %hi(D_8010C95C)
/* 7B560 800E20B0 AC20C95C */  sw        $zero, %lo(D_8010C95C)($at)
/* 7B564 800E20B4 3C018011 */  lui       $at, %hi(D_8010C980)
/* 7B568 800E20B8 AC20C980 */  sw        $zero, %lo(D_8010C980)($at)
/* 7B56C 800E20BC 3C01800F */  lui       $at, %hi(D_800F7B40)
/* 7B570 800E20C0 AC207B40 */  sw        $zero, %lo(D_800F7B40)($at)
/* 7B574 800E20C4 3C01800F */  lui       $at, %hi(D_800F7B44)
/* 7B578 800E20C8 AC207B44 */  sw        $zero, %lo(D_800F7B44)($at)
/* 7B57C 800E20CC 3C018011 */  lui       $at, %hi(D_8010C938)
/* 7B580 800E20D0 AC20C938 */  sw        $zero, %lo(D_8010C938)($at)
/* 7B584 800E20D4 3C018011 */  lui       $at, %hi(D_8010C990)
/* 7B588 800E20D8 AC20C990 */  sw        $zero, %lo(D_8010C990)($at)
/* 7B58C 800E20DC A202000D */  sb        $v0, 0xd($s0)
/* 7B590 800E20E0 2402000D */  addiu     $v0, $zero, 0xd
/* 7B594 800E20E4 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 7B598 800E20E8 2484419C */  addiu     $a0, $a0, %lo(gGameStatusPtr)
/* 7B59C 800E20EC A20200BE */  sb        $v0, 0xbe($s0)
/* 7B5A0 800E20F0 8C830000 */  lw        $v1, ($a0)
/* 7B5A4 800E20F4 240200FF */  addiu     $v0, $zero, 0xff
/* 7B5A8 800E20F8 A202000E */  sb        $v0, 0xe($s0)
/* 7B5AC 800E20FC A202000F */  sb        $v0, 0xf($s0)
/* 7B5B0 800E2100 9062007E */  lbu       $v0, 0x7e($v1)
/* 7B5B4 800E2104 304200F7 */  andi      $v0, $v0, 0xf7
/* 7B5B8 800E2108 A062007E */  sb        $v0, 0x7e($v1)
/* 7B5BC 800E210C 8C830000 */  lw        $v1, ($a0)
/* 7B5C0 800E2110 9062007E */  lbu       $v0, 0x7e($v1)
/* 7B5C4 800E2114 304200EF */  andi      $v0, $v0, 0xef
/* 7B5C8 800E2118 A062007E */  sb        $v0, 0x7e($v1)
/* 7B5CC 800E211C 8C840000 */  lw        $a0, ($a0)
/* 7B5D0 800E2120 9082007E */  lbu       $v0, 0x7e($a0)
/* 7B5D4 800E2124 3C013F80 */  lui       $at, 0x3f80
/* 7B5D8 800E2128 44811000 */  mtc1      $at, $f2
/* 7B5DC 800E212C 30420001 */  andi      $v0, $v0, 1
/* 7B5E0 800E2130 1040000F */  beqz      $v0, .L800E2170
/* 7B5E4 800E2134 24020037 */   addiu    $v0, $zero, 0x37
/* 7B5E8 800E2138 A60200B0 */  sh        $v0, 0xb0($s0)
/* 7B5EC 800E213C 8E020004 */  lw        $v0, 4($s0)
/* 7B5F0 800E2140 24030026 */  addiu     $v1, $zero, 0x26
/* 7B5F4 800E2144 A60300B2 */  sh        $v1, 0xb2($s0)
/* 7B5F8 800E2148 34421000 */  ori       $v0, $v0, 0x1000
/* 7B5FC 800E214C AE020004 */  sw        $v0, 4($s0)
/* 7B600 800E2150 9082007E */  lbu       $v0, 0x7e($a0)
/* 7B604 800E2154 30420002 */  andi      $v0, $v0, 2
/* 7B608 800E2158 1040000A */  beqz      $v0, .L800E2184
/* 7B60C 800E215C 24020002 */   addiu    $v0, $zero, 2
/* 7B610 800E2160 ACA20000 */  sw        $v0, ($a1)
/* 7B614 800E2164 9082007F */  lbu       $v0, 0x7f($a0)
/* 7B618 800E2168 08038861 */  j         .L800E2184
/* 7B61C 800E216C A202000C */   sb       $v0, 0xc($s0)
.L800E2170:
/* 7B620 800E2170 24020025 */  addiu     $v0, $zero, 0x25
/* 7B624 800E2174 A60200B0 */  sh        $v0, 0xb0($s0)
/* 7B628 800E2178 2402001A */  addiu     $v0, $zero, 0x1a
/* 7B62C 800E217C A60200B2 */  sh        $v0, 0xb2($s0)
/* 7B630 800E2180 A0800080 */  sb        $zero, 0x80($a0)
.L800E2184:
/* 7B634 800E2184 3C02800F */  lui       $v0, %hi(D_800F7B70)
/* 7B638 800E2188 24427B70 */  addiu     $v0, $v0, %lo(D_800F7B70)
/* 7B63C 800E218C C4400000 */  lwc1      $f0, ($v0)
/* 7B640 800E2190 46020002 */  mul.s     $f0, $f0, $f2
/* 7B644 800E2194 00000000 */  nop
/* 7B648 800E2198 24420004 */  addiu     $v0, $v0, 4
/* 7B64C 800E219C E6000058 */  swc1      $f0, 0x58($s0)
/* 7B650 800E21A0 C4400000 */  lwc1      $f0, ($v0)
/* 7B654 800E21A4 46020002 */  mul.s     $f0, $f0, $f2
/* 7B658 800E21A8 00000000 */  nop
/* 7B65C 800E21AC E600005C */  swc1      $f0, 0x5c($s0)
/* 7B660 800E21B0 C4400004 */  lwc1      $f0, 4($v0)
/* 7B664 800E21B4 46020002 */  mul.s     $f0, $f0, $f2
/* 7B668 800E21B8 00000000 */  nop
/* 7B66C 800E21BC 0000202D */  daddu     $a0, $zero, $zero
/* 7B670 800E21C0 0C039769 */  jal       set_action_state
/* 7B674 800E21C4 E600006C */   swc1     $f0, 0x6c($s0)
/* 7B678 800E21C8 3C068007 */  lui       $a2, %hi(gGameStatusPtr)
/* 7B67C 800E21CC 8CC6419C */  lw        $a2, %lo(gGameStatusPtr)($a2)
/* 7B680 800E21D0 AE000054 */  sw        $zero, 0x54($s0)
/* 7B684 800E21D4 AE000080 */  sw        $zero, 0x80($s0)
/* 7B688 800E21D8 AE000064 */  sw        $zero, 0x64($s0)
/* 7B68C 800E21DC AE000088 */  sw        $zero, 0x88($s0)
/* 7B690 800E21E0 AE0000B8 */  sw        $zero, 0xb8($s0)
/* 7B694 800E21E4 A60000C0 */  sh        $zero, 0xc0($s0)
/* 7B698 800E21E8 AE000028 */  sw        $zero, 0x28($s0)
/* 7B69C 800E21EC AE00002C */  sw        $zero, 0x2c($s0)
/* 7B6A0 800E21F0 AE000030 */  sw        $zero, 0x30($s0)
/* 7B6A4 800E21F4 AE000084 */  sw        $zero, 0x84($s0)
/* 7B6A8 800E21F8 AE000090 */  sw        $zero, 0x90($s0)
/* 7B6AC 800E21FC AE000094 */  sw        $zero, 0x94($s0)
/* 7B6B0 800E2200 AE000098 */  sw        $zero, 0x98($s0)
/* 7B6B4 800E2204 AE00009C */  sw        $zero, 0x9c($s0)
/* 7B6B8 800E2208 84C30086 */  lh        $v1, 0x86($a2)
/* 7B6BC 800E220C 84C2008C */  lh        $v0, 0x8c($a2)
/* 7B6C0 800E2210 00031900 */  sll       $v1, $v1, 4
/* 7B6C4 800E2214 3C018009 */  lui       $at, %hi(gAreas+0x4)
/* 7B6C8 800E2218 00230821 */  addu      $at, $at, $v1
/* 7B6CC 800E221C 8C2334F4 */  lw        $v1, %lo(gAreas+0x4)($at)
/* 7B6D0 800E2220 00021140 */  sll       $v0, $v0, 5
/* 7B6D4 800E2224 00431021 */  addu      $v0, $v0, $v1
/* 7B6D8 800E2228 8C440004 */  lw        $a0, 4($v0)
/* 7B6DC 800E222C 8C850014 */  lw        $a1, 0x14($a0)
/* 7B6E0 800E2230 10A0001B */  beqz      $a1, .L800E22A0
/* 7B6E4 800E2234 00000000 */   nop
/* 7B6E8 800E2238 84C3008E */  lh        $v1, 0x8e($a2)
/* 7B6EC 800E223C 8C820018 */  lw        $v0, 0x18($a0)
/* 7B6F0 800E2240 0062102A */  slt       $v0, $v1, $v0
/* 7B6F4 800E2244 10400016 */  beqz      $v0, .L800E22A0
/* 7B6F8 800E2248 00031100 */   sll      $v0, $v1, 4
/* 7B6FC 800E224C 00451021 */  addu      $v0, $v0, $a1
/* 7B700 800E2250 C4400000 */  lwc1      $f0, ($v0)
/* 7B704 800E2254 E6000028 */  swc1      $f0, 0x28($s0)
/* 7B708 800E2258 84C2008E */  lh        $v0, 0x8e($a2)
/* 7B70C 800E225C 8C830014 */  lw        $v1, 0x14($a0)
/* 7B710 800E2260 00021100 */  sll       $v0, $v0, 4
/* 7B714 800E2264 00431021 */  addu      $v0, $v0, $v1
/* 7B718 800E2268 C4400004 */  lwc1      $f0, 4($v0)
/* 7B71C 800E226C E600002C */  swc1      $f0, 0x2c($s0)
/* 7B720 800E2270 84C2008E */  lh        $v0, 0x8e($a2)
/* 7B724 800E2274 8C830014 */  lw        $v1, 0x14($a0)
/* 7B728 800E2278 00021100 */  sll       $v0, $v0, 4
/* 7B72C 800E227C 00431021 */  addu      $v0, $v0, $v1
/* 7B730 800E2280 C4400008 */  lwc1      $f0, 8($v0)
/* 7B734 800E2284 E6000030 */  swc1      $f0, 0x30($s0)
/* 7B738 800E2288 84C2008E */  lh        $v0, 0x8e($a2)
/* 7B73C 800E228C 8C830014 */  lw        $v1, 0x14($a0)
/* 7B740 800E2290 00021100 */  sll       $v0, $v0, 4
/* 7B744 800E2294 00431021 */  addu      $v0, $v0, $v1
/* 7B748 800E2298 C440000C */  lwc1      $f0, 0xc($v0)
/* 7B74C 800E229C E6000084 */  swc1      $f0, 0x84($s0)
.L800E22A0:
/* 7B750 800E22A0 C6000028 */  lwc1      $f0, 0x28($s0)
/* 7B754 800E22A4 C602002C */  lwc1      $f2, 0x2c($s0)
/* 7B758 800E22A8 C6040030 */  lwc1      $f4, 0x30($s0)
/* 7B75C 800E22AC 3C02800B */  lui       $v0, %hi(gCameras)
/* 7B760 800E22B0 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 7B764 800E22B4 E4400060 */  swc1      $f0, 0x60($v0)
/* 7B768 800E22B8 E4420064 */  swc1      $f2, 0x64($v0)
/* 7B76C 800E22BC 0C039668 */  jal       func_800E59A0
/* 7B770 800E22C0 E4440068 */   swc1     $f4, 0x68($v0)
/* 7B774 800E22C4 3C048011 */  lui       $a0, %hi(D_8010F250)
/* 7B778 800E22C8 2484F250 */  addiu     $a0, $a0, %lo(D_8010F250)
/* 7B77C 800E22CC 0C00A580 */  jal       mem_clear
/* 7B780 800E22D0 24050034 */   addiu    $a1, $zero, 0x34
/* 7B784 800E22D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7B788 800E22D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 7B78C 800E22DC 03E00008 */  jr        $ra
/* 7B790 800E22E0 27BD0018 */   addiu    $sp, $sp, 0x18
