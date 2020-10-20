.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_CA72E0
/* CA72E0 80240040 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CA72E4 80240044 AFB00010 */  sw        $s0, 0x10($sp)
/* CA72E8 80240048 3C108024 */  lui       $s0, 0x8024
/* CA72EC 8024004C 26100F08 */  addiu     $s0, $s0, 0xf08
/* CA72F0 80240050 AFBF0018 */  sw        $ra, 0x18($sp)
/* CA72F4 80240054 AFB10014 */  sw        $s1, 0x14($sp)
/* CA72F8 80240058 8E020000 */  lw        $v0, ($s0)
/* CA72FC 8024005C 14400010 */  bnez      $v0, .L802400A0
/* CA7300 80240060 0080882D */   daddu    $s1, $a0, $zero
/* CA7304 80240064 0C00AB39 */  jal       heap_malloc
/* CA7308 80240068 24040040 */   addiu    $a0, $zero, 0x40
/* CA730C 8024006C AE020000 */  sw        $v0, ($s0)
/* CA7310 80240070 0000182D */  daddu     $v1, $zero, $zero
/* CA7314 80240074 0040282D */  daddu     $a1, $v0, $zero
/* CA7318 80240078 0220202D */  daddu     $a0, $s1, $zero
.L8024007C:
/* CA731C 8024007C 8C820084 */  lw        $v0, 0x84($a0)
/* CA7320 80240080 24840004 */  addiu     $a0, $a0, 4
/* CA7324 80240084 24630001 */  addiu     $v1, $v1, 1
/* CA7328 80240088 ACA20000 */  sw        $v0, ($a1)
/* CA732C 8024008C 28620010 */  slti      $v0, $v1, 0x10
/* CA7330 80240090 1440FFFA */  bnez      $v0, .L8024007C
/* CA7334 80240094 24A50004 */   addiu    $a1, $a1, 4
/* CA7338 80240098 08090037 */  j         .L802400DC
/* CA733C 8024009C 00000000 */   nop      
.L802400A0:
/* CA7340 802400A0 0000182D */  daddu     $v1, $zero, $zero
/* CA7344 802400A4 0040282D */  daddu     $a1, $v0, $zero
/* CA7348 802400A8 0220202D */  daddu     $a0, $s1, $zero
.L802400AC:
/* CA734C 802400AC 8CA20000 */  lw        $v0, ($a1)
/* CA7350 802400B0 24A50004 */  addiu     $a1, $a1, 4
/* CA7354 802400B4 24630001 */  addiu     $v1, $v1, 1
/* CA7358 802400B8 AC820084 */  sw        $v0, 0x84($a0)
/* CA735C 802400BC 28620010 */  slti      $v0, $v1, 0x10
/* CA7360 802400C0 1440FFFA */  bnez      $v0, .L802400AC
/* CA7364 802400C4 24840004 */   addiu    $a0, $a0, 4
/* CA7368 802400C8 3C108024 */  lui       $s0, 0x8024
/* CA736C 802400CC 26100F08 */  addiu     $s0, $s0, 0xf08
/* CA7370 802400D0 0C00AB4B */  jal       heap_free
/* CA7374 802400D4 8E040000 */   lw       $a0, ($s0)
/* CA7378 802400D8 AE000000 */  sw        $zero, ($s0)
.L802400DC:
/* CA737C 802400DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* CA7380 802400E0 8FB10014 */  lw        $s1, 0x14($sp)
/* CA7384 802400E4 8FB00010 */  lw        $s0, 0x10($sp)
/* CA7388 802400E8 24020002 */  addiu     $v0, $zero, 2
/* CA738C 802400EC 03E00008 */  jr        $ra
/* CA7390 802400F0 27BD0020 */   addiu    $sp, $sp, 0x20
