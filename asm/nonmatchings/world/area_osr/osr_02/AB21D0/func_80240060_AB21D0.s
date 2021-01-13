.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240060_AB21D0
/* AB21D0 80240060 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AB21D4 80240064 AFB10014 */  sw        $s1, 0x14($sp)
/* AB21D8 80240068 0080882D */  daddu     $s1, $a0, $zero
/* AB21DC 8024006C AFBF0018 */  sw        $ra, 0x18($sp)
/* AB21E0 80240070 10A0000C */  beqz      $a1, .L802400A4
/* AB21E4 80240074 AFB00010 */   sw       $s0, 0x10($sp)
/* AB21E8 80240078 8E24014C */  lw        $a0, 0x14c($s1)
/* AB21EC 8024007C 0C00EAD2 */  jal       get_npc_safe
/* AB21F0 80240080 AE200074 */   sw       $zero, 0x74($s1)
/* AB21F4 80240084 8E23014C */  lw        $v1, 0x14c($s1)
/* AB21F8 80240088 AE220078 */  sw        $v0, 0x78($s1)
/* AB21FC 8024008C 2463FFFE */  addiu     $v1, $v1, -2
/* AB2200 80240090 00031840 */  sll       $v1, $v1, 1
/* AB2204 80240094 3C028024 */  lui       $v0, %hi(D_8024253C)
/* AB2208 80240098 00431021 */  addu      $v0, $v0, $v1
/* AB220C 8024009C 8442253C */  lh        $v0, %lo(D_8024253C)($v0)
/* AB2210 802400A0 AE22007C */  sw        $v0, 0x7c($s1)
.L802400A4:
/* AB2214 802400A4 8E22007C */  lw        $v0, 0x7c($s1)
/* AB2218 802400A8 14400015 */  bnez      $v0, .L80240100
/* AB221C 802400AC 2442FFFF */   addiu    $v0, $v0, -1
/* AB2220 802400B0 C62C0074 */  lwc1      $f12, 0x74($s1)
/* AB2224 802400B4 0C00A8BB */  jal       sin_deg
/* AB2228 802400B8 8E300078 */   lw       $s0, 0x78($s1)
/* AB222C 802400BC 3C013FC0 */  lui       $at, 0x3fc0
/* AB2230 802400C0 44811000 */  mtc1      $at, $f2
/* AB2234 802400C4 00000000 */  nop
/* AB2238 802400C8 46020002 */  mul.s     $f0, $f0, $f2
/* AB223C 802400CC 00000000 */  nop
/* AB2240 802400D0 3C014190 */  lui       $at, 0x4190
/* AB2244 802400D4 44816000 */  mtc1      $at, $f12
/* AB2248 802400D8 4600010D */  trunc.w.s $f4, $f0
/* AB224C 802400DC 44022000 */  mfc1      $v0, $f4
/* AB2250 802400E0 00000000 */  nop
/* AB2254 802400E4 A20200AB */  sb        $v0, 0xab($s0)
/* AB2258 802400E8 C6200074 */  lwc1      $f0, 0x74($s1)
/* AB225C 802400EC 0C00A6C9 */  jal       clamp_angle
/* AB2260 802400F0 460C0300 */   add.s    $f12, $f0, $f12
/* AB2264 802400F4 0000102D */  daddu     $v0, $zero, $zero
/* AB2268 802400F8 08090042 */  j         .L80240108
/* AB226C 802400FC E6200074 */   swc1     $f0, 0x74($s1)
.L80240100:
/* AB2270 80240100 AE22007C */  sw        $v0, 0x7c($s1)
/* AB2274 80240104 0000102D */  daddu     $v0, $zero, $zero
.L80240108:
/* AB2278 80240108 8FBF0018 */  lw        $ra, 0x18($sp)
/* AB227C 8024010C 8FB10014 */  lw        $s1, 0x14($sp)
/* AB2280 80240110 8FB00010 */  lw        $s0, 0x10($sp)
/* AB2284 80240114 03E00008 */  jr        $ra
/* AB2288 80240118 27BD0020 */   addiu    $sp, $sp, 0x20
/* AB228C 8024011C 00000000 */  nop
